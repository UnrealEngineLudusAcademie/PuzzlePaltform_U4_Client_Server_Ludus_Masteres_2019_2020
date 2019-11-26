// Fill out your copyright notice in the Description page of Project Settings.


#include "CPuzzelPlatformeGameInstance.h"

#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"

UCPuzzelPlatformeGameInstance::UCPuzzelPlatformeGameInstance(const FObjectInitializer & ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("Dans le constructeur"));
}

void UCPuzzelPlatformeGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Dans la methode init()"));
}

void UCPuzzelPlatformeGameInstance::Host()
{
	UEngine *Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));

	UWorld *World = GetWorld();
	if (!ensure(Engine != nullptr))return;

	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");

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
