#pragma once
#include "flecs.h"

struct ItemConfigComponents
{
    struct ItemBaseConfig
    {
        //string BaseName;
        //int BaseTypeChance;
        int BaseTypeID;
        int BaseTypeIntRollMin;
        int BaseTypeIntRollMax;
        float BaseTypeFloatRollMin;
        float BaseTypeFloatRollMax;
    };

    struct ItemRarityConfig
    {
        int RarityLevel;
        int RarityAffixAllowance;
        int RaritySpawnChanceMin;
        int RaritySpawnChanceMax;
        float RarityFloatRollMin;
        float RarityFloatRollMax;
        int RarityIntRollMin;
        int RarityIntRollMax;
    };

    struct ItemAffixModsConfig
    {
        //string ModsString;
        int ModId;
        int ModChanceMin;
        int ModChanceMax;
        int OrPreffixSuffix; // 0 = Preffix 1 = Suffix
        int ModStatRollMin;
        int ModStatRollMax;
    };

    struct ItemManufacturerConfig
    {
        //string ManufacturerString;
        int ManufacturerType;
        int ManufacturerStatIntRollMin;
        int ManufacturerStatIntRollMax;
        float ManufacturerStatFloatRollMin;
        float ManufacturerStatFloatRollMax;
    };

    struct ItemMaterialConfig
    {
        //string MaterialString;

        int MaterialChanceMin;
        int MaterialChanceMax;
        int MaterialType;
        int MaterialStatIntRollMin;
        int MaterialStatIntRollMax;
        float MaterialStatFloatRollMin;
        float MaterialStatFloatRollMax;
    };

    struct ItemQualityConfig
    {
        //string QualityString;
        int QualitySpawnChanceMin;
        int QualitySpawnChanceMax;
        int QualityNum;
        int QualityIntStatIncrease;
        float QualityFloatStatIncrease;
    };

    struct ItemPartsConfig
    {
        //string PartsString;
        int PartsType;
        int PartsChanceMin;
        int PartsChanceMax;
        int PartsStatIntRollMin;
        int PartsStatIntRollMax;
        float PartsStatFloatRollMin;
        float PartsStatFloatRollMax;
    };

    struct ItemStatConfig 
    {
        int StatType;
        int StatIntRollMin;
        int StatIntRollMax;
        int StatFloatRollMin;
        int StatFloatRollMax;
    };

    struct ItemComponentsConfig
    {
        int ItemComponentType;
    };

    struct ItemTagConfig
    {
        int ItemTagType;
    };

    struct StandardItemBaseRollTable
    {
        ItemRarityConfig rarityRollTable[11];

        ItemQualityConfig qualityRollTable[21];

        ItemMaterialConfig materialRollTable[10];

        ItemManufacturerConfig manufacturerRollTable[6];
    };

    struct ItemPartRollTable 
    {
        ItemPartsConfig partRollTable1[10];
        ItemPartsConfig partRollTable2[10];
        ItemPartsConfig partRollTable3[10];
        ItemPartsConfig partRollTable4[10];
        ItemPartsConfig partRollTable5[10];
        ItemPartsConfig partRollTable6[10];
        ItemPartsConfig partRollTable7[10];
        ItemPartsConfig partRollTable8[10];
        ItemPartsConfig partRollTable9[10];
        ItemPartsConfig partRollTable10[10];
    };

    struct ItemModRolltable
    {
        ItemAffixModsConfig modsRollTable1[10];
        ItemAffixModsConfig modsRollTable2[10];
        ItemAffixModsConfig modsRollTable3[10];
        ItemAffixModsConfig modsRollTable4[10];
        ItemAffixModsConfig modsRollTable5[10];
        ItemAffixModsConfig modsRollTable6[10];
        ItemAffixModsConfig modsRollTable7[10];
        ItemAffixModsConfig modsRollTable8[10];
        ItemAffixModsConfig modsRollTable9[10];
        ItemAffixModsConfig modsRollTable10[10];
    };

    struct ConfigStage 
    {
        uint8_t stage;
    };

    ItemConfigComponents(flecs::world& world)
    {
        world.module<ItemConfigComponents>();

        world.component<ItemBaseConfig>();
        world.component<ItemRarityConfig>();
        world.component<ItemAffixModsConfig>();
        world.component<ItemManufacturerConfig>();
        world.component<ItemMaterialConfig>();
        world.component<ItemQualityConfig>();
        world.component<ItemPartsConfig>();
        world.component<ItemStatConfig>();
        world.component<ItemComponentsConfig>();
        world.component<ItemTagConfig>();
        world.component<ItemModRolltable>();
        world.component<StandardItemBaseRollTable>();
        world.component<ConfigStage>();
    }
};