#include "Armor.h"

Armor::Armor(std::string name, unsigned int subType, int armor) :EquipableItem(name, item_types::EQUIPABLE, subType, 0, 0)
{
	this->_armor = armor;
	this->_startArmor = armor;
}

Armor::Armor(std::string name, unsigned int subType, int x, int y, int armor, int startArmor) :EquipableItem(name,item_types::EQUIPABLE, subType, x, y)
{
	this->_armor = armor;
	this->_startArmor = startArmor;
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

const int Armor::GetStartArmorValue() const
{
	return this->_startArmor;
}

void Armor::SetArmorValue(const int value)
{
	this->_armor = value;
}

void Armor::SetStartArmor(const int value)
{
	this->_startArmor = value;
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
