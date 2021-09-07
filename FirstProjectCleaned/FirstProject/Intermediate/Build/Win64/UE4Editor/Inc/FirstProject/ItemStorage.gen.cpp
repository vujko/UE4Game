// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FirstProject/ItemStorage.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeItemStorage() {}
// Cross Module References
	FIRSTPROJECT_API UClass* Z_Construct_UClass_AItemStorage_NoRegister();
	FIRSTPROJECT_API UClass* Z_Construct_UClass_AItemStorage();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_FirstProject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	FIRSTPROJECT_API UClass* Z_Construct_UClass_AWeapon_NoRegister();
// End Cross Module References
	void AItemStorage::StaticRegisterNativesAItemStorage()
	{
	}
	UClass* Z_Construct_UClass_AItemStorage_NoRegister()
	{
		return AItemStorage::StaticClass();
	}
	struct Z_Construct_UClass_AItemStorage_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_WeaponMap_ValueProp;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_WeaponMap_Key_KeyProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WeaponMap_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_WeaponMap;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AItemStorage_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_FirstProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AItemStorage_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ItemStorage.h" },
		{ "ModuleRelativePath", "ItemStorage.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AItemStorage_Statics::NewProp_WeaponMap_ValueProp = { "WeaponMap", nullptr, (EPropertyFlags)0x0004000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UClass_AWeapon_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_AItemStorage_Statics::NewProp_WeaponMap_Key_KeyProp = { "WeaponMap_Key", nullptr, (EPropertyFlags)0x0000000000000001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AItemStorage_Statics::NewProp_WeaponMap_MetaData[] = {
		{ "Category", "SaveData" },
		{ "ModuleRelativePath", "ItemStorage.h" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_AItemStorage_Statics::NewProp_WeaponMap = { "WeaponMap", nullptr, (EPropertyFlags)0x0014000000010001, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AItemStorage, WeaponMap), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AItemStorage_Statics::NewProp_WeaponMap_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AItemStorage_Statics::NewProp_WeaponMap_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AItemStorage_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItemStorage_Statics::NewProp_WeaponMap_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItemStorage_Statics::NewProp_WeaponMap_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItemStorage_Statics::NewProp_WeaponMap,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AItemStorage_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AItemStorage>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AItemStorage_Statics::ClassParams = {
		&AItemStorage::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AItemStorage_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AItemStorage_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AItemStorage_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AItemStorage_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AItemStorage()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AItemStorage_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AItemStorage, 651321868);
	template<> FIRSTPROJECT_API UClass* StaticClass<AItemStorage>()
	{
		return AItemStorage::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AItemStorage(Z_Construct_UClass_AItemStorage, &AItemStorage::StaticClass, TEXT("/Script/FirstProject"), TEXT("AItemStorage"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AItemStorage);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
