// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "CMovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLE_PLATFORMS_U4_API ACMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()


public :

	ACMovingPlatform();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float fltSpeed;
		 
	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector TargetLocation;


	
};
