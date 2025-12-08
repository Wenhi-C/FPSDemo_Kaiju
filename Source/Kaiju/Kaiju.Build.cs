// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Kaiju : ModuleRules
{
	public Kaiju(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "GameplayAbilities", "GameplayTags", "GameplayTasks", "NavigationSystem", "Niagara", "AIModule"});
		
		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
