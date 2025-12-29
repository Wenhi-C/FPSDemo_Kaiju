// Copyright Wenhi


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/KaijuAbilitySystemComponent.h"
#include "AbilitySystem/KaijuAttributeSet.h"
#include "Character/KaijuPlayerCharacter.h"
#include "Player/KaijuPlayerController.h"


void UOverlayWidgetController::BroadcastInitialValues()
{
	OnHealthChange.Broadcast(GetKaijuAttributeSet()->GetHealth());
	OnMaxHealthChange.Broadcast(GetKaijuAttributeSet()->GetMaxHealth());
	OnScoreChange.Broadcast(GetKaijuAttributeSet()->GetScore());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	GetKaijuAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(
		GetKaijuAttributeSet()->GetHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnHealthChange.Broadcast(Data.NewValue);
			});

	GetKaijuAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(
		GetKaijuAttributeSet()->GetMaxHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxHealthChange.Broadcast(Data.NewValue);
			});

	GetKaijuAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(
		GetKaijuAttributeSet()->GetScoreAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnScoreChange.Broadcast(Data.NewValue);
			});

	// 绑定玩家角色的开火委托
	if (AKaijuPlayerController* PC = GetKaijuPlayerController())
	{
		if (AKaijuPlayerCharacter* PlayerCharacter = Cast<AKaijuPlayerCharacter>(PC->GetPawn()))
		{
			PlayerCharacter->OnFireDelegate.AddDynamic(this, &UOverlayWidgetController::OnFire);
		}
	}
}

void UOverlayWidgetController::OnFire()
{
	OnFireBroadcast.Broadcast();
}

