# Enhanced Input System Reference

## Overview

Enhanced Input is UE5's data-driven input system that replaces the legacy input system. Load this reference when working with input binding, mapping contexts, or input actions.

## Core Concepts

### Input Actions (UInputAction)

Data assets that represent logical player actions like "Jump", "Move", or "Shoot".

**Value Types**:
- `Digital (bool)` - Simple button press (e.g., Jump)
- `Axis1D (float)` - Single axis (e.g., Throttle: -1.0 to 1.0)
- `Axis2D (FVector2D)` - Two axes (e.g., Movement: X=strafe, Y=forward)
- `Axis3D (FVector)` - Three axes (e.g., Flying: X, Y, Z)

**Creating in C++**:
```cpp
// In header
UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
TObjectPtr<UInputAction> MoveAction;

UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
TObjectPtr<UInputAction> JumpAction;
```

### Input Mapping Contexts (UInputMappingContext)

Containers that map physical inputs (keys, buttons) to Input Actions. Multiple contexts can be active simultaneously with different priorities.

**Adding contexts at runtime**:
```cpp
#include "EnhancedInputSubsystems.h"

void AMyCharacter::BeginPlay()
{
    Super::BeginPlay();
    
    if (APlayerController* PC = Cast<APlayerController>(GetController()))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = 
            ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
        {
            // Add mapping context with priority (higher = more important)
            Subsystem->AddMappingContext(DefaultMappingContext, 0);
        }
    }
}
```

**Removing contexts**:
```cpp
Subsystem->RemoveMappingContext(MappingContextToRemove);
```

## Binding Input Actions

### In Character/Pawn Class

```cpp
#include "EnhancedInputComponent.h"

void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    
    if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        // Bind to member functions
        EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyCharacter::Move);
        EnhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this, &AMyCharacter::Jump);
        EnhancedInput->BindAction(JumpAction, ETriggerEvent::Completed, this, &AMyCharacter::StopJumping);
    }
}
```

### Callback Function Signatures

**For different value types**:

```cpp
// Digital (bool) - receives FInputActionValue
void Jump(const FInputActionValue& Value);

// Axis1D (float)
void Accelerate(const FInputActionValue& Value);

// Axis2D (FVector2D)
void Move(const FInputActionValue& Value);

// Axis3D (FVector)
void Fly(const FInputActionValue& Value);
```

**Extracting values**:
```cpp
void AMyCharacter::Move(const FInputActionValue& Value)
{
    // For Axis2D
    const FVector2D MovementVector = Value.Get<FVector2D>();
    
    // For Digital/bool
    const bool bIsPressed = Value.Get<bool>();
    
    // For Axis1D
    const float AxisValue = Value.Get<float>();
}
```

## Trigger Events

When binding actions, specify when the callback fires:

- `ETriggerEvent::Started` - Input just started (initial press)
- `ETriggerEvent::Ongoing` - Input is actively held/moved
- `ETriggerEvent::Triggered` - Input meets trigger conditions (most common)
- `ETriggerEvent::Canceled` - Input was interrupted
- `ETriggerEvent::Completed` - Input finished (button released)

**Common usage patterns**:
```cpp
// Button press - fire once
EnhancedInput->BindAction(InteractAction, ETriggerEvent::Started, this, &AMyCharacter::Interact);

// Continuous input - fire every frame while held
EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyCharacter::Move);

// Button release
EnhancedInput->BindAction(JumpAction, ETriggerEvent::Completed, this, &AMyCharacter::StopJumping);
```

## Input Modifiers

Modify raw input values before they reach your code. Applied in the Input Mapping Context editor.

**Common modifiers**:
- `Negate` - Invert the input value
- `Dead Zone` - Create dead zones for analog sticks
- `Scalar` - Multiply input by a value
- `Smooth` - Smooth out input over time
- `Response Curve` - Apply custom response curves

## Input Triggers

Determine when an action fires. Applied in the Input Mapping Context editor.

**Common triggers**:
- `Pressed` - Fire once on initial press
- `Released` - Fire once on release
- `Hold` - Require holding for duration
- `Tap` - Quick press and release
- `Chord` - Require multiple inputs simultaneously

## Common Patterns

### Movement with Enhanced Input

```cpp
// Header
UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
TObjectPtr<UInputAction> MoveAction;

UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
TObjectPtr<UInputAction> LookAction;

// Implementation
void AMyCharacter::Move(const FInputActionValue& Value)
{
    const FVector2D MovementVector = Value.Get<FVector2D>();
    
    if (Controller != nullptr)
    {
        // Forward/backward movement
        AddMovementInput(GetActorForwardVector(), MovementVector.Y);
        
        // Left/right movement
        AddMovementInput(GetActorRightVector(), MovementVector.X);
    }
}

void AMyCharacter::Look(const FInputActionValue& Value)
{
    const FVector2D LookAxisVector = Value.Get<FVector2D>();
    
    if (Controller != nullptr)
    {
        AddControllerYawInput(LookAxisVector.X);
        AddControllerPitchInput(LookAxisVector.Y);
    }
}
```

### Jump with Enhanced Input

```cpp
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    
    if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        // Jump when button pressed, stop jumping when released
        EnhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
        EnhancedInput->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
    }
}
```

### Conditional Context Switching

```cpp
void AMyCharacter::EnterAimingMode()
{
    if (UEnhancedInputLocalPlayerSubsystem* Subsystem = GetInputSubsystem())
    {
        // Remove default context
        Subsystem->RemoveMappingContext(DefaultMappingContext);
        
        // Add aiming context (different key bindings)
        Subsystem->AddMappingContext(AimingMappingContext, 1); // Higher priority
    }
}

void AMyCharacter::ExitAimingMode()
{
    if (UEnhancedInputLocalPlayerSubsystem* Subsystem = GetInputSubsystem())
    {
        Subsystem->RemoveMappingContext(AimingMappingContext);
        Subsystem->AddMappingContext(DefaultMappingContext, 0);
    }
}
```

## Debugging Enhanced Input

### Console Commands

```
showdebug enhancedinput  // Show active contexts and triggered actions
```

### Common Issues

**Input not working**:
1. Check mapping context is added in BeginPlay
2. Verify Input Actions are assigned in Blueprint/Details panel
3. Ensure Enhanced Input plugin is enabled
4. Check that UEnhancedInputComponent is used (not base UInputComponent)

**Wrong trigger firing**:
- Review ETriggerEvent type (Started vs Triggered vs Completed)
- Check Input Triggers in the Mapping Context

## Asset Naming Conventions

**Common patterns** (verify with project):
- Input Actions: `IA_ActionName` (e.g., `IA_Jump`, `IA_Move`)
- Mapping Contexts: `IMC_ContextName` (e.g., `IMC_Default`, `IMC_Vehicle`)

**Always discover actual names**:
```bash
find Content -name "IA_*.uasset"
find Content -name "IMC_*.uasset"
```

## Required Module Dependencies

In `YourProject.Build.cs`:

```csharp
PublicDependencyModuleNames.AddRange(new string[] {
    "Core", 
    "CoreUObject", 
    "Engine", 
    "InputCore",
    "EnhancedInput"  // ← Required
});
```

## Migration from Legacy Input

**Legacy system**:
```cpp
// Old way (UE4)
PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
```

**Enhanced Input**:
```cpp
// New way (UE5)
if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
{
    EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyCharacter::Move);
}
```
