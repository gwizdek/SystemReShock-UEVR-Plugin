using UnrealBuildTool;

public class AssetGen : ModuleRules
{
    public AssetGen(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new[] { "Core" });

        PrivateDependencyModuleNames.AddRange(new[]
        {
            "CoreUObject",
            "Engine",
            "UnrealEd",
            "AssetRegistry",
            // The PNGs are found through the plugin's folder.
            "Projects",
            // MenuGen: widget Blueprints, their trees and function graphs.
            "UMG",
            "UMGEditor",
            "Kismet",
            "BlueprintGraph",
            "KismetCompiler",
            "Slate",
            "SlateCore",
            // The textures are read from PNGs.
            "ImageWrapper",
        });
    }
}
