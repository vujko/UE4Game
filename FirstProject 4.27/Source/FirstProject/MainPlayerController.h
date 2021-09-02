// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECT_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	// Reference to the UMG asset in the editor
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Widgets)
	TSubclassOf<class UUserWidget> HUDOverlayAsset;

	//Variable to hold the widget after creating it
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Widgets)
	UUserWidget* HUDOverlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widgets)
	TSubclassOf<UUserWidget> WEnemyHealthBar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widgets)
	UUserWidget* EnemyHealthBar;

	bool bEnemyHealthBarVisible;

	FVector EnemyLocation;

	void DisplayEnemyHealthBar();
	void HideEnemyHealthBar();



protected:

	void virtual BeginPlay() override;

	void virtual Tick(float DeltaTime) override;
	
};
