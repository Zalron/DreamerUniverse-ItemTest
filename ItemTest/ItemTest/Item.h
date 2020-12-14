#pragma once
#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <cstdint>
#include "flecs.h"

using namespace std;

struct ItemTypeCreation
{
    int ItemTypeint;
    int BaseIntStatRoll;
    float BaseFloatStatRoll;
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
struct Revolver {};
struct HandCrossbow {};
struct Bow {};
struct Crossbow {};
struct Carbine {};
struct AssaultRifle {};
struct SniperRifle {};
struct LightMachineGun {};
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
struct Quivers {};
struct Magazines {};
struct Grenades {};
struct Scrolls {};
struct Mines {};
struct Buildings {};
struct Crafting {};

enum ItemTypeEnum
{
    WeaponMeleeOneHandedMace,
    WeaponMeleeOneHandedKnife,
    WeaponMeleeOneHandedWarhammer,
    WeaponMeleeOneHandedAxe,
    WeaponMeleeOneHandedShield,
    WeaponMeleeOneHandedRapier,
    WeaponMeleeOneHandedClub,
    WeaponMeleeTwoHandedLongSword,
    WeaponMeleeTwoHandedHalberd,
    WeaponMeleeTwoHandedStaff,
    WeaponMeleeTwoHandedSpear,
    WeaponMeleeTwoHandedClaws,
    WeaponRangedOneHandedWand,
    WeaponRangedOneHandedThrowingKnifes,
    WeaponRangedOneHandedThrowingAxes,
    WeaponRangedOneHandedPistol,
    WeaponRangedOneHandedRevolver,
    WeaponRangedOneHandedHandCrossbow,
    WeaponRangedTwoHandedBow,
    WeaponRangedTwoHandedCrossBow,
    WeaponRangedTwoHandedCarbine,
    WeaponRangedTwoHandedAssaultRifle,
    WeaponRangedTwoHandedSniperRifle,
    WeaponRangedTwoHandedLightMachineGun,
    WeaponRangedTwoHandedShotgun,
    WeaponRangedTwoHandedGrenadeLauncher,
    WeaponRangedTwoHandedRocketLauncher,
    ArmourPowerArmourLightHead,
    ArmourPowerArmourLightBelt,
    ArmourPowerArmourLightChest,
    ArmourPowerArmourLightLegs,
    ArmourPowerArmourLightArms,
    ArmourPowerArmourLightHands,
    ArmourPowerArmourLightShoulders,
    ArmourPowerArmourLightBackpack,
    ArmourPowerArmourMediumHead,
    ArmourPowerArmourMediumBelt,
    ArmourPowerArmourMediumChest,
    ArmourPowerArmourMediumLegs,
    ArmourPowerArmourMediumArms,
    ArmourPowerArmourMediumHands,
    ArmourPowerArmourMediumShoulders,
    ArmourPowerArmourMediumBackpack,
    ArmourPowerArmourHeavyHead,
    ArmourPowerArmourHeavyBelt,
    ArmourPowerArmourHeavyChest,
    ArmourPowerArmourHeavyLegs,
    ArmourPowerArmourHeavyArms,
    ArmourPowerArmourHeavyHands,
    ArmourPowerArmourHeavyShoulders,
    ArmourPowerArmourHeavyBackpack,
    ArmourNonPowerArmourHead,
    ArmourNonPowerArmourBelt,
    ArmourNonPowerArmourChest,
    ArmourNonPowerArmourLegs,
    ArmourNonPowerArmourArms,
    ArmourNonPowerArmourHands,
    ArmourNonPowerArmourShoulders,
    ArmourNonPowerArmourBackpack,
    ArmourClothsArmourHead,
    ArmourClothsArmourBelt,
    ArmourClothsArmourChest,
    ArmourClothsArmourLegs,
    ArmourClothsArmourArms,
    ArmourClothsArmourHands,
    ArmourClothsArmourShoulders,
    ArmourClothsArmourBackpack,
    EquipmentFlasksHealth,
    EquipmentFlasksMagic,
    EquipmentFlasksMovement,
    EquipmentFlasksResistance,
    EquipmentAmmoQuivers,
    EquipmentAmmoMagazines,
    EquipmentAmmoGrenades,
    EquipmentAmmoRockets,
    EquipmentAmmoMines,
    EquipmentScrolls,
    EquipmentSpells,
    Buildings,
    Crafting
};

class Item
{
public:
    static void CreateItemEntity(flecs::iter& iter, ItemSpawning* is );
    static void AddComponentstoEntity(flecs::iter& iter, ItemStaging* iss);

private:
    static inline void CreatingOneHandedMeleeWeaponShortSwordItems(flecs::iter& iter, int i);
    static inline void CreatingTwoHandedMeleeWeaponItems(flecs::iter& iter, int i);
    static inline void CreatingOneHandedRangedWeaponItems(flecs::iter& iter, int i);
    static inline void CreatingTwoHandedRangedWeaponItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourLightItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourMediumItems(flecs::iter& iter, int i);
    static inline void CreatingArmourPowerArmourHeavyItems(flecs::iter& iter, int i);
    static inline void CreatingArmourNonPowerArmourItems(flecs::iter& iter, int i);
    static inline void CreatingArmourClothsItems(flecs::iter& iter, int i);
};
#endif
