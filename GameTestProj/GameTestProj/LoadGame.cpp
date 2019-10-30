#include "LoadGame.h"

LoadGame::LoadGame()
{
}

LoadGame::~LoadGame()
{
}

void LoadGame::LoadGameState()
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
		if (num_of_playerItems != -1)
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
		this->LoadBoard();

		std::cout << "Game loaded!" << std::endl;
	}
	else
	{
		std::cout << "ERROR: problem with file!" << std::endl;
		system("pause");
	}
}

void LoadGame::LoadGameItems(std::ifstream& file, const int size)
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

void LoadGame::LoadPlayer(std::ifstream& file)
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

void LoadGame::LoadPlayerIneventory(std::ifstream& file, const int size)
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

void LoadGame::LoadPlayerEquipment(std::ifstream& file, const int state)
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

void LoadGame::LoadEnemy(std::ifstream& file)
{

	this->_enemy->SetPosX(this->ReadIntFromFile(file));

	this->_enemy->SetPosY(this->ReadIntFromFile(file));

	this->_enemy->SetHealth(this->ReadIntFromFile(file));

	this->_enemy->SetDamage(this->ReadIntFromFile(file));

	this->_enemy->SetDropChance(this->ReadIntFromFile(file));

}

void LoadGame::LoadBoard()
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


Player LoadGame::GetPlayer() const
{
	return this->_player;
}

Enemy* LoadGame::GetEnemy() const
{
	return this->_enemy;
}

Inventory LoadGame::GetGameInventory() const
{
	return this->_gameItems;
}

Board LoadGame::GetBoard() const
{
	return this->_board;
}

int LoadGame::ReadIntFromFile(std::ifstream& file)
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