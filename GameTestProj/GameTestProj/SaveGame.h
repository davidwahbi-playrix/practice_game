#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "Player.h"
#include "Enemy.h"
#include <vector>
class SaveGame
{
public:
	SaveGame();
	~SaveGame();

	void SaveGameState(Player player, std::vector<Enemy*> enemies, Inventory gameItems);
	void SaveGameItems(std::ofstream& file, Inventory gameItems);
	void SavePlayerInventory(std::ofstream& file, Player player);
	void SavePlayerEquipment(std::ofstream& file, Player player);
private:

	Player _player;
	std::vector<Enemy*> _enemies;
	Inventory _gameItems;
};

