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
	std::cout << "l -> Load game." << '\n';
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
		this->EquipItem(_equipInd);
	}
}

void Game::Render()
{
	if (_draw) 
	{
		std::cout << "s -> Save game." << '\n';
		std::cout << "l -> Load game." << '\n';
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
		newFile << "Game" << std::endl;
		this->SaveGameItems(newFile);
		newFile << "Player" << std::endl;
		newFile << this->_player.GetPosX() << ';' << this->_player.GetPosY() << ';' << this->_player.GetHealth() << ';' << this->_player.GetDamage() << ';' << this->_player.GetDefence() << ';' << this->_player.GetName() << ';' << std::endl;;
		newFile << "PlayerInventory" << std::endl;
		this->SavePlayerInventory(newFile);
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
		getline(loadedFile, tmp_string); // Enemy
		getline(loadedFile, tmp_string); // Yes or None
		if (tmp_string != "None")
		{
			this->LoadEnemy(loadedFile);
			std::cout << this->_enemy->toString() << std::endl;
		}
		else {
			std::cout << "No enemies left!" << std::endl;
		}

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

		getline(file, tmp_string, ';');
		int item_pos_x;
		tmp_stream.str("");
		tmp_stream.clear();
		tmp_stream << tmp_string;
		tmp_stream >> item_pos_x;

		getline(file, tmp_string, ';');
		int item_pos_y;
		tmp_stream.str("");
		tmp_stream.clear();
		tmp_stream << tmp_string;
		tmp_stream >> item_pos_y;

		getline(file, tmp_string, ';');
		int item_atribut;
		tmp_stream.str("");
		tmp_stream.clear();
		tmp_stream << tmp_string;
		tmp_stream >> item_atribut;

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

	getline(file, tmp_string, ';');
	int player_pos_x;
	tmp_stream.str("");
	tmp_stream.clear();
	tmp_stream << tmp_string;
	tmp_stream >> player_pos_x;
	this->_player.SetPosX(player_pos_x);

	getline(file, tmp_string, ';');
	int player_pos_y;
	tmp_stream.str("");
	tmp_stream.clear();
	tmp_stream << tmp_string;
	tmp_stream >> player_pos_y;
	this->_player.SetPosY(player_pos_y);

	getline(file, tmp_string, ';');
	int player_health;
	tmp_stream.str("");
	tmp_stream.clear();
	tmp_stream << tmp_string;
	tmp_stream >> player_health;
	this->_player.SetHealth(player_health);

	getline(file, tmp_string, ';');
	int player_damage;
	tmp_stream.str("");
	tmp_stream.clear();
	tmp_stream << tmp_string;
	tmp_stream >> player_damage;
	this->_player.SetDamage(player_damage);

	getline(file, tmp_string, ';');
	int player_defence;
	tmp_stream.str("");
	tmp_stream.clear();
	tmp_stream << tmp_string;
	tmp_stream >> player_defence;
	this->_player.SetDefence(player_defence);

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

		getline(file, tmp_string, ';');
		int item_pos_x;
		tmp_stream.str("");
		tmp_stream.clear();
		tmp_stream << tmp_string;
		tmp_stream >> item_pos_x;

		getline(file, tmp_string, ';');
		int item_pos_y;
		tmp_stream.str("");
		tmp_stream.clear();
		tmp_stream << tmp_string;
		tmp_stream >> item_pos_y;

		getline(file, tmp_string, ';');
		int item_atribut;
		tmp_stream.str("");
		tmp_stream.clear();
		tmp_stream << tmp_string;
		tmp_stream >> item_atribut;

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

void Game::LoadEnemy(std::ifstream& file)
{
	std::string tmp_string;
	std::stringstream tmp_stream;

	getline(file, tmp_string, ';');
	int enemy_pos_x;
	tmp_stream.str("");
	tmp_stream.clear();
	tmp_stream << tmp_string;
	tmp_stream >> enemy_pos_x;
	this->_enemy->SetPosX(enemy_pos_x);

	getline(file, tmp_string, ';');
	int enemy_pos_y;
	tmp_stream.str("");
	tmp_stream.clear();
	tmp_stream << tmp_string;
	tmp_stream >> enemy_pos_y;
	this->_enemy->SetPosY(enemy_pos_y);

	getline(file, tmp_string, ';');
	int enemy_health;
	tmp_stream.str("");
	tmp_stream.clear();
	tmp_stream << tmp_string;
	tmp_stream >> enemy_health;
	this->_enemy->SetHealth(enemy_health);

	getline(file, tmp_string, ';');
	int enemy_damage;
	tmp_stream.str("");
	tmp_stream.clear();
	tmp_stream << tmp_string;
	tmp_stream >> enemy_damage;
	this->_enemy->SetDamage(enemy_damage);

	getline(file, tmp_string, ';');
	int enemy_dropChance;
	tmp_stream.str("");
	tmp_stream.clear();
	tmp_stream << tmp_string;
	tmp_stream >> enemy_dropChance;
	this->_enemy->SetDropChance(enemy_dropChance);

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
