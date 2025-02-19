#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_Automap_DeckList

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"


namespace SDK::Params
{

// Function WIDGET_Automap_DeckList.WIDGET_Automap_DeckList_C.ExecuteUbergraph_WIDGET_Automap_DeckList
// 0x0040 (0x0040 - 0x0000)
struct WIDGET_Automap_DeckList_C_ExecuteUbergraph_WIDGET_Automap_DeckList final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Array_Index_Variable;                     // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable;                    // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x000C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FColor                                 CallFunc_GetMeshUIColor_Color;                     // 0x0010(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_14[0x4];                                       // 0x0014(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class UWIDGET_Automap_DeckElement_C*>  K2Node_MakeArray_Array;                            // 0x0018(0x0010)(ReferenceParm, ContainsInstancedReference)
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x0028(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2C[0x4];                                       // 0x002C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UWIDGET_Automap_DeckElement_C*          CallFunc_Array_Get_Item;                           // 0x0030(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Less_IntInt_ReturnValue;                  // 0x0038(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(WIDGET_Automap_DeckList_C_ExecuteUbergraph_WIDGET_Automap_DeckList) == 0x000008, "Wrong alignment on WIDGET_Automap_DeckList_C_ExecuteUbergraph_WIDGET_Automap_DeckList");
static_assert(sizeof(WIDGET_Automap_DeckList_C_ExecuteUbergraph_WIDGET_Automap_DeckList) == 0x000040, "Wrong size on WIDGET_Automap_DeckList_C_ExecuteUbergraph_WIDGET_Automap_DeckList");
static_assert(offsetof(WIDGET_Automap_DeckList_C_ExecuteUbergraph_WIDGET_Automap_DeckList, EntryPoint) == 0x000000, "Member 'WIDGET_Automap_DeckList_C_ExecuteUbergraph_WIDGET_Automap_DeckList::EntryPoint' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_ExecuteUbergraph_WIDGET_Automap_DeckList, Temp_int_Array_Index_Variable) == 0x000004, "Member 'WIDGET_Automap_DeckList_C_ExecuteUbergraph_WIDGET_Automap_DeckList::Temp_int_Array_Index_Variable' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_ExecuteUbergraph_WIDGET_Automap_DeckList, Temp_int_Loop_Counter_Variable) == 0x000008, "Member 'WIDGET_Automap_DeckList_C_ExecuteUbergraph_WIDGET_Automap_DeckList::Temp_int_Loop_Counter_Variable' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_ExecuteUbergraph_WIDGET_Automap_DeckList, CallFunc_Add_IntInt_ReturnValue) == 0x00000C, "Member 'WIDGET_Automap_DeckList_C_ExecuteUbergraph_WIDGET_Automap_DeckList::CallFunc_Add_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_ExecuteUbergraph_WIDGET_Automap_DeckList, CallFunc_GetMeshUIColor_Color) == 0x000010, "Member 'WIDGET_Automap_DeckList_C_ExecuteUbergraph_WIDGET_Automap_DeckList::CallFunc_GetMeshUIColor_Color' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_ExecuteUbergraph_WIDGET_Automap_DeckList, K2Node_MakeArray_Array) == 0x000018, "Member 'WIDGET_Automap_DeckList_C_ExecuteUbergraph_WIDGET_Automap_DeckList::K2Node_MakeArray_Array' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_ExecuteUbergraph_WIDGET_Automap_DeckList, CallFunc_Array_Length_ReturnValue) == 0x000028, "Member 'WIDGET_Automap_DeckList_C_ExecuteUbergraph_WIDGET_Automap_DeckList::CallFunc_Array_Length_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_ExecuteUbergraph_WIDGET_Automap_DeckList, CallFunc_Array_Get_Item) == 0x000030, "Member 'WIDGET_Automap_DeckList_C_ExecuteUbergraph_WIDGET_Automap_DeckList::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_ExecuteUbergraph_WIDGET_Automap_DeckList, CallFunc_Less_IntInt_ReturnValue) == 0x000038, "Member 'WIDGET_Automap_DeckList_C_ExecuteUbergraph_WIDGET_Automap_DeckList::CallFunc_Less_IntInt_ReturnValue' has a wrong offset!");

// Function WIDGET_Automap_DeckList.WIDGET_Automap_DeckList_C.SetDecksVisible
// 0x0068 (0x0068 - 0x0000)
struct WIDGET_Automap_DeckList_C_SetDecksVisible final
{
public:
	class FText                                   CurrentDeckSymbol;                                 // 0x0000(0x0018)(Edit, BlueprintVisible)
	class FName                                   CurrentLevelName;                                  // 0x0018(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<int32>                                 DecksToIncludeList;                                // 0x0020(0x0010)(Edit, BlueprintVisible)
	class FName                                   DeckNameToCheck;                                   // 0x0030(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         DeckToCheck;                                       // 0x0038(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_3C[0x4];                                       // 0x003C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UGI_SinglePlayer_C*                     GameInstance;                                      // 0x0040(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash)
	class UGameInstance*                          CallFunc_GetGameInstance_ReturnValue;              // 0x0048(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   CallFunc_GetCurrentLevelName_Result;               // 0x0050(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UGI_SinglePlayer_C*                     K2Node_DynamicCast_AsGI_Single_Player;             // 0x0058(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0060(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(WIDGET_Automap_DeckList_C_SetDecksVisible) == 0x000008, "Wrong alignment on WIDGET_Automap_DeckList_C_SetDecksVisible");
static_assert(sizeof(WIDGET_Automap_DeckList_C_SetDecksVisible) == 0x000068, "Wrong size on WIDGET_Automap_DeckList_C_SetDecksVisible");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetDecksVisible, CurrentDeckSymbol) == 0x000000, "Member 'WIDGET_Automap_DeckList_C_SetDecksVisible::CurrentDeckSymbol' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetDecksVisible, CurrentLevelName) == 0x000018, "Member 'WIDGET_Automap_DeckList_C_SetDecksVisible::CurrentLevelName' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetDecksVisible, DecksToIncludeList) == 0x000020, "Member 'WIDGET_Automap_DeckList_C_SetDecksVisible::DecksToIncludeList' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetDecksVisible, DeckNameToCheck) == 0x000030, "Member 'WIDGET_Automap_DeckList_C_SetDecksVisible::DeckNameToCheck' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetDecksVisible, DeckToCheck) == 0x000038, "Member 'WIDGET_Automap_DeckList_C_SetDecksVisible::DeckToCheck' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetDecksVisible, GameInstance) == 0x000040, "Member 'WIDGET_Automap_DeckList_C_SetDecksVisible::GameInstance' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetDecksVisible, CallFunc_GetGameInstance_ReturnValue) == 0x000048, "Member 'WIDGET_Automap_DeckList_C_SetDecksVisible::CallFunc_GetGameInstance_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetDecksVisible, CallFunc_GetCurrentLevelName_Result) == 0x000050, "Member 'WIDGET_Automap_DeckList_C_SetDecksVisible::CallFunc_GetCurrentLevelName_Result' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetDecksVisible, K2Node_DynamicCast_AsGI_Single_Player) == 0x000058, "Member 'WIDGET_Automap_DeckList_C_SetDecksVisible::K2Node_DynamicCast_AsGI_Single_Player' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetDecksVisible, K2Node_DynamicCast_bSuccess) == 0x000060, "Member 'WIDGET_Automap_DeckList_C_SetDecksVisible::K2Node_DynamicCast_bSuccess' has a wrong offset!");

// Function WIDGET_Automap_DeckList.WIDGET_Automap_DeckList_C.DeckHasBecomeSelected
// 0x0008 (0x0008 - 0x0000)
struct WIDGET_Automap_DeckList_C_DeckHasBecomeSelected final
{
public:
	class UWIDGET_Automap_DeckElement_C*          DeckElement;                                       // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WIDGET_Automap_DeckList_C_DeckHasBecomeSelected) == 0x000008, "Wrong alignment on WIDGET_Automap_DeckList_C_DeckHasBecomeSelected");
static_assert(sizeof(WIDGET_Automap_DeckList_C_DeckHasBecomeSelected) == 0x000008, "Wrong size on WIDGET_Automap_DeckList_C_DeckHasBecomeSelected");
static_assert(offsetof(WIDGET_Automap_DeckList_C_DeckHasBecomeSelected, DeckElement) == 0x000000, "Member 'WIDGET_Automap_DeckList_C_DeckHasBecomeSelected::DeckElement' has a wrong offset!");

// Function WIDGET_Automap_DeckList.WIDGET_Automap_DeckList_C.SelectDeckByDeckRow
// 0x0020 (0x0020 - 0x0000)
struct WIDGET_Automap_DeckList_C_SelectDeckByDeckRow final
{
public:
	class FName                                   DeckRow;                                           // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UWIDGET_Automap_DeckElement_C*          CallFunc_GetDeckElementByLevelName_DeckElement;    // 0x0008(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   CallFunc_GetDeckRowName_DeckRow;                   // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_EqualEqual_NameName_ReturnValue;          // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0019(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsValid_ReturnValue_1;                    // 0x001A(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(WIDGET_Automap_DeckList_C_SelectDeckByDeckRow) == 0x000008, "Wrong alignment on WIDGET_Automap_DeckList_C_SelectDeckByDeckRow");
static_assert(sizeof(WIDGET_Automap_DeckList_C_SelectDeckByDeckRow) == 0x000020, "Wrong size on WIDGET_Automap_DeckList_C_SelectDeckByDeckRow");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SelectDeckByDeckRow, DeckRow) == 0x000000, "Member 'WIDGET_Automap_DeckList_C_SelectDeckByDeckRow::DeckRow' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SelectDeckByDeckRow, CallFunc_GetDeckElementByLevelName_DeckElement) == 0x000008, "Member 'WIDGET_Automap_DeckList_C_SelectDeckByDeckRow::CallFunc_GetDeckElementByLevelName_DeckElement' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SelectDeckByDeckRow, CallFunc_GetDeckRowName_DeckRow) == 0x000010, "Member 'WIDGET_Automap_DeckList_C_SelectDeckByDeckRow::CallFunc_GetDeckRowName_DeckRow' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SelectDeckByDeckRow, CallFunc_EqualEqual_NameName_ReturnValue) == 0x000018, "Member 'WIDGET_Automap_DeckList_C_SelectDeckByDeckRow::CallFunc_EqualEqual_NameName_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SelectDeckByDeckRow, CallFunc_IsValid_ReturnValue) == 0x000019, "Member 'WIDGET_Automap_DeckList_C_SelectDeckByDeckRow::CallFunc_IsValid_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SelectDeckByDeckRow, CallFunc_IsValid_ReturnValue_1) == 0x00001A, "Member 'WIDGET_Automap_DeckList_C_SelectDeckByDeckRow::CallFunc_IsValid_ReturnValue_1' has a wrong offset!");

// Function WIDGET_Automap_DeckList.WIDGET_Automap_DeckList_C.GetDeckElementByLevelName
// 0x0038 (0x0038 - 0x0000)
struct WIDGET_Automap_DeckList_C_GetDeckElementByLevelName final
{
public:
	class FName                                   LevelName;                                         // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UWIDGET_Automap_DeckElement_C*          DeckElement;                                       // 0x0008(0x0008)(Parm, OutParm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Variable;                                 // 0x0010(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_14[0x4];                                       // 0x0014(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UGameInstance*                          CallFunc_GetGameInstance_ReturnValue;              // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UGI_SinglePlayer_C*                     K2Node_DynamicCast_AsGI_Single_Player;             // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_29[0x3];                                       // 0x0029(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_GetDeckNumberByLevelName_Result;          // 0x002C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UWIDGET_Automap_DeckElement_C*          K2Node_Select_Default;                             // 0x0030(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WIDGET_Automap_DeckList_C_GetDeckElementByLevelName) == 0x000008, "Wrong alignment on WIDGET_Automap_DeckList_C_GetDeckElementByLevelName");
static_assert(sizeof(WIDGET_Automap_DeckList_C_GetDeckElementByLevelName) == 0x000038, "Wrong size on WIDGET_Automap_DeckList_C_GetDeckElementByLevelName");
static_assert(offsetof(WIDGET_Automap_DeckList_C_GetDeckElementByLevelName, LevelName) == 0x000000, "Member 'WIDGET_Automap_DeckList_C_GetDeckElementByLevelName::LevelName' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_GetDeckElementByLevelName, DeckElement) == 0x000008, "Member 'WIDGET_Automap_DeckList_C_GetDeckElementByLevelName::DeckElement' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_GetDeckElementByLevelName, Temp_int_Variable) == 0x000010, "Member 'WIDGET_Automap_DeckList_C_GetDeckElementByLevelName::Temp_int_Variable' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_GetDeckElementByLevelName, CallFunc_GetGameInstance_ReturnValue) == 0x000018, "Member 'WIDGET_Automap_DeckList_C_GetDeckElementByLevelName::CallFunc_GetGameInstance_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_GetDeckElementByLevelName, K2Node_DynamicCast_AsGI_Single_Player) == 0x000020, "Member 'WIDGET_Automap_DeckList_C_GetDeckElementByLevelName::K2Node_DynamicCast_AsGI_Single_Player' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_GetDeckElementByLevelName, K2Node_DynamicCast_bSuccess) == 0x000028, "Member 'WIDGET_Automap_DeckList_C_GetDeckElementByLevelName::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_GetDeckElementByLevelName, CallFunc_GetDeckNumberByLevelName_Result) == 0x00002C, "Member 'WIDGET_Automap_DeckList_C_GetDeckElementByLevelName::CallFunc_GetDeckNumberByLevelName_Result' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_GetDeckElementByLevelName, K2Node_Select_Default) == 0x000030, "Member 'WIDGET_Automap_DeckList_C_GetDeckElementByLevelName::K2Node_Select_Default' has a wrong offset!");

// Function WIDGET_Automap_DeckList.WIDGET_Automap_DeckList_C.SetWaypointTargetDecks
// 0x0070 (0x0070 - 0x0000)
struct WIDGET_Automap_DeckList_C_SetWaypointTargetDecks final
{
public:
	TArray<class FString>                         DeckSymbols;                                       // 0x0000(0x0010)(BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
	class UGI_SinglePlayer_C*                     GameInstance;                                      // 0x0010(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Array_Index_Variable;                     // 0x0018(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable;                    // 0x001C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x0020(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_24[0x4];                                       // 0x0024(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UGameInstance*                          CallFunc_GetGameInstance_ReturnValue;              // 0x0028(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UGI_SinglePlayer_C*                     K2Node_DynamicCast_AsGI_Single_Player;             // 0x0030(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0038(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_39[0x7];                                       // 0x0039(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class UWidget*>                        CallFunc_GetAllChildren_ReturnValue;               // 0x0040(0x0010)(ReferenceParm, ContainsInstancedReference)
	class UWidget*                                CallFunc_Array_Get_Item;                           // 0x0050(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x0058(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_5C[0x4];                                       // 0x005C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UWIDGET_Automap_DeckElement_C*          K2Node_DynamicCast_AsWIDGET_Automap_Deck_Element;  // 0x0060(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess_1;                     // 0x0068(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Less_IntInt_ReturnValue;                  // 0x0069(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Array_Contains_ReturnValue;               // 0x006A(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(WIDGET_Automap_DeckList_C_SetWaypointTargetDecks) == 0x000008, "Wrong alignment on WIDGET_Automap_DeckList_C_SetWaypointTargetDecks");
static_assert(sizeof(WIDGET_Automap_DeckList_C_SetWaypointTargetDecks) == 0x000070, "Wrong size on WIDGET_Automap_DeckList_C_SetWaypointTargetDecks");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetWaypointTargetDecks, DeckSymbols) == 0x000000, "Member 'WIDGET_Automap_DeckList_C_SetWaypointTargetDecks::DeckSymbols' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetWaypointTargetDecks, GameInstance) == 0x000010, "Member 'WIDGET_Automap_DeckList_C_SetWaypointTargetDecks::GameInstance' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetWaypointTargetDecks, Temp_int_Array_Index_Variable) == 0x000018, "Member 'WIDGET_Automap_DeckList_C_SetWaypointTargetDecks::Temp_int_Array_Index_Variable' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetWaypointTargetDecks, Temp_int_Loop_Counter_Variable) == 0x00001C, "Member 'WIDGET_Automap_DeckList_C_SetWaypointTargetDecks::Temp_int_Loop_Counter_Variable' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetWaypointTargetDecks, CallFunc_Add_IntInt_ReturnValue) == 0x000020, "Member 'WIDGET_Automap_DeckList_C_SetWaypointTargetDecks::CallFunc_Add_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetWaypointTargetDecks, CallFunc_GetGameInstance_ReturnValue) == 0x000028, "Member 'WIDGET_Automap_DeckList_C_SetWaypointTargetDecks::CallFunc_GetGameInstance_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetWaypointTargetDecks, K2Node_DynamicCast_AsGI_Single_Player) == 0x000030, "Member 'WIDGET_Automap_DeckList_C_SetWaypointTargetDecks::K2Node_DynamicCast_AsGI_Single_Player' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetWaypointTargetDecks, K2Node_DynamicCast_bSuccess) == 0x000038, "Member 'WIDGET_Automap_DeckList_C_SetWaypointTargetDecks::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetWaypointTargetDecks, CallFunc_GetAllChildren_ReturnValue) == 0x000040, "Member 'WIDGET_Automap_DeckList_C_SetWaypointTargetDecks::CallFunc_GetAllChildren_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetWaypointTargetDecks, CallFunc_Array_Get_Item) == 0x000050, "Member 'WIDGET_Automap_DeckList_C_SetWaypointTargetDecks::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetWaypointTargetDecks, CallFunc_Array_Length_ReturnValue) == 0x000058, "Member 'WIDGET_Automap_DeckList_C_SetWaypointTargetDecks::CallFunc_Array_Length_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetWaypointTargetDecks, K2Node_DynamicCast_AsWIDGET_Automap_Deck_Element) == 0x000060, "Member 'WIDGET_Automap_DeckList_C_SetWaypointTargetDecks::K2Node_DynamicCast_AsWIDGET_Automap_Deck_Element' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetWaypointTargetDecks, K2Node_DynamicCast_bSuccess_1) == 0x000068, "Member 'WIDGET_Automap_DeckList_C_SetWaypointTargetDecks::K2Node_DynamicCast_bSuccess_1' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetWaypointTargetDecks, CallFunc_Less_IntInt_ReturnValue) == 0x000069, "Member 'WIDGET_Automap_DeckList_C_SetWaypointTargetDecks::CallFunc_Less_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_DeckList_C_SetWaypointTargetDecks, CallFunc_Array_Contains_ReturnValue) == 0x00006A, "Member 'WIDGET_Automap_DeckList_C_SetWaypointTargetDecks::CallFunc_Array_Contains_ReturnValue' has a wrong offset!");

}

