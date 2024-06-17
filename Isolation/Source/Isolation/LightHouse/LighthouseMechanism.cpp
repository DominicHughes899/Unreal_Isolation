// Dominic Hughes - Isolation GameJam - Personal Project 


#include "LighthouseMechanism.h"

// Sets default values
ALighthouseMechanism::ALighthouseMechanism()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALighthouseMechanism::BeginPlay()
{
	Super::BeginPlay();
	
	SetRandomBreakTime();
}

void ALighthouseMechanism::Focus(bool HasFuel)
{
	if (!HasFuel && IsBroken)
	{
		OnFocus();
	}
}

void ALighthouseMechanism::Unfocus()
{
	OnUnfocus();
}

void ALighthouseMechanism::EndInteraction(bool Completed)
{
	OnEndInteraction();

	if (Completed)
	{
		IsBroken = false;
		BreakTimer = 0.f;
		SetRandomBreakTime();

		OnFixed();
	}
}

void ALighthouseMechanism::Repair()
{
	
}

// Called every frame
void ALighthouseMechanism::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!IsBroken)
	{
		TickTimer(DeltaTime);
	}
}

void ALighthouseMechanism::SetRandomBreakTime()
{
	BreakTime = FMath::RandRange(MinTime, MaxTime);
}

void ALighthouseMechanism::TickTimer(float DeltaTime)
{
	BreakTimer += DeltaTime;

	if (BreakTimer >= BreakTime)
	{
		IsBroken = true;
		OnBroken();
	}
}

