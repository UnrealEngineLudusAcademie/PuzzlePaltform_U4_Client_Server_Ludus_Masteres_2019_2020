// Fill out your copyright notice in the Description page of Project Settings.


#include "CPlatformTrigger.h"
#include "Components/BoxComponent.h"
#include "CMovingPlatform.h"

// Sets default values
ACPlatformTrigger::ACPlatformTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(FName("TriggerVolume"));//Creation du trigger volume
	if (!ensure(TriggerVolume != nullptr)) return;

	RootComponent = TriggerVolume; //set trigger volume => root
	
	
	
	
	

}

// Called when the game starts or when spawned
void ACPlatformTrigger::BeginPlay()
{
	Super::BeginPlay();
	
	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &ACPlatformTrigger::OnOverlapBegin); // delegate execution Methode OnOverlapBegin (callBack reference) 
	TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &ACPlatformTrigger::OnOverlapEnd);// delegate execution Methode OnOverlapBegin (callBack reference) 
}

// Called every frame
void ACPlatformTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	


}


//Methode Trigger overlap Yes
void ACPlatformTrigger::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("On Begin Overlap"));

	for (ACMovingPlatform* Platform : PlatformsToTrigger)
	{
		Platform->AddActiveTrigger();
	}

}

//Methode Trigger overlap No
void ACPlatformTrigger::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {

	UE_LOG(LogTemp, Warning, TEXT("On End Overlap"));

	for (ACMovingPlatform* Platform : PlatformsToTrigger)
	{
		Platform->RemoveActiveTrigger();
	}
}
