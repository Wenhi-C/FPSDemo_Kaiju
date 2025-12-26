// Copyright Wenhi

#pragma once

#include "CoreMinimal.h"
#include "Character/KaijuBaseCharacter.h"
#include "UI/WidgetController/OverlayWidgetController.h"

#include "KaijuEnemy.generated.h"

class UBehaviorTree;
class AKaijuAIController;
/**
 * 
 */
UCLASS()
class KAIJU_API AKaijuEnemy : public AKaijuBaseCharacter
{
	GENERATED_BODY()
public:
	AKaijuEnemy();
	virtual void PossessedBy(AController* NewController) override;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attribute")
	FOnAttributeChangeSignature OnMaxHealthChangedDelegate;
	
	UPROPERTY(BlueprintAssignable, Category="GAS|Attribute")
	FOnAttributeChangeSignature OnHealthChangedDelegate;

	virtual void Die_Implementation() override;
	
protected:
	virtual void BeginPlay() override;
	
	virtual void InitAbilityActorInfo() override;

	UPROPERTY(EditDefaultsOnly)
	float LifeSpan = 5.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	TObjectPtr<AKaijuAIController> KaijuAIController;

	UPROPERTY(EditAnywhere, Category = "AI")
	TObjectPtr<UBehaviorTree> BehaviorTree;
};
