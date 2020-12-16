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

#pragma region Creating TwoHanded Melee Weapons

inline void Item::CreatingTwoHandedMeleeWeaponItems(flecs::iter& iter, int i)
{
    iter.entity(i).add<Weapons>();
    iter.entity(i).add<Melee>();
    iter.entity(i).add<TwoHanded>();
}

inline void Item::CreatingTwoHandedMeleeWeaponLongSwordItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add<LongSword>();
}

inline void Item::CreatingTwoHandedMeleeWeaponMaceItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add<Mace>();
}

inline void Item::CreatingTwoHandedMeleeWeaponWarhammerItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add<Warhammer>();
}

inline void Item::CreatingTwoHandedMeleeWeaponHalberdItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add<Halberd>();
}

inline void Item::CreatingTwoHandedMeleeWeaponAxeItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add<Axe>();
}

inline void Item::CreatingTwoHandedMeleeWeaponClubItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add<Club>();
}

inline void Item::CreatingTwoHandedMeleeWeaponStaffItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add<Staff>();
}

inline void Item::CreatingTwoHandedMeleeWeaponSpearItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add<Spear>();
}

inline void Item::CreatingTwoHandedMeleeWeaponClawsItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add<Claws>();
}

#pragma endregion

#pragma region Creating OneHanded Range Weapons

inline void Item::CreatingOneHandedRangedWeaponItems(flecs::iter& iter, int i)
{
    iter.entity(i).add<Weapons>();
    iter.entity(i).add<Ranged>();
    iter.entity(i).add<OneHanded>();
}

inline void Item::CreatingOneHandedRangedWeaponWandItems(flecs::iter& iter, int i)
{
    CreatingOneHandedRangedWeaponItems(iter, i);
    iter.entity(i).add<Wand>();
}

inline void Item::CreatingOneHandedRangedWeaponThrowingKnifeItems(flecs::iter& iter, int i)
{
    CreatingOneHandedRangedWeaponItems(iter, i);
    iter.entity(i).add<ThrowingKnifes>();
}

inline void Item::CreatingOneHandedRangedWeaponThrowingAxesItems(flecs::iter& iter, int i)
{
    CreatingOneHandedRangedWeaponItems(iter, i);
    iter.entity(i).add<ThrowingAxes>();
}

inline void Item::CreatingOneHandedRangedWeaponPistolItems(flecs::iter& iter, int i)
{
    CreatingOneHandedRangedWeaponItems(iter, i);
    iter.entity(i).add<Pistol>();
}

inline void Item::CreatingOneHandedRangedWeaponHandCannonItems(flecs::iter& iter, int i)
{
    CreatingOneHandedRangedWeaponItems(iter, i);
    iter.entity(i).add<HandCannon>();
}

inline void Item::CreatingOneHandedRangedWeaponRevolverItems(flecs::iter& iter, int i)
{
    CreatingOneHandedRangedWeaponItems(iter, i);
    iter.entity(i).add<Revolver>();
}

inline void Item::CreatingOneHandedRangedWeaponHandCrossbowItems(flecs::iter& iter, int i)
{
    CreatingOneHandedRangedWeaponItems(iter, i);
    iter.entity(i).add<HandCrossbow>();
}
#pragma endregion

#pragma region Creating TwoHanded Range Weapons

inline void Item::CreatingTwoHandedRangedWeaponItems(flecs::iter& iter, int i)
{
    iter.entity(i).add<Weapons>();
    iter.entity(i).add<Ranged>();
    iter.entity(i).add<TwoHanded>();
}

inline void Item::CreatingTwoHandedRangedWeaponBowItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedRangedWeaponItems(iter, i);
    iter.entity(i).add<Bow>();
}

inline void Item::CreatingTwoHandedRangedWeaponCrossbowItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedRangedWeaponItems(iter, i);
    iter.entity(i).add<Crossbow>();
}

inline void Item::CreatingTwoHandedRangedWeaponCarbineItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedRangedWeaponItems(iter, i);
    iter.entity(i).add<Carbine>();
}

inline void Item::CreatingTwoHandedRangedWeaponAssaultRifleItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedRangedWeaponItems(iter, i);
    iter.entity(i).add<AssaultRifle>();
}

inline void Item::CreatingTwoHandedRangedWeaponSniperRifleItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedRangedWeaponItems(iter, i);
    iter.entity(i).add<SniperRifle>();
}

inline void Item::CreatingTwoHandedRangedWeaponLightMachineGunItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedRangedWeaponItems(iter, i);
    iter.entity(i).add<LightMachineGun>();
}

inline void Item::CreatingTwoHandedRangedWeaponSubMachineGunItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedRangedWeaponItems(iter, i);
    iter.entity(i).add<SubMachineGun>();
}

inline void Item::CreatingTwoHandedRangedWeaponShotgunItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedRangedWeaponItems(iter, i);
    iter.entity(i).add<Shotgun>();
}

inline void Item::CreatingTwoHandedRangedWeaponGrenadeLauncherItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedRangedWeaponItems(iter, i);
    iter.entity(i).add<GrenadeLauncher>();
}

inline void Item::CreatingTwoHandedRangedWeaponRocketLauncherItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedRangedWeaponItems(iter, i);
    iter.entity(i).add<RocketLauncher>();
}

#pragma endregion

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
    iter.entity(i).add<HeavyPowerArmour>();
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


