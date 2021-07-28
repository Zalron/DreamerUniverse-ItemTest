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

        world.system<ItemComponents::ItemStaging, ItemComponents::ItemRarity>("CreatingRarityModComponentsToEntity").iter(CreatingRarityModComponentsToEntity);

    }
    static void CreateItemEntity(const flecs::iter& iter, ItemComponents::ItemSpawning* is );
    static void AddItemComponentstoEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss);
    
    static void SettingSeedForRandomItemEntitiesGeneration(const flecs::iter& iter, ItemComponents::ItemStaging* iss);
    
    static void CreatingRarityModComponentsToEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss, ItemComponents::ItemRarity* ir);

private:
    static inline int CreatingSeed();
    static inline int CreatingRandom32BitIntNumbers(int seed, int min, int max);
    static inline float CreatingRandom32BitFloatNumbers(int seed, float min, float max);

};
#endif
