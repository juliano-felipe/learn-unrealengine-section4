// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankPlayerController.h"
#include "../BattleTank.h"


void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    auto ControllerTank = GetControlledTank();
    if (!ControllerTank) 
	{
        UE_LOG(LogTemp, Warning, TEXT("Player Controller not possessing a Tank."));
    } 
	else 
	{
        UE_LOG(LogTemp, Warning, TEXT("Player Controller possessing %s"), *(ControllerTank->GetName()));
    }
}


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimAtCrosshair();
}


ATank *ATankPlayerController::GetControlledTank() const 
{
    return Cast<ATank>(GetPawn());
}


void ATankPlayerController::AimAtCrosshair()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation; // out parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	return true;
}



