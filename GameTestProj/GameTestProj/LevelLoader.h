#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "Enemy.h"
#include "Player.h"
#include "Inventory.h"

class LevelLoader
{
public:
	LevelLoader();
	~LevelLoader();

	void LoadPlayer(Player& player);
	void SetPlayerStartPos(const int& level, Player& player);

	void LoadLevel2(const int& currLevel, bool& running, Board& board, Inventory& gameItems, std::vector<std::shared_ptr<Enemy>>& smartEnemies);

	void LoadInventory(std::ifstream& file, const unsigned int size, Inventory& inventory);

	void LoadSmartEnemy2(std::ifstream& file, const unsigned int size, std::vector<std::shared_ptr<Enemy>>& smartEnemies);

	void LoadPlayerInfo(std::ifstream& file, Player& player);

	int ReadIntFromFile(std::ifstream& file);
private:
	const int MAXLEVEL = 3;
};

