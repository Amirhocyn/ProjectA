// Copyright Amirhocyn

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "AuraEffectActor.generated.h"

class UAbilitySystemComponent;
class UGameplayEffect;

UENUM(BluePrintType)
enum class EEfectApplicationPolicy: uint8
{
	ApplyOnOverlap,
	ApplyOnEndOverlap,
	DoNotApply
};

UENUM(BluePrintType)
enum class EEfectRemovalPolicy: uint8
{
	RemoveOnEndOverlap,
	DoNotRemove
};

UCLASS()
class PROJECTA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AAuraEffectActor();
protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);

	UFUNCTION(BlueprintCallable)
	void OnOverlap(AActor* TargetActor);

	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(AActor* TargetActor);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Applied Effects")
	bool bDestroyOnEffectRemoval = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

	UPROPERTY(EditAnywhere,  BlueprintReadOnly, Category= "Applied Effects")
	EEfectApplicationPolicy InstantEffectApplicationPolicy = EEfectApplicationPolicy::DoNotApply;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Applied Effects")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;

	UPROPERTY(EditAnywhere,  BlueprintReadOnly, Category= "Applied Effects")
	EEfectApplicationPolicy DurationEffectApplicationPolicy =  EEfectApplicationPolicy::DoNotApply;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Applied Effects")
	TSubclassOf<UGameplayEffect> InfiniteGameplayEffectClass;

	UPROPERTY(EditAnywhere,  BlueprintReadOnly, Category= "Applied Effects")
	EEfectApplicationPolicy InfiniteEffectApplicationPolicy =  EEfectApplicationPolicy::DoNotApply;

	UPROPERTY(EditAnywhere,  BlueprintReadOnly, Category= "Applied Effects")
	EEfectRemovalPolicy InfiniteEffectRemovalPolicy = EEfectRemovalPolicy::RemoveOnEndOverlap;

	TMap<FActiveGameplayEffectHandle, UAbilitySystemComponent*> ActiveEffectHandlels;

	UPROPERTY(EditAnywhere,  BlueprintReadOnly, Category= "Applied Effects")
	float ActorLevel = 1.f;

private:

};
