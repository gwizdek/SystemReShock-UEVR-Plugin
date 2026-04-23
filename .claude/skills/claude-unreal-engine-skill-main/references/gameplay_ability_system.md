# Gameplay Ability System (GAS) Reference

## Overview

The Gameplay Ability System is a framework for building abilities, attributes, and effects in gameplay-driven projects (RPGs, MOBAs, action games). Load this reference when working with GAS components, abilities, attributes, or effects.

## Core Components

### Ability System Component (ASC)

The heart of GAS. Acts as the hub for all abilities, attributes, and effects.

**Key responsibilities**:
- Manages granted abilities
- Stores and replicates attributes
- Applies and tracks gameplay effects
- Handles gameplay tags
- Manages ability activation

**Where to place ASC**:
- **Player characters (listen server/standalone)**: On Pawn/Character
- **Player characters (dedicated server)**: On PlayerState (survives respawns)
- **AI/NPCs**: On Character (they don't respawn typically)

### Gameplay Abilities

Individual actions/abilities (attacks, spells, dashes, etc.). Inherit from `UGameplayAbility`.

### Attribute Set

Container for gameplay attributes (Health, Mana, Stamina, Damage, etc.). Inherit from `UAttributeSet`.

### Gameplay Effects

Modify attributes (damage, healing, buffs, debuffs). Created as data assets or classes.

### Gameplay Tags

Hierarchical labels for abilities, effects, and states (e.g., `Ability.Attack.Melee`, `Status.Stunned`).

## Initial Setup

### 1. Enable Plugin & Dependencies

**.uproject**:
```json
{
  "Plugins": [
    {"Name": "GameplayAbilities", "Enabled": true}
  ]
}
```

**ProjectName.Build.cs**:
```csharp
PublicDependencyModuleNames.AddRange(new string[] {
    "Core", 
    "CoreUObject", 
    "Engine", 
    "InputCore",
    "GameplayAbilities",  // ← Core GAS module
    "GameplayTags",       // ← Tag system
    "GameplayTasks"       // ← Async task system
});
```

### 2. Create Ability System Component

**In Character class** (for single-player/listen server):

```cpp
// MyCharacter.h
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"

UCLASS()
class AMyCharacter : public ACharacter, public IAbilitySystemInterface
{
    GENERATED_BODY()

public:
    AMyCharacter();

    // IAbilitySystemInterface
    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
    TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
    
    UPROPERTY()
    TObjectPtr<UAttributeSet> AttributeSet;
};
```

```cpp
// MyCharacter.cpp
AMyCharacter::AMyCharacter()
{
    AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
    AbilitySystemComponent->SetIsReplicated(true);
    AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
    
    AttributeSet = CreateDefaultSubobject<UMyAttributeSet>(TEXT("AttributeSet"));
}

UAbilitySystemComponent* AMyCharacter::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}
```

**In PlayerState** (for dedicated server):

```cpp
// MyPlayerState.h
#include "AbilitySystemInterface.h"

UCLASS()
class AMyPlayerState : public APlayerState, public IAbilitySystemInterface
{
    GENERATED_BODY()

public:
    AMyPlayerState();
    
    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
    TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
    
    UPROPERTY()
    TObjectPtr<UAttributeSet> AttributeSet;
};
```

### 3. Initialize the ASC

**Critical**: Must call `InitAbilityActorInfo` to link Owner and Avatar:

```cpp
void AMyCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);
    
    // Server: Initialize ability actor info
    if (AbilitySystemComponent)
    {
        AbilitySystemComponent->InitAbilityActorInfo(this, this);
    }
}

void AMyCharacter::OnRep_PlayerState()
{
    Super::OnRep_PlayerState();
    
    // Client: Initialize ability actor info
    if (AbilitySystemComponent)
    {
        AbilitySystemComponent->InitAbilityActorInfo(this, this);
    }
}
```

**If ASC is on PlayerState**:
```cpp
// In Character
void AMyCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);
    
    if (AMyPlayerState* PS = GetPlayerState<AMyPlayerState>())
    {
        // Owner = PlayerState, Avatar = Character
        PS->GetAbilitySystemComponent()->InitAbilityActorInfo(PS, this);
    }
}
```

## Creating Attributes

### Attribute Set Class

```cpp
// MyAttributeSet.h
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"

UCLASS()
class UMyAttributeSet : public UAttributeSet
{
    GENERATED_BODY()

public:
    UMyAttributeSet();

    // Attribute accessors - use macros for boilerplate
    UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Health)
    FGameplayAttributeData Health;
    ATTRIBUTE_ACCESSORS(UMyAttributeSet, Health)

    UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxHealth)
    FGameplayAttributeData MaxHealth;
    ATTRIBUTE_ACCESSORS(UMyAttributeSet, MaxHealth)

    UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Mana)
    FGameplayAttributeData Mana;
    ATTRIBUTE_ACCESSORS(UMyAttributeSet, Mana)

    // Replication
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    // Rep notifies
    UFUNCTION()
    virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);
    
    UFUNCTION()
    virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);
    
    UFUNCTION()
    virtual void OnRep_Mana(const FGameplayAttributeData& OldMana);
    
    // Pre/Post attribute change
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};
```

```cpp
// MyAttributeSet.cpp
#include "Net/UnrealNetwork.h"

UMyAttributeSet::UMyAttributeSet()
{
    // Set default values
    InitHealth(100.0f);
    InitMaxHealth(100.0f);
    InitMana(50.0f);
}

void UMyAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, Health, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, Mana, COND_None, REPNOTIFY_Always);
}

void UMyAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, Health, OldHealth);
}

void UMyAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    Super::PreAttributeChange(Attribute, NewValue);
    
    // Clamp health to [0, MaxHealth]
    if (Attribute == GetHealthAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
    }
}

void UMyAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);
    
    // Handle attribute changes (e.g., death when health reaches 0)
    if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    {
        SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
        
        if (GetHealth() <= 0.0f)
        {
            // Handle death
        }
    }
}
```

## Creating Gameplay Abilities

### Basic Ability Class

```cpp
// MyGameplayAbility.h
#include "Abilities/GameplayAbility.h"

UCLASS()
class UMyGameplayAbility : public UGameplayAbility
{
    GENERATED_BODY()

public:
    UMyGameplayAbility();

protected:
    // Called when ability is activated
    virtual void ActivateAbility(
        const FGameplayAbilitySpecHandle Handle,
        const FGameplayAbilityActorInfo* ActorInfo,
        const FGameplayAbilityActivationInfo ActivationInfo,
        const FGameplayEventData* TriggerEventData
    ) override;
    
    // Called when ability ends
    virtual void EndAbility(
        const FGameplayAbilitySpecHandle Handle,
        const FGameplayAbilityActorInfo* ActorInfo,
        const FGameplayAbilityActivationInfo ActivationInfo,
        bool bReplicateEndAbility,
        bool bWasCancelled
    ) override;
};
```

```cpp
// MyGameplayAbility.cpp
void UMyGameplayAbility::ActivateAbility(...)
{
    if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
        return;
    }
    
    // Ability logic here
    // ...
    
    // End ability when done (for instant abilities)
    EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
```

### Granting Abilities

**At runtime** (usually in BeginPlay or on possession):

```cpp
void AMyCharacter::GiveAbilities()
{
    if (!HasAuthority() || !AbilitySystemComponent)
        return;
    
    for (TSubclassOf<UGameplayAbility>& StartupAbility : DefaultAbilities)
    {
        AbilitySystemComponent->GiveAbility(
            FGameplayAbilitySpec(StartupAbility, 1, INDEX_NONE, this)
        );
    }
}
```

**In header**:
```cpp
UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abilities")
TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;
```

## Activating Abilities

### By Class

```cpp
AbilitySystemComponent->TryActivateAbilityByClass(AbilityClass);
```

### By Tag

```cpp
FGameplayTagContainer TagContainer;
TagContainer.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability.Attack.Melee")));
AbilitySystemComponent->TryActivateAbilitiesByTag(TagContainer);
```

### From Input

```cpp
// Bind ability to input
AbilitySystemComponent->BindAbilityActivationToInputComponent(
    InputComponent,
    FGameplayAbilityInputBinds(
        "ConfirmInput",
        "CancelInput",
        "EAbilityInputID"  // Your input enum
    )
);

// Trigger via input ID
void AMyCharacter::OnAbilityInputPressed(int32 InputID)
{
    AbilitySystemComponent->AbilityLocalInputPressed(InputID);
}
```

## Gameplay Effects

### Creating a Gameplay Effect

**Blueprint/Data Asset** (most common):
1. Right-click in Content Browser
2. Blueprint Class → GameplayEffect
3. Configure:
   - Duration Policy: Instant, Duration, Infinite
   - Modifiers: Which attributes to modify
   - Magnitude: How much to modify

**C++ class** (for complex logic):
```cpp
UCLASS()
class UGE_DamageEffect : public UGameplayEffect
{
    GENERATED_BODY()

public:
    UGE_DamageEffect();
};
```

### Applying Gameplay Effects

```cpp
// Create effect context
FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
EffectContext.AddSourceObject(this);

// Create effect spec
FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(
    DamageEffectClass,
    1, // Level
    EffectContext
);

if (SpecHandle.IsValid())
{
    // Apply to target
    FActiveGameplayEffectHandle ActiveHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToTarget(
        *SpecHandle.Data.Get(),
        TargetAbilitySystemComponent
    );
}
```

## Gameplay Tags

### Setup Gameplay Tags

**Config/DefaultGameplayTags.ini**:
```ini
[/Script/GameplayTags.GameplayTagsSettings]
+GameplayTagList=(Tag="Ability.Attack.Melee",DevComment="Melee attack ability")
+GameplayTagList=(Tag="Ability.Attack.Ranged",DevComment="Ranged attack ability")
+GameplayTagList=(Tag="Status.Stunned",DevComment="Character is stunned")
+GameplayTagList=(Tag="Status.Dead",DevComment="Character is dead")
```

### Using Tags in Abilities

```cpp
// In ability class constructor
AbilityTags.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability.Attack.Melee")));
ActivationOwnedTags.AddTag(FGameplayTag::RequestGameplayTag(FName("Status.Attacking")));
BlockAbilitiesWithTag.AddTag(FGameplayTag::RequestGameplayTag(FName("Status.Stunned")));
```

### Tag Queries

```cpp
// Check if ASC has tag
bool bHasTag = AbilitySystemComponent->HasMatchingGameplayTag(
    FGameplayTag::RequestGameplayTag(FName("Status.Stunned"))
);

// Add/remove tags
FGameplayTagContainer TagsToAdd;
TagsToAdd.AddTag(FGameplayTag::RequestGameplayTag(FName("Status.Invincible")));
AbilitySystemComponent->AddLooseGameplayTags(TagsToAdd);

AbilitySystemComponent->RemoveLooseGameplayTag(
    FGameplayTag::RequestGameplayTag(FName("Status.Invincible"))
);
```

## Replication Modes

Set on ASC via `SetReplicationMode()`:

- **Full**: Replicates everything (expensive, for player characters in small games)
- **Mixed**: Replicates abilities, effects minimally (player characters in most games)
- **Minimal**: Only replicates gameplay tags (AI, NPCs, simulated proxies)

```cpp
AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
```

## Common Patterns

### Damage System

```cpp
// Attacker applies damage effect to target
void DealDamage(AActor* Target, float DamageAmount)
{
    if (IAbilitySystemInterface* ASI = Cast<IAbilitySystemInterface>(Target))
    {
        UAbilitySystemComponent* TargetASC = ASI->GetAbilitySystemComponent();
        
        FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
        EffectContext.AddSourceObject(this);
        
        FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(
            DamageEffectClass,
            1,
            EffectContext
        );
        
        if (SpecHandle.IsValid())
        {
            // Set damage magnitude
            SpecHandle.Data.Get()->SetSetByCallerMagnitude(
                FGameplayTag::RequestGameplayTag(FName("Data.Damage")),
                DamageAmount
            );
            
            AbilitySystemComponent->ApplyGameplayEffectSpecToTarget(
                *SpecHandle.Data.Get(),
                TargetASC
            );
        }
    }
}
```

### Cooldowns

Use `UGameplayAbility::ApplyCooldown()` or set cooldown gameplay effect in ability:

```cpp
// In ability class
UPROPERTY(EditDefaultsOnly, Category = "Cooldown")
FScalableFloat CooldownDuration = 5.0f;

UPROPERTY(EditDefaultsOnly, Category = "Cooldown")
FGameplayTagContainer CooldownTags;
```

### Costs (Mana, Stamina)

Use `UGameplayAbility::ApplyCost()` or set cost gameplay effect:

```cpp
// In ability class
UPROPERTY(EditDefaultsOnly, Category = "Cost")
TSubclassOf<UGameplayEffect> CostGameplayEffectClass;
```

## Debugging GAS

### Console Commands

```
showdebug abilitysystem  // Show abilities, effects, tags, attributes
```

### Logging

```cpp
// Enable GAS logging
LogAbilitySystem.SetVerbosity(ELogVerbosity::VeryVerbose);
```

## Best Practices

1. **Authority checks**: GAS only works on server. Check `HasAuthority()` before granting/activating
2. **Init ASC early**: Call `InitAbilityActorInfo` in `PossessedBy` and `OnRep_PlayerState`
3. **Use tags liberally**: Tags are lightweight and powerful for blocking/allowing abilities
4. **Attribute clamping**: Clamp in `PreAttributeChange` and `PostGameplayEffectExecute`
5. **Replication mode**: Use Minimal for AI/NPCs, Mixed for players
6. **Owner vs Avatar**: Understand difference (Owner has ASC, Avatar is controlled actor)

## Example Projects

- **Lyra** (Epic Games) - Full GAS implementation in action game
- **ActionRPG** (Epic Games) - Simplified GAS for RPG
- **GASDocumentation** (tranek on GitHub) - Comprehensive community documentation
- **Valley of the Ancient** (Epic Games) - Advanced GAS usage

## Common Issues

**Ability not activating**:
- Check authority (server-only)
- Verify `CommitAbility()` succeeds (costs, cooldowns, tags)
- Ensure ASC is initialized

**Attributes not replicating**:
- Add `DOREPLIFETIME_CONDITION_NOTIFY` in `GetLifetimeReplicatedProps`
- Implement OnRep functions
- Set ASC replication mode

**Tags not working**:
- Initialize tags in GameplayTags.ini
- Grant tags via effects or ASC methods
- Check tag queries use correct hierarchical names
