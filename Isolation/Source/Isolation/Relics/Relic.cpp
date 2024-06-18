#include "Relic.h"
// Dominic Hughes - Isolation GameJam - Personal Project 


#include "Relic.h"

// Sets default values
ARelic::ARelic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARelic::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARelic::Focus(bool HasFuel)
{
	OnFocus();
}

void ARelic::DestroyActor()
{

	OnDestroy();

	Destroy();
}

// Called every frame
void ARelic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

