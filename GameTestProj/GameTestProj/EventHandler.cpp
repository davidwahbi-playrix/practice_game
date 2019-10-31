#include "EventHandler.h"

EventHandler::EventHandler()
{
}

EventHandler::~EventHandler()
{
}

int EventHandler::HandleEvent()
{
	int tmp = 100;
	if (GetAsyncKeyState(VK_UP))
	{
		tmp = 1;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		tmp = 3;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		tmp = 4;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		tmp = 2;
	}
	if (GetAsyncKeyState(0x30))
	{
		tmp = 5;
	}
	if (GetAsyncKeyState(0x31))
	{
		tmp = 6;
	}
	if (GetAsyncKeyState(0x32))
	{
		tmp = 7;
	}
	if (GetAsyncKeyState(0x33))
	{
		tmp = 8;
	}
	if (GetAsyncKeyState(0x34))
	{
		tmp = 9;
	}
	if (GetAsyncKeyState(0x53))
	{
		//this->_saver.SaveGameState(player, enemy, gameInv);
		tmp = 10;
	}
	if (GetAsyncKeyState(0x4C))
	{
		/*this->_loader.LoadGameState();
		this->_player = this->_loader.GetPlayer();
		this->_enemy = this->_loader.GetEnemy();
		this->_gameInv= this->_loader.GetGameInventory();
		this->_board = this->_loader.GetBoard(); */
		tmp = 11;
	}
	return tmp;
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
		
