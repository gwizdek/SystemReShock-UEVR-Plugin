# Common Pitfalls & Troubleshooting

## Overview

This reference covers common mistakes, debugging strategies, and solutions to frequent Unreal Engine development issues. Load when encountering errors, unexpected behavior, or project setup problems.

## Input System Issues

### Enhanced Input Not Working

**Symptoms**:
- Input actions don't fire
- Character doesn't respond to keyboard/mouse

**Checklist**:
1. **Plugin enabled**: Check `.uproject` has `"EnhancedInput"` plugin enabled
2. **Module dependency**: Verify `EnhancedInput` in `Build.cs`
3. **Mapping context added**: Must call `AddMappingContext` in `BeginPlay`
4. **Input actions assigned**: Check Blueprint Details panel has Input Actions set
5. **Correct component type**: Must cast to `UEnhancedInputComponent`, not base `UInputComponent`
6. **Project settings**: Editor → Project Settings → Input → Default Classes → Enhanced Input Component

**Common mistake**:
```cpp
// WRONG - base component doesn't support Enhanced Input
if (UInputComponent* Input = PlayerInputComponent)
{
    Input->BindAction(MoveAction, ...); // Won't compile
}

// CORRECT
if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
{
    EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyCharacter::Move);
}
```

### Input Actions Not Found

**Symptom**: Null pointer when trying to bind Input Action

**Cause**: Input Action asset not assigned in Blueprint or doesn't exist

**Solution**:
```bash
# Discover what Input Actions actually exist
find Content -name "IA_*.uasset"

# Or search broadly
find Content -name "*InputAction*.uasset"
```

Then verify asset path matches what's in Blueprint.

### Wrong Trigger Event

**Symptom**: Callback fires too many times or not at all

**Cause**: Using wrong `ETriggerEvent` type

**Solution**:
- `Started` - Once on initial press (good for single-fire actions)
- `Triggered` - Every frame while conditions met (good for movement)
- `Ongoing` - While input active (rarely used)
- `Completed` - Once on release (good for charge-ups)
- `Canceled` - When interrupted

```cpp
// WRONG for continuous movement
EnhancedInput->BindAction(MoveAction, ETriggerEvent::Started, ...);

// CORRECT
EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, ...);
```

## Gameplay Ability System Issues

### Ability Not Activating

**Symptoms**:
- `TryActivateAbility` returns false
- Ability logic never executes

**Debug checklist**:
1. **Authority**: Abilities only activate on server
```cpp
if (!HasAuthority())
{
    UE_LOG(LogTemp, Warning, TEXT("No authority - ability won't activate"));
}
```

2. **ASC initialized**: Must call `InitAbilityActorInfo`
```cpp
// In PossessedBy
AbilitySystemComponent->InitAbilityActorInfo(this, this);
```

3. **Ability granted**: Check ability was given via `GiveAbility`
```cpp
// Use showdebug abilitysystem to verify
```

4. **CommitAbility succeeds**: Check costs, cooldowns, tags
```cpp
if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
{
    UE_LOG(LogTemp, Warning, TEXT("CommitAbility failed - check costs/cooldowns/tags"));
    EndAbility(...);
}
```

5. **Tags allow activation**:
```cpp
// Check BlockAbilitiesWithTag and RequiredTags in ability
```

### Attributes Not Replicating

**Symptoms**:
- Client sees wrong attribute values
- UI doesn't update on clients

**Solution**:
```cpp
// In AttributeSet.cpp
void UMyAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    // CRITICAL: Must use DOREPLIFETIME_CONDITION_NOTIFY
    DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, Health, COND_None, REPNOTIFY_Always);
}

// Must implement OnRep
UFUNCTION()
void OnRep_Health(const FGameplayAttributeData& OldHealth)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, Health, OldHealth);
}
```

### GAS Setup on PlayerState vs Character

**Issue**: Confusion about where to place ASC

**For single-player or listen server**:
- ASC on Character is simpler
- Owner = Avatar = Character

**For dedicated server**:
- ASC on PlayerState survives respawns
- Owner = PlayerState, Avatar = Character
- More complex setup but necessary for multiplayer

**Critical initialization**:
```cpp
// If ASC on PlayerState
void AMyCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);
    
    if (AMyPlayerState* PS = GetPlayerState<AMyPlayerState>())
    {
        // Owner is PlayerState, Avatar is Character
        PS->GetAbilitySystemComponent()->InitAbilityActorInfo(PS, this);
    }
}

void AMyCharacter::OnRep_PlayerState()
{
    Super::OnRep_PlayerState();
    
    if (AMyPlayerState* PS = GetPlayerState<AMyPlayerState>())
    {
        PS->GetAbilitySystemComponent()->InitAbilityActorInfo(PS, this);
    }
}
```

## Build & Compilation Issues

### Unresolved External Symbol

**Symptom**: Linker error like `unresolved external symbol "class UClass * __cdecl ..."`

**Common causes**:
1. **Missing module dependency** in `Build.cs`
2. **Missing MODULENAME_API** export macro
3. **Forward declaration where include needed**
4. **Implementation missing** for declared function

**Solutions**:
```csharp
// 1. Add missing modules to Build.cs
PublicDependencyModuleNames.AddRange(new string[] {
    "EnhancedInput",  // If using Enhanced Input
    "GameplayAbilities",  // If using GAS
    "UMG"  // If using UI widgets
});
```

```cpp
// 2. Add export macro for cross-module usage
class PROJECTNAME_API AMyCharacter : public ACharacter
{
    // ...
};
```

### Hot Reload Issues

**Symptom**: Changes not visible after compilation, crashes on hot reload

**Best practice**: **Don't use Hot Reload for significant changes**

**Solution**:
1. Close Unreal Editor
2. Delete `Binaries/`, `Intermediate/`, `Saved/` folders
3. Rebuild in IDE (Visual Studio, Rider)
4. Reopen editor

**When Hot Reload is safe**:
- Function body changes (not signature)
- Constant value changes
- Minor logic tweaks

**When to avoid**:
- Adding/removing UFUNCTIONs
- Adding/removing UPROPERTYs
- Changing class inheritance
- Adding new includes

### "Asset Failed to Load" Errors

**Symptom**: Missing assets, pink textures, errors in log

**Causes**:
1. Asset moved/renamed without fixing redirectors
2. Asset deleted while still referenced
3. Blueprint referencing missing C++ class

**Solutions**:
```bash
# Fix redirectors in Content Browser
Right-click Content folder → Fix Up Redirectors in Folder

# Find asset references
Right-click asset → Reference Viewer
```

## Blueprint vs C++ Integration Issues

### Blueprint Can't See C++ Function

**Symptom**: Function not visible in Blueprint even though marked UFUNCTION

**Checklist**:
1. **UFUNCTION with BlueprintCallable or BlueprintPure**
```cpp
UFUNCTION(BlueprintCallable, Category = "MyCategory")
void MyFunction();
```

2. **Function is public** (Blueprint can't access private/protected)

3. **Class is blueprintable**
```cpp
UCLASS(Blueprintable)
class AMyCharacter : public ACharacter { };
```

4. **Hot reload completed** (see above)

5. **Regenerate project files**
```bash
# Close editor, then:
GenerateProjectFiles.bat  # On Windows
# Or use Unreal Build Tool
```

### Can't Find C++ Class in Blueprint

**Symptom**: Can't create Blueprint child of C++ class

**Solutions**:
1. **Mark class Blueprintable**
```cpp
UCLASS(Blueprintable, BlueprintType)
class PROJECTNAME_API AMyActor : public AActor { };
```

2. **Ensure class is compiled** and editor restarted

3. **Check Show Plugin Content / Show Engine Content** in Content Browser filters

## Asset Reference Issues

### Hard References Causing Long Load Times

**Problem**: Including asset headers causes entire asset to load

**Wrong**:
```cpp
// In header file - causes hard reference
#include "MyHugeAnimation.h"

UPROPERTY(EditAnywhere)
UAnimSequence* Animation = MyHugeAnimation;  // Loads entire asset at compile time
```

**Correct**:
```cpp
// In header - soft reference
UPROPERTY(EditAnywhere)
TSoftObjectPtr<UAnimSequence> Animation;

// Load when needed
if (!Animation.IsNull())
{
    UAnimSequence* LoadedAnim = Animation.LoadSynchronous();
}
```

### Finding Asset References in C++

**Problem**: Need to reference Blueprint or asset in C++

**Method 1: Expose as property**:
```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Assets")
TSubclassOf<UGameplayAbility> AbilityClass;

// Set in Blueprint Details panel
```

**Method 2: Load by path**:
```cpp
// Get reference path: Right-click asset → Copy Reference
// Example: /Game/Blueprints/BP_MyCharacter.BP_MyCharacter_C

TSoftClassPtr<AActor> AssetClass = TSoftClassPtr<AActor>(
    FSoftObjectPath(TEXT("/Game/Blueprints/BP_MyCharacter.BP_MyCharacter_C"))
);

TSubclassOf<AActor> LoadedClass = AssetClass.LoadSynchronous();
```

**Method 3: ConstructorHelpers (for assets, not Blueprints)**:
```cpp
// In constructor only
static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
    TEXT("/Game/Meshes/MyMesh")
);
if (MeshAsset.Succeeded())
{
    Mesh = MeshAsset.Object;
}
```

## Plugin Issues

### Plugin Not Loading

**Symptoms**:
- Classes from plugin not found
- Plugin marked as "Missing" in editor

**Solutions**:
1. **Check `.uproject`**: Ensure plugin listed as enabled
2. **Rebuild project**: Close editor, rebuild from IDE
3. **Check plugin compatibility**: Some plugins require specific engine versions
4. **Module dependencies**: Add plugin modules to `Build.cs`

### Experimental Plugin Documentation Missing

**Strategy**:
```
# Search Epic docs
web_search: "Unreal Engine [PluginName] documentation"

# Search community
web_search: "Unreal Engine [PluginName] tutorial example"

# Check source code
# Engine/Plugins/Experimental/PluginName/Source/
view Engine/Plugins/Experimental/PluginName/Source/Public

# Forums & AnswerHub
web_search: "site:forums.unrealengine.com [PluginName]"
```

## Multiplayer & Replication Issues

### Properties Not Replicating

**Checklist**:
```cpp
// 1. Mark property for replication
UPROPERTY(Replicated)
float Health;

// 2. Set replication in constructor
bReplicates = true;

// 3. Implement GetLifetimeReplicatedProps
void AMyActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AMyActor, Health);
}

// 4. Include Net/UnrealNetwork.h
#include "Net/UnrealNetwork.h"
```

### RPC Not Executing

**Common issues**:
1. **Function not marked for RPC**
```cpp
UFUNCTION(Server, Reliable)
void ServerFunction();

// Must implement _Implementation
void AMyClass::ServerFunction_Implementation()
{
    // Logic here
}
```

2. **Actor not replicated**: `bReplicates = true`
3. **No authority**: Check `GetLocalRole()` and `GetRemoteRole()`

## Performance Issues

### Finding Performance Bottlenecks

**Console commands**:
```
stat fps       // Show FPS
stat unit      // Show frame time breakdown (Game/Draw/GPU)
stat game      // Show game thread stats
stat gpu       // Show GPU stats
profilegpu     // Detailed GPU profiling

// For GAS specifically
showdebug abilitysystem
```

**Common culprits**:
- Too many tick functions: Use timers or events instead
- Hard asset references: Use soft references
- Expensive Blueprint logic in Tick: Move to C++
- Unoptimized GAS usage: Batch gameplay cues, use minimal replication

## Debugging Tools

### Console Commands

```bash
# Input debugging
showdebug enhancedinput   # Enhanced Input state
showdebug input          # Input state (shipping builds)

# GAS debugging  
showdebug abilitysystem  # Full GAS debug info
showdebug gameplay       # Gameplay tags & abilities

# Performance
stat fps
stat unit
stat game
stat gpu

# Network
stat net                 # Network stats
stat netplayerupdate    # Player update frequency

# Collision
show collision          # Visualize collision shapes
```

### Logging

```cpp
// Enable specific log categories
LogAbilitySystem.SetVerbosity(ELogVerbosity::VeryVerbose);
LogInput.SetVerbosity(ELogVerbosity::Verbose);

// Custom logging
UE_LOG(LogTemp, Warning, TEXT("Debug message: %s"), *SomeString);
UE_LOG(LogTemp, Error, TEXT("Critical error"));
```

### Visual Studio Debugging Tips

**Debugging gameplay**:
1. Launch from IDE (F5) not from editor
2. Set breakpoints in C++ code
3. Use Watch window for UObjects
4. Enable "Just My Code" in VS settings

**Common watch expressions**:
```
GetName()           // Actor name
GetOwner()          // Owning actor
HasAuthority()      // Is server?
GetLocalRole()      // Network role
```

## Best Practices to Avoid Issues

1. **Always close editor before rebuilding** after major C++ changes
2. **Use source control** (Git, Perforce) for safety
3. **Test in PIE first**, then packaged build
4. **Check logs** in `Saved/Logs/` when things go wrong
5. **Use forward declarations** in headers when possible
6. **Profile early and often** to catch performance issues
7. **Document assumptions** about asset structure in code comments
8. **Version control asset references** with comments

## Emergency Recovery

### Project Won't Open

1. Delete `Intermediate/`, `Binaries/`, `Saved/` folders
2. Right-click `.uproject` → "Generate Visual Studio project files"
3. Build from IDE
4. Try opening again

### Corrupted Assets

1. Check source control for previous version
2. Use Content Browser → Show in Explorer → check `.uasset` file exists
3. Delete problematic asset (after backup)
4. Re-import or recreate

### Crashes on Launch

1. Check `Saved/Logs/ProjectName.log` for crash callstack
2. Try launching with `-log` parameter for detailed logging
3. Disable plugins one-by-one in `.uproject`
4. Restore from source control if recent changes suspected
