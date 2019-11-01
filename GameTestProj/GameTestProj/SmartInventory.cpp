/*#include "SmartInventory.h"
#include <iostream>

using namespace std;

SmartInventory::SmartInventory()
{
}

SmartInventory::SmartInventory(const SmartInventory& other)
{

	for (size_t i = 0; i < other.GetVector().size(); i++)
	{
		this->_smartItems.emplace_back(other.GetVector().at(i));
	}
}

SmartInventory::~SmartInventory()
{
}

void SmartInventory::AddSmartItem(std::shared_ptr<Item>& item)
{
	std::shared_ptr<Item> tmpItem = std::make_shared<Item>(item);
	this->_smartItems.emplace_back(tmpItem);
}

void SmartInventory::RemoveSmartItem(const unsigned index)
{
	if (index < 0 || index >= this->_smartItems.size())
	{
		cout << "OUT OF BOUNDS!" << endl;
	}
	this->_smartItems.erase(this->_smartItems.begin() + index);
}

void SmartInventory::ClearSmartInventory()
{
	this->_smartItems.clear();
}

unsigned int SmartInventory::GetItemIndex(const int x, const int y) const
{
	int index = -1;
	for (size_t i = 0; i < _smartItems.size(); i++)
	{
		if (this->_smartItems[i]->GetPosX() == x && this->_smartItems[i]->GetPosY() == y)
		{
			index = i;
		}
	}
	return index;
}

std::shared_ptr<Item>& SmartInventory::AtSmart(const unsigned int index)
{
	if (index < 0 || index >= this->_smartItems.size())
	{
		cout << "OUT OF BOUNDS!" << endl;
	}
	else
	{
		return this->_smartItems[index];
	}
}

std::shared_ptr<Item> SmartInventory::SmartReplace(const unsigned index, std::shared_ptr<Item> item)
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
}

std::vector<std::shared_ptr<Item>> SmartInventory::GetVector() const
{
	return this->_smartItems;
}

void SmartInventory::operator=(const SmartInventory& other)
{
	if (this != &other) {
		this->_smartItems.clear();
		for (size_t i = 0; i < other.GetVector().size(); i++)
		{
			this->_smartItems.emplace_back(other.GetVector().at(i));
		}
	}
}

std::shared_ptr<Item>& SmartInventory::operator[](const unsigned int index)
{
	if (index < 0 || index >= this->_smartItems.size())
	{
		cout << "OUT OF BOUNDS!" << endl;
	}
	else
	{
		return this->_smartItems[index];
	}
}

std::string SmartInventory::toString() const
{
	std::stringstream ss;

	for (size_t i = 0; i < this->_smartItems.size(); i++)
	{
		ss << i << ": " << this->_smartItems[i]->toString() << " " << "\n";
	}

	return ss.str();
} */
