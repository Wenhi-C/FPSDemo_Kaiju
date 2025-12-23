// Copyright Wenhi


#include "AbilitySystem/KaijuAbilitySystemComponent.h"

void UKaijuAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities)
{
	for (auto& Ability : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability);
		GiveAbility(AbilitySpec);
	}
}
