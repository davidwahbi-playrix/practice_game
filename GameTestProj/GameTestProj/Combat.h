#pragma once
#include <iostream>
#include <memory>
#include "SmartPlayer.h"
#include "Enemy.h"
class Combat
{
public:
	Combat();
	~Combat();

	void SmartBattle3(SmartPlayer& player, std::shared_ptr<Enemy>& smartEnemy, bool& canContinue);

private:

};

