#include "MoveUnit.h"

MoveUnit::MoveUnit()
{
	_dir = 0;
	_continue = true;
}

MoveUnit::~MoveUnit()
{
}

void MoveUnit::SmartUnitMove3(Player & player, std::vector<std::shared_ptr<Enemy>>& smartEnemies, Inventory & gameInv, Board & board)
{
	size_t enemyBattleIndex = -1;
	bool status = true;

	player.MoveObject2(player.GetMovePos(_dir)._posX, player.GetMovePos(_dir)._posY, board);

	if (player.GetEnemyFlag())
	{
		int index = GetSmartEnemyInd(player.GetPosX(), player.GetPosY(), smartEnemies);
		enemyBattleIndex = index;
		_bettle.SmartBattle2(player, smartEnemies[index]);
		status = _bettle.GetContinue();
		if (smartEnemies[index] == nullptr)
		{
			smartEnemies.erase(smartEnemies.begin() + index);
		}
	}
	if (player.GetPickedFlag())
	{
		player.UpdatePlayerInventory2(gameInv);
	}
	if (player.GetRepairEntered())
	{
		_repairCenter.ReapirEquipment2(player);
		_repairCenter.SetExit(false);
		player.SetRepairEntered(false);
	}
	for (size_t i = 0; i < smartEnemies.size(); i++)
	{
		if (smartEnemies[i])
		{
			int moveDir = rand() % 4 + 1;

			smartEnemies[i]->MoveObject2(player.GetMovePos(moveDir)._posX, player.GetMovePos(moveDir)._posY, board);

			if (smartEnemies[i]->GetPlayerEncounter() && enemyBattleIndex != i)
			{
				_bettle.SmartBattle2(player, smartEnemies[i]);
				status = _bettle.GetContinue();
				if (smartEnemies[i] == nullptr)
				{
					smartEnemies.erase(smartEnemies.begin() + i);
				}
			}
		}
	}
}


void MoveUnit::SetDir(const int value)
{
	_dir = value;
}

void MoveUnit::SetContinue(const bool & value)
{
	_continue = value;
}

bool MoveUnit::GetContinue() const
{
	return _continue;
}

int MoveUnit::GetSmartEnemyInd(const int x, const int y, const std::vector<std::shared_ptr<Enemy>>& smartEnemies) const
{
	int index = 0;
	for (int i = 0; i < smartEnemies.size(); i++)
	{
		if (smartEnemies[i]->GetPosX() == x && smartEnemies[i]->GetPosY() == y)
		{
			index = i;
		}
	}
	return index;
}


int MoveUnit::GetDirection() const
{
	return _dir;
}
