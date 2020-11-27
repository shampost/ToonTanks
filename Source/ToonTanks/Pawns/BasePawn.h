// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

class UCapsuleComponent;

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

private:

// capsule component needs to be forward declared so as to minimize #includes and increase runtime
UPROPERTY()
UCapsuleComponent* CapsuleComp;

// UStaticMeshComponent is used to create an instance of a UStaticMesh which is an object composed
// of static polygons
UPROPERTY()
UStaticMeshComponent* BaseMesh;
UPROPERTY()
UStaticMeshComponent* TurretMesh;

// useful for defining where the projectile will spawn :)
UPROPERTY()
USceneComponent* ProjectileSpawnPoint;

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
