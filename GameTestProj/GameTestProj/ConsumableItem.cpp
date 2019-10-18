#include "ConsumableItem.h"

ConsumableItem::ConsumableItem(std::string name, unsigned int type, unsigned int subType, int x, int y):Item(name, item_types::CONSUMABLE, subType, x, y)
{
}

ConsumableItem::~ConsumableItem()
{
}
