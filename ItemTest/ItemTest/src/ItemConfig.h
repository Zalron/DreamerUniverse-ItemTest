
#pragma once
#include "ItemComponents.h"
#include <iostream>

using namespace std;

struct ItemConfig
{

    static const struct ItemBaseConfig
    {
        //string BaseName;
        //int BaseTypeChance;
        int BaseTypeIntRollMin;
        int BaseTypeIntRollMax;
        float BaseTypeFloatRollMin;
        float BaseTypeFloatRollMax;
    };

    static const struct ItemRarityConfig
    {
        int RarityLevel;
        int RarityAffixAllowance;
        int RaritySpawnChanceMin;
        int RaritySpawnChanceMax;
        float RarityFloatRollMin;
        float RarityFloatRollMax;
        int RarityIntRollMin;
        int RarityIntRollMax;
    };

    static const struct ItemAffixModsConfig
    {
        //string ModsString;
        int ModChanceMin;
        int ModChanceMax;
        int AffixPlace;
        int ModType;
        int ModStatRollMin;
        int ModStatRollMax;
    };

    static const struct ItemManufacturerConfig
    {
        //string ManufacturerString;
        int ManufacturerType;
        int ManufacturerStatIntRollMin;
        int ManufacturerStatIntRollMax;
        float ManufacturerStatFloatRollMin;
        float ManufacturerStatFloatRollMax;
    };

    static const struct ItemMaterialConfig
    {
        //string MaterialString;
        
        int MaterialChanceMin;
        int MaterialChanceMax;
        int MaterialType;
        int MaterialStatIntRollMin;
        int MaterialStatIntRollMax;
        float MaterialStatFloatRollMin;
        float MaterialStatFloatRollMax;
    };

    static const struct ItemQualityConfig
    {
        //string QualityString;
        int QualitySpawnChanceMin;
        int QualitySpawnChanceMax;
        int QualityNum;
        int QualityIntStatIncrease;
        float QualityFloatStatIncrease;
    };

    static const struct ItemPartsConfig
    {
        //string PartsString;
        int PartsChanceMin;
        int PartsChanceMax;
        int PartsType;
        int PartsStatIntRollMin;
        int PartsStatIntRollMax;
        float PartsStatFloatRollMin;
        float PartsStatFloatRollMax;
    };

    ItemConfig(flecs::world& world)
    {
        world.module<ItemComponents>();

        world.component<ItemBaseConfig>();
        world.component<ItemRarityConfig>();
        world.component<ItemAffixModsConfig>();
        world.component<ItemManufacturerConfig>();
        world.component<ItemMaterialConfig>();
        world.component<ItemQualityConfig>();
    }

    static const struct MeleeItemComponentsConfig
    {
        ItemComponents::CriticalChanceItemStat ItemStat1;
        ItemComponents::MagicalDamageItemStat ItemStat2;
        ItemComponents::PhysicalDamageItemStat ItemStat3;
        ItemComponents::HandlingItemStat ItemStat4;
        ItemComponents::AccuracyItemStat ItemStat5;
        ItemComponents::RangeItemStat ItemStat6;
        ItemComponents::GuardItemStat ItemStat7;
        ItemComponents::BlockChanceItemStat ItemStat8;
        ItemComponents::AttackRateItemStat ItemStat9;
        ItemComponents::WeightItemStat ItemStat10;
    };

    static const struct RangeItemComponentsConfig
    {
        ItemComponents::CriticalChanceItemStat ItemStat1;
        ItemComponents::MagicalDamageItemStat ItemStat2;
        ItemComponents::PhysicalDamageItemStat ItemStat3;
        ItemComponents::HandlingItemStat ItemStat4;
        ItemComponents::AccuracyItemStat ItemStat5;
        ItemComponents::RangeItemStat ItemStat6;
        ItemComponents::MagazineSizeItemStat ItemStat7;
        ItemComponents::ReloadTimeItemStat ItemStat8;
        ItemComponents::FireRateItemStat ItemStat9;
        ItemComponents::WeightItemStat ItemStat10;
    };

    static const struct ArmourItemComponentsConfig
    {
        ItemComponents::CriticalChanceItemStat ItemStat1;
        ItemComponents::MagicalDamageItemStat ItemStat2;
        ItemComponents::PhysicalDamageItemStat ItemStat3;
        ItemComponents::HandlingItemStat ItemStat4;
        ItemComponents::AccuracyItemStat ItemStat5;
        ItemComponents::RangeItemStat ItemStat6;
        ItemComponents::GuardItemStat ItemStat7;
        ItemComponents::BlockChanceItemStat ItemStat8;
        ItemComponents::AttackRateItemStat ItemStat9;
        ItemComponents::WeightItemStat ItemStat10;
    };

    static const struct ItemComponentsConfig
    {
        MeleeItemComponentsConfig MeleeItemComponentsConfigStruct;
    };

    static const struct OneHandedSwordItemTagComponents
    {
        ItemComponents::EquipableItemTag RelationLayer1;
        ItemComponents::WeaponsItemTag RelationLayer2;
        ItemComponents::MeleeItemTag RelationLayer3;
        ItemComponents::OneHandedItemTag RelationLayer4;
        ItemComponents::SwordItemTag RelationLayer5;
    };

    static const struct ItemTagComponentsConfig
    {
        OneHandedSwordItemTagComponents OneHandedSwordItemTagComponentsStuctConfig;
    };

    static const struct StandardItemBaseRollTable
    {
        ItemRarityConfig rarityRollTable[11];

        ItemQualityConfig qualityRollTable[21];

        ItemMaterialConfig materialRollTable[10];

        ItemManufacturerConfig manufacturerRollTable[6];
    };

    static const struct NormalItemBaseRolltable
    {
        ItemTagComponentsConfig ItemTags;

        ItemComponentsConfig ItemComponentConfigStruct;

        ItemBaseConfig ItemBase;

        StandardItemBaseRollTable ItemBaseRollTable;

        /*ItemPartsConfig partRollTable1[];
        ItemPartsConfig partRollTable2[];
        ItemPartsConfig partRollTable3[];
        ItemPartsConfig partRollTable4[];
        ItemPartsConfig partRollTable5[];
        ItemPartsConfig partRollTable6[];
        ItemPartsConfig partRollTable7[];
        ItemPartsConfig partRollTable8[];
        ItemPartsConfig partRollTable9[];
        ItemPartsConfig partRollTable10[];*/

        /*ItemAffixModsConfig modsRollTable1[];
        ItemAffixModsConfig modsRollTable2[];
        ItemAffixModsConfig modsRollTable3[];
        ItemAffixModsConfig modsRollTable4[];
        ItemAffixModsConfig modsRollTable5[];
        ItemAffixModsConfig modsRollTable6[];
        ItemAffixModsConfig modsRollTable7[];
        ItemAffixModsConfig modsRollTable8[];
        ItemAffixModsConfig modsRollTable9[];
        ItemAffixModsConfig modsRollTable10[];*/
    };

    static constexpr MeleeItemComponentsConfig MeleeItemComponentsConfigStruct{};

    static constexpr ItemComponentsConfig ItemComponentConfigStruct{ MeleeItemComponentsConfigStruct };

    static constexpr OneHandedSwordItemTagComponents OneHandedSwordItemTagComponentsStruct{};

    static constexpr ItemTagComponentsConfig OneHandedSwordItemTagComponentsConfig{ OneHandedSwordItemTagComponentsStruct };


    static constexpr ItemBaseConfig OneHandedSwordBronzeFalx{ 14, 17, 2.5f, 2.9f }; //"One Handed Short Sword Bronze Falx"
    static constexpr ItemBaseConfig OneHandedSwordIllyrSica{ 8, 24, 3.2f, 4.0f }; //"One Handed Short Sword Illyr Sica"
    static constexpr ItemBaseConfig OneHandedSwordGrandDao{ 8, 24, 3.2f, 4.0f }; //"One Handed Short Sword Grand Dao"
    static constexpr ItemBaseConfig OneHandedSwordWateredXiphos{ 8, 24, 3.2f, 4.0f }; //"One Handed Short Sword Watered Xiphos"
    static constexpr ItemBaseConfig OneHandedSwordDryKhopesh{ 8, 24, 3.2f, 4.0f }; //"One Handed Short Sword Dry Khopesh"
    static constexpr ItemBaseConfig OneHandedSwordCuttingSabre{ 8, 24, 3.2f, 4.0f }; //"One Handed Short Sword Cutting Sabre"
    static constexpr ItemBaseConfig OneHandedSwordBloodyMacuahuitl{ 8, 24, 3.2f, 4.0f }; //"One Handed Short Sword Bloody Macuahuitl"
    static constexpr ItemBaseConfig OneHandedSwordShiningCrusader{ 8, 24, 3.2f, 4.0f }; //"One Handed Short Sword Shining Crusader"
    static constexpr ItemBaseConfig OneHandedSwordSerratedKhanda{ 8, 24, 3.2f, 4.0f }; //"One Handed Short Sword Serrated Khanda"
    static constexpr ItemBaseConfig OneHandedSwordHoledAkrafena{ 8, 24, 3.2f, 4.0f }; //"One Handed Short Sword Holed Akrafena"


    // static const ItemPartsConfig OneHandedSwordBronzeFalxPart1;

    static constexpr ItemRarityConfig ItemRarity1{ 1, 0, 0, 5000, 0, 0, 0, 4 }; //"Common"
    static constexpr ItemRarityConfig ItemRarity2{ 2, 1, 5000, 7000, 0, 0, 4, 10 }; //"Uncommon"
    static constexpr ItemRarityConfig ItemRarity3{ 3, 2, 7000, 7500, 0, 0,  10, 18 }; //"Rare"
    static constexpr ItemRarityConfig ItemRarity4{ 4, 3, 7500, 8900, 0, 0,  19, 28 }; //"Masterwork"
    static constexpr ItemRarityConfig ItemRarity5{ 5, 4, 8900, 9200, 0, 0,  28, 40 }; //"Epic"
    static constexpr ItemRarityConfig ItemRarity6{ 6, 5, 9200, 9300, 0, 0,  40, 54 }; //"Mythic"
    static constexpr ItemRarityConfig ItemRarity7{ 7, 6, 9300, 9350, 0, 0,  54, 70 }; //"Exotic"
    static constexpr ItemRarityConfig ItemRarity8{ 8, 7, 9350, 9390, 0, 0,  70, 86 }; //"Ancient"
    static constexpr ItemRarityConfig ItemRarity9{ 9, 8, 9390, 9430, 0, 0,  86, 104 }; //"Legendary"
    static constexpr ItemRarityConfig ItemRarity10{ 10, 9, 9430, 9450, 0, 0,  104, 124 }; //"Heirloom"
    static constexpr ItemRarityConfig ItemRarity11{ 11, 10, 9450, 10000, 0, 0,  124, 146 }; //"Transcendent"
    static constexpr ItemRarityConfig ItemRarity12{ 0, 0, 0, 0, 0, 0, 0 }; //"Unique"

    static constexpr ItemMaterialConfig ItemMaterial1{ 0, 1000, 1, 1, 3 }; // Wood
    static constexpr ItemMaterialConfig ItemMaterial2{ 1000, 2000, 2, 2, 5 }; // Stone
    static constexpr ItemMaterialConfig ItemMaterial3{ 2000, 3000, 3, 4, 7 }; // Copper
    static constexpr ItemMaterialConfig ItemMaterial4{ 3000, 4000, 4, 6, 10 }; // Iron
    static constexpr ItemMaterialConfig ItemMaterial5{ 4000, 5000, 5, 9, 20 }; // Steel
    static constexpr ItemMaterialConfig ItemMaterial6{ 5000, 6000, 6, 5, 30 }; // Obsidian
    static constexpr ItemMaterialConfig ItemMaterial7{ 6000, 7000, 7, 30, 50 }; // Diamond
    static constexpr ItemMaterialConfig ItemMaterial8{ 7000, 8000, 8, 90, 120 }; // Unimon 
    static constexpr ItemMaterialConfig ItemMaterial9{ 8000, 9000, 9, 90, 120 }; // Tetradurmus
    static constexpr ItemMaterialConfig ItemMaterial10{ 9000, 10000, 10, 200, 300 }; // Hexaferi

    static constexpr ItemManufacturerConfig ItemManufacturerConfig1{ 1, 250, 300, 20, 30 }; //Triumvirate 
    static constexpr ItemManufacturerConfig ItemManufacturerConfig2{ 2, 100, 180, 15, 16 }; //Kybi-Ran
    static constexpr ItemManufacturerConfig ItemManufacturerConfig3{ 3, 70, 130, 10.0f, 10.5f }; //Yib-Hud
    static constexpr ItemManufacturerConfig ItemManufacturerConfig4{ 4, 60, 85, 8, 10 }; //Ignition
    static constexpr ItemManufacturerConfig ItemManufacturerConfig5{ 5, 90, 180, 4.5f, 4.9f }; //Techcore
    static constexpr ItemManufacturerConfig ItemManufacturerConfig6{ 6, 40, 76, 1.2f, 3.4f }; //O-mal

    static constexpr ItemQualityConfig ItemQualityConfig0{0, 5000, 0, 0, 0 };
    static constexpr ItemQualityConfig ItemQualityConfig1{5000, 7000, 1, 2, 1.5f };
    static constexpr ItemQualityConfig ItemQualityConfig2{7000, 7500, 2, 4, 3 };
    static constexpr ItemQualityConfig ItemQualityConfig3{7500, 9000, 3, 6, 4.5f };
    static constexpr ItemQualityConfig ItemQualityConfig4{9000, 9200, 4, 8, 6 };
    static constexpr ItemQualityConfig ItemQualityConfig5{9200, 9300, 5, 10, 7.5f };
    static constexpr ItemQualityConfig ItemQualityConfig6{9300, 9350, 6, 12, 9 };
    static constexpr ItemQualityConfig ItemQualityConfig7{9350, 9400, 7, 14, 10.5f };
    static constexpr ItemQualityConfig ItemQualityConfig8{9400, 9450, 8, 16, 12 };
    static constexpr ItemQualityConfig ItemQualityConfig9{9450, 9500, 9, 18, 13.5f };
    static constexpr ItemQualityConfig ItemQualityConfig10{9500, 9550, 10, 20, 15 };
    static constexpr ItemQualityConfig ItemQualityConfig11{9550, 9600, 11, 22, 16.5f };
    static constexpr ItemQualityConfig ItemQualityConfig12{9600, 9650, 12, 24, 18 };
    static constexpr ItemQualityConfig ItemQualityConfig13{9650, 9700, 13, 26, 19.5f };
    static constexpr ItemQualityConfig ItemQualityConfig14{9700, 9750, 14, 28, 21 };
    static constexpr ItemQualityConfig ItemQualityConfig15{9750, 9800, 15, 30, 22.5f };
    static constexpr ItemQualityConfig ItemQualityConfig16{9800, 9850, 16, 32, 24 };
    static constexpr ItemQualityConfig ItemQualityConfig17{9850, 9900, 17, 24, 25.5f };
    static constexpr ItemQualityConfig ItemQualityConfig18{9900, 9950, 18, 26, 27 };
    static constexpr ItemQualityConfig ItemQualityConfig19{9950, 9955, 19, 28, 28.5f };
    static constexpr ItemQualityConfig ItemQualityConfig20{9955, 10000, 20, 30, 30 };

    static constexpr StandardItemBaseRollTable standardItemBaseRollTable
    {
        {{ItemRarity1},{ItemRarity2},{ItemRarity3},{ItemRarity4},{ItemRarity5},{ItemRarity6},{ItemRarity7},{ItemRarity8},{ItemRarity9},{ItemRarity10},{ItemRarity11}},
        {{ItemQualityConfig0},{ItemQualityConfig1},{ItemQualityConfig2},{ItemQualityConfig3},{ItemQualityConfig4},{ItemQualityConfig5},{ItemQualityConfig6},{ItemQualityConfig7},{ItemQualityConfig8},{ItemQualityConfig9},{ItemQualityConfig10},{ItemQualityConfig11},{ItemQualityConfig12},{ItemQualityConfig13},{ItemQualityConfig14},{ItemQualityConfig15},{ItemQualityConfig16},{ItemQualityConfig17},{ItemQualityConfig18},{ItemQualityConfig19},{ItemQualityConfig20}},
        {{ItemMaterial1},{ItemMaterial2},{ItemMaterial3},{ItemMaterial4},{ItemMaterial5},{ItemMaterial6},{ItemMaterial7},{ItemMaterial8},{ItemMaterial9},{ItemMaterial10}},
        {{ItemManufacturerConfig1},{ItemManufacturerConfig2},{ItemManufacturerConfig3},{ItemManufacturerConfig4},{ItemManufacturerConfig5},{ItemManufacturerConfig6}}
    };

    static constexpr NormalItemBaseRolltable OneHandedSwordBronzeFalxRollTable
    {
        {OneHandedSwordItemTagComponentsConfig},
        {ItemComponentConfigStruct},
        {OneHandedSwordBronzeFalx},
        {standardItemBaseRollTable}
    };

    static constexpr NormalItemBaseRolltable OneHandedSwordIllyrSicaRollTable
    {
        {OneHandedSwordItemTagComponentsConfig},
        {ItemComponentConfigStruct},
        {OneHandedSwordIllyrSica},
        {standardItemBaseRollTable}
    };

    static constexpr NormalItemBaseRolltable OneHandedSwordGrandDaoRollTable
    {
        {OneHandedSwordItemTagComponentsConfig},
        {ItemComponentConfigStruct},
        {OneHandedSwordGrandDao},
        {standardItemBaseRollTable}
    };

    static constexpr NormalItemBaseRolltable OneHandedSwordWateredXiphosRollTable
    {
        {OneHandedSwordItemTagComponentsConfig},
        {ItemComponentConfigStruct},
        {OneHandedSwordWateredXiphos},
        {standardItemBaseRollTable}
    };

    static constexpr NormalItemBaseRolltable OneHandedSwordDryKhopeshRollTable
    {
        {OneHandedSwordItemTagComponentsConfig},
        {ItemComponentConfigStruct},
        {OneHandedSwordDryKhopesh},
        {standardItemBaseRollTable}
    };

    static constexpr NormalItemBaseRolltable OneHandedSwordCuttingSabreRollTable
    {
        {OneHandedSwordItemTagComponentsConfig},
        {ItemComponentConfigStruct},
        {OneHandedSwordCuttingSabre},
        {standardItemBaseRollTable}
    };

    static constexpr NormalItemBaseRolltable OneHandedSwordBloodyMacuahuitlRollTable
    {
        {OneHandedSwordItemTagComponentsConfig},
        {ItemComponentConfigStruct},
        {OneHandedSwordBloodyMacuahuitl},
        {standardItemBaseRollTable}
    };

    static constexpr NormalItemBaseRolltable OneHandedSwordShiningCrusaderRollTable
    {
        {OneHandedSwordItemTagComponentsConfig},
        {ItemComponentConfigStruct},
        {OneHandedSwordShiningCrusader},
        {standardItemBaseRollTable}
    };

    static constexpr NormalItemBaseRolltable OneHandedSwordSerratedKhandaRollTable
    {
        {OneHandedSwordItemTagComponentsConfig},
        {ItemComponentConfigStruct},
        {OneHandedSwordSerratedKhanda},
        {standardItemBaseRollTable}
    };

    static constexpr NormalItemBaseRolltable OneHandedSwordHoledAkrafenaRollTable
    {
        {OneHandedSwordItemTagComponentsConfig},
        {ItemComponentConfigStruct},
        {OneHandedSwordHoledAkrafena},
        {standardItemBaseRollTable}
    };

    static constexpr int RolltableArrayLength = 10;

    static constexpr NormalItemBaseRolltable RolltableArray[RolltableArrayLength]
    {
        {OneHandedSwordBronzeFalxRollTable},
        {OneHandedSwordIllyrSicaRollTable},
        {OneHandedSwordGrandDaoRollTable},
        {OneHandedSwordWateredXiphosRollTable},
        {OneHandedSwordDryKhopeshRollTable},
        {OneHandedSwordCuttingSabreRollTable},
        {OneHandedSwordBloodyMacuahuitlRollTable},
        {OneHandedSwordShiningCrusaderRollTable},
        {OneHandedSwordSerratedKhandaRollTable},
        {OneHandedSwordHoledAkrafenaRollTable},
    };
};