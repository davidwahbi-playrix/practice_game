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
		_smartItems.emplace_back(other.GetVector().at(i));
	}
}

SmartInventory::~SmartInventory()
{
}

void SmartInventory::AddSmartItem(std::shared_ptr<Item>& item)
{
	std::shared_ptr<Item> tmpItem = std::make_shared<Item>(item);
	_smartItems.emplace_back(tmpItem);
}

void SmartInventory::RemoveSmartItem(const unsigned index)
{
	if (index < 0 || index >= _smartItems.size())
	{
		cout << "OUT OF BOUNDS!" << endl;
	}
	_smartItems.erase(_smartItems.begin() + index);
}

void SmartInventory::ClearSmartInventory()
{
	_smartItems.clear();
}

unsigned int SmartInventory::GetItemIndex(const int x, const int y) const
{
	int index = -1;
	for (size_t i = 0; i < _smartItems.size(); i++)
	{
		if (_smartItems[i]->GetPosX() == x && _smartItems[i]->GetPosY() == y)
		{
			index = i;
		}
	}
	return index;
}

std::shared_ptr<Item>& SmartInventory::AtSmart(const unsigned int index)
{
	if (index < 0 || index >= _smartItems.size())
	{
		cout << "OUT OF BOUNDS!" << endl;
	}
	else
	{
		return _smartItems[index];
	}
}

std::shared_ptr<Item> SmartInventory::SmartReplace(const unsigned index, std::shared_ptr<Item> item)
{
	if (index < 0 || index >= _smartItems.size())
	{
		cout << "OUT OF BOUNDS!" << endl;
	}
	std::shared_ptr<Item> tmp_item = _smartItems[index];
	if (item)
	{
		_smartItems[index] = item;
	}
	else
	{
		_smartItems.erase(_smartItems.begin() + index);
	}
	return tmp_item;
}

std::vector<std::shared_ptr<Item>> SmartInventory::GetVector() const
{
	return _smartItems;
}

void SmartInventory::operator=(const SmartInventory& other)
{
	if (this != &other) {
		_smartItems.clear();
		for (size_t i = 0; i < other.GetVector().size(); i++)
		{
			_smartItems.emplace_back(other.GetVector().at(i));
		}
	}
}

std::shared_ptr<Item>& SmartInventory::operator[](const unsigned int index)
{
	if (index < 0 || index >= _smartItems.size())
	{
		cout << "OUT OF BOUNDS!" << endl;
	}
	else
	{
		return _smartItems[index];
	}
}

std::string SmartInventory::toString() const
{
	std::stringstream ss;

	for (size_t i = 0; i < _smartItems.size(); i++)
	{
		ss << i << ": " << _smartItems[i]->toString() << " " << "\n";
	}

	return ss.str();
} */
