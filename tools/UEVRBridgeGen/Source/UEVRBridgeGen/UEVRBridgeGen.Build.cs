using UnrealBuildTool;

public class UEVRBridgeGen : ModuleRules
{
    public UEVRBridgeGen(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new[] { "Core" });

        PrivateDependencyModuleNames.AddRange(new[]
        {
            "CoreUObject",
            "Engine",
            "UnrealEd",
            "AssetRegistry",
            "Projects",
        });
    }
}
