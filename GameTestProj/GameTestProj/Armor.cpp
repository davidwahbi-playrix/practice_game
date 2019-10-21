#include "Armor.h"

Armor::Armor(std::string name, unsigned int subType, int x, int y, int armor) :EquipableItem(name,item_types::EQUIPABLE, subType, x, y)
{
	this->_armor = armor;
}

Armor::~Armor()
{
}

const int Armor::GetDamageValue()
{
	return 0;
}

const int Armor::GetArmorValue()
{
	return this->_armor;
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