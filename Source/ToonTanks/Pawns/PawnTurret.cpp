// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
    Super::BeginPlay();
    
    /// You can also use GetWorld()->GetTimerManager();
    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
    
    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
}

void APawnTurret::CheckFireCondition()
{
    // if Player == NULL || is Dead, BAIL!!
    if (!PlayerPawn) {
        return;
    }
    
    if (ReturnDistanceToPlayer() <= FireRange) {
        //FIRE
        UE_LOG(LogTemp, Warning, TEXT("Fire Condition Succccccccc"));
    }
}

float APawnTurret::ReturnDistanceToPlayer()
{
    if (!PlayerPawn) {
        return 0.0f;
    }
    
    return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}
