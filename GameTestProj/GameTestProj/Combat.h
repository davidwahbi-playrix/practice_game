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

	void SmartBattle2(Player& player, std::shared_ptr<Enemy>& smartEnemy);

	void SetContinue(const bool& value);

	bool GetContinue() const;
private:
	bool _continue;
};

