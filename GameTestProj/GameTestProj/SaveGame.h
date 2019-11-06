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

	void SaveSmartGameState(Player player, std::vector<std::shared_ptr<Enemy>> smartEnemies, Inventory gameItems);
	void SaveGameItems(std::ofstream& file, Inventory gameItems);
	//void SaveSmartGameItems(std::ofstream& file, Inventory gameItems);

	void SavePlayerInventory(std::ofstream& file, Player player);
	//void SaveSmartPlayerInventory(std::ofstream& file, Player player);

	void SavePlayerEquipment(std::ofstream& file, Player player);
	//void SaveSmartPlayerEquipment(std::ofstream& file, Player player);
private:

	Player _player;
	std::vector<std::shared_ptr<Enemy>> _smartEnemies;
	Inventory _gameItems;
	const int healConst = 1;
};

