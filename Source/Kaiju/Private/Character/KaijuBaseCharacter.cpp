// Copyright Wenhi


#include "Character/KaijuBaseCharacter.h"

#include "AbilitySystem/KaijuAbilitySystemComponent.h"
#include "Actor/KaijuWeapon.h"


AKaijuBaseCharacter::AKaijuBaseCharacter()
{

}

UAbilitySystemComponent* AKaijuBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AKaijuBaseCharacter::MulticastHandleDeath_Implementation()
{
	GetMesh()->SetSimulatePhysics(true);
	GetMesh()->SetEnableGravity(true);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	GetMesh()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
}

void AKaijuBaseCharacter::Die_Implementation()
{
	MulticastHandleDeath();
}

void AKaijuBaseCharacter::InitAbilityActorInfo()
{
}

void AKaijuBaseCharacter::AddCharacterAbilities()
{
	if (!HasAuthority()) return;

	if (UKaijuAbilitySystemComponent* KaijuASC = Cast<UKaijuAbilitySystemComponent>(AbilitySystemComponent))
	{
		KaijuASC->AddCharacterAbilities(StartupAbilities);
	}
}
