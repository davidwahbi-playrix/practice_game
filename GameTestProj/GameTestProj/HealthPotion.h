#pragma once
#include "ConsumableItem.h"
class HealthPotion :
	public ConsumableItem
{
private:
	int _heal;
public:
	HealthPotion(std::string name, unsigned int subType, int heal);
	HealthPotion(std::string name, unsigned int subType, int x, int y, int heal);
	~HealthPotion();

	const int GetHealthValue() const;
	const int GetPoisonValue() const;

	HealthPotion* Clone();
	const std::string toString() const;
};

