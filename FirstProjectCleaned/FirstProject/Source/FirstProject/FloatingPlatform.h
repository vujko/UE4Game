// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingPlatform.generated.h"

UCLASS()
class FIRSTPROJECT_API AFloatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingPlatform();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Platform)
	class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = Platform)
	FVector StartPoint;

	UPROPERTY(EditAnywhere, Category = Platform, meta = (MakeEditWidget = "true"))
	FVector EndPoint;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Platform)
	float InterpSpeed;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Platform)
	bool bInterping;

	FTimerHandle InterpHandle;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Platform)
	float InterpTimer;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Platform)
	float Distance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ToggleInterping();

	void SwapVectors(FVector& VecOne, FVector& VecTwo);

};
