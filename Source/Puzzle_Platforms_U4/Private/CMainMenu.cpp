// Fill out your copyright notice in the Description page of Project Settings.


#include "CMainMenu.h"
#include "CMenuInterface.h"
#include "Components/Button.h"



bool UCMainMenu::Initialize()
{
	//Initialisation callbacks Bouton
	bool blnSuccess = Super::Initialize();

	if (!blnSuccess)return false;

	if (!ensure(Host != nullptr)) return false;

	//Ajout click event OnClicked + appel ref fonction hostServer
	Host->OnClicked.AddDynamic(this, &UCMainMenu::hostServer);


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