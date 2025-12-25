// Copyright Wenhi

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "UObject/NoExportTypes.h"
#include "KaijuWidgetController.generated.h"

class UKaijuAttributeSet;
class UKaijuAbilitySystemComponent;
class AKaijuPlayerState;
class AKaijuPlayerController;
class UAttributeSet;
class UAbilitySystemComponent;

USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
	GENERATED_BODY()

	FWidgetControllerParams() {}
	FWidgetControllerParams(APlayerController* PC, APlayerState* APS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
		: PlayerController(PC), PlayerState(APS), AbilitySystemComponent(ASC), AttributeSet(AS) {}

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<APlayerState> PlayerState = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<UAttributeSet> AttributeSet = nullptr;
};

/**
 * 
 */
UCLASS()
class KAIJU_API UKaijuWidgetController : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetControllerParams(const FWidgetControllerParams& WCParams);

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<APlayerState> PlayerState = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UAttributeSet> AttributeSet = nullptr;
	
	AKaijuPlayerController* GetKaijuPlayerController();
	AKaijuPlayerState* GetKaijuPlayerState();
	UKaijuAbilitySystemComponent* GetKaijuAbilitySystemComponent();
	UKaijuAttributeSet* GetKaijuAttributeSet();
	
private:

	UPROPERTY()
	TObjectPtr<AKaijuPlayerController> KaijuPlayerController;

	UPROPERTY()
	TObjectPtr<AKaijuPlayerState> KaijuPlayerState;

	UPROPERTY()
	TObjectPtr<UKaijuAbilitySystemComponent> KaijuAbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UKaijuAttributeSet> KaijuAttributeSet;
};
