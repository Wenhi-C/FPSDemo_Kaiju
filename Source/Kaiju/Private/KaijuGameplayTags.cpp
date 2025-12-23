// Copyright Wenhi


#include "KaijuGameplayTags.h"

#include "GameplayTagsManager.h"

FKaijuGameplayTags FKaijuGameplayTags::GameplayTags;

void FKaijuGameplayTags::InitializeNativeGameplayTags()
{
	GameplayTags.Abilities_Fire = UGameplayTagsManager::Get().AddNativeGameplayTag(
		"Abilities.Fire",
		FString("Fire Ability"));
}
