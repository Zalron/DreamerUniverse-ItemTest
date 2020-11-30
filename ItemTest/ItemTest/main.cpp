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



int main(int argc, char* argv[]) 
{

    flecs::world ecs;

    ecs.entity("Item").set<ItemType>({ 0,0,0,0 }).set<ItemRarity>({ 0,0 });

    ecs.system<ItemType, ItemRarity>().each([](flecs::entity e, ItemType& it, ItemRarity& ir) 
    {
        
        std::cout << "The " << e.name() << " Has {" <<
            it.BaseIntStatRoll << ", " << ir.RarityAffixAllowance << "}" << std::endl;
        //flecs::entity entity;
    });

    while (ecs.progress()) {}

    std::cout << "Application move_system is running, press CTRL-C to exit..." << std::endl;
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