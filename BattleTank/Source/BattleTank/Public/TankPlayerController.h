// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
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
	ATank* GetControlledTank() const;
	virtual void Tick(float DeltaTime) override;
	void BeginPlay() override;
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector&) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & WorldDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const;
	
	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.3333f;
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.0f; // 10 km
};
