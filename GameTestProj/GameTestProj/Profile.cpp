#include "Profile.h"

Profile::Profile()
{
}

Profile::~Profile()
{
}

void Profile::NewGame()
{
	Board board;
	board.Load("Map.txt");
	this->_board = board;
	Player newPlayer(1, 1, 100, 10, 0, "David");
	this->_smartEnemies.emplace_back(std::make_shared<Enemy>(2, 12, 50, 10, 100));
	this->_smartEnemies.emplace_back(std::make_shared<Enemy>(6, 41, 100, 3, 100));
	this->_player = newPlayer;
	this->_board.Display();

	this->_gameItems.AddItem(Weapon("Sword", WEAPON, 3, 5, 10, 10));
	this->_gameItems.AddItem(Armor("Shield", ARMOR, 1, 8, 20, 20));
	this->_gameItems.AddItem(HealthPotion("Heal", HEAL, 4, 2, 50));
	//this->_smartGameItems.AddSmartItem(Item("Sword", WEAPON, 3, 5, 10));
	//this->_smartGameItems.AddSmartItem(Item("Shield", ARMOR, 1, 8, 20));
	//this->_smartGameItems.AddSmartItem(Item("Heal", HEAL, 4, 2, 50));
}

Player Profile::GetPlayer() const
{
	return this->_player;
}

Inventory Profile::GetGameItems() const
{
	return this->_gameItems;
}

/*Inventory Profile::GetSmartGameItems() const
{
	return this->_smartGameItems;
}*/

Board Profile::GetBoard() const
{
	return this->_board;
}

std::vector<std::shared_ptr<Enemy>> Profile::GetSmartEnemies() const
{
	return this->_smartEnemies;
}

void Profile::SetPlayer(const Player& player)
{
	this->_player = player;
}

void Profile::SetGameItems(const Inventory& inv)
{
	this->_gameItems = inv;
}

/*void Profile::SetSmartGameItems(const Inventory& inv)
{
	this->_smartGameItems = inv;
} */

void Profile::SetBoard(const Board& board)
{
	this->_board = board;
}

void Profile::SetSmartEnemies(const std::vector<std::shared_ptr<Enemy>> smartEnemies)
{
	this->_smartEnemies = smartEnemies;
}
