#pragma once
#include "Item.h"
#include <string>
#include <sstream>
#include "Weapon.h"
#include "Armor.h"
#include "HealthPotion.h"
#include <memory>
#include <vector>
class Inventory
{
public:
	Inventory(unsigned int cap = 10);
	//Inventory();
	Inventory(const Inventory& other);
	~Inventory();

	void AddItem(Item& item);
	//void AddSmartItem(std::shared_ptr<Item>& item);

	void RemoveItem(const unsigned index);
	//void RemoveSmartItem(const unsigned index);

	void ClearInventory();
	//void ClearSmartInventory();

	const unsigned int& Capacity() const;
	const unsigned int& Size() const;
	//std::vector<std::shared_ptr<Item>> GetVector() const;

	Item& At(const unsigned int index);
	//std::shared_ptr<Item>& AtSmart(const unsigned int index);

	void operator = (const Inventory& other);
	Item& operator[](const unsigned int index);

	Item* Replace(const unsigned index, Item* item);
	//std::shared_ptr<Item> SmartReplace(const unsigned index, std::shared_ptr<Item> item);

	unsigned int GetItemIndex(const int x, const int y) const;
	std::string toString() const;
private:
	Item** _items;
	//std::vector<std::shared_ptr<Item>> _smartItems;
	unsigned int _cap;
	unsigned int _numOfItems;

	void Init(const unsigned from=0);
	void Expand();
};

