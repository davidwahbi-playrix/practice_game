#pragma once
#include "Player.h"
#include "Enemy.h"
#include "LevelLoader.h"
#include <vector>
#include <memory>

constexpr int MAXLEVEL = 3;
constexpr int FIRSTLEVEL = 1;
constexpr int VICTORY = 3;
constexpr int GAMEOVER = 99;

class Profile
{
public:
	Profile();
	~Profile();

	void NewGame(bool& running);

	int GetLevel() const;
	int& GetLevel2();

	void SetLevel(const int level);

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

private:
	Player _player;
	std::vector<std::shared_ptr<Enemy>> _smartEnemies;
	Inventory _gameItems;
	//SmartInventory _smartGameItems;
	Board _board;
	LevelLoader _levelLoader;
	int _currentLevel;
};

