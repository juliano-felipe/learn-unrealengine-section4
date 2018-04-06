// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
    GENERATED_BODY()

private:
	void AimAtCrosshair();
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
    ATank* GetControlledTank() const;
	
	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = (1. / 2.);

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = (1. / 3.);

public:

    virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
};
