#ifndef ITEMCONFIG_H
#define ITEMCONFIG_H

#pragma once


using namespace std;


struct ItemBaseTypeConfig
{
    string BaseName;
    float BaseChance;
    int BaseTypeStatRollMin;
    int BaseTypeStatRollMax;
    ItemBaseTypeConfig(float baseChance, int baseTypeStatRollMin, int baseTypeStatRollMax)
    {
        BaseChance = baseChance;
        BaseTypeStatRollMin = baseTypeStatRollMin;
        BaseTypeStatRollMax = baseTypeStatRollMax;
    }
};

struct ItemRarityConfig
{
    float RarityChance;
    int RarityType;
    int RarityAffixAllowance;
    int RarityStatRollMin;
    int RarityStatRollMax;
    ItemRarityConfig(float rarityChance, int rarityType, int rarityAffixAllowance, int typeStatRollMin, int typeStatRollMax)
    {
        RarityChance = rarityChance;
        RarityType = rarityType;
        RarityAffixAllowance = rarityAffixAllowance;
        RarityStatRollMin = typeStatRollMin;
        RarityStatRollMax = typeStatRollMax;
    }
};

struct ItemAffixModsConfig
{
    string ModsString;
    int AffixPlace;
    int ModType;
    int ModStatRollMin;
    int ModStatRollMax;
    ItemAffixModsConfig(int affixPlace, int modType, int typeStatRollMin, int typeStatRollMax)
    {
        AffixPlace = affixPlace;
        ModType = modType;
        ModStatRollMin = typeStatRollMin;
        ModStatRollMax = typeStatRollMax;
    }
};

struct ItemManufacturerConfig
{
    string ManufacturerString;
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
    string MaterialString;
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
    string QualityString;
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
    string PartsString;
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

static const ItemBaseTypeConfig ItemBaseType1{ 1, 14, 17 }; //"One Handed Short Sword Bronze Falx"

static const ItemBaseTypeConfig ItemBaseType2 {2, 8, 24 }; //"One Handed Short Sword Illyr Sica"

static const ItemBaseTypeConfig ItemBaseType7_1_1{ 1, 0, 0 }; //"Identifier Scrolls"

// static const ItemPartsConfig ItemParts1_1_2_1_1;

static const ItemRarityConfig ItemRarity1{ 50, 1, 0, 1, 4 }; //"Common"
static const ItemRarityConfig ItemRarity2{ 70, 2, 1, 4, 10 }; //"Uncommon"
static const ItemRarityConfig ItemRarity3{ 80, 3, 2, 10, 18 }; //"Rare"
static const ItemRarityConfig ItemRarity4{ 85, 4, 3, 19, 28 }; //"Masterwork"
static const ItemRarityConfig ItemRarity5{ 86, 5, 4, 28, 40 }; //"Epic"
static const ItemRarityConfig ItemRarity6{ 86.5f, 6, 5, 40, 54 }; //"Mythic"
static const ItemRarityConfig ItemRarity7{ 87, 7, 6, 54, 70 }; //"Exotic"
static const ItemRarityConfig ItemRarity8{ 87.1f, 8, 7, 70, 86 }; //"Ancient"
static const ItemRarityConfig ItemRarity9{ 87.05f, 9, 8, 86, 104 }; //"Legendary"
static const ItemRarityConfig ItemRarity10{ 87.06f, 10, 9, 104, 124 }; //"Heirloom"
static const ItemRarityConfig ItemRarity11{ 87.071f, 11, 10, 124, 146 }; //"Transcendent"
static const ItemRarityConfig ItemRarity12{ 100, 12, 10, 0, 0 }; //"Unique"

static const ItemMaterialConfig ItemMaterial1{ 10, 1, 1, 3 }; // Wood
static const ItemMaterialConfig ItemMaterial2{ 20, 2, 2, 5 }; // Stone
static const ItemMaterialConfig ItemMaterial3{ 30, 3, 4, 7 }; // Copper
static const ItemMaterialConfig ItemMaterial4{ 40, 4, 6, 10 }; // Iron
static const ItemMaterialConfig ItemMaterial5{ 50, 5, 9, 20 }; // Steel
static const ItemMaterialConfig ItemMaterial6{ 60, 6, 5, 30 }; // Obsidian
static const ItemMaterialConfig ItemMaterial7{ 70, 6, 30, 50 }; // Diamond
static const ItemMaterialConfig ItemMaterial8{ 80, 7, 90, 120 }; // Unimon 
static const ItemMaterialConfig ItemMaterial9{ 90, 7, 90, 120 }; // Tetradurmus
static const ItemMaterialConfig ItemMaterial10{ 100, 8, 200, 300 }; // Hexaferi

static const ItemManufacturerConfig ItemManufacturerConfig1{ 1, 250, 300 }; //Triumvirate 
static const ItemManufacturerConfig ItemManufacturerConfig2{ 2, 100, 180 }; //Kybi-Ran
static const ItemManufacturerConfig ItemManufacturerConfig3{ 3, 70, 130 }; //Yib-Hud
static const ItemManufacturerConfig ItemManufacturerConfig4{ 4, 60, 85 }; //Ignition
static const ItemManufacturerConfig ItemManufacturerConfig5{ 5, 90, 180 }; //Techcore
static const ItemManufacturerConfig ItemManufacturerConfig6{ 6, 40, 76 }; //O-mal

static const ItemQualityConfig ItemQualityConfig0{ 50, 0, 0 };
static const ItemQualityConfig ItemQualityConfig1{ 70, 1, 2 };
static const ItemQualityConfig ItemQualityConfig2{ 80, 2, 4 };
static const ItemQualityConfig ItemQualityConfig3{ 85, 3, 6 };
static const ItemQualityConfig ItemQualityConfig4{ 90, 4, 8 };
static const ItemQualityConfig ItemQualityConfig5{ 92, 5, 10 };
static const ItemQualityConfig ItemQualityConfig6{ 93, 6, 12 };
static const ItemQualityConfig ItemQualityConfig7{ 93.5f, 7, 14 };
static const ItemQualityConfig ItemQualityConfig8{ 94, 8, 16 };
static const ItemQualityConfig ItemQualityConfig9{ 94.5f, 9, 18 };
static const ItemQualityConfig ItemQualityConfig10{ 95, 10, 20 };
static const ItemQualityConfig ItemQualityConfig11{ 95.5f, 11, 22 };
static const ItemQualityConfig ItemQualityConfig12{ 96, 12, 24 };
static const ItemQualityConfig ItemQualityConfig13{ 96.5f, 13, 26 };
static const ItemQualityConfig ItemQualityConfig14{ 97, 14, 28 };
static const ItemQualityConfig ItemQualityConfig15{ 97.5f, 15, 30 };
static const ItemQualityConfig ItemQualityConfig16{ 98, 16, 32 };
static const ItemQualityConfig ItemQualityConfig17{ 98.5f, 17, 24 };
static const ItemQualityConfig ItemQualityConfig18{ 99, 18, 26 };
static const ItemQualityConfig ItemQualityConfig19{ 99.5f, 19, 28 };
static const ItemQualityConfig ItemQualityConfig20{ 100, 20, 30 };

class ItemConfig
{
public:
    static ItemRarityConfig GetConfigItemRarityData(float ItemRarity);
    static ItemQualityConfig GetConfigItemQualityData(float ItemQuality);
    static ItemMaterialConfig GetConfigItemMaterialData(float ItemMaterial);
    static ItemManufacturerConfig GentConfigItemManufacturerData(int ItemManufacturer);
    static ItemBaseTypeConfig GetConfigItemTypeData(float UseType, float ItemType, float ItemBase);

protected:
private:
};
#endif
