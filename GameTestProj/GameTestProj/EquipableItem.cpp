#include "EquipableItem.h"

EquipableItem::EquipableItem(std::string name,unsigned int type, unsigned int subType, int x, int y, int battleCnt) :Item(name, item_types::EQUIPABLE, subType, x, y)
{
	_battleCnt = battleCnt;
}

EquipableItem::~EquipableItem()
{
}

int EquipableItem::GetBattleCnt() const
{
	return _battleCnt;
}

void EquipableItem::IncreseBattleCnt()
{
	_battleCnt++;
}

void EquipableItem::ResetBattleCnt()
{
	_battleCnt = 0;
}

void EquipableItem::SetBattleCnt(const int value)
{
	_battleCnt = value;
}
