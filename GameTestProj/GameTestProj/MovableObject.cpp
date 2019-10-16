#include "MovableObject.h"
#include <iostream>

using namespace std;

MovableObject::MovableObject()
{
}

MovableObject::MovableObject( const int x, const int y, int health, int damage)
{
	// id++;
	CheckPosX(x);
	CheckPosX(y);
	_posX = x;
	_posY = y;
	_health = health;
	_damage = damage;
}

int MovableObject::GetPosX()
{
	return _posX;
}

int MovableObject::GetPosY()
{
	return _posY;
}

void MovableObject::SetPosX(int x)
{
	_posX = x;
}

void MovableObject::SetPosY(int y)
{
	_posY = y;
}

int MovableObject::GetHealth()
{
	return _health;
}

int MovableObject::GetDamage()
{
	return _damage;
}

void MovableObject::SetHealth(int health)
{
	_health = health;
}

void MovableObject::SetDamage(int damage)
{
	_damage = damage;
}

void MovableObject::CheckPosX(const int x)
{
	if (x < 0) {
		cout << "Position out of bounds.";
	}
}

void MovableObject::CheckPosY(const int y)
{
	if (y < 0) {
		cout << "Position out of bounds.";
	}
}

MovableObject::~MovableObject()
{
}
