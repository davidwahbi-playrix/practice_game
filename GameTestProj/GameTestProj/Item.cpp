#include "Item.h"

void Item::Generate()
{
}

Item::Item(std::string name, unsigned int type, unsigned int subType,  int x, int y)
{
	this->_name = name;
	this->_type = type;
	this->_subType = subType;
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

const unsigned int& Item::GetSubType() const
{
	return this->_subType;
}

const std::string Item::GetTypeAsString() const
{
	std::string typestr = "NONE";
	switch (this->_type)
	{
	case EQUIPABLE:
		typestr = "EQUIPABLE";
		break;
	case CONSUMABLE:
		typestr = "CONSUMABLE";
		break;
	default:
		break;
	}
	return typestr;
}

const std::string Item::GetSubTypeAsString() const
{
	std::string typestr = "NONE";
	switch (this->_subType)
	{
	case ARMOR:
		typestr = "ARMOR";
		break;
	case WEAPON:
		typestr = "WEAPON";
		break;
	case HEAL:
		typestr = "HEAL";
		break;
	case POISON:
		typestr = "POISON";
		break;
	default:
		break;
	}
	return typestr;
}

int Item::GetPosX() const
{
	return _posX;
}

int Item::GetPosY() const
{
	return _posY;
}
