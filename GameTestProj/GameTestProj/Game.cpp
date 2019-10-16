#include "Game.h"
#include <Windows.h>

Game::Game()
{
	_isRunning = false;
	_dir = 0;
	_draw = 0;
	_item = nullptr;
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
	_item = new Item("Shield", 1);
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
		break;
	case 2:
		_player.MoveObject(1, 0);
		break;
	case 3:
		_player.MoveObject(0, 1);
		break;
	case 4:
		_player.MoveObject(-1, 0);
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
