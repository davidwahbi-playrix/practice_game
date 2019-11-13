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

	void LoadSmartGameState();
	void LoadPlayer(std::ifstream& file);
	void LoadPlayerEquipment(std::ifstream& file, const int state);
	void LoadSmartEnemy(std::ifstream& file, const unsigned int size);
	void LoadInventory(std::ifstream& file, const unsigned int size, Inventory& inventory);
	void LoadBoard(int currLevel);

	Player GetPlayer() const;
	std::vector<std::shared_ptr<Enemy>> GetSmartEnemies() const;
	Inventory GetGameInventory() const;
	Board GetBoard() const;
	int GetCurrentLevel() const;
	int ReadIntFromFile(std::ifstream& file);
private:
	Player _player;
	std::vector<std::shared_ptr<Enemy>> _smartEnemies;
	Inventory _gameItems;
	Board _board;
	int _currentLevel;
};

