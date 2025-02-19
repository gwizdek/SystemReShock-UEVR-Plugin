#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: COMP_LootableInventory

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "STRUCT_ReferencedLootTable_structs.hpp"
#include "COMP_Inventory_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass COMP_LootableInventory.COMP_LootableInventory_C
// 0x0040 (0x0148 - 0x0108)
class UCOMP_LootableInventory_C final : public UCOMP_Inventory_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0108(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	TArray<struct FSTRUCT_ReferencedLootTable>    LootTables;                                        // 0x0110(0x0010)(Edit, BlueprintVisible)
	bool                                          CustomLootVisibility;                              // 0x0120(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          LootVisibilityState;                               // 0x0121(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          GeneratedLoot;                                     // 0x0122(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor)
	bool                                          GrantedDefaultLoadout;                             // 0x0123(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor)
	bool                                          HasInitializedLootInventory;                       // 0x0124(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          ClampToCompartment;                                // 0x0125(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_126[0x2];                                      // 0x0126(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	class UBoxComponent*                          SpawnVolume;                                       // 0x0128(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	FMulticastInlineDelegateProperty_             OnLootInventoryInitialized;                        // 0x0130(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	class UShapeComponent*                        CompartmentVolume;                                 // 0x0140(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void OnLootInventoryInitialized__DelegateSignature();
	void ExecuteUbergraph_COMP_LootableInventory(int32 EntryPoint);
	void ReceiveBeginPlay();
	void HasGeneratedLoot(bool* Result);
	void IsLootInventoryEmpty(bool* Result);
	void GetLootItemRotation(class UITEM_Base_C* LootItem, class UInventoryBag_C* LootBag, class APICKUP_Base_C* LootPickup, struct FRotator* Rotation);
	void TryInitializeLootInventory();
	void TryGenerateLoot();
	void BindLootBagEvents();
	void TryBindCompartmentEvents();
	void TrySetLootVisibility(bool VisibilityState, bool* Result);
	void ForceSetLootVisibility(bool VisibilityState);
	void ForceUpdatePickupVisibility(class APICKUP_Base_C* PickupActor);
	void TrySpawnPickupItem(class UITEM_Base_C* LootItem, class UInventoryBag_C* LootBag, class APICKUP_Base_C** PickupItem);
	void EVENT_OnBagLootChanged(class UInventoryBag_C* Bag, int32 SlotIndex);
	void TrySpawnPickupItems();
	void OpenLootWindow(class APAWN_Hacker_Implant_C* Hacker, class UPrimitiveComponent* CursorPrimitive);
	void CloseLootWindow();
	void EVENT_OnBeginCompartmentOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const struct FHitResult& SweepResult);
	void InitializeInventory(bool GrantDefaultInventory);
	void ShouldCreateLinkedPickups(bool* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"COMP_LootableInventory_C">();
	}
	static class UCOMP_LootableInventory_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCOMP_LootableInventory_C>();
	}
};
static_assert(alignof(UCOMP_LootableInventory_C) == 0x000008, "Wrong alignment on UCOMP_LootableInventory_C");
static_assert(sizeof(UCOMP_LootableInventory_C) == 0x000148, "Wrong size on UCOMP_LootableInventory_C");
static_assert(offsetof(UCOMP_LootableInventory_C, UberGraphFrame) == 0x000108, "Member 'UCOMP_LootableInventory_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UCOMP_LootableInventory_C, LootTables) == 0x000110, "Member 'UCOMP_LootableInventory_C::LootTables' has a wrong offset!");
static_assert(offsetof(UCOMP_LootableInventory_C, CustomLootVisibility) == 0x000120, "Member 'UCOMP_LootableInventory_C::CustomLootVisibility' has a wrong offset!");
static_assert(offsetof(UCOMP_LootableInventory_C, LootVisibilityState) == 0x000121, "Member 'UCOMP_LootableInventory_C::LootVisibilityState' has a wrong offset!");
static_assert(offsetof(UCOMP_LootableInventory_C, GeneratedLoot) == 0x000122, "Member 'UCOMP_LootableInventory_C::GeneratedLoot' has a wrong offset!");
static_assert(offsetof(UCOMP_LootableInventory_C, GrantedDefaultLoadout) == 0x000123, "Member 'UCOMP_LootableInventory_C::GrantedDefaultLoadout' has a wrong offset!");
static_assert(offsetof(UCOMP_LootableInventory_C, HasInitializedLootInventory) == 0x000124, "Member 'UCOMP_LootableInventory_C::HasInitializedLootInventory' has a wrong offset!");
static_assert(offsetof(UCOMP_LootableInventory_C, ClampToCompartment) == 0x000125, "Member 'UCOMP_LootableInventory_C::ClampToCompartment' has a wrong offset!");
static_assert(offsetof(UCOMP_LootableInventory_C, SpawnVolume) == 0x000128, "Member 'UCOMP_LootableInventory_C::SpawnVolume' has a wrong offset!");
static_assert(offsetof(UCOMP_LootableInventory_C, OnLootInventoryInitialized) == 0x000130, "Member 'UCOMP_LootableInventory_C::OnLootInventoryInitialized' has a wrong offset!");
static_assert(offsetof(UCOMP_LootableInventory_C, CompartmentVolume) == 0x000140, "Member 'UCOMP_LootableInventory_C::CompartmentVolume' has a wrong offset!");

}

