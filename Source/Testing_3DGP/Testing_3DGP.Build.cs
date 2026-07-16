// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Testing_3DGP : ModuleRules
{
	public Testing_3DGP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Testing_3DGP",
			"Testing_3DGP/Variant_Horror",
			"Testing_3DGP/Variant_Horror/UI",
			"Testing_3DGP/Variant_Shooter",
			"Testing_3DGP/Variant_Shooter/AI",
			"Testing_3DGP/Variant_Shooter/UI",
			"Testing_3DGP/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
