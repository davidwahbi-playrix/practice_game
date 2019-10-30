#pragma once
#include "Unit.h"

#include <string>
#include <sstream>
#include <iostream>
#include "Item.h"
#include "Board.h"
class Enemy : public Unit
{
public:
	Enemy();
	Enemy(const int x, const int y, int health, int damage, Board board, int dropChance);
	~Enemy();

	void MoveObject(int vertical, int horizontal);
	void SetBoard(const Board& board);
	void SetDropChance(const int dropChance);

	const int GetDropChance() const;
	Board GetBoard() const;

	const std::string toString();
private:
	Board _enemyBoard;
	int _dorpChance;
};
