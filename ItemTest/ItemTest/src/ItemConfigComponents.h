#pragma once
#include "flecs.h"

struct ItemConfigComponents
{
    struct ItemBaseConfig
    {
        //string BaseName;
        //int BaseTypeChance;
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
        int ModChanceMin;
        int ModChanceMax;
        int AffixPlace;
        int ModType;
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
        int PartsChanceMin;
        int PartsChanceMax;
        int PartsType;
        int PartsStatIntRollMin;
        int PartsStatIntRollMax;
        float PartsStatFloatRollMin;
        float PartsStatFloatRollMax;
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
    }
};