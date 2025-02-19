#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: HARDWARE_Bioscan_Base

#include "Basic.hpp"

#include "STRUCT_HardwareFeature_structs.hpp"


namespace SDK::Params
{

// Function HARDWARE_Bioscan_Base.HARDWARE_Bioscan_Base_C.ExecuteUbergraph_HARDWARE_Bioscan_Base
// 0x0098 (0x0098 - 0x0000)
struct HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UObject*                                Temp_object_Variable;                              // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TDelegate<void(class UObject* Loaded)>        K2Node_CreateDelegate_OutputDelegate;              // 0x0010(0x0010)(ZeroConstructor, NoDestructor)
	class UStaticMesh*                            K2Node_DynamicCast_AsStatic_Mesh;                  // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_29[0x7];                                       // 0x0029(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UObject*                                K2Node_CustomEvent_Loaded;                         // 0x0030(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UObject*                                Temp_object_Variable_1;                            // 0x0038(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInterface*                     K2Node_DynamicCast_AsMaterial_Interface;           // 0x0040(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess_1;                     // 0x0048(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_49[0x7];                                       // 0x0049(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class APAWN_SystemShockCharacter_C*           CallFunc_GetOwnerCharacter_Character;              // 0x0050(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APAWN_Hacker_Implant_C*                 K2Node_DynamicCast_AsPAWN_Hacker_Implant;          // 0x0058(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess_2;                     // 0x0060(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_61[0x3];                                       // 0x0061(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	TDelegate<void(class UObject* Loaded)>        K2Node_CreateDelegate_OutputDelegate_1;            // 0x0064(0x0010)(ZeroConstructor, NoDestructor)
	bool                                          CallFunc_SetStaticMesh_ReturnValue;                // 0x0074(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_75[0x3];                                       // 0x0075(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class APAWN_SystemShockCharacter_C*           CallFunc_GetOwnerCharacter_Character_1;            // 0x0078(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APAWN_Hacker_Implant_C*                 K2Node_DynamicCast_AsPAWN_Hacker_Implant_1;        // 0x0080(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess_3;                     // 0x0088(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_89[0x7];                                       // 0x0089(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UObject*                                K2Node_CustomEvent_Loaded_1;                       // 0x0090(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base) == 0x000008, "Wrong alignment on HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base");
static_assert(sizeof(HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base) == 0x000098, "Wrong size on HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base, EntryPoint) == 0x000000, "Member 'HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base::EntryPoint' has a wrong offset!");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base, Temp_object_Variable) == 0x000008, "Member 'HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base::Temp_object_Variable' has a wrong offset!");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base, K2Node_CreateDelegate_OutputDelegate) == 0x000010, "Member 'HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base::K2Node_CreateDelegate_OutputDelegate' has a wrong offset!");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base, K2Node_DynamicCast_AsStatic_Mesh) == 0x000020, "Member 'HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base::K2Node_DynamicCast_AsStatic_Mesh' has a wrong offset!");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base, K2Node_DynamicCast_bSuccess) == 0x000028, "Member 'HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base, K2Node_CustomEvent_Loaded) == 0x000030, "Member 'HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base::K2Node_CustomEvent_Loaded' has a wrong offset!");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base, Temp_object_Variable_1) == 0x000038, "Member 'HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base::Temp_object_Variable_1' has a wrong offset!");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base, K2Node_DynamicCast_AsMaterial_Interface) == 0x000040, "Member 'HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base::K2Node_DynamicCast_AsMaterial_Interface' has a wrong offset!");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base, K2Node_DynamicCast_bSuccess_1) == 0x000048, "Member 'HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base::K2Node_DynamicCast_bSuccess_1' has a wrong offset!");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base, CallFunc_GetOwnerCharacter_Character) == 0x000050, "Member 'HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base::CallFunc_GetOwnerCharacter_Character' has a wrong offset!");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base, K2Node_DynamicCast_AsPAWN_Hacker_Implant) == 0x000058, "Member 'HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base::K2Node_DynamicCast_AsPAWN_Hacker_Implant' has a wrong offset!");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base, K2Node_DynamicCast_bSuccess_2) == 0x000060, "Member 'HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base::K2Node_DynamicCast_bSuccess_2' has a wrong offset!");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base, K2Node_CreateDelegate_OutputDelegate_1) == 0x000064, "Member 'HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base::K2Node_CreateDelegate_OutputDelegate_1' has a wrong offset!");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base, CallFunc_SetStaticMesh_ReturnValue) == 0x000074, "Member 'HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base::CallFunc_SetStaticMesh_ReturnValue' has a wrong offset!");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base, CallFunc_GetOwnerCharacter_Character_1) == 0x000078, "Member 'HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base::CallFunc_GetOwnerCharacter_Character_1' has a wrong offset!");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base, K2Node_DynamicCast_AsPAWN_Hacker_Implant_1) == 0x000080, "Member 'HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base::K2Node_DynamicCast_AsPAWN_Hacker_Implant_1' has a wrong offset!");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base, K2Node_DynamicCast_bSuccess_3) == 0x000088, "Member 'HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base::K2Node_DynamicCast_bSuccess_3' has a wrong offset!");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base, K2Node_CustomEvent_Loaded_1) == 0x000090, "Member 'HARDWARE_Bioscan_Base_C_ExecuteUbergraph_HARDWARE_Bioscan_Base::K2Node_CustomEvent_Loaded_1' has a wrong offset!");

// Function HARDWARE_Bioscan_Base.HARDWARE_Bioscan_Base_C.OnLoaded_26D97462449B7D5235355185BBACCAA7
// 0x0008 (0x0008 - 0x0000)
struct HARDWARE_Bioscan_Base_C_OnLoaded_26D97462449B7D5235355185BBACCAA7 final
{
public:
	class UObject*                                Loaded;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(HARDWARE_Bioscan_Base_C_OnLoaded_26D97462449B7D5235355185BBACCAA7) == 0x000008, "Wrong alignment on HARDWARE_Bioscan_Base_C_OnLoaded_26D97462449B7D5235355185BBACCAA7");
static_assert(sizeof(HARDWARE_Bioscan_Base_C_OnLoaded_26D97462449B7D5235355185BBACCAA7) == 0x000008, "Wrong size on HARDWARE_Bioscan_Base_C_OnLoaded_26D97462449B7D5235355185BBACCAA7");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_OnLoaded_26D97462449B7D5235355185BBACCAA7, Loaded) == 0x000000, "Member 'HARDWARE_Bioscan_Base_C_OnLoaded_26D97462449B7D5235355185BBACCAA7::Loaded' has a wrong offset!");

// Function HARDWARE_Bioscan_Base.HARDWARE_Bioscan_Base_C.OnLoaded_A2E7E5BF44DB6A31210B5992A4329F8A
// 0x0008 (0x0008 - 0x0000)
struct HARDWARE_Bioscan_Base_C_OnLoaded_A2E7E5BF44DB6A31210B5992A4329F8A final
{
public:
	class UObject*                                Loaded;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(HARDWARE_Bioscan_Base_C_OnLoaded_A2E7E5BF44DB6A31210B5992A4329F8A) == 0x000008, "Wrong alignment on HARDWARE_Bioscan_Base_C_OnLoaded_A2E7E5BF44DB6A31210B5992A4329F8A");
static_assert(sizeof(HARDWARE_Bioscan_Base_C_OnLoaded_A2E7E5BF44DB6A31210B5992A4329F8A) == 0x000008, "Wrong size on HARDWARE_Bioscan_Base_C_OnLoaded_A2E7E5BF44DB6A31210B5992A4329F8A");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_OnLoaded_A2E7E5BF44DB6A31210B5992A4329F8A, Loaded) == 0x000000, "Member 'HARDWARE_Bioscan_Base_C_OnLoaded_A2E7E5BF44DB6A31210B5992A4329F8A::Loaded' has a wrong offset!");

// Function HARDWARE_Bioscan_Base.HARDWARE_Bioscan_Base_C.HasAdvancedBioScanner
// 0x000C (0x000C - 0x0000)
struct HARDWARE_Bioscan_Base_C_HasAdvancedBioScanner final
{
public:
	bool                                          Result;                                            // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_1[0x3];                                        // 0x0001(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_GetVersionNumber_Version;                 // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_GreaterEqual_IntInt_ReturnValue;          // 0x0008(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(HARDWARE_Bioscan_Base_C_HasAdvancedBioScanner) == 0x000004, "Wrong alignment on HARDWARE_Bioscan_Base_C_HasAdvancedBioScanner");
static_assert(sizeof(HARDWARE_Bioscan_Base_C_HasAdvancedBioScanner) == 0x00000C, "Wrong size on HARDWARE_Bioscan_Base_C_HasAdvancedBioScanner");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_HasAdvancedBioScanner, Result) == 0x000000, "Member 'HARDWARE_Bioscan_Base_C_HasAdvancedBioScanner::Result' has a wrong offset!");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_HasAdvancedBioScanner, CallFunc_GetVersionNumber_Version) == 0x000004, "Member 'HARDWARE_Bioscan_Base_C_HasAdvancedBioScanner::CallFunc_GetVersionNumber_Version' has a wrong offset!");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_HasAdvancedBioScanner, CallFunc_GreaterEqual_IntInt_ReturnValue) == 0x000008, "Member 'HARDWARE_Bioscan_Base_C_HasAdvancedBioScanner::CallFunc_GreaterEqual_IntInt_ReturnValue' has a wrong offset!");

// Function HARDWARE_Bioscan_Base.HARDWARE_Bioscan_Base_C.TryHideDisplayMesh
// 0x0010 (0x0010 - 0x0000)
struct HARDWARE_Bioscan_Base_C_TryHideDisplayMesh final
{
public:
	class APAWN_Hacker_Implant_C*                 HackerPawn;                                        // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_SetDisplayMesh_Result;                    // 0x0008(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsOverrideHandheldBeingUsed_Result;       // 0x0009(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(HARDWARE_Bioscan_Base_C_TryHideDisplayMesh) == 0x000008, "Wrong alignment on HARDWARE_Bioscan_Base_C_TryHideDisplayMesh");
static_assert(sizeof(HARDWARE_Bioscan_Base_C_TryHideDisplayMesh) == 0x000010, "Wrong size on HARDWARE_Bioscan_Base_C_TryHideDisplayMesh");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_TryHideDisplayMesh, HackerPawn) == 0x000000, "Member 'HARDWARE_Bioscan_Base_C_TryHideDisplayMesh::HackerPawn' has a wrong offset!");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_TryHideDisplayMesh, CallFunc_SetDisplayMesh_Result) == 0x000008, "Member 'HARDWARE_Bioscan_Base_C_TryHideDisplayMesh::CallFunc_SetDisplayMesh_Result' has a wrong offset!");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_TryHideDisplayMesh, CallFunc_IsOverrideHandheldBeingUsed_Result) == 0x000009, "Member 'HARDWARE_Bioscan_Base_C_TryHideDisplayMesh::CallFunc_IsOverrideHandheldBeingUsed_Result' has a wrong offset!");

// Function HARDWARE_Bioscan_Base.HARDWARE_Bioscan_Base_C.GetHardwareFeatures
// 0x0058 (0x0058 - 0x0000)
struct HARDWARE_Bioscan_Base_C_GetHardwareFeatures final
{
public:
	TArray<struct FSTRUCT_HardwareFeature>        Result;                                            // 0x0000(0x0010)(Parm, OutParm)
	class FText                                   CallFunc_ReplaceHardwareInputActionStringInText_Result; // 0x0010(0x0018)()
	struct FSTRUCT_HardwareFeature                K2Node_MakeStruct_STRUCT_HardwareFeature;          // 0x0028(0x0020)(HasGetValueTypeHash)
	TArray<struct FSTRUCT_HardwareFeature>        K2Node_MakeArray_Array;                            // 0x0048(0x0010)(ReferenceParm)
};
static_assert(alignof(HARDWARE_Bioscan_Base_C_GetHardwareFeatures) == 0x000008, "Wrong alignment on HARDWARE_Bioscan_Base_C_GetHardwareFeatures");
static_assert(sizeof(HARDWARE_Bioscan_Base_C_GetHardwareFeatures) == 0x000058, "Wrong size on HARDWARE_Bioscan_Base_C_GetHardwareFeatures");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_GetHardwareFeatures, Result) == 0x000000, "Member 'HARDWARE_Bioscan_Base_C_GetHardwareFeatures::Result' has a wrong offset!");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_GetHardwareFeatures, CallFunc_ReplaceHardwareInputActionStringInText_Result) == 0x000010, "Member 'HARDWARE_Bioscan_Base_C_GetHardwareFeatures::CallFunc_ReplaceHardwareInputActionStringInText_Result' has a wrong offset!");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_GetHardwareFeatures, K2Node_MakeStruct_STRUCT_HardwareFeature) == 0x000028, "Member 'HARDWARE_Bioscan_Base_C_GetHardwareFeatures::K2Node_MakeStruct_STRUCT_HardwareFeature' has a wrong offset!");
static_assert(offsetof(HARDWARE_Bioscan_Base_C_GetHardwareFeatures, K2Node_MakeArray_Array) == 0x000048, "Member 'HARDWARE_Bioscan_Base_C_GetHardwareFeatures::K2Node_MakeArray_Array' has a wrong offset!");

}

