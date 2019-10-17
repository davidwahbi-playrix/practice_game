#pragma once
#include "EquipableItem.h"
class Weapon :
	public EquipableItem
{
private:
	int _damage;
public:
	Weapon(std::string name, unsigned int type, int x, int y, int damage);
	~Weapon();

	const int GetDamageValue();
	const int GetArmorValue();

	Weapon* Clone();
	const std::string toString() const;
};

