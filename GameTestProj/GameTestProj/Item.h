#pragma once
#include <string>
#include <sstream>
enum item_types {EQUIPABLE = 0, CONSUMABLE};
enum sub_item_types { ARMOR = 0, WEAPON , HEAL, POISON};
class Item
{
private:
	std::string _name;
	unsigned int _type;
	unsigned int _subType;
	int _posX;
	int _posY;
	void Generate();
public:
	Item(std::string name, unsigned int type, unsigned int subType, int x, int y);
	~Item();

	const std::string& GetName() const;
	const unsigned int& GetType() const;
	const unsigned int& GetSubType() const;
	const std::string GetTypeAsString() const;
	const std::string GetSubTypeAsString() const;
	int GetPosX() const;
	int GetPosY() const;

	virtual Item* Clone() = 0;
	virtual const std::string toString() const = 0;
};

