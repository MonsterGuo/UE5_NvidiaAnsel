//Copyright MonsterGuoGuo, Inc. All Rights Reserved.

using System;
using System.IO;
using UnrealBuildTool;

public class NVAnselSDK : ModuleRules
{
	public NVAnselSDK(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			string IncPath = Path.Combine(ModuleDirectory, "include");
			PublicSystemIncludePaths.Add(IncPath);

			string LibPath = Path.Combine(ModuleDirectory, "lib");
			PublicAdditionalLibraries.Add(Path.Combine(LibPath,"AnselSDK64.lib"));
			
			PublicDelayLoadDLLs.Add("AnselSDK64.dll");
			RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/AnselSDK64.dll");
			//这里是添加的变量
			PublicDefinitions.Add("WITH_ANSEL=1");
			PublicDefinitions.Add("ANSEL_DLL=" + "AnselSDK64.dll");
		}
	}
}