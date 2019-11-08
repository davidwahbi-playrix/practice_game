#pragma once
#include "Board.h"
#include <iterator>
#include <map>

struct MovePos {
	MovePos() : _posX(0), _posY(0) {}
	MovePos(int x, int y): _posX(x), _posY(y) {}
	int _posX;
	int _posY;
};

class MovableObject
{
public:
	MovableObject();
	MovableObject(const int x, const int y);
	virtual ~MovableObject();

	int GetPosX() const;
	int GetPosY() const;
	void SetPosX(const int x);
	void SetPosY(const int y);

	void CheckPosX(const int x);
	void CheckPosY(const int y);

	MovePos GetMovePos(const int index);

	virtual void MoveObject2(int vertical, int horizontal, Board& board) = 0;

private:
	int _posX;
	int _posY;
	std::map<int, MovePos> _directions = { {1, MovePos(0, -1)}, {2, MovePos(1, 0)}, {3, MovePos(0, 1)}, {4, MovePos(-1, 0)} };
};

