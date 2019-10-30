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
	Player GetPlayer() const;
	Enemy* GetEnemy() const;
private:
	Player _player;
	Enemy* _enemy;
};

