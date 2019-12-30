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
		class UButton *HostButton;

		UPROPERTY(meta = (BindWidget))
		class UButton *JoinButton;

		UPROPERTY(meta = (BindWidget))
			class UButton* CancelJoinMenuButton;

		UPROPERTY(meta = (BindWidget))
			class UWidgetSwitcher* MenuSwitcher;

		UPROPERTY(meta = (BindWidget))
			class UWidget* MainMenu;

		UPROPERTY(meta = (BindWidget))
			class UWidget* JoinMenu;

		UFUNCTION()
			void hostServer();


		UFUNCTION()
			void OpenJoinMenu();

		UFUNCTION()
			void OpenMainMenu();





protected :

	 bool Initialize();

	 class ICMenuInterface *MenuInterface;

public : 
	void SetMenuInterface(ICMenuInterface *MenuInterface);

	void Setup();
	void Teardown();



};
