#include "EquipableItem.h"

EquipableItem::EquipableItem(std::string name,unsigned int type, unsigned int subType, int x, int y, int battleCnt) :Item(name, item_types::EQUIPABLE, subType, x, y)
{
	this->_battleCnt = battleCnt;
}

EquipableItem::~EquipableItem()
{
}

int EquipableItem::GetBattleCnt() const
{
	return this->_battleCnt;
}

void EquipableItem::IncreseBattleCnt()
{
	this->_battleCnt++;
}

void EquipableItem::ResetBattleCnt()
{
	this->_battleCnt = 0;
}

void EquipableItem::SetBattleCnt(const int value)
{
	this->_battleCnt = value;
}
