#pragma once
#include <iostream>
#include <memory>
#include "Player.h"
#include "Enemy.h"
class Combat
{
public:
	Combat();
	~Combat();

	void SmartBattle(Player player, std::shared_ptr<Enemy> smartEnemy);

	void SetContinue(const bool& value);

	bool GetContinue() const;
	Player GetPlayer() const;
	std::shared_ptr<Enemy> GetSmartEnemy();
private:
	Player _player;
	bool _continue;
	std::shared_ptr<Enemy> _smartEnemy;
};

