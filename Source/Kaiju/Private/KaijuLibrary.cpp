// Copyright Wenhi


#include "KaijuLibrary.h"

#include "Kismet/GameplayStatics.h"
#include "UI/HUD/KaijuHUD.h"
#include "UI/WidgetController/KaijuWidgetController.h"

UOverlayWidgetController* UKaijuLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	FWidgetControllerParams WCParams;
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AKaijuHUD* KaijuHUD = Cast<AKaijuHUD>(PC->GetHUD()))
		{
			return KaijuHUD->GetOverlayWidgetController(WCParams);
		}
	}
	return nullptr;
}
