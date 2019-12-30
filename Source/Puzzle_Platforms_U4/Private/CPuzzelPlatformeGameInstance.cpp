// Fill out your copyright notice in the Description page of Project Settings.


#include "CPuzzelPlatformeGameInstance.h"

#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "CPlatformTrigger.h"
#include "CMainMenu.h"

UCPuzzelPlatformeGameInstance::UCPuzzelPlatformeGameInstance(const FObjectInitializer & ObjectInitializer)
{
	

	ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/MenuSystem/WBP_MainMenu"));
	if (!ensure(MenuBPClass.Class != nullptr))
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing UI Class"));
		return;
	}
		
	MenuClass = MenuBPClass.Class;
}

void UCPuzzelPlatformeGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Found class %s"), *MenuClass->GetName());
}

void UCPuzzelPlatformeGameInstance::Host()
{
	UEngine *Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));

	UWorld *World = GetWorld();
	if (!ensure(Engine != nullptr))return;

	World->ServerTravel("/Game/Maps/ThirdPersonExampleMap?listen");
	
}

void UCPuzzelPlatformeGameInstance::Join(const FString & Adress)
{
	UEngine *Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, FString::Printf(TEXT("Joining %s"),*Adress));

	APlayerController *PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel(Adress, ETravelType::TRAVEL_Absolute);

}

void UCPuzzelPlatformeGameInstance::LoadMenu()
{
	if (!ensure(MenuClass != nullptr)) return;

	UCMainMenu* Menu = CreateWidget<UCMainMenu>(this, MenuClass);

	if (!ensure(Menu != nullptr)) return;
	//display at screen
	Menu->AddToViewport();

	APlayerController *PlayerController = GetFirstLocalPlayerController();

	if (!ensure(PlayerController != nullptr))return;


	//UI Input Mode show Cursor
	FInputModeUIOnly InputModeData;

	InputModeData.SetWidgetToFocus(Menu->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	PlayerController->SetInputMode(InputModeData);

	PlayerController->bShowMouseCursor = true;

	Menu->SetMenuInterface(this);



}
