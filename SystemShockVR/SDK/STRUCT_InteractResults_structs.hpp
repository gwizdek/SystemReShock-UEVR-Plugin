#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: STRUCT_InteractResults

#include "Basic.hpp"

#include "ENUM_InteractResultType_structs.hpp"


namespace SDK
{

// UserDefinedStruct STRUCT_InteractResults.STRUCT_InteractResults
// 0x0020 (0x0020 - 0x0000)
struct FSTRUCT_InteractResults final
{
public:
	ENUM_InteractResultType                       ResultType_2_4ACBC7E247FAD1F3FEE47CA65AD98BD3;     // 0x0000(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_1[0x7];                                        // 0x0001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   ResultText_5_F6EF434741F94D3B8DBB91A530CD454B;     // 0x0008(0x0018)(Edit, BlueprintVisible)
};
static_assert(alignof(FSTRUCT_InteractResults) == 0x000008, "Wrong alignment on FSTRUCT_InteractResults");
static_assert(sizeof(FSTRUCT_InteractResults) == 0x000020, "Wrong size on FSTRUCT_InteractResults");
static_assert(offsetof(FSTRUCT_InteractResults, ResultType_2_4ACBC7E247FAD1F3FEE47CA65AD98BD3) == 0x000000, "Member 'FSTRUCT_InteractResults::ResultType_2_4ACBC7E247FAD1F3FEE47CA65AD98BD3' has a wrong offset!");
static_assert(offsetof(FSTRUCT_InteractResults, ResultText_5_F6EF434741F94D3B8DBB91A530CD454B) == 0x000008, "Member 'FSTRUCT_InteractResults::ResultText_5_F6EF434741F94D3B8DBB91A530CD454B' has a wrong offset!");

}

