#include "HealthPotion.h"

HealthPotion::HealthPotion(std::string name, unsigned int subType, int x, int y, int heal):ConsumableItem(name,item_types::CONSUMABLE,subType,x,y)
{
	this->_heal = heal;
}

HealthPotion::~HealthPotion()
{
}

const int HealthPotion::GetHealthValue()
{
	return this->_heal;
}

const int HealthPotion::GetPoisonValue()
{
	return 0;
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
