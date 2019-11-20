// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CMovingPlatform.h"
#include "CPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLE_PLATFORMS_U4_API ACPlatform : public ACMovingPlatform
{
	GENERATED_BODY()


public :
	ACPlatform();

	virtual void Tick(float DeltaTime) override;

	virtual void print() override;
	
};
