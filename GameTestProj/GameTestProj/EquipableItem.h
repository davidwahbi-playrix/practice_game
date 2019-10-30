#pragma once
#include "Item.h"
class EquipableItem :
	public Item
{
private:
	unsigned int _eqType;
public:
	EquipableItem(std::string name,unsigned int type, unsigned int subType, int x, int y);
	~EquipableItem();

	virtual const int GetDamageValue() const = 0;
	virtual const int GetArmorValue() const = 0;
};

