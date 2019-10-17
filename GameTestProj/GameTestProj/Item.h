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

	const std::string& GetName() const;
	const unsigned int& GetType() const;
	int GetPosX() const;
	int GetPosY() const;

	virtual Item* Clone() = 0;
	virtual const std::string toString() const = 0;
};

