#pragma once
#include "ConsumableItem.h"
class HealthPotion :
	public ConsumableItem
{
public:
	HealthPotion(std::string name, unsigned int subType, int heal);
	HealthPotion(std::string name, unsigned int subType, int x, int y, int heal);
	~HealthPotion();

	const int GetHealthValue() const;
	const int GetPoisonValue() const;

	HealthPotion* Clone();
	std::shared_ptr<Item> SmartClone() override;
	const std::string toString() const;
private:
	int _heal;
};

