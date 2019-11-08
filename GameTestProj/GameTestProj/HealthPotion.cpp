#include "HealthPotion.h"

HealthPotion::HealthPotion(std::string name, unsigned int subType, int heal) :ConsumableItem(name, item_types::CONSUMABLE, subType, 0, 0)
{
	_heal = heal;
	_startCap = heal;
}

HealthPotion::HealthPotion(std::string name, unsigned int subType, int x, int y, int heal):ConsumableItem(name,item_types::CONSUMABLE,subType,x,y)
{
	_heal = heal;
	_startCap = heal;
}

HealthPotion::~HealthPotion()
{
}

const int HealthPotion::GetHealthValue() const
{
	return _heal;
}

const int HealthPotion::GetPoisonValue() const
{
	return 0;
}

const int HealthPotion::GetHealCap() const
{
	return _startCap;
}

void HealthPotion::SetStartCap(const int value)
{
	_startCap = value;
}

HealthPotion* HealthPotion::Clone()
{
	return new HealthPotion(*this);
}

const std::string HealthPotion::toString() const
{
	std::stringstream ss;
	ss << "Health potion: " << GetName() << " | Type: " << GetTypeAsString() << " | SubType: " << GetSubTypeAsString() << " | Heal value: " << _heal;
	return ss.str();
}
