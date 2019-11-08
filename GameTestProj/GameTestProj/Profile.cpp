#include "Profile.h"

Profile::Profile()
{
	_currentLevel = 1;
}

Profile::~Profile()
{
}

void Profile::NewGame()
{
	if (_currentLevel < 3)
	{
		_player = LoadPlayer();
	}
	//_player = LoadPlayer();
	_levelLoader.LoadLevel(_currentLevel);
	_board.InitBoard(_levelLoader.GetBoard().GetRowCount2(), _levelLoader.GetBoard().GetColCount2());
	SetBoard(_levelLoader.GetBoard());
	if (_currentLevel < 3) {
		SetGameItems(_levelLoader.GetGameItems());
		SetSmartEnemies(_levelLoader.GetSmartEnemies());
	}
	_board.Display2();
}

int Profile::GetLevel() const
{
	return _currentLevel;
}

Player Profile::GetPlayer() const
{
	return _player;
}

Player & Profile::GetPlayer2()
{
	return _player;
}

Inventory Profile::GetGameItems() const
{
	return _gameItems;
}

Inventory & Profile::GetGameItems2()
{
	return _gameItems;
}

/*Inventory Profile::GetSmartGameItems() const
{
	return _smartGameItems;
}*/

Board Profile::GetBoard() const
{
	return _board;
}

Board & Profile::GetBoard2()
{
	return _board;
}

std::vector<std::shared_ptr<Enemy>> Profile::GetSmartEnemies() const
{
	return _smartEnemies;
}

std::vector<std::shared_ptr<Enemy>>& Profile::GetSmartEnemies2()
{
	return _smartEnemies;
}

LevelLoader Profile::GetLevelLoader() const
{
	return _levelLoader;
}

void Profile::IncreseLevel()
{
	_currentLevel++;
}

void Profile::SetPlayer(const Player& player)
{
	_player = player;
}

void Profile::SetGameItems(const Inventory& inv)
{
	_gameItems = inv;
}

/*void Profile::SetSmartGameItems(const Inventory& inv)
{
	_smartGameItems = inv;
} */

void Profile::SetBoard(const Board& board)
{
	_board = board;
}

void Profile::SetSmartEnemies(const std::vector<std::shared_ptr<Enemy>> smartEnemies)
{
	_smartEnemies = smartEnemies;
}

Player Profile::LoadPlayer()
{
	Player newPlayer(1, 1, 100, 10, 0, _player.GetName());
	if (_currentLevel > 1)
	{
		newPlayer.SetHealth(_player.GetHealth());
		newPlayer.SetDamage(_player.GetDamage());
		newPlayer.SetDefence(_player.GetDefence());
		if (_player.GetWeapon())
		{
			newPlayer.SetWeapon(_player.GetWeapon());
		}
		if (_player.GetArmor())
		{
			newPlayer.SetArmor(_player.GetArmor());
		}
		newPlayer.SetInventory(_player.GetInventory());
		newPlayer.SetPickedFlag(_player.GetPickedFlag());
		newPlayer.SetEnemyFlag(_player.GetEnemyFlag());
		newPlayer.SetCanEquip(_player.GetCanEquip());
		newPlayer.SetEquipAction(_player.GetEquipAction());
		newPlayer.SetEquipInd(_player.GetEquipAction());
		newPlayer.SetStartDamage(_player.GetStartDamage());
	}
	return newPlayer;
}
