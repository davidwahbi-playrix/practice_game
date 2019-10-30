#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Combat.h"
#include <vector>
class MoveUnit
{
public:
	MoveUnit();
	~MoveUnit();

	void UnitMove(Player player, std::vector<Enemy*> enemies, Inventory gameInv);
	void SetDir(const int value);

	int GetEnemyInd(const int x, const int y, std::vector<Enemy*> enemies) const;

	int GetDirection() const;
	Player GetPlayer() const;
	Inventory GetGameInv() const;
	std::vector<Enemy*> GetEnemies() const;
private:
	Player _player;
	Combat _bettle;
	Inventory _gameInv;
	std::vector<Enemy*> _enemies;
	int _dir;
};

