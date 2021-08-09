#pragma once
#include "flecs.h"
#include <cstdlib>
#include <string>

struct ItemComponents
{
    struct ItemStaging
    {
        int ItemStage;
        int Seed;
    };

    struct ItemSpawning
    {
        int NumberOfItems;
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

    /*struct ItemName
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
    };*/

    struct EquipableItemTag {};
    struct WeaponsItemTag {};
    struct MeleeItemTag {};
    struct RangedItemTag {};
    struct OneHandedItemTag {};
    struct TwoHandedItemTag {};
    struct SwordItemTag {};
    struct MaceItemTag {};
    struct KnifeItemTag {};
    struct WarhammerItemTag {};
    struct AxeItemTag {};
    struct ShieldItemTag {};
    struct RapierItemTag {};
    struct ClubItemTag {};
    struct HalberdItemTag {};
    struct StaffItemTag {};
    struct SpearItemTag {};
    struct ClawsItemTag {};
    struct WandItemTag {};
    struct ThrownItemTag {};
    struct PistolItemTag {};
    struct HandCannonItemTag {};
    struct RevolverItemTag {};
    struct HandCrossbowItemTag {};
    struct BowItemTag {};
    struct CrossbowItemTag {};
    struct CarbineItemTag {};
    struct AssaultRifleItemTag {};
    struct SniperRifleItemTag {};
    struct LightMachineGunItemTag {};
    struct SubMachineGunItemTag {};
    struct ShotgunItemTag {};
    struct GrenadeLauncherItemTag {};
    struct RocketLauncherItemTag {};
    struct ArmourItemTag {};
    struct PowerArmourItemTag {};
    struct LightPowerArmourItemTag {};
    struct MediumPowerArmourItemTag {};
    struct HeavyPowerArmourItemTag {};
    struct NonPowerArmourItemTag {};
    struct ClothsItemTag {};
    struct HeadItemTag {};
    struct BeltItemTag {};
    struct ChestsItemTag {};
    struct LegsItemTag {};
    struct ArmsItemTag {};
    struct HandsItemTag {};
    struct ShouldersItemTag {};
    struct BackpackItemTag {};
    struct RingsItemTag {};
    struct NecklaceItemTag {};
    struct EquipmentItemTag {};
    struct FlasksItemTag {};
    struct HealthItemTag {};
    struct MagicItemTag {};
    struct MovementItemTag {};
    struct ResistanceItemTag {};
    struct AmmoItemTag {};
    struct QuiversItemTag {};
    struct MagazinesItemTag {};
    struct GrenadesItemTag {};
    struct RocketsItemTag {};
    struct MinesItemTag {};
    struct ScrollsItemTag {};
    struct BuildingsItemTag {};
    struct CraftingItemTag {};
    struct MapsItemTag {};
    struct MapChiselItemTag {};
    struct CrystalsItemTag {};
    struct CardsItemTag {};
    struct OrbsItemTag {};
    struct OrbOfIdentifyingItemTag {};
    struct OrbOfErasingItemTag {};
    struct OrbOfForgingItemTag {};
    struct OrbOfChaosItemTag {};
    struct OrbOfDivinityItemTag {};
    struct OrbOfInvigoratingItemTag {};
    struct OrbOfEnforingItemTag {};
    struct OrbOfModifyingItemTag {};
    struct OrbOfEnhancingItemTag {};
    struct OrbOfChangeItemTag {};
    struct OrbOfMirroringItemTag {};

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
        //world.component<ItemName>();
        world.component<EquipableItemTag>();
        world.component<WeaponsItemTag>();
        world.component<MeleeItemTag>();
        world.component<RangedItemTag>();
        world.component<OneHandedItemTag>();
        world.component<TwoHandedItemTag>();
        world.component<SwordItemTag>();
        world.component<MaceItemTag>();
        world.component<KnifeItemTag>();
        world.component<WarhammerItemTag>();
        world.component<AxeItemTag>();
        world.component<ShieldItemTag>();
        world.component<RapierItemTag>();
        world.component<ClubItemTag>();
        world.component<HalberdItemTag>();
        world.component<StaffItemTag>();
        world.component<SpearItemTag>();
        world.component<ClawsItemTag>();
        world.component<WandItemTag>();
        world.component<ThrownItemTag>();
        world.component<PistolItemTag>();
        world.component<HandCannonItemTag>();
        world.component<RevolverItemTag>();
        world.component<HandCrossbowItemTag>();
        world.component<BowItemTag>();
        world.component<CrossbowItemTag>();
        world.component<CarbineItemTag>();
        world.component<AssaultRifleItemTag>();
        world.component<SniperRifleItemTag>();
        world.component<LightMachineGunItemTag>();
        world.component<SubMachineGunItemTag>();
        world.component<ShotgunItemTag>();
        world.component<GrenadeLauncherItemTag>();
        world.component<RocketLauncherItemTag>();
        world.component<ArmourItemTag>();
        world.component<PowerArmourItemTag>();
        world.component<LightPowerArmourItemTag>();
        world.component<MediumPowerArmourItemTag>();
        world.component<HeavyPowerArmourItemTag>();
        world.component<NonPowerArmourItemTag>();
        world.component<ClothsItemTag>();
        world.component<HeadItemTag>();
        world.component<BeltItemTag>();
        world.component<ChestsItemTag>();
        world.component<LegsItemTag>();
        world.component<ArmsItemTag>();
        world.component<HandsItemTag>();
        world.component<ShouldersItemTag>();
        world.component<BackpackItemTag>();
        world.component<RingsItemTag>();
        world.component<NecklaceItemTag>();
        world.component<EquipmentItemTag>();
        world.component<FlasksItemTag>();
        world.component<HealthItemTag>();
        world.component<MagicItemTag>();
        world.component<MovementItemTag>();
        world.component<ResistanceItemTag>();
        world.component<AmmoItemTag>();
        world.component<QuiversItemTag>();
        world.component<MagazinesItemTag>();
        world.component<GrenadesItemTag>();
        world.component<RocketsItemTag>();
        world.component<MinesItemTag>();
        world.component<ScrollsItemTag>();
        world.component<BuildingsItemTag>();
        world.component<CraftingItemTag>();
        world.component<MapsItemTag>();
        world.component<MapChiselItemTag>();
        world.component<CrystalsItemTag>();
        world.component<CardsItemTag>();
        world.component<OrbsItemTag>();
        world.component<OrbOfIdentifyingItemTag>();
        world.component<OrbOfErasingItemTag>();
        world.component<OrbOfForgingItemTag>();
        world.component<OrbOfChaosItemTag>();
        world.component<OrbOfDivinityItemTag>();
        world.component<OrbOfInvigoratingItemTag>();
        world.component<OrbOfEnforingItemTag>();
        world.component<OrbOfModifyingItemTag>();
        world.component<OrbOfEnhancingItemTag>();
        world.component<OrbOfChangeItemTag>();
        world.component<OrbOfMirroringItemTag>();
    }
};

