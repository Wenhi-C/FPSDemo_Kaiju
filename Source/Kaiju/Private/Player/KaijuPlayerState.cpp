// Copyright Wenhi


#include "Player/KaijuPlayerState.h"

#include "AbilitySystem/KaijuAbilitySystemComponent.h"
#include "AbilitySystem/KaijuAttributeSet.h"


AKaijuPlayerState::AKaijuPlayerState()
{
	SetNetUpdateFrequency(100.f);

	AbilitySystemComponent = CreateDefaultSubobject<UKaijuAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UKaijuAttributeSet>("AttributeSet");
}
