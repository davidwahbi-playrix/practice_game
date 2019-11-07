#include "LevelLoader.h"



LevelLoader::LevelLoader()
{
	this->_gameContinue = true;
}


LevelLoader::~LevelLoader()
{
}

void LevelLoader::LoadLevel(int currLevel)
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

	if (currLevel == 3)
	{
		this->_gameContinue = false;
	}

	if (!levelInfoFile.fail())
	{
		getline(levelInfoFile, tmp_string); // Board
		int numRow = this->ReadIntFromFile(levelInfoFile);
		int numCol = this->ReadIntFromFile(levelInfoFile);
		this->_board.InitBoard(numRow, numCol);
		this->_board.Load2(level);

		getline(levelInfoFile, tmp_string); // empty
		getline(levelInfoFile, tmp_string); // Game
		getline(levelInfoFile, tmp_string); // Game inventory size or None
		int num_of_gameItems;
		tmp_stream.str("");
		tmp_stream.clear();
		tmp_stream << tmp_string;
		tmp_stream >> num_of_gameItems;
		if (num_of_gameItems != -1)
		{
			this->LoadInventory(levelInfoFile, num_of_gameItems, this->_gameItems);
			getline(levelInfoFile, tmp_string); // empty
		}
		else
		{
			std::cout << "There are no more items left to pick!" << std::endl;
		}
		getline(levelInfoFile, tmp_string); // Enemy
		getline(levelInfoFile, tmp_string); // Enemy number or None
		int num_of_enemies;
		tmp_stream.str("");
		tmp_stream.clear();
		tmp_stream << tmp_string;
		tmp_stream >> num_of_enemies;
		if (num_of_enemies != -1)
		{
			this->LoadSmartEnemy(levelInfoFile, num_of_enemies);
		}
		else {
			std::cout << "No enemies left!" << std::endl;
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

		int item_pos_x = this->ReadIntFromFile(file);

		int item_pos_y = this->ReadIntFromFile(file);

		int item_atribut = this->ReadIntFromFile(file);

		int item_start_atribut = this->ReadIntFromFile(file);

		int item_battle_cnt = this->ReadIntFromFile(file);

		if (item_type == "WEAPON")
		{
			inventory.AddItem(Weapon(item_name, WEAPON, item_pos_x, item_pos_y, item_atribut, item_start_atribut, item_battle_cnt));
			//_gameItems.AddSmartItem(Weapon(item_name, WEAPON, item_pos_x, item_pos_y, item_atribut));
		}
		else if (item_type == "ARMOR")
		{
			inventory.AddItem(Armor(item_name, ARMOR, item_pos_x, item_pos_y, item_atribut, item_start_atribut, item_battle_cnt));
			//_gameItems.AddSmartItem(Armor(item_name, ARMOR, item_pos_x, item_pos_y, item_atribut));
		}
		else if (item_type == "HEAL")
		{
			inventory.AddItem(HealthPotion(item_name, HEAL, item_pos_x, item_pos_y, item_atribut));
			//_gameItems.AddSmartItem(HealthPotion(item_name, HEAL, item_pos_x, item_pos_y, item_atribut));
		}
		index_Inv++;
	}
}

void LevelLoader::LoadSmartEnemy(std::ifstream& file, const unsigned int size)
{
	size_t index = 0;
	this->_smartEnemies.clear();
	while (!file.eof() && index < size)
	{
		this->_smartEnemies.emplace_back(std::make_shared<Enemy>(1, 1, 0, 0, 0));
		this->_smartEnemies[index]->SetPosX(this->ReadIntFromFile(file));

		this->_smartEnemies[index]->SetPosY(this->ReadIntFromFile(file));

		this->_smartEnemies[index]->SetHealth(this->ReadIntFromFile(file));

		this->_smartEnemies[index]->SetDamage(this->ReadIntFromFile(file));

		this->_smartEnemies[index]->SetDropChance(this->ReadIntFromFile(file));

		index++;
	}
}

Board LevelLoader::GetBoard() const
{
	return this->_board;
}

Inventory LevelLoader::GetGameItems() const
{
	return this->_gameItems;
}

std::vector<std::shared_ptr<Enemy>> LevelLoader::GetSmartEnemies() const
{
	return this->_smartEnemies;
}

bool LevelLoader::GetFinishStatus() const
{
	return this->_gameContinue;
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
