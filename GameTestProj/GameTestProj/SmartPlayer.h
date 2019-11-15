#pragma once
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
	void MoveObject2(int vertical, int horizontal, Board& board);

	void SetSmartInventory(const SmartInventory& inventory);

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

	int GetEquipInd() const;
	int GetStartDamage() const;

	SmartInventory& GetSmartInventory();
	SmartInventory GetSmartInventory2() const;
	const std::string& GetName() const;
	std::shared_ptr<Weapon> GetSmartWeapon() const;
	Weapon& GetSmartWeapon2();
	std::shared_ptr<Armor> GetSmartArmor() const;
	Armor& GetSmartArmor2();
	const int GetDefence() const;

	void AddDamage(int value);
	void AddDefence(int value);
	void AddHealth(int value);
	void SetSmartWeapon(std::shared_ptr<Weapon> smartWeapon);
	void SetSmartArmor(std::shared_ptr<Armor> smartArmor);

	void UpdatePlayerInventory2(SmartInventory& gameInventory);
	void UpdateSmartPlayerInventory(SmartInventory& smartGameInventory);

	void EquipSmartItem(const int index);
	void UpdateSmartPlayerWeapon();

	const std::string toString() const;
private:
	std::string _playerName;
	SmartInventory _smartInventory;
	bool _itemPickedFlag;
	bool _enemyEncounter;
	bool _canEquip;
	bool _equipAction;
	bool _repairEntered;
	int _equipInd;
	int _defence;
	int _startDamage;
	std::shared_ptr<Weapon> _smartWeapon;
	std::shared_ptr<Armor> _smartArmor;
};
