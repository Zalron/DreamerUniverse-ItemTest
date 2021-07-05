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

void Item::AddItemTypeComponentstoEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss)
{
    for (auto it : iter) 
    {
        if (iss->ItemStage == 2) 
        {
            iter.entity(it).set<ItemComponents::ItemTypeCreation>({0,0,0});
            iss->ItemStage = 3;
            //std::cout << "System AddItemTypeComponentstoEntity has add ItemTypeCreation component " << it << " " << std::endl;
        }
    }
}

void Item::AddItemComponentstoEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss)
{
    for (auto it : iter) 
    {
        if (iss->ItemStage == 3)
        {
            float RandomItemGenerationNumber1 = CreatingRandom32BitFloatNumbers(iss->Seed, 0.0f, 100.0f);
            float RandomItemGenerationNumber2 = CreatingRandom32BitFloatNumbers(iss->Seed, 0.0f, 100.0f);
            float RandomItemGenerationNumber3 = CreatingRandom32BitFloatNumbers(iss->Seed, 0.0f, 100.0f);
            float RandomItemGenerationNumber4 = CreatingRandom32BitFloatNumbers(iss->Seed, 0.0f, 100.0f);
            float RandomItemGenerationNumber5 = CreatingRandom32BitFloatNumbers(iss->Seed, 0.0f, 100.0f);

            float RandomItemGeneratrionNumberDivided1 = 100.0f / 2;
            if (RandomItemGenerationNumber1 > RandomItemGeneratrionNumberDivided1)
            {
                float RandomItemGeneratrionNumberDivided2 = 100.0f / 4;
                //iter.entity(it).set<ItemComponents::ItemName>({});
                iter.entity(it).set<ItemComponents::ItemQuality>({});
            }
            else if (RandomItemGenerationNumber1 <= RandomItemGeneratrionNumberDivided1)
            {
                std::cout << "System AddItemComponentstoEntity is creating Item Equipable " << it << " " << std::endl;
                float RandomItemGeneratrionNumberDivided2 = 100.0f / 2;
                iter.entity(it).set<ItemComponents::ItemCharacterLevelRequirements>({});
                iter.entity(it).set<ItemComponents::ItemRarity>({});
                iter.entity(it).set<ItemComponents::ItemQuality>({});
                iter.entity(it).set<ItemComponents::ItemMaterial>({});
                iter.entity(it).set<ItemComponents::ItemManufacturer>({});
                //iter.entity(it).set<ItemComponents::ItemName>({});
                if (RandomItemGenerationNumber2 < RandomItemGeneratrionNumberDivided2 )
                {
                    float RandomItemGenerationNumberDivided3 = 100.0f / 2;
                    std::cout << "System AddItemComponentstoEntity is creating Item  Melee " << it << " " << std::endl;
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
                    iter.entity(it).add_trait<ItemComponents::Equipable, ItemComponents::Weapons>();
                    iter.entity(it).add_trait<ItemComponents::Weapons, ItemComponents::Melee>();
                    if (RandomItemGenerationNumber3 > RandomItemGenerationNumberDivided3)
                    {
                        float RandomItemGeneratrionNumberDivided4 = 100.0f / 8;
                        iter.entity(it).add_trait<ItemComponents::Melee, ItemComponents::OneHanded>();
                        if (RandomItemGeneratrionNumberDivided4 > RandomItemGeneratrionNumberDivided4)
                        {
                            iter.entity(it).add_trait<ItemComponents::OneHanded, ItemComponents::ShortSword>();
                            std::cout << "System AddItemComponentstoEntity is creating Item OneHandedMeleeWeaponShortSword " << it << " " << std::endl;
                        }
                        else if (RandomItemGeneratrionNumberDivided4 <= RandomItemGeneratrionNumberDivided4)
                        {
                            iter.entity(it).add_trait<ItemComponents::OneHanded, ItemComponents::Mace>();
                            std::cout << "System AddItemComponentstoEntity is creating Item OneHandedMeleeWeaponMace " << it << " " << std::endl;
                        }
                        else if (RandomItemGeneratrionNumberDivided4 <= RandomItemGeneratrionNumberDivided4 * 2)
                        {
                            iter.entity(it).add_trait<ItemComponents::OneHanded, ItemComponents::Knife>();
                            std::cout << "System AddItemComponentstoEntity is creating Item OneHandedMeleeWeaponKnife " << it << " " << std::endl;
                        }
                        else if (RandomItemGeneratrionNumberDivided4 <= RandomItemGeneratrionNumberDivided4 * 3)
                        {
                            iter.entity(it).add_trait<ItemComponents::OneHanded, ItemComponents::Warhammer>();
                            std::cout << "System AddItemComponentstoEntity is creating Item OneHandedMeleeWeaponWarhammer " << it << " " << std::endl;
                        }
                        else if (RandomItemGeneratrionNumberDivided4 <= RandomItemGeneratrionNumberDivided4 * 4)
                        {
                            iter.entity(it).add_trait<ItemComponents::OneHanded, ItemComponents::Axe>();
                            std::cout << "System AddItemComponentstoEntity is creating Item OneHandedMeleeWeaponAxe " << it << " " << std::endl;
                        }
                        else if (RandomItemGeneratrionNumberDivided4 <= RandomItemGeneratrionNumberDivided4 * 5)
                        {
                            iter.entity(it).add_trait<ItemComponents::OneHanded, ItemComponents::Shield>();
                            std::cout << "System AddItemComponentstoEntity is creating Item OneHandedMeleeWeaponShield " << it << " " << std::endl;
                        }
                        else if (RandomItemGeneratrionNumberDivided4 <= RandomItemGeneratrionNumberDivided4 * 6)
                        {
                            iter.entity(it).add_trait<ItemComponents::OneHanded, ItemComponents::Rapier>();
                            std::cout << "System AddItemComponentstoEntity is creating Item OneHandedMeleeWeaponRapier " << it << " " << std::endl;
                        }
                        else if (RandomItemGeneratrionNumberDivided4 <= RandomItemGeneratrionNumberDivided4 * 7)
                        {
                            iter.entity(it).add_trait<ItemComponents::OneHanded, ItemComponents::Club>();
                            std::cout << "System AddItemComponentstoEntity is creating Item OneHandedMeleeWeaponClub " << it << " " << std::endl;
                        }
                    }
                    else if (RandomItemGenerationNumber3 <= RandomItemGenerationNumberDivided3)
                    {
                        float RandomItemGenerationNumberDivided4 = 100.0f / 9;
                        iter.entity(it).add_trait<ItemComponents::Melee, ItemComponents::TwoHanded>();
                        if (RandomItemGenerationNumberDivided4 > RandomItemGenerationNumberDivided4)
                        {
                            iter.entity(it).add_trait<ItemComponents::TwoHanded, ItemComponents::LongSword>();
                            std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponLongSword " << it << " " << std::endl;
                        }
                        else if (RandomItemGenerationNumber4 <= RandomItemGenerationNumberDivided4)
                        {
                            iter.entity(it).add_trait<ItemComponents::TwoHanded, ItemComponents::Mace>();
                            std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponMace " << it << " " << std::endl;
                        }
                        else if (RandomItemGenerationNumber4 <= RandomItemGenerationNumberDivided4 * 2)
                        {
                            iter.entity(it).add_trait<ItemComponents::TwoHanded, ItemComponents::Warhammer>();
                            std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponWarhammer " << it << " " << std::endl;
                        }
                        else if (RandomItemGenerationNumber4 <= RandomItemGenerationNumberDivided4 * 3)
                        {
                            iter.entity(it).add_trait<ItemComponents::TwoHanded, ItemComponents::Halberd>();
                            std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponHalberd " << it << " " << std::endl;
                        }
                        else if (RandomItemGenerationNumber4 <= RandomItemGenerationNumberDivided4 * 4)
                        {
                            iter.entity(it).add_trait<ItemComponents::TwoHanded, ItemComponents::Axe>();
                            std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponAxe " << it << " " << std::endl;
                        }
                        else if (RandomItemGenerationNumber4 <= RandomItemGenerationNumberDivided4 * 5)
                        {
                            iter.entity(it).add_trait<ItemComponents::TwoHanded, ItemComponents::Club>();
                            std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponClub " << it << " " << std::endl;
                        }
                        else if (RandomItemGenerationNumber4 <= RandomItemGenerationNumberDivided4 * 6)
                        {
                            iter.entity(it).add_trait<ItemComponents::TwoHanded, ItemComponents::Staff>();
                            std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponStaff " << it << " " << std::endl;
                        }
                        else if (RandomItemGenerationNumber4 <= RandomItemGenerationNumberDivided4 * 7)
                        {
                            iter.entity(it).add_trait<ItemComponents::TwoHanded, ItemComponents::Spear>();
                            std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponSpeard " << it << " " << std::endl;
                        }
                        else if (RandomItemGenerationNumber4 <= RandomItemGenerationNumberDivided4 * 8)
                        {
                            iter.entity(it).add_trait<ItemComponents::TwoHanded, ItemComponents::Claws>();
                            std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponClaws " << it << " " << std::endl;
                        }
                    }
                }
                else if (RandomItemGenerationNumber2 >= RandomItemGeneratrionNumberDivided2)
                {
                    float RandomItemGeneratrionNumberDivided3 = 100.0f / 4;
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
                    iter.entity(it).add_trait<ItemComponents::Equipable, ItemComponents::Weapons>();
                    iter.entity(it).add_trait<ItemComponents::Weapons, ItemComponents::Ranged>();
                    if (RandomItemGenerationNumber3 <= RandomItemGeneratrionNumberDivided3 + RandomItemGeneratrionNumberDivided3 * 3)
                    {
                        float RandomItemGenerationNumberDivided4 = 100.0f / 5;
                        
                        iter.entity(it).add_trait<ItemComponents::Ranged, ItemComponents::OneHanded>();
                        if (RandomItemGenerationNumberDivided4 > RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::OneHanded, ItemComponents::Wand>();
                            std::cout << "System AddItemComponentstoEntity is creating Item OneHandedRangedWeaponWand " << std::endl;
                        }
                        else if (RandomItemGenerationNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::OneHanded, ItemComponents::Thrown>();
                            std::cout << "System AddItemComponentstoEntity is creating Item OneHandedRangedWeaponThrown " << std::endl;
                        }
                        else if (RandomItemGenerationNumberDivided4 <= RandomItemGenerationNumber4 * 2)
                        {
                            iter.entity(it).add_trait<ItemComponents::OneHanded, ItemComponents::Pistol>();
                            std::cout << "System AddItemComponentstoEntity is creating Item OneHandedRangedWeaponPistol " << std::endl;
                        }
                        else if (RandomItemGenerationNumberDivided4 <= RandomItemGenerationNumber4 * 3)
                        {
                            iter.entity(it).add_trait<ItemComponents::OneHanded, ItemComponents::Revolver>();
                            std::cout << "System AddItemComponentstoEntity is creating Item OneHandedRangedWeaponRevolver " << std::endl;
                        }
                        else if (RandomItemGenerationNumberDivided4 <= RandomItemGenerationNumber4 * 4)
                        {
                            iter.entity(it).add_trait<ItemComponents::OneHanded, ItemComponents::HandCrossbow>();
                            std::cout << "System AddItemComponentstoEntity is creating Item OneHandedRangedWeaponHandCrossbow " << std::endl;
                        }
                    }
                    else if (RandomItemGenerationNumber3 <= RandomItemGeneratrionNumberDivided3 + RandomItemGeneratrionNumberDivided3 * 3)
                    {
                        float RandomItemGenerationNumberDivided4 = 100.0f / 10;
                        iter.entity(it).add_trait<ItemComponents::Ranged, ItemComponents::TwoHanded>();
                        if (RandomItemGenerationNumberDivided4 > RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::TwoHanded, ItemComponents::Bow>();
                            std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponBow " << std::endl;
                        }
                        else if (RandomItemGenerationNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::TwoHanded, ItemComponents::Crossbow>();
                            std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponCrossbow " << std::endl;
                        }
                        else if (RandomItemGenerationNumberDivided4 <= RandomItemGenerationNumber4 * 1)
                        {
                            iter.entity(it).add_trait<ItemComponents::TwoHanded, ItemComponents::Carbine>();
                            std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponCarbine " << std::endl;
                        }
                        else if (RandomItemGenerationNumberDivided4 <= RandomItemGenerationNumber4 * 2)
                        {
                            iter.entity(it).add_trait<ItemComponents::TwoHanded, ItemComponents::AssaultRifle>();
                            std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponAssaultRifle " << std::endl;
                        }
                        else if (RandomItemGenerationNumberDivided4 <= RandomItemGenerationNumber4 * 3)
                        {
                            iter.entity(it).add_trait<ItemComponents::TwoHanded, ItemComponents::SniperRifle>();
                            std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponSniperRifle " << std::endl;
                        }
                        else if (RandomItemGenerationNumberDivided4 <= RandomItemGenerationNumber4 * 4)
                        {
                            iter.entity(it).add_trait<ItemComponents::TwoHanded, ItemComponents::LightMachineGun>();
                            std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponLightMachineGun " << std::endl;
                        }
                        else if (RandomItemGenerationNumberDivided4 <= RandomItemGenerationNumber4 * 5)
                        {
                            iter.entity(it).add_trait<ItemComponents::TwoHanded, ItemComponents::SubMachineGun>();
                            std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponSubMachineGun " << std::endl;
                        }
                        else if (RandomItemGenerationNumberDivided4 <= RandomItemGenerationNumber4 * 6)
                        {
                            iter.entity(it).add_trait<ItemComponents::TwoHanded, ItemComponents::Shotgun>();
                            std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponShotgun " << std::endl;
                        }
                        else if (RandomItemGenerationNumberDivided4 <= RandomItemGenerationNumber4 * 7)
                        {
                            iter.entity(it).add_trait<ItemComponents::TwoHanded, ItemComponents::GrenadeLauncher>();
                            std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponGrenadeLauncher " << std::endl;
                        }
                        else if (RandomItemGenerationNumberDivided4 <= RandomItemGenerationNumber4 * 8)
                        {
                            iter.entity(it).add_trait<ItemComponents::TwoHanded, ItemComponents::RocketLauncher>();
                            std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponRocketLauncher " << std::endl;
                        }
                    }
                }
                /*else if (RandomItemGenerationNumber2 <= RandomItemGeneratrionNumberDivided2 * 3)
                {
                    float RandomItemGeneratrionNumberDivided3 = RandomItemGenerationNumber3 / 4;
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
                    iter.entity(it).add_trait<ItemComponents::Equipable, ItemComponents::Armour>();
                    iter.entity(it).add_trait<ItemComponents::Armour, ItemComponents::PowerArmour>();
                    if (RandomItemGenerationNumber3 <= RandomItemGeneratrionNumberDivided3)
                    {
                        float RandomItemGeneratrionNumberDivided4 = RandomItemGenerationNumber4 / 4;
                        iter.entity(it).add_trait<ItemComponents::PowerArmour, ItemComponents::LightPowerArmour>();
                        if (RandomItemGeneratrionNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::LightPowerArmour, ItemComponents::Head>();
                            std::cout << "System AddItemComponentstoEntity is creating Item LightPowerArmourHead " << it << " " << std::endl;
                        }
                        if (RandomItemGeneratrionNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::LightPowerArmour, ItemComponents::Belt>();
                            std::cout << "System AddItemComponentstoEntity is creating Item LightPowerArmourBelt " << it << " " << std::endl;
                        }
                        if (RandomItemGeneratrionNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::LightPowerArmour, ItemComponents::Chests>();
                            std::cout << "System AddItemComponentstoEntity is creating Item LightPowerArmourChests " << it << " " << std::endl;
                        }
                        if (RandomItemGeneratrionNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::LightPowerArmour, ItemComponents::Legs>();
                            std::cout << "System AddItemComponentstoEntity is creating Item LightPowerArmourLegs " << it << " " << std::endl;
                        }
                        if (RandomItemGeneratrionNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::LightPowerArmour, ItemComponents::Arms>();
                            std::cout << "System AddItemComponentstoEntity is creating Item LightPowerArmourArms " << it << " " << std::endl;
                        }
                        if (RandomItemGeneratrionNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::LightPowerArmour, ItemComponents::Hands>();
                            std::cout << "System AddItemComponentstoEntity is creating Item LightPowerArmourHands " << it << " " << std::endl;
                        }
                        if (RandomItemGeneratrionNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::LightPowerArmour, ItemComponents::Shoulders>();
                            std::cout << "System AddItemComponentstoEntity is creating Item LightPowerArmourShoulders " << it << " " << std::endl;
                        }
                        if (RandomItemGeneratrionNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::LightPowerArmour, ItemComponents::Backpack>();
                            std::cout << "System AddItemComponentstoEntity is creating Item LightPowerArmourBackpack " << it << " " << std::endl;
                        }
                    }
                    else if (RandomItemGenerationNumber3 <= RandomItemGeneratrionNumberDivided3)
                    {
                        float RandomItemGeneratrionNumberDivided4 = RandomItemGenerationNumber4 / 4;
                        iter.entity(it).add_trait<ItemComponents::PowerArmour, ItemComponents::MediumPowerArmour>();
                        if (RandomItemGeneratrionNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::MediumPowerArmour, ItemComponents::Head>();
                            std::cout << "System AddItemComponentstoEntity is creating Item MediumPowerArmourHead " << it << " " << std::endl;
                        }
                        if (RandomItemGeneratrionNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::MediumPowerArmour, ItemComponents::Belt>();
                            std::cout << "System AddItemComponentstoEntity is creating Item MediumPowerArmourBelt " << it << " " << std::endl;
                        }
                        if (RandomItemGeneratrionNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::MediumPowerArmour, ItemComponents::Chests>();
                            std::cout << "System AddItemComponentstoEntity is creating Item MediumPowerArmourChests " << it << " " << std::endl;
                        }
                        if (RandomItemGeneratrionNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::MediumPowerArmour, ItemComponents::Legs>();
                            std::cout << "System AddItemComponentstoEntity is creating Item MediumPowerArmourLegs " << it << " " << std::endl;
                        }
                        if (RandomItemGeneratrionNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::MediumPowerArmour, ItemComponents::Arms>();
                            std::cout << "System AddItemComponentstoEntity is creating Item MediumPowerArmourArms " << it << " " << std::endl;
                        }
                        if (RandomItemGeneratrionNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::MediumPowerArmour, ItemComponents::Hands>();
                            std::cout << "System AddItemComponentstoEntity is creating Item MediumPowerArmourHands " << it << " " << std::endl;
                        }
                        if (RandomItemGeneratrionNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::MediumPowerArmour, ItemComponents::Shoulders>();
                            std::cout << "System AddItemComponentstoEntity is creating Item MediumPowerArmourShoulders " << it << " " << std::endl;
                        }
                        if (RandomItemGeneratrionNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::MediumPowerArmour, ItemComponents::Backpack>();
                            std::cout << "System AddItemComponentstoEntity is creating Item MediumPowerArmourBackpack " << it << " " << std::endl;
                        }
                    }
                    else if (RandomItemGenerationNumber3 <= RandomItemGeneratrionNumberDivided3)
                    {
                        float RandomItemGeneratrionNumberDivided4 = RandomItemGenerationNumber4 / 4;
                        iter.entity(it).add_trait<ItemComponents::PowerArmour, ItemComponents::HeavyPowerArmour>();
                        if (RandomItemGeneratrionNumberDivided4 > RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::HeavyPowerArmour, ItemComponents::Head>();
                            std::cout << "System AddItemComponentstoEntity is creating Item HeavyPowerArmourHead " << it << " " << std::endl;
                        }
                        if (RandomItemGeneratrionNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::HeavyPowerArmour, ItemComponents::Belt>();
                            std::cout << "System AddItemComponentstoEntity is creating Item HeavyPowerArmourBelt " << it << " " << std::endl;
                        }
                        if (RandomItemGeneratrionNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::HeavyPowerArmour, ItemComponents::Chests>();
                            std::cout << "System AddItemComponentstoEntity is creating Item HeavyPowerArmourChests " << it << " " << std::endl;
                        }
                        if (RandomItemGeneratrionNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::HeavyPowerArmour, ItemComponents::Legs>();
                            std::cout << "System AddItemComponentstoEntity is creating Item HeavyPowerArmourLegs " << it << " " << std::endl;
                        }
                        if (RandomItemGeneratrionNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::HeavyPowerArmour, ItemComponents::Arms>();
                            std::cout << "System AddItemComponentstoEntity is creating Item HeavyPowerArmourArms " << it << " " << std::endl;
                        }
                        if (RandomItemGeneratrionNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::HeavyPowerArmour, ItemComponents::Hands>();
                            std::cout << "System AddItemComponentstoEntity is creating Item HeavyPowerArmourHands " << it << " " << std::endl;
                        }
                        if (RandomItemGeneratrionNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::HeavyPowerArmour, ItemComponents::Shoulders>();
                            std::cout << "System AddItemComponentstoEntity is creating Item HeavyPowerArmourShoulders " << it << " " << std::endl;
                        }
                        if (RandomItemGeneratrionNumberDivided4 <= RandomItemGenerationNumber4)
                        {
                            iter.entity(it).add_trait<ItemComponents::HeavyPowerArmour, ItemComponents::Backpack>();
                            std::cout << "System AddItemComponentstoEntity is creating Item HeavyPowerArmourBackpack " << it << " " << std::endl;
                        }
                    }
                    else if (RandomItemGenerationNumber3 <= RandomItemGeneratrionNumberDivided3)
                    {
                        
                    }
                }*/
            }
            iss->ItemStage = 4;
            std::cout << "System AddItemComponentstoEntity is creating Items " << it << " " << std::endl;
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
        if(iss->ItemStage == 4)
        {
            float RarityRoll = CreatingRandom32BitFloatNumbers(iss->Seed, 0.0f, 100.0f);
            //std::cout << "Random Rarity number generated " << RarityRoll << std::endl;
            if (RarityRoll <= ItemRarity1.RaritySpawnChance && RarityRoll > ItemRarity2.RaritySpawnChance)
            {
                ir->RarityAffixAllowance = ItemRarity1.RarityAffixAllowance;
                ir->RarityLevel = ItemRarity1.RarityLevel;
                ir->RarityIntRoll = CreatingRandom32BitIntNumbers(iss->Seed, ItemRarity1.RarityIntRollMin, ItemRarity1.RarityIntRollMax);
                ir->RarityFloatRoll = CreatingRandom32BitFloatNumbers(iss->Seed, ItemRarity1.RarityFloatRollMin, ItemRarity1.RarityFloatRollMax);
            }
            else if (RarityRoll <= ItemRarity2.RaritySpawnChance && RarityRoll > ItemRarity3.RaritySpawnChance)
            {
                ir->RarityAffixAllowance = ItemRarity2.RarityAffixAllowance;
                ir->RarityLevel = ItemRarity2.RarityLevel;
                ir->RarityIntRoll = CreatingRandom32BitIntNumbers(iss->Seed, ItemRarity2.RarityIntRollMin, ItemRarity2.RarityIntRollMax);
                ir->RarityFloatRoll = CreatingRandom32BitFloatNumbers(iss->Seed, ItemRarity2.RarityFloatRollMin, ItemRarity2.RarityFloatRollMax);
            }
            else if (RarityRoll <= ItemRarity3.RaritySpawnChance && RarityRoll > ItemRarity4.RaritySpawnChance)
            {
                ir->RarityAffixAllowance = ItemRarity3.RarityAffixAllowance;
                ir->RarityLevel = ItemRarity3.RarityLevel;
                ir->RarityIntRoll = CreatingRandom32BitIntNumbers(iss->Seed, ItemRarity3.RarityIntRollMin, ItemRarity3.RarityIntRollMax);
                ir->RarityFloatRoll = CreatingRandom32BitFloatNumbers(iss->Seed, ItemRarity3.RarityFloatRollMin, ItemRarity3.RarityFloatRollMax);
            }
            else if (RarityRoll <= ItemRarity4.RaritySpawnChance && RarityRoll > ItemRarity5.RaritySpawnChance)
            {
                ir->RarityAffixAllowance = ItemRarity4.RarityAffixAllowance;
                ir->RarityLevel = ItemRarity4.RarityLevel;
                ir->RarityIntRoll = CreatingRandom32BitIntNumbers(iss->Seed, ItemRarity4.RarityIntRollMin, ItemRarity4.RarityIntRollMax);
                ir->RarityFloatRoll = CreatingRandom32BitFloatNumbers(iss->Seed, ItemRarity6.RarityFloatRollMin, ItemRarity4.RarityFloatRollMax);
            }
            else if (RarityRoll <= ItemRarity5.RaritySpawnChance && RarityRoll > ItemRarity5.RaritySpawnChance)
            {
                ir->RarityAffixAllowance = ItemRarity5.RarityAffixAllowance;
                ir->RarityLevel = ItemRarity5.RarityLevel;
                ir->RarityIntRoll = CreatingRandom32BitIntNumbers(iss->Seed, ItemRarity5.RarityIntRollMin, ItemRarity5.RarityIntRollMax);
                ir->RarityFloatRoll = CreatingRandom32BitFloatNumbers(iss->Seed, ItemRarity5.RarityFloatRollMin, ItemRarity5.RarityFloatRollMax);
            }
            else if (RarityRoll <= ItemRarity6.RaritySpawnChance && RarityRoll > ItemRarity7.RaritySpawnChance)
            {
                ir->RarityAffixAllowance = ItemRarity6.RarityAffixAllowance;
                ir->RarityLevel = ItemRarity6.RarityLevel;
                ir->RarityIntRoll = CreatingRandom32BitIntNumbers(iss->Seed, ItemRarity6.RarityIntRollMin, ItemRarity6.RarityIntRollMax);
                ir->RarityFloatRoll = CreatingRandom32BitFloatNumbers(iss->Seed, ItemRarity6.RarityFloatRollMin, ItemRarity6.RarityFloatRollMax);
            }
            else if (RarityRoll <= ItemRarity7.RaritySpawnChance && RarityRoll > ItemRarity8.RaritySpawnChance)
            {
                ir->RarityAffixAllowance = ItemRarity7.RarityAffixAllowance;
                ir->RarityLevel = ItemRarity7.RarityLevel;
                ir->RarityIntRoll = CreatingRandom32BitIntNumbers(iss->Seed, ItemRarity7.RarityIntRollMin, ItemRarity7.RarityIntRollMax);
                ir->RarityFloatRoll = CreatingRandom32BitFloatNumbers(iss->Seed, ItemRarity7.RarityFloatRollMin, ItemRarity7.RarityFloatRollMax);
            }
            else if (RarityRoll <= ItemRarity8.RaritySpawnChance && RarityRoll > ItemRarity9.RaritySpawnChance)
            {
                ir->RarityAffixAllowance = ItemRarity8.RarityAffixAllowance;
                ir->RarityLevel = ItemRarity8.RarityLevel;
                ir->RarityIntRoll = CreatingRandom32BitIntNumbers(iss->Seed, ItemRarity8.RarityIntRollMin, ItemRarity8.RarityIntRollMax);
                ir->RarityFloatRoll = CreatingRandom32BitFloatNumbers(iss->Seed, ItemRarity8.RarityFloatRollMin, ItemRarity8.RarityFloatRollMax);
            }
            else if (RarityRoll <= ItemRarity9.RaritySpawnChance && RarityRoll > ItemRarity10.RaritySpawnChance)
            {
                ir->RarityAffixAllowance = ItemRarity9.RarityAffixAllowance;
                ir->RarityLevel = ItemRarity9.RarityLevel;
                ir->RarityIntRoll = CreatingRandom32BitIntNumbers(iss->Seed, ItemRarity9.RarityIntRollMin, ItemRarity9.RarityIntRollMax);
                ir->RarityFloatRoll = CreatingRandom32BitFloatNumbers(iss->Seed, ItemRarity9.RarityFloatRollMin, ItemRarity9.RarityFloatRollMax);
            }
            else if (RarityRoll <= ItemRarity10.RaritySpawnChance && RarityRoll > ItemRarity11.RaritySpawnChance)
            {
                ir->RarityAffixAllowance = ItemRarity10.RarityAffixAllowance;
                ir->RarityLevel = ItemRarity10.RarityLevel;
                ir->RarityIntRoll = CreatingRandom32BitIntNumbers(iss->Seed, ItemRarity10.RarityIntRollMin, ItemRarity10.RarityIntRollMax);
                ir->RarityFloatRoll = CreatingRandom32BitFloatNumbers(iss->Seed, ItemRarity10.RarityFloatRollMin, ItemRarity10.RarityFloatRollMax);
            }
            else if (RarityRoll <= ItemRarity11.RaritySpawnChance && RarityRoll > ItemRarity12.RaritySpawnChance)
            {
                ir->RarityAffixAllowance = ItemRarity11.RarityAffixAllowance;
                ir->RarityLevel = ItemRarity11.RarityLevel;
                ir->RarityIntRoll = CreatingRandom32BitIntNumbers(iss->Seed, ItemRarity11.RarityIntRollMin, ItemRarity11.RarityIntRollMax);
                ir->RarityFloatRoll = CreatingRandom32BitFloatNumbers(iss->Seed, ItemRarity11.RarityFloatRollMin, ItemRarity11.RarityFloatRollMax);
            }
            else if (RarityRoll <= ItemRarity12.RaritySpawnChance && RarityRoll >= 100.0f)
            {
                ir->RarityAffixAllowance = ItemRarity12.RarityAffixAllowance;
                ir->RarityLevel = ItemRarity12.RarityLevel;
                ir->RarityIntRoll = CreatingRandom32BitIntNumbers(iss->Seed, ItemRarity12.RarityIntRollMin, ItemRarity12.RarityIntRollMax);
                ir->RarityFloatRoll = CreatingRandom32BitFloatNumbers(iss->Seed, ItemRarity12.RarityFloatRollMin, ItemRarity12.RarityFloatRollMax);
            }
            else
            {
                std::cout << "System CreatingRarityComponentsToEntity has number generated out of range" << it << " " << std::endl;
            }
            iss->ItemStage = 5;
            std::cout << "System CreatingRarityComponentsToEntity has run " << std::endl;
        }
    }
}


void Item::CreatingRarityModComponentsToEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss, ItemComponents::ItemTypeCreation* isc, ItemComponents::ItemRarity* ir)
{
    for (auto it : iter)
    {
        if (iss->ItemStage == 5)
        {
            if (ir->RarityAffixAllowance == 1)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods1>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 1 ItemAffixMod component " << it << " " << std::endl;
            }
            else if (ir->RarityAffixAllowance == 2)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods1>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods2>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 2 ItemAffixMod component " << it << " " << std::endl;
            }
            else if (ir->RarityAffixAllowance == 3)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods1>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods2>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods3>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 3 ItemAffixMod component " << it << " " << std::endl;
            }
            else if (ir->RarityAffixAllowance == 4)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods1>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods2>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods3>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods4>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 4 ItemAffixMod component " << it << " " << std::endl;
            }
            else if (ir->RarityAffixAllowance == 5)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods1>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods2>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods3>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods4>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods5>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 5 ItemAffixMod component " << it << " " << std::endl;
            }
            else if (ir->RarityAffixAllowance == 6)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods1>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods2>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods3>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods4>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods5>({});
                iter.entity(it).set<ItemComponents::ItemAffixMods6>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 6 ItemAffixMod component " << it << " " << std::endl;
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
                std::cout << "System CreatingRarityModComponentsToEntity has add 7 ItemAffixMod component " << it << " " << std::endl;
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
                std::cout << "System CreatingRarityModComponentsToEntity has add 8 ItemAffixMod component " << it << " " << std::endl;
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
                std::cout << "System CreatingRarityModComponentsToEntity has add 9 ItemAffixMod component " << it << " " << std::endl;
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
                std::cout << "System CreatingRarityModComponentsToEntity has add 10 ItemAffixMod component " << it << " " << std::endl;
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
                std::cout << "System CreatingRarityModComponentsToEntity has add 10 ItemAffixMod component " << it << " " << std::endl;
            }
            else 
            {
                std::cout << "System CreatingRarityModComponentsToEntity has add 0 ItemAffixMod component " << it << " " << std::endl;
            }
            iss->ItemStage = 6;
            std::cout << "System CreatingRarityModComponentsToEntity has add ItemAffixMod component " << it << " " << std::endl;
        }
    }
}

void Item::CreatingQualityComponentToEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss, ItemComponents::ItemQuality* iq)
{
    for (auto it : iter) 
    {
        if (iss->ItemStage == 6) 
        {
            iter.entity(it).remove<ItemComponents::ItemStaging>();
            iss->ItemStage = 7;
        }
    }
}

void Item::RemovingItemStagingComponentsFromEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss)
{
    for (auto it : iter)
    {
        if (iss->ItemStage == 7)
        {
            iss->ItemStage = 8;
            
            //std::cout << "System RemovingItemStagingComponentsFromEntity is removeing ItemStaging from Items " << it << " " << std::endl;
        }
    }
}

inline std::mt19937 Item::CreatingSeedForRandom32BitNumber() 
{
    
    //return gen;
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

ItemQualityConfig  Item::GetConfigItemQualityData(float ItemQuality)
{
    if (ItemQuality >= ItemQualityConfig0.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig0.QualitySpawnChanceMax)
    {
        return ItemQualityConfig0;
    }
    else if (ItemQuality >= ItemQualityConfig1.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig1.QualitySpawnChanceMax)
    {
        return ItemQualityConfig1;
    }
    else if (ItemQuality >= ItemQualityConfig2.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig2.QualitySpawnChanceMax)
    {
        return ItemQualityConfig2;
    }
    else if (ItemQuality >= ItemQualityConfig3.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig3.QualitySpawnChanceMax)
    {
        return ItemQualityConfig3;
    }
    else if (ItemQuality >= ItemQualityConfig4.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig4.QualitySpawnChanceMax)
    {
        return ItemQualityConfig4;
    }
    else if (ItemQuality >= ItemQualityConfig5.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig5.QualitySpawnChanceMax)
    {
        return ItemQualityConfig5;
    }
    else if (ItemQuality >= ItemQualityConfig6.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig6.QualitySpawnChanceMax)
    {
        return ItemQualityConfig6;
    }
    else if (ItemQuality >= ItemQualityConfig7.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig7.QualitySpawnChanceMax)
    {
        return ItemQualityConfig7;
    }
    else if (ItemQuality >= ItemQualityConfig8.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig8.QualitySpawnChanceMax)
    {
        return ItemQualityConfig8;
    }
    else if (ItemQuality >= ItemQualityConfig9.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig9.QualitySpawnChanceMax)
    {
        return ItemQualityConfig9;
    }
    else if (ItemQuality >= ItemQualityConfig10.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig10.QualitySpawnChanceMax)
    {
        return ItemQualityConfig10;
    }
    else if (ItemQuality >= ItemQualityConfig11.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig11.QualitySpawnChanceMax)
    {
        return ItemQualityConfig11;
    }
    else if (ItemQuality >= ItemQualityConfig12.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig12.QualitySpawnChanceMax)
    {
        return ItemQualityConfig12;
    }
    else if (ItemQuality >= ItemQualityConfig13.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig13.QualitySpawnChanceMax)
    {
        return ItemQualityConfig13;
    }
    else if (ItemQuality >= ItemQualityConfig14.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig14.QualitySpawnChanceMax)
    {
        return ItemQualityConfig14;
    }
    else if (ItemQuality >= ItemQualityConfig15.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig15.QualitySpawnChanceMax)
    {
        return ItemQualityConfig15;
    }
    else if (ItemQuality >= ItemQualityConfig16.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig16.QualitySpawnChanceMax)
    {
        return ItemQualityConfig16;
    }
    else if (ItemQuality >= ItemQualityConfig17.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig17.QualitySpawnChanceMax)
    {
        return ItemQualityConfig17;
    }
    else if (ItemQuality >= ItemQualityConfig18.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig18.QualitySpawnChanceMax)
    {
        return ItemQualityConfig18;
    }
    else if (ItemQuality >= ItemQualityConfig18.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig18.QualitySpawnChanceMax)
    {
        return ItemQualityConfig18;
    }
    else if (ItemQuality >= ItemQualityConfig19.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig19.QualitySpawnChanceMax)
    {
        return ItemQualityConfig19;
    }
    else if (ItemQuality >= ItemQualityConfig20.QualitySpawnChanceMin && ItemQuality < ItemQualityConfig20.QualitySpawnChanceMax)
    {
        return ItemQualityConfig20;
    }
    else 
    {
        ItemQualityConfig errorItemQuality{ 0,0,0,0 };
        return errorItemQuality;
    }
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

