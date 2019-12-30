// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CMainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLE_PLATFORMS_U4_API UCMainMenu : public UUserWidget
{
	GENERATED_BODY()

private :


		UPROPERTY(meta = (BindWidget))
		class UButton *Host;

		UPROPERTY(meta = (BindWidget))
		class UButton *Join;

		UFUNCTION()
			void hostServer();




protected :

	 bool Initialize();

	 class ICMenuInterface *MenuInterface;

public : 
	void SetMenuInterface(ICMenuInterface *MenuInterface);

	void Setup();
	void Teardown();



};
