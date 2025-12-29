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
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFireBroadcastSignature);
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

	UPROPERTY(BlueprintAssignable, Category="GAS|Attribute")
	FOnAttributeChangeSignature OnScoreChange;

	UPROPERTY(BlueprintAssignable, Category="GAS|Fire")
	FOnFireBroadcastSignature OnFireBroadcast;

	UFUNCTION()
	void OnFire();

};
