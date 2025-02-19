#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: COMP_Descriptor

#include "Basic.hpp"

#include "STRUCT_TaggedDescription_structs.hpp"
#include "STRUCT_InteractFlavorText_structs.hpp"


namespace SDK::Params
{

// Function COMP_Descriptor.COMP_Descriptor_C.TryGenerateFlavorText
// 0x0002 (0x0002 - 0x0000)
struct COMP_Descriptor_C_TryGenerateFlavorText final
{
public:
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0000(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Not_PreBool_ReturnValue;                  // 0x0001(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(COMP_Descriptor_C_TryGenerateFlavorText) == 0x000001, "Wrong alignment on COMP_Descriptor_C_TryGenerateFlavorText");
static_assert(sizeof(COMP_Descriptor_C_TryGenerateFlavorText) == 0x000002, "Wrong size on COMP_Descriptor_C_TryGenerateFlavorText");
static_assert(offsetof(COMP_Descriptor_C_TryGenerateFlavorText, CallFunc_IsValid_ReturnValue) == 0x000000, "Member 'COMP_Descriptor_C_TryGenerateFlavorText::CallFunc_IsValid_ReturnValue' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_TryGenerateFlavorText, CallFunc_Not_PreBool_ReturnValue) == 0x000001, "Member 'COMP_Descriptor_C_TryGenerateFlavorText::CallFunc_Not_PreBool_ReturnValue' has a wrong offset!");

// Function COMP_Descriptor.COMP_Descriptor_C.RegenerateFlavorText
// 0x0060 (0x0060 - 0x0000)
struct COMP_Descriptor_C_RegenerateFlavorText final
{
public:
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x0000(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UShuffler*                              CallFunc_SpawnObject_ReturnValue;                  // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FSTRUCT_InteractFlavorText             CallFunc_GetDataTableRowFromName_OutRow;           // 0x0010(0x0020)(HasGetValueTypeHash)
	bool                                          CallFunc_GetDataTableRowFromName_ReturnValue;      // 0x0030(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_31[0x7];                                       // 0x0031(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSTRUCT_InteractFlavorText             CallFunc_GetDataTableRowFromName_OutRow_1;         // 0x0038(0x0020)(HasGetValueTypeHash)
	bool                                          CallFunc_GetDataTableRowFromName_ReturnValue_1;    // 0x0058(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0059(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(COMP_Descriptor_C_RegenerateFlavorText) == 0x000008, "Wrong alignment on COMP_Descriptor_C_RegenerateFlavorText");
static_assert(sizeof(COMP_Descriptor_C_RegenerateFlavorText) == 0x000060, "Wrong size on COMP_Descriptor_C_RegenerateFlavorText");
static_assert(offsetof(COMP_Descriptor_C_RegenerateFlavorText, CallFunc_Array_Length_ReturnValue) == 0x000000, "Member 'COMP_Descriptor_C_RegenerateFlavorText::CallFunc_Array_Length_ReturnValue' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_RegenerateFlavorText, CallFunc_SpawnObject_ReturnValue) == 0x000008, "Member 'COMP_Descriptor_C_RegenerateFlavorText::CallFunc_SpawnObject_ReturnValue' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_RegenerateFlavorText, CallFunc_GetDataTableRowFromName_OutRow) == 0x000010, "Member 'COMP_Descriptor_C_RegenerateFlavorText::CallFunc_GetDataTableRowFromName_OutRow' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_RegenerateFlavorText, CallFunc_GetDataTableRowFromName_ReturnValue) == 0x000030, "Member 'COMP_Descriptor_C_RegenerateFlavorText::CallFunc_GetDataTableRowFromName_ReturnValue' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_RegenerateFlavorText, CallFunc_GetDataTableRowFromName_OutRow_1) == 0x000038, "Member 'COMP_Descriptor_C_RegenerateFlavorText::CallFunc_GetDataTableRowFromName_OutRow_1' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_RegenerateFlavorText, CallFunc_GetDataTableRowFromName_ReturnValue_1) == 0x000058, "Member 'COMP_Descriptor_C_RegenerateFlavorText::CallFunc_GetDataTableRowFromName_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_RegenerateFlavorText, CallFunc_IsValid_ReturnValue) == 0x000059, "Member 'COMP_Descriptor_C_RegenerateFlavorText::CallFunc_IsValid_ReturnValue' has a wrong offset!");

// Function COMP_Descriptor.COMP_Descriptor_C.GetPrimitiveDescriptionMessage
// 0x0078 (0x0078 - 0x0000)
struct COMP_Descriptor_C_GetPrimitiveDescriptionMessage final
{
public:
	class UPrimitiveComponent*                    Primitive;                                         // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0008(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_9[0x7];                                        // 0x0009(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   Message;                                           // 0x0010(0x0018)(Parm, OutParm)
	class FName                                   ComponentTagToFind;                                // 0x0028(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Array_Index_Variable;                     // 0x0030(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   CallFunc_Array_Get_Item;                           // 0x0034(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x003C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable;                    // 0x0040(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Greater_IntInt_ReturnValue;               // 0x0044(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_45[0x3];                                       // 0x0045(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x0048(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_Length_ReturnValue_1;               // 0x004C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FSTRUCT_TaggedDescription              CallFunc_Array_Get_Item_1;                         // 0x0050(0x0020)(ContainsInstancedReference, HasGetValueTypeHash)
	bool                                          CallFunc_Less_IntInt_ReturnValue;                  // 0x0070(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_EqualEqual_NameName_ReturnValue;          // 0x0071(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(COMP_Descriptor_C_GetPrimitiveDescriptionMessage) == 0x000008, "Wrong alignment on COMP_Descriptor_C_GetPrimitiveDescriptionMessage");
static_assert(sizeof(COMP_Descriptor_C_GetPrimitiveDescriptionMessage) == 0x000078, "Wrong size on COMP_Descriptor_C_GetPrimitiveDescriptionMessage");
static_assert(offsetof(COMP_Descriptor_C_GetPrimitiveDescriptionMessage, Primitive) == 0x000000, "Member 'COMP_Descriptor_C_GetPrimitiveDescriptionMessage::Primitive' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_GetPrimitiveDescriptionMessage, Result) == 0x000008, "Member 'COMP_Descriptor_C_GetPrimitiveDescriptionMessage::Result' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_GetPrimitiveDescriptionMessage, Message) == 0x000010, "Member 'COMP_Descriptor_C_GetPrimitiveDescriptionMessage::Message' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_GetPrimitiveDescriptionMessage, ComponentTagToFind) == 0x000028, "Member 'COMP_Descriptor_C_GetPrimitiveDescriptionMessage::ComponentTagToFind' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_GetPrimitiveDescriptionMessage, Temp_int_Array_Index_Variable) == 0x000030, "Member 'COMP_Descriptor_C_GetPrimitiveDescriptionMessage::Temp_int_Array_Index_Variable' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_GetPrimitiveDescriptionMessage, CallFunc_Array_Get_Item) == 0x000034, "Member 'COMP_Descriptor_C_GetPrimitiveDescriptionMessage::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_GetPrimitiveDescriptionMessage, CallFunc_Array_Length_ReturnValue) == 0x00003C, "Member 'COMP_Descriptor_C_GetPrimitiveDescriptionMessage::CallFunc_Array_Length_ReturnValue' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_GetPrimitiveDescriptionMessage, Temp_int_Loop_Counter_Variable) == 0x000040, "Member 'COMP_Descriptor_C_GetPrimitiveDescriptionMessage::Temp_int_Loop_Counter_Variable' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_GetPrimitiveDescriptionMessage, CallFunc_Greater_IntInt_ReturnValue) == 0x000044, "Member 'COMP_Descriptor_C_GetPrimitiveDescriptionMessage::CallFunc_Greater_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_GetPrimitiveDescriptionMessage, CallFunc_Add_IntInt_ReturnValue) == 0x000048, "Member 'COMP_Descriptor_C_GetPrimitiveDescriptionMessage::CallFunc_Add_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_GetPrimitiveDescriptionMessage, CallFunc_Array_Length_ReturnValue_1) == 0x00004C, "Member 'COMP_Descriptor_C_GetPrimitiveDescriptionMessage::CallFunc_Array_Length_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_GetPrimitiveDescriptionMessage, CallFunc_Array_Get_Item_1) == 0x000050, "Member 'COMP_Descriptor_C_GetPrimitiveDescriptionMessage::CallFunc_Array_Get_Item_1' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_GetPrimitiveDescriptionMessage, CallFunc_Less_IntInt_ReturnValue) == 0x000070, "Member 'COMP_Descriptor_C_GetPrimitiveDescriptionMessage::CallFunc_Less_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_GetPrimitiveDescriptionMessage, CallFunc_EqualEqual_NameName_ReturnValue) == 0x000071, "Member 'COMP_Descriptor_C_GetPrimitiveDescriptionMessage::CallFunc_EqualEqual_NameName_ReturnValue' has a wrong offset!");

// Function COMP_Descriptor.COMP_Descriptor_C.SetDescriptionMessage
// 0x0018 (0x0018 - 0x0000)
struct COMP_Descriptor_C_SetDescriptionMessage final
{
public:
	class FText                                   Text;                                              // 0x0000(0x0018)(BlueprintVisible, BlueprintReadOnly, Parm)
};
static_assert(alignof(COMP_Descriptor_C_SetDescriptionMessage) == 0x000008, "Wrong alignment on COMP_Descriptor_C_SetDescriptionMessage");
static_assert(sizeof(COMP_Descriptor_C_SetDescriptionMessage) == 0x000018, "Wrong size on COMP_Descriptor_C_SetDescriptionMessage");
static_assert(offsetof(COMP_Descriptor_C_SetDescriptionMessage, Text) == 0x000000, "Member 'COMP_Descriptor_C_SetDescriptionMessage::Text' has a wrong offset!");

// Function COMP_Descriptor.COMP_Descriptor_C.SetFlavorFeedbackRowName
// 0x0008 (0x0008 - 0x0000)
struct COMP_Descriptor_C_SetFlavorFeedbackRowName final
{
public:
	class FName                                   RowName;                                           // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(COMP_Descriptor_C_SetFlavorFeedbackRowName) == 0x000004, "Wrong alignment on COMP_Descriptor_C_SetFlavorFeedbackRowName");
static_assert(sizeof(COMP_Descriptor_C_SetFlavorFeedbackRowName) == 0x000008, "Wrong size on COMP_Descriptor_C_SetFlavorFeedbackRowName");
static_assert(offsetof(COMP_Descriptor_C_SetFlavorFeedbackRowName, RowName) == 0x000000, "Member 'COMP_Descriptor_C_SetFlavorFeedbackRowName::RowName' has a wrong offset!");

// Function COMP_Descriptor.COMP_Descriptor_C.GetDescriptionMessage
// 0x0040 (0x0040 - 0x0000)
struct COMP_Descriptor_C_GetDescriptionMessage final
{
public:
	class UPrimitiveComponent*                    Primitive;                                         // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FText                                   Message;                                           // 0x0008(0x0018)(Parm, OutParm)
	bool                                          CallFunc_GetPrimitiveDescriptionMessage_Result;    // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_21[0x7];                                       // 0x0021(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CallFunc_GetPrimitiveDescriptionMessage_Message;   // 0x0028(0x0018)()
};
static_assert(alignof(COMP_Descriptor_C_GetDescriptionMessage) == 0x000008, "Wrong alignment on COMP_Descriptor_C_GetDescriptionMessage");
static_assert(sizeof(COMP_Descriptor_C_GetDescriptionMessage) == 0x000040, "Wrong size on COMP_Descriptor_C_GetDescriptionMessage");
static_assert(offsetof(COMP_Descriptor_C_GetDescriptionMessage, Primitive) == 0x000000, "Member 'COMP_Descriptor_C_GetDescriptionMessage::Primitive' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_GetDescriptionMessage, Message) == 0x000008, "Member 'COMP_Descriptor_C_GetDescriptionMessage::Message' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_GetDescriptionMessage, CallFunc_GetPrimitiveDescriptionMessage_Result) == 0x000020, "Member 'COMP_Descriptor_C_GetDescriptionMessage::CallFunc_GetPrimitiveDescriptionMessage_Result' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_GetDescriptionMessage, CallFunc_GetPrimitiveDescriptionMessage_Message) == 0x000028, "Member 'COMP_Descriptor_C_GetDescriptionMessage::CallFunc_GetPrimitiveDescriptionMessage_Message' has a wrong offset!");

// Function COMP_Descriptor.COMP_Descriptor_C.GetInteractFlavorMessage
// 0x0038 (0x0038 - 0x0000)
struct COMP_Descriptor_C_GetInteractFlavorMessage final
{
public:
	class FText                                   Message;                                           // 0x0000(0x0018)(Parm, OutParm)
	TArray<class FText>                           FeedbackText;                                      // 0x0018(0x0010)(Edit, BlueprintVisible)
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x0028(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Greater_IntInt_ReturnValue;               // 0x002C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2D[0x3];                                       // 0x002D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_GetNextIndex_ReturnValue;                 // 0x0030(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(COMP_Descriptor_C_GetInteractFlavorMessage) == 0x000008, "Wrong alignment on COMP_Descriptor_C_GetInteractFlavorMessage");
static_assert(sizeof(COMP_Descriptor_C_GetInteractFlavorMessage) == 0x000038, "Wrong size on COMP_Descriptor_C_GetInteractFlavorMessage");
static_assert(offsetof(COMP_Descriptor_C_GetInteractFlavorMessage, Message) == 0x000000, "Member 'COMP_Descriptor_C_GetInteractFlavorMessage::Message' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_GetInteractFlavorMessage, FeedbackText) == 0x000018, "Member 'COMP_Descriptor_C_GetInteractFlavorMessage::FeedbackText' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_GetInteractFlavorMessage, CallFunc_Array_Length_ReturnValue) == 0x000028, "Member 'COMP_Descriptor_C_GetInteractFlavorMessage::CallFunc_Array_Length_ReturnValue' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_GetInteractFlavorMessage, CallFunc_Greater_IntInt_ReturnValue) == 0x00002C, "Member 'COMP_Descriptor_C_GetInteractFlavorMessage::CallFunc_Greater_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(COMP_Descriptor_C_GetInteractFlavorMessage, CallFunc_GetNextIndex_ReturnValue) == 0x000030, "Member 'COMP_Descriptor_C_GetInteractFlavorMessage::CallFunc_GetNextIndex_ReturnValue' has a wrong offset!");

}

