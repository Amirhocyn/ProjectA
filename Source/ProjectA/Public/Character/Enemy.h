// Copyright Amirhocyn

#pragma once

#include "CoreMinimal.h"
#include "Character/PlayerCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "Enemy.generated.h"

class UWidgetComponent;
/**
 * 
 */
UCLASS()
class PROJECTA_API AEnemy : public APlayerCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AEnemy();

	// Enemy Interface 
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	// End Enemy Interface

	/** Combat Interface */
	virtual int32 GetPlayerLevel() override;
	/** end Combat Interface */

	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSingnature OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSingnature OnMaxHealthChanged;
protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Charecter Class Defaults")
	int32 Level = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;

private:
	
};
