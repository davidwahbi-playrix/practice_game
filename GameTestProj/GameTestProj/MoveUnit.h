#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Combat.h"
#include "RepairCenter.h"
#include <vector>
#include <memory>
class MoveUnit
{
public:
	MoveUnit();
	~MoveUnit();

	Board SmartUnitMove2(Player player, std::vector<std::shared_ptr<Enemy>> smartEnemies, Inventory gameInv, Board board);

	void SetDir(const int value);

	void SetContinue(const bool& value);

	bool GetContinue() const;

	int GetSmartEnemyInd(const int x, const int y, const std::vector<std::shared_ptr<Enemy>>& smartEnemies) const;

	int GetDirection() const;
	Player GetPlayer() const;
	Inventory GetGameInv() const;

	std::vector<std::shared_ptr<Enemy>> GetSmartEnemies() const;
private:
	Player _player;
	Combat _bettle;
	Inventory _gameInv;
	RepairCenter _repairCenter;
	bool _continue;
	std::vector<std::shared_ptr<Enemy>> _smartEnemies;
	int _dir;
};

