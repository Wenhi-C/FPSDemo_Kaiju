// Copyright Wenhi

#pragma once

#include "CoreMinimal.h"
#include "Character/KaijuBaseCharacter.h"
#include "KaijuEnemy.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeChangeSignature, float, NewValue);
/**
 * 
 */
UCLASS()
class KAIJU_API AKaijuEnemy : public AKaijuBaseCharacter
{
	GENERATED_BODY()
public:
	AKaijuEnemy();

	UPROPERTY(BlueprintAssignable, Category="GAS|Attribute")
	FOnAttributeChangeSignature OnMaxHealthChangedDelegate;
	
	UPROPERTY(BlueprintAssignable, Category="GAS|Attribute")
	FOnAttributeChangeSignature OnHealthChangedDelegate;
protected:
	virtual void BeginPlay() override;
	
	virtual void InitAbilityActorInfo() override;
};
