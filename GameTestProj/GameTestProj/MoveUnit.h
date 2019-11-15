#pragma once
#include <vector>
#include <memory>
#include "SmartPlayer.h"
#include "Enemy.h"
#include "Combat.h"
#include "RepairCenter.h"
class MoveUnit
{
public:
	MoveUnit();
	~MoveUnit();

	void SmartUnitMove4(SmartPlayer& player, std::vector<std::shared_ptr<Enemy>>& smartEnemies, SmartInventory& gameInv, Board& board, bool& running);

	void SetDir(const int value);

	int GetSmartEnemyInd(const int x, const int y, const std::vector<std::shared_ptr<Enemy>>& smartEnemies) const;

	int GetDirection() const;

private:
	Combat _bettle;
	RepairCenter _repairCenter;
	int _dir;
};

