// Copyright Wenhi

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/KaijuWidgetController.h"
#include "OverlayWidgetController.generated.h"
class UKaijuAttributeSet;
class UKaijuAbilitySystemComponent;
class AKaijuPlayerState;
class AKaijuPlayerController;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeChangeSignature, float, NewValue);
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class KAIJU_API UOverlayWidgetController : public UKaijuWidgetController
{
	GENERATED_BODY()
public:
	void BroadcastInitialValues();
	void BindCallbacksToDependencies();

	UPROPERTY(BlueprintAssignable, Category="GAS|Attribute")
	FOnAttributeChangeSignature OnHealthChange;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attribute")
	FOnAttributeChangeSignature OnMaxHealthChange;
	
};
