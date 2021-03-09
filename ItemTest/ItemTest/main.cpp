#include "flecs.h"
#include "Item.h"
#include "ItemConfig.h"
#include <iostream>
#include <cstdint>

using namespace std;

int main(int argc, char* argv[]) 
{
    cout << "RAND_MAX value is " << RAND_MAX << endl;

    flecs::world world;

    world.entity("Item").set<ItemSpawning>({1000});

    world.system<ItemSpawning>("CreateItemEntity").iter(&Item::CreateItemEntity);

    world.system<ItemStaging, ItemSpawning>("SettingSeedForRandomItemEntitiesGeneratio").iter(&Item::SettingSeedForRandomItemEntitiesGeneration);

    world.system<ItemStaging>("AddItemTypeComponentstoEntity").iter(&Item::AddItemTypeComponentstoEntity);

    world.system<ItemStaging, ItemTypeCreation>("AddItemComponentstoEntity").iter(&Item::AddItemComponentstoEntity);

    world.system<ItemStaging, ItemTypeCreation, ItemRarity>("CreatingRarityModComponentsToEntit").iter(&Item::CreatingRarityModComponentsToEntity);

    while (world.progress()) {}
}