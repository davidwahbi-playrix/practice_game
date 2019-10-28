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
	SaveGame(Player player, Enemy* enemy, Inventory gameItems);
	~SaveGame();

	void SaveGameState();
	void SaveGameItems(std::ofstream& file);
	void SavePlayerInventory(std::ofstream& file);
	void SavePlayerEquipment(std::ofstream& file);
private:

	Player _player;
	Enemy* _enemy;
	Inventory _gameItems;
};

