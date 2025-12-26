// Copyright Wenhi


#include "AbilitySystem/KaijuAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "Interaction/CombatInterface.h"
#include "Net/UnrealNetwork.h"

UKaijuAttributeSet::UKaijuAttributeSet()
{
	InitMaxHealth(100.f);
	InitHealth(100.f);
	
}

void UKaijuAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UKaijuAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UKaijuAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
}

void UKaijuAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UKaijuAttributeSet, Health, OldHealth);
}

void UKaijuAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UKaijuAttributeSet, MaxHealth, OldMaxHealth);
}

void UKaijuAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp<float>(GetHealth(), 0, GetMaxHealth()));
		if (GetHealth() <= 0.f)
		{
			AActor* AvatarActor =GetOwningAbilitySystemComponent()->GetAvatarActor();
			if (AvatarActor->Implements<UCombatInterface>())
			{
				ICombatInterface::Execute_Die(AvatarActor);
			}
		}
	}
}

