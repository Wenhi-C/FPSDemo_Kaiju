// Copyright Wenhi


#include "UI/WidgetController/KaijuWidgetController.h"

#include "AbilitySystem/KaijuAbilitySystemComponent.h"
#include "AbilitySystem/KaijuAttributeSet.h"
#include "Player/KaijuPlayerController.h"
#include "Player/KaijuPlayerState.h"

void UKaijuWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

AKaijuPlayerController* UKaijuWidgetController::GetKaijuPlayerController()
{
	if (!KaijuPlayerController)
	{
		KaijuPlayerController = Cast<AKaijuPlayerController>(PlayerController);
	}
	return KaijuPlayerController;
}

AKaijuPlayerState* UKaijuWidgetController::GetKaijuPlayerState()
{
	if (!KaijuPlayerState)
	{
		KaijuPlayerState = Cast<AKaijuPlayerState>(PlayerState);
	}
	return KaijuPlayerState;
}

UKaijuAbilitySystemComponent* UKaijuWidgetController::GetKaijuAbilitySystemComponent()
{
	if (!KaijuAbilitySystemComponent)
	{
		KaijuAbilitySystemComponent = Cast<UKaijuAbilitySystemComponent>(AbilitySystemComponent);
	}
	return KaijuAbilitySystemComponent;
}

UKaijuAttributeSet* UKaijuWidgetController::GetKaijuAttributeSet()
{
	if (!KaijuAttributeSet)
	{
		KaijuAttributeSet = Cast<UKaijuAttributeSet>(AttributeSet);
	}
	return KaijuAttributeSet;
}
