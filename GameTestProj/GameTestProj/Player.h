#pragma once
#include "MovableObject.h"
#include <string>
#include "Board.h"
#include "Inventory.h"

class Player : public MovableObject
{
private:
	std::string _playerName;
	Board _playerBoard;
	Inventory _inventory;
	bool _itemPickedFlag;
	int _defence;
	Weapon* _weapon;
	Armor* _armor;

public:
	Player();
	~Player();
	Player( const int x, const int y, int health, int damage, int defence, std::string name, Board board);
	void MoveObject(int vertical, int horizontal);
	Inventory& GetInventory();
	void SetInventory(Inventory inventory);
	void SetBoard(Board board);
	void SetPickedFlag(bool flag);

	bool GetPickedFlag();
	Board GetBoard();
	const std::string& GetName() const;
	Weapon* GetWeapon();
	Armor* GetArmor();

	void AddDamage(int value);
	void AddDefence(int value);
	void AddHealth(int value);
	void SetWeapon(Weapon* weapon);
	void SetArmor(Armor* armor);
	const std::string toString();
};

