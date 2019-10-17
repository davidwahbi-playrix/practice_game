#include "Player.h"
#include <sstream>
#include<iostream>

Player::Player()
{
}

Player::Player( const int x, const int y, int health, int damage, int armor, std::string name, Board board) : MovableObject( x, y, health, damage)
{
	this->_playerName = name;
	this->_playerBoard = board;
	this->_itemPickedFlag = false;
	this->_health = health;
	this->_damage = damage;
	this->_armor = armor;
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
	return this->_playerBoard;
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
	this->_playerBoard = board;
}

void Player::SetPickedFlag(bool flag)
{
	this->_itemPickedFlag = flag;
}

bool Player::GetPickedFlag()
{
	return this->_itemPickedFlag;
}

const std::string& Player::GetName() const
{
	return this->_playerName;
}

void Player::AddDamage(int value)
{
	this->_health += value;
}

void Player::AddArmor(int value)
{
	this->_armor += value;
}

void Player::AddHealth(int value)
{
	this->_health += value;
}

const std::string Player::toString() const
{
	std::stringstream ss;
	ss << this->GetName() << " | Health: " << this->_health << " | Damage: " << this->_damage << " | Armor: " << this->_armor;
	return ss.str();
}

Player::~Player()
{
}
