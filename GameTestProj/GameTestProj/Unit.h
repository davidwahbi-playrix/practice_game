#pragma once
#include "MovableObject.h"
class Unit : public MovableObject
{
public:
	Unit();
	Unit(const int x, const int y, const int health, const int damage);
	~Unit();

	const int GetHealth();
	const int GetDamage();
	void SetHealth(int health);
	void SetDamage(int damage);
private:
	int _health;
	int _damage;
};

