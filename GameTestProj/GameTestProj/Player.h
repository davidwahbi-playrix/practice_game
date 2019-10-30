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


	void SetInventory(const Inventory& inventory);
	void SetBoard(const Board& board);
	void SetPickedFlag(const bool& flag);
	void SetEnemyFlag(const bool& flag);
	void SetName(const std::string& name);
	void SetDefence(const int defence);

	void SetCanEquip(const bool& value);
	void SetEquipInd(const int value);

	bool GetPickedFlag() const;
	bool GetEnemyFlag() const;
	bool GetCanEquip() const;

	int GetEquipInd() const;

	Inventory& GetInventory();
	Board GetBoard() const;
	const std::string& GetName() const;
	Weapon* GetWeapon() const;
	Armor* GetArmor() const;
	const int GetDefence() const;

	void AddDamage(int value);
	void AddDefence(int value);
	void AddHealth(int value);
	void SetWeapon(Weapon* weapon);
	void SetArmor(Armor* armor);

	Inventory UpdatePlayerInventory(Inventory gameInventory);
	void EquipItem(const int index);

	const std::string toString() const;
private:
	std::string _playerName;
	Board _playerBoard;
	Inventory _inventory;
	bool _itemPickedFlag;
	bool _enemyEncounter;
	bool _canEquip;
	int _equipInd;
	int _defence;
	Weapon* _weapon;
	Armor* _armor;
};

