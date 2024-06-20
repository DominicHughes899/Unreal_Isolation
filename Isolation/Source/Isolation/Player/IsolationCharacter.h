// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "InputActionValue.h"

#include "IsolationCharacter.generated.h"

class UInputMappingContext;
class UInputAction;

class IInteractionInterface;

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

	// ==== Components ====
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UBoxComponent* InteractionDetectionBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USceneComponent* AttachLocation;

	// ==== Input Handlers ====
	// Set in BP
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* PlayerMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveForwardAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveRightAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* InteractAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* StopInteractAction;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = Input)
	UInputAction* ResetLocationAction;

	// ==== Input Functions ====
	void MoveForward(const FInputActionValue& Value);

	void MoveRight(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

	void Interact(const FInputActionValue& Value);

	void StopInteraction(const FInputActionValue& Value);

	void ResetLocation(const FInputActionValue& Value) { UE_LOG(LogTemp, Warning, TEXT("Resetting"));  SetActorLocation(ResetLocationVector); }

	// ==== Interaction ====
	UFUNCTION()
	void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor);

	TArray<IInteractionInterface*> InteractablesInRange;

	IInteractionInterface* FocusedInteractable;
	IInteractionInterface* HeldInteractable;

	// Hold interaction function
	void BeginInteraction(IInteractionInterface* Interactable);
	void TickInteraction(float DeltaTime);
	void EndInteraction(bool InteractionCompleted);

	IInteractionInterface* TimedInteractable;
	bool IsInteracting = false;
	float InteractionTimer = 0.f;

	UPROPERTY(EditAnywhere)
	float InteractionTime = 2.f;

	// ==== Blueprint Functions ====
	UFUNCTION(BlueprintImplementableEvent)
	void OnUseFuel();							// For sound cue

	// ==== Carrying ====
	bool CarryingFuel = false;

	UPROPERTY(EditAnywhere)
	FVector ResetLocationVector;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
