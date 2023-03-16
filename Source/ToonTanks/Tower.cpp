// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"

void ATower::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>( UGameplayStatics::GetPlayerPawn(this, 0) );

	GetWorldTimerManager().SetTimer(
		FireRateTimerHandle, 
		this, 
		&ATower::CheckFireCondition, 
		FireRate, 
		true
	);

}


void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Tank)
	{
		FVector TankLocation = Tank->GetActorLocation();
		Distance = FVector::Dist(GetActorLocation(), TankLocation);

		if (Distance <= FireRange)
		{
			RotateTurret(TankLocation);
		}
	}

	
}

void ATower::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

void ATower::CheckFireCondition()
{
	if (Tank && Tank->bAlive && Distance <= FireRange)
	{
		Fire();
	}
}