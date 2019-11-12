#pragma once
#include "Player.h"
#include "Enemy.h"
#include "LevelLoader.h"
#include <vector>
#include <memory>

const int MAXLEVEL = 3;

class Profile
{
public:
	Profile();
	~Profile();

	void NewGame(bool& running);

	int GetLevel() const;

	void GameOver(bool& running);

	bool CanPlayerEquip() const;

	Player GetPlayer() const;
	Player& GetPlayer2();

	Inventory GetGameItems() const;
	Inventory& GetGameItems2();

	//SmartInventory GetSmartGameItems() const;
	Board GetBoard() const;
	Board& GetBoard2();

	std::vector<std::shared_ptr<Enemy>> GetSmartEnemies() const;
	std::vector<std::shared_ptr<Enemy>>& GetSmartEnemies2();

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

