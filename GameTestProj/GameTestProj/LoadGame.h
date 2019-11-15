#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <memory>
#include "SmartPlayer.h"
#include "Enemy.h"
class LoadGame
{
public:
	LoadGame();
	~LoadGame();

	void LoadSmartGameState3(int& level, SmartInventory& gameItems, SmartPlayer& player, std::vector<std::shared_ptr<Enemy>>& smartEnemies, Board& board);

	void LoadSmartPlayer2(std::ifstream& file, SmartPlayer& player);

	void LoadSmartPlayerEquipment2(std::ifstream& file, const int state, SmartPlayer& player);

	void LoadSmartEnemy2(std::ifstream& file, const unsigned int size, std::vector<std::shared_ptr<Enemy>>& smartEnemies);

	void LoadInventory2(std::ifstream& file, const unsigned int size, SmartInventory& inventory);

	void LoadSmartBoard2(int& currLevel, Board& board, SmartPlayer& player, SmartInventory& gameItems, std::vector<std::shared_ptr<Enemy>>& smartEnemies);

	int ReadIntFromFile(std::ifstream& file);
private:

};

