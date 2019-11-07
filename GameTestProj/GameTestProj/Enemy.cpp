#include "Enemy.h"

Enemy::Enemy()
{
	this->_dorpChance = 50;
	this->_playerEncounter = false;
}

Enemy::Enemy(const int x, const int y, int health, int damage, int dropChance) : Unit(x, y, health, damage)
{
	this->_dorpChance = dropChance;
	this->_playerEncounter = false;
}

Enemy::~Enemy()
{
}

Board Enemy::MoveObject(int vertical, int horizontal, Board board)
{
	int x = GetPosX();
	int x2 = x + horizontal;

	int y = GetPosY();
	int y2 = y + vertical;

	char nextElem1 = board.GetElem2(x2, y);
	char nextElem2 = board.GetElem2(x, y2);

	if (nextElem1 == ' ') {
		board.SetElem2(x, y, ' ');
		x += horizontal;
		SetPosX(x);
		board.SetElem2(x, y, 'e');
	}

	if (nextElem2 == ' ') {
		board.SetElem2(x, y, ' ');
		y += vertical;
		SetPosY(y);
		board.SetElem2(x, y, 'e');
	}

	if (nextElem1 == '@') {
		board.SetElem2(x, y, ' ');
		x += horizontal;
		SetPosX(x);
		board.SetElem2(x, y, '@');
		this->_playerEncounter = true;
	}

	if (nextElem2 == '@') {
		board.SetElem2(x, y, ' ');
		y += vertical;
		SetPosY(y);
		board.SetElem2(x, y, '@');
		this->_playerEncounter = true;
	}

	return board;
}

void Enemy::SetDropChance(const int dropChance)
{
	this->_dorpChance = dropChance;
}

void Enemy::SetPlayerEncounter(const bool & value)
{
	this->_playerEncounter = value;
}

bool Enemy::GetPlayerEncounter() const
{
	return this->_playerEncounter;
}

const int Enemy::GetDropChance() const
{
	return this->_dorpChance;
}

const std::string Enemy::toString()
{
	std::stringstream ss;
	ss << "Enemy: | Health: " << this->GetHealth() << " | Damage: " << this->GetDamage() << " | Drop chance: " << this->GetDropChance();
	return ss.str();
}
