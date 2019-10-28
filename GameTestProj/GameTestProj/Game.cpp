#include "Game.h"
#include <Windows.h>
#include <iostream>

Game::Game()
{
	this->_isRunning = false;
	this->_dir = 0;
	this->_draw = 0;
	this->_equip = false;
	this->_equipInd = 0;
	this->_enemy = nullptr;
	this->_canEquip = false;
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
		this->_dir = 1;
		this->_draw = true;
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		system("cls");
		this->_dir = 3;
		this->_draw = true;
	}
	if (GetAsyncKeyState(VK_LEFT)) {
		system("cls");
		this->_dir = 4;
		this->_draw = true;
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		system("cls");
		this->_dir = 2;
		this->_draw = true;
	}
	if (GetAsyncKeyState(0x30))
	{
		if (this->_canEquip)
		{
			system("cls");
			this->_canEquip = false;
			this->_equipInd = 0;
			this->_equip = true;
			this->_draw = true;
		}
	}
	if (GetAsyncKeyState(0x31)) 
	{
		if (this->_canEquip)
		{
			system("cls");
			this->_canEquip = false;
			this->_equipInd = 1;
			this->_equip = true;
			this->_draw = true;
		}
	}
	if (GetAsyncKeyState(0x32))
	{
		if (this->_canEquip)
		{
			system("cls");
			this->_canEquip = false;
			this->_equipInd = 2;
			this->_equip = true;
			this->_draw = true;
		}
	}
	if (GetAsyncKeyState(0x33))
	{
		if (this->_canEquip)
		{
			system("cls");
			this->_canEquip = false;
			this->_equipInd = 3;
			this->_equip = true;
			this->_draw = true;
		}
	}
	if (GetAsyncKeyState(0x53))
	{
		SaveGame saveGame(this->_player, this->_enemy, this->_gameItems);
		saveGame.SaveGameState();
		//this->SaveGame();
	}
	if (GetAsyncKeyState(0x4C))
	{	
		LoadGame loadGame;
		loadGame.LoadGameState();
		//this->LoadGame();
		this->_player = loadGame.GetPlayer();
		this->_enemy = loadGame.GetEnemy();
		this->_gameItems = loadGame.GetGameInventory();
		this->_board = loadGame.GetBoard();
	}
}

void Game::Update()
{
	switch (this->_dir)
	{
	case 1:
		this->_dir = 0;
		this->_player.MoveObject(0, -1);
		if (this->_player.GetEnemyFlag())
		{
			Combat newCombat(this->_player, this->_enemy);
			newCombat.Battle();
			this->_player = newCombat.GetPlayer();
			this->_enemy = newCombat.GetEnemy();
		}
		if (this->_enemy)
		{
			this->_enemy->SetBoard(this->_player.GetBoard());
			this->_enemy->MoveObject(0, -1);
			this->_player.SetBoard(this->_enemy->GetBoard());
		}
		if (this->_player.GetPickedFlag())
		{
			this->UpdatePlayerInventory();
		}
		break;
	case 2:
		this->_dir = 0;
		this->_player.MoveObject(1, 0);
		if (this->_player.GetEnemyFlag())
		{
			Combat newCombat(this->_player, this->_enemy);
			newCombat.Battle();
			this->_player = newCombat.GetPlayer();
			this->_enemy = newCombat.GetEnemy();
		}
		if (this->_enemy)
		{
			this->_enemy->SetBoard(this->_player.GetBoard());
			this->_enemy->MoveObject(0, -1);
			this->_player.SetBoard(this->_enemy->GetBoard());
		}
		if (this->_player.GetPickedFlag()) {
			this->UpdatePlayerInventory();
		}	
		break;
	case 3:
		this->_dir = 0;
		this->_player.MoveObject(0, 1);
		if (this->_player.GetEnemyFlag())
		{
			Combat newCombat(this->_player, this->_enemy);
			newCombat.Battle();
			this->_player = newCombat.GetPlayer();
			this->_enemy = newCombat.GetEnemy();
		}
		if (this->_enemy)
		{
			this->_enemy->SetBoard(this->_player.GetBoard());
			this->_enemy->MoveObject(0, 1);
			this->_player.SetBoard(this->_enemy->GetBoard());
		}
		if (this->_player.GetPickedFlag()) {
			this->UpdatePlayerInventory();
		}
		break;
	case 4:
		this->_dir = 0;
		this->_player.MoveObject(-1, 0);
		if (this->_player.GetEnemyFlag())
		{
			Combat newCombat(this->_player, this->_enemy);
			newCombat.Battle();
			this->_player = newCombat.GetPlayer();
			this->_enemy = newCombat.GetEnemy();
		}
		if (this->_enemy)
		{
			this->_enemy->SetBoard(this->_player.GetBoard());
			this->_enemy->MoveObject(0, 1);
			this->_player.SetBoard(this->_enemy->GetBoard());
		}
		if (this->_player.GetPickedFlag()) {
			this->UpdatePlayerInventory();
		}
		break;
	default:
		break;
	}
	if (this->_equip)
	{
		this->_equip = false;
		if (this->_equipInd < this->_player.GetInventory().Size())
		{
			this->EquipItem(_equipInd);
		}
	}
}

void Game::Render()
{
	if (_draw)
	{
		this->_draw = false;
		this->_renderer.Render(this->_board, this->_player);
		if (_player.GetInventory().Size() > 0)
		{
			this->_canEquip = true;
		}
	}
}

void Game::Clean()
{
}

void Game::UpdatePlayerInventory()
{
	this->_player.SetPickedFlag(false);
	Inventory tmp = this->_player.GetInventory();
	int index = GetGameItemIndex(_player.GetPosX(), _player.GetPosY());
	if (index >= 0)
	{
		tmp.AddItem(_gameItems[index]);
		this->_player.SetInventory(tmp);
		this->_gameItems.RemoveItem(index);
		this->_canEquip = true;
	}
}

void Game::EquipItem(const int index)
{
	Weapon* tmp_w = dynamic_cast<Weapon*>(&this->_player.GetInventory().At(index));
	Armor* tmp_a = dynamic_cast<Armor*>(&this->_player.GetInventory().At(index));
	HealthPotion* tmp_p = dynamic_cast<HealthPotion*>(&this->_player.GetInventory().At(index));

	if (tmp_w) 
	{
		tmp_w = static_cast<Weapon*>(this->_player.GetInventory().Replace(index, this->_player.GetWeapon()));
		this->_player.SetWeapon(tmp_w);
		this->_player.AddDamage(tmp_w->GetDamageValue());
	}
	else if (tmp_a) 
	{
		tmp_a = static_cast<Armor*>(this->_player.GetInventory().Replace(index, this->_player.GetArmor()));
		this->_player.SetArmor(tmp_a);
		this->_player.AddDefence(tmp_a->GetArmorValue());
	}
	else if (tmp_p)
	{
		this->_player.AddHealth(tmp_p->GetHealthValue());
		this->_player.GetInventory().RemoveItem(index);
	}
}

unsigned int Game::GetGameItemIndex(const int x, const int y)
{
	int index = -1;
	for (size_t i = 0; i < this->_gameItems.Size(); i++)
	{
		if (this->_gameItems[i].GetPosX() == x && this->_gameItems[i].GetPosY() == y)
		{
			index = i;
		 }
	}
	return index;
}

bool Game::Running()
{
	return this->_isRunning;
}

bool Game::Draw()
{
	return this->_draw;
}
