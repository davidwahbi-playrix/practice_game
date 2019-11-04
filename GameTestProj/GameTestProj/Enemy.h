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
	Enemy(const int x, const int y, int health, int damage, int dropChance);
	Enemy(const int x, const int y, int health, int damage, Board board, int dropChance);
	~Enemy();

	Board MoveObject(int vertical, int horizontal, Board board);
	void SetDropChance(const int dropChance);

	void SetPlayerEncounter(const bool& value);
	bool GetPlayerEncounter() const;

	const int GetDropChance() const;

	const std::string toString();
private:
	int _dorpChance;
	bool _playerEncounter;
};
