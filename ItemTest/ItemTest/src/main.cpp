//#include "flecs.h"
#include "Item.h"
#include "ItemConfig.h"
#include <flecs_dash.h>
#include <flecs_systems_civetweb.h>
#include <flecs_os_api_stdcpp.h>
#include <iostream>
#include <cstdint>

using namespace std;

int main(int argc, char* argv[]) 
{
    cout << "RAND_MAX value is " << RAND_MAX << endl;

    stdcpp_set_os_api();

    flecs::world world;

    world.set_threads(4);

    world.import<flecs::dash>();

    world.import<flecs::systems::civetweb>();

    world.entity().set<flecs::dash::Server>({ 9090 });

    world.entity("Item").set<ItemSpawning>({1000});

    world.system<ItemSpawning>("CreateItemEntity").iter(&Item::CreateItemEntity);

    world.system<ItemStaging, ItemSpawning>("SettingSeedForRandomItemEntitiesGeneration").iter(&Item::SettingSeedForRandomItemEntitiesGeneration);

    world.system<ItemStaging>("AddItemTypeComponentstoEntity").iter(&Item::AddItemTypeComponentstoEntity);

    world.system<ItemStaging, ItemTypeCreation>("AddItemComponentstoEntity").iter(&Item::AddItemComponentstoEntity);

    world.system<ItemStaging, ItemTypeCreation, ItemRarity>("CreatingRarityModComponentsToEntity").iter(&Item::CreatingRarityModComponentsToEntity);

    while (world.progress()) {}
}