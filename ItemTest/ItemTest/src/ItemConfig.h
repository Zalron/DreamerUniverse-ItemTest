#ifndef ITEMCONFIG_H
#define ITEMCONFIG_H

#pragma once


using namespace std;

struct ItemBaseTypeConfig
{
    //string BaseName;
    int BaseTypeIntRollMin;
    int BaseTypeIntRollMax;
    float BaseTypeFloatRollMin;
    float BaseTypeFloatRollMax;
    ItemBaseTypeConfig(int baseTypeStatRollMin, int baseTypeStatRollMax, float baseTypeFloatRollMin, float baseTypeFloatRollMax)
    {
        BaseTypeIntRollMin = baseTypeStatRollMin;
        BaseTypeIntRollMax = baseTypeStatRollMax;
        BaseTypeFloatRollMin = baseTypeFloatRollMin;
        BaseTypeFloatRollMax = baseTypeFloatRollMax;
    }
};

struct ItemRarityConfig
{
    float RaritySpawnChanceMin;
    float RaritySpawnChanceMax;
    float RarityFloatRollMin;
    float RarityFloatRollMax;
    int RarityLevel;
    int RarityAffixAllowance;
    int RarityIntRollMin;
    int RarityIntRollMax;
    ItemRarityConfig(float raritySpawnChanceMin, float raritySpawnChanceMax, float rarityFloatRollMin, float rarityFloatRollMax, int rarityLevel, int rarityAffixAllowance, int rarityIntRollMin, int rarityIntRollMax)
    {
        RaritySpawnChanceMin = raritySpawnChanceMin;
        RaritySpawnChanceMax = raritySpawnChanceMax;
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
    int MaterialStatRollMin;
    int MaterialStatRollMax;
    ItemMaterialConfig(float materialChance, int materialStatRollMin, int materialStatRollMax)
    {
        MaterialChance = materialChance;
        MaterialStatRollMin = materialStatRollMin;
        MaterialStatRollMax = materialStatRollMax;
    }
};

struct ItemQualityConfig
{
    //string QualityString;
    float QualitySpawnChanceMin;
    float QualitySpawnChanceMax;
    int QualityNum;
    int QualityIntStatIncrease;
    float QualityFloatStatIncrease;
    ItemQualityConfig(float qualitySpawnChanceMin, float qualitySpawnChanceMax, int qualityType, int qualityStatIncrease, float qualityFloatStatIncrease)
    {
        QualitySpawnChanceMin = qualitySpawnChanceMin;
        QualitySpawnChanceMax = qualitySpawnChanceMax;
        QualityNum = qualityType;
        QualityIntStatIncrease = qualityStatIncrease;
        QualityFloatStatIncrease = qualityFloatStatIncrease;
    }
};

struct ItemPartsConfig
{
    //string PartsString;
    int PartsType;
    int PartsStatIntRollMin;
    int PartsStatIntRollMax;
    float PartsStatFloatRollMin;
    float PartsStatFloatRollMax;
    ItemPartsConfig(int partsType, int partsStatIntRollMin, int partsStatIntRollMax, int partsStatFloatRollMin, int partsStatFloatRollMax)
    {
        PartsType = partsType;
        PartsStatIntRollMin = partsStatIntRollMin;
        PartsStatIntRollMax = partsStatIntRollMax;
        PartsStatFloatRollMin = partsStatFloatRollMin;
        PartsStatFloatRollMax = partsStatFloatRollMax;
    }
};

const ItemBaseTypeConfig OneHandedSwordBronzeFalx{ 14, 17, 2.5f, 2.9f }; //"One Handed Short Sword Bronze Falx"
const ItemBaseTypeConfig OneHandedSwordIllyrSica{ 8, 24, 3.2f, 4.0f }; //"One Handed Short Sword Illyr Sica"
const ItemBaseTypeConfig OneHandedSwordGrandDao{ 8, 24, 3.2f, 4.0f }; //"One Handed Short Sword Grand Dao"
const ItemBaseTypeConfig OneHandedSwordWateredXiphos{ 8, 24, 3.2f, 4.0f }; //"One Handed Short Sword Watered Xiphos"
const ItemBaseTypeConfig OneHandedSwordDryKhopesh{ 8, 24, 3.2f, 4.0f }; //"One Handed Short Sword Dry Khopesh"
const ItemBaseTypeConfig OneHandedSwordCuttingSabre{ 8, 24, 3.2f, 4.0f }; //"One Handed Short Sword Cutting Sabre"
const ItemBaseTypeConfig OneHandedSwordBloodyMacuahuitl{ 8, 24, 3.2f, 4.0f }; //"One Handed Short Sword Bloody Macuahuitl"
const ItemBaseTypeConfig OneHandedSwordShiningCrusader{ 8, 24, 3.2f, 4.0f }; //"One Handed Short Sword Shining Crusader"
const ItemBaseTypeConfig OneHandedSwordSerratedKhanda{ 8, 24, 3.2f, 4.0f }; //"One Handed Short Sword Serrated Khanda"
const ItemBaseTypeConfig OneHandedSwordHoledAkrafena{ 8, 24, 3.2f, 4.0f }; //"One Handed Short Sword Holed Akrafena"


// static const ItemPartsConfig ItemParts1;

const ItemRarityConfig ItemRarity1{50, 70, 0, 0, 1, 0, 1, 4 }; //"Common"
const ItemRarityConfig ItemRarity2{70, 80, 0, 0, 2, 1, 4, 10 }; //"Uncommon"
const ItemRarityConfig ItemRarity3{80, 85, 0, 0, 3, 2, 10, 18 }; //"Rare"
const ItemRarityConfig ItemRarity4{85, 89, 0, 0, 4, 3, 19, 28 }; //"Masterwork"
const ItemRarityConfig ItemRarity5{89, 92, 0, 0, 5, 4, 28, 40 }; //"Epic"
const ItemRarityConfig ItemRarity6{92, 93, 0, 0, 6, 5, 40, 54 }; //"Mythic"
const ItemRarityConfig ItemRarity7{93, 93.5f, 0, 0, 7, 6, 54, 70 }; //"Exotic"
const ItemRarityConfig ItemRarity8{93.5f, 93.9f, 0, 0, 8, 7, 70, 86 }; //"Ancient"
const ItemRarityConfig ItemRarity9{93.9f, 94.3f, 0, 0, 9, 8, 86, 104 }; //"Legendary"
const ItemRarityConfig ItemRarity10{94.3f, 94.5f, 0, 0, 10, 9, 104, 124 }; //"Heirloom"
const ItemRarityConfig ItemRarity11{94.5f, 94.6f, 0, 0, 11, 10, 124, 146 }; //"Transcendent"
const ItemRarityConfig ItemRarity12{94.6f, 100, 0, 0, 0, 0, 0, 0 }; //"Unique"

const ItemMaterialConfig ItemMaterial1{ 10, 1, 3 }; // Wood
const ItemMaterialConfig ItemMaterial2{ 20, 2, 5 }; // Stone
const ItemMaterialConfig ItemMaterial3{ 30, 4, 7 }; // Copper
const ItemMaterialConfig ItemMaterial4{ 40, 6, 10 }; // Iron
const ItemMaterialConfig ItemMaterial5{ 50, 9, 20 }; // Steel
const ItemMaterialConfig ItemMaterial6{ 60, 5, 30 }; // Obsidian
const ItemMaterialConfig ItemMaterial7{ 70, 30, 50 }; // Diamond
const ItemMaterialConfig ItemMaterial8{ 80, 90, 120 }; // Unimon 
const ItemMaterialConfig ItemMaterial9{ 90, 90, 120 }; // Tetradurmus
const ItemMaterialConfig ItemMaterial10{ 100, 200, 300 }; // Hexaferi

const ItemManufacturerConfig ItemManufacturerConfig1{ 1, 250, 300 }; //Triumvirate 
const ItemManufacturerConfig ItemManufacturerConfig2{ 2, 100, 180 }; //Kybi-Ran
const ItemManufacturerConfig ItemManufacturerConfig3{ 3, 70, 130 }; //Yib-Hud
const ItemManufacturerConfig ItemManufacturerConfig4{ 4, 60, 85 }; //Ignition
const ItemManufacturerConfig ItemManufacturerConfig5{ 5, 90, 180 }; //Techcore
const ItemManufacturerConfig ItemManufacturerConfig6{ 6, 40, 76 }; //O-mal

const ItemQualityConfig ItemQualityConfig0{ 50, 70, 0, 0, 0};
const ItemQualityConfig ItemQualityConfig1{ 70, 80, 1, 2, 1.5f};
const ItemQualityConfig ItemQualityConfig2{ 80, 85, 2, 4, 3};
const ItemQualityConfig ItemQualityConfig3{ 85, 90, 3, 6, 4.5f};
const ItemQualityConfig ItemQualityConfig4{ 90, 92, 4, 8, 6};
const ItemQualityConfig ItemQualityConfig5{ 92, 93, 5, 10, 7.5f};
const ItemQualityConfig ItemQualityConfig6{ 93, 93.5f, 6, 12, 9};
const ItemQualityConfig ItemQualityConfig7{ 93.5f, 94, 7, 14, 10.5f};
const ItemQualityConfig ItemQualityConfig8{ 94, 94.5f, 8, 16, 12};
const ItemQualityConfig ItemQualityConfig9{ 94.5f, 95, 9, 18, 13.5f};
const ItemQualityConfig ItemQualityConfig10{ 95, 95.5f, 10, 20, 15};
const ItemQualityConfig ItemQualityConfig11{ 95.5f, 96, 11, 22, 16.5f};
const ItemQualityConfig ItemQualityConfig12{ 96, 96.5f, 12, 24, 18};
const ItemQualityConfig ItemQualityConfig13{ 96.5f, 97, 13, 26, 19.5f};
const ItemQualityConfig ItemQualityConfig14{ 97, 97.5f, 14, 28, 21};
const ItemQualityConfig ItemQualityConfig15{ 97.5f, 98, 15, 30, 22.5f};
const ItemQualityConfig ItemQualityConfig16{ 98, 98.5f, 16, 32, 24};
const ItemQualityConfig ItemQualityConfig17{ 98.5f, 99, 17, 24, 25.5f};
const ItemQualityConfig ItemQualityConfig18{ 99, 99.5f, 18, 26, 27};
const ItemQualityConfig ItemQualityConfig19{ 99.5f, 99.55f, 19, 28, 28.5f};
const ItemQualityConfig ItemQualityConfig20{ 99.55f, 100, 20, 30, 30};

#endif
