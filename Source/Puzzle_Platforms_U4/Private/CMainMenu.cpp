// Fill out your copyright notice in the Description page of Project Settings.


#include "CMainMenu.h"
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


void UCMainMenu::hostServer()
{	
	UE_LOG(LogTemp, Warning, TEXT("I'm gonna host a server"));
}