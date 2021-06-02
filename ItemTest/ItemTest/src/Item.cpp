#include "Item.h"

void Item::CreateItemEntity(flecs::iter& iter, ItemSpawning* is)
{
    for (auto it : iter)
    {
        for (auto i  = 0; i < is->NumberOfItems; i++) 
        {
            auto e = iter.world().entity();
            e.set<ItemStaging>({1});
            std::cout << "System CreateItemEntity has created item " << i << " " << std::endl;
        }
        iter.entity(it).destruct();
        std::cout << "System CreateItemEntity is creating items" << std::endl;
    }
}

void Item::SettingSeedForRandomItemEntitiesGeneration(flecs::iter& iter, ItemStaging* iss, ItemSpawning* is)
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

void Item::AddItemTypeComponentstoEntity(flecs::iter& iter, ItemStaging* iss)
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

void Item::AddItemComponentstoEntity(flecs::iter& iter, ItemStaging* iss, ItemTypeCreation* isc)
{
    for (auto it : iter) 
    {
        if (iss->ItemStage == 3)
        {
            CreatingOneHandedMeleeWeaponShortSwordItems(iter, it);
            iss->ItemStage = 4;
            std::cout << "System AddItemComponentstoEntity is creating MeleeWeaponShortSwordItems" << std::endl;
        }
    }
}

void Item::CreatingRarityModComponentsToEntity(flecs::iter& iter, ItemStaging* iss, ItemTypeCreation* isc, ItemRarity* ir)
{
    for (auto it : iter)
    {
        if (iss->ItemStage == 7)
        {
            if (ir->RarityAffixAllowance == 1)
            {
                iter.entity(it).set<ItemAffixMods1>({});
            }
            if (ir->RarityAffixAllowance == 2)
            {
                iter.entity(it).set<ItemAffixMods1>({});
                iter.entity(it).set<ItemAffixMods2>({});
            }
            if (ir->RarityAffixAllowance == 3)
            {
                iter.entity(it).set<ItemAffixMods1>({});
                iter.entity(it).set<ItemAffixMods2>({});
                iter.entity(it).set<ItemAffixMods3>({});
            }
            if (ir->RarityAffixAllowance == 4)
            {
                iter.entity(it).set<ItemAffixMods1>({});
                iter.entity(it).set<ItemAffixMods2>({});
                iter.entity(it).set<ItemAffixMods3>({});
                iter.entity(it).set<ItemAffixMods4>({});
            }
            if (ir->RarityAffixAllowance == 5)
            {
                iter.entity(it).set<ItemAffixMods1>({});
                iter.entity(it).set<ItemAffixMods2>({});
                iter.entity(it).set<ItemAffixMods3>({});
                iter.entity(it).set<ItemAffixMods4>({});
                iter.entity(it).set<ItemAffixMods5>({});
            }
            if (ir->RarityAffixAllowance == 6)
            {
                iter.entity(it).set<ItemAffixMods1>({});
                iter.entity(it).set<ItemAffixMods2>({});
                iter.entity(it).set<ItemAffixMods3>({});
                iter.entity(it).set<ItemAffixMods4>({});
                iter.entity(it).set<ItemAffixMods5>({});
                iter.entity(it).set<ItemAffixMods6>({});
            }
            if (ir->RarityAffixAllowance == 7)
            {
                iter.entity(it).set<ItemAffixMods1>({});
                iter.entity(it).set<ItemAffixMods2>({});
                iter.entity(it).set<ItemAffixMods3>({});
                iter.entity(it).set<ItemAffixMods4>({});
                iter.entity(it).set<ItemAffixMods5>({});
                iter.entity(it).set<ItemAffixMods6>({});
                iter.entity(it).set<ItemAffixMods7>({});
            }
            if (ir->RarityAffixAllowance == 8)
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
            if (ir->RarityAffixAllowance == 9)
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
            if (ir->RarityAffixAllowance == 10)
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
inline void Item::CreatingBaseItemEquipableStats(flecs::iter& iter, int i)
{
    iter.entity(i).set<ItemCharacterLevelRequirements>({ 0 });
    iter.entity(i).set<ItemRarity>({});
    iter.entity(i).set<ItemQuality>({});
    iter.entity(i).set<ItemMaterial>({});
    iter.entity(i).set<ItemManufacturer>({});
    iter.entity(i).set<ItemName>({});
}

inline void Item::CreatingMeleeWeaponComponentsToEntity(flecs::iter& iter, int i)
{
    CreatingBaseItemEquipableStats(iter, i);
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

inline void Item::CreatingRangeWeaponComponentstoEntity(flecs::iter& iter, int i)
{
    CreatingBaseItemEquipableStats(iter, i);
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

inline void Item::CreatingPowerArmourComponentsToEntity(flecs::iter& iter, int i)
{
    CreatingBaseItemEquipableStats(iter, i);
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
inline void Item::CreatingOneHandedMeleeWeaponItems(flecs::iter& iter, int i)
{
    CreatingMeleeWeaponComponentsToEntity(iter, i);
    iter.entity(i).add_trait<Item, Weapons>();
    iter.entity(i).add_trait<Weapons, Melee>();
    iter.entity(i).add_trait<Melee, OneHanded>();
}

inline void Item::CreatingOneHandedMeleeWeaponShortSwordItems(flecs::iter& iter, int i)
{
    CreatingOneHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add_trait<OneHanded, ShortSword>();
}

inline void Item::CreatingOneHandedMeleeWeaponMaceItems(flecs::iter& iter, int i)
{
    CreatingOneHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add_trait<OneHanded, Mace>();
}

inline void Item::CreatingOneHandedMeleeWeaponKnifeItems(flecs::iter& iter, int i)
{
    CreatingOneHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add_trait<OneHanded, Knife>();
}

inline void Item::CreatingOneHandedMeleeWeaponWarhammerItems(flecs::iter& iter, int i)
{
    CreatingOneHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add_trait<OneHanded, Warhammer>();
}

inline void Item::CreatingOneHandedMeleeWeaponAxeItems(flecs::iter& iter, int i)
{
    CreatingOneHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add_trait<OneHanded, Axe>();
}

inline void Item::CreatingOneHandedMeleeWeaponShieldItems(flecs::iter& iter, int i)
{
    CreatingOneHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add_trait<OneHanded, Shield>();
}

inline void Item::CreatingOneHandedMeleeWeaponRapierItems(flecs::iter& iter, int i)
{
    CreatingOneHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add_trait<OneHanded, Rapier>();
}

inline void Item::CreatingOneHandedMeleeWeaponClubItems(flecs::iter& iter, int i)
{
    CreatingOneHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add_trait<OneHanded, Club>();
}

#pragma endregion

#pragma region Creating TwoHanded Melee Weapons

inline void Item::CreatingTwoHandedMeleeWeaponItems(flecs::iter& iter, int i)
{
    iter.entity(i).add_trait<Item, Weapons>();
    iter.entity(i).add_trait<Weapons, Melee>();
    iter.entity(i).add_trait<Melee, TwoHanded>();
}

inline void Item::CreatingTwoHandedMeleeWeaponLongSwordItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add_trait<TwoHanded, LongSword>();
}

inline void Item::CreatingTwoHandedMeleeWeaponMaceItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add_trait<TwoHanded, Mace>();
}

inline void Item::CreatingTwoHandedMeleeWeaponWarhammerItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add_trait<TwoHanded, Warhammer>();
}

inline void Item::CreatingTwoHandedMeleeWeaponHalberdItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add_trait<TwoHanded, Halberd>();
}

inline void Item::CreatingTwoHandedMeleeWeaponAxeItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add_trait<TwoHanded, Axe>();
}

inline void Item::CreatingTwoHandedMeleeWeaponClubItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add_trait<TwoHanded, Club>();
}

inline void Item::CreatingTwoHandedMeleeWeaponStaffItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add_trait<TwoHanded, Staff>();
}

inline void Item::CreatingTwoHandedMeleeWeaponSpearItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add_trait<TwoHanded, Spear>();
}

inline void Item::CreatingTwoHandedMeleeWeaponClawsItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i);
    iter.entity(i).add_trait<TwoHanded, Claws>();
}

#pragma endregion

#pragma region Creating OneHanded Range Weapons

inline void Item::CreatingOneHandedRangedWeaponItems(flecs::iter& iter, int i)
{
    iter.entity(i).add_trait<Item, Weapons>();
    iter.entity(i).add_trait<Weapons, Ranged>();
    iter.entity(i).add_trait<Ranged, OneHanded>();
}

inline void Item::CreatingOneHandedRangedWeaponWandItems(flecs::iter& iter, int i)
{
    CreatingOneHandedRangedWeaponItems(iter, i);
    iter.entity(i).add_trait<OneHanded, Wand>();
}

inline void Item::CreatingOneHandedRangedWeaponThrowingKnifeItems(flecs::iter& iter, int i)
{
    CreatingOneHandedRangedWeaponItems(iter, i);
    iter.entity(i).add_trait<OneHanded, ThrowingKnifes>();
}

inline void Item::CreatingOneHandedRangedWeaponThrowingAxesItems(flecs::iter& iter, int i)
{
    CreatingOneHandedRangedWeaponItems(iter, i);
    iter.entity(i).add_trait<OneHanded, ThrowingAxes>();
}

inline void Item::CreatingOneHandedRangedWeaponPistolItems(flecs::iter& iter, int i)
{
    CreatingOneHandedRangedWeaponItems(iter, i);
    iter.entity(i).add_trait<OneHanded, Pistol>();
}

inline void Item::CreatingOneHandedRangedWeaponHandCannonItems(flecs::iter& iter, int i)
{
    CreatingOneHandedRangedWeaponItems(iter, i);
    iter.entity(i).add_trait<OneHanded, HandCannon>();
}

inline void Item::CreatingOneHandedRangedWeaponRevolverItems(flecs::iter& iter, int i)
{
    CreatingOneHandedRangedWeaponItems(iter, i);
    iter.entity(i).add_trait<OneHanded, Revolver>();
}

inline void Item::CreatingOneHandedRangedWeaponHandCrossbowItems(flecs::iter& iter, int i)
{
    CreatingOneHandedRangedWeaponItems(iter, i);
    iter.entity(i).add_trait<OneHanded, HandCrossbow>();
}
#pragma endregion

#pragma region Creating TwoHanded Range Weapons

inline void Item::CreatingTwoHandedRangedWeaponItems(flecs::iter& iter, int i)
{
    iter.entity(i).add_trait<Item, Weapons>();
    iter.entity(i).add_trait<Weapons, Ranged>();
    iter.entity(i).add_trait<Ranged, TwoHanded>();
}

inline void Item::CreatingTwoHandedRangedWeaponBowItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedRangedWeaponItems(iter, i);
    iter.entity(i).add_trait<TwoHanded, Bow>();
}

inline void Item::CreatingTwoHandedRangedWeaponCrossbowItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedRangedWeaponItems(iter, i);
    iter.entity(i).add_trait<TwoHanded, Crossbow>();
}

inline void Item::CreatingTwoHandedRangedWeaponCarbineItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedRangedWeaponItems(iter, i);
    iter.entity(i).add_trait<TwoHanded, Carbine>();
}

inline void Item::CreatingTwoHandedRangedWeaponAssaultRifleItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedRangedWeaponItems(iter, i);
    iter.entity(i).add_trait<TwoHanded, AssaultRifle>();
}

inline void Item::CreatingTwoHandedRangedWeaponSniperRifleItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedRangedWeaponItems(iter, i);
    iter.entity(i).add_trait<TwoHanded, SniperRifle>();
}

inline void Item::CreatingTwoHandedRangedWeaponLightMachineGunItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedRangedWeaponItems(iter, i);
    iter.entity(i).add_trait<TwoHanded, LightMachineGun>();
}

inline void Item::CreatingTwoHandedRangedWeaponSubMachineGunItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedRangedWeaponItems(iter, i);
    iter.entity(i).add_trait<TwoHanded, SubMachineGun>();
}

inline void Item::CreatingTwoHandedRangedWeaponShotgunItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedRangedWeaponItems(iter, i);
    iter.entity(i).add_trait<TwoHanded, Shotgun>();
}

inline void Item::CreatingTwoHandedRangedWeaponGrenadeLauncherItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedRangedWeaponItems(iter, i);
    iter.entity(i).add_trait<TwoHanded, GrenadeLauncher>();
}

inline void Item::CreatingTwoHandedRangedWeaponRocketLauncherItems(flecs::iter& iter, int i)
{
    CreatingTwoHandedRangedWeaponItems(iter, i);
    iter.entity(i).add_trait<TwoHanded, RocketLauncher>();
}

#pragma endregion

#pragma region Creating Light PowerArmour

void Item::CreatingArmourPowerArmourLightItems(flecs::iter& iter, int i)
{
    iter.entity(i).add_trait<Item, Armour>();
    iter.entity(i).add_trait<Armour, PowerArmour>();
    iter.entity(i).add_trait<PowerArmour, LightPowerArmour>();
}

inline void Item::CreatingArmourPowerArmourLightHeadItems(flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourLightItems(iter, i);
    iter.entity(i).add_trait<LightPowerArmour, Head>();
}

inline void Item::CreatingArmourPowerArmourLightBeltItems(flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourLightItems(iter, i);
    iter.entity(i).add_trait<LightPowerArmour, Belt>();
}

inline void Item::CreatingArmourPowerArmourLightChestItems(flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourLightItems(iter, i);
    iter.entity(i).add_trait<LightPowerArmour, Chests>();
}

inline void Item::CreatingArmourPowerArmourLightLegsItems(flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourLightItems(iter, i);
    iter.entity(i).add_trait<LightPowerArmour, Legs>();
}

inline void Item::CreatingArmourPowerArmourLightArmsItems(flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourLightItems(iter, i);
    iter.entity(i).add_trait<LightPowerArmour, Arms>();
}

inline void Item::CreatingArmourPowerArmourLightHandsItems(flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourLightItems(iter, i);
    iter.entity(i).add_trait<LightPowerArmour, Hands>();
}

inline void Item::CreatingArmourPowerArmourLightShouldersItems(flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourLightItems(iter, i);
    iter.entity(i).add_trait<LightPowerArmour, Shoulders>();
}

inline void Item::CreatingArmourPowerArmourLightBackpackItems(flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourLightItems(iter, i);
    iter.entity(i).add_trait<LightPowerArmour, Backpack>();
}

#pragma endregion

#pragma region Creating Medium PowerArmour

void Item::CreatingArmourPowerArmourMediumItems(flecs::iter& iter, int i)
{
    iter.entity(i).add_trait<Item, Armour>();
    iter.entity(i).add_trait<Armour, PowerArmour>();
    iter.entity(i).add_trait<PowerArmour, MediumPowerArmour>();
}

inline void Item::CreatingArmourPowerArmourMediumHeadItems(flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourMediumItems(iter, i);
    iter.entity(i).add_trait<MediumPowerArmour, Head>();
}

inline void Item::CreatingArmourPowerArmourMediumBeltItems(flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourMediumItems(iter, i);
    iter.entity(i).add_trait<MediumPowerArmour, Belt>();
}

inline void Item::CreatingArmourPowerArmourMediumChestItems(flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourMediumItems(iter, i);
    iter.entity(i).add_trait<MediumPowerArmour, Chests>();
}

inline void Item::CreatingArmourPowerArmourMediumLegsItems(flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourMediumItems(iter, i);
    iter.entity(i).add_trait<MediumPowerArmour, Legs>();
}

inline void Item::CreatingArmourPowerArmourMediumArmsItems(flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourMediumItems(iter, i);
    iter.entity(i).add_trait<MediumPowerArmour, Arms>();
}

inline void Item::CreatingArmourPowerArmourMediumHandsItems(flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourMediumItems(iter, i);
    iter.entity(i).add_trait<MediumPowerArmour, Hands>();
}

inline void Item::CreatingArmourPowerArmourMediumShouldersItems(flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourMediumItems(iter, i);
    iter.entity(i).add_trait<MediumPowerArmour, Shoulders>();
}

inline void Item::CreatingArmourPowerArmourMediumBackpackItems(flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourMediumItems(iter, i);
    iter.entity(i).add_trait<MediumPowerArmour, Backpack>();
}

#pragma endregion

#pragma region Creating Heavy PowerArmour

inline void Item::CreatingArmourPowerArmourHeavyItems(flecs::iter& iter, int i)
{
    iter.entity(i).add_trait<Item, Armour>();
    iter.entity(i).add_trait<Armour, PowerArmour>();
    iter.entity(i).add_trait<PowerArmour, HeavyPowerArmour>();
}

inline void Item::CreatingArmourPowerArmourHeavyHeadItems(flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourHeavyItems(iter, i);
    iter.entity(i).add_trait<HeavyPowerArmour, Head>();
}

inline void Item::CreatingArmourPowerArmourHeavyBeltItems(flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourHeavyItems(iter, i);
    iter.entity(i).add_trait<HeavyPowerArmour, Belt>();
}

inline void Item::CreatingArmourPowerArmourHeavyChestItems(flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourHeavyItems(iter, i);
    iter.entity(i).add_trait<HeavyPowerArmour, Chests>();
}

inline void Item::CreatingArmourPowerArmourHeavyLegsItems(flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourHeavyItems(iter, i);
    iter.entity(i).add_trait<HeavyPowerArmour, Legs>();
}

inline void Item::CreatingArmourPowerArmourHeavyArmsItems(flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourHeavyItems(iter, i);
    iter.entity(i).add_trait<HeavyPowerArmour, Arms>();
}

inline void Item::CreatingArmourPowerArmourHeavyHandsItems(flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourHeavyItems(iter, i);
    iter.entity(i).add_trait<HeavyPowerArmour, Hands>();
}

inline void Item::CreatingArmourPowerArmourHeavyShouldersItems(flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourHeavyItems(iter, i);
    iter.entity(i).add_trait<HeavyPowerArmour, Shoulders>();
}

inline void Item::CreatingArmourPowerArmourHeavyBackpackItems(flecs::iter& iter, int i)
{
    CreatingArmourPowerArmourHeavyItems(iter, i);
    iter.entity(i).add_trait<HeavyPowerArmour, Backpack>();
}

#pragma endregion

#pragma region Creating NonPowerArmour

inline void Item::CreatingArmourNonPowerArmourItems(flecs::iter& iter, int i)
{
    iter.entity(i).add_trait<Item, Armour>();
    iter.entity(i).add_trait<Armour, NonPowerArmour>();
}

inline void Item::CreatingArmourNonPowerArmourHeadItems(flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<NonPowerArmour, Head>();
}

inline void Item::CreatingArmourNonPowerArmourBeltItems(flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<NonPowerArmour, Belt>();
}

inline void Item::CreatingArmourNonPowerArmourChestItems(flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<NonPowerArmour, Chests>();
}

inline void Item::CreatingArmourNonPowerArmourLegsItems(flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<NonPowerArmour, Legs>();
}

inline void Item::CreatingArmourNonPowerArmourArmsItems(flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<NonPowerArmour, Arms>();
}

inline void Item::CreatingArmourNonPowerArmourHandsItems(flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<NonPowerArmour, Hands>();
}

inline void Item::CreatingArmourNonPowerArmourShouldersItems(flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<NonPowerArmour, Shoulders>();
}

inline void Item::CreatingArmourNonPowerArmourBackpackItems(flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<NonPowerArmour, Backpack>();
}

#pragma endregion

#pragma region Creating Cloths Armour

void Item::CreatingArmourClothsItems(flecs::iter& iter, int i)
{
    iter.entity(i).add_trait<Item, Armour>();
    iter.entity(i).add_trait<Armour, Cloths>();
}

inline void Item::CreatingArmourClothsHeadItems(flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<Cloths, Head>();
}

inline void Item::CreatingArmourClothsBeltItems(flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<Cloths, Belt>();
}

inline void Item::CreatingArmourClothsChestItems(flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<Cloths, Chests>();
}

inline void Item::CreatingArmourClothsLegsItems(flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<Cloths, Legs>();
}

inline void Item::CreatingArmourClothsArmsItems(flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<Cloths, Arms>();
}

inline void Item::CreatingArmourClothsHandsItems(flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<Cloths, Hands>();
}

inline void Item::CreatingArmourClothsShouldersItems(flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<Cloths, Shoulders>();
}

inline void Item::CreatingArmourClothsBackpackItems(flecs::iter& iter, int i)
{
    CreatingArmourNonPowerArmourItems(iter, i);
    iter.entity(i).add_trait<Cloths, Backpack>();
}

inline void Item::CreatingEquipmentFlasks(flecs::iter& iter, int i)
{
    iter.entity(i).add_trait<Item, Equipment>();
    iter.entity(i).add_trait<Equipment, Flasks>();
}

inline void Item::CreatingEquipmentFlasksHealth(flecs::iter& iter, int i)
{
    CreatingEquipmentFlasks(iter, i);
    iter.entity(i).add_trait<Flasks, Health>();
}

inline void Item::CreatingEquipmentFlasksMagic(flecs::iter& iter, int i)
{
    CreatingEquipmentFlasks(iter, i);
    iter.entity(i).add_trait<Flasks, Magic>();
}

inline void Item::CreatingEquipmentFlasksMovement(flecs::iter& iter, int i)
{
    CreatingEquipmentFlasks(iter, i);
    iter.entity(i).add_trait<Flasks, Movement>();
}

inline void Item::CreatingEquipmentFlasksResistance(flecs::iter& iter, int i)
{
    CreatingEquipmentFlasks(iter, i);
    iter.entity(i).add_trait<Flasks, Resistance>();
}

inline void Item::CreatingEquipmentAmmo(flecs::iter& iter, int i)
{
    iter.entity(i).add_trait<Item, Equipment>();
    iter.entity(i).add_trait<Equipment, Ammo>();
}

inline void Item::CreatingEquipmentAmmoQuivers(flecs::iter& iter, int i)
{
    CreatingEquipmentAmmo(iter, i);
    iter.entity(i).add_trait<Equipment, Quivers>();
}

inline void Item::CreatingEquipmentAmmoMagazines(flecs::iter& iter, int i)
{
    CreatingEquipmentAmmo(iter, i);
    iter.entity(i).add_trait<Equipment, Magazines>();
}

inline void Item::CreatingEquipmentAmmoGrenades(flecs::iter& iter, int i)
{
    CreatingEquipmentAmmo(iter, i);
    iter.entity(i).add_trait<Equipment, Grenades>();
}

inline void Item::CreatingEquipmentAmmoRockets(flecs::iter& iter, int i)
{
    CreatingEquipmentAmmo(iter, i);
    iter.entity(i).add_trait<Equipment, Rockets>();
}

inline void Item::CreatingEquipmentAmmoMines(flecs::iter& iter, int i)
{
    CreatingEquipmentAmmo(iter, i);
    iter.entity(i).add_trait<Equipment, Mines>();
}

#pragma endregion

