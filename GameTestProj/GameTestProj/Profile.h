#pragma once
#include "Player.h"
#include "Enemy.h"
#include <vector>
class Profile
{
public:
	Profile();
	~Profile();

	void NewGame();

	Player GetPlayer() const;
	Enemy* GetEnemy() const;
	Inventory GetGameItems() const;
	Board GetBoard() const;
	std::vector<Enemy*> GetEnemies() const;

	void SetPlayer(const Player& player);
	void SetEnemy(Enemy* enemy);
	void SetGameItems(const Inventory& inv);
	void SetBoard(const Board& board);
	void SetEnemies(const std::vector<Enemy*> enemies);
private:
	Player _player;
	Enemy* _enemy;
	std::vector<Enemy*> _enemies;
	Inventory _gameItems;
	Board _board;
};

