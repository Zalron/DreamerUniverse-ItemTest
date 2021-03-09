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

    world.system<ItemStaging>("AddComponentstoEntity").iter(&Item::AddItemTypeComponentstoEntity);

    while (world.progress()) {}
}