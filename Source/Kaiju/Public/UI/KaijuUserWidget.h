// Copyright Wenhi

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "KaijuUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class KAIJU_API UKaijuUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
