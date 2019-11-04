#include "Game.h"

Game::Game()
{
	this->_isRunning = false;
}

Game::~Game()
{
}

void Game::Init()
{	
	this->_renderer.SaveLoadMenu();
	this->_profile.NewGame();
	this->_isRunning = true;
}

void Game::HandleEvents()
{
	int tmpInput = this->_eventHandler.HandleEvent();
	Player tmpPlayer = this->_profile.GetPlayer();
	if (tmpInput < 5)
	{
		this->_renderer.ClearView();
		this->_unitMover.SetDir(tmpInput);
		this->_renderer.SetDraw(true);
	}
	else if (tmpInput > 4 && tmpInput < 10)
	{
		if (this->_profile.GetPlayer().GetCanEquip())
		{
			this->_renderer.ClearView();
			tmpPlayer.SetCanEquip(false);
			tmpPlayer.SetEquipInd(tmpInput - 5);
			tmpPlayer.SetEquipAction(true);
			this->_profile.SetPlayer(tmpPlayer);
			this->_renderer.SetDraw(true);
		}

	}
	else if (tmpInput == 10)
	{
		this->_saver.SaveSmartGameState(this->_profile.GetPlayer(), this->_profile.GetSmartEnemies(), this->_profile.GetGameItems());
		//this->_saver.SaveSmartGameState(this->_profile.GetPlayer(), this->_profile.GetSmartEnemies(), this->_profile.GetSmartGameItems());
	}
	else if (tmpInput == 11)
	{
		this->_loader.LoadSmartGameState();
		this->_profile.SetPlayer(this->_loader.GetPlayer());
		this->_profile.SetSmartEnemies(this->_loader.GetSmartEnemies());
		this->_profile.SetGameItems(this->_loader.GetGameInventory());
		//this->_profile.SetSmartGameItems(this->_loader.GetGameInventory());
		this->_profile.SetBoard(this->_loader.GetBoard());
	}
}

void Game::Update()
{
	if (_unitMover.GetDirection() > 0)
	{
		this->_profile.SetBoard(this->_unitMover.SmartUnitMove2(this->_profile.GetPlayer(), this->_profile.GetSmartEnemies(), this->_profile.GetGameItems(), this->_profile.GetBoard()));
		//this->_unitMover.SmartUnitMove(this->_profile.GetPlayer(), this->_profile.GetSmartEnemies(), this->_profile.GetSmartGameItems());
		this->SetRunning(_unitMover.GetContinue());
		if (!this->Running())
		{
			this->_renderer.SetDraw(false);
		}
		this->_profile.SetPlayer(this->_unitMover.GetPlayer());
		this->_profile.SetSmartEnemies(this->_unitMover.GetSmartEnemies());
		this->_profile.SetGameItems(this->_unitMover.GetGameInv());
		//this->_profile.SetSmartGameItems(this->_unitMover.GetGameInv());
	}
	Player tmpPlayer = this->_profile.GetPlayer();

	if (tmpPlayer.GetEquipAction())
	{
		tmpPlayer.SetEquipAction(false);
		this->_profile.SetPlayer(tmpPlayer);
		if (this->_profile.GetPlayer().GetEquipInd() < this->_profile.GetPlayer().GetInventory().Size())
		//if (this->_profile.GetPlayer().GetEquipInd() < this->_profile.GetPlayer().GetSmartInventory().Size())
		{
			Player tmpPlayer = this->_profile.GetPlayer();
			tmpPlayer.EquipItem(_profile.GetPlayer().GetEquipInd());
			this->_profile.SetPlayer(tmpPlayer);
		}
		else
		{
			if (this->_profile.GetPlayer().GetInventory().Size() > 0)
			//if (this->_profile.GetPlayer().GetSmartInventory().Size() > 0)
			{
				Player tmpPlayer = this->_profile.GetPlayer();
				tmpPlayer.SetCanEquip(true);
				this->_profile.SetPlayer(tmpPlayer);
			}
		}
	}
}


void Game::Render()
{

	if (this->_renderer.GetDraw())
	{
		this->_renderer.SetDraw(false);
		this->_renderer.SaveLoadMenu();
		//this->_profile.SetBoard(this->_profile.GetPlayer().GetBoard());
		this->_profile.GetBoard().Display();
		if (this->_profile.GetPlayer().GetInventory().Size() > 0)
		//if (this->_profile.GetPlayer().GetSmartInventory().Size() > 0)
		{
			this->_renderer.RenderPlayerInventory(this->_profile.GetPlayer());
		}
		this->_renderer.RenderPlayer(this->_profile.GetPlayer());
	}
}

void Game::Clean()
{
}

bool Game::Running() const
{
	return this->_isRunning;
}
void Game::SetRunning(const bool & value)
{
	this->_isRunning = value;
}
Renderer Game::GetRenderer() const
{
	return this->_renderer;
}

