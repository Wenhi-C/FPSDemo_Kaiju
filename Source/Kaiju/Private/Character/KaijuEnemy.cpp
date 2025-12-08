// Copyright Wenhi


#include "Character/KaijuEnemy.h"

#include "AbilitySystem/KaijuAbilitySystemComponent.h"
#include "AbilitySystem/KaijuAttributeSet.h"

AKaijuEnemy::AKaijuEnemy()
{
	AbilitySystemComponent = CreateDefaultSubobject<UKaijuAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	AttributeSet = CreateDefaultSubobject<UKaijuAttributeSet>("AttributeSet");
}

void AKaijuEnemy::BeginPlay()
{
	Super::BeginPlay();
	InitAbilityActorInfo();
}

void AKaijuEnemy::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
