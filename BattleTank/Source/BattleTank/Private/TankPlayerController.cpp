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
		//UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString());
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *LookDirection.ToString());
	}

	// Line-trace along that LookDirection , and see what we hit (up to a max range)
	return true;
}


bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	// "De-project" the screen position of the crosshair to a world direction
	FVector CameraWorldLocation; // to be discarded
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y,
		CameraWorldLocation, LookDirection);
}



