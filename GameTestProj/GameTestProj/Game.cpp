#include "Game.h"
#include <Windows.h>
#include <iostream>

Game::Game()
{
	this->_isRunning = false;
	this->_draw = 0;
	this->_equip = false;
	this->_enemy = nullptr;
}

Game::~Game()
{
	delete this->_enemy;
	this->_enemy = nullptr;
}

void Game::Init()
{	
	Board board;
	board.Load("Map.txt");
	Player newPlayer(1, 1, 100, 10, 0, "David", board);
	_enemy = new Enemy(2, 12, 50, 5, board, 100);
	this->_player = newPlayer;
	Board plBoard = newPlayer.GetBoard();
	this->_board = plBoard;
	this->_renderer.SaveLoadMenu();
	plBoard.Display();

	this->_gameItems.AddItem(Weapon("Sword",WEAPON, 3, 5, 10));
	this->_gameItems.AddItem(Armor("Shield",ARMOR, 1, 8, 20));
	this->_gameItems.AddItem(HealthPotion("Heal", HEAL, 4, 2, 50));

	this->_isRunning = true;
}

void Game::HandleEvents()
{
	if (GetAsyncKeyState(VK_UP)) {
		system("cls");
		this->_unitMover.SetDir(1);
		this->_draw = true;
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		system("cls");
		this->_unitMover.SetDir(3);
		this->_draw = true;
	}
	if (GetAsyncKeyState(VK_LEFT)) {
		system("cls");
		this->_unitMover.SetDir(4);
		this->_draw = true;
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		system("cls");
		this->_unitMover.SetDir(2);
		this->_draw = true;
	}
	if (GetAsyncKeyState(0x30))
	{
		if (this->_player.GetCanEquip())
		{
			system("cls");
			this->_player.SetCanEquip(false);
			this->_player.SetEquipInd(0);
			this->_equip = true;
			this->_draw = true;
		}
	}
	if (GetAsyncKeyState(0x31)) 
	{
		if (this->_player.GetCanEquip())
		{
			system("cls");
			this->_player.SetCanEquip(false);
			this->_player.SetEquipInd(1);
			this->_equip = true;
			this->_draw = true;
		}
	}
	if (GetAsyncKeyState(0x32))
	{
		if (this->_player.GetCanEquip())
		{
			system("cls");
			this->_player.SetCanEquip(false);
			this->_player.SetEquipInd(2);
			this->_equip = true;
			this->_draw = true;
		}
	}
	if (GetAsyncKeyState(0x33))
	{
		if (this->_player.GetCanEquip())
		{
			system("cls");
			this->_player.SetCanEquip(false);
			this->_player.SetEquipInd(3);
			this->_equip = true;
			this->_draw = true;
		}
	}
	if (GetAsyncKeyState(0x53))
	{
		SaveGame saveGame(this->_player, this->_enemy, this->_gameItems);
		saveGame.SaveGameState();
	}
	if (GetAsyncKeyState(0x4C))
	{	
		LoadGame loadGame;
		loadGame.LoadGameState();
		this->_player = loadGame.GetPlayer();
		this->_enemy = loadGame.GetEnemy();
		this->_gameItems = loadGame.GetGameInventory();
		this->_board = loadGame.GetBoard();
	}
}

void Game::Update()
{
	if (_unitMover.GetDirection() > 0)
	{
		this->_unitMover.UnitMove(this->_player, this->_enemy, this->_gameItems);
		this->_player = this->_unitMover.GetPlayer();
		this->_enemy = this->_unitMover.GetEnemy();
	}
	if (this->_equip)
	{
		this->_equip = false;
		if (this->_player.GetEquipInd() < this->_player.GetInventory().Size())
		{
			this->_player.EquipItem(_player.GetEquipInd());
		}
	}
}


void Game::Render()
{
	if (_draw)
	{
		this->_draw = false;
		this->_renderer.SaveLoadMenu();
		this->_board = this->_player.GetBoard();
		this->_board.Display();
		if (this->_player.GetInventory().Size() > 0)
		{
			std::cout << "Player inventory:" << std::endl;
			std::cout << this->_player.GetInventory().toString() << '\n';
			std::cout << "Equip/Consume item using keys 0,1,2..." << '\n';
		}
		std::cout << this->_player.toString();
	}
}

void Game::Clean()
{
}

bool Game::Running()
{
	return this->_isRunning;
}

bool Game::Draw()
{
	return this->_draw;
}
