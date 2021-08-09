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
            static int RandomItemGeneratrionNumber = CreatingRandom32BitIntNumbers(iss->Seed, 0, ItemConfig::RolltableArrayLength);
            static auto RolledItem = ItemConfig::RolltableArray[RandomItemGeneratrionNumber];

            static auto RolledItemBase = RolledItem.ItemBase;
            iter.entity(it).set<ItemComponents::ItemBase>({RandomItemGeneratrionNumber ,CreatingRandom32BitIntNumbers(iss->Seed,RolledItemBase.BaseTypeIntRollMin,RolledItemBase.BaseTypeIntRollMax),
                CreatingRandom32BitFloatNumbers(iss->Seed,RolledItemBase.BaseTypeFloatRollMin,RolledItemBase.BaseTypeFloatRollMax)});

            //static const auto RolledItemRarity = RolledItem.ItemBaseRollTable.rarityRollTable[1];
            //std::cout << "System AddItemComponentstoEntity is adding " << RolledItemRarity.RaritySpawnChanceMin << " " << RolledItemRarity.RaritySpawnChanceMax << " To Rolled Items " << std::endl;

            int RandomItemGeneratrionRarityNumber = CreatingRandom32BitIntNumbers(iss->Seed, 0, 10000 + 1);
            std::cout << "System AddItemComponentstoEntity has rolled rarity " << RandomItemGeneratrionRarityNumber << " " << std::endl;
            static auto RolledItemRarity = RolledItem.ItemBaseRollTable.rarityRollTable[0];
            for (size_t i = 0; i < 11; i++)
            {
                if (RolledItem.ItemBaseRollTable.rarityRollTable[i].RaritySpawnChanceMin >= RandomItemGeneratrionRarityNumber && RolledItem.ItemBaseRollTable.rarityRollTable[i].RaritySpawnChanceMax < RandomItemGeneratrionRarityNumber)
                {
                    RolledItemRarity = RolledItem.ItemBaseRollTable.rarityRollTable[i];
                    ItemConfig::CheckRarityConfigValues(RolledItemRarity);
                    iter.entity(it).set<ItemComponents::ItemRarity>({ RolledItemRarity.RarityLevel,
                        CreatingRandom32BitFloatNumbers(iss->Seed,RolledItemRarity.RarityFloatRollMin,RolledItemRarity.RarityFloatRollMax),
                        CreatingRandom32BitIntNumbers(iss->Seed,RolledItemRarity.RarityIntRollMin,RolledItemRarity.RarityIntRollMax),
                        RolledItemRarity.RarityAffixAllowance });
                    std::cout << "System AddItemComponentstoEntity is adding " << RolledItemRarity.RarityLevel << " To Rolled Items " << std::endl;
                }
                else 
                {
                    std::cout << "System AddItemComponentstoEntity is adding " << RolledItemRarity.RarityLevel << " To Rolled Items " << std::endl;
                }
            }
            
            
            int RandomItemGeneratrionQualityNumber = CreatingRandom32BitIntNumbers(iss->Seed, 0, 10000 + 1);
            for (size_t i = 0; i < 21; i++)
            {
                if (RolledItem.ItemBaseRollTable.qualityRollTable[i].QualitySpawnChanceMin >= RandomItemGeneratrionQualityNumber && RolledItem.ItemBaseRollTable.qualityRollTable[i].QualitySpawnChanceMax < RandomItemGeneratrionQualityNumber)
                {
                    static auto RolledItemQuality = RolledItem.ItemBaseRollTable.qualityRollTable[i];
                    iter.entity(it).set<ItemComponents::ItemQuality>({ RolledItemQuality.QualityNum, 
                        RolledItemQuality.QualityIntStatIncrease, 
                        RolledItemQuality.QualityFloatStatIncrease});
                }
            }
            int RandomItemGeneratrionMaterialNumber = CreatingRandom32BitIntNumbers(iss->Seed, 0, 10000 + 1);
            for (size_t i = 0; i < 10; i++)
            {
                if (RolledItem.ItemBaseRollTable.materialRollTable[i].MaterialChanceMin >= RandomItemGeneratrionMaterialNumber && RolledItem.ItemBaseRollTable.materialRollTable[i].MaterialChanceMin < RandomItemGeneratrionMaterialNumber)
                {
                    static auto RolledItemMaterial = RolledItem.ItemBaseRollTable.materialRollTable[i];
                    iter.entity(it).set<ItemComponents::ItemMaterial>({RolledItemMaterial.MaterialType,
                        CreatingRandom32BitIntNumbers(iss->Seed,RolledItemMaterial.MaterialStatIntRollMin,RolledItemMaterial.MaterialStatIntRollMax),
                        CreatingRandom32BitFloatNumbers(iss->Seed,RolledItemMaterial.MaterialStatFloatRollMin,RolledItemMaterial.MaterialStatFloatRollMax)
                        });
                }
            }
            int RandomItemGeneratrionManufacturerNumber = CreatingRandom32BitIntNumbers(iss->Seed, 0, 11 + 1);
            for (size_t i = 0; i < 11; i++)
            {
                if (RolledItem.ItemBaseRollTable.manufacturerRollTable[i].ManufacturerType == RandomItemGeneratrionManufacturerNumber)
                {
                    static auto RolledItemManufacturer = RolledItem.ItemBaseRollTable.manufacturerRollTable[i];
                    iter.entity(it).set<ItemComponents::ItemManufacturer>({RolledItemManufacturer.ManufacturerType,
                        CreatingRandom32BitIntNumbers(iss->Seed,RolledItemManufacturer.ManufacturerStatIntRollMin,RolledItemManufacturer.ManufacturerStatIntRollMax),
                        CreatingRandom32BitFloatNumbers(iss->Seed,RolledItemManufacturer.ManufacturerStatFloatRollMin,RolledItemManufacturer.ManufacturerStatFloatRollMax)
                        });
                }
            }

            iter.entity(it).set<>(RolledItem.ItemTags.OneHandedSwordItemTagComponentsStuctConfig.RelationLayer1);
            iter.entity(it).set<>(RolledItem.ItemTags.OneHandedSwordItemTagComponentsStuctConfig.RelationLayer2);
            iter.entity(it).set<>(RolledItem.ItemTags.OneHandedSwordItemTagComponentsStuctConfig.RelationLayer3);
            iter.entity(it).set<>(RolledItem.ItemTags.OneHandedSwordItemTagComponentsStuctConfig.RelationLayer4);
            iter.entity(it).set<>(RolledItem.ItemTags.OneHandedSwordItemTagComponentsStuctConfig.RelationLayer5);

            iter.entity(it).set<>(RolledItem.ItemComponentConfigStruct.MeleeItemComponentsConfigStruct.ItemStat1);
            iter.entity(it).set<>(RolledItem.ItemComponentConfigStruct.MeleeItemComponentsConfigStruct.ItemStat2);
            iter.entity(it).set<>(RolledItem.ItemComponentConfigStruct.MeleeItemComponentsConfigStruct.ItemStat3);
            iter.entity(it).set<>(RolledItem.ItemComponentConfigStruct.MeleeItemComponentsConfigStruct.ItemStat4);
            iter.entity(it).set<>(RolledItem.ItemComponentConfigStruct.MeleeItemComponentsConfigStruct.ItemStat5);
            iter.entity(it).set<>(RolledItem.ItemComponentConfigStruct.MeleeItemComponentsConfigStruct.ItemStat6);
            iter.entity(it).set<>(RolledItem.ItemComponentConfigStruct.MeleeItemComponentsConfigStruct.ItemStat7);
            iter.entity(it).set<>(RolledItem.ItemComponentConfigStruct.MeleeItemComponentsConfigStruct.ItemStat8);
            iter.entity(it).set<>(RolledItem.ItemComponentConfigStruct.MeleeItemComponentsConfigStruct.ItemStat9);
            iter.entity(it).set<>(RolledItem.ItemComponentConfigStruct.MeleeItemComponentsConfigStruct.ItemStat10);
            iss->ItemStage = 3;
            std::cout << "System AddItemComponentstoEntity is creating Items " << std::endl;
        }
    }
}

void Item::CreatingRarityModComponentsToEntity(const flecs::iter& iter, ItemComponents::ItemBase* ib, ItemComponents::ItemStaging* iss, ItemComponents::ItemRarity* ir)
{
    for (auto it : iter)
    {
        if (iss->ItemStage == 3)
        {
            static const auto RolledItem = ItemConfig::RolltableArray[ib->BaseItemType];
            static const auto RolledItemRarity = RolledItem.ItemBaseRollTable.rarityRollTable[ir->RarityAffixAllowance];
            if (RolledItemRarity.RarityAffixAllowance == 1 || RolledItemRarity.RarityAffixAllowance > 1)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods1>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 1 ItemAffixMod component " << std::endl;
            }
            if (RolledItemRarity.RarityAffixAllowance == 2 || RolledItemRarity.RarityAffixAllowance > 2)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods2>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 2 ItemAffixMod component " << std::endl;
            }
            if (RolledItemRarity.RarityAffixAllowance == 3 || RolledItemRarity.RarityAffixAllowance > 3)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods3>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 3 ItemAffixMod component " << std::endl;
            }
            if (RolledItemRarity.RarityAffixAllowance == 4 || RolledItemRarity.RarityAffixAllowance > 4)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods4>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 4 ItemAffixMod component " << std::endl;
            }
            if (RolledItemRarity.RarityAffixAllowance == 5 || RolledItemRarity.RarityAffixAllowance > 5)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods5>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 5 ItemAffixMod component " << std::endl;
            }
            if (RolledItemRarity.RarityAffixAllowance == 6 || RolledItemRarity.RarityAffixAllowance > 6)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods6>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 6 ItemAffixMod component " << std::endl;
            }
            if (RolledItemRarity.RarityAffixAllowance == 7 || RolledItemRarity.RarityAffixAllowance > 7)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods7>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 7 ItemAffixMod component " << std::endl;
            }
            if (RolledItemRarity.RarityAffixAllowance == 8 || RolledItemRarity.RarityAffixAllowance > 8)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods8>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 8 ItemAffixMod component " << std::endl;
            }
            if (RolledItemRarity.RarityAffixAllowance == 9 || RolledItemRarity.RarityAffixAllowance > 9)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods9>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 9 ItemAffixMod component " << std::endl;
            }
            if (RolledItemRarity.RarityAffixAllowance == 10)
            {
                iter.entity(it).set<ItemComponents::ItemAffixMods10>({});
                std::cout << "System CreatingRarityModComponentsToEntity has add 10 ItemAffixMod component " << std::endl;
            }
            if (RolledItemRarity.RarityAffixAllowance == 0)
            {
                std::cout << "System CreatingRarityModComponentsToEntity has add 0 ItemAffixMod component " << std::endl;
            }
            iss->ItemStage = 4;
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
