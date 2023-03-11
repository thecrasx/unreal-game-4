// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	ATank();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	FVector DeltaLocation = FVector::ZeroVector;
	FRotator DeltaRotation = FRotator::ZeroRotator;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* Camera;

	UPROPERTY(EditAnyWhere, Category = "Movement")
	float Speed = 300;

	UPROPERTY(EditAnyWhere, Category = "Movement")
	float TurnRate = 100;

	void Move(float Value);
	void Turn(float Value);

	APlayerController* PlayerControllerRef;
};
