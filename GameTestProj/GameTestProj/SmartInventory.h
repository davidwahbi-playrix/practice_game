#pragma once
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

	void AddSmartItem(std::shared_ptr<Item> item);
	void RemoveSmartItem(const unsigned index);
	void ClearSmartInventory();

	unsigned int GetItemIndex(const int x, const int y) const;
	const unsigned int& Size() const;

	std::shared_ptr<Item>& AtSmart(const unsigned int index);

	template <typename T>
	T SmartReplace(const unsigned index, const T& item);

	std::vector<std::shared_ptr<Item>> GetVector() const;

	void operator = (const SmartInventory& other);
	std::shared_ptr<Item>& operator[](const unsigned int index);
	std::string toString() const;

private:
	std::vector<std::shared_ptr<Item>> _smartItems;
};

