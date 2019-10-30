#pragma once
#include "EquipableItem.h"
class Armor :
	public EquipableItem
{
private:
	int _armor;
public:
	Armor(std::string name, unsigned int subType, int armor);
	Armor(std::string name,unsigned int subType, int x, int y, int armor);
	~Armor();

	const int GetDamageValue() const;
	const int GetArmorValue() const;

	Armor* Clone();
	const std::string toString() const;
};

