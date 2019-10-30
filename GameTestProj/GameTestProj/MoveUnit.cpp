#include "MoveUnit.h"

MoveUnit::MoveUnit()
{
	this->_dir = 0;
	this->_enemy = nullptr;
}

MoveUnit::~MoveUnit()
{
	
}

void MoveUnit::UnitMove(Player player, Enemy* enemy, Inventory gameInv)
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
		this->_bettle.Battle(player, enemy);
		player = this->_bettle.GetPlayer();
		enemy = this->_bettle.GetEnemy();
	}
	if (player.GetPickedFlag())
	{
		tmpInv = player.UpdatePlayerInventory(gameInv);
	}
	else
	{
		tmpInv = gameInv;
	}
	if (enemy)
	{
		enemy->SetBoard(player.GetBoard());
		int moveDir = rand() % 4 + 1;
		switch (moveDir)
		{
		case 1:
			enemy->MoveObject(0, -1);
			break;
		case 2:
			enemy->MoveObject(1, 0);
			break;
		case 3:
			enemy->MoveObject(0, 1);
			break;
		case 4:
			enemy->MoveObject(-1, 0);
			break;
		default:
			break;
		}
		player.SetBoard(enemy->GetBoard());
	}

	this->_player = player;
	this->_enemy = enemy;
	this->_gameInv = tmpInv;
}

void MoveUnit::UnitMove(Player player, std::vector<Enemy*> enemies, Inventory gameInv)
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
		int index = this->GetEnemyInd(player.GetPosX(), player.GetPosY(), enemies);
		this->_bettle.Battle(player, enemies[index]);
		player = this->_bettle.GetPlayer();
		enemies[index] = this->_bettle.GetEnemy();
		if (enemies[index] == nullptr)
		{
			enemies.erase(enemies.begin() + index);
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
	for (size_t i = 0; i < enemies.size(); i++)
	{
		if (enemies[i])
		{
			enemies[i]->SetBoard(player.GetBoard());
			int moveDir = rand() % 4 + 1;
			switch (moveDir)
			{
			case 1:
				enemies[i]->MoveObject(0, -1);
				break;
			case 2:
				enemies[i]->MoveObject(1, 0);
				break;
			case 3:
				enemies[i]->MoveObject(0, 1);
				break;
			case 4:
				enemies[i]->MoveObject(-1, 0);
				break;
			default:
				break;
			}
			player.SetBoard(enemies[i]->GetBoard());
		}
	}

	this->_player = player;
	this->_enemies = enemies;
	this->_gameInv = tmpInv;
}


void MoveUnit::SetDir(const int value)
{
	this->_dir = value;
}

int MoveUnit::GetEnemyInd(const int x, const int y, std::vector<Enemy*> enemies) const
{
	int index = 0;
	for (size_t i = 0; i < enemies.size(); i++)
	{
		if (enemies[i]->GetPosX() == x && enemies[i]->GetPosY() == y)
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

Enemy* MoveUnit::GetEnemy() const
{
	return this->_enemy;
}

Inventory MoveUnit::GetGameInv() const
{
	return this->_gameInv;
}

std::vector<Enemy*> MoveUnit::GetEnemies() const
{
	return this->_enemies;
}
