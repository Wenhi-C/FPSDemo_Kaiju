// Copyright Wenhi


#include "UI/KaijuUserWidget.h"

void UKaijuUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
