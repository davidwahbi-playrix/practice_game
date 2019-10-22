#include "Player.h"

Player::Player()
{
	this->_itemPickedFlag = false;
	this->_enemyEncounter = false;
	this->_defence = 0;
	this->_weapon = nullptr;
	this->_armor = nullptr;
}

Player::Player( const int x, const int y, int health, int damage, int defence, std::string name, Board board) : MovableObject( x, y, health, damage)
{
	this->_playerName = name;
	this->_playerBoard = board;
	this->_itemPickedFlag = false;
	this->_enemyEncounter = false;
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
	if (nextElem1 == 'e') {
		_playerBoard.SetElem(x, y, ' ');
		x += horizontal;
		SetPosX(x);
		_playerBoard.SetElem(x, y, '@');
		_enemyEncounter = true;

	}

	if (nextElem2 == 'e') {
		_playerBoard.SetElem(x, y, ' ');
		y += vertical;
		SetPosY(y);
		_playerBoard.SetElem(x, y, '@');
		_enemyEncounter = true;
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

void Player::SetEnemyFlag(bool flag)
{
	this->_enemyEncounter = flag;
}

bool Player::GetPickedFlag()
{
	return this->_itemPickedFlag;
}

bool Player::GetEnemyFlag()
{
	return this->_enemyEncounter;
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
	int damage = this->GetDamage() + value;
	this->SetDamage(damage);
}

void Player::AddDefence(int value)
{
	this->_defence += value;
}

void Player::AddHealth(int value)
{
	int health = this->GetHealth() + value;
	this->SetHealth(health);
}

void Player::SetWeapon(Weapon* weapon)
{
	this->_weapon = weapon;
}

void Player::SetArmor(Armor* armor)
{
	this->_armor = armor;
}

const std::string Player::toString()
{
	std::stringstream ss;
	ss << this->GetName() << " | Health: " << this->GetHealth() << " | Damage: " << this->GetDamage() <<  " | Armor: " << this->_defence;
	return ss.str();
}

Player::~Player()
{
	delete this->_weapon;
	delete this->_armor;
}
