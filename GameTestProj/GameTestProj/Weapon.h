#pragma once
#include "EquipableItem.h"
class Weapon :
	public EquipableItem
{
public:
	Weapon(std::string name, unsigned int subType, int damage);
	Weapon(std::string name, unsigned int subType, int x, int y, int damage, int startDamage);
	~Weapon();

	const int GetDamageValue() const;
	const int GetArmorValue() const;

	const int GetStartDamageValue() const;

	void SetDamageValue(const int value);
	void SetStartDamage(const int value);
	Weapon* Clone();
	const std::string toString() const;
private:
	int _damage;
	int _startDamage;
};

