#include "Item.h"

void Item::CreateItemEntity(const flecs::iter& iter, ItemSpawning* is)
{
    for (auto it : iter)
    {
        for (auto i  = 0; i < is->NumberOfItems; i++) 
        {
            auto e = iter.world().entity();
            e.set<ItemStaging>({ 1 });
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
            int randomNumber = CreatingSeed();
            std::cout << "System SettingSeedForRandomItemEntitiesGeneration has generated this number " << randomNumber << " for " << it << std::endl;
            iss->Seed = randomNumber;
            iss->ItemStage = 2;
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
            std::cout << "System AddItemTypeComponentstoEntity has add ItemTypeCreation component " << it << " " << std::endl;
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
            std::cout << "System AddItemComponentstoEntity is creating Items " << it << " " << std::endl;
        }
    }
}



void Item::CreatingRarityModComponentsToEntity(const flecs::iter& iter, ItemStaging* iss, ItemTypeCreation* isc, ItemRarity* ir)
{
    for (auto it : iter)
    {
        if (iss->ItemStage == 4)
        {

            if (ir->RarityAffixAllowance == 1)
            {

                iter.entity(it).set<ItemAffixMods1>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 1 ItemAffixMod component " << it << " " << std::endl;
            }
            else if (ir->RarityAffixAllowance == 2)
            {
                iter.entity(it).set<ItemAffixMods1>({});
                iter.entity(it).set<ItemAffixMods2>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 2 ItemAffixMod component " << it << " " << std::endl;
            }
            else if (ir->RarityAffixAllowance == 3)
            {
                iter.entity(it).set<ItemAffixMods1>({});
                iter.entity(it).set<ItemAffixMods2>({});
                iter.entity(it).set<ItemAffixMods3>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 3 ItemAffixMod component " << it << " " << std::endl;
            }
            else if (ir->RarityAffixAllowance == 4)
            {
                iter.entity(it).set<ItemAffixMods1>({});
                iter.entity(it).set<ItemAffixMods2>({});
                iter.entity(it).set<ItemAffixMods3>({});
                iter.entity(it).set<ItemAffixMods4>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 4 ItemAffixMod component " << it << " " << std::endl;
            }
            else if (ir->RarityAffixAllowance == 5)
            {
                iter.entity(it).set<ItemAffixMods1>({});
                iter.entity(it).set<ItemAffixMods2>({});
                iter.entity(it).set<ItemAffixMods3>({});
                iter.entity(it).set<ItemAffixMods4>({});
                iter.entity(it).set<ItemAffixMods5>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 5 ItemAffixMod component " << it << " " << std::endl;
            }
            else if (ir->RarityAffixAllowance == 6)
            {
                iter.entity(it).set<ItemAffixMods1>({});
                iter.entity(it).set<ItemAffixMods2>({});
                iter.entity(it).set<ItemAffixMods3>({});
                iter.entity(it).set<ItemAffixMods4>({});
                iter.entity(it).set<ItemAffixMods5>({});
                iter.entity(it).set<ItemAffixMods6>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 6 ItemAffixMod component " << it << " " << std::endl;
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
                std::cout << "System CreatingRarityModComponentsToEntity has add 7 ItemAffixMod component " << it << " " << std::endl;
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
                std::cout << "System CreatingRarityModComponentsToEntity has add 8 ItemAffixMod component " << it << " " << std::endl;
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
                std::cout << "System CreatingRarityModComponentsToEntity has add 9 ItemAffixMod component " << it << " " << std::endl;
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
                std::cout << "System CreatingRarityModComponentsToEntity has add 10 ItemAffixMod component " << it << " " << std::endl;
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
                std::cout << "System CreatingRarityModComponentsToEntity has add 10 ItemAffixMod component " << it << " " << std::endl;
            }
            else 
            {
                std::cout << "System CreatingRarityModComponentsToEntity has add 0 ItemAffixMod component " << it << " " << std::endl;
            }
            iss->ItemStage = 5;
        }
    }
}

void Item::RemovingItemStagingComponentsFromEntity(const flecs::iter& iter, ItemStaging* iss)
{
    for (auto it : iter)
    {
        if (iss->ItemStage == 5)
        {
            iss->ItemStage = 6;
            iter.entity(it).remove<ItemStaging>();
            std::cout << "System RemovingItemStagingComponentsFromEntity is removeing ItemStaging from Items " << it << " " << std::endl;
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
    std::uniform_int_distribution<> randomNumber32(min, max);
    int randomNumber = randomNumber32(gen);
    return randomNumber;
}

inline float Item::CreatingRandom32BitFloatNumbers(int seed, float min, float max) 
{
    std::mt19937 gen(seed);
    std::uniform_real_distribution<> randomNumber32(min, max);
    float randomNumber = randomNumber32(seed);
    return randomNumber;
}

inline void Item::CreatingEquipableItems(const flecs::iter& iter, size_t i, int seed)
{
    int NumberOfitemTypes = 33;
    int randomNumber = CreatingRandom32BitIntNumbers(seed, 0, 33);
    if (randomNumber == 0)
    {
        CreatingOneHandedMeleeWeaponShortSwordItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item OneHandedMeleeWeaponShortSword " << i << " " << std::endl;
    }
    else if (randomNumber == 1)
    {
        CreatingOneHandedMeleeWeaponMaceItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item OneHandedMeleeWeaponMace " << i << " " << std::endl;
    }
    else if (randomNumber == 2)
    {
        CreatingOneHandedMeleeWeaponKnifeItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item OneHandedMeleeWeaponKnife " << i << " " << std::endl;
    }
    else if (randomNumber == 3)
    {
        CreatingOneHandedMeleeWeaponWarhammerItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item OneHandedMeleeWeaponWarhammer " << i << " " << std::endl;
    }
    else if (randomNumber == 4)
    {
        CreatingOneHandedMeleeWeaponAxeItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item OneHandedMeleeWeaponAxe " << i << " " << std::endl;
    }
    else if (randomNumber == 5)
    {
        CreatingOneHandedMeleeWeaponShieldItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item OneHandedMeleeWeaponShield " << i << " " << std::endl;
    }
    else if (randomNumber == 6)
    {
        CreatingOneHandedMeleeWeaponRapierItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item OneHandedMeleeWeaponRapier " << i << " " << std::endl;
    }
    else if (randomNumber == 7)
    {
        CreatingOneHandedMeleeWeaponClubItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item OneHandedMeleeWeaponClub " << i << " " << std::endl;
    }
    else if (randomNumber == 8)
    {
        CreatingTwoHandedMeleeWeaponLongSwordItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponLongSword " << i << " " << std::endl;
    }
    else if (randomNumber == 9)
    {
        CreatingTwoHandedMeleeWeaponMaceItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponMace " << i << " " << std::endl;
    }
    else if (randomNumber == 10)
    {
        CreatingTwoHandedMeleeWeaponWarhammerItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponWarhammer " << i << " " << std::endl;
    }
    else if (randomNumber == 11)
    {
        CreatingTwoHandedMeleeWeaponHalberdItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponHalberd " << i << " " << std::endl;
    }
    else if (randomNumber == 12)
    {
        CreatingTwoHandedMeleeWeaponAxeItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponAxe " << i << " " << std::endl;
    }
    else if (randomNumber == 13)
    {
        CreatingTwoHandedMeleeWeaponClubItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponClub " << i << " " << std::endl;
    }
    else if (randomNumber == 14)
    {
        CreatingTwoHandedMeleeWeaponStaffItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponStaff " << i << " " << std::endl;
    }
    else if (randomNumber == 15)
    {
        CreatingTwoHandedMeleeWeaponSpearItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponSpeard " << i << " " << std::endl;
    }
    else if (randomNumber == 16)
    {
        CreatingTwoHandedMeleeWeaponClawsItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedMeleeWeaponClaws " << i << " " << std::endl;
    }
    else if (randomNumber == 17)
    {
        CreatingOneHandedRangedWeaponWandItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item OneHandedRangedWeaponWand " << i << " " << std::endl;
    }
    else if (randomNumber == 18)
    {
        CreatingOneHandedRangedWeaponThrownItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item OneHandedRangedWeaponThrown " << i << " " << std::endl;
    }
    else if (randomNumber == 19)
    {
        CreatingOneHandedRangedWeaponPistolItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item OneHandedRangedWeaponPistol " << i << " " << std::endl;
    }
    else if (randomNumber == 20)
    {
        CreatingOneHandedRangedWeaponRevolverItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item OneHandedRangedWeaponRevolver " << i << " " << std::endl;
    }
    else if (randomNumber == 21)
    {
        CreatingOneHandedRangedWeaponHandCrossbowItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item OneHandedRangedWeaponHandCrossbow " << i << " " << std::endl;
    }
    else if (randomNumber == 22)
    {
        CreatingTwoHandedRangedWeaponBowItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponBow " << i << " " << std::endl;
    }
    else if (randomNumber == 23)
    {
        CreatingTwoHandedRangedWeaponCrossbowItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponCrossbow " << i << " " << std::endl;
    }
    else if (randomNumber == 24)
    {
        CreatingTwoHandedRangedWeaponCarbineItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponCarbine " << i << " " << std::endl;
    }
    else if (randomNumber == 25)
    {
        CreatingTwoHandedRangedWeaponAssaultRifleItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponAssaultRifle " << i << " " << std::endl;
    }
    else if (randomNumber == 26)
    {
        CreatingTwoHandedRangedWeaponSniperRifleItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponSniperRifle " << i << " " << std::endl;
    }
    else if (randomNumber == 27)
    {
        CreatingTwoHandedRangedWeaponLightMachineGunItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponLightMachineGun " << i << " " << std::endl;
    }
    else if (randomNumber == 28)
    {
        CreatingTwoHandedRangedWeaponSubMachineGunItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponSubMachineGun " << i << " " << std::endl;
    }
    else if (randomNumber == 29)
    {
        CreatingTwoHandedRangedWeaponShotgunItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponShotgun " << i << " " << std::endl;
    }
    else if (randomNumber == 30)
    {
        CreatingTwoHandedRangedWeaponGrenadeLauncherItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponGrenadeLauncher " << i << " " << std::endl;

    }
    else if (randomNumber == 32)
    {
        CreatingTwoHandedRangedWeaponRocketLauncherItems(iter, i, seed);
        std::cout << "System AddItemComponentstoEntity is creating Item TwoHandedRangedWeaponRocketLauncher " << i << " " << std::endl;

    }
    else 
    {
        std::cout << "For some reason a number is out of range " << i << " " << std::endl;
        randomNumber = seed % NumberOfitemTypes;
    }
}

ItemRarityConfig GetConfigItemRarityData(float RarityRoll)
{
    if (RarityRoll >= ItemRarity1.RarityChanceMin && RarityRoll < ItemRarity1.RarityChanceMax)
    {
        return ItemRarity1;
    }
    if (RarityRoll >= ItemRarity2.RarityChanceMin && RarityRoll < ItemRarity2.RarityChanceMax)
    {
        return ItemRarity2;
    }
    if (RarityRoll >= ItemRarity3.RarityChanceMin && RarityRoll < ItemRarity3.RarityChanceMax)
    {
        return ItemRarity3;
    }
    if (RarityRoll >= ItemRarity4.RarityChanceMin && RarityRoll < ItemRarity4.RarityChanceMax)
    {
        return ItemRarity4;
    }
    if (RarityRoll >= ItemRarity5.RarityChanceMin && RarityRoll < ItemRarity5.RarityChanceMax)
    {
        return ItemRarity5;
    }
    if (RarityRoll >= ItemRarity6.RarityChanceMin && RarityRoll < ItemRarity6.RarityChanceMax)
    {
        return ItemRarity6;
    }
    if (RarityRoll >= ItemRarity7.RarityChanceMin && RarityRoll < ItemRarity7.RarityChanceMax)
    {
        return ItemRarity7;
    }
    if (RarityRoll >= ItemRarity8.RarityChanceMin && RarityRoll < ItemRarity8.RarityChanceMax)
    {
        return ItemRarity8;
    }
    if (RarityRoll >= ItemRarity9.RarityChanceMin && RarityRoll < ItemRarity9.RarityChanceMax)
    {
        return ItemRarity9;
    }
    if (RarityRoll >= ItemRarity10.RarityChanceMin && RarityRoll < ItemRarity10.RarityChanceMax)
    {
        return ItemRarity10;
    }
    if (RarityRoll >= ItemRarity11.RarityChanceMin && RarityRoll < ItemRarity11.RarityChanceMax)
    {
        return ItemRarity11;
    }
    if (RarityRoll >= ItemRarity12.RarityChanceMin && RarityRoll <= ItemRarity12.RarityChanceMax)
    {
        return ItemRarity12;
    }
    ItemRarityConfig errorItemRarity{0,0,0,0,0,0};
    //Debug.Log("Error Item base not found");
    return errorItemRarity;
}

ItemQualityConfig  Item::GetConfigItemQualityData(float ItemQuality)
{
    if (ItemQuality <= ItemQualityConfig0.QualityChance)
    {
        return ItemQualityConfig0;
    }
    if (ItemQuality > ItemQualityConfig0.QualityChance && ItemQuality <= ItemQualityConfig1.QualityChance)
    {
        return ItemQualityConfig1;
    }
    if (ItemQuality > ItemQualityConfig1.QualityChance && ItemQuality <= ItemQualityConfig2.QualityChance)
    {
        return ItemQualityConfig2;
    }
    if (ItemQuality > ItemQualityConfig2.QualityChance && ItemQuality <= ItemQualityConfig3.QualityChance)
    {
        return ItemQualityConfig3;
    }
    if (ItemQuality > ItemQualityConfig3.QualityChance && ItemQuality <= ItemQualityConfig4.QualityChance)
    {
        return ItemQualityConfig4;
    }
    if (ItemQuality > ItemQualityConfig4.QualityChance && ItemQuality <= ItemQualityConfig5.QualityChance)
    {
        return ItemQualityConfig5;
    }
    if (ItemQuality > ItemQualityConfig5.QualityChance && ItemQuality <= ItemQualityConfig6.QualityChance)
    {
        return ItemQualityConfig6;
    }
    if (ItemQuality > ItemQualityConfig6.QualityChance && ItemQuality <= ItemQualityConfig7.QualityChance)
    {
        return ItemQualityConfig7;
    }
    if (ItemQuality > ItemQualityConfig7.QualityChance && ItemQuality <= ItemQualityConfig8.QualityChance)
    {
        return ItemQualityConfig8;
    }
    if (ItemQuality > ItemQualityConfig8.QualityChance && ItemQuality <= ItemQualityConfig9.QualityChance)
    {
        return ItemQualityConfig9;
    }
    if (ItemQuality > ItemQualityConfig9.QualityChance && ItemQuality <= ItemQualityConfig10.QualityChance)
    {
        return ItemQualityConfig10;
    }
    if (ItemQuality > ItemQualityConfig10.QualityChance && ItemQuality <= ItemQualityConfig11.QualityChance)
    {
        return ItemQualityConfig11;
    }
    if (ItemQuality > ItemQualityConfig11.QualityChance && ItemQuality <= ItemQualityConfig12.QualityChance)
    {
        return ItemQualityConfig12;
    }
    if (ItemQuality > ItemQualityConfig12.QualityChance && ItemQuality <= ItemQualityConfig13.QualityChance)
    {
        return ItemQualityConfig13;
    }
    if (ItemQuality > ItemQualityConfig13.QualityChance && ItemQuality <= ItemQualityConfig14.QualityChance)
    {
        return ItemQualityConfig14;
    }
    if (ItemQuality > ItemQualityConfig14.QualityChance && ItemQuality <= ItemQualityConfig15.QualityChance)
    {
        return ItemQualityConfig15;
    }
    if (ItemQuality > ItemQualityConfig15.QualityChance && ItemQuality <= ItemQualityConfig16.QualityChance)
    {
        return ItemQualityConfig16;
    }
    if (ItemQuality > ItemQualityConfig16.QualityChance && ItemQuality <= ItemQualityConfig17.QualityChance)
    {
        return ItemQualityConfig17;
    }
    if (ItemQuality > ItemQualityConfig17.QualityChance && ItemQuality <= ItemQualityConfig18.QualityChance)
    {
        return ItemQualityConfig18;
    }
    if (ItemQuality > ItemQualityConfig18.QualityChance && ItemQuality <= ItemQualityConfig19.QualityChance)
    {
        return ItemQualityConfig19;
    }
    if (ItemQuality < ItemQualityConfig19.QualityChance)
    {
        return ItemQualityConfig20;
    }
    ItemQualityConfig errorItemQuality{ 0,0,0 };
    return errorItemQuality;
}

inline void Item::CreatingBaseItemEquipableStats(const flecs::iter& iter, size_t i, int seed)
{
    iter.entity(i).set<ItemCharacterLevelRequirements>({});
    ItemRarityConfig itemRarityConfig = GetConfigItemRarityData(CreatingRandom32BitFloatNumbers(seed, 0, 100));
    iter.entity(i).set<ItemRarity>({ itemRarityConfig.RarityLevel, CreatingRandom32BitIntNumbers(seed, itemRarityConfig.RarityIntRollMin, itemRarityConfig.RarityIntRollMax) ,CreatingRandom32BitFloatNumbers(seed, itemRarityConfig.RarityFloatRollMin, itemRarityConfig.RarityFloatRollMax), itemRarityConfig.RarityAffixAllowance });
    iter.entity(i).set<ItemQuality>({});
    iter.entity(i).set<ItemMaterial>({});
    iter.entity(i).set<ItemManufacturer>({});
    iter.entity(i).set<ItemName>({});
}

inline void Item::CreatingMeleeWeaponComponentsToEntity(const flecs::iter& iter, size_t i, int seed)
{
    CreatingBaseItemEquipableStats(iter, i, seed);
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

inline void Item::CreatingRangeWeaponComponentstoEntity(const flecs::iter& iter, size_t i, int seed)
{
    CreatingBaseItemEquipableStats(iter, i, seed);
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

inline void Item::CreatingPowerArmourComponentsToEntity(const flecs::iter& iter, size_t i, int seed)
{
    CreatingBaseItemEquipableStats(iter, i, seed);
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
inline void Item::CreatingOneHandedMeleeWeaponItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingMeleeWeaponComponentsToEntity(iter, i, randomRarity);
    iter.entity(i).add_trait<Item, Weapons>();
    iter.entity(i).add_trait<Weapons, Melee>();
    iter.entity(i).add_trait<Melee, OneHanded>();
}

inline void Item::CreatingOneHandedMeleeWeaponShortSwordItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingOneHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, ShortSword>();
}

inline void Item::CreatingOneHandedMeleeWeaponMaceItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingOneHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, Mace>();
}

inline void Item::CreatingOneHandedMeleeWeaponKnifeItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingOneHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, Knife>();
}

inline void Item::CreatingOneHandedMeleeWeaponWarhammerItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingOneHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, Warhammer>();
}

inline void Item::CreatingOneHandedMeleeWeaponAxeItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingOneHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, Axe>();
}

inline void Item::CreatingOneHandedMeleeWeaponShieldItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingOneHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, Shield>();
}

inline void Item::CreatingOneHandedMeleeWeaponRapierItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingOneHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, Rapier>();
}

inline void Item::CreatingOneHandedMeleeWeaponClubItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingOneHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, Club>();
}

#pragma endregion

#pragma region Creating TwoHanded Melee Weapons

inline void Item::CreatingTwoHandedMeleeWeaponItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingMeleeWeaponComponentsToEntity(iter, i, randomRarity);
    iter.entity(i).add_trait<Item, Weapons>();
    iter.entity(i).add_trait<Weapons, Melee>();
    iter.entity(i).add_trait<Melee, TwoHanded>();
}

inline void Item::CreatingTwoHandedMeleeWeaponLongSwordItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, LongSword>();
}

inline void Item::CreatingTwoHandedMeleeWeaponMaceItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, Mace>();
}

inline void Item::CreatingTwoHandedMeleeWeaponWarhammerItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, Warhammer>();
}

inline void Item::CreatingTwoHandedMeleeWeaponHalberdItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, Halberd>();
}

inline void Item::CreatingTwoHandedMeleeWeaponAxeItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, Axe>();
}

inline void Item::CreatingTwoHandedMeleeWeaponClubItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, Club>();
}

inline void Item::CreatingTwoHandedMeleeWeaponStaffItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, Staff>();
}

inline void Item::CreatingTwoHandedMeleeWeaponSpearItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, Spear>();
}

inline void Item::CreatingTwoHandedMeleeWeaponClawsItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingTwoHandedMeleeWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, Claws>();
}

#pragma endregion

#pragma region Creating OneHanded Range Weapons

inline void Item::CreatingOneHandedRangedWeaponItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingRangeWeaponComponentstoEntity(iter, i, randomRarity);
    iter.entity(i).add_trait<Item, Weapons>();
    iter.entity(i).add_trait<Weapons, Ranged>();
    iter.entity(i).add_trait<Ranged, OneHanded>();
}

inline void Item::CreatingOneHandedRangedWeaponWandItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingOneHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, Wand>();
}

inline void Item::CreatingOneHandedRangedWeaponThrownItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingOneHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, Thrown>();
}

inline void Item::CreatingOneHandedRangedWeaponPistolItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingOneHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, Pistol>();
}

inline void Item::CreatingOneHandedRangedWeaponRevolverItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingOneHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, Revolver>();
}

inline void Item::CreatingOneHandedRangedWeaponHandCrossbowItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingOneHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<OneHanded, HandCrossbow>();
}
#pragma endregion

#pragma region Creating TwoHanded Range Weapons

inline void Item::CreatingTwoHandedRangedWeaponItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingRangeWeaponComponentstoEntity(iter, i, randomRarity);
    iter.entity(i).add_trait<Item, Weapons>();
    iter.entity(i).add_trait<Weapons, Ranged>();
    iter.entity(i).add_trait<Ranged, TwoHanded>();
}

inline void Item::CreatingTwoHandedRangedWeaponBowItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingTwoHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, Bow>();
}

inline void Item::CreatingTwoHandedRangedWeaponCrossbowItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingTwoHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, Crossbow>();
}

inline void Item::CreatingTwoHandedRangedWeaponCarbineItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingTwoHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, Carbine>();
}

inline void Item::CreatingTwoHandedRangedWeaponAssaultRifleItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingTwoHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, AssaultRifle>();
}

inline void Item::CreatingTwoHandedRangedWeaponSniperRifleItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingTwoHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, SniperRifle>();
}

inline void Item::CreatingTwoHandedRangedWeaponLightMachineGunItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingTwoHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, LightMachineGun>();
}

inline void Item::CreatingTwoHandedRangedWeaponSubMachineGunItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingTwoHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, SubMachineGun>();
}

inline void Item::CreatingTwoHandedRangedWeaponShotgunItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingTwoHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, Shotgun>();
}

inline void Item::CreatingTwoHandedRangedWeaponGrenadeLauncherItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingTwoHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, GrenadeLauncher>();
}

inline void Item::CreatingTwoHandedRangedWeaponRocketLauncherItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingTwoHandedRangedWeaponItems(iter, i, randomRarity);
    iter.entity(i).add_trait<TwoHanded, RocketLauncher>();
}

#pragma endregion

#pragma region Creating Light PowerArmour

inline void Item::CreatingArmourPowerArmourLightItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingPowerArmourComponentsToEntity(iter, i, randomRarity);
    iter.entity(i).add_trait<Item, Armour>();
    iter.entity(i).add_trait<Armour, PowerArmour>();
    iter.entity(i).add_trait<PowerArmour, LightPowerArmour>();
}

inline void Item::CreatingArmourPowerArmourLightHeadItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourPowerArmourLightItems(iter, i, randomRarity);
    iter.entity(i).add_trait<LightPowerArmour, Head>();
}

inline void Item::CreatingArmourPowerArmourLightBeltItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourPowerArmourLightItems(iter, i, randomRarity);
    iter.entity(i).add_trait<LightPowerArmour, Belt>();
}

inline void Item::CreatingArmourPowerArmourLightChestItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourPowerArmourLightItems(iter, i, randomRarity);
    iter.entity(i).add_trait<LightPowerArmour, Chests>();
}

inline void Item::CreatingArmourPowerArmourLightLegsItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourPowerArmourLightItems(iter, i, randomRarity);
    iter.entity(i).add_trait<LightPowerArmour, Legs>();
}

inline void Item::CreatingArmourPowerArmourLightArmsItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourPowerArmourLightItems(iter, i, randomRarity);
    iter.entity(i).add_trait<LightPowerArmour, Arms>();
}

inline void Item::CreatingArmourPowerArmourLightHandsItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourPowerArmourLightItems(iter, i, randomRarity);
    iter.entity(i).add_trait<LightPowerArmour, Hands>();
}

inline void Item::CreatingArmourPowerArmourLightShouldersItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourPowerArmourLightItems(iter, i, randomRarity);
    iter.entity(i).add_trait<LightPowerArmour, Shoulders>();
}

inline void Item::CreatingArmourPowerArmourLightBackpackItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourPowerArmourLightItems(iter, i, randomRarity);
    iter.entity(i).add_trait<LightPowerArmour, Backpack>();
}

#pragma endregion

#pragma region Creating Medium PowerArmour

void Item::CreatingArmourPowerArmourMediumItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingPowerArmourComponentsToEntity(iter, i, randomRarity);
    iter.entity(i).add_trait<Item, Armour>();
    iter.entity(i).add_trait<Armour, PowerArmour>();
    iter.entity(i).add_trait<PowerArmour, MediumPowerArmour>();
}

inline void Item::CreatingArmourPowerArmourMediumHeadItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourPowerArmourMediumItems(iter, i, randomRarity);
    iter.entity(i).add_trait<MediumPowerArmour, Head>();
}

inline void Item::CreatingArmourPowerArmourMediumBeltItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourPowerArmourMediumItems(iter, i, randomRarity);
    iter.entity(i).add_trait<MediumPowerArmour, Belt>();
}

inline void Item::CreatingArmourPowerArmourMediumChestItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourPowerArmourMediumItems(iter, i, randomRarity);
    iter.entity(i).add_trait<MediumPowerArmour, Chests>();
}

inline void Item::CreatingArmourPowerArmourMediumLegsItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourPowerArmourMediumItems(iter, i, randomRarity);
    iter.entity(i).add_trait<MediumPowerArmour, Legs>();
}

inline void Item::CreatingArmourPowerArmourMediumArmsItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourPowerArmourMediumItems(iter, i, randomRarity);
    iter.entity(i).add_trait<MediumPowerArmour, Arms>();
}

inline void Item::CreatingArmourPowerArmourMediumHandsItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourPowerArmourMediumItems(iter, i, randomRarity);
    iter.entity(i).add_trait<MediumPowerArmour, Hands>();
}

inline void Item::CreatingArmourPowerArmourMediumShouldersItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourPowerArmourMediumItems(iter, i, randomRarity);
    iter.entity(i).add_trait<MediumPowerArmour, Shoulders>();
}

inline void Item::CreatingArmourPowerArmourMediumBackpackItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourPowerArmourMediumItems(iter, i, randomRarity);
    iter.entity(i).add_trait<MediumPowerArmour, Backpack>();
}

#pragma endregion

#pragma region Creating Heavy PowerArmour

inline void Item::CreatingArmourPowerArmourHeavyItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingPowerArmourComponentsToEntity(iter, i, randomRarity);
    iter.entity(i).add_trait<Item, Armour>();
    iter.entity(i).add_trait<Armour, PowerArmour>();
    iter.entity(i).add_trait<PowerArmour, HeavyPowerArmour>();
}

inline void Item::CreatingArmourPowerArmourHeavyHeadItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourPowerArmourHeavyItems(iter, i, randomRarity);
    iter.entity(i).add_trait<HeavyPowerArmour, Head>();
}

inline void Item::CreatingArmourPowerArmourHeavyBeltItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourPowerArmourHeavyItems(iter, i, randomRarity);
    iter.entity(i).add_trait<HeavyPowerArmour, Belt>();
}

inline void Item::CreatingArmourPowerArmourHeavyChestItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourPowerArmourHeavyItems(iter, i, randomRarity);
    iter.entity(i).add_trait<HeavyPowerArmour, Chests>();
}

inline void Item::CreatingArmourPowerArmourHeavyLegsItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourPowerArmourHeavyItems(iter, i, randomRarity);
    iter.entity(i).add_trait<HeavyPowerArmour, Legs>();
}

inline void Item::CreatingArmourPowerArmourHeavyArmsItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourPowerArmourHeavyItems(iter, i, randomRarity);
    iter.entity(i).add_trait<HeavyPowerArmour, Arms>();
}

inline void Item::CreatingArmourPowerArmourHeavyHandsItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourPowerArmourHeavyItems(iter, i, randomRarity);
    iter.entity(i).add_trait<HeavyPowerArmour, Hands>();
}

inline void Item::CreatingArmourPowerArmourHeavyShouldersItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourPowerArmourHeavyItems(iter, i, randomRarity);
    iter.entity(i).add_trait<HeavyPowerArmour, Shoulders>();
}

inline void Item::CreatingArmourPowerArmourHeavyBackpackItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourPowerArmourHeavyItems(iter, i, randomRarity);
    iter.entity(i).add_trait<HeavyPowerArmour, Backpack>();
}

#pragma endregion

#pragma region Creating NonPowerArmour

inline void Item::CreatingArmourNonPowerArmourItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    iter.entity(i).add_trait<Item, Armour>();
    iter.entity(i).add_trait<Armour, NonPowerArmour>();
}

inline void Item::CreatingArmourNonPowerArmourHeadItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourNonPowerArmourItems(iter, i, randomRarity);
    iter.entity(i).add_trait<NonPowerArmour, Head>();
}

inline void Item::CreatingArmourNonPowerArmourBeltItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourNonPowerArmourItems(iter, i, randomRarity);
    iter.entity(i).add_trait<NonPowerArmour, Belt>();
}

inline void Item::CreatingArmourNonPowerArmourChestItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourNonPowerArmourItems(iter, i, randomRarity);
    iter.entity(i).add_trait<NonPowerArmour, Chests>();
}

inline void Item::CreatingArmourNonPowerArmourLegsItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourNonPowerArmourItems(iter, i, randomRarity);
    iter.entity(i).add_trait<NonPowerArmour, Legs>();
}

inline void Item::CreatingArmourNonPowerArmourArmsItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourNonPowerArmourItems(iter, i, randomRarity);
    iter.entity(i).add_trait<NonPowerArmour, Arms>();
}

inline void Item::CreatingArmourNonPowerArmourHandsItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourNonPowerArmourItems(iter, i, randomRarity);
    iter.entity(i).add_trait<NonPowerArmour, Hands>();
}

inline void Item::CreatingArmourNonPowerArmourShouldersItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourNonPowerArmourItems(iter, i, randomRarity);
    iter.entity(i).add_trait<NonPowerArmour, Shoulders>();
}

inline void Item::CreatingArmourNonPowerArmourBackpackItems(const flecs::iter& iter, size_t i, int randomRarity)
{
    CreatingArmourNonPowerArmourItems(iter, i, randomRarity);
    iter.entity(i).add_trait<NonPowerArmour, Backpack>();
}

#pragma endregion

#pragma region Creating Cloths Armour

void Item::CreatingArmourClothsItems(const flecs::iter& iter, size_t i)
{
    iter.entity(i).add_trait<Item, Armour>();
    iter.entity(i).add_trait<Armour, Cloths>();
}

inline void Item::CreatingArmourClothsHeadItems(const flecs::iter& iter, size_t i)
{
    CreatingArmourClothsItems(iter, i);
    iter.entity(i).add_trait<Cloths, Head>();
}

inline void Item::CreatingArmourClothsBeltItems(const flecs::iter& iter, size_t i)
{
    CreatingArmourClothsItems(iter, i);
    iter.entity(i).add_trait<Cloths, Belt>();
}

inline void Item::CreatingArmourClothsChestItems(const flecs::iter& iter, size_t i)
{
    CreatingArmourClothsItems(iter, i);
    iter.entity(i).add_trait<Cloths, Chests>();
}

inline void Item::CreatingArmourClothsLegsItems(const flecs::iter& iter, size_t i)
{
    CreatingArmourClothsItems(iter, i);
    iter.entity(i).add_trait<Cloths, Legs>();
}

inline void Item::CreatingArmourClothsArmsItems(const flecs::iter& iter, size_t i)
{
    CreatingArmourClothsItems(iter, i);
    iter.entity(i).add_trait<Cloths, Arms>();
}

inline void Item::CreatingArmourClothsHandsItems(const flecs::iter& iter, size_t i)
{
    CreatingArmourClothsItems(iter, i);
    iter.entity(i).add_trait<Cloths, Hands>();
}

inline void Item::CreatingArmourClothsShouldersItems(const flecs::iter& iter, size_t i)
{
    CreatingArmourClothsItems(iter, i);
    iter.entity(i).add_trait<Cloths, Shoulders>();
}

inline void Item::CreatingArmourClothsBackpackItems(const flecs::iter& iter, size_t i)
{
    CreatingArmourClothsItems(iter, i);
    iter.entity(i).add_trait<Cloths, Backpack>();
}

inline void Item::CreatingEquipmentFlasks(const flecs::iter& iter, size_t i)
{
    iter.entity(i).add_trait<Item, Equipment>();
    iter.entity(i).add_trait<Equipment, Flasks>();
}

inline void Item::CreatingEquipmentFlasksHealth(const flecs::iter& iter, size_t i)
{
    CreatingEquipmentFlasks(iter, i);
    iter.entity(i).add_trait<Flasks, Health>();
}

inline void Item::CreatingEquipmentFlasksMagic(const flecs::iter& iter, size_t i)
{
    CreatingEquipmentFlasks(iter, i);
    iter.entity(i).add_trait<Flasks, Magic>();
}

inline void Item::CreatingEquipmentFlasksMovement(const flecs::iter& iter, size_t i)
{
    CreatingEquipmentFlasks(iter, i);
    iter.entity(i).add_trait<Flasks, Movement>();
}

inline void Item::CreatingEquipmentFlasksResistance(const flecs::iter& iter, size_t i)
{
    CreatingEquipmentFlasks(iter, i);
    iter.entity(i).add_trait<Flasks, Resistance>();
}

inline void Item::CreatingEquipmentAmmo(const flecs::iter& iter, size_t i)
{
    iter.entity(i).add_trait<Item, Equipment>();
    iter.entity(i).add_trait<Equipment, Ammo>();
}

inline void Item::CreatingEquipmentAmmoQuivers(const flecs::iter& iter, size_t i)
{
    CreatingEquipmentAmmo(iter, i);
    iter.entity(i).add_trait<Equipment, Quivers>();
}

inline void Item::CreatingEquipmentAmmoMagazines(const flecs::iter& iter, size_t i)
{
    CreatingEquipmentAmmo(iter, i);
    iter.entity(i).add_trait<Equipment, Magazines>();
}

inline void Item::CreatingEquipmentAmmoGrenades(const flecs::iter& iter, size_t i)
{
    CreatingEquipmentAmmo(iter, i);
    iter.entity(i).add_trait<Equipment, Grenades>();
}

inline void Item::CreatingEquipmentAmmoRockets(const flecs::iter& iter, size_t i)
{
    CreatingEquipmentAmmo(iter, i);
    iter.entity(i).add_trait<Equipment, Rockets>();
}

inline void Item::CreatingEquipmentAmmoMines(const flecs::iter& iter, size_t i)
{
    CreatingEquipmentAmmo(iter, i);
    iter.entity(i).add_trait<Equipment, Mines>();
}

inline void Item::CreatingCraftingMaps(const flecs::iter& iter, size_t i)
{
    
    iter.entity(i).add_trait<Crafting, Maps>();
}

inline void Item::CreatingCraftingMapChisel(const flecs::iter& iter, size_t i)
{
    iter.entity(i).add_trait<Crafting, MapChisel>();
}

inline void Item::CreatingCraftingCrystals(const flecs::iter& iter, size_t i)
{
    iter.entity(i).add_trait<Crafting, Crystals>();
}

inline void Item::CreatingCraftingCards(const flecs::iter& iter, size_t i)
{
    iter.entity(i).add_trait<Crafting, Cards>();
}

inline void Item::CreatingCraftingOrbs(const flecs::iter& iter, size_t i)
{
    iter.entity(i).add_trait<Crafting, Orbs>();
}

#pragma endregion

