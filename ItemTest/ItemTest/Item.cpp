#include "Item.h"

void Item::CreateItemEntity(flecs::iter& iter, ItemSpawning* is)
{
    for (auto it : iter)
    {
        for (auto i  = 0; i < is->NumberOfItems; i++) 
        {
            auto e = iter.world().entity();
            e.set<ItemStaging>({1, is->Seed});
            std::cout << "System CreateItemEntity has created item" << i << " " << std::endl;
        }
        iter.entity(it).remove<ItemSpawning>();
        std::cout << "System CreateItemEntity is creating items" << std::endl;
    }
}

void Item::AddItemTypeComponentstoEntity(flecs::iter& iter, ItemStaging* iss)
{
    for (auto it : iter) 
    {
        if (iss->ItemStage == 1) 
        {
            iter.entity(it).set<ItemTypeCreation>({0,0,0 });
            iss->ItemStage = 2;
        }
    }
}
#pragma region Creating OneHanded Melee Weapons

inline void Item::CreatingOneHandedMeleeWeaponItems(flecs::iter& iter, int i)
{
    iter.entity(i).add<Weapons>();
    iter.entity(i).add<Melee>();
    iter.entity(i).add<OneHanded>();
}

inline void Item::CreatingOneHandedMeleeWeaponShortSwordItems(flecs::iter& iter, int i)
{
    CreatingOneHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add<ShortSword>();
}

inline void Item::CreatingOneHandedMeleeWeaponMaceItems(flecs::iter& iter, int i)
{
    CreatingOneHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add<Mace>();
}

inline void Item::CreatingOneHandedMeleeWeaponKnifeItems(flecs::iter& iter, int i)
{
    CreatingOneHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add<Knife>();
}

inline void Item::CreatingOneHandedMeleeWeaponWarhammerItems(flecs::iter& iter, int i)
{
    CreatingOneHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add<Warhammer>();
}

inline void Item::CreatingOneHandedMeleeWeaponAxeItems(flecs::iter& iter, int i)
{
    CreatingOneHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add<Axe>();
}

inline void Item::CreatingOneHandedMeleeWeaponShieldItems(flecs::iter& iter, int i)
{
    CreatingOneHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add<Shield>();
}

inline void Item::CreatingOneHandedMeleeWeaponRapierItems(flecs::iter& iter, int i)
{
    CreatingOneHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add<Rapier>();
}

inline void Item::CreatingOneHandedMeleeWeaponClubItems(flecs::iter& iter, int i)
{
    CreatingOneHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add<Club>();
}

#pragma endregion

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


