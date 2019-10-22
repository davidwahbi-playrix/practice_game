#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include "MovableObject.h"
#include "Board.h"
class Enemy :
	public MovableObject
{
private:
	Board _enemyBoard;
public:
	Enemy();
	Enemy(const int x, const int y, int health, int damage, Board board);
	~Enemy();

	void MoveObject(int vertical, int horizontal);
	void SetBoard(Board board);

	Board GetBoard();

	const std::string toString();
};
