// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Ansel/Public/AnselFunctionLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnselFunctionLibrary() {}
// Cross Module References
	ANSEL_API UClass* Z_Construct_UClass_UAnselFunctionLibrary();
	ANSEL_API UClass* Z_Construct_UClass_UAnselFunctionLibrary_NoRegister();
	ANSEL_API UEnum* Z_Construct_UEnum_Ansel_EUIControlEffectTarget();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_Ansel();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EUIControlEffectTarget;
	static UEnum* EUIControlEffectTarget_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EUIControlEffectTarget.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EUIControlEffectTarget.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Ansel_EUIControlEffectTarget, Z_Construct_UPackage__Script_Ansel(), TEXT("EUIControlEffectTarget"));
		}
		return Z_Registration_Info_UEnum_EUIControlEffectTarget.OuterSingleton;
	}
	template<> ANSEL_API UEnum* StaticEnum<EUIControlEffectTarget>()
	{
		return EUIControlEffectTarget_StaticEnum();
	}
	struct Z_Construct_UEnum_Ansel_EUIControlEffectTarget_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_Ansel_EUIControlEffectTarget_Statics::Enumerators[] = {
		{ "Bloom", (int64)Bloom },
		{ "DepthOfField", (int64)DepthOfField },
		{ "ChromaticAberration", (int64)ChromaticAberration },
		{ "MotionBlur", (int64)MotionBlur },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_Ansel_EUIControlEffectTarget_Statics::Enum_MetaDataParams[] = {
		{ "Bloom.Name", "Bloom" },
		{ "BlueprintType", "true" },
		{ "ChromaticAberration.Name", "ChromaticAberration" },
		{ "DepthOfField.Name", "DepthOfField" },
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
		{ "MotionBlur.Name", "MotionBlur" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Ansel_EUIControlEffectTarget_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_Ansel,
		nullptr,
		"EUIControlEffectTarget",
		"EUIControlEffectTarget",
		Z_Construct_UEnum_Ansel_EUIControlEffectTarget_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_Ansel_EUIControlEffectTarget_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(Z_Construct_UEnum_Ansel_EUIControlEffectTarget_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_Ansel_EUIControlEffectTarget_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_Ansel_EUIControlEffectTarget()
	{
		if (!Z_Registration_Info_UEnum_EUIControlEffectTarget.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EUIControlEffectTarget.InnerSingleton, Z_Construct_UEnum_Ansel_EUIControlEffectTarget_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EUIControlEffectTarget.InnerSingleton;
	}
	DEFINE_FUNCTION(UAnselFunctionLibrary::execConstrainCameraByGeometry)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_STRUCT(FVector,Z_Param_NewCameraLocation);
		P_GET_STRUCT(FVector,Z_Param_PreviousCameraLocation);
		P_GET_STRUCT(FVector,Z_Param_OriginalCameraLocation);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_OutCameraLocation);
		P_FINISH;
		P_NATIVE_BEGIN;
		UAnselFunctionLibrary::ConstrainCameraByGeometry(Z_Param_WorldContextObject,Z_Param_NewCameraLocation,Z_Param_PreviousCameraLocation,Z_Param_OriginalCameraLocation,Z_Param_Out_OutCameraLocation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAnselFunctionLibrary::execConstrainCameraByDistance)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_STRUCT(FVector,Z_Param_NewCameraLocation);
		P_GET_STRUCT(FVector,Z_Param_PreviousCameraLocation);
		P_GET_STRUCT(FVector,Z_Param_OriginalCameraLocation);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_OutCameraLocation);
		P_GET_PROPERTY(FFloatProperty,Z_Param_MaxDistance);
		P_FINISH;
		P_NATIVE_BEGIN;
		UAnselFunctionLibrary::ConstrainCameraByDistance(Z_Param_WorldContextObject,Z_Param_NewCameraLocation,Z_Param_PreviousCameraLocation,Z_Param_OriginalCameraLocation,Z_Param_Out_OutCameraLocation,Z_Param_MaxDistance);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAnselFunctionLibrary::execSetUIControlVisibility)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FByteProperty,Z_Param_UIControlTarget);
		P_GET_UBOOL(Z_Param_bIsVisible);
		P_FINISH;
		P_NATIVE_BEGIN;
		UAnselFunctionLibrary::SetUIControlVisibility(Z_Param_WorldContextObject,EUIControlEffectTarget(Z_Param_UIControlTarget),Z_Param_bIsVisible);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAnselFunctionLibrary::execSetAutoPause)
	{
		P_GET_UBOOL(Z_Param_bShouldAutoPause);
		P_FINISH;
		P_NATIVE_BEGIN;
		UAnselFunctionLibrary::SetAutoPause(Z_Param_bShouldAutoPause);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAnselFunctionLibrary::execSetAutoPostprocess)
	{
		P_GET_UBOOL(Z_Param_bShouldAutoPostprocess);
		P_FINISH;
		P_NATIVE_BEGIN;
		UAnselFunctionLibrary::SetAutoPostprocess(Z_Param_bShouldAutoPostprocess);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAnselFunctionLibrary::execSetCameraConstraintDistance)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_MaxCameraDistance);
		P_FINISH;
		P_NATIVE_BEGIN;
		UAnselFunctionLibrary::SetCameraConstraintDistance(Z_Param_MaxCameraDistance);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAnselFunctionLibrary::execSetCameraConstraintCameraSize)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_CameraSize);
		P_FINISH;
		P_NATIVE_BEGIN;
		UAnselFunctionLibrary::SetCameraConstraintCameraSize(Z_Param_CameraSize);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAnselFunctionLibrary::execSetCameraMovementSpeed)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_TranslationSpeed);
		P_FINISH;
		P_NATIVE_BEGIN;
		UAnselFunctionLibrary::SetCameraMovementSpeed(Z_Param_TranslationSpeed);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAnselFunctionLibrary::execSetSettleFrames)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_NumSettleFrames);
		P_FINISH;
		P_NATIVE_BEGIN;
		UAnselFunctionLibrary::SetSettleFrames(Z_Param_NumSettleFrames);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAnselFunctionLibrary::execSetIsPhotographyAllowed)
	{
		P_GET_UBOOL(Z_Param_bIsPhotographyAllowed);
		P_FINISH;
		P_NATIVE_BEGIN;
		UAnselFunctionLibrary::SetIsPhotographyAllowed(Z_Param_bIsPhotographyAllowed);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAnselFunctionLibrary::execIsPhotographyAllowed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UAnselFunctionLibrary::IsPhotographyAllowed();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAnselFunctionLibrary::execIsPhotographyAvailable)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UAnselFunctionLibrary::IsPhotographyAvailable();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAnselFunctionLibrary::execStopSession)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		UAnselFunctionLibrary::StopSession(Z_Param_WorldContextObject);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAnselFunctionLibrary::execStartSession)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		UAnselFunctionLibrary::StartSession(Z_Param_WorldContextObject);
		P_NATIVE_END;
	}
	void UAnselFunctionLibrary::StaticRegisterNativesUAnselFunctionLibrary()
	{
		UClass* Class = UAnselFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ConstrainCameraByDistance", &UAnselFunctionLibrary::execConstrainCameraByDistance },
			{ "ConstrainCameraByGeometry", &UAnselFunctionLibrary::execConstrainCameraByGeometry },
			{ "IsPhotographyAllowed", &UAnselFunctionLibrary::execIsPhotographyAllowed },
			{ "IsPhotographyAvailable", &UAnselFunctionLibrary::execIsPhotographyAvailable },
			{ "SetAutoPause", &UAnselFunctionLibrary::execSetAutoPause },
			{ "SetAutoPostprocess", &UAnselFunctionLibrary::execSetAutoPostprocess },
			{ "SetCameraConstraintCameraSize", &UAnselFunctionLibrary::execSetCameraConstraintCameraSize },
			{ "SetCameraConstraintDistance", &UAnselFunctionLibrary::execSetCameraConstraintDistance },
			{ "SetCameraMovementSpeed", &UAnselFunctionLibrary::execSetCameraMovementSpeed },
			{ "SetIsPhotographyAllowed", &UAnselFunctionLibrary::execSetIsPhotographyAllowed },
			{ "SetSettleFrames", &UAnselFunctionLibrary::execSetSettleFrames },
			{ "SetUIControlVisibility", &UAnselFunctionLibrary::execSetUIControlVisibility },
			{ "StartSession", &UAnselFunctionLibrary::execStartSession },
			{ "StopSession", &UAnselFunctionLibrary::execStopSession },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics
	{
		struct AnselFunctionLibrary_eventConstrainCameraByDistance_Parms
		{
			UObject* WorldContextObject;
			FVector NewCameraLocation;
			FVector PreviousCameraLocation;
			FVector OriginalCameraLocation;
			FVector OutCameraLocation;
			float MaxDistance;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NewCameraLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_NewCameraLocation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PreviousCameraLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_PreviousCameraLocation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OriginalCameraLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_OriginalCameraLocation;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutCameraLocation;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxDistance;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AnselFunctionLibrary_eventConstrainCameraByDistance_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::NewProp_NewCameraLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::NewProp_NewCameraLocation = { "NewCameraLocation", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AnselFunctionLibrary_eventConstrainCameraByDistance_Parms, NewCameraLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::NewProp_NewCameraLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::NewProp_NewCameraLocation_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::NewProp_PreviousCameraLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::NewProp_PreviousCameraLocation = { "PreviousCameraLocation", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AnselFunctionLibrary_eventConstrainCameraByDistance_Parms, PreviousCameraLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::NewProp_PreviousCameraLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::NewProp_PreviousCameraLocation_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::NewProp_OriginalCameraLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::NewProp_OriginalCameraLocation = { "OriginalCameraLocation", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AnselFunctionLibrary_eventConstrainCameraByDistance_Parms, OriginalCameraLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::NewProp_OriginalCameraLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::NewProp_OriginalCameraLocation_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::NewProp_OutCameraLocation = { "OutCameraLocation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AnselFunctionLibrary_eventConstrainCameraByDistance_Parms, OutCameraLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::NewProp_MaxDistance = { "MaxDistance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AnselFunctionLibrary_eventConstrainCameraByDistance_Parms, MaxDistance), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::NewProp_NewCameraLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::NewProp_PreviousCameraLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::NewProp_OriginalCameraLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::NewProp_OutCameraLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::NewProp_MaxDistance,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::Function_MetaDataParams[] = {
		{ "Category", "Photography" },
		{ "Comment", "/** A utility which constrains distance of camera from its start point; may be useful when implementing a custom APlayerCameraManager::PhotographyCameraModify */" },
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
		{ "ToolTip", "A utility which constrains distance of camera from its start point; may be useful when implementing a custom APlayerCameraManager::PhotographyCameraModify" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "ConstrainCameraByDistance", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::AnselFunctionLibrary_eventConstrainCameraByDistance_Parms), Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics
	{
		struct AnselFunctionLibrary_eventConstrainCameraByGeometry_Parms
		{
			UObject* WorldContextObject;
			FVector NewCameraLocation;
			FVector PreviousCameraLocation;
			FVector OriginalCameraLocation;
			FVector OutCameraLocation;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NewCameraLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_NewCameraLocation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PreviousCameraLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_PreviousCameraLocation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OriginalCameraLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_OriginalCameraLocation;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutCameraLocation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AnselFunctionLibrary_eventConstrainCameraByGeometry_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::NewProp_NewCameraLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::NewProp_NewCameraLocation = { "NewCameraLocation", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AnselFunctionLibrary_eventConstrainCameraByGeometry_Parms, NewCameraLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::NewProp_NewCameraLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::NewProp_NewCameraLocation_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::NewProp_PreviousCameraLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::NewProp_PreviousCameraLocation = { "PreviousCameraLocation", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AnselFunctionLibrary_eventConstrainCameraByGeometry_Parms, PreviousCameraLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::NewProp_PreviousCameraLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::NewProp_PreviousCameraLocation_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::NewProp_OriginalCameraLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::NewProp_OriginalCameraLocation = { "OriginalCameraLocation", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AnselFunctionLibrary_eventConstrainCameraByGeometry_Parms, OriginalCameraLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::NewProp_OriginalCameraLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::NewProp_OriginalCameraLocation_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::NewProp_OutCameraLocation = { "OutCameraLocation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AnselFunctionLibrary_eventConstrainCameraByGeometry_Parms, OutCameraLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::NewProp_NewCameraLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::NewProp_PreviousCameraLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::NewProp_OriginalCameraLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::NewProp_OutCameraLocation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::Function_MetaDataParams[] = {
		{ "Category", "Photography" },
		{ "Comment", "/** A utility which constrains the camera against collidable geometry; may be useful when implementing a custom APlayerCameraManager::PhotographyCameraModify */" },
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
		{ "ToolTip", "A utility which constrains the camera against collidable geometry; may be useful when implementing a custom APlayerCameraManager::PhotographyCameraModify" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "ConstrainCameraByGeometry", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::AnselFunctionLibrary_eventConstrainCameraByGeometry_Parms), Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAllowed_Statics
	{
		struct AnselFunctionLibrary_eventIsPhotographyAllowed_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAllowed_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((AnselFunctionLibrary_eventIsPhotographyAllowed_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAllowed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(AnselFunctionLibrary_eventIsPhotographyAllowed_Parms), &Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAllowed_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAllowed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAllowed_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAllowed_Statics::Function_MetaDataParams[] = {
		{ "Category", "Photography" },
		{ "Comment", "/** Whether the app is permitting photography at this time.  See CVar r.Photography.Allowed */" },
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
		{ "ToolTip", "Whether the app is permitting photography at this time.  See CVar r.Photography.Allowed" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAllowed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "IsPhotographyAllowed", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAllowed_Statics::AnselFunctionLibrary_eventIsPhotographyAllowed_Parms), Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAllowed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAllowed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAllowed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAllowed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAllowed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAllowed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAvailable_Statics
	{
		struct AnselFunctionLibrary_eventIsPhotographyAvailable_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAvailable_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((AnselFunctionLibrary_eventIsPhotographyAvailable_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAvailable_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(AnselFunctionLibrary_eventIsPhotographyAvailable_Parms), &Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAvailable_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAvailable_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAvailable_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAvailable_Statics::Function_MetaDataParams[] = {
		{ "Category", "Photography" },
		{ "Comment", "/** Whether the photography system is available at all.  See CVar r.Photography.Available */" },
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
		{ "ToolTip", "Whether the photography system is available at all.  See CVar r.Photography.Available" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAvailable_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "IsPhotographyAvailable", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAvailable_Statics::AnselFunctionLibrary_eventIsPhotographyAvailable_Parms), Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAvailable_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAvailable_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAvailable_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAvailable_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAvailable()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAvailable_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPause_Statics
	{
		struct AnselFunctionLibrary_eventSetAutoPause_Parms
		{
			bool bShouldAutoPause;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bShouldAutoPause_MetaData[];
#endif
		static void NewProp_bShouldAutoPause_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShouldAutoPause;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPause_Statics::NewProp_bShouldAutoPause_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPause_Statics::NewProp_bShouldAutoPause_SetBit(void* Obj)
	{
		((AnselFunctionLibrary_eventSetAutoPause_Parms*)Obj)->bShouldAutoPause = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPause_Statics::NewProp_bShouldAutoPause = { "bShouldAutoPause", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(AnselFunctionLibrary_eventSetAutoPause_Parms), &Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPause_Statics::NewProp_bShouldAutoPause_SetBit, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPause_Statics::NewProp_bShouldAutoPause_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPause_Statics::NewProp_bShouldAutoPause_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPause_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPause_Statics::NewProp_bShouldAutoPause,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPause_Statics::Function_MetaDataParams[] = {
		{ "Category", "Photography" },
		{ "Comment", "/** Sets whether the photography system automatically pauses the game during a photography session.  See CVar r.Photography.AutoPause */" },
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
		{ "ToolTip", "Sets whether the photography system automatically pauses the game during a photography session.  See CVar r.Photography.AutoPause" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPause_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "SetAutoPause", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPause_Statics::AnselFunctionLibrary_eventSetAutoPause_Parms), Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPause_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPause_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPause_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPause_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPause()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPause_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPostprocess_Statics
	{
		struct AnselFunctionLibrary_eventSetAutoPostprocess_Parms
		{
			bool bShouldAutoPostprocess;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bShouldAutoPostprocess_MetaData[];
#endif
		static void NewProp_bShouldAutoPostprocess_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShouldAutoPostprocess;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPostprocess_Statics::NewProp_bShouldAutoPostprocess_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPostprocess_Statics::NewProp_bShouldAutoPostprocess_SetBit(void* Obj)
	{
		((AnselFunctionLibrary_eventSetAutoPostprocess_Parms*)Obj)->bShouldAutoPostprocess = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPostprocess_Statics::NewProp_bShouldAutoPostprocess = { "bShouldAutoPostprocess", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(AnselFunctionLibrary_eventSetAutoPostprocess_Parms), &Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPostprocess_Statics::NewProp_bShouldAutoPostprocess_SetBit, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPostprocess_Statics::NewProp_bShouldAutoPostprocess_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPostprocess_Statics::NewProp_bShouldAutoPostprocess_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPostprocess_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPostprocess_Statics::NewProp_bShouldAutoPostprocess,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPostprocess_Statics::Function_MetaDataParams[] = {
		{ "Category", "Photography" },
		{ "Comment", "/** Sets whether the photography system automatically tries to optimize Unreal's postprocessing effects for photography.  See CVar r.Photography.AutoPostprocess */" },
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
		{ "ToolTip", "Sets whether the photography system automatically tries to optimize Unreal's postprocessing effects for photography.  See CVar r.Photography.AutoPostprocess" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPostprocess_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "SetAutoPostprocess", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPostprocess_Statics::AnselFunctionLibrary_eventSetAutoPostprocess_Parms), Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPostprocess_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPostprocess_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPostprocess_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPostprocess_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPostprocess()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPostprocess_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintCameraSize_Statics
	{
		struct AnselFunctionLibrary_eventSetCameraConstraintCameraSize_Parms
		{
			float CameraSize;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraSize_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraSize;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintCameraSize_Statics::NewProp_CameraSize_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintCameraSize_Statics::NewProp_CameraSize = { "CameraSize", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AnselFunctionLibrary_eventSetCameraConstraintCameraSize_Parms, CameraSize), METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintCameraSize_Statics::NewProp_CameraSize_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintCameraSize_Statics::NewProp_CameraSize_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintCameraSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintCameraSize_Statics::NewProp_CameraSize,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintCameraSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Photography" },
		{ "Comment", "/** Sets the size of the photography camera for collision purposes; only relevant when default implementation of PlayerCameraManager's PhotographyCameraModify function is used.  See CVar r.Photography.Constrain.CameraSize */" },
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
		{ "ToolTip", "Sets the size of the photography camera for collision purposes; only relevant when default implementation of PlayerCameraManager's PhotographyCameraModify function is used.  See CVar r.Photography.Constrain.CameraSize" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintCameraSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "SetCameraConstraintCameraSize", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintCameraSize_Statics::AnselFunctionLibrary_eventSetCameraConstraintCameraSize_Parms), Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintCameraSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintCameraSize_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintCameraSize_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintCameraSize_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintCameraSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintCameraSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintDistance_Statics
	{
		struct AnselFunctionLibrary_eventSetCameraConstraintDistance_Parms
		{
			float MaxCameraDistance;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxCameraDistance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxCameraDistance;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintDistance_Statics::NewProp_MaxCameraDistance_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintDistance_Statics::NewProp_MaxCameraDistance = { "MaxCameraDistance", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AnselFunctionLibrary_eventSetCameraConstraintDistance_Parms, MaxCameraDistance), METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintDistance_Statics::NewProp_MaxCameraDistance_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintDistance_Statics::NewProp_MaxCameraDistance_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintDistance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintDistance_Statics::NewProp_MaxCameraDistance,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintDistance_Statics::Function_MetaDataParams[] = {
		{ "Category", "Photography" },
		{ "Comment", "/** Sets maximum distance which the camera is allowed to wander from its initial position; only relevant when default implementation of PlayerCameraManager's PhotographyCameraModify function is used.  See CVar r.Photography.Constrain.MaxCameraDistance */" },
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
		{ "ToolTip", "Sets maximum distance which the camera is allowed to wander from its initial position; only relevant when default implementation of PlayerCameraManager's PhotographyCameraModify function is used.  See CVar r.Photography.Constrain.MaxCameraDistance" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintDistance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "SetCameraConstraintDistance", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintDistance_Statics::AnselFunctionLibrary_eventSetCameraConstraintDistance_Parms), Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintDistance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintDistance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintDistance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintDistance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintDistance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintDistance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraMovementSpeed_Statics
	{
		struct AnselFunctionLibrary_eventSetCameraMovementSpeed_Parms
		{
			float TranslationSpeed;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TranslationSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TranslationSpeed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraMovementSpeed_Statics::NewProp_TranslationSpeed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraMovementSpeed_Statics::NewProp_TranslationSpeed = { "TranslationSpeed", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AnselFunctionLibrary_eventSetCameraMovementSpeed_Parms, TranslationSpeed), METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraMovementSpeed_Statics::NewProp_TranslationSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraMovementSpeed_Statics::NewProp_TranslationSpeed_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraMovementSpeed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraMovementSpeed_Statics::NewProp_TranslationSpeed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraMovementSpeed_Statics::Function_MetaDataParams[] = {
		{ "Category", "Photography" },
		{ "Comment", "/** Sets the normal speed of movement of the photography camera.  See CVar r.Photography.TranslationSpeed */" },
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
		{ "ToolTip", "Sets the normal speed of movement of the photography camera.  See CVar r.Photography.TranslationSpeed" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraMovementSpeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "SetCameraMovementSpeed", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraMovementSpeed_Statics::AnselFunctionLibrary_eventSetCameraMovementSpeed_Parms), Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraMovementSpeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraMovementSpeed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraMovementSpeed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraMovementSpeed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraMovementSpeed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraMovementSpeed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAnselFunctionLibrary_SetIsPhotographyAllowed_Statics
	{
		struct AnselFunctionLibrary_eventSetIsPhotographyAllowed_Parms
		{
			bool bIsPhotographyAllowed;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsPhotographyAllowed_MetaData[];
#endif
		static void NewProp_bIsPhotographyAllowed_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsPhotographyAllowed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_SetIsPhotographyAllowed_Statics::NewProp_bIsPhotographyAllowed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_UAnselFunctionLibrary_SetIsPhotographyAllowed_Statics::NewProp_bIsPhotographyAllowed_SetBit(void* Obj)
	{
		((AnselFunctionLibrary_eventSetIsPhotographyAllowed_Parms*)Obj)->bIsPhotographyAllowed = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_SetIsPhotographyAllowed_Statics::NewProp_bIsPhotographyAllowed = { "bIsPhotographyAllowed", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(AnselFunctionLibrary_eventSetIsPhotographyAllowed_Parms), &Z_Construct_UFunction_UAnselFunctionLibrary_SetIsPhotographyAllowed_Statics::NewProp_bIsPhotographyAllowed_SetBit, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_SetIsPhotographyAllowed_Statics::NewProp_bIsPhotographyAllowed_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetIsPhotographyAllowed_Statics::NewProp_bIsPhotographyAllowed_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAnselFunctionLibrary_SetIsPhotographyAllowed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_SetIsPhotographyAllowed_Statics::NewProp_bIsPhotographyAllowed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_SetIsPhotographyAllowed_Statics::Function_MetaDataParams[] = {
		{ "Category", "Photography" },
		{ "Comment", "/** Sets whether the app is permitting photography at this time.  See CVar r.Photography.Allowed */" },
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
		{ "ToolTip", "Sets whether the app is permitting photography at this time.  See CVar r.Photography.Allowed" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAnselFunctionLibrary_SetIsPhotographyAllowed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "SetIsPhotographyAllowed", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAnselFunctionLibrary_SetIsPhotographyAllowed_Statics::AnselFunctionLibrary_eventSetIsPhotographyAllowed_Parms), Z_Construct_UFunction_UAnselFunctionLibrary_SetIsPhotographyAllowed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetIsPhotographyAllowed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_SetIsPhotographyAllowed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetIsPhotographyAllowed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_SetIsPhotographyAllowed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAnselFunctionLibrary_SetIsPhotographyAllowed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAnselFunctionLibrary_SetSettleFrames_Statics
	{
		struct AnselFunctionLibrary_eventSetSettleFrames_Parms
		{
			int32 NumSettleFrames;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NumSettleFrames_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_NumSettleFrames;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_SetSettleFrames_Statics::NewProp_NumSettleFrames_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_SetSettleFrames_Statics::NewProp_NumSettleFrames = { "NumSettleFrames", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AnselFunctionLibrary_eventSetSettleFrames_Parms, NumSettleFrames), METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_SetSettleFrames_Statics::NewProp_NumSettleFrames_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetSettleFrames_Statics::NewProp_NumSettleFrames_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAnselFunctionLibrary_SetSettleFrames_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_SetSettleFrames_Statics::NewProp_NumSettleFrames,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_SetSettleFrames_Statics::Function_MetaDataParams[] = {
		{ "Category", "Photography" },
		{ "Comment", "/** Sets the number of frames between captures in a multi-part shot.  See CVar r.Photography.SettleFrames */" },
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
		{ "ToolTip", "Sets the number of frames between captures in a multi-part shot.  See CVar r.Photography.SettleFrames" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAnselFunctionLibrary_SetSettleFrames_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "SetSettleFrames", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAnselFunctionLibrary_SetSettleFrames_Statics::AnselFunctionLibrary_eventSetSettleFrames_Parms), Z_Construct_UFunction_UAnselFunctionLibrary_SetSettleFrames_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetSettleFrames_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_SetSettleFrames_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetSettleFrames_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_SetSettleFrames()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAnselFunctionLibrary_SetSettleFrames_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics
	{
		struct AnselFunctionLibrary_eventSetUIControlVisibility_Parms
		{
			UObject* WorldContextObject;
			TEnumAsByte<EUIControlEffectTarget> UIControlTarget;
			bool bIsVisible;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UIControlTarget_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_UIControlTarget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsVisible_MetaData[];
#endif
		static void NewProp_bIsVisible_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsVisible;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AnselFunctionLibrary_eventSetUIControlVisibility_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics::NewProp_UIControlTarget_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics::NewProp_UIControlTarget = { "UIControlTarget", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AnselFunctionLibrary_eventSetUIControlVisibility_Parms, UIControlTarget), Z_Construct_UEnum_Ansel_EUIControlEffectTarget, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics::NewProp_UIControlTarget_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics::NewProp_UIControlTarget_MetaData)) }; // 2401745550
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics::NewProp_bIsVisible_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics::NewProp_bIsVisible_SetBit(void* Obj)
	{
		((AnselFunctionLibrary_eventSetUIControlVisibility_Parms*)Obj)->bIsVisible = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics::NewProp_bIsVisible = { "bIsVisible", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(AnselFunctionLibrary_eventSetUIControlVisibility_Parms), &Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics::NewProp_bIsVisible_SetBit, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics::NewProp_bIsVisible_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics::NewProp_bIsVisible_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics::NewProp_UIControlTarget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics::NewProp_bIsVisible,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics::Function_MetaDataParams[] = {
		{ "Category", "Photography" },
		{ "Comment", "/** Show or hide controls in the photography UI which let the player tweak standard UE visual effects during photography - for example, depth of field or chromatic aberration.  Note: these controls only exist when SetAutoPostprocess is turned on.  Some may not apply to your application either because you are not using the associated effect or you are using a custom version of the effect. */" },
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
		{ "ToolTip", "Show or hide controls in the photography UI which let the player tweak standard UE visual effects during photography - for example, depth of field or chromatic aberration.  Note: these controls only exist when SetAutoPostprocess is turned on.  Some may not apply to your application either because you are not using the associated effect or you are using a custom version of the effect." },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "SetUIControlVisibility", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics::AnselFunctionLibrary_eventSetUIControlVisibility_Parms), Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAnselFunctionLibrary_StartSession_Statics
	{
		struct AnselFunctionLibrary_eventStartSession_Parms
		{
			UObject* WorldContextObject;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_StartSession_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AnselFunctionLibrary_eventStartSession_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAnselFunctionLibrary_StartSession_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_StartSession_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_StartSession_Statics::Function_MetaDataParams[] = {
		{ "Category", "Photography" },
		{ "Comment", "/** Starts a photography session */" },
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
		{ "ToolTip", "Starts a photography session" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAnselFunctionLibrary_StartSession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "StartSession", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAnselFunctionLibrary_StartSession_Statics::AnselFunctionLibrary_eventStartSession_Parms), Z_Construct_UFunction_UAnselFunctionLibrary_StartSession_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_StartSession_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_StartSession_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_StartSession_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_StartSession()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAnselFunctionLibrary_StartSession_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAnselFunctionLibrary_StopSession_Statics
	{
		struct AnselFunctionLibrary_eventStopSession_Parms
		{
			UObject* WorldContextObject;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAnselFunctionLibrary_StopSession_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AnselFunctionLibrary_eventStopSession_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAnselFunctionLibrary_StopSession_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAnselFunctionLibrary_StopSession_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAnselFunctionLibrary_StopSession_Statics::Function_MetaDataParams[] = {
		{ "Category", "Photography" },
		{ "Comment", "/** Stops a photography session */" },
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
		{ "ToolTip", "Stops a photography session" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAnselFunctionLibrary_StopSession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "StopSession", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAnselFunctionLibrary_StopSession_Statics::AnselFunctionLibrary_eventStopSession_Parms), Z_Construct_UFunction_UAnselFunctionLibrary_StopSession_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_StopSession_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAnselFunctionLibrary_StopSession_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAnselFunctionLibrary_StopSession_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_StopSession()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAnselFunctionLibrary_StopSession_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAnselFunctionLibrary);
	UClass* Z_Construct_UClass_UAnselFunctionLibrary_NoRegister()
	{
		return UAnselFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UAnselFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAnselFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_Ansel,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UAnselFunctionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance, "ConstrainCameraByDistance" }, // 835717556
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry, "ConstrainCameraByGeometry" }, // 1231679113
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAllowed, "IsPhotographyAllowed" }, // 2820818905
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAvailable, "IsPhotographyAvailable" }, // 3610045348
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPause, "SetAutoPause" }, // 1283578090
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPostprocess, "SetAutoPostprocess" }, // 2229933977
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintCameraSize, "SetCameraConstraintCameraSize" }, // 1101246224
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintDistance, "SetCameraConstraintDistance" }, // 1039417760
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraMovementSpeed, "SetCameraMovementSpeed" }, // 839333845
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_SetIsPhotographyAllowed, "SetIsPhotographyAllowed" }, // 2830673669
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_SetSettleFrames, "SetSettleFrames" }, // 1910769775
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility, "SetUIControlVisibility" }, // 619510930
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_StartSession, "StartSession" }, // 2947146185
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_StopSession, "StopSession" }, // 3264400892
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnselFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "AnselFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAnselFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAnselFunctionLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UAnselFunctionLibrary_Statics::ClassParams = {
		&UAnselFunctionLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UAnselFunctionLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UAnselFunctionLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAnselFunctionLibrary()
	{
		if (!Z_Registration_Info_UClass_UAnselFunctionLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAnselFunctionLibrary.OuterSingleton, Z_Construct_UClass_UAnselFunctionLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UAnselFunctionLibrary.OuterSingleton;
	}
	template<> ANSEL_API UClass* StaticClass<UAnselFunctionLibrary>()
	{
		return UAnselFunctionLibrary::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAnselFunctionLibrary);
	UAnselFunctionLibrary::~UAnselFunctionLibrary() {}
	struct Z_CompiledInDeferFile_FID_Users_Monster_Desktop_New_folder_Ansel_HostProject_Plugins_Ansel_Source_Ansel_Public_AnselFunctionLibrary_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Monster_Desktop_New_folder_Ansel_HostProject_Plugins_Ansel_Source_Ansel_Public_AnselFunctionLibrary_h_Statics::EnumInfo[] = {
		{ EUIControlEffectTarget_StaticEnum, TEXT("EUIControlEffectTarget"), &Z_Registration_Info_UEnum_EUIControlEffectTarget, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2401745550U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Monster_Desktop_New_folder_Ansel_HostProject_Plugins_Ansel_Source_Ansel_Public_AnselFunctionLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UAnselFunctionLibrary, UAnselFunctionLibrary::StaticClass, TEXT("UAnselFunctionLibrary"), &Z_Registration_Info_UClass_UAnselFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAnselFunctionLibrary), 162766584U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Monster_Desktop_New_folder_Ansel_HostProject_Plugins_Ansel_Source_Ansel_Public_AnselFunctionLibrary_h_1170249136(TEXT("/Script/Ansel"),
		Z_CompiledInDeferFile_FID_Users_Monster_Desktop_New_folder_Ansel_HostProject_Plugins_Ansel_Source_Ansel_Public_AnselFunctionLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Monster_Desktop_New_folder_Ansel_HostProject_Plugins_Ansel_Source_Ansel_Public_AnselFunctionLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Users_Monster_Desktop_New_folder_Ansel_HostProject_Plugins_Ansel_Source_Ansel_Public_AnselFunctionLibrary_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Monster_Desktop_New_folder_Ansel_HostProject_Plugins_Ansel_Source_Ansel_Public_AnselFunctionLibrary_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
