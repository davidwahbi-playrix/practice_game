#pragma once
#include <string>
#include <sstream>
enum item_types {EQUIPABLE = 0, CONSUMABLE};
class Item
{
private:
	std::string _name;
	unsigned int _type;
	int _posX;
	int _posY;
	void Generate();
public:
	Item(std::string name, unsigned int type, int x, int y);
	~Item();

	const std::string& GetName();
	const unsigned int& GetType();

	const std::string toString() const;
};

