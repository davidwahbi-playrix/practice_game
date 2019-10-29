#pragma once
#include "Unit.h"
#include <string>
#include <sstream>
#include <iostream>
#include "Board.h"
#include "Inventory.h"

class Player : public Unit
{
public:
	Player();
	~Player();
	Player(const int x, const int y, int health, int damage, int defence, std::string name, Board board);
	void MoveObject(int vertical, int horizontal);
	Inventory& GetInventory();
	void SetInventory(const Inventory& inventory);
	void SetBoard(const Board& board);
	void SetPickedFlag(const bool& flag);
	void SetEnemyFlag(const bool& flag);
	void SetName(const std::string& name);
	void SetDefence(const int defence);

	bool GetPickedFlag();
	bool GetEnemyFlag();
	Board GetBoard();
	const std::string& GetName() const;
	Weapon* GetWeapon();
	Armor* GetArmor();
	const int GetDefence();

	void AddDamage(int value);
	void AddDefence(int value);
	void AddHealth(int value);
	void SetWeapon(Weapon* weapon);
	void SetArmor(Armor* armor);
	const std::string toString();
private:
	std::string _playerName;
	Board _playerBoard;
	Inventory _inventory;
	bool _itemPickedFlag;
	bool _enemyEncounter;
	int _defence;
	Weapon* _weapon;
	Armor* _armor;
	/*std::unique_ptr<Weapon> _weapon
	std::unique_ptr*/
};

