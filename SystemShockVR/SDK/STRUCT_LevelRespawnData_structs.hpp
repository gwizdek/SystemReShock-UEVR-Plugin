#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: STRUCT_LevelRespawnData

#include "Basic.hpp"

#include "STRUCT_EnemyRespawnData_structs.hpp"


namespace SDK
{

// UserDefinedStruct STRUCT_LevelRespawnData.STRUCT_LevelRespawnData
// 0x0018 (0x0018 - 0x0000)
struct FSTRUCT_LevelRespawnData final
{
public:
	class FName                                   LevelName_8_2F6EC5C245A8B2C149DA41AC21F4AA60;      // 0x0000(0x0008)(Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<struct FSTRUCT_EnemyRespawnData>       RespawnDataPerEnemy_4_D23B8BD84868931E927DAE84361088A9; // 0x0008(0x0010)(Edit, BlueprintVisible, SaveGame)
};
static_assert(alignof(FSTRUCT_LevelRespawnData) == 0x000008, "Wrong alignment on FSTRUCT_LevelRespawnData");
static_assert(sizeof(FSTRUCT_LevelRespawnData) == 0x000018, "Wrong size on FSTRUCT_LevelRespawnData");
static_assert(offsetof(FSTRUCT_LevelRespawnData, LevelName_8_2F6EC5C245A8B2C149DA41AC21F4AA60) == 0x000000, "Member 'FSTRUCT_LevelRespawnData::LevelName_8_2F6EC5C245A8B2C149DA41AC21F4AA60' has a wrong offset!");
static_assert(offsetof(FSTRUCT_LevelRespawnData, RespawnDataPerEnemy_4_D23B8BD84868931E927DAE84361088A9) == 0x000008, "Member 'FSTRUCT_LevelRespawnData::RespawnDataPerEnemy_4_D23B8BD84868931E927DAE84361088A9' has a wrong offset!");

}

