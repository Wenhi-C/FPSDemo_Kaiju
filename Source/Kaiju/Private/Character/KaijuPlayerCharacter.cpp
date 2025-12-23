// Copyright Wenhi


#include "Character/KaijuPlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Actor/KaijuWeapon.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/KaijuPlayerState.h"

AKaijuPlayerCharacter::AKaijuPlayerCharacter()
{
	// Create a CameraComponent	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	CameraComponent->SetupAttachment(GetCapsuleComponent());
	CameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	CameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(CameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

	GetMesh()->SetOwnerNoSee(true);

	GetCharacterMovement()->bOrientRotationToMovement = true;
}

void AKaijuPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitAbilityActorInfo();
	AddCharacterAbilities();
}

void AKaijuPlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbilityActorInfo();
}

FVector AKaijuPlayerCharacter::GetWeaponMuzzleLocation() const
{
	if (Weapon)
		return Weapon->WeaponMesh->GetSocketLocation(FName("Muzzle"));
	return FVector::ZeroVector;
}

void AKaijuPlayerCharacter::InitAbilityActorInfo()
{
	AKaijuPlayerState* KaijuPlayerState = Cast<AKaijuPlayerState>(GetPlayerState());
	check(KaijuPlayerState);

	AbilitySystemComponent = KaijuPlayerState->GetAbilitySystemComponent();
	AttributeSet = KaijuPlayerState->GetAttributeSet();

	AbilitySystemComponent->InitAbilityActorInfo(KaijuPlayerState, this);
	
}

