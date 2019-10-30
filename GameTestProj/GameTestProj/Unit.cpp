#include "Unit.h"

Unit::Unit()
{
	this->_health = 50;
	this->_damage = 1;
}

Unit::Unit(const int x, const int y, const int health, const int damage) : MovableObject(x,y)
{
	this->_health = health;
	this->_damage = damage;
}

Unit::~Unit()
{
}

const int Unit::GetHealth() const
{
	return this->_health;
}

const int Unit::GetDamage() const
{
	return _damage;
}

void Unit::SetHealth(const int health)
{
	this->_health = health;
}

void Unit::SetDamage(const int damage)
{
	this->_damage = damage;
}
