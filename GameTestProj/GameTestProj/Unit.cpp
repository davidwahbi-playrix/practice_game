#include "Unit.h"

Unit::Unit()
{
	_health = 50;
	_damage = 1;
}

Unit::Unit(const int x, const int y, const int health, const int damage) : MovableObject(x,y)
{
	_health = health;
	_damage = damage;
}

Unit::~Unit()
{
}

const int Unit::GetHealth() const
{
	return _health;
}

const int Unit::GetDamage() const
{
	return _damage;
}

void Unit::SetHealth(const int health)
{
	_health = health;
}

void Unit::SetDamage(const int damage)
{
	_damage = damage;
}
