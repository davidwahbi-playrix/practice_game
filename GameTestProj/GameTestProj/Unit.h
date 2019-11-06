#pragma once
#include "MovableObject.h"
class Unit : public MovableObject
{
public:
	Unit();
	Unit(const int x, const int y, const int health, const int damage);
	virtual ~Unit();

	const int GetHealth() const;
	const int GetDamage() const;
	void SetHealth(const int health);
	void SetDamage(const int damage);
private:
	int _health;
	int _damage;
};

