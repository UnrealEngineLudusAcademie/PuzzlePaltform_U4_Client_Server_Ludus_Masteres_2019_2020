// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Puzzle_Platforms_U4EditorTarget : TargetRules
{
	public Puzzle_Platforms_U4EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("Puzzle_Platforms_U4");
	}
}
