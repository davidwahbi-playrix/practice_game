#include "EquipableItem.h"

EquipableItem::EquipableItem(std::string name,unsigned int type, unsigned int subType, int x, int y) :Item(name, item_types::EQUIPABLE, subType, x, y)
{
}

EquipableItem::~EquipableItem()
{
}