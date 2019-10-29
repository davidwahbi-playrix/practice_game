#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Combat.h"
class MoveUnit
{
public:
	MoveUnit();
	~MoveUnit();

	void UnitMove(Player player, Enemy* enemy, Inventory gameInv);

	void SetDir(const int value);

	int GetDirection() const;
	Player GetPlayer() const;
	Enemy* GetEnemy() const;
private:
	Player _player;
	Enemy* _enemy;
	Combat _bettle;
	int _dir;
};

