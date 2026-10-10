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
            // VROptionsMenuGen: widget Blueprints, their trees and function graphs.
            "UMG",
            "UMGEditor",
            "Kismet",
            "BlueprintGraph",
            "KismetCompiler",
            "Slate",
            "SlateCore",
            // VROptionsMenuGen: the category icon texture is read from a PNG.
            "ImageWrapper",
        });
    }
}
