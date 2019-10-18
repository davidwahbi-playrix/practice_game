#include "Game.h"
#include <Windows.h>
#include <iostream>

Game::Game()
{
	_isRunning = false;
	_dir = 0;
	_draw = 0;
	//_weapon = nullptr;
	//_armor = nullptr;
}

Game::~Game()
{
	//delete _weapon;
	//delete _armor;
}

void Game::Init()
{
	Board board;
	board.Load("Map.txt");
	Player newPlayer(1, 1, 100, 10, 0, "David", board);
	_player = newPlayer;
	Board plBoard = newPlayer.GetBoard();
	_board = plBoard;
	plBoard.Display();

	_gameItems.AddItem(Weapon("Sword", 0, 3, 5, 10));
	_gameItems.AddItem(Armor("Shield", 0, 1, 8, 20));

	_isRunning = true;
	// _weapon = new Weapon("Sword", 0, 3, 5, 10);
	// _armor = new Armor("Shield", 1, 1, 8, 20);
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
			this->UpdatePlayerInventory();
		}
		break;
	case 2:
		_player.MoveObject(1, 0);
		if (_player.GetPickedFlag()) {
			this->UpdatePlayerInventory();
		}
		break;
	case 3:
		_player.MoveObject(0, 1);
		if (_player.GetPickedFlag()) {
			this->UpdatePlayerInventory();
		}
		break;
	case 4:
		_player.MoveObject(-1, 0);
		if (_player.GetPickedFlag()) {
			this->UpdatePlayerInventory();
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
		if (_player.GetInventory().Size() > 0)
		{
			std::cout << _player.GetInventory().toString() << "\n";
		}
	}
}

void Game::Clean()
{
}

void Game::UpdatePlayerInventory()
{
	_player.SetPickedFlag(false);
	Inventory tmp = _player.GetInventory();
	int index = GetGameItemIndex(_player.GetPosX(), _player.GetPosY());
	if (index >= 0)
	{
		tmp.AddItem(_gameItems[index]);
		_player.SetInventory(tmp);
	}
}

unsigned int Game::GetGameItemIndex(const int x, const int y)
{
	int index = -1;
	for (size_t i = 0; i < this->_gameItems.Size(); i++)
	{
		if (_gameItems[i].GetPosX() == x && _gameItems[i].GetPosY() == y)
		{
			index = i;
		 }
	}
	return index;
}

bool Game::Running()
{
	return _isRunning;
}

bool Game::Draw()
{
	return _draw;
}
