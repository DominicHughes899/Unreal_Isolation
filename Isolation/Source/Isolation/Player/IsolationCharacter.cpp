// Fill out your copyright notice in the Description page of Project Settings.


#include "IsolationCharacter.h"

#include "Components/InputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

// Sets default values
AIsolationCharacter::AIsolationCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AIsolationCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Setup input mapping context
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(PlayerMappingContext, 0);
		}
	}
}

void AIsolationCharacter::MoveForward(const FInputActionValue& Value)
{
	AddMovementInput(GetActorForwardVector(), Value.Get<float>());
}

void AIsolationCharacter::MoveRight(const FInputActionValue& Value)
{
	AddMovementInput(GetActorRightVector(), Value.Get<float>());
}

// Called every frame
void AIsolationCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AIsolationCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &AIsolationCharacter::MoveForward);
		EnhancedInputComponent->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &AIsolationCharacter::MoveRight);
	}
}

