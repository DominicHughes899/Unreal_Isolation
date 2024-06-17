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

	virtual void BeginInteraction() override { OnBeginInteraction(); }
	virtual void EndInteraction(bool Completed) override;

	virtual void Repair() override;

	// ==== Blueprint Functions ====
	UFUNCTION(BlueprintImplementableEvent)
	void OnFocus();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUnfocus();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBroken();

	UFUNCTION(BlueprintImplementableEvent)
	void OnFixed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBeginInteraction();
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnEndInteraction();
	

	// ==== Blueprint Properties ====
	UPROPERTY(EditAnywhere)
	float MinTime = 40.f;

	UPROPERTY(EditAnywhere)
	float MaxTime = 120.f;

	UPROPERTY(BlueprintReadOnly)
	bool IsBroken = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private: 
	// ==== Mechanism breaking interaction ====
	void SetRandomBreakTime();
	void TickTimer(float DeltaTime);



	float BreakTimer = 0.f;
	float BreakTime = 0.f;

};
