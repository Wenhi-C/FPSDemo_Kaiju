// Copyright Wenhi


#include "Character/KaijuEnemy.h"

#include "AbilitySystem/KaijuAbilitySystemComponent.h"
#include "AbilitySystem/KaijuAttributeSet.h"
#include "AI/KaijuAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/PawnMovementComponent.h"

AKaijuEnemy::AKaijuEnemy()
{
	AbilitySystemComponent = CreateDefaultSubobject<UKaijuAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	AttributeSet = CreateDefaultSubobject<UKaijuAttributeSet>("AttributeSet");
}

void AKaijuEnemy::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (!HasAuthority()) return;
	KaijuAIController = Cast<AKaijuAIController>(NewController);

	KaijuAIController->GetBlackboardComponent()->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
	KaijuAIController->RunBehaviorTree(BehaviorTree);

	AddCharacterAbilities();
}

void AKaijuEnemy::Die_Implementation()
{

	Super::Die_Implementation();
	SetLifeSpan(LifeSpan);
	GetMovementComponent()->StopActiveMovement();
	if (KaijuAIController && KaijuAIController->GetBlackboardComponent())
	{
		KaijuAIController->GetBlackboardComponent()->SetValueAsBool(FName("Dead"), true);
	}
}

void AKaijuEnemy::MulticastHandleDeath()
{
	Super::MulticastHandleDeath();

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
