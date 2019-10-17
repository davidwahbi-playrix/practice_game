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

const std::string& Item::GetName() const
{
	return this->_name;
}

const unsigned int& Item::GetType() const
{
	return this->_type;
}

int Item::GetPosX() const
{
	return _posX;
}

int Item::GetPosY() const
{
	return _posY;
}
