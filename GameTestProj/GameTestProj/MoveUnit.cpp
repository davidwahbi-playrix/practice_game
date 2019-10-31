#include "MoveUnit.h"

MoveUnit::MoveUnit()
{
	this->_dir = 0;
}

MoveUnit::~MoveUnit()
{
}

void MoveUnit::SmartUnitMove(Player player, std::vector<std::shared_ptr<Enemy>> smartEnemies, Inventory gameInv)
{
	Inventory tmpInv;
	switch (this->_dir)
	{
	case 1:
		this->_dir = 0;
		player.MoveObject(0, -1);
		break;
	case 2:
		this->_dir = 0;
		player.MoveObject(1, 0);
		break;
	case 3:
		this->_dir = 0;
		player.MoveObject(0, 1);
		break;
	case 4:
		this->_dir = 0;
		player.MoveObject(-1, 0);
		break;
	default:
		break;
	}
	if (player.GetEnemyFlag())
	{
		int index = this->GetSmartEnemyInd(player.GetPosX(), player.GetPosY(), smartEnemies);
		this->_bettle.SmartBattle(player, smartEnemies[index]);
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
	for (size_t i = 0; i < smartEnemies.size(); i++)
	{
		if (smartEnemies[i])
		{
			smartEnemies[i]->SetBoard(player.GetBoard());
			int moveDir = rand() % 4 + 1;
			switch (moveDir)
			{
			case 1:
				smartEnemies[i]->MoveObject(0, -1);
				break;
			case 2:
				smartEnemies[i]->MoveObject(1, 0);
				break;
			case 3:
				smartEnemies[i]->MoveObject(0, 1);
				break;
			case 4:
				smartEnemies[i]->MoveObject(-1, 0);
				break;
			default:
				break;
			}
			player.SetBoard(smartEnemies[i]->GetBoard());
		}
	}

	this->_player = player;
	this->_smartEnemies = std::move(smartEnemies);
	this->_gameInv = tmpInv;
}


void MoveUnit::SetDir(const int value)
{
	this->_dir = value;
}

int MoveUnit::GetSmartEnemyInd(const int x, const int y, const std::vector<std::shared_ptr<Enemy>>& smartEnemies) const
{
	int index = 0;
	for (size_t i = 0; i < smartEnemies.size(); i++)
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
