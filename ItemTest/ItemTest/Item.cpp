#include "Item.h"

void Item::CreateItemEntity(flecs::iter& iter, ItemType* it, ItemRarity* ir)
{
    for (auto i : iter)
    {
        Item::CreatingMeleeItems(iter, i);
        std::cout << "The " << iter.entity(i).name() << " Has ItemType {" <<
            it[i].BaseType << ", " << it[i].Type << ", " << it[i].UseType << ", " << it[i].BaseIntStatRoll << "}, Has ItemRarity {" <<
            ir[i].RarityAffixAllowance << ", " << ir[i].RarityRoll << ", " << ir[i].RarityAffixAllowance << "} " << std::endl;
        std::cout << "Application CreateItemEntity is running, press CTRL-C to exit..." << std::endl;
    }
}

void Item::CreatingMeleeItems(flecs::iter& iter, int i)
{
	iter.entity(i).add<Weapons>();
	iter.entity(i).add<Melee>();
}
