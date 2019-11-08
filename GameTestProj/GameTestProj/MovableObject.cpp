#include "MovableObject.h"
#include <iostream>

using namespace std;

MovableObject::MovableObject()
{
	_posX = 1;
	_posY = 1;
}

MovableObject::MovableObject( const int x, const int y)
{
	CheckPosX(x);
	CheckPosX(y);
	_posX = x;
	_posY = y;
}

int MovableObject::GetPosX() const
{
	return _posX;
}

int MovableObject::GetPosY() const
{
	return _posY;
}

void MovableObject::SetPosX(const int x)
{
	_posX = x;
}

void MovableObject::SetPosY(const int y)
{
	_posY = y;
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

MovePos MovableObject::GetMovePos(const int index)
{
	map<int, MovePos>::iterator itr;
	return _directions.at(index);
}

MovableObject::~MovableObject()
{
}
