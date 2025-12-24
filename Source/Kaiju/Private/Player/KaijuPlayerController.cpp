// Copyright Wenhi


#include "Player/KaijuPlayerController.h"

#include "AbilitySystemComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "KaijuGameplayTags.h"
#include "Character/KaijuPlayerCharacter.h"


AKaijuPlayerController::AKaijuPlayerController()
{
	bReplicates = true;
}

void AKaijuPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	check(DefaultMappingContext)
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}
void AKaijuPlayerController::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	if (!LoadControlledCharacter()) return;

	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	ControlledCharacter->AddMovementInput(ForwardDirection, MovementVector.Y);
	ControlledCharacter->AddMovementInput(RightDirection, MovementVector.X);
}

void AKaijuPlayerController::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();
	if (!LoadControlledCharacter()) return;
	ControlledCharacter->AddControllerYawInput(LookAxisVector.X);
	ControlledCharacter->AddControllerPitchInput(LookAxisVector.Y);

}

void AKaijuPlayerController::JumpStart(const FInputActionValue& Value)
{
	if (LoadControlledCharacter())
		ControlledCharacter->Jump();
}

void AKaijuPlayerController::JumpEnd(const FInputActionValue& Value)
{
	if (LoadControlledCharacter())
		ControlledCharacter->StopJumping();
}

void AKaijuPlayerController::Fire(const FInputActionValue& Value)
{
	if (!LoadControlledCharacter()) return;
	AKaijuPlayerCharacter* KaijuPlayerCharacterPlayer = Cast<AKaijuPlayerCharacter>(ControlledCharacter);
	if (KaijuPlayerCharacterPlayer->GetWeapon())
	{
		UAbilitySystemComponent* ASC = KaijuPlayerCharacterPlayer->GetAbilitySystemComponent();
		for (const FGameplayAbilitySpec& AbilitySpec : ASC->GetActivatableAbilities())
		{
			if (AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(FKaijuGameplayTags::Get().Input_Fire))
			{
				ASC->TryActivateAbility(AbilitySpec.Handle);
			}
		}
	}
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

		// Fire
		EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Triggered, this, &AKaijuPlayerController::Fire);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

bool AKaijuPlayerController::LoadControlledCharacter()
{
	if (!ControlledCharacter) ControlledCharacter = GetPawn<ACharacter>();
	return ControlledCharacter != nullptr;
}
