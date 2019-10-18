#pragma once
#include "EquipableItem.h"
class Armor :
	public EquipableItem
{
private:
	int _armor;
public:
	Armor(std::string name,unsigned int subType, int x, int y, int armor);
	~Armor();

	const int GetDamageValue();
	const int GetArmorValue();

	Armor* Clone();
	const std::string toString() const;
};

