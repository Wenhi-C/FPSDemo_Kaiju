// Copyright Wenhi

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "KaijuGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class KAIJU_API UKaijuGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:

	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag;
protected:
	
};
