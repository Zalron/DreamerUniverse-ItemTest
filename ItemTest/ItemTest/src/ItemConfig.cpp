#include "ItemConfig.h"
#include <iostream> 




//
//ItemMaterialConfig  ItemConfig::GetConfigItemMaterialData(float ItemMaterial)
//{
//    if (ItemMaterial <= ItemMaterial1.MaterialChance)
//    {
//        return ItemMaterial1;
//    }
//    if (ItemMaterial > ItemMaterial1.MaterialChance && ItemMaterial <= ItemMaterial2.MaterialChance)
//    {
//        return ItemMaterial2;
//    }
//    if (ItemMaterial > ItemMaterial2.MaterialChance && ItemMaterial <= ItemMaterial3.MaterialChance)
//    {
//        return ItemMaterial3;
//    }
//    if (ItemMaterial > ItemMaterial3.MaterialChance && ItemMaterial <= ItemMaterial4.MaterialChance)
//    {
//        return ItemMaterial4;
//    }
//    if (ItemMaterial > ItemMaterial4.MaterialChance && ItemMaterial <= ItemMaterial5.MaterialChance)
//    {
//        return ItemMaterial5;
//    }
//    if (ItemMaterial > ItemMaterial5.MaterialChance && ItemMaterial <= ItemMaterial6.MaterialChance)
//    {
//        return ItemMaterial6;
//    }
//    if (ItemMaterial > ItemMaterial6.MaterialChance && ItemMaterial <= ItemMaterial7.MaterialChance)
//    {
//        return ItemMaterial7;
//    }
//    if (ItemMaterial > ItemMaterial7.MaterialChance && ItemMaterial <= ItemMaterial8.MaterialChance)
//    {
//        return ItemMaterial8;
//    }
//    if (ItemMaterial > ItemMaterial8.MaterialChance && ItemMaterial <= ItemMaterial9.MaterialChance)
//    {
//        return ItemMaterial9;
//    }
//    if (ItemMaterial > ItemMaterial9.MaterialChance && ItemMaterial <= ItemMaterial10.MaterialChance)
//    {
//        return ItemMaterial10;
//    }
//    ItemMaterialConfig errorItemType{0,0,0,0};
//    //Debug.Log("Error Item Material not found");
//    return errorItemType;
//}
//
//ItemManufacturerConfig  ItemConfig::GentConfigItemManufacturerData(int ItemManufacturer)
//{
//    if (ItemManufacturer == 1)
//    {
//        return ItemManufacturerConfig1;
//    }
//    if (ItemManufacturer == 2)
//    {
//        return ItemManufacturerConfig2;
//    }
//    if (ItemManufacturer == 3)
//    {
//        return ItemManufacturerConfig3;
//    }
//    if (ItemManufacturer == 4)
//    {
//        return ItemManufacturerConfig4;
//    }
//    if (ItemManufacturer == 5)
//    {
//        return ItemManufacturerConfig5;
//    }
//    if (ItemManufacturer == 6)
//    {
//        return ItemManufacturerConfig6;
//    }
//
//    ItemManufacturerConfig errorItemManufacturer{0,0,0};
//    return errorItemManufacturer;
//}
//
//ItemBaseTypeConfig  ItemConfig::GetConfigItemTypeData(float UseType, float ItemType, float ItemBase)
//{
//    if (UseType <= ItemBaseType1_1_1.UseTypeChance)
//    {
//        if (ItemType <= ItemBaseType1_1_1.TypeChance)
//        {
//            if (ItemBase <= ItemBaseType1_1_1.BaseTypeChance)
//            {
//                return ItemBaseType1_1_1;
//            }
//            if (ItemBase > ItemBaseType1_1_1.BaseTypeChance && ItemBase <= ItemBaseType1_1_2.BaseTypeChance)
//            {
//                return ItemBaseType1_1_2;
//            }
//        }
//    }
//
//    if (UseType > ItemBaseType1_1_1.UseTypeChance && UseType <= ItemBaseType7_1_1.UseTypeChance)
//    {
//        if (ItemType > ItemBaseType1_1_1.TypeChance && ItemType <= ItemBaseType7_1_1.UseTypeChance)
//        {
//            if (ItemBase <= ItemBaseType1_1_1.BaseTypeChance)
//            {
//                return ItemBaseType7_1_1;
//            }
//        }
//    }
//
//    ItemBaseTypeConfig errorItemType{0,0,0,0,0,0,0,0};
//    //Debug.Log("Error Item base not found");
//    return errorItemType;
//}