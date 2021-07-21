#pragma once
#ifndef ITEM_H
#define ITEM_H

#include <cstdint>
#include <cstdlib>
#include "flecs.h"
#include "ItemConfig.h"
#include "ItemComponents.h"
#include <flecs_os_api_stdcpp.h>
#include <random>
#include <iostream>
using namespace std;


struct Item
{
public:

    Item(flecs::world& world) 
    {
        world.import<ItemComponents>();
        world.module<Item>();

        world.system<ItemComponents::ItemSpawning>("CreateItemEntity").iter(CreateItemEntity);

        world.system<ItemComponents::ItemStaging>("SettingSeedForRandomItemEntitiesGeneration").iter(SettingSeedForRandomItemEntitiesGeneration);

        world.system<ItemComponents::ItemStaging, ItemComponents::ItemCharacterLevelRequirements, ItemComponents::ItemRarity, ItemComponents::ItemQuality, ItemComponents::ItemMaterial, ItemComponents::ItemManufacturer>("AddItemStatComponentsToEntity").iter(AddItemStatComponentsToEntity);

        world.system<ItemComponents::ItemStaging, ItemComponents::CriticalChanceItemStat, ItemComponents::MagicalDamageItemStat, ItemComponents::PhysicalDamageItemStat, ItemComponents::HandlingItemStat, ItemComponents::AccuracyItemStat, ItemComponents::RangeItemStat, ItemComponents::GuardItemStat, ItemComponents::BlockChanceItemStat, ItemComponents::AttackRateItemStat, ItemComponents::WeightItemStat>("AllItemMeleeTagComponentsToEntity").iter(AllItemMeleeTagComponentsToEntity);

        world.system<ItemComponents::ItemStaging, ItemComponents::CriticalChanceItemStat, ItemComponents::MagicalDamageItemStat, ItemComponents::PhysicalDamageItemStat, ItemComponents::HandlingItemStat, ItemComponents::AccuracyItemStat, ItemComponents::RangeItemStat, ItemComponents::MagazineSizeItemStat, ItemComponents::ReloadTimeItemStat, ItemComponents::FireRateItemStat, ItemComponents::WeightItemStat>("AllItemRangedTagComponentsToEntity").iter(AllItemRangedTagComponentsToEntity);

        world.system<ItemComponents::ItemStaging, ItemComponents::ArmourItemStat, ItemComponents::ArmourRechargeRateItemStat, ItemComponents::ArmourRechargeDelayItemStat, ItemComponents::ShieldItemStat, ItemComponents::ShieldRechargeRateItemStat, ItemComponents::ShieldRechargeDelayItemStat, ItemComponents::EnergyItemStat, ItemComponents::EnergyRechargeRateItemStat, ItemComponents::EnergyRechargeDelayItemStat, ItemComponents::WeightItemStat>("AllItemArmourTagComponentsToEntity").iter(AllItemArmourTagComponentsToEntity);

        world.system<ItemComponents::ItemStaging>("AddItemComponentstoEntity").iter(AddItemComponentstoEntity);

        world.system<ItemComponents::ItemStaging, ItemComponents::ItemRarity>("CreatingRarityModComponentsToEntity").iter(CreatingRarityModComponentsToEntity);

        world.system<ItemComponents::ItemStaging, ItemComponents::ItemRarity>("CreatingRarityComponentsToEntity").iter(CreatingRarityComponentsToEntity);

        world.system<ItemComponents::ItemStaging, ItemComponents::ItemQuality>("CreatingQualityComponentToEntity").iter(CreatingQualityComponentToEntity);

        world.system<ItemComponents::ItemStaging>("RemovingItemStagingComponentsFromEntity").iter(RemovingItemStagingComponentsFromEntity);
    }
    static void CreateItemEntity(const flecs::iter& iter, ItemComponents::ItemSpawning* is );
    static void AddItemComponentstoEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss);
    static void AddItemStatComponentsToEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss, ItemComponents::ItemCharacterLevelRequirements* iclr, ItemComponents::ItemRarity* ir, ItemComponents::ItemQuality* iq, ItemComponents::ItemMaterial* im, ItemComponents::ItemManufacturer* imu);
    static void AllItemMeleeTagComponentsToEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss, ItemComponents::CriticalChanceItemStat* ccis, ItemComponents::MagicalDamageItemStat* msis, ItemComponents::PhysicalDamageItemStat* pdis, ItemComponents::HandlingItemStat* his, ItemComponents::AccuracyItemStat* ais, ItemComponents::RangeItemStat* ris, ItemComponents::GuardItemStat* gis, ItemComponents::BlockChanceItemStat* dcis, ItemComponents::AttackRateItemStat* aris, ItemComponents::WeightItemStat* wis);
    static void AllItemRangedTagComponentsToEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss, ItemComponents::CriticalChanceItemStat* ccis, ItemComponents::MagicalDamageItemStat* msis, ItemComponents::PhysicalDamageItemStat* pdis, ItemComponents::HandlingItemStat* his, ItemComponents::AccuracyItemStat* ais, ItemComponents::RangeItemStat* ris, ItemComponents::MagazineSizeItemStat* gis, ItemComponents::ReloadTimeItemStat* dcis, ItemComponents::FireRateItemStat* fris, ItemComponents::WeightItemStat* wis);
    static void AllItemArmourTagComponentsToEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss, ItemComponents::ArmourItemStat* ais, ItemComponents::ArmourRechargeRateItemStat* arris, ItemComponents::ArmourRechargeDelayItemStat *ardis, ItemComponents::ShieldItemStat* sis, ItemComponents::ShieldRechargeRateItemStat* srris, ItemComponents::ShieldRechargeDelayItemStat* srdis, ItemComponents::EnergyItemStat* eis, ItemComponents::EnergyRechargeRateItemStat* erris, ItemComponents::EnergyRechargeDelayItemStat* erdis, ItemComponents::WeightItemStat* wis);
    static void SettingSeedForRandomItemEntitiesGeneration(const flecs::iter& iter, ItemComponents::ItemStaging* iss);
    static void CreatingRarityComponentsToEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss, ItemComponents::ItemRarity* ir);
    static void CreatingRarityModComponentsToEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss, ItemComponents::ItemRarity* ir);
    static void CreatingQualityComponentToEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss, ItemComponents::ItemQuality* iq);
    static void CreatingMaterialComponentToEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss, ItemComponents::ItemMaterial* iq);
    static void CreatingManufacturerComponentToEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss, ItemComponents::ItemManufacturer* iq);
    
    static void RemovingItemStagingComponentsFromEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss);

private:
    static inline std::mt19937 CreatingSeedForRandom32BitNumber();
    static inline int CreatingSeed();
    static inline int CreatingRandom32BitIntNumbers(int seed, int min, int max);
    static inline float CreatingRandom32BitFloatNumbers(int seed, float min, float max);

    static inline ItemRarityConfig GetConfigItemRarityData(float ItemRaritySpawnChance);
    static inline ItemMaterialConfig GetConfigItemMaterialData(float ItemMaterialSpawnChance);
    static inline ItemManufacturerConfig GentConfigItemManufacturerData(int ItemManufacturerSpawnChance);
    //static inline ItemBaseTypeConfig GetConfigItemTypeData(float ItemBaseSpawnChance);

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
