#pragma once
#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <cstdint>
#include <cstdlib>
#include "flecs.h"
#include "ItemConfig.h"
#include <flecs_os_api_stdcpp.h>
#include <random>
#include <iostream>
using namespace std;


struct Item
{
public:

    struct ItemStaging
    {
        int ItemStage;
        int Seed;
    };

    struct ItemSpawning
    {
        int NumberOfItems;
    };

    struct ItemTypeCreation
    {
        int ItemTypeInt;
        int BaseIntStatRoll;
        float BaseFloatStatRoll;
    };

    struct ItemRarity
    {
        //int LevelRequirement;
        int RarityLevel;
        int RarityFloatRoll;
        float RarityIntRoll;
        int RarityAffixAllowance;
    };

    struct ItemQuality
    {
        int QualityNum;
        int QualityStatIncrease;
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

    struct ItemLevel
    {
        int ItemLevel;
    };

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

    struct Weapons {};
    struct Melee {};
    struct Ranged {};
    struct OneHanded {};
    struct TwoHanded {};
    struct ShortSword {};
    struct Mace {};
    struct Knife {};
    struct Warhammer {};
    struct Axe {};
    struct Shield {};
    struct Rapier {};
    struct Club {};
    struct LongSword {};
    struct Halberd {};
    struct Staff {};
    struct Spear {};
    struct Claws {};
    struct Wand {};
    struct Thrown {};
    struct Pistol {};
    struct HandCannon {};
    struct Revolver {};
    struct HandCrossbow {};
    struct Bow {};
    struct Crossbow {};
    struct Carbine {};
    struct AssaultRifle {};
    struct SniperRifle {};
    struct LightMachineGun {};
    struct SubMachineGun {};
    struct Shotgun {};
    struct GrenadeLauncher {};
    struct RocketLauncher {};
    struct Armour {};
    struct PowerArmour {};
    struct LightPowerArmour {};
    struct MediumPowerArmour {};
    struct HeavyPowerArmour {};
    struct NonPowerArmour {};
    struct Cloths {};
    struct Head {};
    struct Belt {};
    struct Chests {};
    struct Legs {};
    struct Arms {};
    struct Hands {};
    struct Shoulders {};
    struct Backpack {};
    struct Rings {};
    struct Necklace {};
    struct Equipment {};
    struct Flasks {};
    struct Health {};
    struct Magic {};
    struct Movement {};
    struct Resistance {};
    struct Ammo {};
    struct Quivers {};
    struct Magazines {};
    struct Grenades {};
    struct Rockets {};
    struct Mines {};
    struct Scrolls {};
    struct Buildings {};
    struct Crafting {};
    struct Maps {};
    struct MapChisel {};
    struct Crystals {};
    struct Cards {};
    struct Orbs {};
    struct OrbOfIdentifying {};
    struct OrbOfErasing {};
    struct OrbOfForging {};
    struct OrbOfChaos {};
    struct OrbOfDivinity {};
    struct OrbOfInvigorating {};
    struct OrbOfEnforing {};
    struct OrbOfModifying {};
    struct OrbOfEnhancing {};
    struct OrbOfChange {};
    struct OrbOfMirroring {};

    Item(flecs::world& world) 
    {
        world.module<Item>();

        world.component<ItemStaging>();
        world.component<ItemSpawning>();
        world.component<ItemTypeCreation>();
        world.component<ItemRarity>();
        world.component<ItemQuality>();
        world.component<ItemMaterial>();
        world.component<ItemManufacturer>();
        world.component<ItemLevel>();
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
        world.component<Weapons>();
        world.component<Melee> ();
        world.component<Ranged> ();
        world.component<OneHanded> ();
        world.component<TwoHanded> ();
        world.component<ShortSword> ();
        world.component<Mace> ();
        world.component<Knife> ();
        world.component<Warhammer> ();
        world.component<Axe> ();
        world.component<Shield> ();
        world.component<Rapier> ();
        world.component<Club> ();
        world.component<LongSword> ();
        world.component<Halberd> ();
        world.component<Staff> ();
        world.component<Spear> ();
        world.component<Claws> ();
        world.component<Wand> ();
        world.component<Thrown> ();
        world.component<Pistol> ();
        world.component<HandCannon> ();
        world.component<Revolver> ();
        world.component<HandCrossbow> ();
        world.component<Bow>();
        world.component<Crossbow>();
        world.component<Carbine>();
        world.component<AssaultRifle>();
        world.component<SniperRifle>();
        world.component<LightMachineGun>();
        world.component<SubMachineGun>();
        world.component<Shotgun>();
        world.component<GrenadeLauncher>();
        world.component<RocketLauncher>();
        world.component<Armour>();
        world.component<PowerArmour>();
        world.component<LightPowerArmour>();
        world.component<MediumPowerArmour>();
        world.component<HeavyPowerArmour>();
        world.component<NonPowerArmour>();
        world.component<Cloths>();
        world.component<Head>();
        world.component<Belt>();
        world.component<Chests>();
        world.component<Legs>();
        world.component<Arms>();
        world.component<Hands>();
        world.component<Shoulders>();
        world.component<Backpack>();
        world.component<Rings>();
        world.component<Necklace>();
        world.component<Equipment>();
        world.component<Flasks>();
        world.component<Health>();
        world.component<Magic>();
        world.component<Movement>();
        world.component<Resistance>();
        world.component<Ammo>();
        world.component<Quivers>();
        world.component<Magazines>();
        world.component<Grenades>();
        world.component<Rockets>();
        world.component<Mines>();
        world.component<Scrolls>();
        world.component<Buildings>();
        world.component<Crafting>();
        world.component<Maps>();
        world.component<MapChisel>();
        world.component<Crystals>();
        world.component<Cards>();
        world.component<Orbs>();
        world.component<OrbOfIdentifying>();
        world.component<OrbOfErasing>();
        world.component<OrbOfForging>();
        world.component<OrbOfChaos>();
        world.component<OrbOfDivinity>();
        world.component<OrbOfInvigorating>();
        world.component<OrbOfEnforing>();
        world.component<OrbOfModifying>();
        world.component<OrbOfEnhancing>();
        world.component<OrbOfChange>();
        world.component<OrbOfMirroring>();

        world.system<ItemSpawning>("CreateItemEntity").iter(CreateItemEntity);

        world.system<ItemStaging>("SettingSeedForRandomItemEntitiesGeneration").iter(SettingSeedForRandomItemEntitiesGeneration);

        world.system<ItemStaging>("AddItemTypeComponentstoEntity").iter(AddItemTypeComponentstoEntity);

        world.system<ItemStaging>("AddItemComponentstoEntity").iter(AddItemComponentstoEntity);

        world.system<ItemStaging, ItemTypeCreation, ItemRarity>("CreatingRarityModComponentsToEntity").iter(CreatingRarityModComponentsToEntity);

        world.system<ItemStaging>("RemovingItemStagingComponentsFromEntity").iter(RemovingItemStagingComponentsFromEntity);
    }
    static void CreateItemEntity(const flecs::iter& iter, ItemSpawning* is );
    static void AddItemTypeComponentstoEntity(const flecs::iter& iter, ItemStaging* iss);
    static void AddItemComponentstoEntity(const flecs::iter& iter, ItemStaging* iss);
    static void SettingSeedForRandomItemEntitiesGeneration(const flecs::iter& iter, ItemStaging* iss);
    static void CreatingRarityComponentsToEntity(const flecs::iter& iter, ItemStaging* iss, ItemRarity* ir);
    static void CreatingRarityModComponentsToEntity(const flecs::iter& iter, ItemStaging* iss, ItemTypeCreation* isc, ItemRarity* ir);
    
    static void RemovingItemStagingComponentsFromEntity(const flecs::iter& iter, ItemStaging* iss);

   

private:
    static inline std::mt19937 CreatingSeedForRandom32BitNumber();
    static inline int CreatingSeed();
    static inline int CreatingRandom32BitIntNumbers(int seed, int min, int max);
    static inline float CreatingRandom32BitFloatNumbers(int seed, float min, float max);
    static inline void CreatingEquipableItems(const flecs::iter& iter, size_t i, int seed);
    static inline void CreatingBaseItemEquipableStats(const flecs::iter& iter, size_t i, int seed);
    static inline void CreatingMeleeWeaponComponentsToEntity(const flecs::iter& iter, size_t i, int seed);
    static inline void CreatingRangeWeaponComponentstoEntity(const flecs::iter& iter, size_t i, int seed);
    static inline void CreatingPowerArmourComponentsToEntity(const flecs::iter& iter, size_t i, int seed);
    static inline ItemQualityConfig GetConfigItemQualityData(float ItemQualitySpawnChance);
    static inline ItemRarityConfig GetConfigItemRarityData(float ItemRaritySpawnChance);
    static inline ItemMaterialConfig GetConfigItemMaterialData(float ItemMaterialSpawnChance);
    static inline ItemManufacturerConfig GentConfigItemManufacturerData(int ItemManufacturerSpawnChance);
    static inline ItemBaseTypeConfig GetConfigItemTypeData(float ItemBaseSpawnChance);
    
    static inline void CreatingOneHandedMeleeWeaponItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingOneHandedMeleeWeaponShortSwordItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingOneHandedMeleeWeaponMaceItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingOneHandedMeleeWeaponKnifeItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingOneHandedMeleeWeaponWarhammerItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingOneHandedMeleeWeaponAxeItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingOneHandedMeleeWeaponShieldItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingOneHandedMeleeWeaponRapierItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingOneHandedMeleeWeaponClubItems(const flecs::iter& iter, size_t i, int randomRarity);
    
    static inline void CreatingTwoHandedMeleeWeaponItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingTwoHandedMeleeWeaponLongSwordItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingTwoHandedMeleeWeaponMaceItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingTwoHandedMeleeWeaponWarhammerItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingTwoHandedMeleeWeaponHalberdItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingTwoHandedMeleeWeaponAxeItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingTwoHandedMeleeWeaponClubItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingTwoHandedMeleeWeaponStaffItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingTwoHandedMeleeWeaponSpearItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingTwoHandedMeleeWeaponClawsItems(const flecs::iter& iter, size_t i, int randomRarity);

    static inline void CreatingOneHandedRangedWeaponItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingOneHandedRangedWeaponWandItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingOneHandedRangedWeaponThrownItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingOneHandedRangedWeaponPistolItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingOneHandedRangedWeaponRevolverItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingOneHandedRangedWeaponHandCrossbowItems(const flecs::iter& iter, size_t i, int randomRarity);

    static inline void CreatingTwoHandedRangedWeaponItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingTwoHandedRangedWeaponBowItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingTwoHandedRangedWeaponCrossbowItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingTwoHandedRangedWeaponCarbineItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingTwoHandedRangedWeaponAssaultRifleItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingTwoHandedRangedWeaponSniperRifleItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingTwoHandedRangedWeaponLightMachineGunItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingTwoHandedRangedWeaponSubMachineGunItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingTwoHandedRangedWeaponShotgunItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingTwoHandedRangedWeaponGrenadeLauncherItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingTwoHandedRangedWeaponRocketLauncherItems(const flecs::iter& iter, size_t i, int randomRarity);

    static inline void CreatingArmourPowerArmourLightItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourPowerArmourLightHeadItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourPowerArmourLightBeltItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourPowerArmourLightChestItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourPowerArmourLightLegsItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourPowerArmourLightArmsItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourPowerArmourLightHandsItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourPowerArmourLightShouldersItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourPowerArmourLightBackpackItems(const flecs::iter& iter, size_t i, int randomRarity);

    static inline void CreatingArmourPowerArmourMediumItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourPowerArmourMediumHeadItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourPowerArmourMediumBeltItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourPowerArmourMediumChestItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourPowerArmourMediumLegsItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourPowerArmourMediumArmsItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourPowerArmourMediumHandsItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourPowerArmourMediumShouldersItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourPowerArmourMediumBackpackItems(const flecs::iter& iter, size_t i, int randomRarity);

    static inline void CreatingArmourPowerArmourHeavyItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourPowerArmourHeavyHeadItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourPowerArmourHeavyBeltItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourPowerArmourHeavyChestItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourPowerArmourHeavyLegsItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourPowerArmourHeavyArmsItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourPowerArmourHeavyHandsItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourPowerArmourHeavyShouldersItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourPowerArmourHeavyBackpackItems(const flecs::iter& iter, size_t i, int randomRarity);

    static inline void CreatingArmourNonPowerArmourItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourNonPowerArmourHeadItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourNonPowerArmourBeltItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourNonPowerArmourChestItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourNonPowerArmourLegsItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourNonPowerArmourArmsItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourNonPowerArmourHandsItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourNonPowerArmourShouldersItems(const flecs::iter& iter, size_t i, int randomRarity);
    static inline void CreatingArmourNonPowerArmourBackpackItems(const flecs::iter& iter, size_t i, int randomRarity);

    static inline void CreatingArmourClothsItems(const flecs::iter& iter, size_t i);
    static inline void CreatingArmourClothsHeadItems(const flecs::iter& iter, size_t i);
    static inline void CreatingArmourClothsBeltItems(const flecs::iter& iter, size_t i);
    static inline void CreatingArmourClothsChestItems(const flecs::iter& iter, size_t i);
    static inline void CreatingArmourClothsLegsItems(const flecs::iter& iter, size_t i);
    static inline void CreatingArmourClothsArmsItems(const flecs::iter& iter, size_t i);
    static inline void CreatingArmourClothsHandsItems(const flecs::iter& iter, size_t i);
    static inline void CreatingArmourClothsShouldersItems(const flecs::iter& iter, size_t i);
    static inline void CreatingArmourClothsBackpackItems(const flecs::iter& iter, size_t i);

    static inline void CreatingEquipmentFlasks(const flecs::iter& iter, size_t i);
    static inline void CreatingEquipmentFlasksHealth(const flecs::iter& iter, size_t i);
    static inline void CreatingEquipmentFlasksMagic(const flecs::iter& iter, size_t i);
    static inline void CreatingEquipmentFlasksMovement(const flecs::iter& iter, size_t i);
    static inline void CreatingEquipmentFlasksResistance(const flecs::iter& iter, size_t i);

    static inline void CreatingEquipmentAmmo(const flecs::iter& iter, size_t i);
    static inline void CreatingEquipmentAmmoQuivers(const flecs::iter& iter, size_t i);
    static inline void CreatingEquipmentAmmoMagazines(const flecs::iter& iter, size_t i);
    static inline void CreatingEquipmentAmmoGrenades(const flecs::iter& iter, size_t i);
    static inline void CreatingEquipmentAmmoRockets(const flecs::iter& iter, size_t i);
    static inline void CreatingEquipmentAmmoMines(const flecs::iter& iter, size_t i);
    
    static inline void CreatingCraftingMaps(const flecs::iter& iter, size_t i);
    static inline void CreatingCraftingMapChisel(const flecs::iter& iter, size_t i);
    static inline void CreatingCraftingCrystals(const flecs::iter& iter, size_t i);
    static inline void CreatingCraftingCards(const flecs::iter& iter, size_t i);
    static inline void CreatingCraftingOrbs(const flecs::iter& iter, size_t i);

};
#endif
