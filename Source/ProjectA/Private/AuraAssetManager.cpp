// Copyright Amirhocyn


#include "AuraAssetManager.h"
#include "AuraGameplayTags.h"


UAuraAssetManager& UAuraAssetManager::Get()
{
	check(GEngine);
	UAuraAssetManager* AuraAssetManager = Cast<UAuraAssetManager>(GEngine->AssetManager);
	return *AuraAssetManager;
}

void UAuraAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	FAuraGamePlayTags::InitializedNativeGameplayTags();

	//This is required to use Target Data.
	//UAbilitySystemGlobals::Get().InitGlobalData();
}
