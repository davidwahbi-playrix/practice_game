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
	~Enemy();

	void MoveObject2(int vertical, int horizontal, Board& board);
	void SetDropChance(const int dropChance);

	void ReceiveHit(const int playerDamage, const int playerHealth, const int playerDefence);
	bool CanBattle(const int polayerDamage) const;

	void SetPlayerEncounter(const bool& value);
	bool GetPlayerEncounter() const;

	const int GetDropChance() const;

	const std::string toString();
private:
	int _dorpChance;
	bool _playerEncounter;
};
