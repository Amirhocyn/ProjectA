// Copyright Amirhocyn

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AuraAbilitySystemLibrary.generated.h"

class UAttributeWidgetController;
class UOverlayWidgetController;
/**
 * 
 */
UCLASS()
class PROJECTA_API UAuraAbilitySystemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category= "AuraAbilitySystemLibrary|WidgetController")
	static UOverlayWidgetController* GetOverlayWidgetController(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category= "AuraAbilitySystemLibrary|WidgetController")
	static UAttributeWidgetController* GetAttributeWidgetController(const UObject* WorldContextObject);
};
