#pragma once
#include "MovableObject.h"
#include <string>
#include "Board.h"
#include "Inventory.h"
#include "Weapon.h"

class Player : public MovableObject
{
private:
	std::string _playerName;
	Board _playerBoard;
	Inventory _inventory;
	bool _itemPickedFlag;
	int _health;
	int _damage;
	int _armor;
public:
	Player();
	~Player();
	Player( const int x, const int y, int health, int damage, int armor, std::string name, Board board);
	void MoveObject(int vertical, int horizontal);
	Inventory& GetInventory();
	void SetInventory(Inventory inventory);
	void SetBoard(Board board);
	void SetPickedFlag(bool flag);

	bool GetPickedFlag();
	Board GetBoard();
	const std::string& GetName() const;

	void AddDamage(int value);
	void AddArmor(int value);
	void AddHealth(int value);
	const std::string toString() const;
};

