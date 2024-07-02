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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* SprintAction;

	// ==== Input Functions ====
	void MoveForward(const FInputActionValue& Value);

	void MoveRight(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

	void Interact(const FInputActionValue& Value);

	void StopInteraction(const FInputActionValue& Value);

	void ResetLocation(const FInputActionValue& Value) { UE_LOG(LogTemp, Warning, TEXT("Resetting"));  SetActorLocation(ResetLocationVector); }

	void EnableSprint(const FInputActionValue& Value);

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

	UFUNCTION(BlueprintImplementableEvent)
	void ShowStamina();

	UFUNCTION(BlueprintImplementableEvent)
	void HideStamina();

	// ==== Carrying ====
	bool CarryingFuel = false;

	UPROPERTY(EditAnywhere)
	FVector ResetLocationVector;

	// ==== Sprinting ====
	void DisableSprint();
	void StaminaTick(float DeltaTime);
	void TiredTick(float DeltaTime);

	void FadeUIin();
	void FadeUIOut();

	bool IsSprinting = false;
	bool IsTired = false;
	bool StaminaShouldTick = false;
	bool RechargePaused = false;
	bool IsUIVisible = false;

	float MaxStamina = 100.f;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	float Stamina = MaxStamina;
	
	// Recharge 
	float StaminaDecayRate = 25.f;
	float StaminaRechargeRate = 20.f;
	float StaminaRechargePauseTimer = 0.f;
	float StaminaRechargePauseTime = 0.8f;

	// Tired
	float StaminaEmptyRefillTime = 6.f;
	float StaminaEmptyRefillTimer = 0.f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
