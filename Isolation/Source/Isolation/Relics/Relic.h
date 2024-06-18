// Dominic Hughes - Isolation GameJam - Personal Project 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "../Interface/InteractionInterface.h"

#include "Relic.generated.h"

UCLASS()
class ISOLATION_API ARelic : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARelic();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// ==== Interface functions ====
	virtual void Focus(bool HasFuel) override;

	virtual void Unfocus() override { OnUnfocus(); }

	virtual bool CheckTag(FName TagToCheck) { return ActorHasTag(TagToCheck); }

	virtual void DestroyActor() override;

	// ==== Blueprint Functions ====
	UFUNCTION(BlueprintImplementableEvent)
	void OnFocus();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUnfocus();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDestroy();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
