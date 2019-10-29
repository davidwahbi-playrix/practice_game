#pragma once
#include <Windows.h>
#include "LoadGame.h"
#include "SaveGame.h"
class EventHandler
{
public:
	EventHandler();
	~EventHandler();
	int HandleEvent();
	//int HandleEvent(Player player, Enemy* enemy, Inventory gameInv, Board board);

	//Player GetPlayer() const;
	//Enemy* GetEnemy() const;
	//Inventory GetInv() const;
	//Board GetBoard() const;
private:
	//LoadGame _loader;
	//SaveGame _saver;
	//Player _player;
	//Enemy* _enemy;
	//Inventory _gameInv;
	//Board _board;
};

