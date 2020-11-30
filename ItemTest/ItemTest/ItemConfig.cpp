#include "ItemConfig.h"
#include <iostream> 


static ItemRarityConfig GetConfigItemRarityData(float ItemRarity)
{
    if (ItemRarity <= ItemRarity1.RarityChance)
    {
        return ItemRarity1;
    }
    if (ItemRarity > ItemRarity1.RarityChance && ItemRarity <= ItemRarity2.RarityChance)
    {
        return ItemRarity2;
    }
    if (ItemRarity > ItemRarity2.RarityChance && ItemRarity <= ItemRarity3.RarityChance)
    {
        return ItemRarity3;
    }
    if (ItemRarity > ItemRarity3.RarityChance && ItemRarity <= ItemRarity4.RarityChance)
    {
        return ItemRarity4;
    }
    if (ItemRarity > ItemRarity4.RarityChance && ItemRarity <= ItemRarity5.RarityChance)
    {
        return ItemRarity5;
    }
    if (ItemRarity > ItemRarity5.RarityChance && ItemRarity <= ItemRarity6.RarityChance)
    {
        return ItemRarity6;
    }
    if (ItemRarity > ItemRarity6.RarityChance && ItemRarity <= ItemRarity7.RarityChance)
    {
        return ItemRarity7;
    }
    if (ItemRarity > ItemRarity7.RarityChance && ItemRarity <= ItemRarity8.RarityChance)
    {
        return ItemRarity8;
    }
    if (ItemRarity > ItemRarity8.RarityChance && ItemRarity <= ItemRarity9.RarityChance)
    {
        return ItemRarity9;
    }
    if (ItemRarity > ItemRarity9.RarityChance && ItemRarity <= ItemRarity10.RarityChance)
    {
        return ItemRarity10;
    }
    if (ItemRarity > ItemRarity10.RarityChance && ItemRarity <= ItemRarity11.RarityChance)
    {
        return ItemRarity11;
    }
    if (ItemRarity < ItemRarity12.RarityChance)
    {
        return ItemRarity12;
    }
    ItemRarityConfig errorItemRarity{0,0,0,0,0};
    //Debug.Log("Error Item base not found");
    return errorItemRarity;
}

static ItemQualityConfig GetConfigItemQualityData(float ItemQuality)
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
    ItemQualityConfig errorItemQuality{0,0,0};
    return errorItemQuality;
}

static ItemMaterialConfig GetConfigItemMaterialData(float ItemMaterial)
{
    if (ItemMaterial <= ItemMaterial1.MaterialChance)
    {
        return ItemMaterial1;
    }
    if (ItemMaterial > ItemMaterial1.MaterialChance && ItemMaterial <= ItemMaterial2.MaterialChance)
    {
        return ItemMaterial2;
    }
    if (ItemMaterial > ItemMaterial2.MaterialChance && ItemMaterial <= ItemMaterial3.MaterialChance)
    {
        return ItemMaterial3;
    }
    if (ItemMaterial > ItemMaterial3.MaterialChance && ItemMaterial <= ItemMaterial4.MaterialChance)
    {
        return ItemMaterial4;
    }
    if (ItemMaterial > ItemMaterial4.MaterialChance && ItemMaterial <= ItemMaterial5.MaterialChance)
    {
        return ItemMaterial5;
    }
    if (ItemMaterial > ItemMaterial5.MaterialChance && ItemMaterial <= ItemMaterial6.MaterialChance)
    {
        return ItemMaterial6;
    }
    if (ItemMaterial > ItemMaterial6.MaterialChance && ItemMaterial <= ItemMaterial7.MaterialChance)
    {
        return ItemMaterial7;
    }
    if (ItemMaterial > ItemMaterial7.MaterialChance && ItemMaterial <= ItemMaterial8.MaterialChance)
    {
        return ItemMaterial8;
    }
    if (ItemMaterial > ItemMaterial8.MaterialChance && ItemMaterial <= ItemMaterial9.MaterialChance)
    {
        return ItemMaterial9;
    }
    if (ItemMaterial > ItemMaterial9.MaterialChance && ItemMaterial <= ItemMaterial10.MaterialChance)
    {
        return ItemMaterial10;
    }
    ItemMaterialConfig errorItemType{0,0,0,0};
    //Debug.Log("Error Item Material not found");
    return errorItemType;
}

static ItemManufacturerConfig GentConfigItemManufacturerData(int ItemManufacturer)
{
    if (ItemManufacturer == 1)
    {
        return ItemManufacturerConfig1;
    }
    if (ItemManufacturer == 2)
    {
        return ItemManufacturerConfig2;
    }
    if (ItemManufacturer == 3)
    {
        return ItemManufacturerConfig3;
    }
    if (ItemManufacturer == 4)
    {
        return ItemManufacturerConfig4;
    }
    if (ItemManufacturer == 5)
    {
        return ItemManufacturerConfig5;
    }
    if (ItemManufacturer == 6)
    {
        return ItemManufacturerConfig6;
    }

    ItemManufacturerConfig errorItemManufacturer{0,0,0};
    return errorItemManufacturer;
}

static ItemBaseTypeConfig GetConfigItemTypeData(float UseType, float ItemType, float ItemBase)
{
    if (UseType <= ItemBaseType1_1_1.UseTypeChance)
    {
        if (ItemType <= ItemBaseType1_1_1.TypeChance)
        {
            if (ItemBase <= ItemBaseType1_1_1.BaseTypeChance)
            {
                return ItemBaseType1_1_1;
            }
            if (ItemBase > ItemBaseType1_1_1.BaseTypeChance && ItemBase <= ItemBaseType1_1_2.BaseTypeChance)
            {
                return ItemBaseType1_1_2;
            }
        }
    }

    if (UseType > ItemBaseType1_1_1.UseTypeChance && UseType <= ItemBaseType7_1_1.UseTypeChance)
    {
        if (ItemType > ItemBaseType1_1_1.TypeChance && ItemType <= ItemBaseType7_1_1.UseTypeChance)
        {
            if (ItemBase <= ItemBaseType1_1_1.BaseTypeChance)
            {
                return ItemBaseType7_1_1;
            }
        }
    }

    ItemBaseTypeConfig errorItemType{0,0,0,0,0,0,0,0};
    //Debug.Log("Error Item base not found");
    return errorItemType;
}