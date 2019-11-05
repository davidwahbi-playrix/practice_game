#include "MoveUnit.h"

MoveUnit::MoveUnit()
{
	this->_dir = 0;
	this->_continue = true;
}

MoveUnit::~MoveUnit()
{
}

Board MoveUnit::SmartUnitMove2(Player player, std::vector<std::shared_ptr<Enemy>> smartEnemies, Inventory gameInv, Board board)
{
	Inventory tmpInv;
	Board tmpBoard = board;
	size_t enemyBattleIndex = -1;
	bool status = true;
	switch (this->_dir)
	{
	case 1:
		this->_dir = 0;
		tmpBoard = player.MoveObject(0, -1, tmpBoard);
		break;
	case 2:
		this->_dir = 0;
		tmpBoard = player.MoveObject(1, 0, tmpBoard);
		break;
	case 3:
		this->_dir = 0;
		tmpBoard = player.MoveObject(0, 1, tmpBoard);
		break;
	case 4:
		this->_dir = 0;
		tmpBoard = player.MoveObject(-1, 0, tmpBoard);
		break;
	default:
		break;
	}
	if (player.GetEnemyFlag())
	{
		int index = this->GetSmartEnemyInd(player.GetPosX(), player.GetPosY(), smartEnemies);
		enemyBattleIndex = index;
		this->_bettle.SmartBattle(player, smartEnemies[index]);
		status = _bettle.GetContinue();
		player = this->_bettle.GetPlayer();
		smartEnemies[index] = std::move(this->_bettle.GetSmartEnemy());
		if (smartEnemies[index] == nullptr)
		{
			smartEnemies.erase(smartEnemies.begin() + index);
		}
	}
	if (player.GetPickedFlag())
	{
		tmpInv = player.UpdatePlayerInventory(gameInv);
	}
	else
	{
		tmpInv = gameInv;
	}
	if (player.GetRepairEntered())
	{
		int tmpValue = this->_repairCenter.ReapirEquipment(player);
		this->_repairCenter.SetExit(false);
		player.SetRepairEntered(false);
		if (player.GetArmor())
		{
			Armor* tmpArmor = player.GetArmor();
			tmpArmor->SetArmorValue(tmpValue);
			player.SetArmor(tmpArmor);
			player.SetDefence(tmpArmor->GetArmorValue());
		}
	}
	for (size_t i = 0; i < smartEnemies.size(); i++)
	{
		if (smartEnemies[i])
		{
			int moveDir = rand() % 4 + 1;
			switch (moveDir)
			{
			case 1:
				tmpBoard = smartEnemies[i]->MoveObject(0, -1, tmpBoard);
				break;
			case 2:
				tmpBoard = smartEnemies[i]->MoveObject(1, 0, tmpBoard);
				break;
			case 3:
				tmpBoard = smartEnemies[i]->MoveObject(0, 1, tmpBoard);
				break;
			case 4:
				tmpBoard = smartEnemies[i]->MoveObject(-1, 0, tmpBoard);
				break;
			default:
				break;
			}

			if (smartEnemies[i]->GetPlayerEncounter() && enemyBattleIndex != i)
			{
				this->_bettle.SmartBattle(player, smartEnemies[i]);
				status = _bettle.GetContinue();
				player = this->_bettle.GetPlayer();
				smartEnemies[i] = std::move(this->_bettle.GetSmartEnemy());
				if (smartEnemies[i] == nullptr)
				{
					smartEnemies.erase(smartEnemies.begin() + i);
				}
			}
		}
	}
	this->_player = player;
	this->_smartEnemies = std::move(smartEnemies);
	this->_gameInv = tmpInv;
	this->_continue = status;

	return tmpBoard;
}


void MoveUnit::SetDir(const int value)
{
	this->_dir = value;
}

void MoveUnit::SetContinue(const bool & value)
{
	this->_continue = value;
}

bool MoveUnit::GetContinue() const
{
	return this->_continue;
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
	return this->_dir;
}

Player MoveUnit::GetPlayer() const
{
	return this->_player;
}

Inventory MoveUnit::GetGameInv() const
{
	return this->_gameInv;
}

std::vector<std::shared_ptr<Enemy>> MoveUnit::GetSmartEnemies() const
{
	return this->_smartEnemies;
}
