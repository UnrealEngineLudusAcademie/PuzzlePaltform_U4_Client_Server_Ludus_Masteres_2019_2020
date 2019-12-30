// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CMenuInterface.h"
#include "CMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLE_PLATFORMS_U4_API UCMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	class ICMenuInterface *MenuInterface;

public:

	void SetMenuInterface(ICMenuInterface *MenuInterface);

	void Setup();
	void Teardown();


	
};
