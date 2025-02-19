#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: STRUCT_LootTableEntry

#include "Basic.hpp"


namespace SDK
{

// UserDefinedStruct STRUCT_LootTableEntry.STRUCT_LootTableEntry
// 0x0040 (0x0040 - 0x0000)
struct FSTRUCT_LootTableEntry final
{
public:
	TSoftClassPtr<class UClass>                   ItemClass_48_D48145164AEB0AD4B9AF8B9991A4C56D;     // 0x0000(0x0028)(Edit, BlueprintVisible, HasGetValueTypeHash)
	class UDataTable*                             DataTable_36_4858BCE44D6D6A57312A9D92AE7D11A2;     // 0x0028(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Count_51_7C7EB75444B47F43D12EF0AE7A51C02B;         // 0x0030(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Weight_37_182A86A8456189C5C5F9388D213C9EED;        // 0x0034(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Unique_33_774C6D994D675AD1CFD98FAE5219E150;        // 0x0038(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(FSTRUCT_LootTableEntry) == 0x000008, "Wrong alignment on FSTRUCT_LootTableEntry");
static_assert(sizeof(FSTRUCT_LootTableEntry) == 0x000040, "Wrong size on FSTRUCT_LootTableEntry");
static_assert(offsetof(FSTRUCT_LootTableEntry, ItemClass_48_D48145164AEB0AD4B9AF8B9991A4C56D) == 0x000000, "Member 'FSTRUCT_LootTableEntry::ItemClass_48_D48145164AEB0AD4B9AF8B9991A4C56D' has a wrong offset!");
static_assert(offsetof(FSTRUCT_LootTableEntry, DataTable_36_4858BCE44D6D6A57312A9D92AE7D11A2) == 0x000028, "Member 'FSTRUCT_LootTableEntry::DataTable_36_4858BCE44D6D6A57312A9D92AE7D11A2' has a wrong offset!");
static_assert(offsetof(FSTRUCT_LootTableEntry, Count_51_7C7EB75444B47F43D12EF0AE7A51C02B) == 0x000030, "Member 'FSTRUCT_LootTableEntry::Count_51_7C7EB75444B47F43D12EF0AE7A51C02B' has a wrong offset!");
static_assert(offsetof(FSTRUCT_LootTableEntry, Weight_37_182A86A8456189C5C5F9388D213C9EED) == 0x000034, "Member 'FSTRUCT_LootTableEntry::Weight_37_182A86A8456189C5C5F9388D213C9EED' has a wrong offset!");
static_assert(offsetof(FSTRUCT_LootTableEntry, Unique_33_774C6D994D675AD1CFD98FAE5219E150) == 0x000038, "Member 'FSTRUCT_LootTableEntry::Unique_33_774C6D994D675AD1CFD98FAE5219E150' has a wrong offset!");

}

