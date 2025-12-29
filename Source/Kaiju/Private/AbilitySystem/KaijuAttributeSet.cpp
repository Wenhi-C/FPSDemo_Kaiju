// Copyright Wenhi


#include "AbilitySystem/KaijuAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayEffectExtension.h"
#include "Interaction/CombatInterface.h"
#include "Character/KaijuEnemy.h"
#include "Character/KaijuPlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"

UKaijuAttributeSet::UKaijuAttributeSet()
{
	InitMaxHealth(100.f);
	InitHealth(100.f);
	InitScore(0.f);
}

void UKaijuAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UKaijuAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UKaijuAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UKaijuAttributeSet, Score, COND_None, REPNOTIFY_Always);
}

void UKaijuAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UKaijuAttributeSet, Health, OldHealth);
}

void UKaijuAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UKaijuAttributeSet, MaxHealth, OldMaxHealth);
}

void UKaijuAttributeSet::OnRep_Score(const FGameplayAttributeData& OldScore) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UKaijuAttributeSet, Score, OldScore);
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

				// 如果死亡的是敌人，给伤害造成者（玩家）加分
				if (AvatarActor->ActorHasTag(FName("Enemy")))
				{
					FGameplayEffectContextHandle ContextHandle = Data.EffectSpec.GetContext();
					if (ContextHandle.IsValid())
					{
						AActor* SourceActor = ContextHandle.GetEffectCauser();
						if (AKaijuPlayerCharacter* PlayerCharacter = Cast<AKaijuPlayerCharacter>(SourceActor))
						{
							if (UKaijuAttributeSet* SourceAttributeSet = Cast<UKaijuAttributeSet>(PlayerCharacter->GetAttributeSet()))
							{
								SourceAttributeSet->SetScore(SourceAttributeSet->GetScore() + 1.f);
								if (SourceAttributeSet->GetScore() >= PlayerCharacter->GetWinRequireScores())
								{
									UGameplayStatics::OpenLevelBySoftObjectPtr(PlayerCharacter, PlayerCharacter->SuccessMap);
								}
							}
						}
					}
				}
			}
		}
	}
}

