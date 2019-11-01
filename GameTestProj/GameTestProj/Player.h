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
	//void SetSmartInventory(const Inventory& inventory);

	void SetBoard(const Board& board);
	void SetPickedFlag(const bool& flag);
	void SetEnemyFlag(const bool& flag);
	void SetName(const std::string& name);
	void SetDefence(const int defence);

	void SetCanEquip(const bool& value);
	void SetEquipAction(const bool& value);
	void SetEquipInd(const int value);

	bool GetPickedFlag() const;
	bool GetEnemyFlag() const;
	bool GetCanEquip() const;
	bool GetEquipAction() const;

	int GetEquipInd() const;

	Inventory& GetInventory();
	Inventory& GetSmartInventory();
	Board GetBoard() const;
	const std::string& GetName() const;
	Weapon* GetWeapon() const;
	//std::shared_ptr<Weapon> GetSmartWeapon() const;
	Armor* GetArmor() const;
	//std::shared_ptr<Armor> GetSmartArmor() const;
	const int GetDefence() const;

	void AddDamage(int value);
	void AddDefence(int value);
	void AddHealth(int value);
	void SetWeapon(Weapon* weapon);
	//void SetSmartWeapon(std::shared_ptr<Weapon> smartWeapon);
	void SetArmor(Armor* armor);
	//void SetSmartArmor(std::shared_ptr<Armor> smartArmor);

	Inventory UpdatePlayerInventory(Inventory gameInventory);
	Inventory UpdateSmartPlayerInventory(Inventory smartGameInventory);

	void EquipItem(const int index);
	//void EquipSmartItem(const int index);

	const std::string toString() const;
private:
	std::string _playerName;
	Board _playerBoard;
	Inventory _inventory;
	Inventory _smartInventory;
	bool _itemPickedFlag;
	bool _enemyEncounter;
	bool _canEquip;
	bool _equipAction;
	int _equipInd;
	int _defence;
	Weapon* _weapon;
	std::shared_ptr<Weapon> _smartWeapon;
	Armor* _armor;
	std::shared_ptr<Armor> _smartArmor;
};

