// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "../Interface/InteractionInterface.h"

#include "MainLight.generated.h"

UCLASS()
class ISOLATION_API AMainLight : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMainLight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// ==== Interface functions ====
	virtual void Focus(bool HasFuel) override;
	virtual void Unfocus() override;

	virtual bool CheckTag(FName TagToCheck) override;

	// ==== Blueprint Functions ====
	UFUNCTION(BlueprintImplementableEvent)
	void OnFocus(bool HasFuel);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUnfocus();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
