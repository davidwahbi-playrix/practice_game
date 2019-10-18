#pragma once
#include "ConsumableItem.h"
class HealthPotion :
	public ConsumableItem
{
private:
	int _heal;
public:
	HealthPotion(std::string name, unsigned int subType, int x, int y, int heal);
	~HealthPotion();

	const int GetHealthValue();
	const int GetPoisonValue();

	HealthPotion* Clone();
	const std::string toString() const;
};

