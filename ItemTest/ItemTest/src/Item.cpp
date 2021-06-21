#include "Item.h"

void Item::CreateItemEntity(const flecs::iter& iter, ItemSpawning* is)
{
    for (auto it : iter)
    {
        for (auto i  = 0; i < is->NumberOfItems; i++) 
        {
            auto e = iter.world().entity();
            e.set<ItemStaging>({1});
            std::cout << "System CreateItemEntity has created item " << i << " " << std::endl;
        }
        iter.entity(it).remove<ItemSpawning>();
        std::cout << "System CreateItemEntity is creating items" << std::endl;
    }
}

void Item::SettingSeedForRandomItemEntitiesGeneration(const flecs::iter& iter, ItemStaging* iss)
{
    for (auto it : iter)
    {
        if (iss->ItemStage == 1)
        {
            srand((unsigned)time(0));
            int randomNumber = rand();
            iss->Seed = randomNumber;
            iss->ItemStage = 2;
            std::cout << "System SettingSeedForRandomItemEntitiesGeneration is randomly generating number" << std::endl;
        }
    }
}

void Item::AddItemTypeComponentstoEntity(const flecs::iter& iter, ItemStaging* iss)
{
    for (auto it : iter) 
    {
        if (iss->ItemStage == 2) 
        {
            iter.entity(it).set<ItemTypeCreation>({0,0,0});
            iss->ItemStage = 3;
            std::cout << "System AddItemTypeComponentstoEntity has add ItemTypeCreation component" << std::endl;
        }
    }
}

void Item::AddItemComponentstoEntity(const flecs::iter& iter, ItemStaging* iss)
{
    for (auto it : iter) 
    {
        if (iss->ItemStage == 3)
        {
            CreatingEquipableItems(iter, it, iss->Seed);
            iss->ItemStage = 4;
            std::cout << "System AddItemComponentstoEntity is creating Items" << std::endl;
        }
    }
}

inline void Item::CreatingEquipableItems(const flecs::iter& iter, int i, int seed)
{
    int randomNumber = seed % 22;
    if (randomNumber == 0)
    {
        CreatingOneHandedMeleeWeaponShortSwordItems(iter, i, seed);
    }
    if (randomNumber == 1)
    {
        CreatingOneHandedMeleeWeaponMaceItems(iter, i, seed);
    }
    if (randomNumber == 2)
    {
        CreatingOneHandedMeleeWeaponKnifeItems(iter, i, seed);
    }
    if (randomNumber == 3)
    {
        CreatingOneHandedMeleeWeaponWarhammerItems(iter, i, seed);
    }
    if (randomNumber == 4)
    {
        CreatingOneHandedMeleeWeaponAxeItems(iter, i, seed);
    }
    if (randomNumber == 5)
    {
        CreatingOneHandedMeleeWeaponShieldItems(iter, i, seed);
    }
    if (randomNumber == 6)
    {
        CreatingOneHandedMeleeWeaponRapierItems(iter, i, seed);
    }
    if (randomNumber == 7)
    {
        CreatingOneHandedMeleeWeaponClubItems(iter, i, seed);
    }
    if (randomNumber == 8) 
    {
        CreatingTwoHandedMeleeWeaponLongSwordItems(iter, i, seed);
    }
    if (randomNumber == 9)
    {
        CreatingTwoHandedMeleeWeaponMaceItems(iter, i, seed);
    }
    if (randomNumber == 10)
    {
        CreatingTwoHandedMeleeWeaponWarhammerItems(iter, i, seed);
    }
    if (randomNumber == 11)
    {
        CreatingTwoHandedMeleeWeaponHalberdItems(iter, i, seed);
    }
    if (randomNumber == 12)
    {
        CreatingTwoHandedMeleeWeaponAxeItems(iter, i, seed);
    }
    if (randomNumber == 13)
    {
        CreatingTwoHandedMeleeWeaponClubItems(iter, i, seed);
    }
    if (randomNumber == 14)
    {
        CreatingTwoHandedMeleeWeaponStaffItems(iter, i, seed);
    }
    if (randomNumber == 15)
    {
        CreatingTwoHandedMeleeWeaponSpearItems(iter, i, seed);
    }
    if (randomNumber == 16)
    {
        CreatingTwoHandedMeleeWeaponClawsItems(iter, i, seed);
    }
    if (randomNumber == 17)
    {
        CreatingOneHandedRangedWeaponWandItems(iter, i, seed);
    }
    if (randomNumber == 18)
    {
        CreatingOneHandedRangedWeaponThrownItems(iter, i, seed);
    }
    if (randomNumber == 19)
    {
        CreatingOneHandedRangedWeaponPistolItems(iter, i, seed);
    }
    if (randomNumber == 20)
    {
        CreatingOneHandedRangedWeaponRevolverItems(iter, i, seed);
    }
    if (randomNumber == 21)
    {
        CreatingOneHandedRangedWeaponHandCrossbowItems(iter, i, seed);
    }
    else 
    {
        randomNumber = seed % 22;
    }
}

void Item::CreatingRarityModComponentsToEntity(const flecs::iter& iter, ItemStaging* iss, ItemTypeCreation* isc, ItemRarity* ir)
{
    for (auto it : iter)
    {
        if (iss->ItemStage == 7)
        {
            if (ir->RarityAffixAllowance == 1)
            {
                iter.entity(it).set<ItemAffixMods1>({});
            }
            else if (ir->RarityAffixAllowance == 2)
            {
                iter.entity(it).set<ItemAffixMods1>({});
                iter.entity(it).set<ItemAffixMods2>({});
            }
            else if (ir->RarityAffixAllowance == 3)
            {
                iter.entity(it).set<ItemAffixMods1>({});
                iter.entity(it).set<ItemAffixMods2>({});
                iter.entity(it).set<ItemAffixMods3>({});
            }
            else if (ir->RarityAffixAllowance == 4)
            {
                iter.entity(it).set<ItemAffixMods1>({});
                iter.entity(it).set<ItemAffixMods2>({});
                iter.entity(it).set<ItemAffixMods3>({});
                iter.entity(it).set<ItemAffixMods4>({});
            }
            else if (ir->RarityAffixAllowance == 5)
            {
                iter.entity(it).set<ItemAffixMods1>({});
                iter.entity(it).set<ItemAffixMods2>({});
                iter.entity(it).set<ItemAffixMods3>({});
                iter.entity(it).set<ItemAffixMods4>({});
                iter.entity(it).set<ItemAffixMods5>({});
            }
            else if (ir->RarityAffixAllowance == 6)
            {
                iter.entity(it).set<ItemAffixMods1>({});
                iter.entity(it).set<ItemAffixMods2>({});
                iter.entity(it).set<ItemAffixMods3>({});
                iter.entity(it).set<ItemAffixMods4>({});
                iter.entity(it).set<ItemAffixMods5>({});
                iter.entity(it).set<ItemAffixMods6>({});
            }
            else if (ir->RarityAffixAllowance == 7)
            {
                iter.entity(it).set<ItemAffixMods1>({});
                iter.entity(it).set<ItemAffixMods2>({});
                iter.entity(it).set<ItemAffixMods3>({});
                iter.entity(it).set<ItemAffixMods4>({});
                iter.entity(it).set<ItemAffixMods5>({});
                iter.entity(it).set<ItemAffixMods6>({});
                iter.entity(it).set<ItemAffixMods7>({});
            }
            else if (ir->RarityAffixAllowance == 8)
            {
                iter.entity(it).set<ItemAffixMods1>({});
                iter.entity(it).set<ItemAffixMods2>({});
                iter.entity(it).set<ItemAffixMods3>({});
                iter.entity(it).set<ItemAffixMods4>({});
                iter.entity(it).set<ItemAffixMods5>({});
                iter.entity(it).set<ItemAffixMods6>({});
                iter.entity(it).set<ItemAffixMods7>({});
                iter.entity(it).set<ItemAffixMods8>({});
            }
            else if (ir->RarityAffixAllowance == 9)
            {
                iter.entity(it).set<ItemAffixMods1>({});
                iter.entity(it).set<ItemAffixMods2>({});
                iter.entity(it).set<ItemAffixMods3>({});
                iter.entity(it).set<ItemAffixMods4>({});
                iter.entity(it).set<ItemAffixMods5>({});
                iter.entity(it).set<ItemAffixMods6>({});
                iter.entity(it).set<ItemAffixMods7>({});
                iter.entity(it).set<ItemAffixMods8>({});
                iter.entity(it).set<ItemAffixMods9>({});
            }
            else if (ir->RarityAffixAllowance == 10)
            {
                iter.entity(it).set<ItemAffixMods1>({});
                iter.entity(it).set<ItemAffixMods2>({});
                iter.entity(it).set<ItemAffixMods3>({});
                iter.entity(it).set<ItemAffixMods4>({});
                iter.entity(it).set<ItemAffixMods5>({});
                iter.entity(it).set<ItemAffixMods6>({});
                iter.entity(it).set<ItemAffixMods7>({});
                iter.entity(it).set<ItemAffixMods8>({});
                iter.entity(it).set<ItemAffixMods9>({});
                iter.entity(it).set<ItemAffixMods10>({});
            }
            else if (ir->RarityAffixAllowance == 11)
            {
                iter.entity(it).set<ItemAffixMods1>({});
                iter.entity(it).set<ItemAffixMods2>({});
                iter.entity(it).set<ItemAffixMods3>({});
                iter.entity(it).set<ItemAffixMods4>({});
                iter.entity(it).set<ItemAffixMods5>({});
                iter.entity(it).set<ItemAffixMods6>({});
                iter.entity(it).set<ItemAffixMods7>({});
                iter.entity(it).set<ItemAffixMods8>({});
                iter.entity(it).set<ItemAffixMods9>({});
                iter.entity(it).set<ItemAffixMods10>({});
            }
            iss->ItemStage = 8;
        }
    }
}

inline void Item::CreatingBaseItemEquipableStats(const flecs::iter& iter, int i, int randomRarity)
{
    iter.entity(i).set<ItemCharacterLevelRequirements>({});
    int randomRaritySeed = randomRarity % 11;
    iter.entity(i).set<ItemRarity>({randomRaritySeed, 0, randomRaritySeed});
    iter.entity(i).set<ItemQuality>({});
    iter.entity(i).set<ItemMaterial>({});
    iter.entity(i).set<ItemManufacturer>({});
    iter.entity(i).set<ItemName>({});
}

inline void Item::CreatingMeleeWeaponComponentsToEntity(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingBaseItemEquipableStats(iter, i, randomRarity);
    iter.entity(i).set<CriticalChanceItemStat>({});
    iter.entity(i).set<MagicalDamageItemStat>({});
    iter.entity(i).set<PhysicalDamageItemStat>({});
    iter.entity(i).set<HandlingItemStat>({});
    iter.entity(i).set<AccuracyItemStat>({});
    iter.entity(i).set<RangeItemStat>({});
    iter.entity(i).set<GuardItemStat>({});
    iter.entity(i).set<BlockChanceItemStat>({});
    iter.entity(i).set<AttackRateItemStat>({});
    iter.entity(i).set<WeightItemStat>({});
}

inline void Item::CreatingRangeWeaponComponentstoEntity(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingBaseItemEquipableStats(iter, i, randomRarity);
    iter.entity(i).set<CriticalChanceItemStat>({});
    iter.entity(i).set<MagicalDamageItemStat>({});
    iter.entity(i).set<PhysicalDamageItemStat>({});
    iter.entity(i).set<HandlingItemStat>({});
    iter.entity(i).set<AccuracyItemStat>({});
    iter.entity(i).set<RangeItemStat>({});
    iter.entity(i).set<MagazineSizeItemStat>({});
    iter.entity(i).set<ReloadTimeItemStat>({});
    iter.entity(i).set<FireRateItemStat>({});
    iter.entity(i).set<WeightItemStat>({});
}

inline void Item::CreatingPowerArmourComponentsToEntity(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingBaseItemEquipableStats(iter, i, randomRarity);
    iter.entity(i).set<ArmourItemStat>({});
    iter.entity(i).set<ArmourRechargeRateItemStat>({});
    iter.entity(i).set<ArmourRechargeDelayItemStat>({});
    iter.entity(i).set<ShieldItemStat>({});
    iter.entity(i).set<ShieldRechargeRateItemStat>({});
    iter.entity(i).set<ShieldRechargeDelayItemStat>({});
    iter.entity(i).set<EnergyItemStat>({});
    iter.entity(i).set<EnergyRechargeRateItemStat>({});
    iter.entity(i).set<EnergyRechargeDelayItemStat>({});
    iter.entity(i).set<WeightItemStat>({});
}

#pragma region Creating OneHanded Melee Weapons
inline void Item::CreatingOneHandedMeleeWeaponItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingMeleeWeaponComponentsToEntity(iter, i, randomRarity);
    iter.entity(i).add_trait<Item, Weapons>();
    iter.entity(i).add_trait<Weapons, Melee>();
    iter.entity(i).add_trait<Melee, OneHanded>();
}

inline void Item::CreatingOneHandedMeleeWeaponShortSwordItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingOneHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, ShortSword>();
}

inline void Item::CreatingOneHandedMeleeWeaponMaceItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingOneHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, Mace>();
}

inline void Item::CreatingOneHandedMeleeWeaponKnifeItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingOneHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, Knife>();
}

inline void Item::CreatingOneHandedMeleeWeaponWarhammerItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingOneHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, Warhammer>();
}

inline void Item::CreatingOneHandedMeleeWeaponAxeItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingOneHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, Axe>();
}

inline void Item::CreatingOneHandedMeleeWeaponShieldItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingOneHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, Shield>();
}

inline void Item::CreatingOneHandedMeleeWeaponRapierItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingOneHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, Rapier>();
}

inline void Item::CreatingOneHandedMeleeWeaponClubItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingOneHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, Club>();
}

#pragma endregion

#pragma region Creating TwoHanded Melee Weapons

inline void Item::CreatingTwoHandedMeleeWeaponItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingMeleeWeaponComponentsToEntity(iter, i, randomRarity);
    iter.entity(i).add_trait<Item, Weapons>();
    iter.entity(i).add_trait<Weapons, Melee>();
    iter.entity(i).add_trait<Melee, TwoHanded>();
}

inline void Item::CreatingTwoHandedMeleeWeaponLongSwordItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, LongSword>();
}

inline void Item::CreatingTwoHandedMeleeWeaponMaceItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, Mace>();
}

inline void Item::CreatingTwoHandedMeleeWeaponWarhammerItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, Warhammer>();
}

inline void Item::CreatingTwoHandedMeleeWeaponHalberdItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, Halberd>();
}

inline void Item::CreatingTwoHandedMeleeWeaponAxeItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, Axe>();
}

inline void Item::CreatingTwoHandedMeleeWeaponClubItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, Club>();
}

inline void Item::CreatingTwoHandedMeleeWeaponStaffItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, Staff>();
}

inline void Item::CreatingTwoHandedMeleeWeaponSpearItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, Spear>();
}

inline void Item::CreatingTwoHandedMeleeWeaponClawsItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, Claws>();
}

#pragma endregion

#pragma region Creating OneHanded Range Weapons

inline void Item::CreatingOneHandedRangedWeaponItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingRangeWeaponComponentstoEntity(iter, i, randomRarity);
    iter.entity(i).add_trait<Item, Weapons>();
    iter.entity(i).add_trait<Weapons, Ranged>();
    iter.entity(i).add_trait<Ranged, OneHanded>();
}

inline void Item::CreatingOneHandedRangedWeaponWandItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingOneHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, Wand>();
}

inline void Item::CreatingOneHandedRangedWeaponThrownItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingOneHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, Thrown>();
}

inline void Item::CreatingOneHandedRangedWeaponPistolItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingOneHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, Pistol>();
}

inline void Item::CreatingOneHandedRangedWeaponRevolverItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingOneHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, Revolver>();
}

inline void Item::CreatingOneHandedRangedWeaponHandCrossbowItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingOneHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, HandCrossbow>();
}
#pragma endregion

#pragma region Creating TwoHanded Range Weapons

inline void Item::CreatingTwoHandedRangedWeaponItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingRangeWeaponComponentstoEntity(iter, i, randomRarity);
    iter.entity(i).add_trait<Item, Weapons>();
    iter.entity(i).add_trait<Weapons, Ranged>();
    iter.entity(i).add_trait<Ranged, TwoHanded>();
}

inline void Item::CreatingTwoHandedRangedWeaponBowItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingTwoHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, Bow>();
}

inline void Item::CreatingTwoHandedRangedWeaponCrossbowItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingTwoHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, Crossbow>();
}

inline void Item::CreatingTwoHandedRangedWeaponCarbineItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingTwoHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, Carbine>();
}

inline void Item::CreatingTwoHandedRangedWeaponAssaultRifleItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingTwoHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, AssaultRifle>();
}

inline void Item::CreatingTwoHandedRangedWeaponSniperRifleItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingTwoHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, SniperRifle>();
}

inline void Item::CreatingTwoHandedRangedWeaponLightMachineGunItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingTwoHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, LightMachineGun>();
}

inline void Item::CreatingTwoHandedRangedWeaponSubMachineGunItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingTwoHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, SubMachineGun>();
}

inline void Item::CreatingTwoHandedRangedWeaponShotgunItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingTwoHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, Shotgun>();
}

inline void Item::CreatingTwoHandedRangedWeaponGrenadeLauncherItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingTwoHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, GrenadeLauncher>();
}

inline void Item::CreatingTwoHandedRangedWeaponRocketLauncherItems(const flecs::iter& iter, int i, int randomRarity)
{
    CreatingTwoHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, RocketLauncher>();
}

#pragma endregion

#pragma region Creating Light PowerArmour

void Item::CreatingArmourPowerArmourLightItems(const flecs::iter& iter, int i)
{
    iter.entity(i).add_trait<Item, Armour>();
    iter.entity(i).add_trait<Armour, PowerArmour>();
    iter.entity(i).add_trait<PowerArmour, LightPowerArmour>();
}

inline void Item::CreatingArmourPowerArmourLightHeadItems(const flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourLightItems(iter, i);
    iter.entity(i).add_trait<LightPowerArmour, Head>();
}

inline void Item::CreatingArmourPowerArmourLightBeltItems(const flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourLightItems(iter, i);
    iter.entity(i).add_trait<LightPowerArmour, Belt>();
}

inline void Item::CreatingArmourPowerArmourLightChestItems(const flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourLightItems(iter, i);
    iter.entity(i).add_trait<LightPowerArmour, Chests>();
}

inline void Item::CreatingArmourPowerArmourLightLegsItems(const flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourLightItems(iter, i);
    iter.entity(i).add_trait<LightPowerArmour, Legs>();
}

inline void Item::CreatingArmourPowerArmourLightArmsItems(const flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourLightItems(iter, i);
    iter.entity(i).add_trait<LightPowerArmour, Arms>();
}

inline void Item::CreatingArmourPowerArmourLightHandsItems(const flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourLightItems(iter, i);
    iter.entity(i).add_trait<LightPowerArmour, Hands>();
}

inline void Item::CreatingArmourPowerArmourLightShouldersItems(const flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourLightItems(iter, i);
    iter.entity(i).add_trait<LightPowerArmour, Shoulders>();
}

inline void Item::CreatingArmourPowerArmourLightBackpackItems(const flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourLightItems(iter, i);
    iter.entity(i).add_trait<LightPowerArmour, Backpack>();
}

#pragma endregion

#pragma region Creating Medium PowerArmour

void Item::CreatingArmourPowerArmourMediumItems(const flecs::iter& iter, int i)
{
    iter.entity(i).add_trait<Item, Armour>();
    iter.entity(i).add_trait<Armour, PowerArmour>();
    iter.entity(i).add_trait<PowerArmour, MediumPowerArmour>();
}

inline void Item::CreatingArmourPowerArmourMediumHeadItems(const flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourMediumItems(iter, i);
    iter.entity(i).add_trait<MediumPowerArmour, Head>();
}

inline void Item::CreatingArmourPowerArmourMediumBeltItems(const flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourMediumItems(iter, i);
    iter.entity(i).add_trait<MediumPowerArmour, Belt>();
}

inline void Item::CreatingArmourPowerArmourMediumChestItems(const flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourMediumItems(iter, i);
    iter.entity(i).add_trait<MediumPowerArmour, Chests>();
}

inline void Item::CreatingArmourPowerArmourMediumLegsItems(const flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourMediumItems(iter, i);
    iter.entity(i).add_trait<MediumPowerArmour, Legs>();
}

inline void Item::CreatingArmourPowerArmourMediumArmsItems(const flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourMediumItems(iter, i);
    iter.entity(i).add_trait<MediumPowerArmour, Arms>();
}

inline void Item::CreatingArmourPowerArmourMediumHandsItems(const flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourMediumItems(iter, i);
    iter.entity(i).add_trait<MediumPowerArmour, Hands>();
}

inline void Item::CreatingArmourPowerArmourMediumShouldersItems(const flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourMediumItems(iter, i);
    iter.entity(i).add_trait<MediumPowerArmour, Shoulders>();
}

inline void Item::CreatingArmourPowerArmourMediumBackpackItems(const flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourMediumItems(iter, i);
    iter.entity(i).add_trait<MediumPowerArmour, Backpack>();
}

#pragma endregion

#pragma region Creating Heavy PowerArmour

inline void Item::CreatingArmourPowerArmourHeavyItems(const flecs::iter& iter, int i)
{
    iter.entity(i).add_trait<Item, Armour>();
    iter.entity(i).add_trait<Armour, PowerArmour>();
    iter.entity(i).add_trait<PowerArmour, HeavyPowerArmour>();
}

inline void Item::CreatingArmourPowerArmourHeavyHeadItems(const flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourHeavyItems(iter, i);
    iter.entity(i).add_trait<HeavyPowerArmour, Head>();
}

inline void Item::CreatingArmourPowerArmourHeavyBeltItems(const flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourHeavyItems(iter, i);
    iter.entity(i).add_trait<HeavyPowerArmour, Belt>();
}

inline void Item::CreatingArmourPowerArmourHeavyChestItems(const flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourHeavyItems(iter, i);
    iter.entity(i).add_trait<HeavyPowerArmour, Chests>();
}

inline void Item::CreatingArmourPowerArmourHeavyLegsItems(const flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourHeavyItems(iter, i);
    iter.entity(i).add_trait<HeavyPowerArmour, Legs>();
}

inline void Item::CreatingArmourPowerArmourHeavyArmsItems(const flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourHeavyItems(iter, i);
    iter.entity(i).add_trait<HeavyPowerArmour, Arms>();
}

inline void Item::CreatingArmourPowerArmourHeavyHandsItems(const flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourHeavyItems(iter, i);
    iter.entity(i).add_trait<HeavyPowerArmour, Hands>();
}

inline void Item::CreatingArmourPowerArmourHeavyShouldersItems(const flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourHeavyItems(iter, i);
    iter.entity(i).add_trait<HeavyPowerArmour, Shoulders>();
}

inline void Item::CreatingArmourPowerArmourHeavyBackpackItems(const flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourHeavyItems(iter, i);
    iter.entity(i).add_trait<HeavyPowerArmour, Backpack>();
}

#pragma endregion

#pragma region Creating NonPowerArmour

inline void Item::CreatingArmourNonPowerArmourItems(const flecs::iter& iter, int i)
{
    iter.entity(i).add_trait<Item, Armour>();
    iter.entity(i).add_trait<Armour, NonPowerArmour>();
}

inline void Item::CreatingArmourNonPowerArmourHeadItems(const flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<NonPowerArmour, Head>();
}

inline void Item::CreatingArmourNonPowerArmourBeltItems(const flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<NonPowerArmour, Belt>();
}

inline void Item::CreatingArmourNonPowerArmourChestItems(const flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<NonPowerArmour, Chests>();
}

inline void Item::CreatingArmourNonPowerArmourLegsItems(const flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<NonPowerArmour, Legs>();
}

inline void Item::CreatingArmourNonPowerArmourArmsItems(const flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<NonPowerArmour, Arms>();
}

inline void Item::CreatingArmourNonPowerArmourHandsItems(const flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<NonPowerArmour, Hands>();
}

inline void Item::CreatingArmourNonPowerArmourShouldersItems(const flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<NonPowerArmour, Shoulders>();
}

inline void Item::CreatingArmourNonPowerArmourBackpackItems(const flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<NonPowerArmour, Backpack>();
}

#pragma endregion

#pragma region Creating Cloths Armour

void Item::CreatingArmourClothsItems(const flecs::iter& iter, int i)
{
    iter.entity(i).add_trait<Item, Armour>();
    iter.entity(i).add_trait<Armour, Cloths>();
}

inline void Item::CreatingArmourClothsHeadItems(const flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<Cloths, Head>();
}

inline void Item::CreatingArmourClothsBeltItems(const flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<Cloths, Belt>();
}

inline void Item::CreatingArmourClothsChestItems(const flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<Cloths, Chests>();
}

inline void Item::CreatingArmourClothsLegsItems(const flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<Cloths, Legs>();
}

inline void Item::CreatingArmourClothsArmsItems(const flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<Cloths, Arms>();
}

inline void Item::CreatingArmourClothsHandsItems(const flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<Cloths, Hands>();
}

inline void Item::CreatingArmourClothsShouldersItems(const flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<Cloths, Shoulders>();
}

inline void Item::CreatingArmourClothsBackpackItems(const flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<Cloths, Backpack>();
}

inline void Item::CreatingEquipmentFlasks(const flecs::iter& iter, int i)
{
    iter.entity(i).add_trait<Item, Equipment>();
    iter.entity(i).add_trait<Equipment, Flasks>();
}

inline void Item::CreatingEquipmentFlasksHealth(const flecs::iter& iter, int i)
{
    CreatingEquipmentFlasks(iter, i);
    iter.entity(i).add_trait<Flasks, Health>();
}

inline void Item::CreatingEquipmentFlasksMagic(const flecs::iter& iter, int i)
{
    CreatingEquipmentFlasks(iter, i);
    iter.entity(i).add_trait<Flasks, Magic>();
}

inline void Item::CreatingEquipmentFlasksMovement(const flecs::iter& iter, int i)
{
    CreatingEquipmentFlasks(iter, i);
    iter.entity(i).add_trait<Flasks, Movement>();
}

inline void Item::CreatingEquipmentFlasksResistance(const flecs::iter& iter, int i)
{
    CreatingEquipmentFlasks(iter, i);
    iter.entity(i).add_trait<Flasks, Resistance>();
}

inline void Item::CreatingEquipmentAmmo(const flecs::iter& iter, int i)
{
    iter.entity(i).add_trait<Item, Equipment>();
    iter.entity(i).add_trait<Equipment, Ammo>();
}

inline void Item::CreatingEquipmentAmmoQuivers(const flecs::iter& iter, int i)
{
    CreatingEquipmentAmmo(iter, i);
    iter.entity(i).add_trait<Equipment, Quivers>();
}

inline void Item::CreatingEquipmentAmmoMagazines(const flecs::iter& iter, int i)
{
    CreatingEquipmentAmmo(iter, i);
    iter.entity(i).add_trait<Equipment, Magazines>();
}

inline void Item::CreatingEquipmentAmmoGrenades(const flecs::iter& iter, int i)
{
    CreatingEquipmentAmmo(iter, i);
    iter.entity(i).add_trait<Equipment, Grenades>();
}

inline void Item::CreatingEquipmentAmmoRockets(const flecs::iter& iter, int i)
{
    CreatingEquipmentAmmo(iter, i);
    iter.entity(i).add_trait<Equipment, Rockets>();
}

inline void Item::CreatingEquipmentAmmoMines(const flecs::iter& iter, int i)
{
    CreatingEquipmentAmmo(iter, i);
    iter.entity(i).add_trait<Equipment, Mines>();
}

#pragma endregion

