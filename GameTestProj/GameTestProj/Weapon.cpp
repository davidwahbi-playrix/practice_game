#include "Weapon.h"

Weapon::Weapon(std::string name, unsigned int subType, int damage):EquipableItem(name, item_types::EQUIPABLE,subType,0,0)
{
	this->_damage = damage;
}

Weapon::Weapon(std::string name, unsigned int subType, int x, int y, int damage):EquipableItem(name,item_types::EQUIPABLE, subType,x,y)
{
	this->_damage = damage;
}

Weapon::~Weapon()
{
}

const int Weapon::GetDamageValue()
{
	return this->_damage;
}

const int Weapon::GetArmorValue()
{
	return 0;
}

Weapon* Weapon::Clone()
{
	return new Weapon(*this);
}

const std::string Weapon::toString() const
{
	std::stringstream ss;
	ss << "Weapon: " << this->GetName() << " | Type: " << this->GetTypeAsString() << " | SubType: " << this->GetSubTypeAsString() << " | Damage: " << this->_damage;
	return ss.str();
}
