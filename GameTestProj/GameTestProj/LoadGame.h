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
	void LoadGameItems(std::ifstream& file, const unsigned int size);
	void LoadPlayer(std::ifstream& file);
	void LoadPlayerIneventory(std::ifstream& file, const unsigned int size);
	void LoadPlayerEquipment(std::ifstream& file, const int state);
	void LoadSmartEnemy(std::ifstream& file, const unsigned int size);
	void LoadBoard();

	Player GetPlayer() const;
	std::vector<std::shared_ptr<Enemy>> GetSmartEnemies() const;
	Inventory GetGameInventory() const;
	Board GetBoard() const;
	int ReadIntFromFile(std::ifstream& file);
private:
	Player _player;
	std::vector<std::shared_ptr<Enemy>> _smartEnemies;
	Inventory _gameItems;
	Board _board;
};

