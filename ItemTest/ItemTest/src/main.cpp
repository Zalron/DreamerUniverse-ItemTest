#include "flecs.h"
#include "Item.h"
#include "ItemComponents.h"
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

    cout << "Type the amount of threads you want" << std::endl;

    cin >> threadcount;

    if (threadcount == 0)
    {
        threadcount = 12;
    }

    world.set_threads(threadcount);

    int AmountofItemstoSpawn;

    cout << "Type the amount of items to spawn" << std::endl;

    cin >> AmountofItemstoSpawn;

    if (AmountofItemstoSpawn == 0)
    {
        AmountofItemstoSpawn = 1000;
    }

    world.entity("Item").set<ItemComponents::ItemSpawning>({ AmountofItemstoSpawn });

    world.set_target_fps(60);

    //world.import<flecs::dash>();

    //world.import<flecs::systems::civetweb>();

    //world.entity().set<flecs::dash::Server>({ 9090 });

    while (world.progress()) {}
}