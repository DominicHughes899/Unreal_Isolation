// Dominic Hughes - Isolation GameJam - Personal Project 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "../Interface/InteractionInterface.h"

#include "LighthouseMechanism.generated.h"

UCLASS()
class ISOLATION_API ALighthouseMechanism : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALighthouseMechanism();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// ==== Interface Functions ====
	virtual void Focus(bool HasFuel) override;
	virtual void Unfocus() override;

	virtual bool CheckTag(FName TagToCheck) override { return ActorHasTag(TagToCheck); }

	// ==== Blueprint Functions ====
	UFUNCTION(BlueprintImplementableEvent)
	void OnFocus();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUnfocus();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
