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
	switch (this->_dir)
	{
	case 1:
		this->_dir = 0;
		player.MoveObject(0, -1);
		if (player.GetEnemyFlag())
		{
			this->_bettle.Battle(player, enemy);
			player = this->_bettle.GetPlayer();
			enemy = this->_bettle.GetEnemy();
		}
		if (enemy)
		{
			enemy->SetBoard(player.GetBoard());
			enemy->MoveObject(0, -1);
			player.SetBoard(enemy->GetBoard());
		}
		if (player.GetPickedFlag())
		{
			player.UpdatePlayerInventory(gameInv);
		}
		break;
	case 2:
		this->_dir = 0;
		player.MoveObject(1, 0);
		if (player.GetEnemyFlag())
		{
			this->_bettle.Battle(player, enemy);
			player = this->_bettle.GetPlayer();
			enemy = this->_bettle.GetEnemy();
		}
		if (enemy)
		{
			enemy->SetBoard(player.GetBoard());
			enemy->MoveObject(0, -1);
			player.SetBoard(enemy->GetBoard());
		}
		if (player.GetPickedFlag())
		{
			player.UpdatePlayerInventory(gameInv);
		}
		break;
	case 3:
		this->_dir = 0;
		player.MoveObject(0, 1);
		if (player.GetEnemyFlag())
		{
			this->_bettle.Battle(player, enemy);
			player = this->_bettle.GetPlayer();
			enemy = this->_bettle.GetEnemy();
		}
		if (enemy)
		{
			enemy->SetBoard(player.GetBoard());
			enemy->MoveObject(0, 1);
			player.SetBoard(enemy->GetBoard());
		}
		if (player.GetPickedFlag())
		{
			player.UpdatePlayerInventory(gameInv);
		}
		break;
	case 4:
		this->_dir = 0;
		player.MoveObject(-1, 0);
		if (player.GetEnemyFlag())
		{
			this->_bettle.Battle(player, enemy);
			player = this->_bettle.GetPlayer();
			enemy = this->_bettle.GetEnemy();
		}
		if (enemy)
		{
			enemy->SetBoard(player.GetBoard());
			enemy->MoveObject(0, 1);
			player.SetBoard(enemy->GetBoard());
		}
		if (player.GetPickedFlag())
		{
			player.UpdatePlayerInventory(gameInv);
		}
		break;
	default:
		break;
	}

	this->_player = player;
	this->_enemy = enemy;
}

void MoveUnit::SetDir(const int value)
{
	this->_dir = value;
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
