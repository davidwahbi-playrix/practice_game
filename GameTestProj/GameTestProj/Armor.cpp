#include "Armor.h"

Armor::Armor(std::string name, unsigned int subType, int armor) :EquipableItem(name, item_types::EQUIPABLE, subType, 0, 0, 0)
{
	_armor = armor;
	_startArmor = armor;
}

Armor::Armor(std::string name, unsigned int subType, int x, int y, int armor, int startArmor, int battleCnt) :EquipableItem(name,item_types::EQUIPABLE, subType, x, y, battleCnt)
{
	_armor = armor;
	_startArmor = startArmor;
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
	return _armor;
}

const int Armor::GetStartArmorValue() const
{
	return _startArmor;
}

void Armor::SetArmorValue(const int value)
{
	_armor = value;
}

void Armor::SetStartArmor(const int value)
{
	_startArmor = value;
}

Armor* Armor::Clone()
{
	return new Armor(*this);
} 

const std::string Armor::toString() const
{
	std::stringstream ss;
	ss << "Armor: " << GetName() << " | Type: " << GetTypeAsString() << " | SubType: " << GetSubTypeAsString() << " | Armor: " << _armor;
	return ss.str();
}
