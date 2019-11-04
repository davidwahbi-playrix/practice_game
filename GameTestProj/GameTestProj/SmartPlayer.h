/*#pragma once
#include "Unit.h"
#include <string>
#include <sstream>
#include <iostream>
#include "Board.h"
#include "SmartInventory.h"
class SmartPlayer : public Unit
{
public:
	SmartPlayer();
	~SmartPlayer();
	SmartPlayer(const int x, const int y, int health, int damage, int defence, std::string name);
	Board MoveObject(int vertical, int horizontal, Board board);

	void SetSmartInventory(const SmartInventory& inventory);

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

	SmartInventory& GetSmartInventory();
	const std::string& GetName() const;
	std::shared_ptr<Weapon> GetSmartWeapon() const;
	std::shared_ptr<Armor> GetSmartArmor() const;
	const int GetDefence() const;

	void AddDamage(int value);
	void AddDefence(int value);
	void AddHealth(int value);
	void SetSmartWeapon(std::shared_ptr<Weapon> smartWeapon);
	void SetSmartArmor(std::shared_ptr<Armor> smartArmor);

	SmartInventory UpdatePlayerInventory(SmartInventory gameInventory);
	SmartInventory UpdateSmartPlayerInventory(SmartInventory smartGameInventory);

	void EquipSmartItem(const int index);

	const std::string toString() const;
private:
	std::string _playerName;
	SmartInventory _smartInventory;
	bool _itemPickedFlag;
	bool _enemyEncounter;
	bool _canEquip;
	bool _equipAction;
	int _equipInd;
	int _defence;
	std::shared_ptr<Item> _smartWeapon;
	std::shared_ptr<Item> _smartArmor;
};*/
