#include "Game.h"
#include <Windows.h>
#include <iostream>

Game::Game()
{
	this->_isRunning = false;
	this->_hasFile = false;
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
	this->SaveLoadMenu();
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
		this->SetHesFile(true);
	}
	if (GetAsyncKeyState(0x4C))
	{
		this->LoadGame();
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
		this->SaveLoadMenu();
		this->_draw = false;
		this->_board = _player.GetBoard();
		this->_board.Display();
		if (_player.GetInventory().Size() > 0)
		{
			std::cout << "Player inventory:" << std::endl;
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
		this->_gameItems.RemoveItem(index);
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
				system("pause");
				system("cls");
			}
		}
		else {
			std::cout << "You are DEAD!" << '\n';
			exit = true;
			system("pause");
			system("cls");
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

void Game::SaveLoadMenu()
{
	std::cout << "s -> Save game." << '\n';
	std::ifstream hasFile("SaveGame.txt");
	if (!hasFile.fail())
	{
		this->SetHesFile(true);
		std::cout << "l -> Load game." << '\n';
	}
	std::cout << '\n';
}

void Game::SaveGame()
{
	std::ofstream newFile;
	newFile.open("SaveGame.txt");
	if (newFile.is_open()) {
		newFile << "Game" << std::endl;
		this->SaveGameItems(newFile);
		newFile << "Player" << std::endl;
		newFile << this->_player.GetPosX() << ';' << this->_player.GetPosY() << ';' << this->_player.GetHealth() << ';' << this->_player.GetDamage() << ';' << this->_player.GetDefence() << ';' << this->_player.GetName() << ';' << std::endl;;
		newFile << "PlayerInventory" << std::endl;
		this->SavePlayerInventory(newFile);
		newFile << "PlayerEquipment" << std::endl;
		this->SavePlayerEquipment(newFile);
		newFile << "Enemy" << std::endl;
		if (this->_enemy)
		{
			newFile << "Yes" << std::endl;
			newFile << this->_enemy->GetPosX() << ';' << this->_enemy->GetPosY() << ';' << this->_enemy->GetHealth() << ';' << this->_enemy->GetDamage() << ';' << this->_enemy->GetDropChance() << ';' << std::endl;;
		}
		else
		{
			newFile << "None" << std::endl;
		}
		newFile.close();
		std::cout << '\n' << "Game is saved!" << '\n';
	}
}

void Game::SavePlayerInventory(std::ofstream& file)
{
	if (this->_player.GetInventory().Size() > 0)
	{
		file << this->_player.GetInventory().Size() << std::endl;
		for (size_t i = 0; i < _player.GetInventory().Size(); i++)
		{
			Weapon* tmp_w = dynamic_cast<Weapon*>(&this->_player.GetInventory().At(i));
			Armor* tmp_a = dynamic_cast<Armor*>(&this->_player.GetInventory().At(i));
			HealthPotion* tmp_p = dynamic_cast<HealthPotion*>(&this->_player.GetInventory().At(i));

			if (tmp_w)
			{
				file << tmp_w->GetName() << ';' << tmp_w->GetSubTypeAsString() << ';' << tmp_w->GetPosX() << ';' << tmp_w->GetPosY() << ';' << tmp_w->GetDamageValue() << ';';
			}
			if (tmp_a)
			{
				file << tmp_a->GetName() << ';' << tmp_a->GetSubTypeAsString() << ';' << tmp_a->GetPosX() << ';' << tmp_a->GetPosY() << ';' << tmp_a->GetArmorValue() << ';';
			}
			if (tmp_p)
			{
				file << tmp_p->GetName() << ';' << tmp_p->GetSubTypeAsString() << ';' << tmp_p->GetPosX() << ';' << tmp_p->GetPosY() << ';' << tmp_p->GetHealthValue() << ';';
			}
		}
		file << std::endl;
	}
	else
	{
		file << -1 << std::endl;
	}
}

void Game::SavePlayerEquipment(std::ofstream& file)
{	
	file << "Weapon" << std::endl;
	if (this->_player.GetWeapon()) {
		file << "Yes" << std::endl;
		file << _player.GetWeapon()->GetName() << ';' << _player.GetWeapon()->GetSubTypeAsString() << ';' << _player.GetWeapon()->GetPosX() << ';' << _player.GetWeapon()->GetPosY() << ';' << _player.GetWeapon()->GetDamageValue() << ';';
		file << std::endl;
	}
	else
	{
		file << "None" << std::endl;
	}
	file << "Armor" << std::endl;
	if (this->_player.GetArmor()) {
		file << "Yes" << std::endl;
		file << _player.GetArmor()->GetName() << ';' << _player.GetArmor()->GetSubTypeAsString() << ';' << _player.GetArmor()->GetPosX() << ';' << _player.GetArmor()->GetPosY() << ';' << _player.GetArmor()->GetDamageValue() << ';';
		file << std::endl;
	}
	else
	{
		file << "None" << std::endl;
	}
}

void Game::SaveGameItems(std::ofstream& file)
{
	if (this->_gameItems.Size() > 0) 
	{
		file << this->_gameItems.Size() << std::endl;
		for (size_t i = 0; i < this->_gameItems.Size(); i++)
		{
			Weapon* tmp_w = dynamic_cast<Weapon*>(&this->_gameItems.At(i));
			Armor* tmp_a = dynamic_cast<Armor*>(&this->_gameItems.At(i));
			HealthPotion* tmp_p = dynamic_cast<HealthPotion*>(&this->_gameItems.At(i));

			if (tmp_w)
			{
				file << tmp_w->GetName() << ';' << tmp_w->GetSubTypeAsString() << ';' << tmp_w->GetPosX() << ';' << tmp_w->GetPosY() << ';' << tmp_w->GetDamageValue() << ';';
			}
			if (tmp_a)
			{
				file << tmp_a->GetName() << ';' << tmp_a->GetSubTypeAsString() << ';' << tmp_a->GetPosX() << ';' << tmp_a->GetPosY() << ';' << tmp_a->GetArmorValue() << ';';
			}
			if (tmp_p)
			{
				file << tmp_p->GetName() << ';' << tmp_p->GetSubTypeAsString() << ';' << tmp_p->GetPosX() << ';' << tmp_p->GetPosY() << ';' << tmp_p->GetHealthValue() << ';';
			}
		}
		file << std::endl;
	}
	else
	{
		file << -1 << std::endl;
	}
}

void Game::LoadGame()
{
	std::ifstream loadedFile("SaveGame.txt");
	std::string tmp_string;
	std::stringstream tmp_stream;

	if (!loadedFile.fail())
	{
		system("cls");

		getline(loadedFile, tmp_string); // Game
		getline(loadedFile, tmp_string); // Game inventory size or None
		int num_of_gameItems;
		tmp_stream.str("");
		tmp_stream.clear();
		tmp_stream << tmp_string;
		tmp_stream >> num_of_gameItems;
		if (num_of_gameItems != -1)
		{
			this->LoadGameItems(loadedFile, num_of_gameItems);
			std::cout << this->_gameItems.toString() << std::endl;
			getline(loadedFile, tmp_string); // empty
		}
		else
		{
			std::cout << "There are no more items left to pick!" << std::endl;
		}
		getline(loadedFile, tmp_string); // player
		this->LoadPlayer(loadedFile); // Load player
		std::cout << this->_player.toString() << std::endl;

		getline(loadedFile, tmp_string); // empty
		getline(loadedFile, tmp_string); // Player Invnetory
		getline(loadedFile, tmp_string); // Player inventory size or None
		int num_of_playerItems;
		tmp_stream.str("");
		tmp_stream.clear();
		tmp_stream << tmp_string;
		tmp_stream >> num_of_playerItems;
		if (num_of_playerItems != -1 )
		{
			this->LoadPlayerIneventory(loadedFile, num_of_playerItems);
			std::cout << this->_player.GetInventory().toString() << std::endl;
			getline(loadedFile, tmp_string); // empty
		}
		else
		{
			std::cout << "Player has no items in inventory!" << std::endl;
		}
		getline(loadedFile, tmp_string); // PlayerEquipment
		getline(loadedFile, tmp_string); // Weapon
		getline(loadedFile, tmp_string); // Yes or None
		if (tmp_string != "None")
		{
			this->LoadPlayerEquipment(loadedFile, 1);
			std::cout << "Player weapon: " << this->_player.GetWeapon()->toString() << std::endl;
			getline(loadedFile, tmp_string); // empty
		}
		else
		{
			std::cout << "Player has no weapon!" << std::endl;
		}
		getline(loadedFile, tmp_string); // Armor
		getline(loadedFile, tmp_string); // Yes or None
		if (tmp_string != "None")
		{
			this->LoadPlayerEquipment(loadedFile, 2);
			std::cout << "Player armor: " << this->_player.GetArmor()->toString() << std::endl;
			getline(loadedFile, tmp_string); // empty
		}
		else
		{
			std::cout << "Player has no armor!" << std::endl;
		}
		getline(loadedFile, tmp_string); // Enemy
		getline(loadedFile, tmp_string); // Yes or None
		if (tmp_string != "None")
		{	
			if (!_enemy)
			{
				_enemy = new Enemy(0, 0, 0, 0, this->_board, 0);
			}
			this->LoadEnemy(loadedFile);
			std::cout << this->_enemy->toString() << std::endl;
		}
		else {
			std::cout << "No enemies left!" << std::endl;
		}
		system("pause");
		system("cls");
		this->SaveLoadMenu();
		this->LoadBoard();

		std::cout << "Game loaded!" << std::endl;
	}
	else
	{
		std::cout << "ERROR: problem with file!" << std::endl;
		system("pause");
	}
}

void Game::LoadGameItems(std::ifstream& file, const int size)
{
	std::string tmp_string;
	std::stringstream tmp_stream;
	size_t index_gameInv = 0;

	this->_gameItems.ClearInventory();

	while (!file.eof() && index_gameInv < size)
	{
		getline(file, tmp_string, ';');
		std::string item_name = tmp_string;

		getline(file, tmp_string, ';');
		std::string item_type = tmp_string;

		int item_pos_x = this->ReadIntFromFile(file);

		int item_pos_y = this->ReadIntFromFile(file);

		int item_atribut = this->ReadIntFromFile(file);

		if (item_type == "WEAPON")
		{
			_gameItems.AddItem(Weapon(item_name, WEAPON, item_pos_x, item_pos_y, item_atribut));
		}
		else if (item_type == "ARMOR")
		{
			_gameItems.AddItem(Armor(item_name, ARMOR, item_pos_x, item_pos_y, item_atribut));
		}
		else if (item_type == "HEAL")
		{
			_gameItems.AddItem(HealthPotion(item_name, HEAL, item_pos_x, item_pos_y, item_atribut));
		}
		index_gameInv++;
	}
}

void Game::LoadPlayer(std::ifstream& file)
{
	std::string tmp_string;
	std::stringstream tmp_stream;

	this->_player.SetPosX(this->ReadIntFromFile(file));
	this->_player.SetPosY(this->ReadIntFromFile(file));
	this->_player.SetHealth(this->ReadIntFromFile(file));
	this->_player.SetDamage(this->ReadIntFromFile(file));
	this->_player.SetDefence(this->ReadIntFromFile(file));

	getline(file, tmp_string, ';');
	this->_player.SetName(tmp_string);

}

void Game::LoadPlayerIneventory(std::ifstream& file, const int size)
{
	std::string tmp_string;
	std::stringstream tmp_stream;
	size_t index_playerInv = 0;
	this->_player.GetInventory().ClearInventory();

	while (!file.eof() && index_playerInv < size)
	{
		getline(file, tmp_string, ';');
		std::string item_name = tmp_string;

		getline(file, tmp_string, ';');
		std::string item_type = tmp_string;

		int item_pos_x = this->ReadIntFromFile(file);

		int item_pos_y = this->ReadIntFromFile(file);

		int item_atribut = this->ReadIntFromFile(file);

		if (item_type == "WEAPON")
		{
			this->_player.GetInventory().AddItem(Weapon(item_name, WEAPON, item_pos_x, item_pos_y, item_atribut));
		}
		else if (item_type == "ARMOR")
		{
			this->_player.GetInventory().AddItem(Armor(item_name, ARMOR, item_pos_x, item_pos_y, item_atribut));
		}
		else if (item_type == "HEAL")
		{
			this->_player.GetInventory().AddItem(HealthPotion(item_name, HEAL, item_pos_x, item_pos_y, item_atribut));
		}
		index_playerInv++;
	}
}

void Game::LoadPlayerEquipment(std::ifstream& file, const int state)
{
	std::string tmp_string;
	std::stringstream tmp_stream;

	getline(file, tmp_string, ';');
	std::string item_name = tmp_string;

	getline(file, tmp_string, ';');
	std::string item_type = tmp_string;

	int item_pos_x = this->ReadIntFromFile(file);

	int item_pos_y = this->ReadIntFromFile(file);

	int item_atribut = this->ReadIntFromFile(file);

	if (state == 1)
	{
		this->_player.SetWeapon(new Weapon(item_name, WEAPON, item_pos_x, item_pos_y, item_atribut));
	}
	else if (state == 2)
	{
		this->_player.SetArmor(new Armor(item_name, ARMOR, item_pos_x, item_pos_y, item_atribut));
	}
	
	
}

void Game::LoadEnemy(std::ifstream& file)
{

	this->_enemy->SetPosX(this->ReadIntFromFile(file));

	this->_enemy->SetPosY(this->ReadIntFromFile(file));

	this->_enemy->SetHealth(this->ReadIntFromFile(file));

	this->_enemy->SetDamage(this->ReadIntFromFile(file));

	this->_enemy->SetDropChance(this->ReadIntFromFile(file));

}

void Game::LoadBoard()
{
	Board board;
	board.Load("Map.txt");

	board.ClearBoard();
	board.SetElem(_player.GetPosX(), _player.GetPosY(), '@');
	if (_gameItems.Size() > 0)
	{
		for (size_t i = 0; i < _gameItems.Size(); i++)
		{
			board.SetElem(_gameItems[i].GetPosX(), _gameItems[i].GetPosY(), 'i');
		}
	}
	if (_enemy)
	{
		board.SetElem(_enemy->GetPosX(), _enemy->GetPosY(), 'e');
	}

	this->_board = board;
	this->_player.SetBoard(board);
	if (_enemy)
	{
		this->_enemy->SetBoard(board);
	}
	this->_board.Display();

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

bool Game::HasFile()
{
	return this->_hasFile;
}

void Game::SetHesFile(bool flag)
{
	this->_hasFile = flag;
}

int Game::ReadIntFromFile(std::ifstream& file)
{
	std::string tmp_string;
	std::stringstream tmp_stream;
	int tmp_value = 0;
	getline(file, tmp_string, ';');
	tmp_stream.str("");
	tmp_stream.clear();
	tmp_stream << tmp_string;
	tmp_stream >> tmp_value;
	return tmp_value;
}
