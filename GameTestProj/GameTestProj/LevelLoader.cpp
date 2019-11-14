#include "LevelLoader.h"



LevelLoader::LevelLoader()
{

}


LevelLoader::~LevelLoader()
{
}

void LevelLoader::LoadPlayer(Player & player)
{
	std::ifstream defaultPlayerInfo("DefaultPlayer.txt");
	LoadPlayerInfo(defaultPlayerInfo, player);
}

void LevelLoader::SetPlayerStartPos(const int& level, Player & player)
{
	std::string levelInfo = "LevelInfo";
	levelInfo += std::to_string(level);
	levelInfo = levelInfo + ".txt";
	std::ifstream levelInfoFile(levelInfo);
	std::string tmp_string;
	std::stringstream tmp_stream;
	getline(levelInfoFile, tmp_string); // Player
	player.SetPosX(ReadIntFromFile(levelInfoFile));
	player.SetPosY(ReadIntFromFile(levelInfoFile));
	getline(levelInfoFile, tmp_string); // empty
}

void LevelLoader::LoadLevel2(const int & currLevel, bool & running, Board & board, Inventory & gameItems, std::vector<std::shared_ptr<Enemy>>& smartEnemies)
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

	if (currLevel >= MAXLEVEL)
	{
		running = false;
		system("cls");
	}

	if (!levelInfoFile.fail())
	{
		getline(levelInfoFile, tmp_string); // Player
		getline(levelInfoFile, tmp_string); // Player position
		getline(levelInfoFile, tmp_string); // Board
		int numRow = ReadIntFromFile(levelInfoFile);
		int numCol = ReadIntFromFile(levelInfoFile);
		board.InitBoard(numRow, numCol);
		board.Load2(level);

		getline(levelInfoFile, tmp_string); // empty
		getline(levelInfoFile, tmp_string); // Game
		getline(levelInfoFile, tmp_string); // Game inventory size or None
		int num_of_gameItems;
		tmp_stream.str("");
		tmp_stream.clear();
		tmp_stream << tmp_string;
		tmp_stream >> num_of_gameItems;
		gameItems.ClearInventory();
		if (num_of_gameItems != -1)
		{
			LoadInventory(levelInfoFile, num_of_gameItems, gameItems);
			getline(levelInfoFile, tmp_string); // empty
		}
		else
		{
			if (currLevel < MAXLEVEL)
			{
				std::cout << "There are no more items left to pick!" << std::endl;
			}
		}
		getline(levelInfoFile, tmp_string); // Enemy
		getline(levelInfoFile, tmp_string); // Enemy number or None
		int num_of_enemies;
		tmp_stream.str("");
		tmp_stream.clear();
		tmp_stream << tmp_string;
		tmp_stream >> num_of_enemies;
		smartEnemies.clear();
		if (num_of_enemies != -1)
		{
			LoadSmartEnemy2(levelInfoFile, num_of_enemies, smartEnemies);
		}
		else {
			if (currLevel < MAXLEVEL)
			{
				std::cout << "No enemies left!" << std::endl;
			}
		}
	}
}

void LevelLoader::LoadInventory(std::ifstream & file, const unsigned int size, Inventory& inventory)
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

void LevelLoader::LoadSmartEnemy2(std::ifstream & file, const unsigned int size, std::vector<std::shared_ptr<Enemy>>& smartEnemies)
{
	size_t index = 0;
	smartEnemies.clear();
	while (!file.eof() && index < size)
	{
		smartEnemies.emplace_back(std::make_shared<Enemy>(1, 1, 0, 0, 0));
		smartEnemies[index]->SetPosX(ReadIntFromFile(file));

		smartEnemies[index]->SetPosY(ReadIntFromFile(file));

		smartEnemies[index]->SetHealth(ReadIntFromFile(file));

		smartEnemies[index]->SetDamage(ReadIntFromFile(file));

		smartEnemies[index]->SetDropChance(ReadIntFromFile(file));

		index++;
	}
}

void LevelLoader::LoadPlayerInfo(std::ifstream & file, Player & player)
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

int LevelLoader::ReadIntFromFile(std::ifstream& file)
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
