#include "Item.h"

void Item::Generate()
{
}

Item::Item(std::string name, unsigned int type, int x, int y)
{
	this->_name = name;
	this->_type = type;
	this->_posX = x;
	this->_posY = y;
}

Item::~Item()
{

}

const std::string& Item::GetName()
{
	return this->_name;
}

const unsigned int& Item::GetType()
{
	return this->_type;
}

const std::string Item::toString() const
{
	std::stringstream ss;

	ss << "Name: " << this->_name << "| Type: " << this->_type << "\n";

	return ss.str();
}
