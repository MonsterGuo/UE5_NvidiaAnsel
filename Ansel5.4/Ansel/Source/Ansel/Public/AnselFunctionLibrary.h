// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "AnselFunctionLibrary.generated.h"

UENUM(BlueprintType)
enum EUIControlEffectTarget
{
	Bloom,
	DepthOfField,
	ChromaticAberration,
	MotionBlur
};

UCLASS()
class ANSEL_API UAnselFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Starts a photography session */
	UFUNCTION(BlueprintCallable, Category = "Photography", meta = (WorldContext = WorldContextObject))
	static void StartSession(UObject* WorldContextObject);

	/** Stops a photography session */
	UFUNCTION(BlueprintCallable, Category = "Photography", meta = (WorldContext = WorldContextObject))
	static void StopSession(UObject* WorldContextObject);

	/** Whether the photography system is available at all.  See CVar r.Photography.Available */
	UFUNCTION(BlueprintCallable, Category = "Photography")
	static bool IsPhotographyAvailable();

	/** Whether the app is permitting photography at this time.  See CVar r.Photography.Allowed */
	UFUNCTION(BlueprintCallable, Category = "Photography")
	static bool IsPhotographyAllowed();

	/** Sets whether the app is permitting photography at this time.  See CVar r.Photography.Allowed */
	UFUNCTION(BlueprintCallable, Category = "Photography")
	static void SetIsPhotographyAllowed(const bool bIsPhotographyAllowed);

	/** Sets the number of frames between captures in a multi-part shot.  See CVar r.Photography.SettleFrames */
	UFUNCTION(BlueprintCallable, Category = "Photography")
	static void SetSettleFrames(const int NumSettleFrames);

	/** Sets the normal speed of movement of the photography camera.  See CVar r.Photography.TranslationSpeed */
	UFUNCTION(BlueprintCallable, Category = "Photography")
	static void SetCameraMovementSpeed(const float TranslationSpeed);

	/** Sets the size of the photography camera for collision purposes; only relevant when default implementation of PlayerCameraManager's PhotographyCameraModify function is used.  See CVar r.Photography.Constrain.CameraSize */
	UFUNCTION(BlueprintCallable, Category = "Photography")
	static void SetCameraConstraintCameraSize(const float CameraSize);

	/** Sets maximum distance which the camera is allowed to wander from its initial position; only relevant when default implementation of PlayerCameraManager's PhotographyCameraModify function is used.  See CVar r.Photography.Constrain.MaxCameraDistance */
	UFUNCTION(BlueprintCallable, Category = "Photography")
	static void SetCameraConstraintDistance(const float MaxCameraDistance);

	/** Sets whether the photography system automatically tries to optimize Unreal's postprocessing effects for photography.  See CVar r.Photography.AutoPostprocess */
	UFUNCTION(BlueprintCallable, Category = "Photography")
	static void SetAutoPostprocess(const bool bShouldAutoPostprocess);

	/** Sets whether the photography system automatically pauses the game during a photography session.  See CVar r.Photography.AutoPause */
	UFUNCTION(BlueprintCallable, Category = "Photography")
	static void SetAutoPause(const bool bShouldAutoPause);

	/** Show or hide controls in the photography UI which let the player tweak standard UE visual effects during photography - for example, depth of field or chromatic aberration.  Note: these controls only exist when SetAutoPostprocess is turned on.  Some may not apply to your application either because you are not using the associated effect or you are using a custom version of the effect. */
	UFUNCTION(BlueprintCallable, Category = "Photography", meta = (WorldContext = WorldContextObject))
	static void SetUIControlVisibility(UObject* WorldContextObject, const TEnumAsByte<EUIControlEffectTarget> UIControlTarget, const bool bIsVisible);

	/** A utility which constrains distance of camera from its start point; may be useful when implementing a custom APlayerCameraManager::PhotographyCameraModify */
	UFUNCTION(BlueprintCallable, Category = "Photography", meta = (WorldContext = WorldContextObject))
	static void ConstrainCameraByDistance(UObject* WorldContextObject, const FVector NewCameraLocation, const FVector PreviousCameraLocation, const FVector OriginalCameraLocation, FVector& OutCameraLocation, float MaxDistance);

	/** A utility which constrains the camera against collidable geometry; may be useful when implementing a custom APlayerCameraManager::PhotographyCameraModify */
	UFUNCTION(BlueprintCallable, Category = "Photography", meta = (WorldContext = WorldContextObject))
	static void ConstrainCameraByGeometry(UObject* WorldContextObject, const FVector NewCameraLocation, const FVector PreviousCameraLocation, const FVector OriginalCameraLocation, FVector& OutCameraLocation);
};
