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
	 _eventHandler.HandleEvent2(_unitMover, _renderer, _profile, _saver, _loader);
}

void Game::Update()
{
	if (_unitMover.GetDirection() > 0)
	{
		_unitMover.SmartUnitMove3(_profile.GetPlayer2(), _profile.GetSmartEnemies2(), _profile.GetGameItems2(), _profile.GetBoard2());
		SetRunning(_unitMover.GetContinue());
		if (!Running())
		{
			_renderer.SetDraw(false);
		}
	}
	if (_profile.GetPlayer2().GetEquipAction())
	{
		_profile.GetPlayer2().SetEquipAction(false);
		if (_profile.CanPlayerEquip())
		{
			_profile.GetPlayer2().EquipItem(_profile.GetPlayer().GetEquipInd());
		}
		else
		{
			if (_profile.GetPlayer().GetInventory().Size() > 0)
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
		_profile.GetBoard().Display2();
		if (_profile.GetPlayer().GetInventory().Size() > 0)
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

