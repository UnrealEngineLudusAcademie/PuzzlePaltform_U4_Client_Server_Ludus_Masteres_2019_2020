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

	GlobalStartLocation = GetActorLocation(); //Recuperation du vecteur courant de la position Actor
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation); //Definition de la position finale du deplacement
}

void ACMovingPlatform::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);


	if (HasAuthority()) {

		FVector Location = GetActorLocation();
		float JourneyLenght = (GlobalTargetLocation - GlobalStartLocation).Size();//Determine la longueur du deplacement
		float JourneyTravelled = (Location - GlobalStartLocation).Size(); //Deplacement realise
		
		if (JourneyTravelled >= JourneyLenght) {
			FVector Swap = GlobalStartLocation;
			GlobalStartLocation = GlobalTargetLocation;
			GlobalTargetLocation = Swap;

		}
		
		FVector Direction = (GlobalTargetLocation - Location).GetSafeNormal();
		Location += fltSpeed * DeltaTime*Direction;
		SetActorLocation(Location);

	}
	



}
