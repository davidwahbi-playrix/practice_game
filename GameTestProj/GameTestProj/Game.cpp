#include "Game.h"
#include <Windows.h>

Game::Game()
{
	_isRunning = false;
	_dir = 0;
	_draw = 0;
}

Game::~Game()
{
}

void Game::Init()
{
	Board board;
	board.Load("Map.txt");
	Player newPlayer(1, 1, 100, 10, "David2", board);
	_player = newPlayer;
	Board plBoard = newPlayer.GetBoard();
	_board = plBoard;
	plBoard.Display();
	// Item tmp("Shield", 1, 3, 5);
	//_item = tmp;
	_isRunning = true;
}

void Game::HandleEvents()
{
	if (GetAsyncKeyState(VK_UP)) {
		system("cls");
		_dir = 1;
		_draw = true;
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		system("cls");
		_dir = 3;
		_draw = true;
	}
	if (GetAsyncKeyState(VK_LEFT)) {
		system("cls");
		_dir = 4;
		_draw = true;
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		system("cls");
		_dir = 2;
		_draw = true;
	}
}

void Game::Update()
{
	switch (_dir)
	{
	case 1:
		_player.MoveObject(0, -1);
		if (_player.GetPickedFlag()) {
			_player.SetPickedFlag(false);
			Inventory temp_inv = _player.GetInventory();
			temp_inv.AddItem(Item("Shield",1,3,5));
			_player.SetInventory(temp_inv);
		}
		break;
	case 2:
		_player.MoveObject(1, 0);
		if (_player.GetPickedFlag()) {
			_player.SetPickedFlag(false);
			_player.GetInventory().AddItem(Item("Shield", 1, 3, 5));
		}
		break;
	case 3:
		_player.MoveObject(0, 1);
		if (_player.GetPickedFlag()) {
			_player.SetPickedFlag(false);
			_player.GetInventory().AddItem(Item("Shield", 1, 3, 5));
		}
		break;
	case 4:
		_player.MoveObject(-1, 0);
		if (_player.GetPickedFlag()) {
			_player.SetPickedFlag(false);
			_player.GetInventory().AddItem(Item("Shield", 1, 3, 5));
		}
		break;
	default:
		break;
	}
}

void Game::Render()
{
	if (_draw)
	{
		_draw = false;
		_board = _player.GetBoard();
		_board.Display();
		_player.GetInventory().toString();
	}
}

void Game::Clean()
{
}

bool Game::Running()
{
	return _isRunning;
}

bool Game::Draw()
{
	return _draw;
}
