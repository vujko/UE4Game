// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"
#include "MainCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Sound/SoundCue.h"

APickup::APickup()
{

}


void APickup::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
    Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
    
    if(OtherActor)
    {
        AMainCharacter* Player = Cast<AMainCharacter>(OtherActor);
        if (Player)
        {
            OnPickupBP(Player);
            if (OnCollisionParticleSystem)
            {
                UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), OnCollisionParticleSystem, GetActorLocation(), FRotator(0.f), true);
            }
            if (OverlapSound)
            {
                UGameplayStatics::PlaySound2D(this, OverlapSound);
            }
            Destroy();
        }
        
    }
}

void APickup::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
}