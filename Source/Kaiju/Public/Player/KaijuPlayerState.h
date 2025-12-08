// Copyright Wenhi

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "KaijuPlayerState.generated.h"
class UAbilitySystemComponent;
class UAttributeSet;
/**
 * 
 */
UCLASS()
class KAIJU_API AKaijuPlayerState : public APlayerState
{
	GENERATED_BODY()
AKaijuPlayerState();
protected:
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
	
};
