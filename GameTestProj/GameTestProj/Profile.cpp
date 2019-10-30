#include "Profile.h"

Profile::Profile()
{
	this->_enemy = nullptr;
}

Profile::~Profile()
{
	delete this->_enemy;
	this->_enemy = nullptr;
}

void Profile::NewGame()
{
	Board board;
	board.Load("Map.txt");
	Player newPlayer(1, 1, 100, 10, 0, "David", board);
	this->_enemy = new Enemy(2, 12, 50, 5, board, 100);
	this->_player = newPlayer;
	Board plBoard = newPlayer.GetBoard();
	this->_board = plBoard;
	plBoard.Display();

	this->_gameItems.AddItem(Weapon("Sword", WEAPON, 3, 5, 10));
	this->_gameItems.AddItem(Armor("Shield", ARMOR, 1, 8, 20));
	this->_gameItems.AddItem(HealthPotion("Heal", HEAL, 4, 2, 50));
}

Player Profile::GetPlayer() const
{
	return this->_player;
}

Enemy* Profile::GetEnemy() const
{
	return this->_enemy;
}

Inventory Profile::GetGameItems() const
{
	return this->_gameItems;
}

Board Profile::GetBoard() const
{
	return this->_board;
}

void Profile::SetPlayer(const Player& player)
{
	this->_player = player;
}

void Profile::SetEnemy(Enemy* enemy)
{
	this->_enemy = enemy;
}

void Profile::SetGameItems(const Inventory& inv)
{
	this->_gameItems = inv;
}

void Profile::SetBoard(const Board& board)
{
	this->_board = board;
}
