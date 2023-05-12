// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Containers/Map.h"
#include "Containers/StaticBitArray.h"
#include "IAnselPlugin.h"
#include "Camera/CameraTypes.h"
#include "Camera/CameraPhotography.h"
#include "Camera/PlayerCameraManager.h"
#include "HAL/ConsoleManager.h"
#include "Engine/Engine.h"
#include "Engine/GameViewportClient.h"
#include "Engine/LocalPlayer.h"
#include "Engine/ViewportSplitScreen.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/HUD.h"
#include "GameFramework/WorldSettings.h"
#include "Kismet/GameplayStatics.h"
#include "Widgets/SWindow.h"
#include "Application/SlateApplicationBase.h"
#include "RenderResource.h"
#include "Interfaces/IPluginManager.h"
#include "RenderUtils.h"
#include "UnrealClient.h"
#include <functional>

#include "AnselFunctionLibrary.h"
#include <AnselSDK.h>

DEFINE_LOG_CATEGORY_STATIC(LogAnsel, Log, All);

#define LOCTEXT_NAMESPACE "Photography"

static TAutoConsoleVariable<int32> CVarPhotographyAllow(
	TEXT("r.Photography.Allow"),
	1,
	TEXT("If 1, allow the user to freeze the scene and potentially use a roaming camera to\n")
	TEXT("take screenshots.  Set this dynamically to permit or forbid photography per-level,\n")
	TEXT("per-cutscene, etc.  (Default: 1)"));

static TAutoConsoleVariable<int32> CVarPhotographyEnableMultipart(
	TEXT("r.Photography.EnableMultipart"),
	1,
	TEXT("If 1, allow the photography system to take high-resolution shots that need to be rendered in tiles which are later stitched together.  (Default: 1)"));

static TAutoConsoleVariable<int32> CVarPhotographySettleFrames(
	TEXT("r.Photography.SettleFrames"),
	10,
	TEXT("The number of frames to let the rendering 'settle' before taking a photo.  Useful to allow temporal AA/smoothing to work well; if not using any temporal effects, can be lowered for faster capture.  (Default: 10)"));

static TAutoConsoleVariable<float> CVarPhotographyTranslationSpeed(
	TEXT("r.Photography.TranslationSpeed"),
	300.0f,
	TEXT("Normal speed (in Unreal Units per second) at which to move the roaming photography camera. (Default: 300.0)"));

static TAutoConsoleVariable<float> CVarConstrainCameraSize(
	TEXT("r.Photography.Constrain.CameraSize"),
	14.0f,
	TEXT("Radius (in Unreal Units) of sphere around the camera; used to prevent the camera clipping into nearby geometry when constraining camera with collision.  Negative values disable default camera collisions. (Default: 14.0)"));

static TAutoConsoleVariable<float> CVarConstrainCameraDistance(
	TEXT("r.Photography.Constrain.MaxCameraDistance"),
	2500.0f,
	TEXT("Maximum distance (in Unreal Units) which camera is allowed to wander from its initial position when constraining camera by distance.  Negative values disable default distance contraints. (Default: 2500.0)"));

static TAutoConsoleVariable<int32> CVarPhotographyAutoPostprocess(
	TEXT("r.Photography.AutoPostprocess"),
	1,
	TEXT("If 1, the photography system will attempt to automatically disable HUD, subtitles, and some standard postprocessing effects during photography sessions/captures which are known to give poor photography results.  Set to 0 to manage all postprocessing tweaks manually from the PlayerCameraManager Blueprint callbacks.  Note: Blueprint callbacks will be called regardless of AutoPostprocess value.  (Default: auto-disable (1)"));

static TAutoConsoleVariable<int32> CVarPhotographyAutoPause(
	TEXT("r.Photography.AutoPause"),
	1,
	TEXT("If 1, the photography system will attempt to ensure that the level is paused while in photography mode.  Set to 0 to manage pausing and unpausing manually from the PlayerCameraManager Blueprint callbacks.    Note: Blueprint callbacks will be called regardless of AutoPause value.  (Default: auto-pause (1)"));

static TAutoConsoleVariable<int32> CVarAllowHighQuality(
	TEXT("r.Photography.AllowHighQuality"),
	1,
	TEXT("Whether to permit Ansel RT (high-quality mode).\n"),
	ECVF_RenderThreadSafe);

// intentionally undocumented
static TAutoConsoleVariable<int32> CVarExtreme(
	TEXT("r.Photography.Extreme"),
	0,
	TEXT("Whether to use 'extreme' quality settings for Ansel RT (EXPERIMENTAL).\n"),
	ECVF_RenderThreadSafe);

/////////////////////////////////////////////////
// All the Ansel-specific details

class FNVAnselCameraPhotographyPrivate : public ICameraPhotography
{
public:
	FNVAnselCameraPhotographyPrivate();
	virtual ~FNVAnselCameraPhotographyPrivate() override;
	virtual bool UpdateCamera(FMinimalViewInfo& InOutPOV, APlayerCameraManager* PCMgr) override;
	virtual void UpdatePostProcessing(FPostProcessSettings& InOutPostProcessSettings) override;
	virtual void StartSession() override;
	virtual void StopSession() override;
	virtual bool IsSupported() override;
	virtual void SetUIControlVisibility(uint8 UIControlTarget, bool bIsVisible) override;
	virtual void DefaultConstrainCamera(const FVector NewCameraLocation, const FVector PreviousCameraLocation, const FVector OriginalCameraLocation, FVector& OutCameraLocation, APlayerCameraManager* PCMgr) override;
	virtual const TCHAR* const GetProviderName() override { return TEXT("NVIDIA Ansel"); };

	enum econtrols {
		control_dofscale,
		control_dofsensorwidth,
		control_doffocalregion,
		control_doffocaldistance,
		control_dofdepthbluramount,
		control_dofdepthblurradius,
		control_bloomintensity,
		control_bloomscale,
		control_scenefringeintensity,
		control_OLDSettings,
		control_LumenSettings,
		control_SkylightSettings,
		control_AntiAliasing,
		control_sgQuality,
		control_COUNT
	};
	typedef union {
		bool bool_val;
		float float_val;
	} ansel_control_val;

private:
	void ReconfigureAnsel();
	void DeconfigureAnsel();

	static ansel::StartSessionStatus AnselStartSessionCallback(ansel::SessionConfiguration& settings, void* userPointer);
	static void AnselStopSessionCallback(void* userPointer);
	static void AnselStartCaptureCallback(const ansel::CaptureConfiguration& CaptureInfo, void* userPointer);
	static void AnselStopCaptureCallback(void* userPointer);
	static void AnselChangeQualityCallback(bool isHighQuality, void* userPointer);

	static bool AnselCamerasMatch(ansel::Camera& a, ansel::Camera& b);

	void AnselCameraToFMinimalView(FMinimalViewInfo& InOutPOV, ansel::Camera& AnselCam);
	void FMinimalViewToAnselCamera(ansel::Camera& InOutAnselCam, FMinimalViewInfo& POV);

	bool BlueprintModifyCamera(ansel::Camera& InOutAnselCam, APlayerCameraManager* PCMgr); // returns whether modified cam is in original (session-start) position

	void ConfigureRenderingSettingsForPhotography(FPostProcessSettings& InOutPostProcessSettings);
	void SetUpSessionCVars();
	void DoCustomUIControls(FPostProcessSettings& InOutPPSettings, bool bRebuildControls);
	void DeclareSlider(int id, FText LocTextLabel, float LowerBound, float UpperBound, float Val);
	void DeclareBool(int id,FText LocTextLabel,bool Val);
	bool ProcessUISlider(int id, float& InOutVal);
	void ProcessUIBool(int id,bool& InOutVal);
	
	bool CaptureCVar(FString CVarName);
	void SetCapturedCVarPredicated(const char* CVarName, float valueIfNotReset, std::function<bool(const float, const float)> comparison, bool wantReset, bool useExistingPriority);
	void SetCapturedCVar(const char* CVarName, float valueIfNotReset, bool wantReset = false, bool useExistingPriority = false);

	ansel::Configuration* AnselConfig;
	ansel::Camera AnselCamera;
	ansel::Camera AnselCameraOriginal;
	ansel::Camera AnselCameraPrevious;

	FMinimalViewInfo UECameraOriginal;
	FMinimalViewInfo UECameraPrevious;

	FPostProcessSettings UEPostProcessingOriginal;

	bool bAnselSessionActive;
	bool bAnselSessionNewlyActive;
	bool bAnselSessionWantDeactivate;
	bool bAnselCaptureActive;
	bool bAnselCaptureNewlyActive;
	bool bAnselCaptureNewlyFinished;
	ansel::CaptureConfiguration AnselCaptureInfo;

	bool bForceDisallow;
	bool bIsOrthoProjection;

	bool bWasMovableCameraBeforeSession;
	bool bWasPausedBeforeSession;
	bool bWasShowingHUDBeforeSession;
	bool bWereSubtitlesEnabledBeforeSession;
	bool bWasFadingEnabledBeforeSession;
	bool bWasScreenMessagesEnabledBeforeSession = false;
	float fTimeDilationBeforeSession;

	bool bCameraIsInOriginalState = true;

	bool bAutoPostprocess;
	bool bAutoPause;
	bool bRayTracingEnabled = false;
	bool bPausedInternally = false;

	bool bHighQualityModeDesired = false;
	bool bHighQualityModeIsSetup = false;

	// 这是新增的部分
	bool bHighLodDesired = false;
	bool bHighLodIsSetup = false;
	bool bHighLumenDesired = false;
	bool bHighLumenIsSetup = false;
	bool bHighSkyLightDesired = false;
	bool bHighSkyLightIsSetup = false;
	bool bHighAntiAliasingDesired = false;
	bool bHighAntiAliasingIsSetup = false;
	bool bHighSgQualityDesired = false;
	bool bHighSgQualityIsSetup = false;
	
	ansel::FovType RequiredFovType = ansel::kHorizontalFov;
	ansel::FovType CurrentlyConfiguredFovType = ansel::kHorizontalFov;

	float RequiredWorldToMeters = 100.f;
	float CurrentlyConfiguredWorldToMeters = 0.f;

	uint32_t NumFramesSinceSessionStart;

	// members relating to the 'Game Settings' controls in the Ansel overlay UI
	TStaticBitArray<256> bEffectUIAllowed;

	bool bUIControlsNeedRebuild;
	ansel::UserControlDesc UIControls[control_COUNT];
	static ansel_control_val UIControlValues[control_COUNT]; // static to allow access from a callback
	float UIControlRangeLower[control_COUNT];
	float UIControlRangeUpper[control_COUNT];

	/** Console variable delegate for checking when the console variables have changed */
	FConsoleCommandDelegate CVarDelegate;
	FConsoleVariableSinkHandle CVarDelegateHandle;

	struct CVarInfo {
		IConsoleVariable* cvar;
		float fInitialVal;
	};
	TMap<FString, CVarInfo> InitialCVarMap;
};

FNVAnselCameraPhotographyPrivate::ansel_control_val FNVAnselCameraPhotographyPrivate::UIControlValues[control_COUNT];

static void* AnselSDKDLLHandle = 0;
static bool bAnselDLLLoaded = false;

bool FNVAnselCameraPhotographyPrivate::CaptureCVar(FString CVarName)
{
	IConsoleVariable* cvar = IConsoleManager::Get().FindConsoleVariable(CVarName.GetCharArray().GetData());
	if (!cvar) return false;

	CVarInfo info;
	info.cvar = cvar;
	info.fInitialVal = cvar->GetFloat();

	InitialCVarMap.Add(CVarName, info);
	return true;
}

FNVAnselCameraPhotographyPrivate::FNVAnselCameraPhotographyPrivate()
	: ICameraPhotography()
	, bAnselSessionActive(false)
	, bAnselSessionNewlyActive(false)
	, bAnselSessionWantDeactivate(false)
	, bAnselCaptureActive(false)
	, bAnselCaptureNewlyActive(false)
	, bAnselCaptureNewlyFinished(false)
	, bForceDisallow(false)
	, bIsOrthoProjection(false)
{
	for (int i = 0; i < bEffectUIAllowed.Num(); ++i)
	{
		bEffectUIAllowed[i] = true; // allow until explicitly disallowed
	}

	if (bAnselDLLLoaded)
	{
		AnselConfig = new ansel::Configuration();

		CVarDelegate = FConsoleCommandDelegate::CreateLambda([this] {
			static float LastTranslationSpeed = -1.0f;
			static int32 LastSettleFrames = -1;
			
			float ThisTranslationSpeed = CVarPhotographyTranslationSpeed->GetFloat();
			int32 ThisSettleFrames = CVarPhotographySettleFrames->GetInt();

			if (ThisTranslationSpeed != LastTranslationSpeed ||
				ThisSettleFrames != LastSettleFrames)
			{
				ReconfigureAnsel();
				LastTranslationSpeed = ThisTranslationSpeed;
				LastSettleFrames = ThisSettleFrames;
			}
		});

		CVarDelegateHandle = IConsoleManager::Get().RegisterConsoleVariableSink_Handle(CVarDelegate);
		ReconfigureAnsel();
	}
	else
	{
		UE_LOG(LogAnsel, Log, TEXT("Ansel DLL was not successfully loaded."));
	}
}


FNVAnselCameraPhotographyPrivate::~FNVAnselCameraPhotographyPrivate()
{	
	if (bAnselDLLLoaded)
	{
		IConsoleManager::Get().UnregisterConsoleVariableSink_Handle(CVarDelegateHandle);
		DeconfigureAnsel();
		delete AnselConfig;
	}
}


bool FNVAnselCameraPhotographyPrivate::IsSupported()
{
	return bAnselDLLLoaded && ansel::isAnselAvailable();
}

void FNVAnselCameraPhotographyPrivate::SetUIControlVisibility(uint8 UIControlTarget, bool bIsVisible)
{
	bEffectUIAllowed[UIControlTarget] = bIsVisible;
}

bool FNVAnselCameraPhotographyPrivate::AnselCamerasMatch(ansel::Camera& a, ansel::Camera& b)
{
	return a.position.x == b.position.x &&
		a.position.y == b.position.y &&
		a.position.z == b.position.z &&
		a.rotation.x == b.rotation.x &&
		a.rotation.y == b.rotation.y &&
		a.rotation.z == b.rotation.z &&
		a.rotation.w == b.rotation.w &&
		a.fov == b.fov &&
		a.projectionOffsetX == b.projectionOffsetX &&
		a.projectionOffsetY == b.projectionOffsetY;
}

void FNVAnselCameraPhotographyPrivate::AnselCameraToFMinimalView(FMinimalViewInfo& InOutPOV, ansel::Camera& AnselCam)
{
	InOutPOV.FOV = AnselCam.fov;
	InOutPOV.Location.X = AnselCam.position.x;
	InOutPOV.Location.Y = AnselCam.position.y;
	InOutPOV.Location.Z = AnselCam.position.z;
	FQuat rotq(AnselCam.rotation.x, AnselCam.rotation.y, AnselCam.rotation.z, AnselCam.rotation.w);
	InOutPOV.Rotation = FRotator(rotq);
	InOutPOV.OffCenterProjectionOffset.Set(AnselCam.projectionOffsetX, AnselCam.projectionOffsetY);
}

void FNVAnselCameraPhotographyPrivate::FMinimalViewToAnselCamera(ansel::Camera& InOutAnselCam, FMinimalViewInfo& POV)
{
	InOutAnselCam.fov = POV.FOV;
	InOutAnselCam.position = { float(POV.Location.X), float(POV.Location.Y), float(POV.Location.Z) };
	FQuat rotq = POV.Rotation.Quaternion();
	InOutAnselCam.rotation = { float(rotq.X), float(rotq.Y), float(rotq.Z), float(rotq.W) };
	InOutAnselCam.projectionOffsetX = 0.f; // Ansel only writes these, doesn't read
	InOutAnselCam.projectionOffsetY = 0.f;
}

bool FNVAnselCameraPhotographyPrivate::BlueprintModifyCamera(ansel::Camera& InOutAnselCam, APlayerCameraManager* PCMgr)
{
	FMinimalViewInfo Proposed;

	AnselCameraToFMinimalView(Proposed, InOutAnselCam);
	PCMgr->PhotographyCameraModify(Proposed.Location, UECameraPrevious.Location, UECameraOriginal.Location, Proposed.Location/*out by ref*/);
	// only position has possibly changed
	InOutAnselCam.position.x = Proposed.Location.X;
	InOutAnselCam.position.y = Proposed.Location.Y;
	InOutAnselCam.position.z = Proposed.Location.Z;

	UECameraPrevious = Proposed;

	bool bIsCameraInOriginalTransform =
		Proposed.Location.Equals(UECameraOriginal.Location) &&
		Proposed.Rotation.Equals(UECameraOriginal.Rotation) &&
		Proposed.FOV == UECameraOriginal.FOV;
	return bIsCameraInOriginalTransform;
}

void FNVAnselCameraPhotographyPrivate::DeclareSlider(int id, FText LocTextLabel, float LowerBound, float UpperBound, float Val)
{
	UIControlRangeLower[id] = LowerBound;
	UIControlRangeUpper[id] = UpperBound;

	UIControls[id].labelUtf8 = TCHAR_TO_UTF8(LocTextLabel.ToString().GetCharArray().GetData());
	UIControlValues[id].float_val = FMath::GetRangePct(LowerBound, UpperBound, Val);

	UIControls[id].callback = [](const ansel::UserControlInfo& info) {
		UIControlValues[info.userControlId - 1].float_val = *(float*)info.value;
	};
	UIControls[id].info.userControlId = id + 1; // reserve 0 as 'unused'
	UIControls[id].info.userControlType = ansel::kUserControlSlider;
	UIControls[id].info.value = &UIControlValues[id].float_val;

	ansel::UserControlStatus status = ansel::addUserControl(UIControls[id]);
	UE_LOG(LogAnsel, Log, TEXT("control#%d status=%d"), (int)id, (int)status);
}
//声明bool值
void FNVAnselCameraPhotographyPrivate::DeclareBool(int id,FText LocTextLabel,bool Val)
{
	UIControls[id].labelUtf8 = TCHAR_TO_UTF8(LocTextLabel.ToString().GetCharArray().GetData());
	UIControlValues[id].bool_val = Val;
	UIControls[id].callback = [](const ansel::UserControlInfo& info)
	{
		UIControlValues[info.userControlId - 1].bool_val = *(bool*)info.value;
	};
	UIControls[id].info.userControlId = id+1;
	UIControls[id].info.userControlType = ansel::kUserControlBoolean;
	UIControls[id].info.value = &UIControlValues[id].bool_val;
	ansel::UserControlStatus status = ansel::addUserControl(UIControls[id]);
}

bool FNVAnselCameraPhotographyPrivate::ProcessUISlider(int id, float& InOutVal)
{
	if (UIControls[id].info.userControlId <= 0)
	{
		return false; // control is not in use
	}

	InOutVal = FMath::Lerp(UIControlRangeLower[id], UIControlRangeUpper[id], UIControlValues[id].float_val);
	return true;
}

void FNVAnselCameraPhotographyPrivate::ProcessUIBool(int id, bool& InOutVal)
{
	if (UIControls[id].info.userControlId <= 0)
	{
		InOutVal = false; // control is not in use
	}
	InOutVal = UIControlValues[id].bool_val;
}

void FNVAnselCameraPhotographyPrivate::DoCustomUIControls(FPostProcessSettings& InOutPPSettings, bool bRebuildControls)
{
	if (bRebuildControls)
	{
		// clear existing controls
		for (int i = 0; i < control_COUNT; ++i)
		{
			if (UIControls[i].info.userControlId > 0) // we are using id 0 as 'unused'
			{
				ansel::removeUserControl(UIControls[i].info.userControlId);
				UIControls[i].info.userControlId = 0;
			}
		}
		
		DeclareBool(control_OLDSettings,LOCTEXT("LOD_Settings","LOD High"),false);
		DeclareBool(control_LumenSettings,LOCTEXT("Lumen_Settings","Lumen High"),false);
		DeclareBool(control_SkylightSettings,LOCTEXT("Skylight_Settings","Skylight High"),false);
		DeclareBool(control_AntiAliasing,LOCTEXT("AntiAliasing_Settings","AntiAliasing High"),false);
		DeclareBool(control_sgQuality,LOCTEXT("sgQuality_Settings","SQ_Quality High"),false);
		// save postproc settings at session start
		UEPostProcessingOriginal = InOutPPSettings;

		// add all relevant controls
		PRAGMA_DISABLE_DEPRECATION_WARNINGS
		if (bEffectUIAllowed[DepthOfField])
		{
			const bool bAnyDofVisible = InOutPPSettings.DepthOfFieldFstop > 0 && InOutPPSettings.DepthOfFieldFocalDistance > 0;

			if (bAnyDofVisible)
			{
				DeclareSlider(
					control_dofsensorwidth,
					LOCTEXT("control_dofsensorwidth", "Focus Sensor"), // n.b. similar effect to focus scale
					0.1f, 1000.f,
					InOutPPSettings.DepthOfFieldSensorWidth
				);

				DeclareSlider(
					control_doffocaldistance,
					LOCTEXT("control_doffocaldistance", "Focus Distance"),
					0.f, 1000.f, // UU - doc'd to 10000U but that's too coarse for a narrow UI control
					InOutPPSettings.DepthOfFieldFocalDistance
				);

				DeclareSlider(
					control_dofdepthbluramount,
					LOCTEXT("control_dofbluramount", "Blur Distance km"),
					0.000001f, 1.f, // km; doc'd as up to 100km but that's too coarse for a narrow UI control
					InOutPPSettings.DepthOfFieldDepthBlurAmount
				);

				DeclareSlider(
					control_dofdepthblurradius,
					LOCTEXT("control_dofblurradius", "Blur Radius"),
					0.f, 4.f,
					InOutPPSettings.DepthOfFieldDepthBlurRadius
				);
			}
		}
		PRAGMA_ENABLE_DEPRECATION_WARNINGS

		if (bEffectUIAllowed[Bloom] &&
			InOutPPSettings.BloomIntensity > 0.f)
		{
			DeclareSlider(
				control_bloomintensity,
				LOCTEXT("control_bloomintensity", "Bloom Intensity"),
				0.f, 8.f,
				InOutPPSettings.BloomIntensity
			);
			DeclareSlider(
				control_bloomscale,
				LOCTEXT("control_bloomscale", "Bloom Scale"),
				0.f, 64.f,
				InOutPPSettings.BloomSizeScale
			);
		}

		if (bEffectUIAllowed[ChromaticAberration] &&
			InOutPPSettings.SceneFringeIntensity > 0.f)
		{
			DeclareSlider(
				control_scenefringeintensity,
				LOCTEXT("control_chromaticaberration", "Chromatic Aberration"),
				0.f, 15.f, // note: FPostProcesssSettings metadata says range is 0./5. but larger values have been seen in the wild 
				InOutPPSettings.SceneFringeIntensity
			);
		}

		bUIControlsNeedRebuild = false;
	}

	// postprocessing is based upon postprocessing settings at session start time (avoids set of
	// UI tweakables changing due to the camera wandering between postprocessing volumes, also
	// avoids most discontinuities where stereo and panoramic captures can also wander between
	// postprocessing volumes during the capture process)
	InOutPPSettings = UEPostProcessingOriginal;

	// update values where corresponding controls are in use
	if (ProcessUISlider(control_dofscale, InOutPPSettings.DepthOfFieldScale))
	{
		InOutPPSettings.bOverride_DepthOfFieldScale = 1;
	}
	if (ProcessUISlider(control_doffocalregion, InOutPPSettings.DepthOfFieldFocalRegion))
	{
		InOutPPSettings.bOverride_DepthOfFieldFocalRegion = 1;
	}
	if (ProcessUISlider(control_dofsensorwidth, InOutPPSettings.DepthOfFieldSensorWidth))
	{
		InOutPPSettings.bOverride_DepthOfFieldSensorWidth = 1;
	}
	if (ProcessUISlider(control_doffocaldistance, InOutPPSettings.DepthOfFieldFocalDistance))
	{
		InOutPPSettings.bOverride_DepthOfFieldFocalDistance = 1;
	}
	if (ProcessUISlider(control_dofdepthbluramount, InOutPPSettings.DepthOfFieldDepthBlurAmount))
	{
		InOutPPSettings.bOverride_DepthOfFieldDepthBlurAmount = 1;
	}
	if (ProcessUISlider(control_dofdepthblurradius, InOutPPSettings.DepthOfFieldDepthBlurRadius))
	{
		InOutPPSettings.bOverride_DepthOfFieldDepthBlurRadius = 1;
	}
	if (ProcessUISlider(control_bloomintensity, InOutPPSettings.BloomIntensity))
	{
		InOutPPSettings.bOverride_BloomIntensity = 1;
	}
	if (ProcessUISlider(control_bloomscale, InOutPPSettings.BloomSizeScale))
	{
		InOutPPSettings.bOverride_BloomSizeScale = 1;
	}
	if (ProcessUISlider(control_scenefringeintensity, InOutPPSettings.SceneFringeIntensity))
	{
		InOutPPSettings.bOverride_SceneFringeIntensity = 1;
	}

	// 这里已经将值传输到对应位置了
	ProcessUIBool(control_OLDSettings,bHighLodDesired);
	ProcessUIBool(control_LumenSettings,bHighLumenDesired);
	ProcessUIBool(control_SkylightSettings,bHighSkyLightDesired);
	ProcessUIBool(control_AntiAliasing,bHighAntiAliasingDesired);
	ProcessUIBool(control_sgQuality,bHighSgQualityDesired);
}

bool FNVAnselCameraPhotographyPrivate::UpdateCamera(FMinimalViewInfo& InOutPOV, APlayerCameraManager* PCMgr)
{
	check(PCMgr != nullptr);
	bool bGameCameraCutThisFrame = false;

	bForceDisallow = false;
	if (!bAnselSessionActive)
	{
		// grab & store some view details that effect Ansel session setup but which it could be
		// unsafe to access from the Ansel callbacks (which aren't necessarily on render
		// or game thread).
		bIsOrthoProjection = (InOutPOV.ProjectionMode == ECameraProjectionMode::Orthographic);
		if (UGameViewportClient* ViewportClient = PCMgr->GetWorld()->GetGameViewport())
		{
			bForceDisallow = bForceDisallow || (ViewportClient->GetCurrentSplitscreenConfiguration() != ESplitScreenType::None); // forbid if in splitscreen.
		}

		// forbid photography if in stereoscopic/VR mode
		bForceDisallow = bForceDisallow || (GEngine->IsStereoscopic3D());

		// continually check for infrequent changes in some game parameters which annoyingly
		// require Ansel to be completely reinitialized:
		// 1. detect world-to-meters scale
		if (const UWorld* World = GEngine->GetWorld())
		{
			const AWorldSettings* WorldSettings = World->GetWorldSettings();
			if (WorldSettings && WorldSettings->WorldToMeters != 0.f)
			{
				RequiredWorldToMeters = WorldSettings->WorldToMeters;
			}
		}
		// 2. detect FOV constraint settings - vital for multi-part snapshot tiling
		if (const APlayerController* PC = PCMgr->GetOwningPlayerController())
		{
			if (const ULocalPlayer* LocalPlayer = PC->GetLocalPlayer())
			{
				if (const UGameViewportClient* ViewportClient = LocalPlayer->ViewportClient)
				{
					if (const FViewport* Viewport = ViewportClient->Viewport)
					{
						const FVector2D& LPViewScale = LocalPlayer->Size;
						uint32 SizeX = FMath::TruncToInt(LPViewScale.X * Viewport->GetSizeXY().X);
						uint32 SizeY = FMath::TruncToInt(LPViewScale.Y * Viewport->GetSizeXY().Y);

						EAspectRatioAxisConstraint AspectRatioAxisConstraint = LocalPlayer->AspectRatioAxisConstraint;

						// (logic from FMinimalViewInfo::CalculateProjectionMatrixGivenView() -) if x is bigger, and we're respecting x or major axis, AND mobile isn't forcing us to be Y axis aligned
						if (((SizeX > SizeY) && (AspectRatioAxisConstraint == AspectRatio_MajorAxisFOV)) || (AspectRatioAxisConstraint == AspectRatio_MaintainXFOV) || (InOutPOV.ProjectionMode == ECameraProjectionMode::Orthographic))
						{
							RequiredFovType = ansel::kHorizontalFov;
						}
						else
						{
							RequiredFovType = ansel::kVerticalFov;
						}
					}
				}
			}
		}
		if (CurrentlyConfiguredWorldToMeters != RequiredWorldToMeters ||
			CurrentlyConfiguredFovType != RequiredFovType)
		{
			ReconfigureAnsel();
		}
	}

	if (bAnselSessionActive)
	{
		APlayerController* PCOwner = PCMgr->GetOwningPlayerController();
		check(PCOwner != nullptr);

		++NumFramesSinceSessionStart;

		if (bAnselCaptureNewlyActive)
		{
			PCMgr->OnPhotographyMultiPartCaptureStart();
			bGameCameraCutThisFrame = true;
			bAnselCaptureNewlyActive = false;
		}

		if (bAnselCaptureNewlyFinished)
		{
			bGameCameraCutThisFrame = true;
			bAnselCaptureNewlyFinished = false;
			PCMgr->OnPhotographyMultiPartCaptureEnd();
		}

		if (bAnselSessionWantDeactivate)
		{
			bAnselSessionActive = false;
			bAnselSessionWantDeactivate = false;

			// auto-restore state

			if (bAutoPostprocess)
			{
				if (bWasShowingHUDBeforeSession)
				{
					PCOwner->MyHUD->ShowHUD(); // toggle off
				}
				if (bWereSubtitlesEnabledBeforeSession)
				{
					UGameplayStatics::SetSubtitlesEnabled(true);
				}
				if (bWasFadingEnabledBeforeSession)
				{
					PCMgr->bEnableFading = true;
				}
			}

			GAreScreenMessagesEnabled = bWasScreenMessagesEnabledBeforeSession;

			if (bAutoPause && !bWasPausedBeforeSession)
			{
				PCOwner->GetWorldSettings()->SetTimeDilation(fTimeDilationBeforeSession);
				PCOwner->SetPause(false);
				bPausedInternally = false;
			}

			PCMgr->GetWorld()->bIsCameraMoveableWhenPaused = bWasMovableCameraBeforeSession;

			// Re-activate Windows Cursor as Ansel will automatically hide the Windows mouse cursor when Ansel UI is enabled.
			//	See https://nvidiagameworks.github.io/Ansel/md/Ansel_integration_guide.html
			// !Needs to be done after AnselStopSessionCallback
			TSharedPtr<GenericApplication> PlatformApplication = FSlateApplicationBase::Get().GetPlatformApplication();
			if (PlatformApplication.IsValid() && PlatformApplication->Cursor.IsValid())
			{
				PlatformApplication->Cursor->Show(true); // If we don't force-show it now (nb. it may nonetheless be an invisible cursor), in DX12 it never seems to come back when PCOwner does actually want it...?
				//PlatformApplication->Cursor->Show(PCOwner->ShouldShowMouseCursor());
			}

			for (auto &foo : InitialCVarMap)
			{
				// RESTORE CVARS FROM SESSION START
				if (foo.Value.cvar)
					foo.Value.cvar->SetWithCurrentPriority(foo.Value.fInitialVal);
			}
			InitialCVarMap.Empty(); // clear saved cvar values

			bHighQualityModeIsSetup = false;
			PCMgr->OnPhotographySessionEnd(); // after unpausing

			// no need to restore original camera params; re-clobbered every frame
		}
		else
		{
			bCameraIsInOriginalState = false;

			if (bAnselSessionNewlyActive)
			{
				NumFramesSinceSessionStart = 0;

				PCMgr->OnPhotographySessionStart(); // before pausing

				// copy these values to avoid mix-up if the CVars are changed during capture callbacks
				bAutoPause = !!CVarPhotographyAutoPause->GetInt();
				bAutoPostprocess = !!CVarPhotographyAutoPostprocess->GetInt();
				bRayTracingEnabled = IsRayTracingEnabled();
				
				// attempt to pause game
				bWasPausedBeforeSession = PCOwner->IsPaused();
				bWasMovableCameraBeforeSession = PCMgr->GetWorld()->bIsCameraMoveableWhenPaused;
				PCMgr->GetWorld()->bIsCameraMoveableWhenPaused = true;
				if (bAutoPause && !bWasPausedBeforeSession)
				{
					fTimeDilationBeforeSession = PCOwner->GetWorldSettings()->TimeDilation;
					PCOwner->GetWorldSettings()->SetTimeDilation(0.f); // kill character motion-blur, this looks better than setting the motion-blur level to 0 (which flickers) - kinda heavy-handed but the only way I've found to kill motion-blur while also preventing flicker
					// we pause() properly in a *future* frame so Slomo can first kick-in properly
				}

				SetUpSessionCVars();

				bWasScreenMessagesEnabledBeforeSession = GAreScreenMessagesEnabled;
				GAreScreenMessagesEnabled = false;

				bWasFadingEnabledBeforeSession = PCMgr->bEnableFading;
				bWasShowingHUDBeforeSession = PCOwner->MyHUD &&
					PCOwner->MyHUD->bShowHUD;
				bWereSubtitlesEnabledBeforeSession = UGameplayStatics::AreSubtitlesEnabled();
				if (bAutoPostprocess)
				{
					if (bWasShowingHUDBeforeSession)
					{
						PCOwner->MyHUD->ShowHUD(); // toggle off
					}
					UGameplayStatics::SetSubtitlesEnabled(false);
					PCMgr->bEnableFading = false;
				}

				bUIControlsNeedRebuild = true;

				// store initial camera info
				UECameraPrevious = InOutPOV;
				UECameraOriginal = InOutPOV;

				FMinimalViewToAnselCamera(AnselCamera, InOutPOV);
				ansel::updateCamera(AnselCamera);

				AnselCameraOriginal = AnselCamera;
				AnselCameraPrevious = AnselCamera;

				bCameraIsInOriginalState = true;

				bAnselSessionNewlyActive = false;
			}
			else
			{
				ansel::updateCamera(AnselCamera);

				// active session; give Blueprints opportunity to modify camera, unless a capture is in progress
				if (!bAnselCaptureActive)
				{
					bCameraIsInOriginalState = BlueprintModifyCamera(AnselCamera, PCMgr);
				}
			}

			// ensure 2 frames have passed before pausing so that 0-timedilation can kick-in and kill the motion-blur!
			// why 2 frames rather than 1 (or even 0)?  dunno!  probably 1 frame for the new time dilation to go into effect and 1 more frame for the motion vectors to update.
			if (NumFramesSinceSessionStart == 2)
			{
				if (bAutoPause && !bWasPausedBeforeSession)
				{
					PCOwner->SetPause(true);
					bPausedInternally = true;
				}
			}

			AnselCameraToFMinimalView(InOutPOV, AnselCamera);

			AnselCameraPrevious = AnselCamera;
		}

		if (bAnselCaptureActive)
		{
			// eliminate letterboxing during capture
			InOutPOV.bConstrainAspectRatio = false;
		}
	}

	return bGameCameraCutThisFrame;
}

void FNVAnselCameraPhotographyPrivate::SetCapturedCVarPredicated(const char* CVarName, float valueIfNotReset, std::function<bool(const float, const float)> comparison, bool wantReset, bool useExistingPriority)
{
	CVarInfo* info = nullptr;
	if (InitialCVarMap.Contains(CVarName) || CaptureCVar(CVarName))
	{
		info = &InitialCVarMap[CVarName];
		if (info->cvar && comparison(valueIfNotReset, info->fInitialVal))
		{
			if (useExistingPriority)
				info->cvar->SetWithCurrentPriority(wantReset ? info->fInitialVal : valueIfNotReset);
			else
				info->cvar->Set(wantReset ? info->fInitialVal : valueIfNotReset);
		}
	}
	if (!(info && info->cvar)) UE_LOG(LogAnsel, Log, TEXT("CVar used by Ansel not found: %hs"), CVarName);
}

void FNVAnselCameraPhotographyPrivate::SetCapturedCVar(const char* CVarName, float valueIfNotReset, bool wantReset, bool useExistingPriority)
{
	SetCapturedCVarPredicated(CVarName, valueIfNotReset,
		[](float, float) { return true; },
		wantReset, useExistingPriority);
}

//渲染配置
void FNVAnselCameraPhotographyPrivate::ConfigureRenderingSettingsForPhotography(FPostProcessSettings& InOutPostProcessingSettings)
{
#define QUALITY_CVAR(NAME,BOOSTVAL) SetCapturedCVar(NAME, BOOSTVAL, !bHighQualityModeDesired, true)
#define QUALITY_CVAR_AT_LEAST(NAME,BOOSTVAL) SetCapturedCVarPredicated(NAME, BOOSTVAL, std::greater<float>(), !bHighQualityModeDesired, true)
#define QUALITY_CVAR_AT_MOST(NAME,BOOSTVAL) SetCapturedCVarPredicated(NAME, BOOSTVAL, std::less<float>(), !bHighQualityModeDesired, true)
#define QUALITY_CVAR_LOWPRIORITY_AT_LEAST(NAME,BOOSTVAL) SetCapturedCVarPredicated(NAME, BOOSTVAL, std::greater<float>(), !bHighQualityModeDesired, false)

#define LOD_CVAR(NAME,BOOSTVAL)	SetCapturedCVar(NAME, BOOSTVAL, !bHighLodDesired, true)
#define LUMEN_CVAR(NAME,BOOSTVAL) SetCapturedCVar(NAME, BOOSTVAL, !bHighLumenDesired, true)
#define SKYLIGHT_CVAR(NAME,BOOSTVAL) SetCapturedCVar(NAME, BOOSTVAL, !bHighSkyLightDesired, true)
#define SQQUALITY_CVAR(NAME,BOOSTVAL) SetCapturedCVar(NAME, BOOSTVAL, !bHighSgQualityDesired, true)
#define ANTIALIASING_CVAR(NAME,BOOSTVAL) SetCapturedCVar(NAME, BOOSTVAL, !bHighAntiAliasingDesired, true)
	// LOD Settings
	if(bHighLodIsSetup!=bHighLodDesired)
	{
		
		LOD_CVAR("r.TextureStreaming",0); 
		LOD_CVAR("r.ForceLOD",0);			
		LOD_CVAR("r.particlelodbias", -10);	
		LOD_CVAR("foliage.DitheredLOD", 0);	
		LOD_CVAR("foliage.ForceLOD", 0);
		LOD_CVAR("Foliage.MinimumScreenSize", 0.00000001);
		//LOD_CVAR("r.HLOD", 0);
		bHighLodIsSetup = bHighLodDesired;
#undef LOD_CVAR

	}
	//lumen设定
	if(bHighLumenIsSetup!=bHighLumenDesired)
	{
		LUMEN_CVAR("r.DistanceFields.MaxPerMeshResolution",256);
		LUMEN_CVAR("r.Lumen.ScreenProbeGather.ScreenSpaceBentNormal.ApplyDuringIntegration",0);
		LUMEN_CVAR("r.LumenScene.DirectLighting.OffscreenShadowing.TraceMeshSDFs",0);
		LUMEN_CVAR("r.Lumen.HardwareRayTracing",1);
		LUMEN_CVAR("r.Lumen.TranslucencyVolume.TraceFromVolume",0);
		LUMEN_CVAR("r.Lumen.Reflections.RadianceCache",1);
		LUMEN_CVAR("r.LumenScene.Radiosity.ProbeSpacing",8);
		LUMEN_CVAR("r.LumenScene.Radiosity.ProbeOcclusion",0);
		LUMEN_CVAR("r.LumenScene.FarField",1);
		LUMEN_CVAR("r.LumenScene.FarField.MaxTraceDistance",1000000);
		LUMEN_CVAR("r.Lumen.HardwareRayTracing.MaxIterations",128);
		//lumen最终的捕获质量
		//InOutPostProcessingSettings.bOverride_LumenFinalGatherQuality =1;
		//InOutPostProcessingSettings.LumenFinalGatherQuality = 8;
		//场景的更新速度
		//InOutPostProcessingSettings.bOverride_LumenSceneLightingUpdateSpeed =1;
		//InOutPostProcessingSettings.LumenSceneLightingUpdateSpeed = 4;
		//灯光的更新速度
		//InOutPostProcessingSettings.bOverride_LumenFinalGatherLightingUpdateSpeed =1;
		//InOutPostProcessingSettings.LumenFinalGatherLightingUpdateSpeed =4;
		bHighLumenIsSetup = bHighLumenDesired;
#undef LUMEN_CVAR
	}
	// 天光设定
	if(bHighSkyLightIsSetup!=bHighSkyLightDesired)
	{
		SKYLIGHT_CVAR("r.SkyLight.RealTimeReflectionCapture.TimeSlice",0);	
		SKYLIGHT_CVAR("r.VolumetricRenderTarget",0);
		bHighSkyLightIsSetup = bHighSkyLightDesired;
#undef SKYLIGHT_CVAR
	}
	// 质量设定
	if(bHighSgQualityIsSetup!=bHighSgQualityDesired)
	{
		SQQUALITY_CVAR("sg.ViewDistanceQuality", 4);
		SQQUALITY_CVAR("sg.AntiAliasingQuality", 4);
		SQQUALITY_CVAR("sg.ShadowQuality", 4);
		SQQUALITY_CVAR("sg.PostProcessQuality", 4);
		SQQUALITY_CVAR("sg.TextureQuality", 4);
		SQQUALITY_CVAR("sg.FoliageQuality", 4);
		SQQUALITY_CVAR("sg.ShadingQuality", 4);
		bHighSgQualityIsSetup = bHighSgQualityDesired;
#undef SQQUALITY_CVAR
	}
	// ~sg.AntiAliasingQuality @ cine 
	if(bHighAntiAliasingIsSetup!=bHighAntiAliasingDesired)
	{
		//抗锯齿选项
		UE_LOG(LogAnsel, Log, TEXT("AntiAliasing is high quality:True"));
		ANTIALIASING_CVAR("r.AntiAliasingMethod", 2); //这里是抗锯齿方式这里是超分辨率 原为TAA：2	
		ANTIALIASING_CVAR("r.TemporalAASamples",64);										
		ANTIALIASING_CVAR("r.TemporalAAFilterSize",1);		
		ANTIALIASING_CVAR("r.TemporalAA.Quality",2);									
		//QUALITY_CVAR_AT_LEAST("r.ngx.dlss.quality", 2); // high-quality mode for DLSS if in use //NOT
		bHighAntiAliasingIsSetup = bHighAntiAliasingDesired;
#undef ANTIALIASING_CVAR
	}
	
	if (CVarAllowHighQuality.GetValueOnAnyThread()
		&& bHighQualityModeIsSetup != bHighQualityModeDesired
		&& (bPausedInternally || !bAutoPause) // <- don't start overriding vars until truly paused
		)
	{
		// Pump up (or reset) the quality. 
		UE_LOG(LogAnsel, Log, TEXT("Photography is high quality:True"));
		// bring rendering up to (at least) 100% resolution, but won't override manually set value on console
		QUALITY_CVAR_LOWPRIORITY_AT_LEAST("r.ScreenPercentage", 100); //OK

		// most of these are similar to typical cinematic sg.* scalability settings, toned down a little for performance


		// bias various geometry LODs 
		QUALITY_CVAR_AT_MOST("r.StaticMeshLODDistanceScale", 0.25f); // large quality bias //OK
		QUALITY_CVAR_AT_MOST("r.skeletalmeshlodbias", -10); // big bias here since when paused this never gets re-evaluated and the camera could roam to look at a skeletal mesh far away
		
		// 其他设定
		QUALITY_CVAR("r.D3D12.GPUTimeout", 0); 
		QUALITY_CVAR("a.URO.Enable", 0);
		
		
		
		// ~sg.FoliageQuality @ cinematic 
		QUALITY_CVAR_AT_LEAST("foliage.DensityScale", 1.f);		//OK
		QUALITY_CVAR_AT_LEAST("grass.DensityScale", 1.f);		//OK
		// boosted foliage LOD (use distance scale not lod bias - latter is buggy)
		QUALITY_CVAR_AT_LEAST("foliage.LODDistanceScale", 4.f);	//OK
		// ~sg.EffectsQuality @ cinematic
		QUALITY_CVAR_AT_LEAST("r.TranslucencyLightingVolumeDim", 64);							
		QUALITY_CVAR("r.RefractionQuality", 2);													
		QUALITY_CVAR("r.SSR.Quality", 4);														
		// QUALITY_CVAR("r.SceneColorFormat", 4); // no - don't really want to mess with this
		QUALITY_CVAR("r.TranslucencyVolumeBlur", 1);											
		
		QUALITY_CVAR("r.MaterialQualityLevel", 1); // 0==low, -> 1==high <- , 2==medium			
		QUALITY_CVAR("r.SSS.Scale", 1);
		QUALITY_CVAR("r.SSS.SampleSet", 2);	
		QUALITY_CVAR("r.SSS.Quality", 1);		
		QUALITY_CVAR("r.SSS.HalfRes", 0);		
		//QUALITY_CVAR_AT_LEAST("r.EmitterSpawnRateScale", 1.f); // no - not sure this has a point when game is paused
		QUALITY_CVAR("r.ParticleLightQuality", 2); //OK
		QUALITY_CVAR("r.DetailMode", 2);
		
		
		
		
		// ~sg.TextureQuality @ cinematic
		QUALITY_CVAR("r.Streaming.MipBias", 0);					//OK
		QUALITY_CVAR_AT_LEAST("r.MaxAnisotropy", 16);			//OK
		QUALITY_CVAR("r.Streaming.MaxEffectiveScreenSize", 0);	//OK
		// intentionally don't mess with streaming pool size, see 'CVarExtreme' section below
		
		
		
		// ~sg.ViewDistanceQuality @ cine but only mild draw distance boost
		QUALITY_CVAR_AT_LEAST("r.ViewDistanceScale", 50.0f);	//OK

		// ~sg.ShadowQuality @ cinematic
		QUALITY_CVAR_AT_LEAST("r.LightFunctionQuality", 2);		//OK
		QUALITY_CVAR("r.ShadowQuality", 5);						//OK
		QUALITY_CVAR_AT_LEAST("r.Shadow.CSM.MaxCascades", 10);	//OK
		QUALITY_CVAR_AT_LEAST("r.Shadow.MaxResolution", 4096);	//ok
		QUALITY_CVAR_AT_LEAST("r.Shadow.MaxCSMResolution", 4096);	//ok
		QUALITY_CVAR_AT_MOST("r.Shadow.RadiusThreshold", 0.001f);		//更改	
		QUALITY_CVAR("r.Shadow.DistanceScale", 10.f);					//更改
		QUALITY_CVAR("r.Shadow.CSM.TransitionScale", 1.f);		//ok
		QUALITY_CVAR("r.Shadow.PreShadowResolutionFactor", 1.f);	//ok
		QUALITY_CVAR("r.AOQuality", 2);		//ok
		QUALITY_CVAR("r.VolumetricFog", 1);	//ok
		QUALITY_CVAR("r.VolumetricFog.GridPixelSize", 4);	//ok
		QUALITY_CVAR("r.VolumetricFog.GridSizeZ", 128);		//ok
		QUALITY_CVAR_AT_LEAST("r.VolumetricFog.HistoryMissSupersampleCount", 16);	//ok
		QUALITY_CVAR_AT_LEAST("r.LightMaxDrawDistanceScale", 4.f);	//ok

		
		
		
		// pump up the quality of raytracing features, though we won't necessarily turn them on if the game doesn't already have them enabled
		// 这里是当光追开启才特有的
		if (bRayTracingEnabled)
		{
			QUALITY_CVAR_AT_LEAST("D3D12.PSO.StallTimeoutInMs", 8000.0f); // the high-quality RTPSOs may have to be built from scratch the first time; temporarily raise this limit in the hope of avoiding the rare barf-outs.

			/*** HIGH-QUALITY MODE DOES *NOT* FORCE GI ON ***/
			// Don't tweak GI parameters right now - its performance is super-sensitive to changes and a long long frame will cause a device-disconnect.
			//QUALITY_CVAR_AT_MOST("r.RayTracing.GlobalIllumination.DiffuseThreshold", 0); // artifact avoidance

			/*** HIGH-QUALITY MODE DOES *NOT* FORCE RT AO ON ***/
			QUALITY_CVAR_AT_LEAST("r.RayTracing.AmbientOcclusion.SamplesPerPixel", 3);

			/*** HIGH-QUALITY MODE DOES *NOT* FORCE RT REFLECTIONS ON ***/
			QUALITY_CVAR("r.raytracing.reflections.rendertilesize", 128); // somewhat protect against long frames (from pumped-up quality) causing a device-disconnect
			QUALITY_CVAR_AT_LEAST("r.RayTracing.Reflections.MaxBounces", 2); // ~sweet-spot
			QUALITY_CVAR_AT_LEAST("r.RayTracing.Reflections.MaxRoughness", 0.9f); // speed hit
			QUALITY_CVAR_AT_LEAST("r.RayTracing.Reflections.MaxRayDistance", 1000000.f);
			QUALITY_CVAR("r.RayTracing.Reflections.SortMaterials", 1); // usually some kind of perf win, especially w/above reflection quality
			QUALITY_CVAR("r.RayTracing.Reflections.DirectLighting", 1);
			//QUALITY_CVAR("r.RayTracing.Reflections.EmissiveAndIndirectLighting", 1);// curiously problematic to force, leave alone
			QUALITY_CVAR_AT_LEAST("r.RayTracing.Reflections.Shadows", 1); // -1==auto, 0==off, 1==hard, 2==soft/area(requires high spp)
			QUALITY_CVAR("r.RayTracing.Reflections.HeightFog", 1);
			QUALITY_CVAR("r.RayTracing.Reflections.ReflectionCaptures", 1);
			//QUALITY_CVAR_AT_LEAST("r.RayTracing.Reflections.SamplesPerPixel", 2); // -1==use pp vol // NOPE, don't touch spp right now: 1 is ok, ~10 is good, anywhere in-between is noisy
			QUALITY_CVAR_AT_LEAST("r.RayTracing.Reflections.ScreenPercentage", 100);
			// QUALITY_CVAR("r.RayTracing.Reflections", 1); // FORCE ON: ignore postproc volume flag -- NOPE, there are a couple of RT reflection issues right now which can leave RT reflections much brighter than their raster counterparts
			//QUALITY_CVAR("r.raytracing.reflections.translucency", 1); // hmm, nope, usually good translucency - but the reflection shader appears to apply translucency after roughness-fade so there's some risk of IQ regression here right now.  may enable after more testing.

			/*** HIGH-QUALITY MODE DOES *NOT* FORCE RT TRANSLUCENCY ON ***/
			QUALITY_CVAR_AT_LEAST("r.RayTracing.Translucency.MaxRoughness", 0.9f);
			QUALITY_CVAR_AT_LEAST("r.RayTracing.Translucency.MaxRayDistance", 1000000.f);
			QUALITY_CVAR_AT_LEAST("r.RayTracing.Translucency.MaxRefractionRays", 11); // number of layers of ray penetration, actually regardless of whether refraction is enabled
			QUALITY_CVAR_AT_LEAST("r.RayTracing.Translucency.Shadows", 1); // turn on at least basic quality

			/*** HIGH-QUALITY MODE DOES *NOT* FORCE RT SHADOWS ON ***/
			QUALITY_CVAR("r.RayTracing.Shadow.MaxLights", -1); // unlimited
			QUALITY_CVAR("r.RayTracing.Shadow.MaxDenoisedLights", -1); // unlimited

			// these apply to various RT effects but mostly reflections+translucency
			QUALITY_CVAR_AT_LEAST("r.raytracing.lighting.maxshadowlights", 256); // as seen in reflections/translucencies
			QUALITY_CVAR_AT_LEAST("r.RayTracing.lighting.maxlights", 256); // as seen in reflections/translucencies
		}

		 // these are some extreme settings whose quality:risk ratio may be debatable or unproven
		if (CVarExtreme->GetInt())
		{
			// great idea but not until I've proven that this isn't deadly or extremely slow on lower-spec machines:
			QUALITY_CVAR("r.Streaming.LimitPoolSizeToVRAM", 0); // 0 is aggressive but is it safe? seems safe.
			QUALITY_CVAR_AT_LEAST("r.Streaming.PoolSize", 3000); // cine - perhaps redundant when r.streaming.fullyloadusedtextures
			
			QUALITY_CVAR("r.streaming.hlodstrategy", 2); // probably use 0 if using r.streaming.fullyloadusedtextures, else 2
			//QUALITY_CVAR("r.streaming.fullyloadusedtextures", 1); // no - LODs oscillate when overcommitted
			QUALITY_CVAR_AT_LEAST("r.viewdistancescale", 10.f); // cinematic - extreme
			
			if (bRayTracingEnabled)
			{
				// higher-IQ thresholds
				QUALITY_CVAR_AT_LEAST("r.RayTracing.Translucency.MaxRoughness", 1.f); // speed hit
				QUALITY_CVAR_AT_LEAST("r.RayTracing.Reflections.MaxRoughness", 1.f); // speed hit
			
				//QUALITY_CVAR("r.ambientocclusionstaticfraction", 0.f); // trust RT AO/GI...? - needs more testing, doesn't seem a big win
			
				/*** EXTREME-QUALITY MODE FORCES GI ON ***/
				// first, some IQ:speed tweaks to make GI speed practical
				QUALITY_CVAR("r.raytracing.GlobalIllumination.rendertilesize", 128); // somewhat protect against long frames (from pumped-up quality) causing a device-disconnect
				QUALITY_CVAR("r.RayTracing.GlobalIllumination.ScreenPercentage", 50); // 50% = this is actually a quality DROP by default but it makes the GI speed practical -- requires >>>=2spp though
				QUALITY_CVAR("r.RayTracing.GlobalIllumination.MaxRayDistance", 7500); // ditto; most of the IQ benefit, but often faster than default huge ray distance
				QUALITY_CVAR_AT_LEAST("r.RayTracing.GlobalIllumination.SamplesPerPixel", 4); // at LEAST 2spp needed to reduce significant noise in some scenes, even up to 8+ helps
				QUALITY_CVAR_AT_LEAST("r.RayTracing.GlobalIllumination.NextEventEstimationSamples", 16); // 2==default; 16 necessary for low-light conditions when using only 4spp, else get blotches.  raising estimation samples cheaper than raising spp.
				QUALITY_CVAR_AT_LEAST("r.GlobalIllumination.Denoiser.ReconstructionSamples", 56/*=max*/); // better if only using 4spp @ quarter rez.  default is 16.
				//QUALITY_CVAR_AT_LEAST("r.RayTracing.GlobalIllumination.MaxBounces", 3); // 2+ is sometimes slightly noticable, sloww
				////QUALITY_CVAR("r.RayTracing.GlobalIllumination.EvalSkyLight", 1); // EXPERIMENTAL
				QUALITY_CVAR("r.RayTracing.GlobalIllumination", 1); // FORCE ON: should be fast enough to not TDR(!) with screenpercentage=50... usually a fair IQ win with random content... hidden behind 'EXTREME' mode until I've exercised it more.
			
				// just not hugely tested:
				QUALITY_CVAR_AT_LEAST("r.RayTracing.StochasticRectLight.SamplesPerPixel", 4);
				//QUALITY_CVAR("r.RayTracing.StochasticRectLight", 1); // 1==suspicious, probably broken
				QUALITY_CVAR_AT_LEAST("r.RayTracing.SkyLight.SamplesPerPixel", 4); // default==-1 UNPROVEN TRY ME
			}
			
			// just not hugely tested:
			QUALITY_CVAR("r.particlelodbias", -10);
			
			// unproven or possibly buggy
			//QUALITY_CVAR("r.streaming.useallmips", 1); // removes relative prioritization spec'd by app... unproven that this is a good idea
			//QUALITY_CVAR_AT_LEAST("r.streaming.boost", 9999); // 0 = supposedly use all available vram, but it looks like 0 = buggy
		}

#undef QUALITY_CVAR
#undef QUALITY_CVAR_AT_LEAST
#undef QUALITY_CVAR_AT_MOST
#undef QUALITY_CVAR_LOWPRIORITY_AT_LEAST
		UE_LOG(LogAnsel, Log, TEXT("Photography HQ mode actualized (enabled=%d)"), (int)bHighQualityModeDesired);
		bHighQualityModeIsSetup = bHighQualityModeDesired;
	}
	if (bAnselCaptureActive)
	{
		// camera doesn't linger in one place very long so maximize streaming rate
		SetCapturedCVar("r.disablelodfade", 1);
		SetCapturedCVar("r.streaming.framesforfullupdate", 1); // recalc required LODs ASAP
		SetCapturedCVar("r.Streaming.MaxNumTexturesToStreamPerFrame", 0); // no limit
		SetCapturedCVar("r.streaming.numstaticcomponentsprocessedperframe", 0); // 0 = load all pending static geom now
		if (bAutoPostprocess)
		{
			// force-disable the standard postprocessing effects which are known to
			// be problematic in multi-part shots

			// nerf remaining motion blur
			InOutPostProcessingSettings.bOverride_MotionBlurAmount = 1;
			InOutPostProcessingSettings.MotionBlurAmount = 0.f;

			// these effects tile poorly
			InOutPostProcessingSettings.bOverride_BloomDirtMaskIntensity = 1;
			InOutPostProcessingSettings.BloomDirtMaskIntensity = 0.f;
			InOutPostProcessingSettings.bOverride_LensFlareIntensity = 1;
			InOutPostProcessingSettings.LensFlareIntensity = 0.f;
			InOutPostProcessingSettings.bOverride_VignetteIntensity = 1;
			InOutPostProcessingSettings.VignetteIntensity = 0.f;
			InOutPostProcessingSettings.bOverride_SceneFringeIntensity = 1;
			InOutPostProcessingSettings.SceneFringeIntensity = 0.f;

			// freeze auto-exposure adaptation 
			InOutPostProcessingSettings.bOverride_AutoExposureSpeedDown = 0;
			InOutPostProcessingSettings.AutoExposureSpeedDown = 0.f;
			InOutPostProcessingSettings.bOverride_AutoExposureSpeedUp = 0;
			InOutPostProcessingSettings.AutoExposureSpeedUp = 0.f;

			// bring rendering up to (at least) full resolution
			if (InOutPostProcessingSettings.ScreenPercentage_DEPRECATED < 100.f)
			{
				// note: won't override r.screenpercentage set from console, that takes precedence
				InOutPostProcessingSettings.bOverride_ScreenPercentage_DEPRECATED = 1;
				InOutPostProcessingSettings.ScreenPercentage_DEPRECATED = 100.f;
			}
			bool bAnselSuperresCaptureActive = AnselCaptureInfo.captureType == ansel::kCaptureTypeSuperResolution;
			bool bAnselStereoCaptureActive = AnselCaptureInfo.captureType == ansel::kCaptureType360Stereo || AnselCaptureInfo.captureType == ansel::kCaptureTypeStereo;
			if (bAnselStereoCaptureActive)
			{
				// Attempt to nerf DoF in stereoscopic shots where it can be quite unpleasant for the viewer
				InOutPostProcessingSettings.bOverride_DepthOfFieldScale = 1;
				InOutPostProcessingSettings.DepthOfFieldScale = 0.f; // BokehDOF
				InOutPostProcessingSettings.bOverride_DepthOfFieldNearBlurSize = 1;
				InOutPostProcessingSettings.DepthOfFieldNearBlurSize = 0.f; // GaussianDOF
				InOutPostProcessingSettings.bOverride_DepthOfFieldFarBlurSize = 1;
				InOutPostProcessingSettings.DepthOfFieldFarBlurSize = 0.f; // GaussianDOF
				InOutPostProcessingSettings.bOverride_DepthOfFieldDepthBlurRadius = 1;
				InOutPostProcessingSettings.DepthOfFieldDepthBlurRadius = 0.f; // CircleDOF
				InOutPostProcessingSettings.bOverride_DepthOfFieldVignetteSize = 1;
				InOutPostProcessingSettings.DepthOfFieldVignetteSize = 200.f; // Scene.h says 200.0 means 'no effect'
			}
			if (!bAnselSuperresCaptureActive)
			{
				// Disable SSR in multi-part shots unless taking a super-resolution shot; SSR *usually* degrades gracefully in tiled shots, and super-resolution mode in Ansel has an 'enhance' option which repairs any lingering SSR artifacts quite well.
				InOutPostProcessingSettings.bOverride_ScreenSpaceReflectionIntensity = 1;
				InOutPostProcessingSettings.ScreenSpaceReflectionIntensity = 0.f;
			}
		}
	}
}


void FNVAnselCameraPhotographyPrivate::SetUpSessionCVars()
{
	// This set of CVar tweaks are good - or necessary - for photographic sessions
	{
		SetCapturedCVar("r.oneframethreadlag", 1); // ansel needs frame latency to be predictable

		// these are okay tweaks to streaming heuristics to reduce latency of full texture loads or minimize VRAM waste
		SetCapturedCVar("r.streaming.minmipforsplitrequest", 1); // strictly prioritize what's visible right now
		SetCapturedCVar("r.streaming.hiddenprimitivescale", 0.001f); // hint to engine to deprioritize obscured textures...?
		SetCapturedCVar("r.Streaming.Boost", 1);

		SetCapturedCVar("r.motionblurquality", 0); // this nerfs motion blur for non-characters
	}
}

void FNVAnselCameraPhotographyPrivate::UpdatePostProcessing(FPostProcessSettings& InOutPostProcessingSettings)
{
	if (bAnselSessionActive)
	{
		DoCustomUIControls(InOutPostProcessingSettings, bUIControlsNeedRebuild);

		ConfigureRenderingSettingsForPhotography(InOutPostProcessingSettings);
	}
}

void FNVAnselCameraPhotographyPrivate::StartSession()
{
	ansel::startSession();
}

void FNVAnselCameraPhotographyPrivate::StopSession()
{
	ansel::stopSession();
}

void FNVAnselCameraPhotographyPrivate::DefaultConstrainCamera(const FVector NewCameraLocation, const FVector PreviousCameraLocation, const FVector OriginalCameraLocation, FVector& OutCameraLocation, APlayerCameraManager* PCMgr)
{
	// let proposed camera through unmodified by default
	OutCameraLocation = NewCameraLocation;

	// First, constrain by distance
	FVector ConstrainedLocation;
	float MaxDistance = CVarConstrainCameraDistance->GetFloat();
	UAnselFunctionLibrary::ConstrainCameraByDistance(PCMgr, NewCameraLocation, PreviousCameraLocation, OriginalCameraLocation, ConstrainedLocation, MaxDistance);

	// Second, constrain against collision geometry
	UAnselFunctionLibrary::ConstrainCameraByGeometry(PCMgr, ConstrainedLocation, PreviousCameraLocation, OriginalCameraLocation, OutCameraLocation);
}

ansel::StartSessionStatus FNVAnselCameraPhotographyPrivate::AnselStartSessionCallback(ansel::SessionConfiguration& settings, void* userPointer)
{
	ansel::StartSessionStatus AnselSessionStatus = ansel::kDisallowed;
	FNVAnselCameraPhotographyPrivate* PrivateImpl = static_cast<FNVAnselCameraPhotographyPrivate*>(userPointer);
	check(PrivateImpl != nullptr);

	if (!PrivateImpl->bForceDisallow && CVarPhotographyAllow->GetInt() && !GIsEditor)
	{
		bool bPauseAllowed = true;
		bool bEnableMultipart = !!CVarPhotographyEnableMultipart->GetInt();

		settings.isTranslationAllowed = true;
		settings.isFovChangeAllowed = !PrivateImpl->bIsOrthoProjection;
		settings.isRotationAllowed = true;
		settings.isPauseAllowed = bPauseAllowed;
		settings.isHighresAllowed = bEnableMultipart;
		settings.is360MonoAllowed = bEnableMultipart;
		settings.is360StereoAllowed = bEnableMultipart;

		PrivateImpl->bAnselSessionActive = true;
		PrivateImpl->bAnselSessionNewlyActive = true;
		PrivateImpl->bHighQualityModeDesired = false;

		AnselSessionStatus = ansel::kAllowed;
	}

	UE_LOG(LogAnsel, Log, TEXT("Photography camera session attempt started, Allowed=%d, ForceDisallowed=%d"), int(AnselSessionStatus == ansel::kAllowed), int(PrivateImpl->bForceDisallow));

	return AnselSessionStatus;
}

void FNVAnselCameraPhotographyPrivate::AnselStopSessionCallback(void* userPointer)
{
	FNVAnselCameraPhotographyPrivate* PrivateImpl = static_cast<FNVAnselCameraPhotographyPrivate*>(userPointer);
	check(PrivateImpl != nullptr);
	if (PrivateImpl->bAnselSessionActive && PrivateImpl->bAnselSessionNewlyActive)
	{
		// if we've not acted upon the new session at all yet, then just don't.
		PrivateImpl->bAnselSessionActive = false;
	}
	else
	{
		PrivateImpl->bAnselSessionWantDeactivate = true;
	}

	UE_LOG(LogAnsel, Log, TEXT("Photography camera session end"));
}

void FNVAnselCameraPhotographyPrivate::AnselStartCaptureCallback(const ansel::CaptureConfiguration& CaptureInfo, void* userPointer)
{
	FNVAnselCameraPhotographyPrivate* PrivateImpl = static_cast<FNVAnselCameraPhotographyPrivate*>(userPointer);
	check(PrivateImpl != nullptr);
	PrivateImpl->bAnselCaptureActive = true;
	PrivateImpl->bAnselCaptureNewlyActive = true;
	PrivateImpl->AnselCaptureInfo = CaptureInfo;

	UE_LOG(LogAnsel, Log, TEXT("Photography camera multi-part capture started"));
}

void FNVAnselCameraPhotographyPrivate::AnselStopCaptureCallback(void* userPointer)
{
	FNVAnselCameraPhotographyPrivate* PrivateImpl = static_cast<FNVAnselCameraPhotographyPrivate*>(userPointer);
	check(PrivateImpl != nullptr);
	PrivateImpl->bAnselCaptureActive = false;
	PrivateImpl->bAnselCaptureNewlyFinished = true;

	UE_LOG(LogAnsel, Log, TEXT("Photography camera multi-part capture end"));
}

void FNVAnselCameraPhotographyPrivate::AnselChangeQualityCallback(bool isHighQuality, void* ACPPuserPointer)
{
	FNVAnselCameraPhotographyPrivate* PrivateImpl = static_cast<FNVAnselCameraPhotographyPrivate*>(ACPPuserPointer);
	check(PrivateImpl != nullptr);
	PrivateImpl->bHighQualityModeDesired = isHighQuality;

	UE_LOG(LogAnsel, Log, TEXT("Photography HQ mode toggle (%d)"), (int)isHighQuality);
}

void FNVAnselCameraPhotographyPrivate::ReconfigureAnsel()
{
	check(AnselConfig != nullptr);
	AnselConfig->userPointer = this;
	AnselConfig->startSessionCallback = AnselStartSessionCallback;
	AnselConfig->stopSessionCallback = AnselStopSessionCallback;
	AnselConfig->startCaptureCallback = AnselStartCaptureCallback;
	AnselConfig->stopCaptureCallback = AnselStopCaptureCallback;
	AnselConfig->changeQualityCallback = AnselChangeQualityCallback;

	// Getting fovType wrong can lead to multi-part captures stitching incorrectly, especially 360 shots
	AnselConfig->fovType = RequiredFovType;
	
	if (GEngine->GameViewport && GEngine->GameViewport->GetWindow().IsValid() && GEngine->GameViewport->GetWindow()->GetNativeWindow().IsValid())
	{
		AnselConfig->gameWindowHandle = GEngine->GameViewport->GetWindow()->GetNativeWindow()->GetOSWindowHandle();
	}
	UE_LOG(LogAnsel, Log, TEXT("gameWindowHandle= %p"), AnselConfig->gameWindowHandle);

	AnselConfig->translationalSpeedInWorldUnitsPerSecond = CVarPhotographyTranslationSpeed->GetFloat();

	AnselConfig->metersInWorldUnit = 1.0f / RequiredWorldToMeters;
	UE_LOG(LogAnsel, Log, TEXT("We reckon %f meters to 1 world unit"), AnselConfig->metersInWorldUnit);

	AnselConfig->isCameraOffcenteredProjectionSupported = true;

	AnselConfig->captureLatency = 0; // important

	AnselConfig->captureSettleLatency = CVarPhotographySettleFrames->GetInt();

	ansel::SetConfigurationStatus status = ansel::setConfiguration(*AnselConfig);
	if (status != ansel::kSetConfigurationSuccess)
	{
		UE_LOG(LogAnsel, Log, TEXT("ReconfigureAnsel setConfiguration returned %ld"), (long int)(status));
	}

	CurrentlyConfiguredFovType = RequiredFovType;
	CurrentlyConfiguredWorldToMeters = RequiredWorldToMeters;
}

void FNVAnselCameraPhotographyPrivate::DeconfigureAnsel()
{
	check(AnselConfig != nullptr);

	AnselConfig->userPointer = nullptr;
	AnselConfig->startSessionCallback = nullptr;
	AnselConfig->stopSessionCallback = nullptr;
	AnselConfig->startCaptureCallback = nullptr;
	AnselConfig->stopCaptureCallback = nullptr;
	AnselConfig->gameWindowHandle = nullptr;
	ansel::SetConfigurationStatus status = ansel::setConfiguration(*AnselConfig);
	if (status != ansel::kSetConfigurationSuccess)
	{
		UE_LOG(LogAnsel, Log, TEXT("DeconfigureAnsel setConfiguration returned %ld"), (long int)(status));
	}
}

class FAnselModule : public IAnselModule
{
public:
	virtual void StartupModule() override
	{
		ICameraPhotographyModule::StartupModule();
		check(!bAnselDLLLoaded);

		// Late-load Ansel DLL.  DLL name has been worked out by the build scripts as ANSEL_DLL
		FString AnselDLLName;
		FString AnselBinariesRoot = FPaths::FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("Ansel"))->GetBaseDir(),TEXT("/Binaries/ThirdParty/"));
		// common preprocessor fudge to convert macro expansion into string
#define STRINGIFY(X) STRINGIFY2(X)
#define STRINGIFY2(X) #X
			AnselDLLName = AnselBinariesRoot + TEXT(STRINGIFY(ANSEL_DLL));
			AnselSDKDLLHandle = FPlatformProcess::GetDllHandle(*(AnselDLLName));

		bAnselDLLLoaded = AnselSDKDLLHandle != 0;
		UE_LOG(LogAnsel, Log, TEXT("Tried to load %s : success=%d"), *AnselDLLName, int(bAnselDLLLoaded));
	}

	virtual void ShutdownModule() override
	{		
		if (bAnselDLLLoaded)
		{
			FPlatformProcess::FreeDllHandle(AnselSDKDLLHandle);
			AnselSDKDLLHandle = 0;
			bAnselDLLLoaded = false;
		}
		ICameraPhotographyModule::ShutdownModule();
	}
private:

	virtual TSharedPtr< class ICameraPhotography > CreateCameraPhotography() override
	{
		TSharedPtr<ICameraPhotography> Photography = nullptr;

		FNVAnselCameraPhotographyPrivate* PhotographyPrivate = new FNVAnselCameraPhotographyPrivate();
		if (PhotographyPrivate->IsSupported())
		{
			Photography = TSharedPtr<ICameraPhotography>(PhotographyPrivate);
		}
		else
		{
			delete PhotographyPrivate;
		}

		return Photography;
	}
};

IMPLEMENT_MODULE(FAnselModule, Ansel)

#undef LOCTEXT_NAMESPACE