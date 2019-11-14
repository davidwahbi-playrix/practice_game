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
	Player(const int x, const int y, int health, int damage, int defence, std::string name);
	void MoveObject2(int vertical, int horizontal, Board& board);

	void SetInventory(const Inventory& inventory);

	void SetPickedFlag(const bool& flag);
	void SetEnemyFlag(const bool& flag);
	void SetName(const std::string& name);
	void SetDefence(const int defence);
	void SetStartDamage(const int value);

	void SetCanEquip(const bool& value);
	void SetEquipAction(const bool& value);
	void SetEquipInd(const int value);
	void SetRepairEntered(const bool& value);

	void ReceiveHit(const int enemyDamage);
	bool CanBattle(const int enemyDamage) const;

	bool GetPickedFlag() const;
	bool GetEnemyFlag() const;
	bool GetCanEquip() const;
	bool GetEquipAction() const;
	bool GetRepairEntered() const;

	unsigned int GetEquipInd() const;
	int GetStartDamage() const;

	Inventory& GetInventory();
	const std::string& GetName() const;
	Weapon* GetWeapon() const;
	Weapon& GetWeapon2();

	Armor* GetArmor() const;
	Armor& GetArmor2();

	const int GetDefence() const;

	void AddDamage(int value);
	void AddDefence(int value);
	void AddHealth(int value);
	void SetWeapon(Weapon* weapon);
	void SetArmor(Armor* armor);

	void UpdatePlayerInventory2(Inventory& gameInventory);
	void UpdatePlayerWeapon();

	void EquipItem(const int index);

	const std::string toString() const;
private:
	std::string _playerName;
	Inventory _inventory;
	bool _itemPickedFlag;
	bool _enemyEncounter;
	bool _canEquip;
	bool _equipAction;
	bool _repairEntered;
	unsigned int _equipInd;
	int _defence;
	int _startDamage;
	Weapon* _weapon;
	Armor* _armor;
};

