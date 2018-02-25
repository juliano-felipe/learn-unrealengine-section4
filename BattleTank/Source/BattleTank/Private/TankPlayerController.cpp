// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"


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

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}



