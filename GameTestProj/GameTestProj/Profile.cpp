#include "Profile.h"

Profile::Profile()
{
	_currentLevel = 1;
}

Profile::~Profile()
{
}

void Profile::NewGame(bool &running)
{
	if (_currentLevel == FIRSTLEVEL)
	{
		_levelLoader.LoadPlayer(_player);
	}
	else
	{
		if (_currentLevel < MAXLEVEL)
		{
			_levelLoader.SetPlayerStartPos(_currentLevel, _player);
		}
	}
	_levelLoader.LoadLevel2(_currentLevel, running, _board, _gameItems, _smartEnemies);

	if (_currentLevel == FIRSTLEVEL || _currentLevel == VICTORY || _currentLevel == GAMEOVER)
	{
		_board.Display2();
	}
}

int Profile::GetLevel() const
{
	return _currentLevel;
}

int& Profile::GetLevel2()
{
	return _currentLevel;
}

void Profile::SetLevel(const int level)
{
	_currentLevel = level;
}

void Profile::GameOver(bool& running)
{
	_currentLevel = 99;
	NewGame(running);
}

bool Profile::CanPlayerEquip() const
{
	return (GetPlayer().GetEquipInd() < GetPlayer().GetInventory().Size());
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
