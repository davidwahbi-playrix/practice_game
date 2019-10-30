#include "Game.h"
#include <Windows.h>
#include <iostream>

Game::Game()
{
	this->_isRunning = false;
	this->_draw = 0;
	this->_equip = false;
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
	int tmp = this->_eventHandler.HandleEvent();
	Player tmpPlayer = this->_profile.GetPlayer();
	switch (tmp)
	{
	case 1:
		system("cls");
		this->_unitMover.SetDir(1);
		this->_draw = true;
		break;
	case 2:
		system("cls");
		this->_unitMover.SetDir(2);
		this->_draw = true;
		break;
	case 3:
		system("cls");
		this->_unitMover.SetDir(3);
		this->_draw = true;
		break;
	case 4:
		system("cls");
		this->_unitMover.SetDir(4);
		this->_draw = true;
		break;
	case 5:
		if (this->_profile.GetPlayer().GetCanEquip())
		{
			system("cls");
			tmpPlayer.SetCanEquip(false);
			tmpPlayer.SetEquipInd(0);
			this->_profile.SetPlayer(tmpPlayer);
			this->_equip = true;
			this->_draw = true;
		}
		break;
	case 6:
		if (this->_profile.GetPlayer().GetCanEquip())
		{
			system("cls");
			tmpPlayer.SetCanEquip(false);
			tmpPlayer.SetEquipInd(1);
			this->_profile.SetPlayer(tmpPlayer);
			this->_equip = true;
			this->_draw = true;
		}
		break;
	case 7:
		if (this->_profile.GetPlayer().GetCanEquip())
		{
			system("cls");
			tmpPlayer.SetCanEquip(false);
			tmpPlayer.SetEquipInd(2);
			this->_profile.SetPlayer(tmpPlayer);
			this->_equip = true;
			this->_draw = true;
		}
		break;
	case 8:
		if (this->_profile.GetPlayer().GetCanEquip())
		{
			system("cls");
			tmpPlayer.SetCanEquip(false);
			tmpPlayer.SetEquipInd(3);
			this->_profile.SetPlayer(tmpPlayer);
			this->_equip = true;
			this->_draw = true;
		}
		break;
	case 9:
		if (this->_profile.GetPlayer().GetCanEquip())
		{
			system("cls");
			tmpPlayer.SetCanEquip(false);
			tmpPlayer.SetEquipInd(4);
			this->_profile.SetPlayer(tmpPlayer);
			this->_equip = true;
			this->_draw = true;
		}
		break;
	case 10:
		this->_saver.SaveGameState(this->_profile.GetPlayer(), this->_profile.GetEnemies(), this->_profile.GetGameItems());
		break;
	case 11:
		this->_loader.LoadGameState();
		this->_profile.SetPlayer(this->_loader.GetPlayer());
		this->_profile.SetEnemies(this->_loader.GetEnemies());
		this->_profile.SetGameItems(this->_loader.GetGameInventory());
		this->_profile.SetBoard(this->_loader.GetBoard());
		break;
	default:
		break;
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
	if (this->_equip)
	{
		this->_equip = false;
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
	if (_draw)
	{
		this->_draw = false;
		this->_renderer.SaveLoadMenu();
		this->_profile.SetBoard(this->_profile.GetPlayer().GetBoard());
		this->_profile.GetBoard().Display();
		if (this->_profile.GetPlayer().GetInventory().Size() > 0)
		{
			std::cout << "Player inventory:" << std::endl;
			std::cout << this->_profile.GetPlayer().GetInventory().toString() << '\n';
			std::cout << "Equip/Consume item using keys 0,1,2..." << '\n';
		}
		std::cout << this->_profile.GetPlayer().toString();
	}
}

void Game::Clean()
{
}

bool Game::Running() const
{
	return this->_isRunning;
}

bool Game::Draw() const
{
	return this->_draw;
} 
