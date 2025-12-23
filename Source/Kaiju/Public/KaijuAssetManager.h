// Copyright Wenhi

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "KaijuAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class KAIJU_API UKaijuAssetManager : public UAssetManager
{
	GENERATED_BODY()
public:
	static UKaijuAssetManager& Get();
protected:
	virtual void StartInitialLoading() override;
};
