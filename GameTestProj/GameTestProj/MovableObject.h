#pragma once
#include "Board.h"
class MovableObject
{
public:
	MovableObject();
	MovableObject(const int x, const int y);
	int GetPosX() const;
	int GetPosY() const;
	void SetPosX(const int x);
	void SetPosY(const int y);

	void CheckPosX(const int x);
	void CheckPosY(const int y);
	virtual Board MoveObject(int vertical, int horizontal, Board board) = 0;
	virtual ~MovableObject();
private:
	int _posX;
	int _posY;
};

