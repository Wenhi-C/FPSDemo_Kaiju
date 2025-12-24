// Copyright Wenhi

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 *
 * 单例模式 包含 Native Gameplay Tags
 */
struct  FKaijuGameplayTags
{
public:
	static const FKaijuGameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeGameplayTags();

	FGameplayTag Abilities_Fire;

	FGameplayTag Input_Fire;
protected:
	
private:
	static FKaijuGameplayTags GameplayTags;
};
