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

	UKaijuAttributeSet* KaijuAS = Cast<UKaijuAttributeSet>(AttributeSet);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(KaijuAS->GetHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnHealthChangedDelegate.Broadcast(Data.NewValue);
		});
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(KaijuAS->GetMaxHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxHealthChangedDelegate.Broadcast(Data.NewValue);
		});
	OnHealthChangedDelegate.Broadcast(KaijuAS->GetHealth());
	OnMaxHealthChangedDelegate.Broadcast(KaijuAS->GetMaxHealth());
}

void AKaijuEnemy::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
