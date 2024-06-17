// Fill out your copyright notice in the Description page of Project Settings.


#include "MainLight.h"

// Sets default values
AMainLight::AMainLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainLight::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMainLight::Focus(bool HasFuel)
{
	OnFocus(HasFuel);

}

void AMainLight::Unfocus()
{
	OnUnfocus();
}

bool AMainLight::CheckTag(FName TagToCheck)
{
	return ActorHasTag(TagToCheck);
}

void AMainLight::FillFuel()
{
	if (FuelLevel == 0)
	{
		OnFuelRefill();
		LightOn = true;
	}

	FuelLevel += 0.4f;

	if (FuelLevel >= 1.f)
	{
		FuelLevel = 1.f;
	}
}

// Called every frame
void AMainLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (LightOn)
	{
		DrainFuel(DeltaTime);
	}
}

void AMainLight::DrainFuel(float DeltaTime)
{
	if (FuelLevel >= 0)
	{
		FuelLevel -= DeltaTime * FuelEfficiency;
	}
	else
	{
		FuelLevel = 0;

		LightOn = false;
		OnFuelEmpty();
	}

	OnDrainFuel(FuelLevel);
}

