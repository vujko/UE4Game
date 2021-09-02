// Fill out your copyright notice in the Description page of Project Settings.


#include "Critter.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"

// Sets default values
ACritter::ACritter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	MeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(GetRootComponent());

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(GetRootComponent());
	CameraComponent->SetRelativeLocation(FVector(-300.f, 0.f, 300.f));
	CameraComponent->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));

	// AutoPossessPlayer = EAutoReceiveInput::Player0;
	MaxSpeed = 100.f;
	CurrentVelocity = FVector(0.f);
}

// Called when the game starts or when spawned
void ACritter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACritter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation();
	NewLocation += CurrentVelocity * DeltaTime;
	SetActorLocation(NewLocation);

}

// Called to bind functionality to input
void ACritter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ACritter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ACritter::MoveRight);

}

void ACritter::MoveForward(float Value){
	CurrentVelocity.X = FMath::Clamp(Value, -1.f, 1.f) * MaxSpeed;
}

void ACritter::MoveRight(float Value){
	CurrentVelocity.Y = FMath::Clamp(Value, -1.f, 1.f) * MaxSpeed;
}
