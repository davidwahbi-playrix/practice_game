#pragma once
#include "EquipableItem.h"
class Armor :
	public EquipableItem
{
public:
	Armor(std::string name, unsigned int subType, int armor);
	Armor(std::string name, unsigned int subType, int x, int y, int armor);
	~Armor();

	const int GetDamageValue() const;
	const int GetArmorValue() const;

	const int GetStartArmorValue() const;

	void SetArmorValue(const int value);

	Armor* Clone();
	const std::string toString() const;
private:
	int _armor;
	int _startArmor;
};

