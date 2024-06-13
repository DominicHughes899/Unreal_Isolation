// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "../Interface/InteractionInterface.h"

#include "FuelCan.generated.h"


UCLASS()
class ISOLATION_API AFuelCan : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFuelCan();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// ==== Interface Functions ====
	virtual void Focus(bool HasFuel) override;
	virtual void Unfocus() override;
	virtual void Pickup(USceneComponent* AttachLocation) override;

	virtual void DestroyActor() override { Destroy(); }

	UPROPERTY(BlueprintReadOnly)
	bool ShouldAnimate = true;

	// ==== Blueprint Functions ====
	UFUNCTION(BlueprintImplementableEvent)
	void OnFocus();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUnfocus();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPickup();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



};
