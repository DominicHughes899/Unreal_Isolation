// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "InputActionValue.h"

#include "IsolationCharacter.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class ISOLATION_API AIsolationCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AIsolationCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// ==== Input Handlers ====
	// Set in BP
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* PlayerMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveForwardAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveRightAction;

	// ==== Input Functions ====
	void MoveForward(const FInputActionValue& Value);

	void MoveRight(const FInputActionValue& Value);



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
