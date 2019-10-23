#pragma once
#include "MovableObject.h"

#include <string>
#include <sstream>
#include <iostream>
#include "Item.h"
#include "Board.h"
class Enemy :
	public MovableObject
{
private:
	Board _enemyBoard;
	int _dorpChance;
public:
	Enemy();
	Enemy(const int x, const int y, int health, int damage, Board board, int dropChance);
	~Enemy();

	void MoveObject(int vertical, int horizontal);
	void SetBoard(Board board);
	void SetDropChance(const int dropChance);

	const int GetDropChance();
	Board GetBoard();

	const std::string toString();
};
