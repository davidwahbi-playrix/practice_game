#include "Game.h"

Game::Game()
{
	_isRunning = false;
}

Game::~Game()
{
}

void Game::Init()
{	
	_renderer.SaveLoadMenu();
	_profile.NewGame();
	_isRunning = true;
}

void Game::HandleEvents()
{
	int tmpInput = _eventHandler.HandleEvent();
	if (tmpInput < 5)
	{
		_renderer.ClearView();
		_unitMover.SetDir(tmpInput);
		_renderer.SetDraw(true);
	}
	else if (tmpInput > 4 && tmpInput < 10)
	{
		if (_profile.GetPlayer().GetCanEquip())
		{
			_renderer.ClearView();
			_profile.GetPlayer2().SetCanEquip(false);
			_profile.GetPlayer2().SetEquipInd(tmpInput - 5);
			_profile.GetPlayer2().SetEquipAction(true);
			_renderer.SetDraw(true);
		}

	}
	else if (tmpInput == 10)
	{
		_saver.SaveSmartGameState(_profile.GetLevel(), _profile.GetPlayer(), _profile.GetSmartEnemies(), _profile.GetGameItems());
		//_saver.SaveSmartGameState(_profile.GetPlayer(), _profile.GetSmartEnemies(), _profile.GetSmartGameItems());
	}
	else if (tmpInput == 11)
	{
		_loader.LoadSmartGameState();
		_profile.SetPlayer(_loader.GetPlayer());
		_profile.SetSmartEnemies(_loader.GetSmartEnemies());
		_profile.SetGameItems(_loader.GetGameInventory());
		//_profile.SetSmartGameItems(_loader.GetGameInventory());
		_profile.SetBoard(_loader.GetBoard());
	}
}

void Game::Update()
{
	if (_unitMover.GetDirection() > 0)
	{
		_unitMover.SmartUnitMove3(_profile.GetPlayer2(), _profile.GetSmartEnemies2(), _profile.GetGameItems2(), _profile.GetBoard2());
		//_unitMover.SmartUnitMove(_profile.GetPlayer(), _profile.GetSmartEnemies(), _profile.GetSmartGameItems());
		SetRunning(_unitMover.GetContinue());
		if (!Running())
		{
			_renderer.SetDraw(false);
		}
	}
	if (_profile.GetPlayer2().GetEquipAction())
	{
		_profile.GetPlayer2().SetEquipAction(false);
		if (_profile.GetPlayer().GetEquipInd() < _profile.GetPlayer().GetInventory().Size())
		//if (_profile.GetPlayer().GetEquipInd() < _profile.GetPlayer().GetSmartInventory().Size())
		{
			_profile.GetPlayer2().EquipItem(_profile.GetPlayer().GetEquipInd());

		}
		else
		{
			if (_profile.GetPlayer().GetInventory().Size() > 0)
			//if (_profile.GetPlayer().GetSmartInventory().Size() > 0)
			{
				_profile.GetPlayer2().SetCanEquip(true);
			}
		}
	}
}


void Game::Render()
{

	if (_renderer.GetDraw())
	{
		_renderer.SetDraw(false);
		_renderer.SaveLoadMenu();
		//_profile.SetBoard(_profile.GetPlayer().GetBoard());
		_profile.GetBoard().Display2();
		if (_profile.GetPlayer().GetInventory().Size() > 0)
		//if (_profile.GetPlayer().GetSmartInventory().Size() > 0)
		{
			_renderer.RenderPlayerInventory(_profile.GetPlayer());
		}
		_renderer.RenderPlayer(_profile.GetPlayer());
		if (_profile.GetSmartEnemies().size() == 0)
		{
			_profile.IncreseLevel();
			_renderer.NextLevel(_profile.GetLevel());
			_profile.NewGame();
		}
		SetRunning(_profile.GetLevelLoader().GetFinishStatus());
		if (!Running())
		{
			_renderer.SetDraw(false);
		}
	}
}

void Game::Clean()
{
}

bool Game::Running() const
{
	return _isRunning;
}
void Game::SetRunning(const bool & value)
{
	_isRunning = value;
}
Renderer Game::GetRenderer() const
{
	return _renderer;
}

