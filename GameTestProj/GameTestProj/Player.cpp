#include "Player.h"
#include <sstream>
#include<iostream>

Player::Player()
{
	this->_itemPickedFlag = false;
	this->_health = 100;
	this->_damage = 5;
	this->_defence = 0;
	this->_weapon = nullptr;
	this->_armor = nullptr;
}

Player::Player( const int x, const int y, int health, int damage, int defence, std::string name, Board board) : MovableObject( x, y, health, damage)
{
	this->_playerName = name;
	this->_playerBoard = board;
	this->_itemPickedFlag = false;
	this->_health = health;
	this->_damage = damage;
	this->_defence = defence;
	this->_weapon = nullptr;
	this->_armor = nullptr;
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

	if (nextElem1 == 'i') {
		_playerBoard.SetElem(x, y, ' ');
		x += horizontal;
		SetPosX(x);
		_playerBoard.SetElem(x, y, '@');
		_itemPickedFlag = true;

	}

	if (nextElem2 == 'i') {
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

Weapon* Player::GetWeapon()
{
	return this->_weapon;
}

Armor* Player::GetArmor()
{
	return this->_armor;
}

void Player::AddDamage(int value)
{
	this->_damage += value;
}

void Player::AddDefence(int value)
{
	this->_defence += value;
}

void Player::AddHealth(int value)
{
	this->_health += value;
}

void Player::SetWeapon(Weapon* weapon)
{
	this->_weapon = weapon;
}

void Player::SetArmor(Armor* armor)
{
	this->_armor = armor;
}

const std::string Player::toString() const
{
	std::stringstream ss;
	ss << this->GetName() << " | Health: " << this->_health << " | Damage: " << this->_damage <<  " | Armor: " << this->_defence;
	return ss.str();
}

Player::~Player()
{
	delete this->_weapon;
	delete this->_armor;
}
