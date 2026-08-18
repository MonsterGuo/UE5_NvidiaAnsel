// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Ansel : ModuleRules
{
	public Ansel(ReadOnlyTargetRules Target) : base(Target)
    {
	    PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateDependencyModuleNames.AddRange(
	        new string[]
        {
			"Core",
			"CoreUObject",
            "SlateCore",
			"Engine",
			"RenderCore",
			"RHI",
            "NVAnselSDK",
            "Projects"
		});
        PublicDependencyModuleNames.AddRange(
	        new string[]
	        {
		        "Engine",
		        "NVAnselSDK"
	        }
        );
    }
}
