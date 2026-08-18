// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AnselFunctionLibrary.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeAnselFunctionLibrary() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary(ETypeConstructPhase);
COREUOBJECT_API UClass* Z_Construct_UClass_UObject(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_Ansel(ETypeConstructPhase);
ANSEL_API UClass* Z_Construct_UClass_UAnselFunctionLibrary(ETypeConstructPhase);
ANSEL_API UEnum* Z_Construct_UEnum_Ansel_EUIControlEffectTarget(ETypeConstructPhase);
ANSEL_API UClass* Z_Construct_UClass_UAnselFunctionLibrary(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Enum EUIControlEffectTarget ****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_Ansel_EUIControlEffectTarget_Statics
template<> ANSEL_NON_ATTRIBUTED_API UEnum* StaticEnum<EUIControlEffectTarget>()
{
	return Z_Construct_UEnum_Ansel_EUIControlEffectTarget(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Bloom.Name", "Bloom" },
		{ "BlueprintType", "true" },
		{ "ChromaticAberration.Name", "ChromaticAberration" },
		{ "DepthOfField.Name", "DepthOfField" },
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
		{ "MotionBlur.Name", "MotionBlur" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "Bloom", (int64)Bloom },
		{ "DepthOfField", (int64)DepthOfField },
		{ "ChromaticAberration", (int64)ChromaticAberration },
		{ "MotionBlur", (int64)MotionBlur },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_Ansel,
	nullptr,
	"EUIControlEffectTarget",
	"EUIControlEffectTarget",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::Regular,
	(uint8)UEnum::EUnderlyingType::int32,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EUIControlEffectTarget;
UEnum* Z_Construct_UEnum_Ansel_EUIControlEffectTarget(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EUIControlEffectTarget.OuterSingleton)
		{
			ZRIE_EUIControlEffectTarget.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Ansel_EUIControlEffectTarget, (UObject*)Z_Construct_UPackage__Script_Ansel(ETypeConstructPhase::Outer), TEXT("EUIControlEffectTarget"));
		}
		return ZRIE_EUIControlEffectTarget.OuterSingleton;
	}
	if (!ZRIE_EUIControlEffectTarget.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EUIControlEffectTarget.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EUIControlEffectTarget.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EUIControlEffectTarget ******************************************************

// ********** Begin Class UAnselFunctionLibrary Function ConstrainCameraByDistance *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance_Statics
struct UHT_STATICS
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
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Photography" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** A utility which constrains distance of camera from its start point; may be useful when implementing a custom APlayerCameraManager::PhotographyCameraModify */" },
#endif
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A utility which constrains distance of camera from its start point; may be useful when implementing a custom APlayerCameraManager::PhotographyCameraModify" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewCameraLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviousCameraLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OriginalCameraLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ConstrainCameraByDistance constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewCameraLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PreviousCameraLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OriginalCameraLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutCameraLocation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxDistance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ConstrainCameraByDistance constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ConstrainCameraByDistance Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AnselFunctionLibrary_eventConstrainCameraByDistance_Parms, WorldContextObject), Z_Construct_UClass_UObject, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_NewCameraLocation = { "NewCameraLocation", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(AnselFunctionLibrary_eventConstrainCameraByDistance_Parms, NewCameraLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewCameraLocation_MetaData), NewProp_NewCameraLocation_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PreviousCameraLocation = { "PreviousCameraLocation", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(AnselFunctionLibrary_eventConstrainCameraByDistance_Parms, PreviousCameraLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviousCameraLocation_MetaData), NewProp_PreviousCameraLocation_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_OriginalCameraLocation = { "OriginalCameraLocation", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(AnselFunctionLibrary_eventConstrainCameraByDistance_Parms, OriginalCameraLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OriginalCameraLocation_MetaData), NewProp_OriginalCameraLocation_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_OutCameraLocation = { "OutCameraLocation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(AnselFunctionLibrary_eventConstrainCameraByDistance_Parms, OutCameraLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MaxDistance = { "MaxDistance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(AnselFunctionLibrary_eventConstrainCameraByDistance_Parms, MaxDistance), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewCameraLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PreviousCameraLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OriginalCameraLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutCameraLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaxDistance,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ConstrainCameraByDistance Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "ConstrainCameraByDistance", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::AnselFunctionLibrary_eventConstrainCameraByDistance_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::AnselFunctionLibrary_eventConstrainCameraByDistance_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
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
// ********** End Class UAnselFunctionLibrary Function ConstrainCameraByDistance *******************

// ********** Begin Class UAnselFunctionLibrary Function ConstrainCameraByGeometry *****************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry_Statics
struct UHT_STATICS
{
	struct AnselFunctionLibrary_eventConstrainCameraByGeometry_Parms
	{
		UObject* WorldContextObject;
		FVector NewCameraLocation;
		FVector PreviousCameraLocation;
		FVector OriginalCameraLocation;
		FVector OutCameraLocation;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Photography" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** A utility which constrains the camera against collidable geometry; may be useful when implementing a custom APlayerCameraManager::PhotographyCameraModify */" },
#endif
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A utility which constrains the camera against collidable geometry; may be useful when implementing a custom APlayerCameraManager::PhotographyCameraModify" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewCameraLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviousCameraLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OriginalCameraLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ConstrainCameraByGeometry constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewCameraLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PreviousCameraLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OriginalCameraLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutCameraLocation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ConstrainCameraByGeometry constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ConstrainCameraByGeometry Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AnselFunctionLibrary_eventConstrainCameraByGeometry_Parms, WorldContextObject), Z_Construct_UClass_UObject, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_NewCameraLocation = { "NewCameraLocation", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(AnselFunctionLibrary_eventConstrainCameraByGeometry_Parms, NewCameraLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewCameraLocation_MetaData), NewProp_NewCameraLocation_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PreviousCameraLocation = { "PreviousCameraLocation", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(AnselFunctionLibrary_eventConstrainCameraByGeometry_Parms, PreviousCameraLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviousCameraLocation_MetaData), NewProp_PreviousCameraLocation_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_OriginalCameraLocation = { "OriginalCameraLocation", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(AnselFunctionLibrary_eventConstrainCameraByGeometry_Parms, OriginalCameraLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OriginalCameraLocation_MetaData), NewProp_OriginalCameraLocation_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_OutCameraLocation = { "OutCameraLocation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(AnselFunctionLibrary_eventConstrainCameraByGeometry_Parms, OutCameraLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NewCameraLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PreviousCameraLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OriginalCameraLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutCameraLocation,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ConstrainCameraByGeometry Property Definitions **************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "ConstrainCameraByGeometry", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::AnselFunctionLibrary_eventConstrainCameraByGeometry_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::AnselFunctionLibrary_eventConstrainCameraByGeometry_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
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
// ********** End Class UAnselFunctionLibrary Function ConstrainCameraByGeometry *******************

// ********** Begin Class UAnselFunctionLibrary Function IsPhotographyAllowed **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAllowed_Statics
struct UHT_STATICS
{
	struct AnselFunctionLibrary_eventIsPhotographyAllowed_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Photography" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether the app is permitting photography at this time.  See CVar r.Photography.Allowed */" },
#endif
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether the app is permitting photography at this time.  See CVar r.Photography.Allowed" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsPhotographyAllowed constinit property declarations ******************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((AnselFunctionLibrary_eventIsPhotographyAllowed_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsPhotographyAllowed constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsPhotographyAllowed Property Definitions *****************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(AnselFunctionLibrary_eventIsPhotographyAllowed_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsPhotographyAllowed Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "IsPhotographyAllowed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::AnselFunctionLibrary_eventIsPhotographyAllowed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::AnselFunctionLibrary_eventIsPhotographyAllowed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAllowed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UAnselFunctionLibrary::execIsPhotographyAllowed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UAnselFunctionLibrary::IsPhotographyAllowed();
	P_NATIVE_END;
}
// ********** End Class UAnselFunctionLibrary Function IsPhotographyAllowed ************************

// ********** Begin Class UAnselFunctionLibrary Function IsPhotographyAvailable ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAvailable_Statics
struct UHT_STATICS
{
	struct AnselFunctionLibrary_eventIsPhotographyAvailable_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Photography" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether the photography system is available at all.  See CVar r.Photography.Available */" },
#endif
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether the photography system is available at all.  See CVar r.Photography.Available" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsPhotographyAvailable constinit property declarations ****************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((AnselFunctionLibrary_eventIsPhotographyAvailable_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsPhotographyAvailable constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsPhotographyAvailable Property Definitions ***************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(AnselFunctionLibrary_eventIsPhotographyAvailable_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsPhotographyAvailable Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "IsPhotographyAvailable", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::AnselFunctionLibrary_eventIsPhotographyAvailable_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::AnselFunctionLibrary_eventIsPhotographyAvailable_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAvailable(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UAnselFunctionLibrary::execIsPhotographyAvailable)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UAnselFunctionLibrary::IsPhotographyAvailable();
	P_NATIVE_END;
}
// ********** End Class UAnselFunctionLibrary Function IsPhotographyAvailable **********************

// ********** Begin Class UAnselFunctionLibrary Function SetAutoPause ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPause_Statics
struct UHT_STATICS
{
	struct AnselFunctionLibrary_eventSetAutoPause_Parms
	{
		bool bShouldAutoPause;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Photography" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets whether the photography system automatically pauses the game during a photography session.  See CVar r.Photography.AutoPause */" },
#endif
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets whether the photography system automatically pauses the game during a photography session.  See CVar r.Photography.AutoPause" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShouldAutoPause_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetAutoPause constinit property declarations **************************
	static void NewProp_bShouldAutoPause_SetBit(void* Obj)
	{
		((AnselFunctionLibrary_eventSetAutoPause_Parms*)Obj)->bShouldAutoPause = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShouldAutoPause;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetAutoPause constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetAutoPause Property Definitions *************************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bShouldAutoPause = { "bShouldAutoPause", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(AnselFunctionLibrary_eventSetAutoPause_Parms), &UHT_STATICS::NewProp_bShouldAutoPause_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShouldAutoPause_MetaData), NewProp_bShouldAutoPause_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bShouldAutoPause,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetAutoPause Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "SetAutoPause", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::AnselFunctionLibrary_eventSetAutoPause_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::AnselFunctionLibrary_eventSetAutoPause_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPause(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UAnselFunctionLibrary::execSetAutoPause)
{
	P_GET_UBOOL(Z_Param_bShouldAutoPause);
	P_FINISH;
	P_NATIVE_BEGIN;
	UAnselFunctionLibrary::SetAutoPause(Z_Param_bShouldAutoPause);
	P_NATIVE_END;
}
// ********** End Class UAnselFunctionLibrary Function SetAutoPause ********************************

// ********** Begin Class UAnselFunctionLibrary Function SetAutoPostprocess ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPostprocess_Statics
struct UHT_STATICS
{
	struct AnselFunctionLibrary_eventSetAutoPostprocess_Parms
	{
		bool bShouldAutoPostprocess;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Photography" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets whether the photography system automatically tries to optimize Unreal's postprocessing effects for photography.  See CVar r.Photography.AutoPostprocess */" },
#endif
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets whether the photography system automatically tries to optimize Unreal's postprocessing effects for photography.  See CVar r.Photography.AutoPostprocess" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShouldAutoPostprocess_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetAutoPostprocess constinit property declarations ********************
	static void NewProp_bShouldAutoPostprocess_SetBit(void* Obj)
	{
		((AnselFunctionLibrary_eventSetAutoPostprocess_Parms*)Obj)->bShouldAutoPostprocess = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShouldAutoPostprocess;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetAutoPostprocess constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetAutoPostprocess Property Definitions *******************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bShouldAutoPostprocess = { "bShouldAutoPostprocess", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(AnselFunctionLibrary_eventSetAutoPostprocess_Parms), &UHT_STATICS::NewProp_bShouldAutoPostprocess_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShouldAutoPostprocess_MetaData), NewProp_bShouldAutoPostprocess_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bShouldAutoPostprocess,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetAutoPostprocess Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "SetAutoPostprocess", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::AnselFunctionLibrary_eventSetAutoPostprocess_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::AnselFunctionLibrary_eventSetAutoPostprocess_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPostprocess(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UAnselFunctionLibrary::execSetAutoPostprocess)
{
	P_GET_UBOOL(Z_Param_bShouldAutoPostprocess);
	P_FINISH;
	P_NATIVE_BEGIN;
	UAnselFunctionLibrary::SetAutoPostprocess(Z_Param_bShouldAutoPostprocess);
	P_NATIVE_END;
}
// ********** End Class UAnselFunctionLibrary Function SetAutoPostprocess **************************

// ********** Begin Class UAnselFunctionLibrary Function SetCameraConstraintCameraSize *************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintCameraSize_Statics
struct UHT_STATICS
{
	struct AnselFunctionLibrary_eventSetCameraConstraintCameraSize_Parms
	{
		float CameraSize;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Photography" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the size of the photography camera for collision purposes; only relevant when default implementation of PlayerCameraManager's PhotographyCameraModify function is used.  See CVar r.Photography.Constrain.CameraSize */" },
#endif
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the size of the photography camera for collision purposes; only relevant when default implementation of PlayerCameraManager's PhotographyCameraModify function is used.  See CVar r.Photography.Constrain.CameraSize" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraSize_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetCameraConstraintCameraSize constinit property declarations *********
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraSize;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetCameraConstraintCameraSize constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetCameraConstraintCameraSize Property Definitions ********************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_CameraSize = { "CameraSize", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(AnselFunctionLibrary_eventSetCameraConstraintCameraSize_Parms, CameraSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraSize_MetaData), NewProp_CameraSize_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CameraSize,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetCameraConstraintCameraSize Property Definitions **********************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "SetCameraConstraintCameraSize", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::AnselFunctionLibrary_eventSetCameraConstraintCameraSize_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::AnselFunctionLibrary_eventSetCameraConstraintCameraSize_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintCameraSize(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UAnselFunctionLibrary::execSetCameraConstraintCameraSize)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_CameraSize);
	P_FINISH;
	P_NATIVE_BEGIN;
	UAnselFunctionLibrary::SetCameraConstraintCameraSize(Z_Param_CameraSize);
	P_NATIVE_END;
}
// ********** End Class UAnselFunctionLibrary Function SetCameraConstraintCameraSize ***************

// ********** Begin Class UAnselFunctionLibrary Function SetCameraConstraintDistance ***************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintDistance_Statics
struct UHT_STATICS
{
	struct AnselFunctionLibrary_eventSetCameraConstraintDistance_Parms
	{
		float MaxCameraDistance;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Photography" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets maximum distance which the camera is allowed to wander from its initial position; only relevant when default implementation of PlayerCameraManager's PhotographyCameraModify function is used.  See CVar r.Photography.Constrain.MaxCameraDistance */" },
#endif
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets maximum distance which the camera is allowed to wander from its initial position; only relevant when default implementation of PlayerCameraManager's PhotographyCameraModify function is used.  See CVar r.Photography.Constrain.MaxCameraDistance" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxCameraDistance_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetCameraConstraintDistance constinit property declarations ***********
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxCameraDistance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetCameraConstraintDistance constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetCameraConstraintDistance Property Definitions **********************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MaxCameraDistance = { "MaxCameraDistance", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(AnselFunctionLibrary_eventSetCameraConstraintDistance_Parms, MaxCameraDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxCameraDistance_MetaData), NewProp_MaxCameraDistance_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaxCameraDistance,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetCameraConstraintDistance Property Definitions ************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "SetCameraConstraintDistance", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::AnselFunctionLibrary_eventSetCameraConstraintDistance_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::AnselFunctionLibrary_eventSetCameraConstraintDistance_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintDistance(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UAnselFunctionLibrary::execSetCameraConstraintDistance)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_MaxCameraDistance);
	P_FINISH;
	P_NATIVE_BEGIN;
	UAnselFunctionLibrary::SetCameraConstraintDistance(Z_Param_MaxCameraDistance);
	P_NATIVE_END;
}
// ********** End Class UAnselFunctionLibrary Function SetCameraConstraintDistance *****************

// ********** Begin Class UAnselFunctionLibrary Function SetCameraMovementSpeed ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraMovementSpeed_Statics
struct UHT_STATICS
{
	struct AnselFunctionLibrary_eventSetCameraMovementSpeed_Parms
	{
		float TranslationSpeed;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Photography" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the normal speed of movement of the photography camera.  See CVar r.Photography.TranslationSpeed */" },
#endif
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the normal speed of movement of the photography camera.  See CVar r.Photography.TranslationSpeed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TranslationSpeed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetCameraMovementSpeed constinit property declarations ****************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TranslationSpeed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetCameraMovementSpeed constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetCameraMovementSpeed Property Definitions ***************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_TranslationSpeed = { "TranslationSpeed", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(AnselFunctionLibrary_eventSetCameraMovementSpeed_Parms, TranslationSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TranslationSpeed_MetaData), NewProp_TranslationSpeed_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TranslationSpeed,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetCameraMovementSpeed Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "SetCameraMovementSpeed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::AnselFunctionLibrary_eventSetCameraMovementSpeed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::AnselFunctionLibrary_eventSetCameraMovementSpeed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraMovementSpeed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UAnselFunctionLibrary::execSetCameraMovementSpeed)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_TranslationSpeed);
	P_FINISH;
	P_NATIVE_BEGIN;
	UAnselFunctionLibrary::SetCameraMovementSpeed(Z_Param_TranslationSpeed);
	P_NATIVE_END;
}
// ********** End Class UAnselFunctionLibrary Function SetCameraMovementSpeed **********************

// ********** Begin Class UAnselFunctionLibrary Function SetIsPhotographyAllowed *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UAnselFunctionLibrary_SetIsPhotographyAllowed_Statics
struct UHT_STATICS
{
	struct AnselFunctionLibrary_eventSetIsPhotographyAllowed_Parms
	{
		bool bIsPhotographyAllowed;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Photography" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets whether the app is permitting photography at this time.  See CVar r.Photography.Allowed */" },
#endif
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets whether the app is permitting photography at this time.  See CVar r.Photography.Allowed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsPhotographyAllowed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetIsPhotographyAllowed constinit property declarations ***************
	static void NewProp_bIsPhotographyAllowed_SetBit(void* Obj)
	{
		((AnselFunctionLibrary_eventSetIsPhotographyAllowed_Parms*)Obj)->bIsPhotographyAllowed = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsPhotographyAllowed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetIsPhotographyAllowed constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetIsPhotographyAllowed Property Definitions **************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bIsPhotographyAllowed = { "bIsPhotographyAllowed", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(AnselFunctionLibrary_eventSetIsPhotographyAllowed_Parms), &UHT_STATICS::NewProp_bIsPhotographyAllowed_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsPhotographyAllowed_MetaData), NewProp_bIsPhotographyAllowed_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bIsPhotographyAllowed,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetIsPhotographyAllowed Property Definitions ****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "SetIsPhotographyAllowed", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::AnselFunctionLibrary_eventSetIsPhotographyAllowed_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::AnselFunctionLibrary_eventSetIsPhotographyAllowed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_SetIsPhotographyAllowed(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UAnselFunctionLibrary::execSetIsPhotographyAllowed)
{
	P_GET_UBOOL(Z_Param_bIsPhotographyAllowed);
	P_FINISH;
	P_NATIVE_BEGIN;
	UAnselFunctionLibrary::SetIsPhotographyAllowed(Z_Param_bIsPhotographyAllowed);
	P_NATIVE_END;
}
// ********** End Class UAnselFunctionLibrary Function SetIsPhotographyAllowed *********************

// ********** Begin Class UAnselFunctionLibrary Function SetSettleFrames ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UAnselFunctionLibrary_SetSettleFrames_Statics
struct UHT_STATICS
{
	struct AnselFunctionLibrary_eventSetSettleFrames_Parms
	{
		int32 NumSettleFrames;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Photography" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the number of frames between captures in a multi-part shot.  See CVar r.Photography.SettleFrames */" },
#endif
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the number of frames between captures in a multi-part shot.  See CVar r.Photography.SettleFrames" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NumSettleFrames_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetSettleFrames constinit property declarations ***********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumSettleFrames;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSettleFrames constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSettleFrames Property Definitions **********************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_NumSettleFrames = { "NumSettleFrames", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(AnselFunctionLibrary_eventSetSettleFrames_Parms, NumSettleFrames), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NumSettleFrames_MetaData), NewProp_NumSettleFrames_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NumSettleFrames,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetSettleFrames Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "SetSettleFrames", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::AnselFunctionLibrary_eventSetSettleFrames_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::AnselFunctionLibrary_eventSetSettleFrames_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_SetSettleFrames(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UAnselFunctionLibrary::execSetSettleFrames)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_NumSettleFrames);
	P_FINISH;
	P_NATIVE_BEGIN;
	UAnselFunctionLibrary::SetSettleFrames(Z_Param_NumSettleFrames);
	P_NATIVE_END;
}
// ********** End Class UAnselFunctionLibrary Function SetSettleFrames *****************************

// ********** Begin Class UAnselFunctionLibrary Function SetUIControlVisibility ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility_Statics
struct UHT_STATICS
{
	struct AnselFunctionLibrary_eventSetUIControlVisibility_Parms
	{
		UObject* WorldContextObject;
		TEnumAsByte<EUIControlEffectTarget> UIControlTarget;
		bool bIsVisible;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Photography" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Show or hide controls in the photography UI which let the player tweak standard UE visual effects during photography - for example, depth of field or chromatic aberration.  Note: these controls only exist when SetAutoPostprocess is turned on.  Some may not apply to your application either because you are not using the associated effect or you are using a custom version of the effect. */" },
#endif
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Show or hide controls in the photography UI which let the player tweak standard UE visual effects during photography - for example, depth of field or chromatic aberration.  Note: these controls only exist when SetAutoPostprocess is turned on.  Some may not apply to your application either because you are not using the associated effect or you are using a custom version of the effect." },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UIControlTarget_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsVisible_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetUIControlVisibility constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FBytePropertyParams NewProp_UIControlTarget;
	static void NewProp_bIsVisible_SetBit(void* Obj)
	{
		((AnselFunctionLibrary_eventSetUIControlVisibility_Parms*)Obj)->bIsVisible = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsVisible;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetUIControlVisibility constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetUIControlVisibility Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AnselFunctionLibrary_eventSetUIControlVisibility_Parms, WorldContextObject), Z_Construct_UClass_UObject, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_UIControlTarget = { "UIControlTarget", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(AnselFunctionLibrary_eventSetUIControlVisibility_Parms, UIControlTarget), Z_Construct_UEnum_Ansel_EUIControlEffectTarget, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UIControlTarget_MetaData), NewProp_UIControlTarget_MetaData) }; // 1b233607d87e2f9f8c7fb5c2293e23d7a9a131fd
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bIsVisible = { "bIsVisible", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(AnselFunctionLibrary_eventSetUIControlVisibility_Parms), &UHT_STATICS::NewProp_bIsVisible_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsVisible_MetaData), NewProp_bIsVisible_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_UIControlTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bIsVisible,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetUIControlVisibility Property Definitions *****************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "SetUIControlVisibility", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::AnselFunctionLibrary_eventSetUIControlVisibility_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::AnselFunctionLibrary_eventSetUIControlVisibility_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
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
// ********** End Class UAnselFunctionLibrary Function SetUIControlVisibility **********************

// ********** Begin Class UAnselFunctionLibrary Function StartSession ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UAnselFunctionLibrary_StartSession_Statics
struct UHT_STATICS
{
	struct AnselFunctionLibrary_eventStartSession_Parms
	{
		UObject* WorldContextObject;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Photography" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Starts a photography session */" },
#endif
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Starts a photography session" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif // WITH_METADATA

// ********** Begin Function StartSession constinit property declarations **************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function StartSession constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function StartSession Property Definitions *************************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AnselFunctionLibrary_eventStartSession_Parms, WorldContextObject), Z_Construct_UClass_UObject, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WorldContextObject,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function StartSession Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "StartSession", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::AnselFunctionLibrary_eventStartSession_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::AnselFunctionLibrary_eventStartSession_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_StartSession(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UAnselFunctionLibrary::execStartSession)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_FINISH;
	P_NATIVE_BEGIN;
	UAnselFunctionLibrary::StartSession(Z_Param_WorldContextObject);
	P_NATIVE_END;
}
// ********** End Class UAnselFunctionLibrary Function StartSession ********************************

// ********** Begin Class UAnselFunctionLibrary Function StopSession *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UAnselFunctionLibrary_StopSession_Statics
struct UHT_STATICS
{
	struct AnselFunctionLibrary_eventStopSession_Parms
	{
		UObject* WorldContextObject;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Photography" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Stops a photography session */" },
#endif
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stops a photography session" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif // WITH_METADATA

// ********** Begin Function StopSession constinit property declarations ***************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function StopSession constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function StopSession Property Definitions **************************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AnselFunctionLibrary_eventStopSession_Parms, WorldContextObject), Z_Construct_UClass_UObject, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_WorldContextObject,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function StopSession Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UAnselFunctionLibrary, nullptr, "StopSession", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::AnselFunctionLibrary_eventStopSession_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::AnselFunctionLibrary_eventStopSession_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAnselFunctionLibrary_StopSession(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UAnselFunctionLibrary::execStopSession)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_FINISH;
	P_NATIVE_BEGIN;
	UAnselFunctionLibrary::StopSession(Z_Param_WorldContextObject);
	P_NATIVE_END;
}
// ********** End Class UAnselFunctionLibrary Function StopSession *********************************

// ********** Begin Class UAnselFunctionLibrary ****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UAnselFunctionLibrary_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "AnselFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/AnselFunctionLibrary.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UAnselFunctionLibrary constinit property declarations ********************
// ********** End Class UAnselFunctionLibrary constinit property declarations **********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ConstrainCameraByDistance"), .Pointer = &UAnselFunctionLibrary::execConstrainCameraByDistance },
		{ .NameUTF8 = UTF8TEXT("ConstrainCameraByGeometry"), .Pointer = &UAnselFunctionLibrary::execConstrainCameraByGeometry },
		{ .NameUTF8 = UTF8TEXT("IsPhotographyAllowed"), .Pointer = &UAnselFunctionLibrary::execIsPhotographyAllowed },
		{ .NameUTF8 = UTF8TEXT("IsPhotographyAvailable"), .Pointer = &UAnselFunctionLibrary::execIsPhotographyAvailable },
		{ .NameUTF8 = UTF8TEXT("SetAutoPause"), .Pointer = &UAnselFunctionLibrary::execSetAutoPause },
		{ .NameUTF8 = UTF8TEXT("SetAutoPostprocess"), .Pointer = &UAnselFunctionLibrary::execSetAutoPostprocess },
		{ .NameUTF8 = UTF8TEXT("SetCameraConstraintCameraSize"), .Pointer = &UAnselFunctionLibrary::execSetCameraConstraintCameraSize },
		{ .NameUTF8 = UTF8TEXT("SetCameraConstraintDistance"), .Pointer = &UAnselFunctionLibrary::execSetCameraConstraintDistance },
		{ .NameUTF8 = UTF8TEXT("SetCameraMovementSpeed"), .Pointer = &UAnselFunctionLibrary::execSetCameraMovementSpeed },
		{ .NameUTF8 = UTF8TEXT("SetIsPhotographyAllowed"), .Pointer = &UAnselFunctionLibrary::execSetIsPhotographyAllowed },
		{ .NameUTF8 = UTF8TEXT("SetSettleFrames"), .Pointer = &UAnselFunctionLibrary::execSetSettleFrames },
		{ .NameUTF8 = UTF8TEXT("SetUIControlVisibility"), .Pointer = &UAnselFunctionLibrary::execSetUIControlVisibility },
		{ .NameUTF8 = UTF8TEXT("StartSession"), .Pointer = &UAnselFunctionLibrary::execStartSession },
		{ .NameUTF8 = UTF8TEXT("StopSession"), .Pointer = &UAnselFunctionLibrary::execStopSession },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByDistance, "ConstrainCameraByDistance" }, // a715239ee1cd703f19998c083e4db5f4d0b0680d
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_ConstrainCameraByGeometry, "ConstrainCameraByGeometry" }, // cf9fe57be11edcb224c467d660c7a7cf21e745dd
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAllowed, "IsPhotographyAllowed" }, // c28fb737a2f0dda74cdce3d2ae3704ab53f6cf60
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_IsPhotographyAvailable, "IsPhotographyAvailable" }, // 189b5350c82499353cc3ed6895cad6dafc3c02b9
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPause, "SetAutoPause" }, // 1baa568c89e10d0f401af21bd35c49aca8f2ce69
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_SetAutoPostprocess, "SetAutoPostprocess" }, // 80a3a8f79c6a6ed9eb99385682919dfd7ef11ebc
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintCameraSize, "SetCameraConstraintCameraSize" }, // 8eeab39662095ab752e85b04b107a002f3c4444d
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraConstraintDistance, "SetCameraConstraintDistance" }, // 04f4408a329547da9b91b6ee8acce669f62da833
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_SetCameraMovementSpeed, "SetCameraMovementSpeed" }, // 328185b2e61c9dd4361125670454bf9e43f4cd0e
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_SetIsPhotographyAllowed, "SetIsPhotographyAllowed" }, // 0ace0c5f23a210fd56d3ded4d4c1c99c718c7e25
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_SetSettleFrames, "SetSettleFrames" }, // 2845e57cc11fd59288dd10c5a5a7aab75b3ff830
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_SetUIControlVisibility, "SetUIControlVisibility" }, // 050d3c33d6df50e0c8c7c0d843db550f571dcb3c
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_StartSession, "StartSession" }, // 7d56dea02f82acaaae4f0fc7feb449ffb1ac39b5
		{ &Z_Construct_UFunction_UAnselFunctionLibrary_StopSession, "StopSession" }, // 2f5aaf8257256ad275b17df3b6189de1c49959dc
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAnselFunctionLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UBlueprintFunctionLibrary,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_Ansel,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UAnselFunctionLibrary,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UAnselFunctionLibrary_StaticRegisterNativesUAnselFunctionLibrary()
{
	UClass* Class = UAnselFunctionLibrary::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UAnselFunctionLibrary;
UClass* Z_Construct_UClass_UAnselFunctionLibrary(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UAnselFunctionLibrary;
		if (!Z_Registration_Info_UClass_UAnselFunctionLibrary.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("AnselFunctionLibrary"),
				Z_Registration_Info_UClass_UAnselFunctionLibrary.InnerSingleton,
				UAnselFunctionLibrary_StaticRegisterNativesUAnselFunctionLibrary,
				DataSizeOf<TClass>(),
				alignof(TClass),
				TClass::StaticClassFlags,
				TClass::StaticClassCastFlags(),
				TClass::StaticConfigName(),
				(UClass::ClassConstructorType)InternalConstructor<TClass>,
				(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
				UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
				&TClass::Super::StaticClass,
				&TClass::WithinClass::StaticClass
			);
		}
		return Z_Registration_Info_UClass_UAnselFunctionLibrary.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UAnselFunctionLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAnselFunctionLibrary.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UAnselFunctionLibrary.OuterSingleton;
}
#undef UHT_STATICS
UAnselFunctionLibrary::UAnselFunctionLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAnselFunctionLibrary);
UAnselFunctionLibrary::~UAnselFunctionLibrary() {}
// ********** End Class UAnselFunctionLibrary ******************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Ansel58_Plugins_Ansel_Source_Ansel_Public_AnselFunctionLibrary_h__Script_Ansel_Statics
struct UHT_STATICS
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ Z_Construct_UEnum_Ansel_EUIControlEffectTarget, TEXT("EUIControlEffectTarget"), &ZRIE_EUIControlEffectTarget, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 455292423U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAnselFunctionLibrary, TEXT("UAnselFunctionLibrary"), &Z_Registration_Info_UClass_UAnselFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAnselFunctionLibrary), 3282120122U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Ansel58_Plugins_Ansel_Source_Ansel_Public_AnselFunctionLibrary_h__Script_Ansel_f6e5bc99ea16f4e644a37b1b9f4f0773adfe9318{
	TEXT("/Script/Ansel"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	nullptr, 0,
	UHT_STATICS::EnumInfo, UE_ARRAY_COUNT(UHT_STATICS::EnumInfo),
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
