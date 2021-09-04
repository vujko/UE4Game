// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"


UENUM(BlueprintType)
enum class EMovementStatus : uint8
{
	EMS_Normal		UMETA(DisplayName = "Normal"),
	EMS_Sprinting	UMETA(DisplayName = "Sprinting"),
	EMS_Dead		UMETA(DisplayName = "Dead"),

	EMS_MAX			UMETA(DisplayName = "DefaultMax"),
};

UENUM(BlueprintType)
enum class EStaminaStatus : uint8
{
	ESS_Normal				UMETA(DisplayName = "Normal"),
	ESS_BelowMinimum		UMETA(DisplayName = "BelowMinimum"),
	ESS_Exhuasted			UMETA(DisplayName = "Exhuasted"),
	ESS_ExhaustedRecovering UMETA(DisplayName = "ExhaustedRecovering"),

	ESS_MAX					UMETA(DisplayName = "DefaultMax"),
};

UCLASS()
class FIRSTPROJECT_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Items)
	class AItem* OverlappingItem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Items)
	class AWeapon* EquippedWeapon;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraFollow;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Camera)
	float BaseTurnRate;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Camera)
	float BaseLookUpRate;

	/* Player Stats */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = PlayerStats)
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats)
	float Health;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,Category = PlayerStats)
	float MaxStamina;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = PlayerStats)
	float Stamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = PlayerStats)
	int32 Coins;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
	EMovementStatus MovementStatus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
	EStaminaStatus StaminaStatus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
	float RunningSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
	float SprintingSpeed;

	bool bMovingForward;

	bool bMovingRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
	bool bShiftKeyDown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bLMBDown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
	float StaminaDrainRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
	float MinSprintStamina;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Anims)
	bool bAttacking;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Anims)
	class UAnimMontage* CombatMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Particles)
	class UParticleSystem* HitParticles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Sound)
	class USoundCue* HitSound;

	bool bInterpToEnemy;
	float InterpSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Combat)
	class AEnemy* CombatTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat)
	class AMainPlayerController* MainPlayerController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat)
	TSubclassOf<AEnemy> EnemyFilter;

	UPROPERTY(EditDefaultsOnly, Category = SaveData)
	TSubclassOf<class AItemStorage> WeaponStorage;

	FORCEINLINE void SetCombatTarget(AEnemy* Target) { CombatTarget = Target; }
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const {return CameraBoom;}
	FORCEINLINE class UCameraComponent* GetCameraFollow() const {return CameraFollow;}
	FORCEINLINE void SetStaminaStatus(EStaminaStatus Status) { StaminaStatus = Status;}
	void SetEquippedWeapon(AWeapon* WeaponToSet);
	FORCEINLINE AWeapon* GetEquippedWeapon() { return EquippedWeapon;}
	FORCEINLINE void SetOverlappingItem(AItem* ItemToSet) { OverlappingItem = ItemToSet;}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float input);

	void MoveRight(float input);

	void ShiftKeyDown();

	void ShiftKeyUp();

	void LMBDown();

	void LMBUp();

	void TurnAtRate(float Rate);

	void LookUpAtRate(float Rate);

	void DecrementHealth(float Amount);

	virtual float TakeDamage
	(
		float DamageAmount,
		struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator,
		AActor* DamageCauser
	);

	UFUNCTION(BlueprintCallable)
	void IncrementCoins();

	UFUNCTION(BlueprintCallable)
	void IncrementHealth(float Amount);

	void Die();

	void SetMovementStatus(EMovementStatus NewStatus);

	void Attack();
	
	UFUNCTION(BlueprintCallable)
	void EndAttack();

	UFUNCTION(BlueprintCallable)
	void PlaySwingSound();

	FRotator GetLookAtTargetYaw(FVector Target);

	UFUNCTION(BlueprintCallable)
	void DeathEnd();

	bool Alive();

	void virtual Jump() override;

	void UpdateCombatTarget();

	UFUNCTION()
	void SwitchLevel(FName LevelName);

	UFUNCTION(BlueprintCallable)
	void SaveGame();

	UFUNCTION(BlueprintCallable)
	void LoadGame(bool SetPosition);

};
