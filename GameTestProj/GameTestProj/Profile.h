#pragma once
#include "Player.h"
#include "Enemy.h"
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

	void SetPlayer(const Player& player);
	void SetEnemy(Enemy* enemy);
	void SetGameItems(const Inventory& inv);
	void SetBoard(const Board& board);
private:
	Player _player;
	Enemy* _enemy;
	Inventory _gameItems;
	Board _board;
};

