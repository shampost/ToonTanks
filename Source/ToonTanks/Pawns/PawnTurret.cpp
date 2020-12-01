// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
    Super::BeginPlay();
    
    /// You can also use GetWorld()->GetTimerManager();
    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
}

void APawnTurret::CheckFireCondition()
{
    // if Player == NULL || is Dead, BAIL!!
    
    // if Player within range, FIRE!!
    
    UE_LOG(LogTemp, Warning, TEXT("Fire Condition Checked"));
}
