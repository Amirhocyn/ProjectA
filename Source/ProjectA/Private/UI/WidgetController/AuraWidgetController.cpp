// Copyright Amirhocyn


#include "UI/WidgetController/AuraWidgetController.h"

#include "UI/WidgetController/OverlayWidgetController.h"

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParam& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UAuraWidgetController::BroadcastinitialValues()
{
	
}

void UAuraWidgetController::BindCallbacksToDependencies()
{
	
}
