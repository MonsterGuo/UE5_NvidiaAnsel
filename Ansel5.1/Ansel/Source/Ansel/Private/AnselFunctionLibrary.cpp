// Copyright Epic Games, Inc. All Rights Reserved.

#include "AnselFunctionLibrary.h"

#include "Engine/Engine.h"
#include "Camera/CameraPhotography.h"

static FCameraPhotographyManager* GetPhotographyManager(UObject* WorldContextObject)
{
	UEngine* Engine = GEngine;
	if (Engine)
	{
		UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull);
		if (World)
		{
			if (FCameraPhotographyManager::IsSupported(World))
			{
				return &FCameraPhotographyManager::Get();
			}
		}
	}

	return nullptr;
}

static void StartOrStopSession(bool bStartSession, UObject* WorldContextObject)
{
	FCameraPhotographyManager *PhotoMgr = GetPhotographyManager(WorldContextObject);
	if (PhotoMgr)
	{
		if (bStartSession)
		{
			PhotoMgr->StartSession();
		}
		else
		{
			PhotoMgr->StopSession();
		}
	}
}

void UAnselFunctionLibrary::StartSession(UObject* WorldContextObject)
{
	StartOrStopSession(true, WorldContextObject);
}

void UAnselFunctionLibrary::StopSession(UObject* WorldContextObject)
{
	StartOrStopSession(false, WorldContextObject);
}

bool UAnselFunctionLibrary::IsPhotographyAvailable(void)
{
	static IConsoleVariable* CVarPhotographyAvailable = IConsoleManager::Get().FindConsoleVariable(TEXT("r.Photography.Available"));
	return CVarPhotographyAvailable && CVarPhotographyAvailable->GetInt() != 0;
}

bool UAnselFunctionLibrary::IsPhotographyAllowed(void)
{
	static IConsoleVariable* CVarPhotographyAllowed = IConsoleManager::Get().FindConsoleVariable(TEXT("r.Photography.Allow"));
	return CVarPhotographyAllowed && CVarPhotographyAllowed->GetInt() != 0;
}

void UAnselFunctionLibrary::SetIsPhotographyAllowed(const bool bIsPhotographyAllowed)
{
	static IConsoleVariable* CVarPhotographyAllowed = IConsoleManager::Get().FindConsoleVariable(TEXT("r.Photography.Allow"));
	if (CVarPhotographyAllowed)
	{
		CVarPhotographyAllowed->Set(bIsPhotographyAllowed ? 1 : 0);
	}
}

void UAnselFunctionLibrary::SetSettleFrames(const int NumSettleFrames)
{
	static IConsoleVariable* CVarNumSettleFrames = IConsoleManager::Get().FindConsoleVariable(TEXT("r.Photography.SettleFrames"));
	if (CVarNumSettleFrames)
	{
		CVarNumSettleFrames->Set(NumSettleFrames);
	}
}

void UAnselFunctionLibrary::SetCameraMovementSpeed(const float TranslationSpeed)
{
	static IConsoleVariable* CVarTranslationSpeed = IConsoleManager::Get().FindConsoleVariable(TEXT("r.Photography.TranslationSpeed"));
	if (CVarTranslationSpeed)
	{
		CVarTranslationSpeed->Set(TranslationSpeed);
	}
}

void UAnselFunctionLibrary::SetCameraConstraintCameraSize(const float CameraSize)
{
	static IConsoleVariable* CVarCameraSize = IConsoleManager::Get().FindConsoleVariable(TEXT("r.Photography.Constrain.CameraSize"));
	if (CVarCameraSize)
	{
		CVarCameraSize->Set(CameraSize);
	}
}

void UAnselFunctionLibrary::SetCameraConstraintDistance(const float MaxCameraDistance)
{
	static IConsoleVariable* CVarCameraDistance = IConsoleManager::Get().FindConsoleVariable(TEXT("r.Photography.Constrain.MaxCameraDistance"));
	if (CVarCameraDistance)
	{
		CVarCameraDistance->Set(MaxCameraDistance);
	}
}

void UAnselFunctionLibrary::SetAutoPostprocess(const bool bShouldAutoPostprocess)
{
	static IConsoleVariable* CVarAutoPostprocess = IConsoleManager::Get().FindConsoleVariable(TEXT("r.Photography.AutoPostprocess"));
	if (CVarAutoPostprocess)
	{
		CVarAutoPostprocess->Set(bShouldAutoPostprocess ? 1 : 0);
	}
}

void UAnselFunctionLibrary::SetAutoPause(const bool bShouldAutoPause)
{
	static IConsoleVariable* CVarAutoPause = IConsoleManager::Get().FindConsoleVariable(TEXT("r.Photography.AutoPause"));
	if (CVarAutoPause)
	{
		CVarAutoPause->Set(bShouldAutoPause ? 1 : 0);
	}
}

void UAnselFunctionLibrary::SetUIControlVisibility(UObject* WorldContextObject, const TEnumAsByte<EUIControlEffectTarget> UIControlTarget, const bool bIsVisible)
{
	FCameraPhotographyManager *PhotoMgr = GetPhotographyManager(WorldContextObject);
	if (PhotoMgr)
	{
		PhotoMgr->SetUIControlVisibility(UIControlTarget, bIsVisible);
	}
}

void UAnselFunctionLibrary::ConstrainCameraByDistance(UObject* WorldContextObject, const FVector NewCameraLocation, const FVector PreviousCameraLocation, const FVector OriginalCameraLocation, FVector& OutCameraLocation, float MaxDistance)
{
	if (MaxDistance < 0.f)
	{
		// no constraint by distance
		OutCameraLocation = NewCameraLocation;
		return;
	}

	FVector MovementVector = NewCameraLocation - OriginalCameraLocation;
	MovementVector = MovementVector.GetClampedToMaxSize(MaxDistance);
	OutCameraLocation = OriginalCameraLocation + MovementVector;
}

void UAnselFunctionLibrary::ConstrainCameraByGeometry(UObject* WorldContextObject, const FVector NewCameraLocation, const FVector PreviousCameraLocation, const FVector OriginalCameraLocation, FVector& OutCameraLocation)
{
	OutCameraLocation = NewCameraLocation; // accept new camera position by default

	static IConsoleVariable* CVarConstrainCameraSizeLocal = IConsoleManager::Get().FindConsoleVariable(TEXT("r.Photography.Constrain.CameraSize"));
	const float CameraRadius = CVarConstrainCameraSizeLocal->GetFloat();

	if (CameraRadius < 0.f)
	{
		// no constraint by collisions
		return;
	}

	const float OpenSpaceRadius = 2.f * CameraRadius; // Minimum free space around camera for it to be considered unconfined

	static FVector LastUnconfinedScreenshotCamera = OriginalCameraLocation;
	if (PreviousCameraLocation == OriginalCameraLocation)
	{
		LastUnconfinedScreenshotCamera = OriginalCameraLocation;
	}

	UWorld *World = WorldContextObject->GetWorld();
	ECollisionChannel TraceChannel = ECC_Camera;

	FCollisionShape CameraCollisionShape = FCollisionShape::MakeSphere(CameraRadius);
	FCollisionShape OpenSpaceCollisionShape = FCollisionShape::MakeSphere(OpenSpaceRadius);

	FVector SweepStart = LastUnconfinedScreenshotCamera;
	FVector SweepEnd = NewCameraLocation;
	FVector CastDirection = SweepEnd - SweepStart;

	if (CastDirection.IsNearlyZero())
	{
		return; // just accept new camera position
	}

	FHitResult HitResult;

	// if our idea of an open space is actually significantly occupied - this may occur when the original camera is inside geometry - then skip the sweep and allow unconstrained camera movement until we've found a new open space

	if (World->OverlapAnyTestByChannel(LastUnconfinedScreenshotCamera, FQuat::Identity, TraceChannel, CameraCollisionShape))
	{
		OutCameraLocation = NewCameraLocation;
	}
	else
	{
		// enforce camera origin remaining in line-of-sight from centre of an open space
		if (World->SweepSingleByChannel(HitResult, SweepStart, SweepEnd, FQuat::Identity, TraceChannel, CameraCollisionShape))
		{
			OutCameraLocation = HitResult.Location;
		}
	}

	// Reject proposed camera positions which move the camera away from the rough direction which the user intends
	if (FVector::DotProduct(OutCameraLocation - PreviousCameraLocation, NewCameraLocation - PreviousCameraLocation) <= 0)
	{
		OutCameraLocation = PreviousCameraLocation;
	}

	// Try to move the tracked open space origin relative to the camera movement, if there's space
	FVector OpenSpaceCheckPos = LastUnconfinedScreenshotCamera + (OutCameraLocation - PreviousCameraLocation);

	if (! World->OverlapAnyTestByChannel(OpenSpaceCheckPos, FQuat::Identity, TraceChannel, OpenSpaceCollisionShape))
	{
		LastUnconfinedScreenshotCamera = OpenSpaceCheckPos;
	}
	else
	{
		// proposed open space is blocked, check if new camera position centers on an open space
		if (! World->OverlapAnyTestByChannel(OutCameraLocation, FQuat::Identity, TraceChannel, OpenSpaceCollisionShape))
		{
			LastUnconfinedScreenshotCamera = OutCameraLocation;
		}
	}
}
