// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CMenuInterface.h"
#include "CPuzzelPlatformeGameInstance.generated.h"


/**
 * 
 */
UCLASS()
class PUZZLE_PLATFORMS_U4_API UCPuzzelPlatformeGameInstance : public UGameInstance,public ICMenuInterface
{
	GENERATED_BODY()

public :

		UCPuzzelPlatformeGameInstance(const FObjectInitializer& ObjectInitializer);

		virtual void Init();

		UFUNCTION(Exec)
			void Host()override;
	
		UFUNCTION(Exec)
			void Join(const FString & Adress)override;

		void LoadMainMenu()override;
		
		UFUNCTION(BlueprintCallable)
			void LoadMenu();

		UFUNCTION(BlueprintCallable)
			void InGameLoadMenu();



private:

	TSubclassOf<class UUserWidget> MenuClass;
	TSubclassOf<class UUserWidget> InGameMenuClass;

	class UCMainMenu* Menu;
};
