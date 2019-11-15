#include "MoveUnit.h"

MoveUnit::MoveUnit()
{
	_dir = 0;
}

MoveUnit::~MoveUnit()
{
}

void MoveUnit::SmartUnitMove4(SmartPlayer & player, std::vector<std::shared_ptr<Enemy>>& smartEnemies, SmartInventory & gameInv, Board & board, bool & running)
{
	size_t enemyBattleIndex = -1;

	player.MoveObject2(player.GetMovePos(_dir)._posX, player.GetMovePos(_dir)._posY, board);

	if (player.GetEnemyFlag())
	{
		int index = GetSmartEnemyInd(player.GetPosX(), player.GetPosY(), smartEnemies);
		enemyBattleIndex = index;
		_bettle.SmartBattle3(player, smartEnemies[index], running);
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
		_repairCenter.ReapirEquipment3(player);
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
				_bettle.SmartBattle3(player, smartEnemies[i], running);
				if (smartEnemies[i] == nullptr)
				{
					smartEnemies.erase(smartEnemies.begin() + i);
				}
			}
		}
	}
	_dir = 0;
}


void MoveUnit::SetDir(const int value)
{
	_dir = value;
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
