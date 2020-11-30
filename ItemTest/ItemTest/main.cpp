#include "flecs.h"
#include "ItemComponents.h"
#include "ItemConfig.h"
#include <iostream>
#include <cstdint>

using namespace std;

struct Position 
{
    float x;
    float y;
};

struct Velocity 
{
    float x;
    float y;
};


void CreateItemEntity(flecs::iter& it, ItemType* itt, ItemRarity* ir)
{

    for (auto i : it)
    {
        std::cout << "The " << it.entity(i).name() << " Has ItemType {" <<
            itt[i].BaseType << ", " << itt[i].Type << ", " << itt[i].UseType << ", " << itt[i].BaseIntStatRoll << "}, Has ItemRarity {" << 
            ir[i].RarityAffixAllowance <<  ", " << ir[i].RarityRoll << ", " << ir[i].RarityAffixAllowance << "} " << std::endl;
    }
}

int main(int argc, char* argv[]) 
{

    flecs::world world;

    world.system<ItemType, ItemRarity>("CreateItemEntity").iter(CreateItemEntity);

    world.entity("Item").set<ItemType>({ 0,0 }).set<ItemRarity>({ 0,0 });

    std::cout << "Application CreateItemEntity is running, press CTRL-C to exit..." << std::endl;

    while (world.progress()) {}
}



/* int totalCount = 0;
    flecs::query q = flecs::query<Position>(ecs);
    q.action([&totalCount](flecs::iter& it, flecs::column<Position> t)
    {
        totalCount += it.count();
    });*/

/* ecs.system<Position, const Velocity>().each([](flecs::entity e, Position& p, const Velocity& v)
    {
        p.x += v.x * e.delta_time();
        p.y += v.y * e.delta_time();
        std::cout << "Moved " << e.name() << " to {" <<
                p.x << ", " << p.y << "}" << std::endl;
    });

    ecs.entity("Item")
        .set<Position>({ 0, 0 })
        .set<Velocity>({ 1, 1 });*/