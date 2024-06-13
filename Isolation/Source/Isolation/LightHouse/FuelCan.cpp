// Fill out your copyright notice in the Description page of Project Settings.


#include "FuelCan.h"

// Sets default values
AFuelCan::AFuelCan()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFuelCan::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFuelCan::Focus(bool HasFuel)
{
	OnFocus();
}

void AFuelCan::Unfocus()
{
	OnUnfocus();
}

void AFuelCan::Pickup(USceneComponent* AttachLocation)
{
	ShouldAnimate = false;

	AttachToComponent(AttachLocation, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	OnPickup();
}

// Called every frame
void AFuelCan::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

