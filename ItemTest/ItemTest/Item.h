#pragma once
#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <cstdint>
#include "flecs.h"
#include "ItemConfig.h"

using namespace std;

struct ItemTypeCreation
{
    int ItemTypeInt;
    int BaseIntStatRoll;
    float BaseFloatStatRoll;
};

struct ItemRarity
{
    int LevelRequirement;
    int RarityLevel;
    int RarityRoll;
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

struct ItemCharacterWillpowerhRequirements
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

struct ItemStaging
{
    int ItemStage;
    int Seed;
};

struct ItemSpawning 
{
    int NumberOfItems;
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
struct Ranged{};
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
struct ThrowingKnifes {};
struct ThrowingAxes {};
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


class Item
{
public:
    static void CreateItemEntity(flecs::iter& iter, ItemSpawning* is );
    static void AddItemTypeComponentstoEntity(flecs::iter& iter, ItemStaging* iss);
    static void AddItemComponentstoEntity(flecs::iter& iter, ItemStaging* iss, ItemTypeCreation* isc);
    

private:
    static inline void CreatingMeleeWeaponComponentsToEntity(flecs::iter& iter, int i, ItemTypeCreation* isc);
    static inline void CreatingRangeWeaponComponentstoEntity(flecs::iter& iter, int i, ItemTypeCreation* isc);

    static inline void CreatingRarityModCOmponentsToEntity(flecs::iter& iter, int i, ItemStaging* iss, ItemTypeCreation* isc, ItemRarity* ir);

    static inline void CreatingOneHandedMeleeWeaponItems(flecs::iter& iter, int i);
    static inline void CreatingOneHandedMeleeWeaponShortSwordItems(flecs::iter& iter, int i);
    static inline void CreatingOneHandedMeleeWeaponMaceItems(flecs::iter& iter, int i);
    static inline void CreatingOneHandedMeleeWeaponKnifeItems(flecs::iter& iter, int i);
    static inline void CreatingOneHandedMeleeWeaponWarhammerItems(flecs::iter& iter, int i);
    static inline void CreatingOneHandedMeleeWeaponAxeItems(flecs::iter& iter, int i);
    static inline void CreatingOneHandedMeleeWeaponShieldItems(flecs::iter& iter, int i);
    static inline void CreatingOneHandedMeleeWeaponRapierItems(flecs::iter& iter, int i);
    static inline void CreatingOneHandedMeleeWeaponClubItems(flecs::iter& iter, int i);
    
    static inline void CreatingTwoHandedMeleeWeaponItems(flecs::iter& iter, int i);
    static inline void CreatingTwoHandedMeleeWeaponLongSwordItems(flecs::iter& iter, int i);
    static inline void CreatingTwoHandedMeleeWeaponMaceItems(flecs::iter& iter, int i);
    static inline void CreatingTwoHandedMeleeWeaponWarhammerItems(flecs::iter& iter, int i);
    static inline void CreatingTwoHandedMeleeWeaponHalberdItems(flecs::iter& iter, int i);
    static inline void CreatingTwoHandedMeleeWeaponAxeItems(flecs::iter& iter, int i);
    static inline void CreatingTwoHandedMeleeWeaponClubItems(flecs::iter& iter, int i);
    static inline void CreatingTwoHandedMeleeWeaponStaffItems(flecs::iter& iter, int i);
    static inline void CreatingTwoHandedMeleeWeaponSpearItems(flecs::iter& iter, int i);
    static inline void CreatingTwoHandedMeleeWeaponClawsItems(flecs::iter& iter, int i);

    static inline void CreatingOneHandedRangedWeaponItems(flecs::iter& iter, int i);
    static inline void CreatingOneHandedRangedWeaponWandItems(flecs::iter& iter, int i);
    static inline void CreatingOneHandedRangedWeaponThrowingKnifeItems(flecs::iter& iter, int i);
    static inline void CreatingOneHandedRangedWeaponThrowingAxesItems(flecs::iter& iter, int i);
    static inline void CreatingOneHandedRangedWeaponPistolItems(flecs::iter& iter, int i);
    static inline void CreatingOneHandedRangedWeaponHandCannonItems(flecs::iter& iter, int i);
    static inline void CreatingOneHandedRangedWeaponRevolverItems(flecs::iter& iter, int i);
    static inline void CreatingOneHandedRangedWeaponHandCrossbowItems(flecs::iter& iter, int i);

    static inline void CreatingTwoHandedRangedWeaponItems(flecs::iter& iter, int i);
    static inline void CreatingTwoHandedRangedWeaponBowItems(flecs::iter& iter, int i);
    static inline void CreatingTwoHandedRangedWeaponCrossbowItems(flecs::iter& iter, int i);
    static inline void CreatingTwoHandedRangedWeaponCarbineItems(flecs::iter& iter, int i);
    static inline void CreatingTwoHandedRangedWeaponAssaultRifleItems(flecs::iter& iter, int i);
    static inline void CreatingTwoHandedRangedWeaponSniperRifleItems(flecs::iter& iter, int i);
    static inline void CreatingTwoHandedRangedWeaponLightMachineGunItems(flecs::iter& iter, int i);
    static inline void CreatingTwoHandedRangedWeaponSubMachineGunItems(flecs::iter& iter, int i);
    static inline void CreatingTwoHandedRangedWeaponShotgunItems(flecs::iter& iter, int i);
    static inline void CreatingTwoHandedRangedWeaponGrenadeLauncherItems(flecs::iter& iter, int i);
    static inline void CreatingTwoHandedRangedWeaponRocketLauncherItems(flecs::iter& iter, int i);

    static inline void CreatingArmourPowerArmourLightItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourLightHeadItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourLightBeltItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourLightChestItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourLightLegsItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourLightArmsItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourLightHandsItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourLightShouldersItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourLightBackpackItems(flecs::iter& iter, int i);

    static inline void CreatingArmourPowerArmourMediumItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourMediumHeadItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourMediumBeltItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourMediumChestItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourMediumLegsItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourMediumArmsItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourMediumHandsItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourMediumShouldersItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourMediumBackpackItems(flecs::iter& iter, int i);

    static inline void CreatingArmourPowerArmourHeavyItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourHeavyHeadItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourHeavyBeltItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourHeavyChestItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourHeavyLegsItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourHeavyArmsItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourHeavyHandsItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourHeavyShouldersItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourHeavyBackpackItems(flecs::iter& iter, int i);

    static inline void CreatingArmourNonPowerArmourItems(flecs::iter& iter, int i);
    static inline void CreatingArmourNonPowerArmourHeadItems(flecs::iter& iter, int i);
    static inline void CreatingArmourNonPowerArmourBeltItems(flecs::iter& iter, int i);
    static inline void CreatingArmourNonPowerArmourChestItems(flecs::iter& iter, int i);
    static inline void CreatingArmourNonPowerArmourLegsItems(flecs::iter& iter, int i);
    static inline void CreatingArmourNonPowerArmourArmsItems(flecs::iter& iter, int i);
    static inline void CreatingArmourNonPowerArmourHandsItems(flecs::iter& iter, int i);
    static inline void CreatingArmourNonPowerArmourShouldersItems(flecs::iter& iter, int i);
    static inline void CreatingArmourNonPowerArmourBackpackItems(flecs::iter& iter, int i);

    static inline void CreatingArmourClothsItems(flecs::iter& iter, int i);
    static inline void CreatingArmourClothsHeadItems(flecs::iter& iter, int i);
    static inline void CreatingArmourClothsBeltItems(flecs::iter& iter, int i);
    static inline void CreatingArmourClothsChestItems(flecs::iter& iter, int i);
    static inline void CreatingArmourClothsLegsItems(flecs::iter& iter, int i);
    static inline void CreatingArmourClothsArmsItems(flecs::iter& iter, int i);
    static inline void CreatingArmourClothsHandsItems(flecs::iter& iter, int i);
    static inline void CreatingArmourClothsShouldersItems(flecs::iter& iter, int i);
    static inline void CreatingArmourClothsBackpackItems(flecs::iter& iter, int i);

    static inline void CreatingEquipmentFlasks(flecs::iter& iter, int i);
    static inline void CreatingEquipmentFlasksHealth(flecs::iter& iter, int i);
    static inline void CreatingEquipmentFlasksMagic(flecs::iter& iter, int i);
    static inline void CreatingEquipmentFlasksMovement(flecs::iter& iter, int i);
    static inline void CreatingEquipmentFlasksResistance(flecs::iter& iter, int i);

    static inline void CreatingEquipmentAmmo(flecs::iter& iter, int i);
    static inline void CreatingEquipmentAmmoQuivers(flecs::iter& iter, int i);
    static inline void CreatingEquipmentAmmoMagazines(flecs::iter& iter, int i);
    static inline void CreatingEquipmentAmmoGrenades(flecs::iter& iter, int i);
    static inline void CreatingEquipmentAmmoRockets(flecs::iter& iter, int i);
    static inline void CreatingEquipmentAmmoMines(flecs::iter& iter, int i);
    
    static inline void CreatingCraftingMaps(flecs::iter& iter, int i);
    static inline void CreatingCraftingMapChisel(flecs::iter& iter, int i);
    static inline void CreatingCraftingCrystals(flecs::iter& iter, int i);
    static inline void CreatingCraftingCards(flecs::iter& iter, int i);
    static inline void CreatingCraftingOrbs(flecs::iter& iter, int i);

};
#endif
