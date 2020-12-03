#include "Item.h"

void Item::CreateItemEntity(flecs::iter& iter, ItemType* it, ItemRarity* ir)
{
    for (auto i : iter)
    {
        CreatingOneHandedMeleeWeaponItems(iter, i);
        std::cout << "The " << iter.entity(i).name() << " Has ItemType {" <<
            it[i].BaseType << ", " << it[i].Type << ", " << it[i].UseType << ", " << it[i].BaseIntStatRoll << "}, Has ItemRarity {" <<
            ir[i].RarityAffixAllowance << ", " << ir[i].RarityRoll << ", " << ir[i].RarityAffixAllowance << "} " << std::endl;
        std::cout << "Application CreateItemEntity is running, press CTRL-C to exit..." << std::endl;
    }
}

void Item::CreatingOneHandedMeleeWeaponItems(flecs::iter& iter, int i)
{
	iter.entity(i).add<Weapons>();
	iter.entity(i).add<Melee>();
    iter.entity(i).add<OneHanded>();
}

void Item::CreatingTwoHandedMeleeWeaponItems(flecs::iter& iter, int i)
{
    iter.entity(i).add<Weapons>();
    iter.entity(i).add<Melee>();
    iter.entity(i).add<TwoHanded>();
}

void Item::CreatingOneHandedRangedWeaponItems(flecs::iter& iter, int i)
{
    iter.entity(i).add<Weapons>();
    iter.entity(i).add<Ranged>();
    iter.entity(i).add<OneHanded>();
}

void Item::CreatingTwoHandedRangedWeaponItems(flecs::iter& iter, int i)
{
    iter.entity(i).add<Weapons>();
    iter.entity(i).add<Ranged>();
    iter.entity(i).add<TwoHanded>();
}

void Item::CreatingArmourPowerArmourLightItems(flecs::iter& iter, int i)
{
    iter.entity(i).add<Armour>();
    iter.entity(i).add<PowerArmour>();
    iter.entity(i).add<LightPowerArmour>();
}

void Item::CreatingArmourPowerArmourMediumItems(flecs::iter& iter, int i)
{
    iter.entity(i).add<Armour>();
    iter.entity(i).add<PowerArmour>();
    iter.entity(i).add<MediumPowerArmour>();
}

void Item::CreatingArmourPowerArmourHeavyItems(flecs::iter& iter, int i)
{
    iter.entity(i).add<Armour>();
    iter.entity(i).add<PowerArmour>();
    iter.entity(i).add<MediumPowerArmour>();
}
void Item::CreatingArmourNonPowerArmourItems(flecs::iter& iter, int i)
{
    iter.entity(i).add<Armour>();
    iter.entity(i).add<NonPowerArmour>();
}
void Item::CreatingArmourClothsItems(flecs::iter& iter, int i)
{
    iter.entity(i).add<Armour>();
    iter.entity(i).add<Cloths>();
}
