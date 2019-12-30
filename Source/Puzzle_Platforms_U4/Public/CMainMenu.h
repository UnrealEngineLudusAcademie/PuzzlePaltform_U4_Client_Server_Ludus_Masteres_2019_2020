// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CMenuWidget.h"
#include "CMainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLE_PLATFORMS_U4_API UCMainMenu : public UCMenuWidget
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
			class UButton* ConfirmJoinMenuButton;

		UPROPERTY(meta = (BindWidget))
			class UWidgetSwitcher* MenuSwitcher;

		UPROPERTY(meta = (BindWidget))
			class UWidget* MainMenu;

		UPROPERTY(meta = (BindWidget))
			class UWidget* JoinMenu;

		UPROPERTY(meta = (BindWidget))
			class UEditableTextBox* IPAddressField;

		UFUNCTION()
			void hostServer();

		UFUNCTION()
			void JoinServer();


		UFUNCTION()
			void OpenJoinMenu();

		UFUNCTION()
			void OpenMainMenu();





protected :

	 bool Initialize();

	




};
