#pragma once
#include "EquipableItem.h"
class Weapon :
	public EquipableItem
{
public:
	Weapon(std::string name, unsigned int subType, int damage);
	Weapon(std::string name, unsigned int subType, int x, int y, int damage, int startDamage, int battleCnt);
	~Weapon();

	const int GetDamageValue() const;
	const int GetArmorValue() const;

	const int GetStartDamageValue() const;
	const int GetDecreseValue() const;
	const int GetMinDamageValue() const;

	void SetDamageValue(const int value);
	void SetStartDamage(const int value);
	Weapon* Clone();
	const std::string toString() const;

	bool CheckIfDamaged() const;

private:
	int _damage;
	int _startDamage;
	const int _decreseValue = 2;
	const int _minDamageValue = 1;
};

