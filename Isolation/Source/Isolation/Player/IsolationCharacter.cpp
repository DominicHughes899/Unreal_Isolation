// Fill out your copyright notice in the Description page of Project Settings.


#include "IsolationCharacter.h"

#include "Components/InputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

#include "Components/BoxComponent.h"

#include "../Interface/InteractionInterface.h"

// Sets default values
AIsolationCharacter::AIsolationCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Setup Components
	// Interaction Detection Box
	InteractionDetectionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractionDetectionBox"));
	InteractionDetectionBox->SetupAttachment(RootComponent);
	InteractionDetectionBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	InteractionDetectionBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel1, ECollisionResponse::ECR_Overlap);



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

	// Bind Overlap Functions
	OnActorBeginOverlap.AddDynamic(this, &AIsolationCharacter::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AIsolationCharacter::OnOverlapEnd);
}

// ==== Input Functions ====
void AIsolationCharacter::MoveForward(const FInputActionValue& Value)
{
	AddMovementInput(GetActorForwardVector(), Value.Get<float>());
}

void AIsolationCharacter::MoveRight(const FInputActionValue& Value)
{
	AddMovementInput(GetActorRightVector(), Value.Get<float>());
}

void AIsolationCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddControllerYawInput(-LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AIsolationCharacter::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	// Add Interactable to array
	if (IInteractionInterface* OverlappedInterface = Cast<IInteractionInterface>(OtherActor))
	{
		InteractablesInRange.Add(OverlappedInterface);

	}
}

void AIsolationCharacter::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
	// Remove Interactable from array

	IInteractionInterface* OverlappedInterface = Cast<IInteractionInterface>(OtherActor);

	if (OverlappedInterface && InteractablesInRange.Num() > 0)
	{
		InteractablesInRange.Remove(OverlappedInterface);

	}
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
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AIsolationCharacter::Look);
	}
}

