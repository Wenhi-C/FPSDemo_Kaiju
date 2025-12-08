// Copyright Wenhi

#pragma once

#include "CoreMinimal.h"
#include "Character/KaijuBaseCharacter.h"
#include "KaijuEnemy.generated.h"

/**
 * 
 */
UCLASS()
class KAIJU_API AKaijuEnemy : public AKaijuBaseCharacter
{
	GENERATED_BODY()
public:
	AKaijuEnemy();
protected:
	virtual void BeginPlay() override;
	
	virtual void InitAbilityActorInfo() override;
};
