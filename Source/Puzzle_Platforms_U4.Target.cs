// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Puzzle_Platforms_U4Target : TargetRules
{
	public Puzzle_Platforms_U4Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.Add("Puzzle_Platforms_U4");
	}
}
