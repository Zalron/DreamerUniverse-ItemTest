#pragma once
#include "flecs.h"
#include <cstdlib>
#include <string>

struct ItemComponents
{
    struct ItemStaging
    {
        bool ItemSeedStage;
        bool ItemBaseComponentCreated;
        bool ItemRarityComponentCreated;
        bool ItemQualityComponentCreated;
        bool ItemMaterialComponentCreated;
        bool ItemManufacturerComponentCreated;
        bool ItemAffixComponentsCreated;
        bool ItemPartsComponentsCreated;
        bool ItemTagsCreated;
        bool ItemStatComponentsCreated;
        bool ItemStatCompiled;
        int Seed;
    };

    struct ItemSpawning
    {
        int NumberOfItems;
        int ItemLevel;
    };

    struct ItemBase 
    {
        //string ItemName
        int BaseItemType;
        int BaseIntRoll;
        float BaseFloatRoll;
    };

    struct ItemRarity
    {
        //int LevelRequirement;
        int RarityLevel;
        float RarityFloatRoll;
        int RarityIntRoll;
        int RarityAffixAllowance;
    };

    struct ItemQuality
    {
        int QualityNum;
        int QualityIntStatIncrease;
        float QualityFloatStatIncrease;
    };

    struct ItemMaterial
    {
        //string MaterialName
        int MaterialType;
        int MaterialStatIntRoll;
        float MaterialStatFloatRoll;
    };

    struct ItemManufacturer
    {
        int ManufacturerType;
        int ManufacturerStatIntRoll;
        float ManufacturerStatFloatRoll;
    };

    //struct ItemLevel
    //{
    //    int ItemLevel;
    //};

    struct ItemCharacterLevelRequirements
    {
        int CharacterLevelRequirement;
    };

    struct ItemCharacterStrengthRequirements
    {
        int CharacterStrengthRequirements;
    };

    struct ItemCharacterDexterityRequirements
    {
        int CharacterDexterityRequirements;
    };

    struct ItemCharacterIntelligenceRequirements
    {
        int CharacterIntelligenceRequirements;
    };

    struct ItemCharacterLuckRequirements
    {
        int CharacterLuckRequirements;
    };

    struct ItemCharacterWillpowerRequirements
    {
        int CharacterWillpowerRequirements;
    };

    struct ItemCharacterEnduranceRequirements
    {
        int CharacterEnduranceRequirements;
    };

    struct ItemSkillSlot1
    {
        int SkillSlotId;
        int SkillSlotType;
    };

    struct ItemSkillSlot2
    {
        int SkillSlotId;
        int SkillSlotType;
    };

    struct ItemSkillSlot3
    {
        int SkillSlotId;
        int SkillSlotType;
    };

    struct ItemSkillSlot4
    {
        int SkillSlotId;
        int SkillSlotType;
    };

    struct ItemSkillSlot5
    {
        int SkillSlotId;
        int SkillSlotType;
    };

    struct ItemSkillSlot6
    {
        int SkillSlotId;
        int SkillSlotType;
    };

    struct ItemSkillSlot7
    {
        int SkillSlotId;
        int SkillSlotType;
    };

    struct ItemSkillSlot8
    {
        int SkillSlotId;
        int SkillSlotType;
    };

    struct ItemSkillSlot9
    {
        int SkillSlotId;
        int SkillSlotType;
    };

    struct ItemSkillSlot10
    {
        int SkillSlotId;
        int SkillSlotType;
    };

    struct ItemParts1
    {
        int PartsType;
        int PartsStatIntRoll;
        float PartsStatFloatRoll;
        float PartPercentRoll;
    };

    struct ItemParts2
    {
        int PartsType;
        int PartsStatIntRoll;
        float PartsStatFloatRoll;
        float PartPercentRoll;
    };

    struct ItemParts3
    {
        int PartsType;
        int PartsStatIntRoll;
        float PartsStatFloatRoll;
        float PartPercentRoll;
    };

    struct ItemParts4
    {
        int PartsType;
        int PartsStatIntRoll;
        float PartsStatFloatRoll;
        float PartPercentRoll;
    };

    struct ItemParts5
    {
        int PartsType;
        int PartsStatIntRoll;
        float PartsStatFloatRoll;
        float PartPercentRoll;
    };

    struct ItemParts6
    {
        int PartsType;
        int PartsStatIntRoll;
        float PartsStatFloatRoll;
        float PartPercentRoll;
    };

    struct ItemParts7
    {
        int PartsType;
        int PartsStatIntRoll;
        float PartsStatFloatRoll;
        float PartPercentRoll;
    };

    struct ItemParts8
    {
        int PartsType;
        int PartsStatIntRoll;
        float PartsStatFloatRoll;
        float PartPercentRoll;
    };

    struct ItemParts9
    {
        int PartsType;
        int PartsStatIntRoll;
        float PartsStatFloatRoll;
        float PartPercentRoll;
    };

    struct ItemParts10
    {
        int PartsType;
        int PartsStatIntRoll;
        float PartsStatFloatRoll;
        float PartPercentRoll;
    };

    struct ItemAffixMods1
    {
        int AffixPlace;
        int ModType;
        int ModStatRoll;
        float ModStatFloatRoll;
    };

    struct ItemAffixMods2
    {
        int AffixPlace;
        int ModType;
        int ModStatRoll;
        float ModStatFloatRoll;
    };

    struct ItemAffixMods3
    {
        int AffixPlace;
        int ModType;
        int ModStatRoll;
        float ModStatFloatRoll;
    };

    struct ItemAffixMods4
    {
        int AffixPlace;
        int ModType;
        int ModStatRoll;
        float ModStatFloatRoll;
    };

    struct ItemAffixMods5
    {
        int AffixPlace;
        int ModType;
        int ModStatRoll;
        float ModStatFloatRoll;
    };

    struct ItemAffixMods6
    {
        int AffixPlace;
        int ModType;
        int ModStatRoll;
        float ModStatFloatRoll;
    };

    struct ItemAffixMods7
    {
        int AffixPlace;
        int ModType;
        int ModStatRoll;
        float ModStatFloatRoll;
    };

    struct ItemAffixMods8
    {
        int AffixPlace;
        int ModType;
        int ModStatRoll;
        float ModStatFloatRoll;
    };

    struct ItemAffixMods9
    {
        int AffixPlace;
        int ModType;
        int ModStatRoll;
        float ModStatFloatRoll;
    };

    struct ItemAffixMods10
    {
        int AffixPlace;
        int ModType;
        int ModStatRoll;
        float ModStatFloatRoll;
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

    struct RangeItemStat
    {
        int RangeRoll;
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

    struct ReloadTimeItemStat
    {
        float ReloadTime;
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

    struct ShieldItemStat
    {
        float ShieldRoll;
    };

    struct ShieldRechargeRateItemStat
    {
        float ShieldRechargeRateRoll;
    };

    struct ShieldRechargeDelayItemStat
    {
        float ShieldRechargeDelayRoll;
    };

    struct EnergyItemStat
    {
        float EnergyRoll;
    };

    struct EnergyRechargeRateItemStat
    {
        float EnergyRechargeRateRoll;
    };

    struct EnergyRechargeDelayItemStat
    {
        float EnergyRechargeDelayRoll;
    };

    struct ItemName
    {
        flecs::string BaseName;
        flecs::string CombinedName;
        flecs::string TypeName;
        flecs::string Manufacturer;
        flecs::string Material;
        flecs::string Rarity;
        flecs::string QualityLevelRequirement;
        flecs::string QualityStrengthRequirement;
        flecs::string QualityDexterityRequirement;
        flecs::string QualityIntelligenceRequirement;
        flecs::string QualityLuckRequirement;
        flecs::string QualityWillpowerRequirement;
        flecs::string QualityEnduranceRequirement;
        flecs::string Parts1;
        flecs::string Parts2;
        flecs::string Parts3;
        flecs::string Parts4;
        flecs::string Parts5;
        flecs::string Parts6;
        flecs::string Parts7;
        flecs::string Parts8;
        flecs::string Parts9;
        flecs::string Parts10;
        flecs::string Stats1;
        flecs::string Stats2;
        flecs::string Stats3;
        flecs::string Stats4;
        flecs::string Stats5;
        flecs::string Stats6;
        flecs::string Stats7;
        flecs::string Stats8;
        flecs::string Stats9;
        flecs::string Stats10;
        flecs::string Affixes1;
        flecs::string Affixes2;
        flecs::string Affixes3;
        flecs::string Affixes4;
        flecs::string Affixes5;
        flecs::string Affixes6;
        flecs::string Affixes7;
        flecs::string Affixes8;
        flecs::string Affixes9;
        flecs::string Affixes10;
        flecs::string Mod1;
        flecs::string Mod2;
        flecs::string Mod3;
        flecs::string Mod4;
        flecs::string Mod5;
        flecs::string Mod6;
        flecs::string Mod7;
        flecs::string Mod8;
        flecs::string Mod9;
        flecs::string Mod10;
    };

    ItemComponents(flecs::world& world)
    {
        world.module<ItemComponents>();

        world.component<ItemStaging>();
        world.component<ItemSpawning>();
        world.component<ItemBase>();
        world.component<ItemRarity>();
        world.component<ItemQuality>();
        world.component<ItemMaterial>();
        world.component<ItemManufacturer>();
        //world.component<ItemLevel>();
        world.component<ItemCharacterLevelRequirements>();
        world.component<ItemCharacterStrengthRequirements>();
        world.component<ItemCharacterDexterityRequirements>();
        world.component<ItemCharacterIntelligenceRequirements>();
        world.component<ItemCharacterLuckRequirements>();
        world.component<ItemCharacterWillpowerRequirements>();
        world.component<ItemCharacterEnduranceRequirements>();
        world.component<ItemSkillSlot1>();
        world.component<ItemSkillSlot2>();
        world.component<ItemSkillSlot3>();
        world.component<ItemSkillSlot4>();
        world.component<ItemSkillSlot5>();
        world.component<ItemSkillSlot6>();
        world.component<ItemSkillSlot7>();
        world.component<ItemSkillSlot8>();
        world.component<ItemSkillSlot9>();
        world.component<ItemSkillSlot10>();
        world.component<ItemParts1>();
        world.component<ItemParts2>();
        world.component<ItemParts3>();
        world.component<ItemParts4>();
        world.component<ItemParts5>();
        world.component<ItemParts6>();
        world.component<ItemParts7>();
        world.component<ItemParts8>();
        world.component<ItemParts9>();
        world.component<ItemParts10>();
        world.component<ItemAffixMods1>();
        world.component<ItemAffixMods2>();
        world.component<ItemAffixMods3>();
        world.component<ItemAffixMods4>();
        world.component<ItemAffixMods5>();
        world.component<ItemAffixMods6>();
        world.component<ItemAffixMods7>();
        world.component<ItemAffixMods8>();
        world.component<ItemAffixMods9>();
        world.component<ItemAffixMods10>();
        world.component<CriticalChanceItemStat>();
        world.component<MagicalDamageItemStat>();
        world.component<PhysicalDamageItemStat>();
        world.component<HandlingItemStat>();
        world.component<AccuracyItemStat>();
        world.component<RangeItemStat>();
        world.component<GuardItemStat>();
        world.component<BlockChanceItemStat>();
        world.component<AttackRateItemStat>();
        world.component<WeightItemStat>();
        world.component<MagazineSizeItemStat>();
        world.component<FireRateItemStat>();
        world.component<ReloadTimeItemStat>();
        world.component<EvasionItemStat>();
        world.component<ArmourItemStat>();
        world.component<ArmourRechargeRateItemStat>();
        world.component<ArmourRechargeDelayItemStat>();
        world.component<ShieldItemStat>();
        world.component<ShieldRechargeRateItemStat>();
        world.component<ShieldRechargeDelayItemStat>();
        world.component<EnergyItemStat>();
        world.component<EnergyRechargeRateItemStat>();
        world.component<EnergyRechargeDelayItemStat>();
        world.component<ItemName>();
    }
};

