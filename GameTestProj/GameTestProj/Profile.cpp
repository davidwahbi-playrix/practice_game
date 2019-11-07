#include "Profile.h"

Profile::Profile()
{
	this->_currentLevel = 1;
}

Profile::~Profile()
{
}

void Profile::NewGame()
{
	if (this->_currentLevel < 3)
	{
		this->_player = this->LoadPlayer();
	}
	//this->_player = this->LoadPlayer();
	this->_levelLoader.LoadLevel(this->_currentLevel);
	this->_board.InitBoard(this->_levelLoader.GetBoard().GetRowCount2(), this->_levelLoader.GetBoard().GetColCount2());
	this->SetBoard(this->_levelLoader.GetBoard());
	if (this->_currentLevel < 3) {
		this->SetGameItems(this->_levelLoader.GetGameItems());
		this->SetSmartEnemies(this->_levelLoader.GetSmartEnemies());
	}
	this->_board.Display2();
}

int Profile::GetLevel() const
{
	return this->_currentLevel;
}

Player Profile::GetPlayer() const
{
	return this->_player;
}

Inventory Profile::GetGameItems() const
{
	return this->_gameItems;
}

/*Inventory Profile::GetSmartGameItems() const
{
	return this->_smartGameItems;
}*/

Board Profile::GetBoard() const
{
	return this->_board;
}

std::vector<std::shared_ptr<Enemy>> Profile::GetSmartEnemies() const
{
	return this->_smartEnemies;
}

LevelLoader Profile::GetLevelLoader() const
{
	return this->_levelLoader;
}

void Profile::IncreseLevel()
{
	this->_currentLevel++;
}

void Profile::SetPlayer(const Player& player)
{
	this->_player = player;
}

void Profile::SetGameItems(const Inventory& inv)
{
	this->_gameItems = inv;
}

/*void Profile::SetSmartGameItems(const Inventory& inv)
{
	this->_smartGameItems = inv;
} */

void Profile::SetBoard(const Board& board)
{
	this->_board = board;
}

void Profile::SetSmartEnemies(const std::vector<std::shared_ptr<Enemy>> smartEnemies)
{
	this->_smartEnemies = smartEnemies;
}

Player Profile::LoadPlayer()
{
	Player newPlayer(1, 1, 100, 10, 0, this->_player.GetName());
	if (this->_currentLevel > 1)
	{
		newPlayer.SetHealth(this->_player.GetHealth());
		newPlayer.SetDamage(this->_player.GetDamage());
		newPlayer.SetDefence(this->_player.GetDefence());
		if (this->_player.GetWeapon())
		{
			newPlayer.SetWeapon(this->_player.GetWeapon());
		}
		if (this->_player.GetArmor())
		{
			newPlayer.SetArmor(this->_player.GetArmor());
		}
		newPlayer.SetInventory(this->_player.GetInventory());
		newPlayer.SetPickedFlag(this->_player.GetPickedFlag());
		newPlayer.SetEnemyFlag(this->_player.GetEnemyFlag());
		newPlayer.SetCanEquip(this->_player.GetCanEquip());
		newPlayer.SetEquipAction(this->_player.GetEquipAction());
		newPlayer.SetEquipInd(this->_player.GetEquipAction());
		newPlayer.SetStartDamage(this->_player.GetStartDamage());
	}
	return newPlayer;
}
