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
	std::cout << "s -> Save game." << '\n';
	std::cout << '\n';
	plBoard.Display();

	_gameItems.AddItem(Weapon("Sword",WEAPON, 3, 5, 10));
	_gameItems.AddItem(Armor("Shield",ARMOR, 1, 8, 20));
	_gameItems.AddItem(HealthPotion("Heal", HEAL, 4, 2, 50));

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
		this->SaveGame();
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
			this->Battle();
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
			this->Battle();
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
			this->Battle();
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
			this->Battle();
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
		this->EquipItem(_equipInd);
	}
}

void Game::Render()
{
	if (_draw) 
	{
		std::cout << "s -> Save game." << '\n';
		std::cout << '\n';
		this->_draw = false;
		this->_board = _player.GetBoard();
		this->_board.Display();
		if (_player.GetInventory().Size() > 0)
		{
			this->_canEquip = true;
			std::cout << _player.GetInventory().toString() << '\n';
			std::cout << "Equip/Consume item using keys 0,1,2..." << '\n';
		}
		std::cout << this->_player.toString();
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
		this->_canEquip = true;
	}
}

void Game::Battle()
{
	this->_player.SetEnemyFlag(false);
	bool exit = false;
	std::cout << "Battle started!" << '\n';
	while (!exit)
	{
		int tmpPlayerHP = this->_player.GetHealth();
		int tmpEnemyHP = this->_enemy->GetHealth();
		int tmpPlayerDamage = this->_player.GetDamage();
		int tmpEnemyDamage = this->_enemy->GetDamage();
		if (tmpPlayerHP - tmpEnemyDamage > 0)
		{
			this->_player.SetHealth(tmpPlayerHP - tmpEnemyDamage);
			std::cout << "Enemy Attacks!" << '\n';
			std::cout << this->_player.toString() << '\n';
			if (tmpEnemyHP - tmpPlayerDamage > 0)
			{
				this->_enemy->SetHealth(tmpEnemyHP - tmpPlayerDamage);
				std::cout << "Player Attacks!" << '\n';
				std::cout << this->_enemy->toString() << '\n';
				system("pause");
			}
			else {
				std::cout << "Enemy KILLED!" << '\n';
				exit = true;
				int drop = rand() % 100 + 1;
				if (drop <= _enemy->GetDropChance())
				{
					int type = rand() % 3;
					switch (type)
					{
					case 0:
						std::cout << "Enemy dropped a wepon!" << '\n';
						this->_player.GetInventory().AddItem(Weapon("Spear", WEAPON, 8));
						break;
					case 1:
						std::cout << "Enemy dropped an aromor!" << '\n';
						this->_player.GetInventory().AddItem(Armor("Vest",ARMOR, 5));
						break;
					case 2:
						std::cout << "Enemy dropped a potion!" << '\n';
						this->_player.GetInventory().AddItem(HealthPotion("Spirit",HEAL,15));
						break;
					default:
						break;
					}
				}
				delete this->_enemy;
				this->_enemy = nullptr;
			}
		}
		else {
			std::cout << "You are DEAD!" << '\n';
			exit = true;
		}
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

void Game::SaveGame()
{
	std::ofstream newFile;
	newFile.open("SaveGame.txt");
	if (newFile.is_open()) {
		newFile << this->_player.GetPosX() << ';' << this->_player.GetPosY() << ';' << this->_player.GetHealth() << ';' << this->_player.GetDamage() << ';' << this->_player.GetDefence() << ';' << this->_player.GetName() << std::endl;
		if (this->_player.GetInventory().Size() > 0)
		{
			for (size_t i = 0; i < _player.GetInventory().Size(); i++)
			{
				Weapon* tmp_w = dynamic_cast<Weapon*>(&this->_player.GetInventory().At(i));
				Armor* tmp_a = dynamic_cast<Armor*>(&this->_player.GetInventory().At(i));
				HealthPotion* tmp_p = dynamic_cast<HealthPotion*>(&this->_player.GetInventory().At(i));

				if (tmp_w)
				{
					newFile << tmp_w->GetName() << ';' << tmp_w->GetSubTypeAsString() << ';' << tmp_w->GetPosX() << ';' << tmp_w->GetPosY() << ';' << tmp_w->GetDamageValue() << std::endl;
				}
				if (tmp_a)
				{
					newFile << tmp_a->GetName() << ';' << tmp_a->GetSubTypeAsString() << ';' << tmp_a->GetPosX() << ';' << tmp_a->GetPosY() << ';' << tmp_a->GetArmorValue() << std::endl;
				}
				if (tmp_p)
				{
					newFile << tmp_p->GetName() << ';' << tmp_p->GetSubTypeAsString() << ';' << tmp_p->GetPosX() << ';' << tmp_p->GetPosY() << ';' << tmp_p->GetHealthValue() << std::endl;
				}
			}
		}
		if (this->_enemy)
		{
			newFile << this->_enemy->GetPosX() << ';' << this->_enemy->GetPosY() << ';' << this->_enemy->GetHealth() << ';' << this->_enemy->GetDamage() << std::endl;;
		}
		newFile.close();
		std::cout << '\n' << "Game is saved!" << '\n';
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
