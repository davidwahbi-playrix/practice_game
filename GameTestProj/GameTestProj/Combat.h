#pragma once
#include <iostream>
#include "Player.h"
#include "Enemy.h"
class Combat
{
public:
	Combat();
	~Combat();

	void Battle(Player player, Enemy* enemy);
	Player GetPlayer();
	Enemy* GetEnemy();
private:
	Player _player;
	Enemy* _enemy;
};

