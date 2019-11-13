#include "LoadGame.h"

LoadGame::LoadGame()
{
}

LoadGame::~LoadGame()
{
}

void LoadGame::LoadSmartGameState()
{
	std::ifstream loadedFile("SaveGame.txt");
	std::string tmp_string;
	std::stringstream tmp_stream;

	if (!loadedFile.fail())
	{
		system("cls");
		getline(loadedFile, tmp_string); // Level
		getline(loadedFile, tmp_string); // Level No.
		tmp_stream.str("");
		tmp_stream.clear();
		tmp_stream << tmp_string;
		tmp_stream >> _currentLevel;

		getline(loadedFile, tmp_string); // Game
		getline(loadedFile, tmp_string); // Game inventory size or None
		int num_of_gameItems;
		tmp_stream.str("");
		tmp_stream.clear();
		tmp_stream << tmp_string;
		tmp_stream >> num_of_gameItems;
		if (num_of_gameItems != -1)
		{
			LoadInventory(loadedFile, num_of_gameItems, _gameItems);
			std::cout << _gameItems.toString() << std::endl;
			getline(loadedFile, tmp_string); // empty
		}
		else
		{
			std::cout << "There are no more items left to pick!" << std::endl;
		}
		getline(loadedFile, tmp_string); // player
		LoadPlayer(loadedFile); // Load player
		std::cout << _player.toString() << std::endl;

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
			LoadInventory(loadedFile, num_of_playerItems, _player.GetInventory());
			std::cout << _player.GetInventory().toString() << std::endl;
			_player.SetCanEquip(true);
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
			LoadPlayerEquipment(loadedFile, 1);
			std::cout << "Player weapon: " << _player.GetWeapon()->toString() << std::endl;
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
			LoadPlayerEquipment(loadedFile, 2);
			std::cout << "Player armor: " << _player.GetArmor()->toString() << std::endl;
			getline(loadedFile, tmp_string); // empty
		}
		else
		{
			std::cout << "Player has no armor!" << std::endl;
		}
		getline(loadedFile, tmp_string); // Enemy
		getline(loadedFile, tmp_string); // Enemy number or None
		int num_of_enemies;
		tmp_stream.str("");
		tmp_stream.clear();
		tmp_stream << tmp_string;
		tmp_stream >> num_of_enemies;
		if (num_of_enemies != -1)
		{
			LoadSmartEnemy(loadedFile, num_of_enemies);
		}
		else {
			std::cout << "No enemies left!" << std::endl;
		}
		system("pause");
		system("cls");
		LoadBoard(_currentLevel);

		std::cout << "Game loaded!" << std::endl;
	}
	else
	{
		std::cout << "ERROR: problem with file!" << std::endl;
		system("pause");
	}
}

void LoadGame::LoadPlayer(std::ifstream& file)
{
	std::string tmp_string;
	std::stringstream tmp_stream;

	_player.SetPosX(ReadIntFromFile(file));
	_player.SetPosY(ReadIntFromFile(file));
	_player.SetHealth(ReadIntFromFile(file));
	_player.SetDamage(ReadIntFromFile(file));
	_player.SetDefence(ReadIntFromFile(file));

	getline(file, tmp_string, ';');
	_player.SetName(tmp_string);
	_player.SetStartDamage(ReadIntFromFile(file));

}

void LoadGame::LoadPlayerEquipment(std::ifstream& file, const int state)
{
	std::string tmp_string;
	std::stringstream tmp_stream;

	getline(file, tmp_string, ';');
	std::string item_name = tmp_string;

	getline(file, tmp_string, ';');
	std::string item_type = tmp_string;

	int item_pos_x = ReadIntFromFile(file);

	int item_pos_y = ReadIntFromFile(file);

	int item_atribut = ReadIntFromFile(file);

	int item_start_atribut = ReadIntFromFile(file);

	int item_battle_cnt = ReadIntFromFile(file);

	if (state == 1)
	{
		_player.SetWeapon(new Weapon(item_name, WEAPON, item_pos_x, item_pos_y, item_atribut, item_start_atribut, item_battle_cnt));

	}
	else if (state == 2)
	{
		_player.SetArmor(new Armor(item_name, ARMOR, item_pos_x, item_pos_y, item_atribut, item_start_atribut, item_battle_cnt));

	}
}

void LoadGame::LoadSmartEnemy(std::ifstream& file, const unsigned int size)
{
	size_t index = 0;
	_smartEnemies.clear();
	while (!file.eof() && index < size)
	{
		_smartEnemies.emplace_back(std::make_shared<Enemy>(1, 1, 0, 0, 0));
		_smartEnemies[index]->SetPosX(ReadIntFromFile(file));

		_smartEnemies[index]->SetPosY(ReadIntFromFile(file));

		_smartEnemies[index]->SetHealth(ReadIntFromFile(file));

		_smartEnemies[index]->SetDamage(ReadIntFromFile(file));

		_smartEnemies[index]->SetDropChance(ReadIntFromFile(file));

		std::cout << _smartEnemies[index]->toString() << std::endl;
		index++;
	}
}

void LoadGame::LoadInventory(std::ifstream & file, const unsigned int size, Inventory& inventory)
{
	std::string tmp_string;
	std::stringstream tmp_stream;
	size_t index_Inv = 0;

	inventory.ClearInventory();

	while (!file.eof() && index_Inv < size)
	{
		getline(file, tmp_string, ';');
		std::string item_name = tmp_string;

		getline(file, tmp_string, ';');
		std::string item_type = tmp_string;

		int item_pos_x = ReadIntFromFile(file);

		int item_pos_y = ReadIntFromFile(file);

		int item_atribut = ReadIntFromFile(file);

		int item_start_atribut = ReadIntFromFile(file);

		int item_battle_cnt = ReadIntFromFile(file);

		if (item_type == "WEAPON")
		{
			inventory.AddItem(Weapon(item_name, WEAPON, item_pos_x, item_pos_y, item_atribut, item_start_atribut, item_battle_cnt));
		}
		else if (item_type == "ARMOR")
		{
			inventory.AddItem(Armor(item_name, ARMOR, item_pos_x, item_pos_y, item_atribut, item_start_atribut, item_battle_cnt));
		}
		else if (item_type == "HEAL")
		{
			inventory.AddItem(HealthPotion(item_name, HEAL, item_pos_x, item_pos_y, item_atribut));
		}
		index_Inv++;
	}
}

void LoadGame::LoadBoard(int currLevel)
{
	std::string level = "Level";
	level += std::to_string(currLevel);
	level = level + ".txt";
	std::string levelInfo = "LevelInfo";
	levelInfo += std::to_string(currLevel);
	levelInfo = levelInfo + ".txt";
	std::ifstream levelFile(level);
	std::ifstream levelInfoFile(levelInfo);
	std::string tmp_string;
	std::stringstream tmp_stream;
	getline(levelInfoFile, tmp_string);
	int numRow = ReadIntFromFile(levelInfoFile);
	int numCol = ReadIntFromFile(levelInfoFile);

	_board.InitBoard(numRow, numCol);
	_board.Load2(level);

	_board.ClearBoard();
	_board.SetElem3(_player.GetPosX(), _player.GetPosY(), '@');
	if (_gameItems.Size() > 0)
	{
		for (size_t i = 0; i < _gameItems.Size(); i++)
		{
			_board.SetElem3(_gameItems[i].GetPosX(), _gameItems[i].GetPosY(), 'i');
		}
	}
	if (_smartEnemies.size() > 0)
	{
		for (size_t i = 0; i < _smartEnemies.size(); i++)
		{
			_board.SetElem3(_smartEnemies[i]->GetPosX(), _smartEnemies[i]->GetPosY(), 'e');
		}
	}

	_board.Display2();

}

Player LoadGame::GetPlayer() const
{
	return _player;
}

std::vector<std::shared_ptr<Enemy>> LoadGame::GetSmartEnemies() const
{
	return _smartEnemies;
}

Inventory LoadGame::GetGameInventory() const
{
	return _gameItems;
}

Board LoadGame::GetBoard() const
{
	return _board;
}

int LoadGame::GetCurrentLevel() const
{
	return _currentLevel;
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