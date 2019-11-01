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
	//this->_smartItems = std::vector<std::shared_ptr<Item>>(this->_cap);
	this->Init();

	for (size_t i = 0; i < this->_numOfItems; i++)
	//for (size_t i = 0; i < other.GetVector().size(); i++)
	{
		this->_items[i] = other._items[i]->Clone();
		//this->_smartItems.emplace_back(other.GetVector().at(i));
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

/*void Inventory::AddSmartItem(std::shared_ptr<Item>& item)
{
	std::shared_ptr<Item> tmpItem = std::make_shared<Item>(item);
	//this->_smartItems[this->_numOfItems++] = tmpItem;
	this->_smartItems.emplace_back(tmpItem);
}*/

void Inventory::RemoveItem(const unsigned index)
{
	if (index < 0 || index >= this->_numOfItems)
	{
		cout << "OUT OF BOUNDS!" << endl;
	}
	delete this->_items[index];
	this->_items[index] = this->_items[--this->_numOfItems];
}

/*void Inventory::RemoveSmartItem(const unsigned index)
{
	if (index < 0 || index >= this->_smartItems.size())
	{
		cout << "OUT OF BOUNDS!" << endl;
	}
	this->_smartItems.erase(this->_smartItems.begin() + index);
}*/

void Inventory::ClearInventory()
{
	for (size_t i = 0; i < this->_numOfItems; i++)
	{
		delete this->_items[i];
	}
	this->_numOfItems = 0;
}

/*void Inventory::ClearSmartInventory()
{
	this->_smartItems.clear();
} */

/*const unsigned int& Inventory::Capacity() const
{
	return this->_cap;
} */

const unsigned int& Inventory::Size() const
{
	return this->_numOfItems;
}

/*std::vector<std::shared_ptr<Item>> Inventory::GetVector() const
{
	return this->_smartItems;
} */

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
/*std::shared_ptr<Item>& Inventory::AtSmart(const unsigned int index)
{
	if (index < 0 || index >= this->_smartItems.size())
	{
		cout << "OUT OF BOUNDS!" << endl;
	}
	else
	{
		return this->_smartItems[index];
	}
} */


void Inventory::operator=(const Inventory& other)
{
	if (this != &other) {
		for (size_t i = 0; i < this->_numOfItems; i++)
		{
			delete this->_items[i];
		}
		delete[] this->_items;
		//this->_smartItems.clear();

		this->_cap = other._cap;
		this->_numOfItems = other._numOfItems;
		this->_items = new Item * [this->_cap];
		this->Init();

		for (size_t i = 0; i < this->_numOfItems; i++)
		{
			this->_items[i] = other._items[i]->Clone();
		}
		/*for (size_t i = 0; i < other.GetVector().size(); i++)
		{
			this->_smartItems.emplace_back(other.GetVector().at(i));
		}*/
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

/*std::shared_ptr<Item> Inventory::SmartReplace(const unsigned index, std::shared_ptr<Item> item)
{
	if (index < 0 || index >= this->_smartItems.size())
	{
		cout << "OUT OF BOUNDS!" << endl;
	}
	std::shared_ptr<Item> tmp_item = this->_smartItems[index];
	if (item)
	{
		this->_smartItems[index] = item;
	}
	else
	{
		this->_smartItems.erase(this->_smartItems.begin() + index);
	}
	return tmp_item;
} */

unsigned int Inventory::GetItemIndex(const int x, const int y) const
{
	int index = -1;
	for (size_t i = 0; i < _numOfItems; i++)
	//for (size_t i = 0; i < _smartItems.size(); i++)
	{
		if (this->_items[i]->GetPosX() == x && this->_items[i]->GetPosY() == y)
		//if (this->_smartItems[i]->GetPosX() == x && this->_smartItems[i]->GetPosY() == y)
		{
			index = i;
		}
	}
	return index;
}

std::string Inventory::toString() const
{	
	std::stringstream ss;

	for (size_t i = 0; i < this->_numOfItems; i++)
	//for (size_t i = 0; i < this->_smartItems.size(); i++)
	{
		ss << i << ": " << this->_items[i]->toString() << " " << "\n";
		//ss << i << ": " << this->_smartItems[i]->toString() << " " << "\n";
	}

	return ss.str();
}
