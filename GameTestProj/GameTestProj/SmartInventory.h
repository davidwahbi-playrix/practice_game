/*#pragma once
#include <vector>
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "HealthPotion.h"
class SmartInventory
{
public:
	SmartInventory();
	SmartInventory(const SmartInventory& other);
	~SmartInventory();

	void AddSmartItem(std::shared_ptr<Item>& item);
	void RemoveSmartItem(const unsigned index);
	void ClearSmartInventory();

	unsigned int GetItemIndex(const int x, const int y) const;

	std::shared_ptr<Item>& AtSmart(const unsigned int index);

	std::shared_ptr<Item> SmartReplace(const unsigned index, std::shared_ptr<Item> item);

	std::vector<std::shared_ptr<Item>> GetVector() const;

	void operator = (const SmartInventory& other);
	std::shared_ptr<Item>& operator[](const unsigned int index);
	std::string toString() const;

private:
	std::vector<std::shared_ptr<Item>> _smartItems;
};*/

