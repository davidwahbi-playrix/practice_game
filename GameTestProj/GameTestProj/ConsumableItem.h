#pragma once
#include "Item.h"
class ConsumableItem :
	public Item
{
private:
public:
	ConsumableItem(std::string name, unsigned int type, int x, int y);
	~ConsumableItem();

	virtual const int GetHealthValue() = 0;
};

