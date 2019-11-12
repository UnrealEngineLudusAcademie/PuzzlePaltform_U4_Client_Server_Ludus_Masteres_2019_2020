// Fill out your copyright notice in the Description page of Project Settings.


#include "CMovingPlatform.h"


ACMovingPlatform::ACMovingPlatform() {


	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);


}

void ACMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority()) {

		SetReplicates(true);//Active la replication sur les clients
		SetReplicateMovement(true);//Active la replication des mouvements sur les clients

	}
}

void ACMovingPlatform::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);


	if (HasAuthority()) {

		FVector Location = GetActorLocation();
		FVector GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
		FVector Direction = (GlobalTargetLocation - Location).GetSafeNormal();
		Location += fltSpeed * DeltaTime*Direction;
		SetActorLocation(Location);

	}
	



}
