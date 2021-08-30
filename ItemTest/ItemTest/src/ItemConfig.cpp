#include "ItemConfig.h"
#include <iostream> 

void ItemConfig::StartConfig(const flecs::iter& iter, ItemConfigComponents::ConfigStage* cs)
{
    for (auto it : iter) 
    {
        if (cs->stage == 1) 
        {
            auto ConfigItemBronzeFalx = iter.world().entity();
            ConfigItemBronzeFalx.set<ItemConfigComponents::ItemBaseConfig>({1, 14, 17, 2.5f, 2.9f }); //"One Handed Short Sword Bronze Falx"
            ConfigItemBronzeFalx.set<ItemConfigComponents::ItemTagConfig>({1});
            ConfigItemBronzeFalx.set<ItemConfigComponents::ItemComponentsConfig>({1});
            ConfigItemBronzeFalx.set<ItemConfigComponents::StandardItemBaseRollTable>({ItemConfigComponents::standardItemBaseRollTable });

            auto ConfigItemIllyrSica = iter.world().entity();
            ConfigItemIllyrSica.set<ItemConfigComponents::ItemBaseConfig>({2, 14, 17, 2.5f, 2.9f }); //"One Handed Short Sword Illyr Sica"
            ConfigItemIllyrSica.set<ItemConfigComponents::ItemTagConfig>({1});
            ConfigItemIllyrSica.set<ItemConfigComponents::ItemComponentsConfig>({1});
            ConfigItemIllyrSica.set<ItemConfigComponents::StandardItemBaseRollTable>({ ItemConfigComponents::standardItemBaseRollTable });

            auto ConfigItemGrandDao = iter.world().entity();
            ConfigItemGrandDao.set<ItemConfigComponents::ItemBaseConfig>({3, 14, 17, 2.5f, 2.9f }); //"One Handed Short Sword Grand Dao"
            ConfigItemGrandDao.set<ItemConfigComponents::ItemTagConfig>({1});
            ConfigItemGrandDao.set<ItemConfigComponents::ItemComponentsConfig>({1});
            ConfigItemGrandDao.set<ItemConfigComponents::StandardItemBaseRollTable>({ ItemConfigComponents::standardItemBaseRollTable });

            auto ConfigItemWateredXiphos = iter.world().entity();
            ConfigItemWateredXiphos.set<ItemConfigComponents::ItemBaseConfig>({4, 14, 17, 2.5f, 2.9f }); //"One Handed Short Sword Watered Xiphos"
            ConfigItemWateredXiphos.set<ItemConfigComponents::ItemTagConfig>({1});
            ConfigItemWateredXiphos.set<ItemConfigComponents::ItemComponentsConfig>({1});
            ConfigItemWateredXiphos.set<ItemConfigComponents::StandardItemBaseRollTable>({ ItemConfigComponents::standardItemBaseRollTable });

            auto ConfigItemDryKhopesh = iter.world().entity();
            ConfigItemDryKhopesh.set<ItemConfigComponents::ItemBaseConfig>({5, 14, 17, 2.5f, 2.9f }); //"One Handed Short Sword Dry Khopesh"
            ConfigItemDryKhopesh.set<ItemConfigComponents::ItemTagConfig>({1});
            ConfigItemDryKhopesh.set<ItemConfigComponents::ItemComponentsConfig>({1});
            ConfigItemDryKhopesh.set<ItemConfigComponents::StandardItemBaseRollTable>({ ItemConfigComponents::standardItemBaseRollTable });

            auto ConfigItemCuttingSabre = iter.world().entity();
            ConfigItemCuttingSabre.set<ItemConfigComponents::ItemBaseConfig>({6, 14, 17, 2.5f, 2.9f }); //"One Handed Short Sword Cutting Sabre"
            ConfigItemCuttingSabre.set<ItemConfigComponents::ItemTagConfig>({1});
            ConfigItemCuttingSabre.set<ItemConfigComponents::ItemComponentsConfig>({1});
            ConfigItemCuttingSabre.set<ItemConfigComponents::StandardItemBaseRollTable>({ ItemConfigComponents::standardItemBaseRollTable });

            auto ConfigItemBloodyMacuahui = iter.world().entity();
            ConfigItemBloodyMacuahui.set<ItemConfigComponents::ItemBaseConfig>({7, 14, 17, 2.5f, 2.9f }); //"One Handed Short Sword Bloody Macuahuit"
            ConfigItemBloodyMacuahui.set<ItemConfigComponents::ItemTagConfig>({1});
            ConfigItemBloodyMacuahui.set<ItemConfigComponents::ItemComponentsConfig>({1});
            ConfigItemBloodyMacuahui.set<ItemConfigComponents::StandardItemBaseRollTable>({ ItemConfigComponents::standardItemBaseRollTable });

            auto ConfigItemShiningCrusader = iter.world().entity();
            ConfigItemShiningCrusader.set<ItemConfigComponents::ItemBaseConfig>({8, 14, 17, 2.5f, 2.9f }); //"One Handed Short Sword Shining Crusader"
            ConfigItemShiningCrusader.set<ItemConfigComponents::ItemTagConfig>({1});
            ConfigItemShiningCrusader.set<ItemConfigComponents::ItemComponentsConfig>({1});
            ConfigItemShiningCrusader.set<ItemConfigComponents::StandardItemBaseRollTable>({ ItemConfigComponents::standardItemBaseRollTable });

            auto ConfigItemSerratedKhanda = iter.world().entity();
            ConfigItemSerratedKhanda.set<ItemConfigComponents::ItemBaseConfig>({9, 14, 17, 2.5f, 2.9f }); //"One Handed Short Sword Serrated Khanda"
            ConfigItemSerratedKhanda.set<ItemConfigComponents::ItemTagConfig>({1});
            ConfigItemSerratedKhanda.set<ItemConfigComponents::ItemComponentsConfig>({1});
            ConfigItemSerratedKhanda.set<ItemConfigComponents::StandardItemBaseRollTable>({ ItemConfigComponents::standardItemBaseRollTable });

            auto ConfigItemHoledAkrafena = iter.world().entity();
            ConfigItemHoledAkrafena.set<ItemConfigComponents::ItemBaseConfig>({10, 14, 17, 2.5f, 2.9f }); //"One Handed Short Sword Holed Akrafena"
            ConfigItemHoledAkrafena.set<ItemConfigComponents::ItemTagConfig>({1});
            ConfigItemHoledAkrafena.set<ItemConfigComponents::ItemComponentsConfig>({1});
            ConfigItemHoledAkrafena.set<ItemConfigComponents::StandardItemBaseRollTable>({ ItemConfigComponents::standardItemBaseRollTable });

            iter.world().entity("Item").set<ItemComponents::ItemSpawning>({ 1000 });

            cs->stage++;
        }
    }
}


