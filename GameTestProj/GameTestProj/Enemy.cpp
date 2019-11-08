#include "Enemy.h"

Enemy::Enemy()
{
	_dorpChance = 50;
	_playerEncounter = false;
}

Enemy::Enemy(const int x, const int y, int health, int damage, int dropChance) : Unit(x, y, health, damage)
{
	_dorpChance = dropChance;
	_playerEncounter = false;
}

Enemy::~Enemy()
{
}

void Enemy::MoveObject2(int vertical, int horizontal, Board & board)
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
		_playerEncounter = true;
	}

	if (nextElem2 == '@') {
		board.SetElem2(x, y, ' ');
		y += vertical;
		SetPosY(y);
		board.SetElem2(x, y, '@');
		_playerEncounter = true;
	}
}

void Enemy::SetDropChance(const int dropChance)
{
	_dorpChance = dropChance;
}

void Enemy::ReceiveHit(const int playerDamage, const int playerHealth, const int playerDefence)
{
	if (playerHealth + playerDefence - GetDamage() > 0)
	{
		if (GetHealth() - playerDamage > 0)
		{
			SetHealth(GetHealth() - playerDamage);
		}
	}

}

bool Enemy::CanBattle(const int polayerDamage) const
{
	return (GetHealth() - polayerDamage > 0);
}

void Enemy::SetPlayerEncounter(const bool & value)
{
	_playerEncounter = value;
}

bool Enemy::GetPlayerEncounter() const
{
	return _playerEncounter;
}

const int Enemy::GetDropChance() const
{
	return _dorpChance;
}

const std::string Enemy::toString()
{
	std::stringstream ss;
	ss << "Enemy: | Health: " << GetHealth() << " | Damage: " << GetDamage() << " | Drop chance: " << GetDropChance();
	return ss.str();
}
