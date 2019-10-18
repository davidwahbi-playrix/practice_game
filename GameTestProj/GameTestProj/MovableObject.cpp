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
	this->_posX = x;
	this->_posY = y;
	this->_health = health;
	this->_damage = damage;
}

int MovableObject::GetPosX()
{
	return this->_posX;
}

int MovableObject::GetPosY()
{
	return this->_posY;
}

void MovableObject::SetPosX(int x)
{
	this->_posX = x;
}

void MovableObject::SetPosY(int y)
{
	this->_posY = y;
}

int MovableObject::GetHealth()
{
	return this->_health;
}

int MovableObject::GetDamage()
{
	return this->_damage;
}

void MovableObject::SetHealth(int health)
{
	this->_health = health;
}

void MovableObject::SetDamage(int damage)
{
	this->_damage = damage;
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
