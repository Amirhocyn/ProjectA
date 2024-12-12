// Copyright Amirhocyn


#include "UI/Widget/AuraUserWidget.h"

void UAuraUserWidget::SetWidgetContoller(UObject* InWidgetController)
{
	WidgetContoller = InWidgetController;
	WidgetControllerSet();
}
