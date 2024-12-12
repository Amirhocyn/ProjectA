// Copyright Amirhocyn

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuraUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTA_API UAuraUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetContoller(UObject* InWidgetController);

	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetContoller;
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
