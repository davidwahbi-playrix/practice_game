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

Inventory::Inventory(const Inventory* other)
{
	this->_cap = other->_cap;
	this->_numOfItems = other->_numOfItems;

	this->_items = new Item * [this->_cap];
	this->Init();

	for (size_t i = 0; i < this->_numOfItems; i++)
	{
		this->_items[i] = new Item(*other->_items[i]);
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

void Inventory::AddItem(const Item& item)
{
	if (this->_numOfItems >= this->_cap)
	{
		this->Expand();
	}

	this->_items[this->_numOfItems++] = new Item(item);
}

void Inventory::RemoveItem(const unsigned index)
{

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
	if (index < 0 || index > this->_numOfItems)
	{
		cout << "OUT OF BOUNDS!" << endl;
	}
	else
	{
		return *(this->_items[index]);
	}
}

Item& Inventory::operator[](const unsigned int index)
{
	if (index < 0 || index > this->_numOfItems)
	{
		cout << "OUT OF BOUNDS!" << endl;
	}
	else
	{
		return *(this->_items[index]);
	}
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
