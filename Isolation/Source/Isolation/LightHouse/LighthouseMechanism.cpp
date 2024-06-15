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
	
}

void ALighthouseMechanism::Focus(bool HasFuel)
{
	if (!HasFuel)
	{
		OnFocus();
	}
}

void ALighthouseMechanism::Unfocus()
{
	OnUnfocus();
}

// Called every frame
void ALighthouseMechanism::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

