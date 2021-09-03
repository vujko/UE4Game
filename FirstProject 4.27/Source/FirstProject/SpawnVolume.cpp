// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnVolume.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Critter.h"
#include "Enemy.h"
#include "AIController.h"
// Sets default values
ASpawnVolume::ASpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawningBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));

}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();

	if (Actor_1 && Actor_2)
	{
		SpawnArray.Add(Actor_1);
		SpawnArray.Add(Actor_2);
	}
	
}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ASpawnVolume::GetSpawningPoint()
{
	FVector BoxOrigin = SpawningBox->GetComponentLocation();
	FVector Extent = SpawningBox->GetScaledBoxExtent();

	return UKismetMathLibrary::RandomPointInBoundingBox(BoxOrigin, Extent);
}

void ASpawnVolume::SpawnOurActor_Implementation(UClass* ToSpawn, const FVector Location)
{
	if(ToSpawn)
	{
		UWorld* World = GetWorld();
		if(World)
		{
			World->SpawnActor<AActor>(ToSpawn, Location, FRotator(0.f));


		}
	}
}

TSubclassOf<AActor> ASpawnVolume::GetSpawningActor()
{
	if (SpawnArray.Num() > 0)
	{
		int32 Selection = FMath::RandRange(0, SpawnArray.Num() - 1);
		return SpawnArray[Selection];
	}
	else
	{
		return nullptr;
	}
}

