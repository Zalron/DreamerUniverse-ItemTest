#pragma once
#ifndef ITEMCOMPONENTS_H
#define ITEMCOMPONENTS_H
#include <string>
#include <cstdint>

using namespace std;

struct ItemType
{
    int UseType;
    int Type;
    int BaseType;
    int BaseIntStatRoll;
};

struct ItemSkillSlots
{
    int SkillSlotId;
    int SkillSlotType;
};

struct ItemRarityComponent
{
    int LevelRequirement;
};

struct ItemRarity
{
    int RarityType;
    int RarityRoll;
    int RarityAffixAllowance;
};

struct ItemQuality
{
    int QualityNum;
    int QualityStatIncrease;
};

struct ItemParts
{
    int PartsType;
    int PartsStatIntRoll;
    float PartsStatFloatRoll;
    float PartPercentRoll;
};

struct ItemMaterial
{
    int MaterialType;
    int MaterialStatRoll;
};

struct ItemManufacturer
{
    int ManufacturerType;
    int ManufacturerStatRoll;
};

struct ItemAffixMods
{
    int AffixPlace;
    int ModType;
    int ModStatRoll;
    float ModStatFloatRoll;
};

struct ItemStaging
{
    int ItemStage;
    int Seed;
};

struct CriticalChanceItemStat
{
    float CriticalChanceRoll;
};

struct MagicalDamageItemStat
{
    int MagicalDamageRoll;
};

struct PhysicalDamageItemStat
{
    int PhysicalDamageRoll;
};

struct HandlingItemStat
{
    float HandlingRoll;
};

struct AccuracyItemStat
{
    float AccuracyRoll;
};

struct GuardItemStat
{
    int GuardRoll;
};

struct BlockChanceItemStat
{
    float CriticalChanceRoll;
};

struct AttackRateItemStat
{
    float AttackRateRoll;
};

struct WeightItemStat
{
    int WeightRoll;
};

struct MagazineSizeItemStat
{
    int MagazineSizeRoll;
};

struct FireRateItemStat
{
    int FireRateRoll;
};

struct EvasionItemStat
{
    float EvasionRoll;
};

struct ArmourItemStat
{
    float ArmourRoll;
};

struct ArmourRechargeRateItemStat
{
    float ArmourRechargeRateRoll;
};

struct ArmourRechargeDelayItemStat
{
    float ArmourRechargeDelayRoll;
};

struct ItemName
{
    string BaseName;
    string CombinedName;
    string TypeName;
    string Manufacturer;
    string Material;
    string Rarity;
    string QualityLevelRequirement;
    string QualityStrengthRequirement;
    string QualityDexterityRequirement;
    string QualityIntelligenceRequirement;
    string QualityLuckRequirement;
    string QualityWillpowerRequirement;
    string QualityEnduranceRequirement;
    string Parts1;
    string Parts2;
    string Parts3;
    string Parts4;
    string Parts5;
    string Parts6;
    string Parts7;
    string Parts8;
    string Parts9;
    string Parts10;
    string Stats1;
    string Stats2;
    string Stats3;
    string Stats4;
    string Stats5;
    string Stats6;
    string Stats7;
    string Stats8;
    string Stats9;
    string Stats10;
    string Affixes1;
    string Affixes2;
    string Affixes3;
    string Affixes4;
    string Affixes5;
    string Affixes6;
    string Affixes7;
    string Affixes8;
    string Affixes9;
    string Affixes10;
    string Mod1;
    string Mod2;
    string Mod3;
    string Mod4;
    string Mod5;
    string Mod6;
    string Mod7;
    string Mod8;
    string Mod9;
    string Mod10;
};

class ItemComponents
{
public:

private:

};
#endif
