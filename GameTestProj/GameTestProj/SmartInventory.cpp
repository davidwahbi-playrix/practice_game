#include "SmartInventory.h"
#include <iostream>

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

void SmartInventory::AddSmartItem(std::shared_ptr<Item> item)
{
	_smartItems.emplace_back(item);
}

void SmartInventory::RemoveSmartItem(const unsigned index)
{
	if (index < 0 || index >= _smartItems.size())
	{
		std::cout << "OUT OF BOUNDS!" << std::endl;
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

const unsigned int & SmartInventory::Size() const
{
	return _smartItems.size();
}

std::shared_ptr<Item>& SmartInventory::AtSmart(const unsigned int index)
{
	if (index < 0 || index >= _smartItems.size())
	{
		std::cout << "OUT OF BOUNDS!" << std::endl;
	}
	else
	{
		return _smartItems[index];
	}
}

template <typename T>
T SmartInventory::SmartReplace(const unsigned index, const T& item)
{
	if (index < 0 || index >= _smartItems.size())
	{
		std::cout << "OUT OF BOUNDS!" << std::endl;
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
		std::cout << "OUT OF BOUNDS!" << std::endl;
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
}