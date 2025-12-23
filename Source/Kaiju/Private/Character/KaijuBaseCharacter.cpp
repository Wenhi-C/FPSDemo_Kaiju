// Copyright Wenhi


#include "Character/KaijuBaseCharacter.h"

#include "AbilitySystem/KaijuAbilitySystemComponent.h"


AKaijuBaseCharacter::AKaijuBaseCharacter()
{

}

UAbilitySystemComponent* AKaijuBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
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
