#pragma once
#include "Item.h"
class EquipableItem :
	public Item
{
private:
public:
	EquipableItem(std::string name, unsigned int type, int x, int y);
	~EquipableItem();

	virtual const int GetDamageValue() = 0;
	virtual const int GetArmorValue() = 0;
};

