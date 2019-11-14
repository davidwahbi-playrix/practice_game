#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <memory>
class SaveGame
{
public:
	SaveGame();
	~SaveGame();

	void SaveSmartGameState(const int& level,Player& player, const std::vector<std::shared_ptr<Enemy>>& smartEnemies, Inventory& gameItems);
	void SaveInventory(std::ofstream& file, Inventory& inaventory);
	//void SaveSmartInventory(std::ofstream& file, Inventory& inventory);

	void SavePlayerEquipment(std::ofstream& file, Player player);
	//void SaveSmartPlayerEquipment(std::ofstream& file, Player player);
private:
	const int healConst = 1;
};

