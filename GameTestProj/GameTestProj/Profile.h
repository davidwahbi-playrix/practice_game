#pragma once
#include "Player.h"
#include "Enemy.h"
#include "LevelLoader.h"
#include <vector>
#include <memory>
class Profile
{
public:
	Profile();
	~Profile();

	void NewGame();

	int GetLevel() const;
	Player GetPlayer() const;
	Inventory GetGameItems() const;
	//SmartInventory GetSmartGameItems() const;
	Board GetBoard() const;
	std::vector<std::shared_ptr<Enemy>> GetSmartEnemies() const;
	LevelLoader GetLevelLoader() const;

	void IncreseLevel();
	void SetPlayer(const Player& player);
	void SetGameItems(const Inventory& inv);
	//void SetSmartGameItems(const SmartInventory& inv);
	void SetBoard(const Board& board);
	void SetSmartEnemies(const std::vector<std::shared_ptr<Enemy>> smartEnemies);
	Player LoadPlayer();
private:
	Player _player;
	std::vector<std::shared_ptr<Enemy>> _smartEnemies;
	Inventory _gameItems;
	//SmartInventory _smartGameItems;
	Board _board;
	LevelLoader _levelLoader;
	int _currentLevel;
};

