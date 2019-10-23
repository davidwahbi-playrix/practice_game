#include "Inventory.h"
#include <iostream>

using namespace std;

void Inventory::Init(const unsigned from)
{
	for (size_t i = 0; i < this->_cap; i++)
	{
		this->_items[i] = nullptr;
	}
}

void Inventory::Expand()
{
	this->_cap *= 2;

	Item** temp = new Item * [this->_cap];

	for (size_t i = 0; i < this->_numOfItems; i++)
	{
		temp[i] = this->_items[i];
	}
	delete[] this->_items;

	this->_items = temp;

	this->Init(this->_numOfItems);
}

Inventory::Inventory(unsigned int cap)
{
	this->_cap = cap;
	this->_numOfItems = 0;
	this->_items = new Item * [cap];

	this->Init();
}

Inventory::Inventory(const Inventory& other)
{
	this->_cap = other._cap;
	this->_numOfItems = other._numOfItems;

	this->_items = new Item * [this->_cap];
	this->Init();

	for (size_t i = 0; i < this->_numOfItems; i++)
	{
		this->_items[i] = other._items[i]->Clone();
	}
}

Inventory::~Inventory()
{
	for (size_t i = 0; i < this->_numOfItems; i++)
	{
		delete this->_items[i];
	}

	delete [] this->_items;
}

void Inventory::AddItem( Item& item)
{
	if (this->_numOfItems >= this->_cap)
	{
		this->Expand();
	}

	this->_items[this->_numOfItems++] = item.Clone();
}

void Inventory::RemoveItem(const unsigned index)
{
	if (index < 0 || index >= this->_numOfItems)
	{
		cout << "OUT OF BOUNDS!" << endl;
	}
	delete this->_items[index];
	this->_items[index] = this->_items[--this->_numOfItems];
}

void Inventory::ClearInventory()
{
	for (size_t i = 0; i < this->_numOfItems; i++)
	{
		delete this->_items[i];
	}
	this->_numOfItems = 0;
}

const unsigned int& Inventory::Capacity() const
{
	return this->_cap;
}

const unsigned int& Inventory::Size() const
{
	return this->_numOfItems;
}

Item& Inventory::At(const unsigned int index)
{
	if (index < 0 || index >= this->_numOfItems)
	{
		cout << "OUT OF BOUNDS!" << endl;
	}
	else
	{
		return *(this->_items[index]);
	}
}

void Inventory::operator=(const Inventory& other)
{
	if (this != &other) {
		for (size_t i = 0; i < this->_numOfItems; i++)
		{
			delete this->_items[i];
		}
		delete[] this->_items;

		this->_cap = other._cap;
		this->_numOfItems = other._numOfItems;
		this->_items = new Item * [this->_cap];
		this->Init();

		for (size_t i = 0; i < this->_numOfItems; i++)
		{
			this->_items[i] = other._items[i]->Clone();
		}
	}

}

Item& Inventory::operator[](const unsigned int index)
{
	if (index < 0 || index >= this->_numOfItems)
	{
		cout << "OUT OF BOUNDS!" << endl;
	}
	else
	{
		return *(this->_items[index]);
	}
}

Item* Inventory::Replace(const unsigned index, Item* item)
{
	if (index < 0 || index >= this->_numOfItems)
	{
		cout << "OUT OF BOUNDS!" << endl;
	}
	Item* tmp_item = this->_items[index]->Clone();
	delete this->_items[index];
	if (item)
	{
		this->_items[index] = item->Clone();
	}
	else 
	{
		this->_items[index] = this->_items[--this->_numOfItems];
	}
	return tmp_item;
}

std::string Inventory::toString() const
{	
	std::stringstream ss;

	for (size_t i = 0; i < this->_numOfItems; i++)
	{
		ss << i << ": " << this->_items[i]->toString() << " " << "\n";
	}

	return ss.str();
}
