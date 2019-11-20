// Fill out your copyright notice in the Description page of Project Settings.


#include "CMovingPlatform.h"


ACMovingPlatform::ACMovingPlatform() {


	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);//La plateforme est mobile
	
	nActiveTriggers = 1;//variable d'activation le déplacement de la plateforme


}

void ACMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority()) {//Set autorisation d'execution du code client/server

		SetReplicates(true);//Active la replication sur les clients
		SetReplicateMovement(true);//Active la replication des mouvements sur les clients

	}

	GlobalStartLocation = GetActorLocation(); //Recuperation du vecteur courant de la position Actor
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation); //Definition de la position finale du deplacement
}

void ACMovingPlatform::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

	

	if (nActiveTriggers>0) { //Si variable d'activation de la du déplacement de la plateforme est > 1


		if (HasAuthority()) { //Set autorisation d'execution du code client/server

			FVector Location = GetActorLocation();
			float fltJourneyLenght = (GlobalTargetLocation - GlobalStartLocation).Size();//Determine la longueur du deplacement
			float fltJourneyTravelled = (Location - GlobalStartLocation).Size(); //Deplacement realise
		
			if (fltJourneyTravelled >= fltJourneyLenght) { //Set retour de la plateforme
				FVector Swap = GlobalStartLocation;
				GlobalStartLocation = GlobalTargetLocation;
				GlobalTargetLocation = Swap;

			}
		
			FVector Direction = (GlobalTargetLocation - Location).GetSafeNormal();
			Location += fltSpeed * DeltaTime*Direction;
			SetActorLocation(Location);

		}

	


	}



}

void ACMovingPlatform::AddActiveTrigger()
{
	
	nActiveTriggers++;//Incrementation de la variable si active trigger(overlap trigger)

	UE_LOG(LogTemp, Warning, TEXT("ActiveTrigger %d"), nActiveTriggers);
}

void ACMovingPlatform::RemoveActiveTrigger()
{
	if (nActiveTriggers > 0)
		nActiveTriggers--; //Decrementation de la variable si pas active trigger(overlap trigger)

	UE_LOG(LogTemp, Warning, TEXT("ActiveTrigger %d"), nActiveTriggers);
}

void ACMovingPlatform::print()
{
	UE_LOG(LogTemp, Warning, TEXT("Print CMovingPlatform"));
}
