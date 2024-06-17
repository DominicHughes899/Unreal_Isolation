// Dominic Hughes - Isolation GameJam - Personal Project 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Boat.generated.h"

UCLASS()
class ISOLATION_API ABoat : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoat();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
