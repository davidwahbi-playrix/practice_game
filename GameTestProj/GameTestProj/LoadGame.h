#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include "Player.h"
#include "Enemy.h"
class LoadGame
{
public:
	LoadGame();
	~LoadGame();

	void LoadGameState();
	void LoadGameItems(std::ifstream& file, const int size);
	void LoadPlayer(std::ifstream& file);
	void LoadPlayerIneventory(std::ifstream& file, const int size);
	void LoadPlayerEquipment(std::ifstream& file, const int state);
	void LoadEnemy(std::ifstream& file);
	void LoadBoard();

	Player GetPlayer();
	Enemy* GetEnemy();
	Inventory GetGameInventory();
	Board GetBoard();
	int ReadIntFromFile(std::ifstream& file);
private:
	Player _player;
	Enemy* _enemy;
	Inventory _gameItems;
	Board _board;
};

