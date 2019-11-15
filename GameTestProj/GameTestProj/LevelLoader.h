#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "Enemy.h"
#include "SmartPlayer.h"
#include "Inventory.h"
#include "SmartInventory.h"

class LevelLoader
{
public:
	LevelLoader();
	~LevelLoader();

	void LoadPlayer2(SmartPlayer& player);

	void SetPlayerStartPos2(const int& level, SmartPlayer& player);

	void LoadLevel3(const int& currLevel, bool& running, Board& board, SmartInventory& gameItems, std::vector<std::shared_ptr<Enemy>>& smartEnemies);

	void LoadInventory2(std::ifstream& file, const unsigned int size, SmartInventory& inventory);

	void LoadSmartEnemy2(std::ifstream& file, const unsigned int size, std::vector<std::shared_ptr<Enemy>>& smartEnemies);

	void LoadPlayerInfo2(std::ifstream& file, SmartPlayer& player);

	int ReadIntFromFile(std::ifstream& file);
private:
	const int MAXLEVEL = 3;
};

