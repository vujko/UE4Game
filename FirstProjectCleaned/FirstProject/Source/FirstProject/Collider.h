// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Collider.generated.h"

UCLASS()
class FIRSTPROJECT_API ACollider : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACollider();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class USphereComponent* SphereComponent;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	class UColliderMovementComponent* OurMovementComponent;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float Speed;

	//FORCEINLINE se koristi da se u kodu koji sadrzi poziv ove funkcije, zameni sa telom funkcije
	//bez ovoga bi morao program da skaze do ovde da bi resio poziv
	FORCEINLINE UStaticMeshComponent* GetMeshComponent() {return MeshComponent;}
	FORCEINLINE void SetMeshComponent(UStaticMeshComponent* m) {MeshComponent = m;}

	FORCEINLINE USphereComponent* GetSphereComponent() {return SphereComponent;}
	FORCEINLINE void SetSphereComponent(USphereComponent* s) {SphereComponent = s;}

	FORCEINLINE UCameraComponent* GetCameraComponent() {return Camera;}
	FORCEINLINE void SetSphereComponent(UCameraComponent* c) {Camera = c;}

	FORCEINLINE USpringArmComponent* GetSpringArmComponent() {return SpringArm;}
	FORCEINLINE void SetSpringArmComponent(USpringArmComponent* s) {SpringArm = s;}

	FORCEINLINE UColliderMovementComponent* GetOurMovementComponent() {return OurMovementComponent;}
	FORCEINLINE void SetOurMovementComponent(UColliderMovementComponent* c) {OurMovementComponent = c;}

	virtual UPawnMovementComponent* GetMovementComponent() const override;

private:

	void MoveForward(float input);
	void MoveRight(float input);

	void PitchCamera(float input);
	void YawCamera(float input);

	FVector2D CameraInput;

};
