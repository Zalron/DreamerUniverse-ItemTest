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

        world.system<ItemComponents::ItemStaging>("AddItemTypeComponentstoEntity").iter(AddItemTypeComponentstoEntity);

        world.system<ItemComponents::ItemStaging>("AddItemComponentstoEntity").iter(AddItemComponentstoEntity);

        world.system<ItemComponents::ItemStaging, ItemComponents::ItemTypeCreation, ItemComponents::ItemRarity>("CreatingRarityModComponentsToEntity").iter(CreatingRarityModComponentsToEntity);

        world.system<ItemComponents::ItemStaging, ItemComponents::ItemRarity>("CreatingRarityComponentsToEntity").iter(CreatingRarityComponentsToEntity);

        world.system<ItemComponents::ItemStaging, ItemComponents::ItemQuality>("CreatingQualityComponentToEntity").iter(CreatingQualityComponentToEntity);

        world.system<ItemComponents::ItemStaging>("RemovingItemStagingComponentsFromEntity").iter(RemovingItemStagingComponentsFromEntity);
    }
    static void CreateItemEntity(const flecs::iter& iter, ItemComponents::ItemSpawning* is );
    static void AddItemTypeComponentstoEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss);
    static void AddItemComponentstoEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss);
    static void SettingSeedForRandomItemEntitiesGeneration(const flecs::iter& iter, ItemComponents::ItemStaging* iss);
    static void CreatingRarityComponentsToEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss, ItemComponents::ItemRarity* ir);
    static void CreatingRarityModComponentsToEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss, ItemComponents::ItemTypeCreation* isc, ItemComponents::ItemRarity* ir);
    static void CreatingQualityComponentToEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss, ItemComponents::ItemQuality* iq);
    
    static void RemovingItemStagingComponentsFromEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss);

   

private:
    static inline std::mt19937 CreatingSeedForRandom32BitNumber();
    static inline int CreatingSeed();
    static inline int CreatingRandom32BitIntNumbers(int seed, int min, int max);
    static inline float CreatingRandom32BitFloatNumbers(int seed, float min, float max);
    static inline void CreatingBaseCraftingItem(const flecs::iter& iter, size_t i, int seed);
    static inline void CreatingEquipableItems(const flecs::iter& iter, size_t i, int seed);
    static inline void CreatingBaseItemEquipableStats(const flecs::iter& iter, size_t i, int seed);
    static inline void CreatingMeleeWeaponComponentsToEntity(const flecs::iter& iter, size_t i, int seed);
    static inline void CreatingRangeWeaponComponentstoEntity(const flecs::iter& iter, size_t i, int seed);
    static inline void CreatingPowerArmourComponentsToEntity(const flecs::iter& iter, size_t i, int seed);
    static inline ItemQualityConfig GetConfigItemQualityData(float ItemQualitySpawnChance);
    static inline ItemRarityConfig GetConfigItemRarityData(float ItemRaritySpawnChance);
    static inline ItemMaterialConfig GetConfigItemMaterialData(float ItemMaterialSpawnChance);
    static inline ItemManufacturerConfig GentConfigItemManufacturerData(int ItemManufacturerSpawnChance);
    //static inline ItemBaseTypeConfig GetConfigItemTypeData(float ItemBaseSpawnChance);

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
