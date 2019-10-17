#pragma once
#include "Item.h"
#include <string>
#include <sstream>
class Inventory
{
private:
	Item** _items;
	unsigned int _cap;
	unsigned int _numOfItems;

	void Init(const unsigned from=0);
	void Expand();
public:
	Inventory(unsigned int cap=10);
	Inventory(const Inventory& other);
	~Inventory();

	void AddItem(Item& item);
	void RemoveItem(const unsigned index);

	const unsigned int& Capacity() const;
	const unsigned int& Size() const;
	Item& At(const unsigned int index);

	void operator = (const Inventory& other);
	Item& operator[](const unsigned int index);
	std::string toString() const;
};

