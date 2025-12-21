// Copyright Wenhi

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "KaijuBaseCharacter.generated.h"

class UAttributeSet;

UCLASS()
class KAIJU_API AKaijuBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	AKaijuBaseCharacter();
	
	/* AbilitySystem Interface */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	/* AbilitySystem Interface */

	UAttributeSet* GetAttributeSet() const { return AttributeSet; };

	// 初始化关于GAS的信息
	virtual void InitAbilityActorInfo();
	
protected:


	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	
	
};
