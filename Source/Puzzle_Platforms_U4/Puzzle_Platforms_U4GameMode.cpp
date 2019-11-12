// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Puzzle_Platforms_U4GameMode.h"
#include "Puzzle_Platforms_U4Character.h"
#include "UObject/ConstructorHelpers.h"

APuzzle_Platforms_U4GameMode::APuzzle_Platforms_U4GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
