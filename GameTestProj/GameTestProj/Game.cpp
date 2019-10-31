#include "Game.h"
#include <Windows.h>
#include <iostream>

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
		system("cls");
		this->_unitMover.SetDir(tmpInput);
		this->_renderer.SetDraw(true);
	}
	else if (tmpInput > 4 && tmpInput < 10)
	{
		if (this->_profile.GetPlayer().GetCanEquip())
		{
			system("cls");
			tmpPlayer.SetCanEquip(false);
			tmpPlayer.SetEquipInd(tmpInput - 5);
			tmpPlayer.SetEquipAction(true);
			this->_profile.SetPlayer(tmpPlayer);
			this->_renderer.SetDraw(true);
		}

	}
	else if (tmpInput == 10)
	{
		this->_saver.SaveGameState(this->_profile.GetPlayer(), this->_profile.GetEnemies(), this->_profile.GetGameItems());
	}
	else if (tmpInput == 11)
	{
		this->_loader.LoadGameState();
		this->_profile.SetPlayer(this->_loader.GetPlayer());
		this->_profile.SetEnemies(this->_loader.GetEnemies());
		this->_profile.SetGameItems(this->_loader.GetGameInventory());
		this->_profile.SetBoard(this->_loader.GetBoard());
	}
}

void Game::Update()
{
	if (_unitMover.GetDirection() > 0)
	{
		this->_unitMover.UnitMove(this->_profile.GetPlayer(), this->_profile.GetEnemies(), this->_profile.GetGameItems());
		this->_profile.SetPlayer(this->_unitMover.GetPlayer());
		this->_profile.SetEnemies(this->_unitMover.GetEnemies());
		this->_profile.SetGameItems(this->_unitMover.GetGameInv());
	}
	Player tmpPlayer = this->_profile.GetPlayer();

	if (tmpPlayer.GetEquipAction())
	{
		tmpPlayer.SetEquipAction(false);
		this->_profile.SetPlayer(tmpPlayer);
		if (this->_profile.GetPlayer().GetEquipInd() < this->_profile.GetPlayer().GetInventory().Size())
		{
			Player tmpPlayer = this->_profile.GetPlayer();
			tmpPlayer.EquipItem(_profile.GetPlayer().GetEquipInd());
			this->_profile.SetPlayer(tmpPlayer);
		}
		else
		{
			if (this->_profile.GetPlayer().GetInventory().Size() > 0)
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
		this->_profile.SetBoard(this->_profile.GetPlayer().GetBoard());
		this->_profile.GetBoard().Display();
		if (this->_profile.GetPlayer().GetInventory().Size() > 0)
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
Renderer Game::GetRenderer() const
{
	return this->_renderer;
}

