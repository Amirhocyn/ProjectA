// Copyright Amirhocyn

#pragma once

#include "CoreMinimal.h"
#include "Character/PlayerCharacterBase.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTA_API APlayerCharacter : public APlayerCharacterBase
{
	GENERATED_BODY()
	
public:
	APlayerCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	/** Combat Interface */
	virtual int32 GetPlayerLevel() override;
	/** end Combat Interface */
private:
	virtual void InitAbilityActorInfo() override;
};
