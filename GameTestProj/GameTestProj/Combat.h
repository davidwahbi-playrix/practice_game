#pragma once
#include <iostream>
#include "Player.h"
#include "Enemy.h"
class Combat
{
public:
	Combat();
	Combat(Player player, Enemy* enemy);
	~Combat();

	void Battle();
	Player GetPlayer();
	Enemy* GetEnemy();
private:
	Player _player;
	Enemy* _enemy;
};

