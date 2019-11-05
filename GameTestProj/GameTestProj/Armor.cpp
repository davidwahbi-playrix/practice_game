#include "Armor.h"

Armor::Armor(std::string name, unsigned int subType, int armor) :EquipableItem(name, item_types::EQUIPABLE, subType, 0, 0)
{
	this->_armor = armor;
}

Armor::Armor(std::string name, unsigned int subType, int x, int y, int armor) :EquipableItem(name,item_types::EQUIPABLE, subType, x, y)
{
	this->_armor = armor;
}

Armor::~Armor()
{
}

const int Armor::GetDamageValue() const
{
	return 0;
}

const int Armor::GetArmorValue() const
{
	return this->_armor;
}

void Armor::SetArmorValue(const int value)
{
	this->_armor = value;
}

Armor* Armor::Clone()
{
	return new Armor(*this);
} 

const std::string Armor::toString() const
{
	std::stringstream ss;
	ss << "Armor: " << this->GetName() << " | Type: " << this->GetTypeAsString() << " | SubType: " << this->GetSubTypeAsString() << " | Armor: " << this->_armor;
	return ss.str();
}
