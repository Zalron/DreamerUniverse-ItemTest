#include "flecs.h"
#include "Item.h"
#include "ItemConfig.h"
#include <iostream>
#include <cstdint>

using namespace std;

int main(int argc, char* argv[]) 
{

    flecs::world world;

    world.entity("Item").set<ItemType>({ 0,0 }).set<ItemRarity>({ 0,0 });

    world.system<ItemType, ItemRarity>("CreateItemEntity").iter(&Item::CreateItemEntity);

    while (world.progress()) {}
}