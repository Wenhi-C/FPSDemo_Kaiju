// Copyright Wenhi


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/KaijuAbilitySystemComponent.h"
#include "AbilitySystem/KaijuAttributeSet.h"


void UOverlayWidgetController::BroadcastInitialValues()
{
	OnHealthChange.Broadcast(GetKaijuAttributeSet()->GetHealth());
	OnMaxHealthChange.Broadcast(GetKaijuAttributeSet()->GetMaxHealth());
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
}

