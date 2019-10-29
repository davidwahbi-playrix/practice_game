#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "Player.h"
#include "Enemy.h"
class SaveGame
{
public:
	SaveGame();
	~SaveGame();

	void SaveGameState(Player player, Enemy* enemy, Inventory gameItems);
	void SaveGameItems(std::ofstream& file, Inventory gameItems);
	void SavePlayerInventory(std::ofstream& file, Player player);
	void SavePlayerEquipment(std::ofstream& file, Player player);
private:

	Player _player;
	Enemy* _enemy;
	Inventory _gameItems;
};

