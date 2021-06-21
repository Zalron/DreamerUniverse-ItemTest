//#include "flecs.h"
#include "Item.h"
//#include "ItemConfig.h"
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

    world.set_threads(12);

    //world.import<flecs::dash>();

    //world.import<flecs::systems::civetweb>();

    //world.entity().set<flecs::dash::Server>({ 9090 });

    world.import<Item>();

    world.entity("Item").set<Item::ItemSpawning>({ 1000 });

    world.set_target_fps(60);

    while (world.progress()) {}
}