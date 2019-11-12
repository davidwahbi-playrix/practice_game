#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "Enemy.h"
#include "Inventory.h"

class LevelLoader
{
public:
	LevelLoader();
	~LevelLoader();

	void LoadLevel(int currLevel, bool& running);
	void LoadInventory(std::ifstream& file, const unsigned int size, Inventory& inventory);
	void LoadSmartEnemy(std::ifstream& file, const unsigned int size);

	Board GetBoard() const;
	Inventory GetGameItems() const;
	std::vector<std::shared_ptr<Enemy>> GetSmartEnemies() const;

	int ReadIntFromFile(std::ifstream& file);
private:
	std::vector<std::shared_ptr<Enemy>> _smartEnemies;
	Inventory _gameItems;
	Board _board;
	const int MAXLEVEL = 3;
};

