#include "Weapon.h"

Weapon::Weapon(std::string name, unsigned int subType, int damage):EquipableItem(name, item_types::EQUIPABLE,subType,0,0,0)
{
	_damage = damage;
	_startDamage = damage;
}

Weapon::Weapon(std::string name, unsigned int subType, int x, int y, int damage, int startDamage, int battleCnt):EquipableItem(name,item_types::EQUIPABLE, subType,x,y, battleCnt)
{
	_damage = damage;
	_startDamage = startDamage;
}

Weapon::~Weapon()
{
}

const int Weapon::GetDamageValue() const
{
	return _damage;
}

const int Weapon::GetArmorValue() const
{
	return 0;
}

const int Weapon::GetStartDamageValue() const
{
	return _startDamage;
}

const int Weapon::GetDecreseValue() const
{
	return _decreseValue;
}

const int Weapon::GetMinDamageValue() const
{
	return _minDamageValue;
}

void Weapon::SetDamageValue(const int value)
{
	_damage = value;
}

void Weapon::SetStartDamage(const int value)
{
	_startDamage = value;
}

Weapon* Weapon::Clone()
{
	return new Weapon(*this);
} 

const std::string Weapon::toString() const
{
	std::stringstream ss;
	ss << "Weapon: " << GetName() << " | Type: " << GetTypeAsString() << " | SubType: " << GetSubTypeAsString() << " | Damage: " << _damage;
	return ss.str();
}

bool Weapon::CheckIfDamaged() const
{
	return (GetBattleCnt() > 0 && GetBattleCnt() % 2 == 0);
}
