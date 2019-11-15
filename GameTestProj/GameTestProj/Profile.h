#pragma once
#include <vector>
#include <memory>
#include "SmartPlayer.h"
#include "Enemy.h"
#include "LevelLoader.h"

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

	SmartPlayer& GetSmartPlayer2();
	SmartPlayer GetSmartPlayer2() const;

	SmartInventory& GetSmartGameItems();
	Board GetBoard() const;
	Board& GetBoard2();

	std::vector<std::shared_ptr<Enemy>> GetSmartEnemies() const;
	std::vector<std::shared_ptr<Enemy>>& GetSmartEnemies2();

	LevelLoader GetLevelLoader() const;
	void IncreseLevel();

private:
	SmartPlayer _smartPlayer;
	std::vector<std::shared_ptr<Enemy>> _smartEnemies;
	SmartInventory _smartGameItems;
	Board _board;
	LevelLoader _levelLoader;
	int _currentLevel;
};

