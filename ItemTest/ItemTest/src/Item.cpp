#include "Item.h"

void Item::CreateItemEntity(const flecs::iter& iter, ItemComponents::ItemSpawning* is)
{
    for (auto it : iter)
    {
        for (auto i = 0; i < is->NumberOfItems; i++) 
        {
            auto e = iter.world().entity();
            e.set<ItemComponents::ItemStaging>({ 1 });
            //std::cout << "System CreateItemEntity has created item " << i << " " << std::endl;
        }
        //e.destruct();
        iter.entity(it).remove<ItemComponents::ItemSpawning>();
        //iter.entity(it).destruct();
        
        //std::cout << "System CreateItemEntity is creating items" << std::endl;
    }
}

void Item::SettingSeedForRandomItemEntitiesGeneration(const flecs::iter& iter, ItemComponents::ItemStaging* iss)
{
    for (auto it : iter)
    {
        if (!iss->ItemSeedStage)
        {
            int randomNumber = CreatingSeed();
            //std::cout << "System SettingSeedForRandomItemEntitiesGeneration has generated this number " << randomNumber << " for " << it << std::endl;
            iss->Seed = randomNumber;
            iss->ItemSeedStage = true;
        }
    }
}

void Item::AddItemBaseComponenttoEntity(const flecs::iter& iter, ItemComponents::ItemStaging* iss)
{
    auto ItemConfigQuery = iter.world().filter<ItemConfigComponents::ItemBaseConfig, ItemConfigComponents::ItemTagConfig, ItemConfigComponents::ItemComponentsConfig, ItemConfigComponents::StandardItemBaseRollTable>();

    for (auto it : iter)
    {
        if (!iss->ItemBaseComponentCreated)
        {
            int GeneratingRandomBaseItemID = CreatingRandom32BitIntNumbers(iss->Seed, 1, 10);
            ItemConfigQuery.each([&](ItemConfigComponents::ItemBaseConfig& ibc, ItemConfigComponents::ItemTagConfig& itc, ItemConfigComponents::ItemComponentsConfig& icc, ItemConfigComponents::StandardItemBaseRollTable& brt)
            {
                if (ibc.BaseTypeID == GeneratingRandomBaseItemID)
                {
                    iter.entity(it).set<ItemComponents::ItemBase>({ GeneratingRandomBaseItemID,
                    CreatingRandom32BitIntNumbers(iss->Seed, ibc.BaseTypeIntRollMin, ibc.BaseTypeIntRollMax),
                    CreatingRandom32BitFloatNumbers(iss->Seed, ibc.BaseTypeFloatRollMin, ibc.BaseTypeFloatRollMax) });
                }
            });
            std::cout << "System AddItemBaseComponenttoEntity is creating Items " << std::endl;
            iss->ItemSeedStage = true;
        }
    }
}

void Item::AddItemRarityComponenttoEntity(const flecs::iter &iter, ItemComponents::ItemStaging *iss, ItemComponents::ItemBase *ib)
{
    auto ItemConfigQuery = iter.world().filter<ItemConfigComponents::ItemBaseConfig, ItemConfigComponents::ItemTagConfig, ItemConfigComponents::ItemComponentsConfig, ItemConfigComponents::StandardItemBaseRollTable>();

    for (auto it : iter)
    {
        if (!iss->ItemRarityComponentCreated)
        {
            ItemConfigQuery.each([&](ItemConfigComponents::ItemBaseConfig& ibc, ItemConfigComponents::ItemTagConfig& itc, ItemConfigComponents::ItemComponentsConfig& icc, ItemConfigComponents::StandardItemBaseRollTable& brt)
            {
                int RandomItemGeneratrionRarityNumber = CreatingRandom32BitIntNumbers(iss->Seed, 0, 10000 + 1);

                for (int i = 0; i < 11; i++)
                {
                    if (brt.rarityRollTable[i].RaritySpawnChanceMin <= RandomItemGeneratrionRarityNumber && brt.rarityRollTable[i].RaritySpawnChanceMax >= RandomItemGeneratrionRarityNumber)
                    {
                        iter.entity(it).set<ItemComponents::ItemRarity>(
                                { brt.rarityRollTable[i].RarityLevel,
                              CreatingRandom32BitFloatNumbers(iss->Seed, brt.rarityRollTable[i].RarityFloatRollMin, brt.rarityRollTable[i].RarityFloatRollMax),
                              CreatingRandom32BitIntNumbers(iss->Seed, brt.rarityRollTable[i].RarityIntRollMin, brt.rarityRollTable[i].RarityIntRollMax),
                              brt.rarityRollTable[i].RarityAffixAllowance });
                    }
                }
            });
            iss->ItemRarityComponentCreated = true;
        }
    }
}

void Item::AddItemQualityComponenttoEntity(const flecs::iter &iter, ItemComponents::ItemStaging *iss, ItemComponents::ItemBase *ib)
{
    auto ItemConfigQuery = iter.world().filter<ItemConfigComponents::ItemBaseConfig, ItemConfigComponents::ItemTagConfig, ItemConfigComponents::ItemComponentsConfig, ItemConfigComponents::StandardItemBaseRollTable>();

    for (auto it : iter)
    {
        if (!iss->ItemQualityComponentCreated)
        {
            ItemConfigQuery.each([&](ItemConfigComponents::ItemBaseConfig& ibc, ItemConfigComponents::ItemTagConfig& itc, ItemConfigComponents::ItemComponentsConfig& icc, ItemConfigComponents::StandardItemBaseRollTable& brt)
            {
                int RandomItemGeneratrionQualityNumber = CreatingRandom32BitIntNumbers(iss->Seed, 0, 10000 + 1);
                for (int i = 0; i < 21; i++)
                {
                    if (brt.qualityRollTable[i].QualitySpawnChanceMin <= RandomItemGeneratrionQualityNumber && brt.qualityRollTable[i].QualitySpawnChanceMax >= RandomItemGeneratrionQualityNumber)
                    {
                        iter.entity(it).set<ItemComponents::ItemQuality>({ brt.qualityRollTable[i].QualityNum,
                                                                           brt.qualityRollTable[i].QualityIntStatIncrease,
                                                                           brt.qualityRollTable[i].QualityFloatStatIncrease });
                    }
                }
            });
            iss->ItemQualityComponentCreated;
        }
    }
}

void Item::AddItemMaterialComponenttoEntity(const flecs::iter &iter, ItemComponents::ItemStaging *iss, ItemComponents::ItemBase *ib)
{
    auto ItemConfigQuery = iter.world().filter<ItemConfigComponents::ItemBaseConfig, ItemConfigComponents::ItemTagConfig, ItemConfigComponents::ItemComponentsConfig, ItemConfigComponents::StandardItemBaseRollTable>();

    for (auto it : iter)
    {
        if (!iss->ItemMaterialComponentCreated)
        {
            ItemConfigQuery.each([&](ItemConfigComponents::ItemBaseConfig& ibc, ItemConfigComponents::ItemTagConfig& itc, ItemConfigComponents::ItemComponentsConfig& icc, ItemConfigComponents::StandardItemBaseRollTable& brt)
             {
                 int RandomItemGeneratrionMaterialNumber = CreatingRandom32BitIntNumbers(iss->Seed, 0, 10000 + 1);
                 for (int i = 0; i < 10; i++)
                 {
                     if (brt.materialRollTable[i].MaterialChanceMin <= RandomItemGeneratrionMaterialNumber && brt.materialRollTable[i].MaterialChanceMax >= RandomItemGeneratrionMaterialNumber)
                     {
                         iter.entity(it).set<ItemComponents::ItemMaterial>({ brt.materialRollTable[i].MaterialType,
                                                                             CreatingRandom32BitIntNumbers(iss->Seed, brt.materialRollTable[i].MaterialStatIntRollMin, brt.materialRollTable[i].MaterialStatIntRollMax),
                                                                             CreatingRandom32BitFloatNumbers(iss->Seed, brt.materialRollTable[i].MaterialStatFloatRollMin, brt.materialRollTable[i].MaterialStatFloatRollMax)
                                                                           });
                     }
                 }
             });
            iss->ItemMaterialComponentCreated = true;
        }
    }
}

void Item::AddItemManufacturerComponenttoEntity(const flecs::iter &iter, ItemComponents::ItemStaging *iss, ItemComponents::ItemBase *ib)
{
    auto ItemConfigQuery = iter.world().filter<ItemConfigComponents::ItemBaseConfig, ItemConfigComponents::ItemTagConfig, ItemConfigComponents::ItemComponentsConfig, ItemConfigComponents::StandardItemBaseRollTable>();

    for (auto it : iter)
    {
        if (!iss->ItemManufacturerComponentCreated)
        {
            ItemConfigQuery.each([&](ItemConfigComponents::ItemBaseConfig& ibc, ItemConfigComponents::ItemTagConfig& itc, ItemConfigComponents::ItemComponentsConfig& icc, ItemConfigComponents::StandardItemBaseRollTable& brt)
             {
                 int RandomItemGeneratrionManufacturerNumber = CreatingRandom32BitIntNumbers(iss->Seed, 0, 11 + 1);
                 for (int i = 0; i < 5; i++)
                 {
                     if (brt.manufacturerRollTable[i].ManufacturerType == RandomItemGeneratrionManufacturerNumber)
                     {
                         iter.entity(it).set<ItemComponents::ItemManufacturer>({ brt.manufacturerRollTable[i].ManufacturerType,
                                                                                 CreatingRandom32BitIntNumbers(iss->Seed, brt.manufacturerRollTable[i].ManufacturerStatIntRollMin, brt.manufacturerRollTable[i].ManufacturerStatIntRollMax),
                                                                                 CreatingRandom32BitFloatNumbers(iss->Seed, brt.manufacturerRollTable[i].ManufacturerStatFloatRollMin, brt.manufacturerRollTable[i].ManufacturerStatFloatRollMax)
                                                                               });
                     }
                 }
             });
            iss->ItemManufacturerComponentCreated = true;
        }
    }
}

void Item::AddItemAffixComponenttoEntity(const flecs::iter &iter, ItemComponents::ItemStaging *iss, ItemComponents::ItemBase *ib, ItemComponents::ItemRarity* ir)
{
    auto ItemConfigQuery = iter.world().filter<ItemConfigComponents::ItemBaseConfig, ItemConfigComponents::ItemTagConfig, ItemConfigComponents::ItemComponentsConfig, ItemConfigComponents::StandardItemBaseRollTable>();

    for (auto it : iter)
    {
        if (!iss->ItemAffixComponentsCreated)
        {
            ItemConfigQuery.each([&](ItemConfigComponents::ItemBaseConfig& ibc, ItemConfigComponents::ItemTagConfig& itc, ItemConfigComponents::ItemComponentsConfig& icc, ItemConfigComponents::StandardItemBaseRollTable& brt)
            {
                if (ir->RarityAffixAllowance == 1 || ir->RarityAffixAllowance > 1)
                {
                    iter.entity(it).set<ItemComponents::ItemAffixMods1>({});
                }
                 if (ir->RarityAffixAllowance == 2 || ir->RarityAffixAllowance > 2)
                 {
                     iter.entity(it).set<ItemComponents::ItemAffixMods2>({});
                 }
                 if (ir->RarityAffixAllowance == 3 || ir->RarityAffixAllowance > 3)
                 {
                     iter.entity(it).set<ItemComponents::ItemAffixMods3>({});
                 }
                 if (ir->RarityAffixAllowance == 4 || ir->RarityAffixAllowance > 4)
                 {
                     iter.entity(it).set<ItemComponents::ItemAffixMods4>({});
                 }
                 if (ir->RarityAffixAllowance == 5 || ir->RarityAffixAllowance > 5)
                 {
                     iter.entity(it).set<ItemComponents::ItemAffixMods5>({});
                 }
                 if (ir->RarityAffixAllowance == 6 || ir->RarityAffixAllowance > 6)
                 {
                     iter.entity(it).set<ItemComponents::ItemAffixMods6>({});
                 }
                 if (ir->RarityAffixAllowance == 7 || ir->RarityAffixAllowance > 7)
                 {
                     iter.entity(it).set<ItemComponents::ItemAffixMods7>({});
                 }
                 if (ir->RarityAffixAllowance == 8 || ir->RarityAffixAllowance > 8)
                 {
                     iter.entity(it).set<ItemComponents::ItemAffixMods8>({});
                 }
                 if (ir->RarityAffixAllowance == 9 || ir->RarityAffixAllowance > 9)
                 {
                     iter.entity(it).set<ItemComponents::ItemAffixMods9>({});
                 }
                 if (ir->RarityAffixAllowance == 10)
                 {
                     iter.entity(it).set<ItemComponents::ItemAffixMods10>({});
                 }
            });
            iss->ItemAffixComponentsCreated = true;
        }
    }
}

void Item::AddItemPartsComponenttoEntity(const flecs::iter &iter, ItemComponents::ItemStaging *iss, ItemComponents::ItemBase *ib)
{
    auto ItemConfigQuery = iter.world().filter<ItemConfigComponents::ItemBaseConfig, ItemConfigComponents::ItemTagConfig, ItemConfigComponents::ItemComponentsConfig, ItemConfigComponents::StandardItemBaseRollTable>();

    for (auto it : iter)
    {
        if (!iss->ItemRarityComponentCreated)
        {
            ItemConfigQuery.each([&](ItemConfigComponents::ItemBaseConfig& ibc, ItemConfigComponents::ItemTagConfig& itc, ItemConfigComponents::ItemComponentsConfig& icc, ItemConfigComponents::StandardItemBaseRollTable& brt)
                                 {

                                 });
        }
    }
}

void Item::AddItemTagsComponenttoEntity(const flecs::iter &iter, ItemComponents::ItemStaging *iss, ItemComponents::ItemBase *ib)
{
    auto ItemConfigQuery = iter.world().filter<ItemConfigComponents::ItemBaseConfig, ItemConfigComponents::ItemTagConfig, ItemConfigComponents::ItemComponentsConfig, ItemConfigComponents::StandardItemBaseRollTable>();

    for (auto it : iter)
    {
        if (!iss->ItemTagsCreated)
        {
            ItemConfigQuery.each([&](ItemConfigComponents::ItemBaseConfig& ibc, ItemConfigComponents::ItemTagConfig& itc, ItemConfigComponents::ItemComponentsConfig& icc, ItemConfigComponents::StandardItemBaseRollTable& brt)
                                 {
                                     if (itc.ItemTagType == 1)
                                     {
                                         iter.entity(it).add<ItemComponents::EquipableItemTag>();
                                         iter.entity(it).add<ItemComponents::WeaponsItemTag>();
                                         iter.entity(it).add<ItemComponents::MeleeItemTag>();
                                         iter.entity(it).add<ItemComponents::OneHandedItemTag>();
                                         iter.entity(it).add<ItemComponents::SwordItemTag>();
                                     }
                                 });
            iss->ItemTagsCreated = true;
        }
    }
}

void Item::AddItemStatsComponenttoEntity(const flecs::iter &iter, ItemComponents::ItemStaging *iss, ItemComponents::ItemBase *ib)
{
    auto ItemConfigQuery = iter.world().filter<ItemConfigComponents::ItemBaseConfig, ItemConfigComponents::ItemTagConfig, ItemConfigComponents::ItemComponentsConfig, ItemConfigComponents::StandardItemBaseRollTable>();

    for (auto it : iter)
    {
        if (!iss->ItemStatComponentsCreated)
        {
            ItemConfigQuery.each([&](ItemConfigComponents::ItemBaseConfig& ibc, ItemConfigComponents::ItemTagConfig& itc, ItemConfigComponents::ItemComponentsConfig& icc, ItemConfigComponents::StandardItemBaseRollTable& brt)
             {
                 if (icc.ItemComponentType == 1)
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
                 }
                 else if (icc.ItemComponentType == 2)
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
                 }
                 else if (icc.ItemComponentType == 3)
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
                 }
             });
            iss->ItemStatComponentsCreated = true;
        }
    }
}

void Item::CompliedItemStatsOnEntity(const flecs::iter &iter, ItemComponents::ItemStaging *iss, ItemComponents::ItemBase *ib)
{
    auto ItemConfigQuery = iter.world().filter<ItemConfigComponents::ItemBaseConfig, ItemConfigComponents::ItemTagConfig, ItemConfigComponents::ItemComponentsConfig, ItemConfigComponents::StandardItemBaseRollTable>();

    for (auto it : iter)
    {
        if (!iss->ItemStatCompiled)
        {
            ItemConfigQuery.each([&](ItemConfigComponents::ItemBaseConfig& ibc, ItemConfigComponents::ItemTagConfig& itc, ItemConfigComponents::ItemComponentsConfig& icc, ItemConfigComponents::StandardItemBaseRollTable& brt)
                                 {

                                 });
            iss->ItemStatCompiled = true;
        }
    }
}

inline int Item::CreatingSeed()
{
    std::random_device rand32;
    std::mt19937 gen(rand32());
    std::uniform_int_distribution<int> randomNumber32(0, INT32_MAX);
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

inline int Item::CalculatingFinalItemStatRollInt(int itemRoll, int rarityRoll, int qualityRoll, int materialRoll, int manufacturerRoll, 
    int  itemPart1, int  itemPart2, int  itemPart3, int  itemPart4, int  itemPart5, int  itemPart6, int  itemPart7, int  itemPart8, int  itemPart9, int  itemPart10, 
    int  itemAffixMods1, int itemAffixMods2, int itemAffixMods3, int itemAffixMods4, int itemAffixMods5, int itemAffixMods6, int itemAffixMods7, int itemAffixMods8, int itemAffixMods9, int itemAffixMods10)
{
    return itemRoll + rarityRoll + qualityRoll + materialRoll + manufacturerRoll + 
        itemPart1 + itemPart2 + itemPart3 + itemPart4 + itemPart5 + itemPart6 + itemPart7 + itemPart8 + itemPart9 + itemPart10 + 
        itemAffixMods1 + itemAffixMods2 + itemAffixMods3 + itemAffixMods4 + itemAffixMods5 + itemAffixMods6 + itemAffixMods7 + itemAffixMods8 + itemAffixMods9 + itemAffixMods10;
}

inline float Item::CalculatingFinalItemStatRollFloat(float itemRoll, float rarityRoll, float qualityRoll, float materialRoll, float manufacturerRoll, 
    float itemPart1, float itemPart2, float itemPart3, float itemPart4, float itemPart5, float itemPart6, float itemPart7, float itemPart8, float itemPart9, float itemPart10, 
    float itemAffixMods1, float itemAffixMods2, float itemAffixMods3, float itemAffixMods4, float itemAffixMods5, float itemAffixMods6, float itemAffixMods7, float itemAffixMods8, float itemAffixMods9, float itemAffixMods10)
{
    return itemRoll + rarityRoll + qualityRoll + materialRoll + manufacturerRoll +
        itemPart1 + itemPart2 + itemPart3 + itemPart4 + itemPart5 + itemPart6 + itemPart7 + itemPart8 + itemPart9 + itemPart10 +
        itemAffixMods1 + itemAffixMods2 + itemAffixMods3 + itemAffixMods4 + itemAffixMods5 + itemAffixMods6 + itemAffixMods7 + itemAffixMods8 + itemAffixMods9 + itemAffixMods10;
}
