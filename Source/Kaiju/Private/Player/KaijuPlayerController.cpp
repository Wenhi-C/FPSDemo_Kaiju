// Copyright Wenhi


#include "Player/KaijuPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Character/KaijuPlayerCharacter.h"


AKaijuPlayerController::AKaijuPlayerController()
{
	bReplicates = true;
}

void AKaijuPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	ControlledCharacter = GetPawn<ACharacter>();
	check(ControlledCharacter);
	
	check(DefaultMappingContext)
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}
void AKaijuPlayerController::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	ControlledCharacter->AddMovementInput(ControlledCharacter->GetActorForwardVector(), MovementVector.Y);
	ControlledCharacter->AddMovementInput(ControlledCharacter->GetActorRightVector(), MovementVector.X);
}

void AKaijuPlayerController::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	ControlledCharacter->AddControllerYawInput(LookAxisVector.X);
	ControlledCharacter->AddControllerPitchInput(LookAxisVector.Y);
}

void AKaijuPlayerController::JumpStart(const FInputActionValue& Value)
{
	ControlledCharacter->Jump();
}

void AKaijuPlayerController::JumpEnd(const FInputActionValue& Value)
{
	ControlledCharacter->StopJumping();
}

void AKaijuPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AKaijuPlayerController::JumpStart);
		
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AKaijuPlayerController::JumpEnd);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AKaijuPlayerController::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AKaijuPlayerController::Look);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}
