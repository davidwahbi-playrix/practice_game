#include "Profile.h"

Profile::Profile()
{
}

Profile::~Profile()
{

	for (size_t i = 0; i < this->_enemies.size(); i++)
	{
		delete this->_enemies[i];
		this->_enemies[i] = nullptr;
	}
	this->_enemies.clear();
}

void Profile::NewGame()
{
	Board board;
	board.Load("Map.txt");
	Player newPlayer(1, 1, 100, 10, 0, "David", board);
	this->_enemies.emplace_back(new Enemy(2, 12, 50, 5, board, 100));
	this->_enemies.emplace_back(new Enemy(6, 41, 100, 3, board, 100));
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

Inventory Profile::GetGameItems() const
{
	return this->_gameItems;
}

Board Profile::GetBoard() const
{
	return this->_board;
}

std::vector<Enemy*> Profile::GetEnemies() const
{
	return this->_enemies;
}

void Profile::SetPlayer(const Player& player)
{
	this->_player = player;
}

void Profile::SetGameItems(const Inventory& inv)
{
	this->_gameItems = inv;
}

void Profile::SetBoard(const Board& board)
{
	this->_board = board;
}

void Profile::SetEnemies(const std::vector<Enemy*> enemies)
{
	this->_enemies = enemies;
}
