// Fill out your copyright notice in the Description page of Project Settings.


#include "ColliderMovementComponent.h"

void UColliderMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction){
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if(!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime)){ return; }

    FVector DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.f);
    if(!DesiredMovementThisFrame.IsNearlyZero()){
        FHitResult HitInfo;
        SafeMoveUpdatedComponent(DesiredMovementThisFrame, UpdatedComponent->GetComponentRotation(), true,  HitInfo);
        bool MyBool = HitInfo.IsValidBlockingHit();
        UE_LOG(LogTemp, Warning, TEXT("Bool value is: %s"), MyBool?  TEXT("true") : TEXT("false"));
        if(HitInfo.IsValidBlockingHit())
        {
            SlideAlongSurface(DesiredMovementThisFrame, 1.f - HitInfo.Time, HitInfo.Normal, HitInfo);
            
        }
    }
}