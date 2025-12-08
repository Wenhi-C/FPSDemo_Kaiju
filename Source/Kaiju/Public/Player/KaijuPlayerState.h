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
public:
	AKaijuPlayerState();

	UFUNCTION(BlueprintPure)
	UAbilitySystemComponent* GetAbilitySystemComponent() const { return AbilitySystemComponent; }
	UFUNCTION(BlueprintPure)
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
	
};
