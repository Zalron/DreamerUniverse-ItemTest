#include "flecs.h"
#include "Item.h"
#include "ItemComponents.h"
//#include <flecs_dash.h>
//#include <flecs_systems_civetweb.h>
#include <flecs_os_api_stdcpp.h>
#include <iostream>

using namespace std;

int main() 
{
    //stdcpp_set_os_api();

    flecs::world world;

    /*int32_t threadcount;

    cout << "Type the amount of threads you want" << std::endl;

    cin >> threadcount;

    if (threadcount == 0)
    {
        threadcount = 12;
    }

    world.set_threads(threadcount);*/

    int AmountofItemstoSpawn;

    cout << "Type the amount of items to spawn" << std::endl;

    cin >> AmountofItemstoSpawn;

    if (AmountofItemstoSpawn == 0)
    {
        AmountofItemstoSpawn = 100;
    }

    world.import<ItemConfig>();

    world.import<Item>();

    world.entity("Item").set<ItemConfigComponents::ConfigStage>({ 1 });

    world.set_target_fps(60);

    //world.import<flecs::dash>();

    //world.import<flecs::systems::civetweb>();

    //world.entity().set<flecs::dash::Server>({ 9090 });

    while (world.progress()) {}
}