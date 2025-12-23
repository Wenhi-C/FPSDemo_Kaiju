// Copyright Wenhi


#include "KaijuAssetManager.h"

#include "KaijuGameplayTags.h"

UKaijuAssetManager& UKaijuAssetManager::Get()
{
	check(GEngine);
	UKaijuAssetManager* KaijuAssetManager = Cast<UKaijuAssetManager>(GEngine->AssetManager);
	return *KaijuAssetManager;
}

void UKaijuAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FKaijuGameplayTags::InitializeNativeGameplayTags();
}
