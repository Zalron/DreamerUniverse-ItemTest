#ifndef ITEMCONFIG_H
#define ITEMCONFIG_H

#pragma once


using namespace std;

struct ItemBaseTypeConfig
{
    //string BaseName;
    float BaseChance;
    int BaseTypeStatRollMin;
    int BaseTypeStatRollMax;
    ItemBaseTypeConfig(float baseChance, int baseTypeStatRollMin, int baseTypeStatRollMax)
    {
        BaseTypeStatRollMin = baseTypeStatRollMin;
        BaseTypeStatRollMax = baseTypeStatRollMax;
    }
};

struct ItemRarityConfig
{
    float RarityFloatRollMin;
    float RarityFloatRollMax;
    int RarityLevel;
    int RarityAffixAllowance;
    int RarityIntRollMin;
    int RarityIntRollMax;
    ItemRarityConfig(float rarityFloatRollMin, float rarityFloatRollMax, int rarityLevel, int rarityAffixAllowance, int rarityIntRollMin, int rarityIntRollMax)
    {
        RarityFloatRollMin = rarityFloatRollMin;
        RarityFloatRollMax = rarityFloatRollMax;
        RarityLevel = rarityLevel;
        RarityAffixAllowance = rarityAffixAllowance;
        RarityIntRollMin = rarityIntRollMin;
        RarityIntRollMax = rarityIntRollMax;
    }
};

struct ItemAffixModsConfig
{
    //string ModsString;
    float ModChanceMin;
    float ModChanceMax;
    int AffixPlace;
    int ModType;
    int ModStatRollMin;
    int ModStatRollMax;
    ItemAffixModsConfig(float modChanceMin, float modChanceMax, int affixPlace, int modType, int typeStatRollMin, int typeStatRollMax)
    {
        ModChanceMin = modChanceMin;
        ModChanceMax = modChanceMax;
        AffixPlace = affixPlace;
        ModType = modType;
        ModStatRollMin = typeStatRollMin;
        ModStatRollMax = typeStatRollMax;
    }
};

struct ItemManufacturerConfig
{
    //string ManufacturerString;
    int ManufacturerType;
    int ManufacturerStatRollMin;
    int ManufacturerStatRollMax;
    ItemManufacturerConfig(int manufacturerType, int  manufacturerStatRollMin, int  manufacturerStatRollMax)
    {
        ManufacturerType = manufacturerType;
        ManufacturerStatRollMin = manufacturerStatRollMin;
        ManufacturerStatRollMax = manufacturerStatRollMax;
    }
};

struct ItemMaterialConfig
{
    //string MaterialString;
    float MaterialChance;
    int MaterialType;
    int MaterialStatRollMin;
    int MaterialStatRollMax;
    ItemMaterialConfig(float materialChance, int materialType, int materialStatRollMin, int materialStatRollMax)
    {
        MaterialChance = materialChance;
        MaterialType = materialType;
        MaterialStatRollMin = materialStatRollMin;
        MaterialStatRollMax = materialStatRollMax;
    }
};

struct ItemQualityConfig
{
    //string QualityString;
    float QualityChance;
    int QualityNum;
    int QualityStatIncrease;
    ItemQualityConfig(float qualityChance, int qualityType, int qualityStatIncrease)
    {
        QualityChance = qualityChance;
        QualityNum = qualityType;
        QualityStatIncrease = qualityStatIncrease;
    }
};

struct ItemPartsConfig
{
    //string PartsString;
    int PartsType;
    int PartsStatRollMin;
    int PartsStatRollMax;
    ItemPartsConfig(int partsType, int partsStatRollMin, int partsStatRollMax)
    {
        PartsType = partsType;
        PartsStatRollMin = partsStatRollMin;
        PartsStatRollMax = partsStatRollMax;
    }
};

const ItemBaseTypeConfig ItemBaseType1{ 1, 14, 17 }; //"One Handed Short Sword Bronze Falx"

const ItemBaseTypeConfig ItemBaseType2{ 2, 8, 24 }; //"One Handed Short Sword Illyr Sica"

const ItemBaseTypeConfig ItemBaseType7_1_1{ 1, 0, 0 }; //"Identifier Scrolls"

// static const ItemPartsConfig ItemParts1_1_2_1_1;

const ItemRarityConfig ItemRarity1{0, 50, 1, 0, 1, 4 }; //"Common"
const ItemRarityConfig ItemRarity2{50, 70, 2, 1, 4, 10 }; //"Uncommon"
const ItemRarityConfig ItemRarity3{70, 80, 3, 2, 10, 18 }; //"Rare"
const ItemRarityConfig ItemRarity4{80, 85, 4, 3, 19, 28 }; //"Masterwork"
const ItemRarityConfig ItemRarity5{85, 86, 5, 4, 28, 40 }; //"Epic"
const ItemRarityConfig ItemRarity6{86, 86.5f, 6, 5, 40, 54 }; //"Mythic"
const ItemRarityConfig ItemRarity7{86.5f, 87, 7, 6, 54, 70 }; //"Exotic"
const ItemRarityConfig ItemRarity8{87, 87.1f, 8, 7, 70, 86 }; //"Ancient"
const ItemRarityConfig ItemRarity9{87.1f, 87.05f, 9, 8, 86, 104 }; //"Legendary"
const ItemRarityConfig ItemRarity10{87.05f, 87.06f, 10, 9, 104, 124 }; //"Heirloom"
const ItemRarityConfig ItemRarity11{87.06f, 87.071f, 11, 10, 124, 146 }; //"Transcendent"
const ItemRarityConfig ItemRarity12{87.071f, 100, 12, 10, 0, 0 }; //"Unique"

const ItemMaterialConfig ItemMaterial1{ 10, 1, 1, 3 }; // Wood
const ItemMaterialConfig ItemMaterial2{ 20, 2, 2, 5 }; // Stone
const ItemMaterialConfig ItemMaterial3{ 30, 3, 4, 7 }; // Copper
const ItemMaterialConfig ItemMaterial4{ 40, 4, 6, 10 }; // Iron
const ItemMaterialConfig ItemMaterial5{ 50, 5, 9, 20 }; // Steel
const ItemMaterialConfig ItemMaterial6{ 60, 6, 5, 30 }; // Obsidian
const ItemMaterialConfig ItemMaterial7{ 70, 6, 30, 50 }; // Diamond
const ItemMaterialConfig ItemMaterial8{ 80, 7, 90, 120 }; // Unimon 
const ItemMaterialConfig ItemMaterial9{ 90, 7, 90, 120 }; // Tetradurmus
const ItemMaterialConfig ItemMaterial10{ 100, 8, 200, 300 }; // Hexaferi

const ItemManufacturerConfig ItemManufacturerConfig1{ 1, 250, 300 }; //Triumvirate 
const ItemManufacturerConfig ItemManufacturerConfig2{ 2, 100, 180 }; //Kybi-Ran
const ItemManufacturerConfig ItemManufacturerConfig3{ 3, 70, 130 }; //Yib-Hud
const ItemManufacturerConfig ItemManufacturerConfig4{ 4, 60, 85 }; //Ignition
const ItemManufacturerConfig ItemManufacturerConfig5{ 5, 90, 180 }; //Techcore
const ItemManufacturerConfig ItemManufacturerConfig6{ 6, 40, 76 }; //O-mal

const ItemQualityConfig ItemQualityConfig0{ 50, 0, 0 };
const ItemQualityConfig ItemQualityConfig1{ 70, 1, 2 };
const ItemQualityConfig ItemQualityConfig2{ 80, 2, 4 };
const ItemQualityConfig ItemQualityConfig3{ 85, 3, 6 };
const ItemQualityConfig ItemQualityConfig4{ 90, 4, 8 };
const ItemQualityConfig ItemQualityConfig5{ 92, 5, 10 };
const ItemQualityConfig ItemQualityConfig6{ 93, 6, 12 };
const ItemQualityConfig ItemQualityConfig7{ 93.5f, 7, 14 };
const ItemQualityConfig ItemQualityConfig8{ 94, 8, 16 };
const ItemQualityConfig ItemQualityConfig9{ 94.5f, 9, 18 };
const ItemQualityConfig ItemQualityConfig10{ 95, 10, 20 };
const ItemQualityConfig ItemQualityConfig11{ 95.5f, 11, 22 };
const ItemQualityConfig ItemQualityConfig12{ 96, 12, 24 };
const ItemQualityConfig ItemQualityConfig13{ 96.5f, 13, 26 };
const ItemQualityConfig ItemQualityConfig14{ 97, 14, 28 };
const ItemQualityConfig ItemQualityConfig15{ 97.5f, 15, 30 };
const ItemQualityConfig ItemQualityConfig16{ 98, 16, 32 };
const ItemQualityConfig ItemQualityConfig17{ 98.5f, 17, 24 };
const ItemQualityConfig ItemQualityConfig18{ 99, 18, 26 };
const ItemQualityConfig ItemQualityConfig19{ 99.5f, 19, 28 };
const ItemQualityConfig ItemQualityConfig20{ 100, 20, 30 };

static ItemQualityConfig GetConfigItemQualityData(float ItemQuality);
static ItemMaterialConfig GetConfigItemMaterialData(float ItemMaterial);
static ItemManufacturerConfig GentConfigItemManufacturerData(int ItemManufacturer);
static ItemBaseTypeConfig GetConfigItemTypeData(float UseType, float ItemType, float ItemBase);

#endif
