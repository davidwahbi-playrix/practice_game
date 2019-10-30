#pragma once
#include "Item.h"
class ConsumableItem :
	public Item
{
private:
public:
	ConsumableItem(std::string name, unsigned int type, unsigned int subType, int x, int y);
	~ConsumableItem();

	virtual const int GetHealthValue() const = 0;
	virtual const int GetPoisonValue() const = 0;
};

