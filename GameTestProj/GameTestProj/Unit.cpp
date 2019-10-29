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

const int Unit::GetHealth()
{
	return this->_health;
}

const int Unit::GetDamage()
{
	return _damage;
}

void Unit::SetHealth(int health)
{
	this->_health = health;
}

void Unit::SetDamage(int damage)
{
	this->_damage = damage;
}
