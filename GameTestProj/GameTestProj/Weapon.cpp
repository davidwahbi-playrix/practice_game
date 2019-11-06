#include "Weapon.h"

Weapon::Weapon(std::string name, unsigned int subType, int damage):EquipableItem(name, item_types::EQUIPABLE,subType,0,0)
{
	this->_damage = damage;
	this->_startDamage = damage;
}

Weapon::Weapon(std::string name, unsigned int subType, int x, int y, int damage):EquipableItem(name,item_types::EQUIPABLE, subType,x,y)
{
	this->_damage = damage;
	this->_startDamage = damage;
}

Weapon::~Weapon()
{
}

const int Weapon::GetDamageValue() const
{
	return this->_damage;
}

const int Weapon::GetArmorValue() const
{
	return 0;
}

const int Weapon::GetStartDamageValue() const
{
	return this->_startDamage;
}

void Weapon::SetDamageValue(const int value)
{
	this->_damage = value;
}

void Weapon::SetStartDamage(const int value)
{
	this->_startDamage = value;
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
