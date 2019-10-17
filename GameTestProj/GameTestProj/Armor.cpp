#include "Armor.h"

Armor::Armor(std::string name, unsigned int type, int x, int y, int armor) :EquipableItem(name, 0, x, y)
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
	ss << "Armor: " << this->GetName() << " | Type: " << this->GetType() << " | Armor: " << this->_armor;
	return ss.str();
}
