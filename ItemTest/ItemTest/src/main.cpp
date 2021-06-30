//#include "flecs.h"
#include "Item.h"
//#include <flecs_dash.h>
//#include <flecs_systems_civetweb.h>
#include <flecs_os_api_stdcpp.h>
#include <iostream>
#include <cstdint>

using namespace std;

int main() 
{
    cout << "RAND_MAX value is " << RAND_MAX << endl;

    stdcpp_set_os_api();

    flecs::world world;

    world.import<Item>();

    int32_t threadcount;

    std:cout << "Type the amount of threads you want" << std::endl;

    std::cin >> threadcount;

    world.set_threads(threadcount);

    int AmountofItemstoSpawn;

    std::cout << "Type the amount of items to spawn" << std::endl;

    std::cin >> AmountofItemstoSpawn;

    world.entity("Item").set<ItemComponents::ItemSpawning>({ AmountofItemstoSpawn });

    world.set_target_fps(60);

    //world.import<flecs::dash>();

    //world.import<flecs::systems::civetweb>();

    //world.entity().set<flecs::dash::Server>({ 9090 });

    while (world.progress()) {}
}