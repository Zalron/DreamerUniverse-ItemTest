#pragma once
#include "flecs.h"
#include "ItemComponents.h"
#include "ItemConfigComponents.h"
#include <iostream>

using namespace std;

struct ItemConfig
{
	ItemConfig(flecs::world& world)
	{
		world.module<ItemConfig>();

		world.import<ItemComponents>();
		world.import<ItemConfigComponents>();


		world.system<ItemConfigComponents::ConfigStage>("StartConfig").iter(StartConfig);
	}

	static void StartConfig(const flecs::iter& iter, ItemConfigComponents::ConfigStage* cs);

	//static void Add
};