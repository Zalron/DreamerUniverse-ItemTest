#pragma once
#include "flecs.h"
#include <cstring>

struct ItemConfigComponents
{
    struct ItemBaseConfig
    {
        int BaseTypeID;
    };

    struct ItemRarityConfig
    {
        int RarityLevel;
        int RarityAffixAllowance;
        int RaritySpawnChanceMin;
        int RaritySpawnChanceMax;
    };

    struct ItemAffixModsConfig
    {
        int ModId;
        bool OrPrefixSuffix; // 0 = Prefix 1 = Suffix
    };

    struct ItemManufacturerConfig
    {
        int ManufacturerType;
    };

    struct ItemMaterialConfig
    {
        int MaterialType;
        int MaterialChanceMin;
        int MaterialChanceMax;

    };

    struct ItemQualityConfig
    {
        int QualitySpawnChanceMin;
        int QualitySpawnChanceMax;
        int QualityNum;
    };

    struct ItemPartsConfig
    {
        int PartsType;
        int PartsChanceMin;
        int PartsChanceMax;
    };

    struct ItemStatConfig 
    {
        int StatType;
        int StatIntRollMin;
        int StatIntRollMax;
    };

    struct ItemComponentsConfig
    {
        int ItemComponentType{};
    };

    struct ItemWeaponMeleeOneHandedSwordTags
    {
        flecs::entity EquipableItemTag;
        flecs::entity WeaponsItemTag;
        flecs::entity MeleeItemTag;
        flecs::entity OneHandedItemTag;
        flecs::entity SwordItemTag;
    };

    struct ItemWeaponMeleeOneHandedMaceTags
    {
        flecs::entity EquipableItemTag;
        flecs::entity WeaponsItemTag;
        flecs::entity MeleeItemTag;
        flecs::entity OneHandedItemTag;
        flecs::entity SwordItemTag;
    };

    struct ItemWeaponMeleeOneHandedKnifeTags
    {
        flecs::entity EquipableItemTag;
        flecs::entity WeaponsItemTag;
        flecs::entity MeleeItemTag;
        flecs::entity OneHandedItemTag;
        flecs::entity KnifeItemTag;
    };

    struct ItemWeaponMeleeOneHandedWarhammerTags
    {
        flecs::entity EquipableItemTag;
        flecs::entity WeaponsItemTag;
        flecs::entity MeleeItemTag;
        flecs::entity OneHandedItemTag;
        flecs::entity WarhammerItemTag;
    };

    struct ItemWeaponMeleeOneHandedAxeTags
    {
        flecs::entity EquipableItemTag;
        flecs::entity WeaponsItemTag;
        flecs::entity MeleeItemTag;
        flecs::entity OneHandedItemTag;
        flecs::entity AxeItemTag;
    };

    struct ItemWeaponMeleeOneHandedShieldTags
    {
        flecs::entity EquipableItemTag;
        flecs::entity WeaponsItemTag;
        flecs::entity MeleeItemTag;
        flecs::entity OneHandedItemTag;
        flecs::entity ShieldItemTag;
    };

    struct ItemWeaponMeleeOneHandedRapierTags
    {
        flecs::entity EquipableItemTag;
        flecs::entity WeaponsItemTag;
        flecs::entity MeleeItemTag;
        flecs::entity OneHandedItemTag;
        flecs::entity RapierItemTag;
    };

    struct ItemTagConfig
    {
        int8_t ItemTagId;
        ItemWeaponMeleeOneHandedSwordTags ItemWeaponMeleeOneHandedSwordTagsConfig;
        ItemWeaponMeleeOneHandedMaceTags ItemWeaponMeleeOneHandedMaceTagsConfig;
        ItemWeaponMeleeOneHandedKnifeTags ItemWeaponMeleeOneHandedKnifeTagsConfig;
        ItemWeaponMeleeOneHandedWarhammerTags ItemWeaponMeleeOneHandedWarhammerTagsConfig;
        ItemWeaponMeleeOneHandedAxeTags ItemWeaponMeleeOneHandedAxeTagsConfig;
        ItemWeaponMeleeOneHandedShieldTags ItemWeaponMeleeOneHandedShieldTagsConfig;
        ItemWeaponMeleeOneHandedRapierTags ItemWeaponMeleeOneHandedRapierTagsConfig;
    };

    struct StandardItemBaseRollTable
    {
        ItemRarityConfig rarityRollTable[11];

        ItemQualityConfig qualityRollTable[21];

        ItemMaterialConfig materialRollTable[10];

        ItemManufacturerConfig manufacturerRollTable[6];
    };

    struct ItemPartRollTable 
    {
        ItemPartsConfig partRollTable1[10];
        ItemPartsConfig partRollTable2[10];
        ItemPartsConfig partRollTable3[10];
        ItemPartsConfig partRollTable4[10];
        ItemPartsConfig partRollTable5[10];
        ItemPartsConfig partRollTable6[10];
        ItemPartsConfig partRollTable7[10];
        ItemPartsConfig partRollTable8[10];
        ItemPartsConfig partRollTable9[10];
        ItemPartsConfig partRollTable10[10];
    };

    struct ItemModRolltable
    {
        ItemAffixModsConfig modsRollTable1[10];
        ItemAffixModsConfig modsRollTable2[10];
        ItemAffixModsConfig modsRollTable3[10];
        ItemAffixModsConfig modsRollTable4[10];
        ItemAffixModsConfig modsRollTable5[10];
        ItemAffixModsConfig modsRollTable6[10];
        ItemAffixModsConfig modsRollTable7[10];
        ItemAffixModsConfig modsRollTable8[10];
        ItemAffixModsConfig modsRollTable9[10];
        ItemAffixModsConfig modsRollTable10[10];
    };

    struct ConfigStage 
    {
        uint8_t stage;
    };

    explicit ItemConfigComponents(flecs::world& world)
    {
        world.module<ItemConfigComponents>();

        world.component<ItemBaseConfig>();
        world.component<ItemRarityConfig>();
        world.component<ItemAffixModsConfig>();
        world.component<ItemManufacturerConfig>();
        world.component<ItemMaterialConfig>();
        world.component<ItemQualityConfig>();
        world.component<ItemPartsConfig>();
        world.component<ItemStatConfig>();
        world.component<ItemComponentsConfig>();
        world.component<ItemTagConfig>();
        world.component<ItemModRolltable>();
        world.component<StandardItemBaseRollTable>();
        world.component<ConfigStage>();
    }
};

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