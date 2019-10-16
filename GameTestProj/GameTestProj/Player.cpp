#include "Player.h"
#include <sstream>

Player::Player()
{
}

Player::Player( const int x, const int y, int health, int damage, std::string name, Board board) : MovableObject( x, y, health, damage)
{
	_playerName = name;
	_playerBoard = board;
	_itemPickedFlag = false;
}

void Player::MoveObject(int vertical, int horizontal)
{
	int x = GetPosX();
	int x2 = x + horizontal;

	int y = GetPosY();
	int y2 = y + vertical;

	char nextElem1 = _playerBoard.GetElem(x2, y);
	char nextElem2 = _playerBoard.GetElem(x, y2);

	if (nextElem1 == ' ') {
		_playerBoard.SetElem(x, y, ' ');
		x += horizontal;
		SetPosX(x);
		_playerBoard.SetElem(x, y, '@');
	}

	if (nextElem2 == ' ') {
		_playerBoard.SetElem(x, y, ' ');
		y += vertical;
		SetPosY(y);
		_playerBoard.SetElem(x, y, '@');
	}

	if (nextElem1 == '1') {
		_playerBoard.SetElem(x, y, ' ');
		x += horizontal;
		SetPosX(x);
		_playerBoard.SetElem(x, y, '@');
		_itemPickedFlag = true;

	}

	if (nextElem2 == '1') {
		_playerBoard.SetElem(x, y, ' ');
		y += vertical;
		SetPosY(y);
		_playerBoard.SetElem(x, y, '@');
		_itemPickedFlag = true;
	}
}

Board Player::GetBoard()
{
	return _playerBoard;
}

Inventory& Player::GetInventory()
{
	return this->_inventory;
}

void Player::SetInventory(Inventory inventory)
{
	this->_inventory = inventory;
}

void Player::SetBoard(Board board)
{
	_playerBoard = board;
}

void Player::SetPickedFlag(bool flag)
{
	_itemPickedFlag = flag;
}

bool Player::GetPickedFlag()
{
	return _itemPickedFlag;
}

void Player::DisplayName()
{
	std::stringstream buffer;
	buffer << _playerName << std::endl;
}

Player::~Player()
{
}
