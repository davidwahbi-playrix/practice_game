#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include "SmartPlayer.h"
#include "Enemy.h"
class SaveGame
{
public:
	SaveGame();
	~SaveGame();

	void SaveSmartGameState2(const int& level, SmartPlayer& player, const std::vector<std::shared_ptr<Enemy>>& smartEnemies, SmartInventory& gameItems);

	void SaveSmartInventory(std::ofstream& file, SmartInventory& inventory);

	void SaveSmartPlayerEquipment(std::ofstream& file, SmartPlayer player);
private:
	const int healConst = 1;
};

