// Copyright Wenhi


#include "AbilitySystem/KaijuAbilitySystemComponent.h"

#include "AbilitySystem/Ability/KaijuGameplayAbility.h"

void UKaijuAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities)
{
	for (auto& Ability : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability);
		if (UKaijuGameplayAbility* KaijuAbility = Cast<UKaijuGameplayAbility>(AbilitySpec.Ability))
		{
			if (KaijuAbility->InputTag.IsValid())
			{
				AbilitySpec.GetDynamicSpecSourceTags().AddTag(KaijuAbility->InputTag);
			}
		}
		GiveAbility(AbilitySpec);
		
	}
}
