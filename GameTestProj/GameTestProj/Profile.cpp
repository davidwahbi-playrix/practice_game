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
		_levelLoader.LoadPlayer2(_smartPlayer);
	}
	else
	{
		if (_currentLevel < MAXLEVEL)
		{
			_levelLoader.SetPlayerStartPos2(_currentLevel, _smartPlayer);
		}
	}
	_levelLoader.LoadLevel3(_currentLevel, running, _board, _smartGameItems, _smartEnemies);

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
	return (GetSmartPlayer2().GetEquipInd() < GetSmartPlayer2().GetSmartInventory2().Size());
}

SmartPlayer & Profile::GetSmartPlayer2()
{
	return _smartPlayer;
}

SmartPlayer Profile::GetSmartPlayer2() const
{
	return _smartPlayer;
}

SmartInventory& Profile::GetSmartGameItems()
{
	return _smartGameItems;
}

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
