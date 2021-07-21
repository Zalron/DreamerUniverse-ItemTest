#include "Item.h"

void Item::CreateItemEntity(const flecs::iter& iter, ItemComponents::ItemSpawning* is)
{
    for (auto it : iter)
    {
        for (auto i  = 0; i < is->NumberOfItems; i++) 
        {
            auto e = iter.world().entity();
            e.set<ItemComponents::ItemStaging>({ 1 });
            std::cout << "System CreateItemEntity has created item " << i << " " << std::endl;
        }
        iter.entity(it).remove<ItemComponents::ItemSpawning>();
        std::cout << "System CreateItemEntity is creating items" << std::endl;
    }
}

void Item::SettingSeedForRandomItemEntitiesGeneration(const flecs::iter& iter, ItemComponents::ItemStaging* iss)
{
    for (auto it : iter)
    {
       
        if (iss->ItemStage == 1)
        {
            int randomNumber = CreatingSeed();
            //std::cout << "System SettingSeedForRandomItemEntitiesGeneration has generated this number " << randomNumber << " for " << it << std::endl;
            iss->Seed = randomNumber;
            iss->ItemStage = 2;
        }
    }
}

void Item::AddItemComponentstoEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss)
{
    for (auto it : iter)
    {
        if (iss->ItemStage == 2)
        {
            int RandomItemGeneratrionNumber = CreatingRandom32BitIntNumbers(iss->Seed, 0, 1);
            if (RandomItemGeneratrionNumber == 0)
            {
                std::cout << "System AddItemComponentstoEntity is creating Item Craftable " << std::endl;
                //iter.entity(it).set<ItemComponents::ItemName>({});
                iter.entity(it).set<ItemComponents::ItemQuality>({});
            }
            else if (RandomItemGeneratrionNumber == 1)
            {
                std::cout << "System AddItemComponentstoEntity is creating Item Equipable " << std::endl;
                iter.entity(it).set<ItemComponents::ItemCharacterLevelRequirements>({});
                iter.entity(it).set<ItemComponents::ItemRarity>({});
                iter.entity(it).set<ItemComponents::ItemQuality>({});
                iter.entity(it).set<ItemComponents::ItemMaterial>({});
                iter.entity(it).set<ItemComponents::ItemManufacturer>({});
                //iter.entity(it).set<ItemComponents::ItemName>({});
            }
            iss->ItemStage = 3;
            std::cout << "System AddItemComponentstoEntity is creating Items " << std::endl;
        }
    }
}

void Item::AddItemStatComponentsToEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss, ItemComponents::ItemCharacterLevelRequirements* iclr, ItemComponents::ItemRarity* ir, ItemComponents::ItemQuality* iq, ItemComponents::ItemMaterial* im, ItemComponents::ItemManufacturer* imu)
{
    for (auto it : iter)
    {
        if (iss->ItemStage == 3)
        {
            int RandomItemGeneratrionNumber = CreatingRandom32BitIntNumbers(iss->Seed, 0, 2);
            if (RandomItemGeneratrionNumber == 0)
            {
                iter.entity(it).set<ItemComponents::CriticalChanceItemStat>({});
                iter.entity(it).set<ItemComponents::MagicalDamageItemStat>({});
                iter.entity(it).set<ItemComponents::PhysicalDamageItemStat>({});
                iter.entity(it).set<ItemComponents::HandlingItemStat>({});
                iter.entity(it).set<ItemComponents::AccuracyItemStat>({});
                iter.entity(it).set<ItemComponents::RangeItemStat>({});
                iter.entity(it).set<ItemComponents::GuardItemStat>({});
                iter.entity(it).set<ItemComponents::BlockChanceItemStat>({});
                iter.entity(it).set<ItemComponents::AttackRateItemStat>({});
                iter.entity(it).set<ItemComponents::WeightItemStat>({});
                iter.entity(it).add_trait<ItemComponents::EquipableItemTag, ItemComponents::WeaponsItemTag>();
                iter.entity(it).add_trait<ItemComponents::WeaponsItemTag, ItemComponents::MeleeItemTag>(); 
                std::cout << "System AddItemComponentstoEntity is creating Item Weapon Melee " << std::endl;
            }
            else if (RandomItemGeneratrionNumber == 1)
            {
                iter.entity(it).set<ItemComponents::CriticalChanceItemStat>({});
                iter.entity(it).set<ItemComponents::MagicalDamageItemStat>({});
                iter.entity(it).set<ItemComponents::PhysicalDamageItemStat>({});
                iter.entity(it).set<ItemComponents::HandlingItemStat>({});
                iter.entity(it).set<ItemComponents::AccuracyItemStat>({});
                iter.entity(it).set<ItemComponents::RangeItemStat>({});
                iter.entity(it).set<ItemComponents::MagazineSizeItemStat>({});
                iter.entity(it).set<ItemComponents::ReloadTimeItemStat>({});
                iter.entity(it).set<ItemComponents::FireRateItemStat>({});
                iter.entity(it).set<ItemComponents::WeightItemStat>({});
                iter.entity(it).add_trait<ItemComponents::EquipableItemTag, ItemComponents::WeaponsItemTag>();
                iter.entity(it).add_trait<ItemComponents::WeaponsItemTag, ItemComponents::RangedItemTag>();
                std::cout << "System AddItemComponentstoEntity is creating Item Weapon Ranged " << std::endl;
            }
            else if (RandomItemGeneratrionNumber == 2)
            {
                iter.entity(it).set<ItemComponents::ArmourItemStat>({});
                iter.entity(it).set<ItemComponents::ArmourRechargeRateItemStat>({});
                iter.entity(it).set<ItemComponents::ArmourRechargeDelayItemStat>({});
                iter.entity(it).set<ItemComponents::ShieldItemStat>({});
                iter.entity(it).set<ItemComponents::ShieldRechargeRateItemStat>({});
                iter.entity(it).set<ItemComponents::ShieldRechargeDelayItemStat>({});
                iter.entity(it).set<ItemComponents::EnergyItemStat>({});
                iter.entity(it).set<ItemComponents::EnergyRechargeRateItemStat>({});
                iter.entity(it).set<ItemComponents::EnergyRechargeDelayItemStat>({});
                iter.entity(it).set<ItemComponents::WeightItemStat>({});
                iter.entity(it).add_trait<ItemComponents::EquipableItemTag, ItemComponents::ArmourItemTag>();
                iter.entity(it).add_trait<ItemComponents::ArmourItemTag, ItemComponents::PowerArmourItemTag>();
                std::cout << "System AddItemComponentstoEntity is creating Item Armour PowerArmour " << std::endl;
            }
            iss->ItemStage = 4;
        }
    }
}

void  Item::AllItemMeleeTagComponentsToEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss, ItemComponents::CriticalChanceItemStat* ccis, ItemComponents::MagicalDamageItemStat* msis, ItemComponents::PhysicalDamageItemStat* pdis, ItemComponents::HandlingItemStat* his, ItemComponents::AccuracyItemStat* ais, ItemComponents::RangeItemStat* ris, ItemComponents::GuardItemStat* gis, ItemComponents::BlockChanceItemStat* dcis, ItemComponents::AttackRateItemStat* aris, ItemComponents::WeightItemStat* wis)
{
    for(auto it : iter)
    {
        if (iss->ItemStage == 4)
        {
            int RandomItemGeneratrionNumber = CreatingRandom32BitIntNumbers(iss->Seed, 0, 1);
            if (RandomItemGeneratrionNumber == 0)
            {
                int RandomItemGeneratrionNumber1 = CreatingRandom32BitIntNumbers(iss->Seed, 0, 7);
                iter.entity(it).add_trait<ItemComponents::MeleeItemTag, ItemComponents::OneHandedItemTag>();
                if (RandomItemGeneratrionNumber1 == 0)
                {
                    iter.entity(it).add_trait<ItemComponents::OneHandedItemTag, ItemComponents::SwordItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item OneHandedMeleeWeaponSword " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 1)
                {
                    iter.entity(it).add_trait<ItemComponents::OneHandedItemTag, ItemComponents::MaceItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item OneHandedMeleeWeaponMace " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 2)
                {
                    iter.entity(it).add_trait<ItemComponents::OneHandedItemTag, ItemComponents::KnifeItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item OneHandedMeleeWeaponKnife " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 3)
                {
                    iter.entity(it).add_trait<ItemComponents::OneHandedItemTag, ItemComponents::WarhammerItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item OneHandedMeleeWeaponWarhammer " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 4)
                {
                    iter.entity(it).add_trait<ItemComponents::OneHandedItemTag, ItemComponents::AxeItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item OneHandedMeleeWeaponAxe " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 5)
                {
                    iter.entity(it).add_trait<ItemComponents::OneHandedItemTag, ItemComponents::ShieldItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item OneHandedMeleeWeaponShield " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 6)
                {
                    iter.entity(it).add_trait<ItemComponents::OneHandedItemTag, ItemComponents::RapierItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item OneHandedMeleeWeaponRapier " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 7)
                {
                    iter.entity(it).add_trait<ItemComponents::OneHandedItemTag, ItemComponents::ClubItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item OneHandedMeleeWeaponClub " << std::endl;
                }
            }
            else if (RandomItemGeneratrionNumber == 1)
            {
                int RandomItemGeneratrionNumber1 = CreatingRandom32BitIntNumbers(iss->Seed, 0, 8);
                iter.entity(it).add_trait<ItemComponents::MeleeItemTag, ItemComponents::TwoHandedItemTag>();
                if (RandomItemGeneratrionNumber1 == 0)
                {
                    iter.entity(it).add_trait<ItemComponents::TwoHandedItemTag, ItemComponents::SwordItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponSword " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 1)
                {
                    iter.entity(it).add_trait<ItemComponents::TwoHandedItemTag, ItemComponents::MaceItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponMace " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 2)
                {
                    iter.entity(it).add_trait<ItemComponents::TwoHandedItemTag, ItemComponents::WarhammerItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponWarhammer " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 3)
                {
                    iter.entity(it).add_trait<ItemComponents::TwoHandedItemTag, ItemComponents::HalberdItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponHalberd " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 4)
                {
                    iter.entity(it).add_trait<ItemComponents::TwoHandedItemTag, ItemComponents::AxeItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponAxe " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 5)
                {
                    iter.entity(it).add_trait<ItemComponents::TwoHandedItemTag, ItemComponents::ClubItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponClub " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 6)
                {
                    iter.entity(it).add_trait<ItemComponents::TwoHandedItemTag, ItemComponents::StaffItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponStaff " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 7)
                {
                    iter.entity(it).add_trait<ItemComponents::TwoHandedItemTag, ItemComponents::SpearItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponSpeard " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 8)
                {
                    iter.entity(it).add_trait<ItemComponents::TwoHandedItemTag, ItemComponents::ClawsItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponClaws " << std::endl;
                }
            }
            iss->ItemStage = 5;
        }
    }
}

void Item::AllItemRangedTagComponentsToEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss, ItemComponents::CriticalChanceItemStat* ccis, ItemComponents::MagicalDamageItemStat* msis, ItemComponents::PhysicalDamageItemStat* pdis, ItemComponents::HandlingItemStat* his, ItemComponents::AccuracyItemStat* ais, ItemComponents::RangeItemStat* ris, ItemComponents::MagazineSizeItemStat* gis, ItemComponents::ReloadTimeItemStat* dcis, ItemComponents::FireRateItemStat* fris, ItemComponents::WeightItemStat* wis)
{
    for (auto it : iter)
    {
        if (iss->ItemStage == 4)
        {
            int RandomItemGeneratrionNumber = CreatingRandom32BitIntNumbers(iss->Seed, 0, 1);
            if (RandomItemGeneratrionNumber == 0)
            {
                int RandomItemGeneratrionNumber1 = CreatingRandom32BitIntNumbers(iss->Seed, 0, 4);
                iter.entity(it).add_trait<ItemComponents::RangedItemTag, ItemComponents::OneHandedItemTag>();
                if (RandomItemGeneratrionNumber1 == 0)
                {
                    iter.entity(it).add_trait<ItemComponents::OneHandedItemTag, ItemComponents::WandItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item OneHandedRangedWeaponWand " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 1)
                {
                    iter.entity(it).add_trait<ItemComponents::OneHandedItemTag, ItemComponents::ThrownItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item OneHandedRangedWeaponThrown " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 2)
                {
                    iter.entity(it).add_trait<ItemComponents::OneHandedItemTag, ItemComponents::PistolItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item OneHandedRangedWeaponPistol " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 3)
                {
                    iter.entity(it).add_trait<ItemComponents::OneHandedItemTag, ItemComponents::RevolverItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item OneHandedRangedWeaponRevolver " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 4)
                {
                    iter.entity(it).add_trait<ItemComponents::OneHandedItemTag, ItemComponents::HandCrossbowItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item OneHandedRangedWeaponHandCrossbow " << std::endl;
                }
            }
            else if (RandomItemGeneratrionNumber == 1)
            {
                int RandomItemGeneratrionNumber1 = CreatingRandom32BitIntNumbers(iss->Seed, 0, 9);
                iter.entity(it).add_trait<ItemComponents::RangedItemTag, ItemComponents::TwoHandedItemTag>();
                if (RandomItemGeneratrionNumber1 == 0)
                {
                    iter.entity(it).add_trait<ItemComponents::TwoHandedItemTag, ItemComponents::BowItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponBow " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 1)
                {
                    iter.entity(it).add_trait<ItemComponents::TwoHandedItemTag, ItemComponents::CrossbowItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponCrossbow " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 2)
                {
                    iter.entity(it).add_trait<ItemComponents::TwoHandedItemTag, ItemComponents::CarbineItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponCarbine " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 3)
                {
                    iter.entity(it).add_trait<ItemComponents::TwoHandedItemTag, ItemComponents::AssaultRifleItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponAssaultRifle " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 4)
                {
                    iter.entity(it).add_trait<ItemComponents::TwoHandedItemTag, ItemComponents::SniperRifleItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponSniperRifle " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 5)
                {
                    iter.entity(it).add_trait<ItemComponents::TwoHandedItemTag, ItemComponents::LightMachineGunItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponLightMachineGun " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 6)
                {
                    iter.entity(it).add_trait<ItemComponents::TwoHandedItemTag, ItemComponents::SubMachineGunItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponSubMachineGun " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 7)
                {
                    iter.entity(it).add_trait<ItemComponents::TwoHandedItemTag, ItemComponents::ShotgunItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponShotgun " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 8)
                {
                    iter.entity(it).add_trait<ItemComponents::TwoHandedItemTag, ItemComponents::GrenadeLauncherItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponGrenadeLauncher " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 9)
                {
                    iter.entity(it).add_trait<ItemComponents::TwoHandedItemTag, ItemComponents::RocketLauncherItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponRocketLauncher " << std::endl;
                }
            }
            iss->ItemStage = 5;
        }
    }
}

void Item::AllItemArmourTagComponentsToEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss, ItemComponents::ArmourItemStat* ais, ItemComponents::ArmourRechargeRateItemStat* arris, ItemComponents::ArmourRechargeDelayItemStat* ardis, ItemComponents::ShieldItemStat* sis, ItemComponents::ShieldRechargeRateItemStat* srris, ItemComponents::ShieldRechargeDelayItemStat* srdis, ItemComponents::EnergyItemStat* eis, ItemComponents::EnergyRechargeRateItemStat* erris, ItemComponents::EnergyRechargeDelayItemStat* erdis, ItemComponents::WeightItemStat* wis)
{
    for (auto it : iter)
    {
        if (iss->ItemStage == 4)
        {
            int RandomItemGeneratrionNumber = CreatingRandom32BitIntNumbers(iss->Seed, 0, 2);
            if (RandomItemGeneratrionNumber == 0)
            {
                int RandomItemGeneratrionNumber1 = CreatingRandom32BitIntNumbers(iss->Seed, 0, 7);
                iter.entity(it).add_trait<ItemComponents::PowerArmourItemTag, ItemComponents::LightPowerArmourItemTag>();
                if (RandomItemGeneratrionNumber1 == 0)
                {
                    iter.entity(it).add_trait<ItemComponents::LightPowerArmourItemTag, ItemComponents::HeadItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item LightPowerArmourHead " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 1)
                {
                    iter.entity(it).add_trait<ItemComponents::LightPowerArmourItemTag, ItemComponents::BeltItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item LightPowerArmourBelt " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 2)
                {
                    iter.entity(it).add_trait<ItemComponents::LightPowerArmourItemTag, ItemComponents::ChestsItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item LightPowerArmourChests " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 3)
                {
                    iter.entity(it).add_trait<ItemComponents::LightPowerArmourItemTag, ItemComponents::LegsItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item LightPowerArmourLegs " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 4)
                {
                    iter.entity(it).add_trait<ItemComponents::LightPowerArmourItemTag, ItemComponents::ArmsItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item LightPowerArmourArms " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 5)
                {
                    iter.entity(it).add_trait<ItemComponents::LightPowerArmourItemTag, ItemComponents::HandsItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item LightPowerArmourHands " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 6)
                {
                    iter.entity(it).add_trait<ItemComponents::LightPowerArmourItemTag, ItemComponents::ShouldersItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item LightPowerArmourShoulders " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 7)
                {
                    iter.entity(it).add_trait<ItemComponents::LightPowerArmourItemTag, ItemComponents::BackpackItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item LightPowerArmourBackpack " << std::endl;
                }
            }
            else if (RandomItemGeneratrionNumber == 1)
            {
                int RandomItemGeneratrionNumber1 = CreatingRandom32BitIntNumbers(iss->Seed, 0, 7);
                iter.entity(it).add_trait<ItemComponents::PowerArmourItemTag, ItemComponents::MediumPowerArmourItemTag>();
                if (RandomItemGeneratrionNumber1 == 0)
                {
                    iter.entity(it).add_trait<ItemComponents::MediumPowerArmourItemTag, ItemComponents::HeadItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item MediumPowerArmourHead " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 1)
                {
                    iter.entity(it).add_trait<ItemComponents::MediumPowerArmourItemTag, ItemComponents::BeltItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item MediumPowerArmourBelt " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 2)
                {
                    iter.entity(it).add_trait<ItemComponents::MediumPowerArmourItemTag, ItemComponents::ChestsItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item MediumPowerArmourChests " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 3)
                {
                    iter.entity(it).add_trait<ItemComponents::MediumPowerArmourItemTag, ItemComponents::LegsItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item MediumPowerArmourLegs " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 4)
                {
                    iter.entity(it).add_trait<ItemComponents::MediumPowerArmourItemTag, ItemComponents::ArmsItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item MediumPowerArmourArms " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 5)
                {
                    iter.entity(it).add_trait<ItemComponents::MediumPowerArmourItemTag, ItemComponents::HandsItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item MediumPowerArmourHands " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 6)
                {
                    iter.entity(it).add_trait<ItemComponents::MediumPowerArmourItemTag, ItemComponents::ShouldersItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item MediumPowerArmourShoulders " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 7)
                {
                    iter.entity(it).add_trait<ItemComponents::MediumPowerArmourItemTag, ItemComponents::BackpackItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item MediumPowerArmourBackpack " << std::endl;
                }
            }
            else if (RandomItemGeneratrionNumber == 2)
            {
                int RandomItemGeneratrionNumber1 = CreatingRandom32BitIntNumbers(iss->Seed, 0, 7);
                iter.entity(it).add_trait<ItemComponents::PowerArmourItemTag, ItemComponents::HeavyPowerArmourItemTag>();
                if (RandomItemGeneratrionNumber1 == 0)
                {
                    iter.entity(it).add_trait<ItemComponents::HeavyPowerArmourItemTag, ItemComponents::HeadItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item HeavyPowerArmourHead " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 1)
                {
                    iter.entity(it).add_trait<ItemComponents::HeavyPowerArmourItemTag, ItemComponents::BeltItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item HeavyPowerArmourBelt " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 2)
                {
                    iter.entity(it).add_trait<ItemComponents::HeavyPowerArmourItemTag, ItemComponents::ChestsItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item HeavyPowerArmourChests " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 3)
                {
                    iter.entity(it).add_trait<ItemComponents::HeavyPowerArmourItemTag, ItemComponents::LegsItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item HeavyPowerArmourLegs " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 4)
                {
                    iter.entity(it).add_trait<ItemComponents::HeavyPowerArmourItemTag, ItemComponents::ArmsItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item HeavyPowerArmourArms " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 5)
                {
                    iter.entity(it).add_trait<ItemComponents::HeavyPowerArmourItemTag, ItemComponents::HandsItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item HeavyPowerArmourHands " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 6)
                {
                    iter.entity(it).add_trait<ItemComponents::HeavyPowerArmourItemTag, ItemComponents::ShouldersItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item HeavyPowerArmourShoulders " << std::endl;
                }
                else if (RandomItemGeneratrionNumber1 == 7)
                {
                    iter.entity(it).add_trait<ItemComponents::HeavyPowerArmourItemTag, ItemComponents::BackpackItemTag>();
                    std::cout << "System AddItemComponentstoEntity is creating Item HeavyPowerArmourBackpack " << std::endl;
                }
            }
            iss->ItemStage = 5;
        }
    }
}

//#pragma endregion
//
//#pragma region Creating NonPowerArmour
//
//inline void Item::CreatingArmourNonPowerArmourItems(const flecs::iter& iter, size_t i, int randomRarity)
//{
//    iter.entity(i).add_trait<Item, Armour>();
//    iter.entity(i).add_trait<Armour, NonPowerArmour>();
//}
//
//inline void Item::CreatingArmourNonPowerArmourHeadItems(const flecs::iter& iter, size_t i, int randomRarity)
//{
//    CreatingArmourNonPowerArmourItems(iter, i, randomRarity);
//    iter.entity(i).add_trait<NonPowerArmour, Head>();
//}
//
//inline void Item::CreatingArmourNonPowerArmourBeltItems(const flecs::iter& iter, size_t i, int randomRarity)
//{
//    CreatingArmourNonPowerArmourItems(iter, i, randomRarity);
//    iter.entity(i).add_trait<NonPowerArmour, Belt>();
//}
//
//inline void Item::CreatingArmourNonPowerArmourChestItems(const flecs::iter& iter, size_t i, int randomRarity)
//{
//    CreatingArmourNonPowerArmourItems(iter, i, randomRarity);
//    iter.entity(i).add_trait<NonPowerArmour, Chests>();
//}
//
//inline void Item::CreatingArmourNonPowerArmourLegsItems(const flecs::iter& iter, size_t i, int randomRarity)
//{
//    CreatingArmourNonPowerArmourItems(iter, i, randomRarity);
//    iter.entity(i).add_trait<NonPowerArmour, Legs>();
//}
//
//inline void Item::CreatingArmourNonPowerArmourArmsItems(const flecs::iter& iter, size_t i, int randomRarity)
//{
//    CreatingArmourNonPowerArmourItems(iter, i, randomRarity);
//    iter.entity(i).add_trait<NonPowerArmour, Arms>();
//}
//
//inline void Item::CreatingArmourNonPowerArmourHandsItems(const flecs::iter& iter, size_t i, int randomRarity)
//{
//    CreatingArmourNonPowerArmourItems(iter, i, randomRarity);
//    iter.entity(i).add_trait<NonPowerArmour, Hands>();
//}
//
//inline void Item::CreatingArmourNonPowerArmourShouldersItems(const flecs::iter& iter, size_t i, int randomRarity)
//{
//    CreatingArmourNonPowerArmourItems(iter, i, randomRarity);
//    iter.entity(i).add_trait<NonPowerArmour, Shoulders>();
//}
//
//inline void Item::CreatingArmourNonPowerArmourBackpackItems(const flecs::iter& iter, size_t i, int randomRarity)
//{
//    CreatingArmourNonPowerArmourItems(iter, i, randomRarity);
//    iter.entity(i).add_trait<NonPowerArmour, Backpack>();
//}
//
//#pragma endregion
//
//#pragma region Creating Cloths Armour
//
//inline void Item::CreatingArmourClothsItems(const flecs::iter& iter, size_t i)
//{
//    iter.entity(i).add_trait<Item, Armour>();
//    iter.entity(i).add_trait<Armour, Cloths>();
//}
//
//inline void Item::CreatingArmourClothsHeadItems(const flecs::iter& iter, size_t i)
//{
//    CreatingArmourClothsItems(iter, i);
//    iter.entity(i).add_trait<Cloths, Head>();
//}
//
//inline void Item::CreatingArmourClothsBeltItems(const flecs::iter& iter, size_t i)
//{
//    CreatingArmourClothsItems(iter, i);
//    iter.entity(i).add_trait<Cloths, Belt>();
//}
//
//inline void Item::CreatingArmourClothsChestItems(const flecs::iter& iter, size_t i)
//{
//    CreatingArmourClothsItems(iter, i);
//    iter.entity(i).add_trait<Cloths, Chests>();
//}
//
//inline void Item::CreatingArmourClothsLegsItems(const flecs::iter& iter, size_t i)
//{
//    CreatingArmourClothsItems(iter, i);
//    iter.entity(i).add_trait<Cloths, Legs>();
//}
//
//inline void Item::CreatingArmourClothsArmsItems(const flecs::iter& iter, size_t i)
//{
//    CreatingArmourClothsItems(iter, i);
//    iter.entity(i).add_trait<Cloths, Arms>();
//}
//
//inline void Item::CreatingArmourClothsHandsItems(const flecs::iter& iter, size_t i)
//{
//    CreatingArmourClothsItems(iter, i);
//    iter.entity(i).add_trait<Cloths, Hands>();
//}
//
//inline void Item::CreatingArmourClothsShouldersItems(const flecs::iter& iter, size_t i)
//{
//    CreatingArmourClothsItems(iter, i);
//    iter.entity(i).add_trait<Cloths, Shoulders>();
//}
//
//inline void Item::CreatingArmourClothsBackpackItems(const flecs::iter& iter, size_t i)
//{
//    CreatingArmourClothsItems(iter, i);
//    iter.entity(i).add_trait<Cloths, Backpack>();
//}

void Item::CreatingRarityComponentsToEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss, ItemComponents::ItemRarity* ir)
{
    for (auto it : iter)
    {
        if(iss->ItemStage == 5)
        {
            float RarityRoll = CreatingRandom32BitFloatNumbers(iss->Seed, 0.0f, ItemRarity12.RaritySpawnChanceMax);
            //std::cout << "Random Rarity number generated " << RarityRoll << std::endl;
            if (RarityRoll >= ItemRarity1.RaritySpawnChanceMin && RarityRoll < ItemRarity1.RaritySpawnChanceMax)
            {
                ir->RarityAffixAllowance = ItemRarity1.RarityAffixAllowance;
                ir->RarityLevel = ItemRarity1.RarityLevel;
                ir->RarityIntRoll = CreatingRandom32BitIntNumbers(iss->Seed, ItemRarity1.RarityIntRollMin, ItemRarity1.RarityIntRollMax);
                ir->RarityFloatRoll = CreatingRandom32BitFloatNumbers(iss->Seed, ItemRarity1.RarityFloatRollMin, ItemRarity1.RarityFloatRollMax);
            }
            else if (RarityRoll >= ItemRarity2.RaritySpawnChanceMin && RarityRoll < ItemRarity2.RaritySpawnChanceMax)
            {
                ir->RarityAffixAllowance = ItemRarity2.RarityAffixAllowance;
                ir->RarityLevel = ItemRarity2.RarityLevel;
                ir->RarityIntRoll = CreatingRandom32BitIntNumbers(iss->Seed, ItemRarity2.RarityIntRollMin, ItemRarity2.RarityIntRollMax);
                ir->RarityFloatRoll = CreatingRandom32BitFloatNumbers(iss->Seed, ItemRarity2.RarityFloatRollMin, ItemRarity2.RarityFloatRollMax);
            }
            else if (RarityRoll >= ItemRarity3.RaritySpawnChanceMin && RarityRoll < ItemRarity3.RaritySpawnChanceMax)
            {
                ir->RarityAffixAllowance = ItemRarity3.RarityAffixAllowance;
                ir->RarityLevel = ItemRarity3.RarityLevel;
                ir->RarityIntRoll = CreatingRandom32BitIntNumbers(iss->Seed, ItemRarity3.RarityIntRollMin, ItemRarity3.RarityIntRollMax);
                ir->RarityFloatRoll = CreatingRandom32BitFloatNumbers(iss->Seed, ItemRarity3.RarityFloatRollMin, ItemRarity3.RarityFloatRollMax);
            }
            else if (RarityRoll >= ItemRarity4.RaritySpawnChanceMin && RarityRoll < ItemRarity4.RaritySpawnChanceMax)
            {
                ir->RarityAffixAllowance = ItemRarity4.RarityAffixAllowance;
                ir->RarityLevel = ItemRarity4.RarityLevel;
                ir->RarityIntRoll = CreatingRandom32BitIntNumbers(iss->Seed, ItemRarity4.RarityIntRollMin, ItemRarity4.RarityIntRollMax);
                ir->RarityFloatRoll = CreatingRandom32BitFloatNumbers(iss->Seed, ItemRarity6.RarityFloatRollMin, ItemRarity4.RarityFloatRollMax);
            }
            else if (RarityRoll >= ItemRarity5.RaritySpawnChanceMin && RarityRoll < ItemRarity5.RaritySpawnChanceMax)
            {
                ir->RarityAffixAllowance = ItemRarity5.RarityAffixAllowance;
                ir->RarityLevel = ItemRarity5.RarityLevel;
                ir->RarityIntRoll = CreatingRandom32BitIntNumbers(iss->Seed, ItemRarity5.RarityIntRollMin, ItemRarity5.RarityIntRollMax);
                ir->RarityFloatRoll = CreatingRandom32BitFloatNumbers(iss->Seed, ItemRarity5.RarityFloatRollMin, ItemRarity5.RarityFloatRollMax);
            }
            else if (RarityRoll >= ItemRarity6.RaritySpawnChanceMin && RarityRoll < ItemRarity6.RaritySpawnChanceMax)
            {
                ir->RarityAffixAllowance = ItemRarity6.RarityAffixAllowance;
                ir->RarityLevel = ItemRarity6.RarityLevel;
                ir->RarityIntRoll = CreatingRandom32BitIntNumbers(iss->Seed, ItemRarity6.RarityIntRollMin, ItemRarity6.RarityIntRollMax);
                ir->RarityFloatRoll = CreatingRandom32BitFloatNumbers(iss->Seed, ItemRarity6.RarityFloatRollMin, ItemRarity6.RarityFloatRollMax);
            }
            else if (RarityRoll >= ItemRarity7.RaritySpawnChanceMin && RarityRoll < ItemRarity7.RaritySpawnChanceMax)
            {
                ir->RarityAffixAllowance = ItemRarity7.RarityAffixAllowance;
                ir->RarityLevel = ItemRarity7.RarityLevel;
                ir->RarityIntRoll = CreatingRandom32BitIntNumbers(iss->Seed, ItemRarity7.RarityIntRollMin, ItemRarity7.RarityIntRollMax);
                ir->RarityFloatRoll = CreatingRandom32BitFloatNumbers(iss->Seed, ItemRarity7.RarityFloatRollMin, ItemRarity7.RarityFloatRollMax);
            }
            else if (RarityRoll >= ItemRarity8.RaritySpawnChanceMin && RarityRoll < ItemRarity8.RaritySpawnChanceMax)
            {
                ir->RarityAffixAllowance = ItemRarity8.RarityAffixAllowance;
                ir->RarityLevel = ItemRarity8.RarityLevel;
                ir->RarityIntRoll = CreatingRandom32BitIntNumbers(iss->Seed, ItemRarity8.RarityIntRollMin, ItemRarity8.RarityIntRollMax);
                ir->RarityFloatRoll = CreatingRandom32BitFloatNumbers(iss->Seed, ItemRarity8.RarityFloatRollMin, ItemRarity8.RarityFloatRollMax);
            }
            else if (RarityRoll >= ItemRarity9.RaritySpawnChanceMin && RarityRoll < ItemRarity9.RaritySpawnChanceMax)
            {
                ir->RarityAffixAllowance = ItemRarity9.RarityAffixAllowance;
                ir->RarityLevel = ItemRarity9.RarityLevel;
                ir->RarityIntRoll = CreatingRandom32BitIntNumbers(iss->Seed, ItemRarity9.RarityIntRollMin, ItemRarity9.RarityIntRollMax);
                ir->RarityFloatRoll = CreatingRandom32BitFloatNumbers(iss->Seed, ItemRarity9.RarityFloatRollMin, ItemRarity9.RarityFloatRollMax);
            }
            else if (RarityRoll >= ItemRarity10.RaritySpawnChanceMin && RarityRoll < ItemRarity10.RaritySpawnChanceMax)
            {
                ir->RarityAffixAllowance = ItemRarity10.RarityAffixAllowance;
                ir->RarityLevel = ItemRarity10.RarityLevel;
                ir->RarityIntRoll = CreatingRandom32BitIntNumbers(iss->Seed, ItemRarity10.RarityIntRollMin, ItemRarity10.RarityIntRollMax);
                ir->RarityFloatRoll = CreatingRandom32BitFloatNumbers(iss->Seed, ItemRarity10.RarityFloatRollMin, ItemRarity10.RarityFloatRollMax);
            }
            else if (RarityRoll >= ItemRarity11.RaritySpawnChanceMin && RarityRoll < ItemRarity11.RaritySpawnChanceMax)
            {
                ir->RarityAffixAllowance = ItemRarity11.RarityAffixAllowance;
                ir->RarityLevel = ItemRarity11.RarityLevel;
                ir->RarityIntRoll = CreatingRandom32BitIntNumbers(iss->Seed, ItemRarity11.RarityIntRollMin, ItemRarity11.RarityIntRollMax);
                ir->RarityFloatRoll = CreatingRandom32BitFloatNumbers(iss->Seed, ItemRarity11.RarityFloatRollMin, ItemRarity11.RarityFloatRollMax);
            }
            else if (RarityRoll >= ItemRarity12.RaritySpawnChanceMin && RarityRoll <= ItemRarity12.RaritySpawnChanceMax)
            {
                ir->RarityAffixAllowance = ItemRarity12.RarityAffixAllowance;
                ir->RarityLevel = ItemRarity12.RarityLevel;
                ir->RarityIntRoll = CreatingRandom32BitIntNumbers(iss->Seed, ItemRarity12.RarityIntRollMin, ItemRarity12.RarityIntRollMax);
                ir->RarityFloatRoll = CreatingRandom32BitFloatNumbers(iss->Seed, ItemRarity12.RarityFloatRollMin, ItemRarity12.RarityFloatRollMax);
            }
            else
            {
                std::cout << "System CreatingRarityComponentsToEntity has number generated out of range" << RarityRoll << " " << std::endl;
            }
            iss->ItemStage = 6;
            std::cout << "System CreatingRarityComponentsToEntity has run " << std::endl;
        }
    }
}


void Item::CreatingRarityModComponentsToEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss, ItemComponents::ItemRarity* ir)
{
    for (auto it : iter)
    {
        if (iss->ItemStage == 6)
        {
            if (ir->RarityAffixAllowance == 1)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods1>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 1 ItemAffixMod component " << std::endl;
            }
            else if (ir->RarityAffixAllowance == 2)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods1>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods2>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 2 ItemAffixMod component " << std::endl;
            }
            else if (ir->RarityAffixAllowance == 3)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods1>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods2>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods3>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 3 ItemAffixMod component " << std::endl;
            }
            else if (ir->RarityAffixAllowance == 4)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods1>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods2>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods3>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods4>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 4 ItemAffixMod component " << std::endl;
            }
            else if (ir->RarityAffixAllowance == 5)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods1>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods2>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods3>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods4>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods5>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 5 ItemAffixMod component " << std::endl;
            }
            else if (ir->RarityAffixAllowance == 6)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods1>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods2>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods3>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods4>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods5>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods6>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 6 ItemAffixMod component " << std::endl;
            }
            else if (ir->RarityAffixAllowance == 7)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods1>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods2>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods3>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods4>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods5>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods6>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods7>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 7 ItemAffixMod component " << std::endl;
            }
            else if (ir->RarityAffixAllowance == 8)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods1>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods2>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods3>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods4>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods5>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods6>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods7>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods8>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 8 ItemAffixMod component " << std::endl;
            }
            else if (ir->RarityAffixAllowance == 9)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods1>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods2>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods3>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods4>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods5>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods6>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods7>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods8>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods9>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 9 ItemAffixMod component " << std::endl;
            }
            else if (ir->RarityAffixAllowance == 10)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods1>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods2>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods3>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods4>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods5>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods6>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods7>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods8>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods9>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods10>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 10 ItemAffixMod component " << std::endl;
            }
            else if (ir->RarityAffixAllowance == 11)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods1>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods2>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods3>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods4>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods5>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods6>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods7>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods8>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods9>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods10>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 10 ItemAffixMod component " << std::endl;
            }
            else 
            {
                std::cout << "System CreatingRarityModComponentsToEntity has add 0 ItemAffixMod component " << std::endl;
            }
            iss->ItemStage = 7;
            std::cout << "System CreatingRarityModComponentsToEntity has add ItemAffixMod component " << std::endl;
        }
    }
}

void Item::CreatingQualityComponentToEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss, ItemComponents::ItemQuality* iq)
{
    for (auto it : iter) 
    {
        if (iss->ItemStage == 7) 
        {
            float ItemQuality = CreatingRandom32BitFloatNumbers(iss->Seed, 0.0f, ItemQualityConfig20.QualitySpawnChanceMax);
            if (ItemQuality >= ItemQualityConfig0.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig0.QualitySpawnChanceMax)
            {
                iq->QualityNum = ItemQualityConfig0.QualityNum;
                iq->QualityIntStatIncrease = ItemQualityConfig0.QualityIntStatIncrease;
                iq->QualityFloatStatIncrease = ItemQualityConfig0.QualityFloatStatIncrease;
                std::cout << "System CreatingQualityComponentToEntityy has added Quality 0 to items " << std::endl;
            }
            else if (ItemQuality >= ItemQualityConfig1.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig1.QualitySpawnChanceMax)
            {
                iq->QualityNum = ItemQualityConfig1.QualityNum;
                iq->QualityIntStatIncrease = ItemQualityConfig1.QualityIntStatIncrease;
                iq->QualityFloatStatIncrease = ItemQualityConfig1.QualityFloatStatIncrease;
                std::cout << "System CreatingQualityComponentToEntityy has added Quality 1 to items " << std::endl;
            }
            else if (ItemQuality >= ItemQualityConfig2.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig2.QualitySpawnChanceMax)
            {
                iq->QualityNum = ItemQualityConfig2.QualityNum;
                iq->QualityIntStatIncrease = ItemQualityConfig2.QualityIntStatIncrease;
                iq->QualityFloatStatIncrease = ItemQualityConfig2.QualityFloatStatIncrease;;
                std::cout << "System CreatingQualityComponentToEntityy has added Quality 2 to items " << std::endl;
            }
            else if (ItemQuality >= ItemQualityConfig3.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig3.QualitySpawnChanceMax)
            {
                iq->QualityNum = ItemQualityConfig3.QualityNum;
                iq->QualityIntStatIncrease = ItemQualityConfig3.QualityIntStatIncrease;
                iq->QualityFloatStatIncrease = ItemQualityConfig3.QualityFloatStatIncrease;
                std::cout << "System CreatingQualityComponentToEntityy has added Quality 3 to items " << std::endl;
            }
            else if (ItemQuality >= ItemQualityConfig4.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig4.QualitySpawnChanceMax)
            {
                iq->QualityNum = ItemQualityConfig4.QualityNum;
                iq->QualityIntStatIncrease = ItemQualityConfig4.QualityIntStatIncrease;
                iq->QualityFloatStatIncrease = ItemQualityConfig4.QualityFloatStatIncrease;
                std::cout << "System CreatingQualityComponentToEntityy has added Quality 4 to items " << std::endl;
            }
            else if (ItemQuality >= ItemQualityConfig5.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig5.QualitySpawnChanceMax)
            {
                iq->QualityNum = ItemQualityConfig5.QualityNum;
                iq->QualityIntStatIncrease = ItemQualityConfig5.QualityIntStatIncrease;
                iq->QualityFloatStatIncrease = ItemQualityConfig5.QualityFloatStatIncrease;
                std::cout << "System CreatingQualityComponentToEntityy has added Quality 5 to items " << std::endl;
            }
            else if (ItemQuality >= ItemQualityConfig6.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig6.QualitySpawnChanceMax)
            {
                iq->QualityNum = ItemQualityConfig6.QualityNum;
                iq->QualityIntStatIncrease = ItemQualityConfig6.QualityIntStatIncrease;
                iq->QualityFloatStatIncrease = ItemQualityConfig6.QualityFloatStatIncrease;
                std::cout << "System CreatingQualityComponentToEntityy has added Quality 6 to items " << std::endl;
            }
            else if (ItemQuality >= ItemQualityConfig7.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig7.QualitySpawnChanceMax)
            {
                iq->QualityNum = ItemQualityConfig7.QualityNum;
                iq->QualityIntStatIncrease = ItemQualityConfig7.QualityIntStatIncrease;
                iq->QualityFloatStatIncrease = ItemQualityConfig7.QualityFloatStatIncrease;
                std::cout << "System CreatingQualityComponentToEntityy has added Quality 7 to items " << std::endl;
            }
            else if (ItemQuality >= ItemQualityConfig8.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig8.QualitySpawnChanceMax)
            {
                iq->QualityNum = ItemQualityConfig8.QualityNum;
                iq->QualityIntStatIncrease = ItemQualityConfig8.QualityIntStatIncrease;
                iq->QualityFloatStatIncrease = ItemQualityConfig8.QualityFloatStatIncrease;
                std::cout << "System CreatingQualityComponentToEntityy has added Quality 8 to items " << std::endl;
            }
            else if (ItemQuality >= ItemQualityConfig9.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig9.QualitySpawnChanceMax)
            {
                iq->QualityNum = ItemQualityConfig9.QualityNum;
                iq->QualityIntStatIncrease = ItemQualityConfig9.QualityIntStatIncrease;
                iq->QualityFloatStatIncrease = ItemQualityConfig9.QualityFloatStatIncrease;
                std::cout << "System CreatingQualityComponentToEntityy has added Quality 9 to items " << std::endl;
            }
            else if (ItemQuality >= ItemQualityConfig10.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig10.QualitySpawnChanceMax)
            {
                iq->QualityNum = ItemQualityConfig10.QualityNum;
                iq->QualityIntStatIncrease = ItemQualityConfig10.QualityIntStatIncrease;
                iq->QualityFloatStatIncrease = ItemQualityConfig10.QualityFloatStatIncrease;
                std::cout << "System CreatingQualityComponentToEntityy has added Quality 10 to items " << std::endl;
            }
            else if (ItemQuality >= ItemQualityConfig11.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig11.QualitySpawnChanceMax)
            {
                iq->QualityNum = ItemQualityConfig11.QualityNum;
                iq->QualityIntStatIncrease = ItemQualityConfig11.QualityIntStatIncrease;
                iq->QualityFloatStatIncrease = ItemQualityConfig11.QualityFloatStatIncrease;
                std::cout << "System CreatingQualityComponentToEntityy has added Quality 11 to items " << std::endl;
            }
            else if (ItemQuality >= ItemQualityConfig12.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig12.QualitySpawnChanceMax)
            {
                iq->QualityNum = ItemQualityConfig12.QualityNum;
                iq->QualityIntStatIncrease = ItemQualityConfig12.QualityIntStatIncrease;
                iq->QualityFloatStatIncrease = ItemQualityConfig12.QualityFloatStatIncrease;
                std::cout << "System CreatingQualityComponentToEntityy has added Quality 12 to items " << std::endl;
            }
            else if (ItemQuality >= ItemQualityConfig13.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig13.QualitySpawnChanceMax)
            {
                iq->QualityNum = ItemQualityConfig13.QualityNum;
                iq->QualityIntStatIncrease = ItemQualityConfig13.QualityIntStatIncrease;
                iq->QualityFloatStatIncrease = ItemQualityConfig13.QualityFloatStatIncrease;
                std::cout << "System CreatingQualityComponentToEntityy has added Quality 13 to items " << std::endl;
            }
            else if (ItemQuality >= ItemQualityConfig14.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig14.QualitySpawnChanceMax)
            {
                iq->QualityNum = ItemQualityConfig14.QualityNum;
                iq->QualityIntStatIncrease = ItemQualityConfig14.QualityIntStatIncrease;
                iq->QualityFloatStatIncrease = ItemQualityConfig14.QualityFloatStatIncrease;
                std::cout << "System CreatingQualityComponentToEntityy has added Quality 14 to items " << std::endl;
            }
            else if (ItemQuality >= ItemQualityConfig15.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig15.QualitySpawnChanceMax)
            {
                iq->QualityNum = ItemQualityConfig15.QualityNum;
                iq->QualityIntStatIncrease = ItemQualityConfig15.QualityIntStatIncrease;
                iq->QualityFloatStatIncrease = ItemQualityConfig15.QualityFloatStatIncrease;
                std::cout << "System CreatingQualityComponentToEntityy has added Quality 15 to items " << std::endl;
            }
            else if (ItemQuality >= ItemQualityConfig16.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig16.QualitySpawnChanceMax)
            {
                iq->QualityNum = ItemQualityConfig16.QualityNum;
                iq->QualityIntStatIncrease = ItemQualityConfig16.QualityIntStatIncrease;
                iq->QualityFloatStatIncrease = ItemQualityConfig16.QualityFloatStatIncrease;
                std::cout << "System CreatingQualityComponentToEntityy has added Quality 16 to items " << std::endl;
            }
            else if (ItemQuality >= ItemQualityConfig17.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig17.QualitySpawnChanceMax)
            {
                iq->QualityNum = ItemQualityConfig17.QualityNum;
                iq->QualityIntStatIncrease = ItemQualityConfig17.QualityIntStatIncrease;
                iq->QualityFloatStatIncrease = ItemQualityConfig17.QualityFloatStatIncrease;
                std::cout << "System CreatingQualityComponentToEntityy has added Quality 17 to items " << std::endl;
            }
            else if (ItemQuality >= ItemQualityConfig18.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig18.QualitySpawnChanceMax)
            {
                iq->QualityNum = ItemQualityConfig18.QualityNum;
                iq->QualityIntStatIncrease = ItemQualityConfig18.QualityIntStatIncrease;
                iq->QualityFloatStatIncrease = ItemQualityConfig18.QualityFloatStatIncrease;
                std::cout << "System CreatingQualityComponentToEntityy has added Quality 18 to items " << std::endl;
            }
            else if (ItemQuality >= ItemQualityConfig19.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig19.QualitySpawnChanceMax)
            {
                iq->QualityNum = ItemQualityConfig19.QualityNum;
                iq->QualityIntStatIncrease = ItemQualityConfig19.QualityIntStatIncrease;
                iq->QualityFloatStatIncrease = ItemQualityConfig19.QualityFloatStatIncrease;
                std::cout << "System CreatingQualityComponentToEntityy has added Quality 19 to items " << std::endl;
            }
            else if (ItemQuality >= ItemQualityConfig20.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig20.QualitySpawnChanceMax)
            {
                iq->QualityNum = ItemQualityConfig20.QualityNum;
                iq->QualityIntStatIncrease = ItemQualityConfig20.QualityIntStatIncrease;
                iq->QualityFloatStatIncrease = ItemQualityConfig20.QualityFloatStatIncrease;
                std::cout << "System CreatingQualityComponentToEntityy has added Quality 20 to items " << std::endl;
            }
            iss->ItemStage = 8;
        }
    }
}

void Item::RemovingItemStagingComponentsFromEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss)
{
    for (auto it : iter)
    {
        if (iss->ItemStage == 8)
        {
            iss->ItemStage = 9;
            iter.entity(it).remove<ItemComponents::ItemStaging>();
            //std::cout << "System RemovingItemStagingComponentsFromEntity is removeing ItemStaging from Items " << it << " " << std::endl;
        }
    }
}

inline int Item::CreatingSeed()
{
    std::random_device rand32;
    std::mt19937 gen(rand32());
    std::uniform_int_distribution<> randomNumber32(0, INT32_MAX);
    int randomNumber = randomNumber32(gen);
    return randomNumber;
}

inline int Item::CreatingRandom32BitIntNumbers(int seed, int min, int max)
{
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> randomNumber32(min, max);
    int randomNumber = randomNumber32(gen);
    return randomNumber;
}

inline float Item::CreatingRandom32BitFloatNumbers(int seed, float min, float max) 
{
    std::mt19937 gen(seed);
    std::uniform_real_distribution<float> randomNumber32(min, max);
    float randomNumber = randomNumber32(gen);
    return randomNumber;
}

//
//inline void Item::CreatingEquipmentFlasks(const flecs::iter& iter, size_t i)
//{
//    iter.entity(i).add_trait<Item, Equipment>();
//    iter.entity(i).add_trait<Equipment, Flasks>();
//}
//
//inline void Item::CreatingEquipmentFlasksHealth(const flecs::iter& iter, size_t i)
//{
//    CreatingEquipmentFlasks(iter, i);
//    iter.entity(i).add_trait<Flasks, Health>();
//}
//
//inline void Item::CreatingEquipmentFlasksMagic(const flecs::iter& iter, size_t i)
//{
//    CreatingEquipmentFlasks(iter, i);
//    iter.entity(i).add_trait<Flasks, Magic>();
//}
//
//inline void Item::CreatingEquipmentFlasksMovement(const flecs::iter& iter, size_t i)
//{
//    CreatingEquipmentFlasks(iter, i);
//    iter.entity(i).add_trait<Flasks, Movement>();
//}
//
//inline void Item::CreatingEquipmentFlasksResistance(const flecs::iter& iter, size_t i)
//{
//    CreatingEquipmentFlasks(iter, i);
//    iter.entity(i).add_trait<Flasks, Resistance>();
//}
//
//inline void Item::CreatingEquipmentAmmo(const flecs::iter& iter, size_t i)
//{
//    iter.entity(i).add_trait<Item, Equipment>();
//    iter.entity(i).add_trait<Equipment, Ammo>();
//}
//
//inline void Item::CreatingEquipmentAmmoQuivers(const flecs::iter& iter, size_t i)
//{
//    CreatingEquipmentAmmo(iter, i);
//    iter.entity(i).add_trait<Equipment, Quivers>();
//}
//
//inline void Item::CreatingEquipmentAmmoMagazines(const flecs::iter& iter, size_t i)
//{
//    CreatingEquipmentAmmo(iter, i);
//    iter.entity(i).add_trait<Equipment, Magazines>();
//}
//
//inline void Item::CreatingEquipmentAmmoGrenades(const flecs::iter& iter, size_t i)
//{
//    CreatingEquipmentAmmo(iter, i);
//    iter.entity(i).add_trait<Equipment, Grenades>();
//}
//
//inline void Item::CreatingEquipmentAmmoRockets(const flecs::iter& iter, size_t i)
//{
//    CreatingEquipmentAmmo(iter, i);
//    iter.entity(i).add_trait<Equipment, Rockets>();
//}
//
//inline void Item::CreatingEquipmentAmmoMines(const flecs::iter& iter, size_t i)
//{
//    CreatingEquipmentAmmo(iter, i);
//    iter.entity(i).add_trait<Equipment, Mines>();
//}
//
//inline void Item::CreatingCraftingMaps(const flecs::iter& iter, size_t i)
//{
//    
//    iter.entity(i).add_trait<Crafting, Maps>();
//}
//
//inline void Item::CreatingCraftingMapChisel(const flecs::iter& iter, size_t i)
//{
//    iter.entity(i).add_trait<Crafting, MapChisel>();
//}
//
//inline void Item::CreatingCraftingCrystals(const flecs::iter& iter, size_t i)
//{
//    iter.entity(i).add_trait<Crafting, Crystals>();
//}
//
//inline void Item::CreatingCraftingCards(const flecs::iter& iter, size_t i)
//{
//    iter.entity(i).add_trait<Crafting, Cards>();
//}
//
//inline void Item::CreatingCraftingOrbs(const flecs::iter& iter, size_t i)
//{
//    iter.entity(i).add_trait<Crafting, Orbs>();
//}
//
//#pragma endregion

