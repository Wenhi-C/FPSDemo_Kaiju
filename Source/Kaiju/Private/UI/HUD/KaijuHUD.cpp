// Copyright Wenhi


#include "UI/HUD/KaijuHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/KaijuUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AKaijuHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
	}
	return OverlayWidgetController;
}

void AKaijuHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	check(OverlayWidgetControllerClass);
	check(OverlayWidgetClass);

	OverlayWidget = CreateWidget<UKaijuUserWidget>(GetWorld(), OverlayWidgetClass);
	const FWidgetControllerParams WCParams = FWidgetControllerParams(PC, PS, ASC, AS);
	GetOverlayWidgetController(WCParams);
	OverlayWidget->SetWidgetController(OverlayWidgetController);
	OverlayWidget->AddToViewport();
	
}
