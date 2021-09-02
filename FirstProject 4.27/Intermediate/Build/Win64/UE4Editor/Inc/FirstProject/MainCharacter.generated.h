// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FIRSTPROJECT_MainCharacter_generated_h
#error "MainCharacter.generated.h already included, missing '#pragma once' in MainCharacter.h"
#endif
#define FIRSTPROJECT_MainCharacter_generated_h

#define FirstProject_4_27_Source_FirstProject_MainCharacter_h_34_SPARSE_DATA
#define FirstProject_4_27_Source_FirstProject_MainCharacter_h_34_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execDeathEnd); \
	DECLARE_FUNCTION(execPlaySwingSound); \
	DECLARE_FUNCTION(execEndAttack);


#define FirstProject_4_27_Source_FirstProject_MainCharacter_h_34_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execDeathEnd); \
	DECLARE_FUNCTION(execPlaySwingSound); \
	DECLARE_FUNCTION(execEndAttack);


#define FirstProject_4_27_Source_FirstProject_MainCharacter_h_34_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMainCharacter(); \
	friend struct Z_Construct_UClass_AMainCharacter_Statics; \
public: \
	DECLARE_CLASS(AMainCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FirstProject"), NO_API) \
	DECLARE_SERIALIZER(AMainCharacter)


#define FirstProject_4_27_Source_FirstProject_MainCharacter_h_34_INCLASS \
private: \
	static void StaticRegisterNativesAMainCharacter(); \
	friend struct Z_Construct_UClass_AMainCharacter_Statics; \
public: \
	DECLARE_CLASS(AMainCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FirstProject"), NO_API) \
	DECLARE_SERIALIZER(AMainCharacter)


#define FirstProject_4_27_Source_FirstProject_MainCharacter_h_34_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMainCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMainCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMainCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMainCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMainCharacter(AMainCharacter&&); \
	NO_API AMainCharacter(const AMainCharacter&); \
public:


#define FirstProject_4_27_Source_FirstProject_MainCharacter_h_34_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMainCharacter(AMainCharacter&&); \
	NO_API AMainCharacter(const AMainCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMainCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMainCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMainCharacter)


#define FirstProject_4_27_Source_FirstProject_MainCharacter_h_34_PRIVATE_PROPERTY_OFFSET
#define FirstProject_4_27_Source_FirstProject_MainCharacter_h_31_PROLOG
#define FirstProject_4_27_Source_FirstProject_MainCharacter_h_34_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FirstProject_4_27_Source_FirstProject_MainCharacter_h_34_PRIVATE_PROPERTY_OFFSET \
	FirstProject_4_27_Source_FirstProject_MainCharacter_h_34_SPARSE_DATA \
	FirstProject_4_27_Source_FirstProject_MainCharacter_h_34_RPC_WRAPPERS \
	FirstProject_4_27_Source_FirstProject_MainCharacter_h_34_INCLASS \
	FirstProject_4_27_Source_FirstProject_MainCharacter_h_34_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FirstProject_4_27_Source_FirstProject_MainCharacter_h_34_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FirstProject_4_27_Source_FirstProject_MainCharacter_h_34_PRIVATE_PROPERTY_OFFSET \
	FirstProject_4_27_Source_FirstProject_MainCharacter_h_34_SPARSE_DATA \
	FirstProject_4_27_Source_FirstProject_MainCharacter_h_34_RPC_WRAPPERS_NO_PURE_DECLS \
	FirstProject_4_27_Source_FirstProject_MainCharacter_h_34_INCLASS_NO_PURE_DECLS \
	FirstProject_4_27_Source_FirstProject_MainCharacter_h_34_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FIRSTPROJECT_API UClass* StaticClass<class AMainCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FirstProject_4_27_Source_FirstProject_MainCharacter_h


#define FOREACH_ENUM_ESTAMINASTATUS(op) \
	op(EStaminaStatus::ESS_Normal) \
	op(EStaminaStatus::ESS_BelowMinimum) \
	op(EStaminaStatus::ESS_Exhuasted) \
	op(EStaminaStatus::ESS_ExhaustedRecovering) 

enum class EStaminaStatus : uint8;
template<> FIRSTPROJECT_API UEnum* StaticEnum<EStaminaStatus>();

#define FOREACH_ENUM_EMOVEMENTSTATUS(op) \
	op(EMovementStatus::EMS_Normal) \
	op(EMovementStatus::EMS_Sprinting) \
	op(EMovementStatus::EMS_Dead) 

enum class EMovementStatus : uint8;
template<> FIRSTPROJECT_API UEnum* StaticEnum<EMovementStatus>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
