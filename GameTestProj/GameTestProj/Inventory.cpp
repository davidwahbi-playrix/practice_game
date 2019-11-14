#include "Inventory.h"
#include <iostream>

using namespace std;

void Inventory::Init(const unsigned from)
{
	for (size_t i = 0; i < _cap; i++)
	{
		_items[i] = nullptr;
	} 
}

void Inventory::Expand()
{
	_cap *= 2;

	Item** temp = new Item * [_cap];

	for (size_t i = 0; i < _numOfItems; i++)
	{
		temp[i] = _items[i];
	}
	delete[] _items;

	_items = temp;

	Init(_numOfItems);
}

Inventory::Inventory(unsigned int cap)
{
	_cap = cap;
	_numOfItems = 0;
	_items = new Item * [cap];

	Init();
}

Inventory::Inventory(const Inventory& other)
{
	_cap = other._cap;
	_numOfItems = other._numOfItems;

	_items = new Item * [_cap];
	Init();

	for (size_t i = 0; i < _numOfItems; i++)
	{
		_items[i] = other._items[i]->Clone();
	}
}

Inventory::~Inventory()
{
	for (size_t i = 0; i < _numOfItems; i++)
	{
		delete _items[i];
	}

	delete [] _items;
} 

void Inventory::AddItem( Item& item)
{
	if (_numOfItems >= _cap)
	{
		Expand();
	}

	_items[_numOfItems++] = item.Clone();
}

void Inventory::RemoveItem(const unsigned index)
{
	if (index < 0 || index >= _numOfItems)
	{
		cout << "OUT OF BOUNDS!" << endl;
	}
	delete _items[index];
	_items[index] = _items[--_numOfItems];
}

void Inventory::ClearInventory()
{
	for (size_t i = 0; i < _numOfItems; i++)
	{
		delete _items[i];
	}
	_numOfItems = 0;
}

const unsigned int& Inventory::Capacity() const
{
	return _cap;
}

const unsigned int& Inventory::Size() const
{
	return _numOfItems;
}

Item& Inventory::At(const size_t index)
{
	if (index < 0 || index >= _numOfItems)
	{
		cout << "OUT OF BOUNDS!" << endl;
	}
	else
	{
		return *(_items[index]);
	}
}

void Inventory::operator=(const Inventory& other)
{
	if (this != &other) {
		for (size_t i = 0; i < _numOfItems; i++)
		{
			delete _items[i];
		}
		delete[] _items;

		_cap = other._cap;
		_numOfItems = other._numOfItems;
		_items = new Item * [_cap];
		Init();

		for (size_t i = 0; i < _numOfItems; i++)
		{
			_items[i] = other._items[i]->Clone();
		}
	}

}

Item& Inventory::operator[](const unsigned int index)
{
	if (index < 0 || index >= _numOfItems)
	{
		cout << "OUT OF BOUNDS!" << endl;
	}
	else
	{
		return *(_items[index]);
	}
} 

Item* Inventory::Replace(const unsigned index, Item* item)
{
	if (index < 0 || index >= _numOfItems)
	{
		cout << "OUT OF BOUNDS!" << endl;
	}
	Item* tmp_item = _items[index]->Clone();
	delete _items[index];
	if (item)
	{
		_items[index] = item->Clone();
	}
	else 
	{
		_items[index] = _items[--_numOfItems];
	}
	return tmp_item;
}

unsigned int Inventory::GetItemIndex(const int x, const int y) const
{
	unsigned int index = -1;
	for (unsigned int i = 0; i < _numOfItems; i++)
	{
		if (_items[i]->GetPosX() == x && _items[i]->GetPosY() == y)
		{
			index = i;
		}
	}
	return index;
}

std::string Inventory::toString() const
{	
	std::stringstream ss;

	for (size_t i = 0; i < _numOfItems; i++)
	{
		ss << i << ": " << _items[i]->toString() << " " << "\n";
	}

	return ss.str();
}
