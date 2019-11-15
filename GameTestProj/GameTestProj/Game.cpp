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
	_profile.NewGame(_isRunning);
	_isRunning = true;
}

void Game::HandleEvents()
{
	_eventHandler.HandleEvent2(_unitMover, _renderer, _profile, _saver, _loader);
}

void Game::Update()
{
	if (_unitMover.GetDirection() > 0)
	{
		_unitMover.SmartUnitMove4(_profile.GetSmartPlayer2(), _profile.GetSmartEnemies2(), _profile.GetSmartGameItems(), _profile.GetBoard2(), _isRunning);
		if (!Running())
		{
			_renderer.SetDraw(false);
			_profile.GameOver(_isRunning);
		}
	}
	if (_profile.GetSmartPlayer2().GetEquipAction())
	{
		_profile.GetSmartPlayer2().SetEquipAction(false);
		if (_profile.CanPlayerEquip())
		{
			_profile.GetSmartPlayer2().EquipSmartItem(_profile.GetSmartPlayer2().GetEquipInd());
		}
		else
		{
			if (_profile.GetSmartPlayer2().GetSmartInventory().Size() > 0)
			{
				_profile.GetSmartPlayer2().SetCanEquip(true);
			}
		}
	}
}

void Game::Render()
{
	_renderer.Render(_profile, _isRunning);
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

