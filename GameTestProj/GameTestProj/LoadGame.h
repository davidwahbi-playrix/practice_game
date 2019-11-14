#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <memory>
class LoadGame
{
public:
	LoadGame();
	~LoadGame();

	void LoadSmartGameState2(int& level, Inventory& gameItems, Player& player, std::vector<std::shared_ptr<Enemy>>& smartEnemies, Board& board);

	void LoadPlayer2(std::ifstream& file, Player& player);

	void LoadPlayerEquipment2(std::ifstream& file, const int state, Player& player);

	void LoadSmartEnemy2(std::ifstream& file, const unsigned int size, std::vector<std::shared_ptr<Enemy>>& smartEnemies);

	void LoadInventory(std::ifstream& file, const unsigned int size, Inventory& inventory);

	void LoadBoard2(int& currLevel, Board& board, Player& player, Inventory& gameItems, std::vector<std::shared_ptr<Enemy>>& smartEnemies);

	int ReadIntFromFile(std::ifstream& file);
private:

};

