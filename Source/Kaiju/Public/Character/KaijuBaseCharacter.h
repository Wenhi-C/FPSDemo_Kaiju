// Copyright Wenhi

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interaction/CombatInterface.h"
#include "KaijuBaseCharacter.generated.h"

class AKaijuWeapon;
class UGameplayAbility;
class UAttributeSet;

UCLASS()
class KAIJU_API AKaijuBaseCharacter : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()
	
public:
	AKaijuBaseCharacter();
	
	/* AbilitySystem Interface */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	/* AbilitySystem Interface */

	UFUNCTION(NetMulticast, Reliable)
	virtual void MulticastHandleDeath();
	
	/* Combat Interface */
	virtual void Die_Implementation() override;
	/* Combat Interface */
	
	UAttributeSet* GetAttributeSet() const { return AttributeSet; };

	// 初始化关于GAS的信息
	virtual void InitAbilityActorInfo();

	UPROPERTY()
	bool bDie = false;
	
protected:

	void AddCharacterAbilities();
	
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Weapon")
	TObjectPtr<AKaijuWeapon> Weapon;

	
};
