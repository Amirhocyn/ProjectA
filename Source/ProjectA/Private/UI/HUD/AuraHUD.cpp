// Copyright Amirhocyn


#include "UI/HUD/AuraHUD.h"
#include "UI/Widget/AuraUserWidget.h"
#include "Blueprint/UserWidget.h"
#include "UI/WidgetController/AttributeWidgetController.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParam& WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		OverlayWidgetController->BindCallbacksToDependencies();
	}

	return OverlayWidgetController;
}

UAttributeWidgetController* AAuraHUD::GetAttributeWidgetController(const FWidgetControllerParam& WCParams)
{
	if (AttributeWidgetController == nullptr)
    	{
    		AttributeWidgetController = NewObject<UAttributeWidgetController>(this, AttributeWidgetControllerClass);
    		AttributeWidgetController->SetWidgetControllerParams(WCParams);
    		AttributeWidgetController->BindCallbacksToDependencies();
    	}
	return AttributeWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("Overlay widget class uninitialized, please fill out BP_AuraHUD "));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay widget class controller uninitialized, please fill out BP_AuraHUD "));
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(Widget);

	const FWidgetControllerParam WidgetControllerParam(PC, PS, ASC, AS);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParam);

	OverlayWidget->SetWidgetContoller(WidgetController);
	WidgetController->BroadcastinitialValues();
	Widget->AddToViewport();
}
