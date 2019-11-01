#pragma once
#include "EquipableItem.h"
class Weapon :
	public EquipableItem
{
public:
	Weapon(std::string name, unsigned int subType, int damage);
	Weapon(std::string name, unsigned int subType, int x, int y, int damage);
	~Weapon();

	const int GetDamageValue() const;
	const int GetArmorValue() const;

	Weapon* Clone();
	std::shared_ptr<Item> SmartClone() override;
	const std::string toString() const;
private:
	int _damage;

};

