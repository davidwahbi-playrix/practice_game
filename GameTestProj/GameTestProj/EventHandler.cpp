#include "EventHandler.h"

EventHandler::EventHandler()
{
}

EventHandler::~EventHandler()
{
}

int EventHandler::HandleEvent()
{
	if (GetAsyncKeyState(VK_UP))
	{
		return 1;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		return 3;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		return 4;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		return 2;
	}
	if (GetAsyncKeyState(0x30))
	{
		return 5;
	}
	if (GetAsyncKeyState(0x31))
	{
		return 6;
	}
	if (GetAsyncKeyState(0x32))
	{
		return 7;
	}
	if (GetAsyncKeyState(0x33))
	{
		return 8;
	}
	if (GetAsyncKeyState(0x34))
	{
		return 9;
	}
	if (GetAsyncKeyState(0x53))
	{
		//this->_saver.SaveGameState(player, enemy, gameInv);
		return 10;
	}
	if (GetAsyncKeyState(0x4C))
	{
		/*this->_loader.LoadGameState();
		this->_player = this->_loader.GetPlayer();
		this->_enemy = this->_loader.GetEnemy();
		this->_gameInv= this->_loader.GetGameInventory();
		this->_board = this->_loader.GetBoard(); */
		return 11;
	}
}

/*Player EventHandler::GetPlayer() const
{
	return this->_player;
}

Enemy* EventHandler::GetEnemy() const
{
	return this->_enemy;
}

Inventory EventHandler::GetInv() const
{
	return this->_gameInv;
}

Board EventHandler::GetBoard() const
{
	return this->_board;
}*/
		
