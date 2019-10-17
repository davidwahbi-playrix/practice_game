#include "Weapon.h"

Weapon::Weapon(std::string name, unsigned int type, int x, int y, int damage):EquipableItem(name,0,x,y)
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
	ss << "Weapon: " << this->GetName() << " | Type: " << this->GetType() << " | Damage: " << this->_damage;
	return ss.str();
}
