#pragma once
#include "MovableObject.h"
#include <string>
#include "Board.h"
#include "Inventory.h"

class Player : public MovableObject
{
private:
	std::string _playerName;
	Board _playerBoard;
	Inventory _inventory;
public:
	Player();
	Player( const int x, const int y, int health, int damage, std::string name, Board board);
	void MoveObject(int vertical, int horizontal);
	Board GetBoard();
	Inventory& GetInventory();
	void SetBoard(Board board);
	void DisplayName();
	~Player();
};

