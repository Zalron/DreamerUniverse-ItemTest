#include "ItemConfig.h"
#include <iostream> 

void ItemConfig::CheckRarityConfigValues(ItemRarityConfig itemRarityConfig)
{
	std::cout << "Checking all values for ItemRarityConfig RarityAffixAllowance " << itemRarityConfig.RarityAffixAllowance << " " << std::endl;
	std::cout << "Checking all values for ItemRarityConfig RarityLevel " << itemRarityConfig.RarityLevel << " " << std::endl;
	std::cout << "Checking all values for ItemRarityConfig RaritySpawnChanceMin " << itemRarityConfig.RaritySpawnChanceMin << " " << std::endl;
	std::cout << "Checking all values for ItemRarityConfig RaritySpawnChanceMax " << itemRarityConfig.RaritySpawnChanceMax << " " << std::endl;
	std::cout << "Checking all values for ItemRarityConfig RarityIntRollMin " << itemRarityConfig.RarityIntRollMin << " " << std::endl;
	std::cout << "Checking all values for ItemRarityConfig RarityIntRollMax " << itemRarityConfig.RarityIntRollMax << " " << std::endl;
	std::cout << "Checking all values for ItemRarityConfig RarityFloatRollMin " << itemRarityConfig.RarityFloatRollMin << " " << std::endl;
	std::cout << "Checking all values for ItemRarityConfig RarityFloatRollMax " << itemRarityConfig.RarityFloatRollMax << " " << std::endl;
}