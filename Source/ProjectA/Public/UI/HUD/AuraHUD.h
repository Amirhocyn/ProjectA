// Copyright Amirhocyn

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

class UAttributeWidgetController;
class UAttributeSet;
class UAbilitySystemComponent;
struct FWidgetControllerParam;
class UOverlayWidgetController;
class UAuraUserWidget;
/**
 * 
 */
UCLASS()
class PROJECTA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()

public:


	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParam& WCParams);
	UAttributeWidgetController* GetAttributeWidgetController(const FWidgetControllerParam& WCParams);

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

protected:

private:
		
	UPROPERTY()
	TObjectPtr<UAuraUserWidget>  OverlayWidget;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;

	UPROPERTY()
	TObjectPtr<UAttributeWidgetController> AttributeWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAttributeWidgetController> AttributeWidgetControllerClass;
	

	
};
