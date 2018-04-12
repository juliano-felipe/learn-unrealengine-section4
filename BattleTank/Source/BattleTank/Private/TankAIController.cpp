// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay() {
    Super::BeginPlay();
    auto PlayerTank = GetPlayerTank();
    if (!PlayerTank) {
        UE_LOG(LogTemp, Warning, TEXT("AIController can't find Player Tank"));
    } else {
        UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));
    }
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!GetPlayerTank()) { return; }
	// TODO Move towards the player

	// Aim at the towards the player
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	// TODO Fire if reeady

}

ATank* ATankAIController::GetControlledTank() const {
    return Cast<ATank>(GetPawn());
}


ATank* ATankAIController::GetPlayerTank() const {
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}



