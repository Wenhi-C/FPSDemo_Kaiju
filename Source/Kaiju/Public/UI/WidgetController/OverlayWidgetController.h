// Copyright Wenhi

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/KaijuWidgetController.h"
#include "OverlayWidgetController.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeChangeSignature, float, NewValue);
/**
 * 
 */
UCLASS()
class KAIJU_API UOverlayWidgetController : public UKaijuWidgetController
{
	GENERATED_BODY()
	
};
