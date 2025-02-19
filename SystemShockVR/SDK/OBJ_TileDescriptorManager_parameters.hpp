#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: OBJ_TileDescriptorManager

#include "Basic.hpp"

#include "STRUCT_MeshDescriptor_structs.hpp"


namespace SDK::Params
{

// Function OBJ_TileDescriptorManager.OBJ_TileDescriptorManager_C.BuildDescriptorMaps
// 0x0130 (0x0130 - 0x0000)
struct OBJ_TileDescriptorManager_C_BuildDescriptorMaps final
{
public:
	TSoftObjectPtr<class UStaticMesh>             CurrentStaticMesh;                                 // 0x0000(0x0028)(Edit, BlueprintVisible, HasGetValueTypeHash)
	bool                                          HasMaterials;                                      // 0x0028(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_29[0x3];                                       // 0x0029(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   RowName;                                           // 0x002C(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Array_Index_Variable;                     // 0x0034(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable;                    // 0x0038(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x003C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Array_Index_Variable_1;                   // 0x0040(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable_1;                  // 0x0044(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue_1;                 // 0x0048(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Array_Index_Variable_2;                   // 0x004C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable_2;                  // 0x0050(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue_2;                 // 0x0054(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FSTRUCT_MeshDescriptor                 CallFunc_GetDataTableRowFromName_OutRow;           // 0x0058(0x0048)(HasGetValueTypeHash)
	bool                                          CallFunc_GetDataTableRowFromName_ReturnValue;      // 0x00A0(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_A1[0x7];                                       // 0x00A1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class FName>                           CallFunc_GetDataTableRowNames_OutRowNames;         // 0x00A8(0x0010)(ReferenceParm)
	class FName                                   CallFunc_Array_Get_Item;                           // 0x00B8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x00C0(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Less_IntInt_ReturnValue;                  // 0x00C4(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_C5[0x3];                                       // 0x00C5(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	TSoftObjectPtr<class UMaterialInterface>      CallFunc_Array_Get_Item_1;                         // 0x00C8(0x0028)(HasGetValueTypeHash)
	int32                                         CallFunc_Array_Length_ReturnValue_1;               // 0x00F0(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Less_IntInt_ReturnValue_1;                // 0x00F4(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_F5[0x3];                                       // 0x00F5(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_Array_Length_ReturnValue_2;               // 0x00F8(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Greater_IntInt_ReturnValue;               // 0x00FC(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_FD[0x3];                                       // 0x00FD(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	TSoftObjectPtr<class UStaticMesh>             CallFunc_Array_Get_Item_2;                         // 0x0100(0x0028)(HasGetValueTypeHash)
	int32                                         CallFunc_Array_Length_ReturnValue_3;               // 0x0128(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Less_IntInt_ReturnValue_2;                // 0x012C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps) == 0x000008, "Wrong alignment on OBJ_TileDescriptorManager_C_BuildDescriptorMaps");
static_assert(sizeof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps) == 0x000130, "Wrong size on OBJ_TileDescriptorManager_C_BuildDescriptorMaps");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, CurrentStaticMesh) == 0x000000, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::CurrentStaticMesh' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, HasMaterials) == 0x000028, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::HasMaterials' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, RowName) == 0x00002C, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::RowName' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, Temp_int_Array_Index_Variable) == 0x000034, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::Temp_int_Array_Index_Variable' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, Temp_int_Loop_Counter_Variable) == 0x000038, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::Temp_int_Loop_Counter_Variable' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, CallFunc_Add_IntInt_ReturnValue) == 0x00003C, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::CallFunc_Add_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, Temp_int_Array_Index_Variable_1) == 0x000040, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::Temp_int_Array_Index_Variable_1' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, Temp_int_Loop_Counter_Variable_1) == 0x000044, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::Temp_int_Loop_Counter_Variable_1' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, CallFunc_Add_IntInt_ReturnValue_1) == 0x000048, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::CallFunc_Add_IntInt_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, Temp_int_Array_Index_Variable_2) == 0x00004C, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::Temp_int_Array_Index_Variable_2' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, Temp_int_Loop_Counter_Variable_2) == 0x000050, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::Temp_int_Loop_Counter_Variable_2' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, CallFunc_Add_IntInt_ReturnValue_2) == 0x000054, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::CallFunc_Add_IntInt_ReturnValue_2' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, CallFunc_GetDataTableRowFromName_OutRow) == 0x000058, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::CallFunc_GetDataTableRowFromName_OutRow' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, CallFunc_GetDataTableRowFromName_ReturnValue) == 0x0000A0, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::CallFunc_GetDataTableRowFromName_ReturnValue' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, CallFunc_GetDataTableRowNames_OutRowNames) == 0x0000A8, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::CallFunc_GetDataTableRowNames_OutRowNames' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, CallFunc_Array_Get_Item) == 0x0000B8, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, CallFunc_Array_Length_ReturnValue) == 0x0000C0, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::CallFunc_Array_Length_ReturnValue' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, CallFunc_Less_IntInt_ReturnValue) == 0x0000C4, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::CallFunc_Less_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, CallFunc_Array_Get_Item_1) == 0x0000C8, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::CallFunc_Array_Get_Item_1' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, CallFunc_Array_Length_ReturnValue_1) == 0x0000F0, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::CallFunc_Array_Length_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, CallFunc_Less_IntInt_ReturnValue_1) == 0x0000F4, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::CallFunc_Less_IntInt_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, CallFunc_Array_Length_ReturnValue_2) == 0x0000F8, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::CallFunc_Array_Length_ReturnValue_2' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, CallFunc_Greater_IntInt_ReturnValue) == 0x0000FC, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::CallFunc_Greater_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, CallFunc_Array_Get_Item_2) == 0x000100, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::CallFunc_Array_Get_Item_2' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, CallFunc_Array_Length_ReturnValue_3) == 0x000128, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::CallFunc_Array_Length_ReturnValue_3' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_BuildDescriptorMaps, CallFunc_Less_IntInt_ReturnValue_2) == 0x00012C, "Member 'OBJ_TileDescriptorManager_C_BuildDescriptorMaps::CallFunc_Less_IntInt_ReturnValue_2' has a wrong offset!");

// Function OBJ_TileDescriptorManager.OBJ_TileDescriptorManager_C.GetDescriptionFromMaterial
// 0x00F8 (0x00F8 - 0x0000)
struct OBJ_TileDescriptorManager_C_GetDescriptionFromMaterial final
{
public:
	class UMaterialInterface*                     Material;                                          // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FText                                   DescriptionText;                                   // 0x0008(0x0018)(Parm, OutParm)
	struct FSTRUCT_MeshDescriptor                 CallFunc_GetDataTableRowFromName_OutRow;           // 0x0020(0x0048)(HasGetValueTypeHash)
	bool                                          CallFunc_GetDataTableRowFromName_ReturnValue;      // 0x0068(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_69[0x7];                                       // 0x0069(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TSoftObjectPtr<class UMaterialInterface>      CallFunc_Conv_ObjectToSoftObjectReference_ReturnValue; // 0x0070(0x0028)(UObjectWrapper, HasGetValueTypeHash)
	class FName                                   CallFunc_Map_Find_Value;                           // 0x0098(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Map_Find_ReturnValue;                     // 0x00A0(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_A1[0x7];                                       // 0x00A1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSTRUCT_MeshDescriptor                 CallFunc_GetDataTableRowFromName_OutRow_1;         // 0x00A8(0x0048)(HasGetValueTypeHash)
	bool                                          CallFunc_GetDataTableRowFromName_ReturnValue_1;    // 0x00F0(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(OBJ_TileDescriptorManager_C_GetDescriptionFromMaterial) == 0x000008, "Wrong alignment on OBJ_TileDescriptorManager_C_GetDescriptionFromMaterial");
static_assert(sizeof(OBJ_TileDescriptorManager_C_GetDescriptionFromMaterial) == 0x0000F8, "Wrong size on OBJ_TileDescriptorManager_C_GetDescriptionFromMaterial");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescriptionFromMaterial, Material) == 0x000000, "Member 'OBJ_TileDescriptorManager_C_GetDescriptionFromMaterial::Material' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescriptionFromMaterial, DescriptionText) == 0x000008, "Member 'OBJ_TileDescriptorManager_C_GetDescriptionFromMaterial::DescriptionText' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescriptionFromMaterial, CallFunc_GetDataTableRowFromName_OutRow) == 0x000020, "Member 'OBJ_TileDescriptorManager_C_GetDescriptionFromMaterial::CallFunc_GetDataTableRowFromName_OutRow' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescriptionFromMaterial, CallFunc_GetDataTableRowFromName_ReturnValue) == 0x000068, "Member 'OBJ_TileDescriptorManager_C_GetDescriptionFromMaterial::CallFunc_GetDataTableRowFromName_ReturnValue' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescriptionFromMaterial, CallFunc_Conv_ObjectToSoftObjectReference_ReturnValue) == 0x000070, "Member 'OBJ_TileDescriptorManager_C_GetDescriptionFromMaterial::CallFunc_Conv_ObjectToSoftObjectReference_ReturnValue' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescriptionFromMaterial, CallFunc_Map_Find_Value) == 0x000098, "Member 'OBJ_TileDescriptorManager_C_GetDescriptionFromMaterial::CallFunc_Map_Find_Value' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescriptionFromMaterial, CallFunc_Map_Find_ReturnValue) == 0x0000A0, "Member 'OBJ_TileDescriptorManager_C_GetDescriptionFromMaterial::CallFunc_Map_Find_ReturnValue' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescriptionFromMaterial, CallFunc_GetDataTableRowFromName_OutRow_1) == 0x0000A8, "Member 'OBJ_TileDescriptorManager_C_GetDescriptionFromMaterial::CallFunc_GetDataTableRowFromName_OutRow_1' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescriptionFromMaterial, CallFunc_GetDataTableRowFromName_ReturnValue_1) == 0x0000F0, "Member 'OBJ_TileDescriptorManager_C_GetDescriptionFromMaterial::CallFunc_GetDataTableRowFromName_ReturnValue_1' has a wrong offset!");

// Function OBJ_TileDescriptorManager.OBJ_TileDescriptorManager_C.GetDescriptionFromStaticMesh
// 0x0140 (0x0140 - 0x0000)
struct OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh final
{
public:
	class UStaticMesh*                            StaticMesh;                                        // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInterface*                     Material;                                          // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FText                                   DescriptionText;                                   // 0x0010(0x0018)(Parm, OutParm)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_29[0x7];                                       // 0x0029(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TSoftObjectPtr<class UStaticMesh>             CallFunc_Conv_ObjectToSoftObjectReference_ReturnValue; // 0x0030(0x0028)(UObjectWrapper, HasGetValueTypeHash)
	TSoftObjectPtr<class UStaticMesh>             CallFunc_Conv_ObjectToSoftObjectReference_ReturnValue_1; // 0x0058(0x0028)(UObjectWrapper, HasGetValueTypeHash)
	class FText                                   CallFunc_GetDescriptionFromMaterial_DescriptionText; // 0x0080(0x0018)()
	struct FSTRUCT_MeshDescriptor                 CallFunc_GetDataTableRowFromName_OutRow;           // 0x0098(0x0048)(HasGetValueTypeHash)
	bool                                          CallFunc_GetDataTableRowFromName_ReturnValue;      // 0x00E0(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Set_Contains_ReturnValue;                 // 0x00E1(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_BooleanAND_ReturnValue;                   // 0x00E2(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_E3[0x1];                                       // 0x00E3(0x0001)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   CallFunc_Map_Find_Value;                           // 0x00E4(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Map_Find_ReturnValue;                     // 0x00EC(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_ED[0x3];                                       // 0x00ED(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSTRUCT_MeshDescriptor                 CallFunc_GetDataTableRowFromName_OutRow_1;         // 0x00F0(0x0048)(HasGetValueTypeHash)
	bool                                          CallFunc_GetDataTableRowFromName_ReturnValue_1;    // 0x0138(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh) == 0x000008, "Wrong alignment on OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh");
static_assert(sizeof(OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh) == 0x000140, "Wrong size on OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh, StaticMesh) == 0x000000, "Member 'OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh::StaticMesh' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh, Material) == 0x000008, "Member 'OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh::Material' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh, DescriptionText) == 0x000010, "Member 'OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh::DescriptionText' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh, CallFunc_IsValid_ReturnValue) == 0x000028, "Member 'OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh::CallFunc_IsValid_ReturnValue' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh, CallFunc_Conv_ObjectToSoftObjectReference_ReturnValue) == 0x000030, "Member 'OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh::CallFunc_Conv_ObjectToSoftObjectReference_ReturnValue' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh, CallFunc_Conv_ObjectToSoftObjectReference_ReturnValue_1) == 0x000058, "Member 'OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh::CallFunc_Conv_ObjectToSoftObjectReference_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh, CallFunc_GetDescriptionFromMaterial_DescriptionText) == 0x000080, "Member 'OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh::CallFunc_GetDescriptionFromMaterial_DescriptionText' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh, CallFunc_GetDataTableRowFromName_OutRow) == 0x000098, "Member 'OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh::CallFunc_GetDataTableRowFromName_OutRow' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh, CallFunc_GetDataTableRowFromName_ReturnValue) == 0x0000E0, "Member 'OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh::CallFunc_GetDataTableRowFromName_ReturnValue' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh, CallFunc_Set_Contains_ReturnValue) == 0x0000E1, "Member 'OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh::CallFunc_Set_Contains_ReturnValue' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh, CallFunc_BooleanAND_ReturnValue) == 0x0000E2, "Member 'OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh::CallFunc_BooleanAND_ReturnValue' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh, CallFunc_Map_Find_Value) == 0x0000E4, "Member 'OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh::CallFunc_Map_Find_Value' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh, CallFunc_Map_Find_ReturnValue) == 0x0000EC, "Member 'OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh::CallFunc_Map_Find_ReturnValue' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh, CallFunc_GetDataTableRowFromName_OutRow_1) == 0x0000F0, "Member 'OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh::CallFunc_GetDataTableRowFromName_OutRow_1' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh, CallFunc_GetDataTableRowFromName_ReturnValue_1) == 0x000138, "Member 'OBJ_TileDescriptorManager_C_GetDescriptionFromStaticMesh::CallFunc_GetDataTableRowFromName_ReturnValue_1' has a wrong offset!");

// Function OBJ_TileDescriptorManager.OBJ_TileDescriptorManager_C.GetDescRowNameFromStaticMesh
// 0x0050 (0x0050 - 0x0000)
struct OBJ_TileDescriptorManager_C_GetDescRowNameFromStaticMesh final
{
public:
	class UStaticMesh*                            StaticMesh;                                        // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Found;                                             // 0x0008(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_9[0x3];                                        // 0x0009(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   RowName;                                           // 0x000C(0x0008)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_14[0x4];                                       // 0x0014(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TSoftObjectPtr<class UStaticMesh>             CallFunc_Conv_ObjectToSoftObjectReference_ReturnValue; // 0x0018(0x0028)(UObjectWrapper, HasGetValueTypeHash)
	class FName                                   CallFunc_Map_Find_Value;                           // 0x0040(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Map_Find_ReturnValue;                     // 0x0048(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(OBJ_TileDescriptorManager_C_GetDescRowNameFromStaticMesh) == 0x000008, "Wrong alignment on OBJ_TileDescriptorManager_C_GetDescRowNameFromStaticMesh");
static_assert(sizeof(OBJ_TileDescriptorManager_C_GetDescRowNameFromStaticMesh) == 0x000050, "Wrong size on OBJ_TileDescriptorManager_C_GetDescRowNameFromStaticMesh");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescRowNameFromStaticMesh, StaticMesh) == 0x000000, "Member 'OBJ_TileDescriptorManager_C_GetDescRowNameFromStaticMesh::StaticMesh' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescRowNameFromStaticMesh, Found) == 0x000008, "Member 'OBJ_TileDescriptorManager_C_GetDescRowNameFromStaticMesh::Found' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescRowNameFromStaticMesh, RowName) == 0x00000C, "Member 'OBJ_TileDescriptorManager_C_GetDescRowNameFromStaticMesh::RowName' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescRowNameFromStaticMesh, CallFunc_Conv_ObjectToSoftObjectReference_ReturnValue) == 0x000018, "Member 'OBJ_TileDescriptorManager_C_GetDescRowNameFromStaticMesh::CallFunc_Conv_ObjectToSoftObjectReference_ReturnValue' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescRowNameFromStaticMesh, CallFunc_Map_Find_Value) == 0x000040, "Member 'OBJ_TileDescriptorManager_C_GetDescRowNameFromStaticMesh::CallFunc_Map_Find_Value' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescRowNameFromStaticMesh, CallFunc_Map_Find_ReturnValue) == 0x000048, "Member 'OBJ_TileDescriptorManager_C_GetDescRowNameFromStaticMesh::CallFunc_Map_Find_ReturnValue' has a wrong offset!");

// Function OBJ_TileDescriptorManager.OBJ_TileDescriptorManager_C.GetDescRowNameFromMaterial
// 0x0050 (0x0050 - 0x0000)
struct OBJ_TileDescriptorManager_C_GetDescRowNameFromMaterial final
{
public:
	class UMaterialInterface*                     Material;                                          // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Found;                                             // 0x0008(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_9[0x3];                                        // 0x0009(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   RowName;                                           // 0x000C(0x0008)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_14[0x4];                                       // 0x0014(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TSoftObjectPtr<class UMaterialInterface>      CallFunc_Conv_ObjectToSoftObjectReference_ReturnValue; // 0x0018(0x0028)(UObjectWrapper, HasGetValueTypeHash)
	class FName                                   CallFunc_Map_Find_Value;                           // 0x0040(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Map_Find_ReturnValue;                     // 0x0048(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(OBJ_TileDescriptorManager_C_GetDescRowNameFromMaterial) == 0x000008, "Wrong alignment on OBJ_TileDescriptorManager_C_GetDescRowNameFromMaterial");
static_assert(sizeof(OBJ_TileDescriptorManager_C_GetDescRowNameFromMaterial) == 0x000050, "Wrong size on OBJ_TileDescriptorManager_C_GetDescRowNameFromMaterial");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescRowNameFromMaterial, Material) == 0x000000, "Member 'OBJ_TileDescriptorManager_C_GetDescRowNameFromMaterial::Material' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescRowNameFromMaterial, Found) == 0x000008, "Member 'OBJ_TileDescriptorManager_C_GetDescRowNameFromMaterial::Found' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescRowNameFromMaterial, RowName) == 0x00000C, "Member 'OBJ_TileDescriptorManager_C_GetDescRowNameFromMaterial::RowName' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescRowNameFromMaterial, CallFunc_Conv_ObjectToSoftObjectReference_ReturnValue) == 0x000018, "Member 'OBJ_TileDescriptorManager_C_GetDescRowNameFromMaterial::CallFunc_Conv_ObjectToSoftObjectReference_ReturnValue' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescRowNameFromMaterial, CallFunc_Map_Find_Value) == 0x000040, "Member 'OBJ_TileDescriptorManager_C_GetDescRowNameFromMaterial::CallFunc_Map_Find_Value' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetDescRowNameFromMaterial, CallFunc_Map_Find_ReturnValue) == 0x000048, "Member 'OBJ_TileDescriptorManager_C_GetDescRowNameFromMaterial::CallFunc_Map_Find_ReturnValue' has a wrong offset!");

// Function OBJ_TileDescriptorManager.OBJ_TileDescriptorManager_C.GetStaticMeshHasMaterialDescriptor
// 0x0040 (0x0040 - 0x0000)
struct OBJ_TileDescriptorManager_C_GetStaticMeshHasMaterialDescriptor final
{
public:
	class UStaticMesh*                            StaticMesh;                                        // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0008(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_9[0x7];                                        // 0x0009(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TSoftObjectPtr<class UStaticMesh>             CallFunc_Conv_ObjectToSoftObjectReference_ReturnValue; // 0x0010(0x0028)(UObjectWrapper, HasGetValueTypeHash)
	bool                                          CallFunc_Set_Contains_ReturnValue;                 // 0x0038(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(OBJ_TileDescriptorManager_C_GetStaticMeshHasMaterialDescriptor) == 0x000008, "Wrong alignment on OBJ_TileDescriptorManager_C_GetStaticMeshHasMaterialDescriptor");
static_assert(sizeof(OBJ_TileDescriptorManager_C_GetStaticMeshHasMaterialDescriptor) == 0x000040, "Wrong size on OBJ_TileDescriptorManager_C_GetStaticMeshHasMaterialDescriptor");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetStaticMeshHasMaterialDescriptor, StaticMesh) == 0x000000, "Member 'OBJ_TileDescriptorManager_C_GetStaticMeshHasMaterialDescriptor::StaticMesh' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetStaticMeshHasMaterialDescriptor, Result) == 0x000008, "Member 'OBJ_TileDescriptorManager_C_GetStaticMeshHasMaterialDescriptor::Result' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetStaticMeshHasMaterialDescriptor, CallFunc_Conv_ObjectToSoftObjectReference_ReturnValue) == 0x000010, "Member 'OBJ_TileDescriptorManager_C_GetStaticMeshHasMaterialDescriptor::CallFunc_Conv_ObjectToSoftObjectReference_ReturnValue' has a wrong offset!");
static_assert(offsetof(OBJ_TileDescriptorManager_C_GetStaticMeshHasMaterialDescriptor, CallFunc_Set_Contains_ReturnValue) == 0x000038, "Member 'OBJ_TileDescriptorManager_C_GetStaticMeshHasMaterialDescriptor::CallFunc_Set_Contains_ReturnValue' has a wrong offset!");

}

