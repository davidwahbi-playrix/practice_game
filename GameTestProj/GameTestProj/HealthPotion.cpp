#include "HealthPotion.h"

HealthPotion::HealthPotion(std::string name, unsigned int subType, int heal) :ConsumableItem(name, item_types::CONSUMABLE, subType, 0, 0)
{
	this->_heal = heal;
	this->_startCap = heal;
}

HealthPotion::HealthPotion(std::string name, unsigned int subType, int x, int y, int heal):ConsumableItem(name,item_types::CONSUMABLE,subType,x,y)
{
	this->_heal = heal;
	this->_startCap = heal;
}

HealthPotion::~HealthPotion()
{
}

const int HealthPotion::GetHealthValue() const
{
	return this->_heal;
}

const int HealthPotion::GetPoisonValue() const
{
	return 0;
}

const int HealthPotion::GetHealCap() const
{
	return this->_startCap;
}

void HealthPotion::SetStartCap(const int value)
{
	this->_startCap = value;
}

HealthPotion* HealthPotion::Clone()
{
	return new HealthPotion(*this);
}

const std::string HealthPotion::toString() const
{
	std::stringstream ss;
	ss << "Health potion: " << this->GetName() << " | Type: " << this->GetTypeAsString() << " | SubType: " << this->GetSubTypeAsString() << " | Heal value: " << this->_heal;
	return ss.str();
}
