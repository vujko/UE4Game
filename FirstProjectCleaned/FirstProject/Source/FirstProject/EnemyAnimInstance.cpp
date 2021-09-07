// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAnimInstance.h"
#include "Enemy.h"

void UEnemyAnimInstance::NativeInitializeAnimation()
{
    if (Pawn == nullptr)
    {
        Pawn = TryGetPawnOwner();
        if (Pawn)
        {
            Enemy = Cast<AEnemy>(Pawn);
        }
    }
}

void UEnemyAnimInstance::UpdateAnimationProperties()
{
    if (Pawn == nullptr)
    {
        Pawn = TryGetPawnOwner();
    }

    if (Pawn)
    {
        FVector Velocity = Pawn->GetVelocity();
        FVector HorizontalVelocity = FVector(Velocity.X, Velocity.Y, 0.f);
        Speed = HorizontalVelocity.Size();

        if (Enemy == nullptr)
        {
            Enemy = Cast<AEnemy>(Pawn);
        }
    }
}
