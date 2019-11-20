// Fill out your copyright notice in the Description page of Project Settings.


#include "CPlatform.h"

ACPlatform::ACPlatform() {

	nActiveTriggers = 0;

}

void ACPlatform::Tick(float DeltaTime)
{
	print();
}

void ACPlatform::print()
{
	UE_LOG(LogTemp, Warning, TEXT("Print CPlatform"));
}
