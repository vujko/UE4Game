// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerController.h"
#include "Blueprint/UserWidget.h"

void AMainPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if(HUDOverlayAsset)
    {
        HUDOverlay = CreateWidget<UUserWidget>(this, HUDOverlayAsset);
    }
    HUDOverlay->AddToViewport();
    HUDOverlay->SetVisibility(ESlateVisibility::Visible);

    if (WEnemyHealthBar)
    {
        EnemyHealthBar = CreateWidget<UUserWidget>(this, WEnemyHealthBar);
        if (EnemyHealthBar)
        {
            EnemyHealthBar->AddToViewport();
            EnemyHealthBar->SetVisibility(ESlateVisibility::Hidden);
        }
        EnemyHealthBar->SetAlignmentInViewport(FVector2D(0.f, 0.f));
    }

    if (WPauseMenu)
    {
        PauseMenu = CreateWidget<UUserWidget>(this, WPauseMenu);
        if (PauseMenu)
        {
            PauseMenu->AddToViewport();
            PauseMenu->SetVisibility(ESlateVisibility::Hidden);
        }

    }
}

void AMainPlayerController::DisplayEnemyHealthBar()
{
    if (EnemyHealthBar)
    {
        bEnemyHealthBarVisible = true;
        EnemyHealthBar->SetVisibility(ESlateVisibility::Visible);
    }
}

void AMainPlayerController::HideEnemyHealthBar()
{
    if (EnemyHealthBar)
    {
        bEnemyHealthBarVisible = false;
        EnemyHealthBar->SetVisibility(ESlateVisibility::Hidden);
    }
}

void AMainPlayerController::DisplayPauseMenu_Implementation()
{
    if (PauseMenu)
    {
        bPauseMenuVisible = true;
        PauseMenu->SetVisibility(ESlateVisibility::Visible);

        FInputModeGameAndUI InputMode;
        SetInputMode(InputMode);
        bShowMouseCursor = true;
        SetPause(true);
    }
}

void AMainPlayerController::HidePauseMenu_Implementation()
{
    if (PauseMenu)
    {
        bPauseMenuVisible = false;

        GameModeOnly();
        bShowMouseCursor = false;
        SetPause(false);
    }
}

void AMainPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (EnemyHealthBar)
    {
        FVector2D ScreenLocation;
        ProjectWorldLocationToScreen(EnemyLocation, ScreenLocation);
        ScreenLocation.Y -= 100.f;

        EnemyHealthBar->SetPositionInViewport(ScreenLocation);
        EnemyHealthBar->SetDesiredSizeInViewport(FVector2D(200.f, 25.f));   
    }
}

void AMainPlayerController::TogglePauseMenu()
{
    if (bPauseMenuVisible)
    {
        //da smo pozvali HidePuaseMenu_Implementation() pozvala bi se funkcija definisana u cpp
        //ovako se poziva event u blueprintu
        HidePauseMenu();
        
    }
    else {
        DisplayPauseMenu();
        
    }
}

void AMainPlayerController::GameModeOnly()
{
    FInputModeGameOnly InputMode;
    SetInputMode(InputMode);
}
