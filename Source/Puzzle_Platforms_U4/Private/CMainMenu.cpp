// Fill out your copyright notice in the Description page of Project Settings.


#include "CMainMenu.h"
#include "CMenuInterface.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"



bool UCMainMenu::Initialize()
{
	//Initialisation callbacks Bouton
	bool blnSuccess = Super::Initialize();

	if (!blnSuccess)return false;

	if (!ensure(HostButton != nullptr)) return false;

	//Ajout click event OnClicked + appel ref fonction hostServer
	HostButton->OnClicked.AddDynamic(this, &UCMainMenu::hostServer);

	if (!ensure(JoinButton != nullptr)) return false;
	JoinButton->OnClicked.AddDynamic(this, &UCMainMenu::OpenJoinMenu);

	if (!ensure(CancelJoinMenuButton != nullptr)) return false;
	CancelJoinMenuButton->OnClicked.AddDynamic(this, &UCMainMenu::OpenMainMenu);


	return true;
}

void UCMainMenu::SetMenuInterface(class ICMenuInterface * MenuInterface)
{
	this->MenuInterface = MenuInterface;
}

void UCMainMenu::Setup()
{

	//display at screen
	this->AddToViewport();

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	//UI Input Mode show Cursor
	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(this->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	PlayerController->SetInputMode(InputModeData);

	PlayerController->bShowMouseCursor = true;
}

void UCMainMenu::Teardown()
{

	this->RemoveFromViewport();

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeGameOnly InputModeData;
	PlayerController->SetInputMode(InputModeData);

	PlayerController->bShowMouseCursor = false;
}


void UCMainMenu::hostServer()
{	
	if (this->MenuInterface != nullptr) {
		this->MenuInterface->Host();
		
	}

	
}

void UCMainMenu::OpenJoinMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(JoinMenu != nullptr)) return;
	MenuSwitcher->SetActiveWidget(JoinMenu);
}

void UCMainMenu::OpenMainMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(JoinMenu != nullptr)) return;
	MenuSwitcher->SetActiveWidget(MainMenu);
}
