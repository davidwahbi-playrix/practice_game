#include "LoadGame.h"

LoadGame::LoadGame()
{
}

LoadGame::~LoadGame()
{
}

void LoadGame::LoadSmartGameState3(int & level, SmartInventory & gameItems, SmartPlayer & player, std::vector<std::shared_ptr<Enemy>>& smartEnemies, Board & board)
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
		tmp_stream >> level;

		getline(loadedFile, tmp_string); // Game
		getline(loadedFile, tmp_string); // Game inventory size or None
		int num_of_gameItems;
		tmp_stream.str("");
		tmp_stream.clear();
		tmp_stream << tmp_string;
		tmp_stream >> num_of_gameItems;
		gameItems.ClearSmartInventory();
		if (num_of_gameItems != -1)
		{
			LoadInventory2(loadedFile, num_of_gameItems, gameItems);
			std::cout << gameItems.toString() << std::endl;
			getline(loadedFile, tmp_string); // empty
		}
		else
		{
			std::cout << "There are no more items left to pick!" << std::endl;
		}
		getline(loadedFile, tmp_string); // player
		LoadSmartPlayer2(loadedFile, player); // Load player
		std::cout << player.toString() << std::endl;

		getline(loadedFile, tmp_string); // empty
		getline(loadedFile, tmp_string); // Player Invnetory
		getline(loadedFile, tmp_string); // Player inventory size or None
		int num_of_playerItems;
		tmp_stream.str("");
		tmp_stream.clear();
		tmp_stream << tmp_string;
		tmp_stream >> num_of_playerItems;
		player.GetSmartInventory().ClearSmartInventory();
		if (num_of_playerItems != -1)
		{
			LoadInventory2(loadedFile, num_of_playerItems, player.GetSmartInventory());
			std::cout << player.GetSmartInventory().toString() << std::endl;
			player.SetCanEquip(true);
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
			LoadSmartPlayerEquipment2(loadedFile, 1, player);
			std::cout << "Player weapon: " << player.GetSmartWeapon()->toString() << std::endl;
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
			LoadSmartPlayerEquipment2(loadedFile, 2, player);
			std::cout << "Player armor: " << player.GetSmartArmor()->toString() << std::endl;
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
		smartEnemies.clear();
		if (num_of_enemies != -1)
		{
			LoadSmartEnemy2(loadedFile, num_of_enemies, smartEnemies);
		}
		else {
			std::cout << "No enemies left!" << std::endl;
		}
		system("pause");
		system("cls");
		LoadSmartBoard2(level, board, player, gameItems, smartEnemies);

		std::cout << "Game loaded!" << std::endl;
	}
	else
	{
		std::cout << "ERROR: problem with file!" << std::endl;
		system("pause");
	}
}

void LoadGame::LoadSmartPlayer2(std::ifstream & file, SmartPlayer & player)
{
	std::string tmp_string;
	std::stringstream tmp_stream;

	player.SetPosX(ReadIntFromFile(file));
	player.SetPosY(ReadIntFromFile(file));
	player.SetHealth(ReadIntFromFile(file));
	player.SetDamage(ReadIntFromFile(file));
	player.SetDefence(ReadIntFromFile(file));

	getline(file, tmp_string, ';');
	player.SetName(tmp_string);
	player.SetStartDamage(ReadIntFromFile(file));
}

void LoadGame::LoadSmartPlayerEquipment2(std::ifstream & file, const int state, SmartPlayer & player)
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
		player.SetSmartWeapon(std::make_shared<Weapon>(item_name, WEAPON, item_pos_x, item_pos_y, item_atribut, item_start_atribut, item_battle_cnt));

	}
	else if (state == 2)
	{
		player.SetSmartArmor(std::make_shared<Armor>(item_name, ARMOR, item_pos_x, item_pos_y, item_atribut, item_start_atribut, item_battle_cnt));

	}
}

void LoadGame::LoadSmartEnemy2(std::ifstream & file, const unsigned int size, std::vector<std::shared_ptr<Enemy>>& smartEnemies)
{
	size_t index = 0;
	while (!file.eof() && index < size)
	{
		smartEnemies.emplace_back(std::make_shared<Enemy>(1, 1, 0, 0, 0));
		smartEnemies[index]->SetPosX(ReadIntFromFile(file));

		smartEnemies[index]->SetPosY(ReadIntFromFile(file));

		smartEnemies[index]->SetHealth(ReadIntFromFile(file));

		smartEnemies[index]->SetDamage(ReadIntFromFile(file));

		smartEnemies[index]->SetDropChance(ReadIntFromFile(file));

		std::cout << smartEnemies[index]->toString() << std::endl;
		index++;
	}
}

void LoadGame::LoadInventory2(std::ifstream & file, const unsigned int size, SmartInventory & inventory)
{
	std::string tmp_string;
	std::stringstream tmp_stream;
	size_t index_Inv = 0;

	inventory.ClearSmartInventory();

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
			inventory.AddSmartItem(std::make_shared<Weapon>(item_name, WEAPON, item_pos_x, item_pos_y, item_atribut, item_start_atribut, item_battle_cnt));
		}
		else if (item_type == "ARMOR")
		{
			inventory.AddSmartItem(std::make_shared<Armor>(item_name, ARMOR, item_pos_x, item_pos_y, item_atribut, item_start_atribut, item_battle_cnt));
		}
		else if (item_type == "HEAL")
		{
			inventory.AddSmartItem(std::make_shared<HealthPotion>(item_name, HEAL, item_pos_x, item_pos_y, item_atribut));
		}
		index_Inv++;
	}
}

void LoadGame::LoadSmartBoard2(int & currLevel, Board & board, SmartPlayer & player, SmartInventory & gameItems, std::vector<std::shared_ptr<Enemy>>& smartEnemies)
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
	getline(levelInfoFile, tmp_string); // PlayerPos
	getline(levelInfoFile, tmp_string); // position x position y
	getline(levelInfoFile, tmp_string); // Board
	int numRow = ReadIntFromFile(levelInfoFile);
	int numCol = ReadIntFromFile(levelInfoFile);

	board.InitBoard(numRow, numCol);
	board.Load2(level);

	board.ClearBoard();
	board.SetElem3(player.GetPosX(), player.GetPosY(), '@');
	if (gameItems.Size() > 0)
	{
		for (size_t i = 0; i < gameItems.Size(); i++)
		{
			board.SetElem3(gameItems[i]->GetPosX(), gameItems[i]->GetPosY(), 'i');
		}
	}
	if (smartEnemies.size() > 0)
	{
		for (size_t i = 0; i < smartEnemies.size(); i++)
		{
			board.SetElem3(smartEnemies[i]->GetPosX(), smartEnemies[i]->GetPosY(), 'e');
		}
	}

	board.Display2();
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