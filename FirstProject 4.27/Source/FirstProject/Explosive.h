// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Explosive.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECT_API AExplosive : public AItem
{
	GENERATED_BODY()

public:

	AExplosive();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Damage)
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat)
	TSubclassOf< class UDamageType > DamageTypeClass;

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) override;
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
	
};
