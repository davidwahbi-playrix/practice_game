#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(const int x, const int y, int health, int damage, Board board) : MovableObject(x, y, health, damage)
{
	this->_enemyBoard = board;
}

Enemy::~Enemy()
{
}

void Enemy::MoveObject(int vertical, int horizontal)
{
	int x = GetPosX();
	int x2 = x + horizontal;

	int y = GetPosY();
	int y2 = y + vertical;

	char nextElem1 = _enemyBoard.GetElem(x2, y);
	char nextElem2 = _enemyBoard.GetElem(x, y2);

	if (nextElem1 == ' ') {
		_enemyBoard.SetElem(x, y, ' ');
		x += horizontal;
		SetPosX(x);
		_enemyBoard.SetElem(x, y, 'e');
	}

	if (nextElem2 == ' ') {
		_enemyBoard.SetElem(x, y, ' ');
		y += vertical;
		SetPosY(y);
		_enemyBoard.SetElem(x, y, 'e');
	}
}

void Enemy::SetBoard(Board board)
{
	this->_enemyBoard = board;
}

Board Enemy::GetBoard()
{
	return this->_enemyBoard;
}
