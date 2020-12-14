#include "flecs.h"
#include "Item.h"
#include "ItemConfig.h"
#include <iostream>
#include <cstdint>

using namespace std;

int main(int argc, char* argv[]) 
{

    flecs::world world;

    world.entity("Item").set<ItemSpawning>({1000,25});

    world.system<ItemSpawning>("CreateItemEntity").iter(&Item::CreateItemEntity);

    world.system<ItemStaging>("AddComponentstoEntity").iter(&Item::AddComponentstoEntity);

    while (world.progress()) {}
}