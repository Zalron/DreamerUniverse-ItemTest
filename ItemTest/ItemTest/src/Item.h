#pragma once
#ifndef ITEM_H
#define ITEM_H

#include <cstdint>
#include <cstdlib>
#include "flecs.h"
#include "ItemConfig.h"
#include "ItemComponents.h"
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

        world.system<ItemComponents::ItemStaging>("AddItemComponentstoEntity").iter(AddItemComponentstoEntity);

        //world.system<ItemComponents::ItemBase, ItemComponents::ItemStaging, ItemComponents::ItemRarity>("CreatingRarityModComponentsToEntity").iter(CreatingRarityModComponentsToEntity);

    }

    static void CreateItemEntity(const flecs::iter& iter, ItemComponents::ItemSpawning* is);
    static void AddItemComponentstoEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss);
    
    static void SettingSeedForRandomItemEntitiesGeneration(const flecs::iter& iter, ItemComponents::ItemStaging* iss);
    
    //static void CreatingRarityModComponentsToEntity(const flecs::iter& iter, ItemComponents::ItemBase* ib, ItemComponents::ItemStaging* iss, ItemComponents::ItemRarity* ir);

private:
    static inline int CreatingSeed();
    static inline int CreatingRandom32BitIntNumbers(int seed, int min, int max);
    static inline float CreatingRandom32BitFloatNumbers(int seed, float min, float max);
    static inline int CalculatingFinalItemStatRollInt(int itemRoll, int rarityRoll, int qualityRoll, int materialRoll, int manufacturerRoll,
        int itemPart1, int itemPart2, int itemPart3, int itemPart4, int itemPart5, int itemPart6, int itemPart7, int itemPart8, int itemPart9, int itemPart10,
        int itemAffixMods1, int itemAffixMods2, int itemAffixMods3, int itemAffixMods4, int itemAffixMods5, int itemAffixMods6, int itemAffixMods7, int itemAffixMods8, int itemAffixMods9, int itemAffixMods10);
    static inline float CalculatingFinalItemStatRollFloat(float itemRoll, float rarityRoll, float qualityRoll, float materialRoll, float manufacturerRoll,
        float  itemPart1, float itemPart2, float itemPart3, float itemPart4, float itemPart5, float itemPart6, float itemPart7, float itemPart8, float itemPart9, float itemPart10,
        float itemAffixMods1, float itemAffixMods2, float itemAffixMods3, float itemAffixMods4, float itemAffixMods5, float itemAffixMods6, float itemAffixMods7, float itemAffixMods8, float itemAffixMods9, float itemAffixMods10);


};
#endif
