#include "MovableObject.h"
#include <iostream>

using namespace std;

MovableObject::MovableObject()
{
	this->_posX = 1;
	this->_posY = 1;
}

MovableObject::MovableObject( const int x, const int y)
{
	CheckPosX(x);
	CheckPosX(y);
	this->_posX = x;
	this->_posY = y;
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
