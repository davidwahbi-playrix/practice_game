#pragma once
#include "Item.h"
class EquipableItem :
	public Item
{
private:
	unsigned int _eqType;
	int _battleCnt;
public:
	EquipableItem(std::string name,unsigned int type, unsigned int subType, int x, int y, int battleCnt);
	~EquipableItem();

	int GetBattleCnt() const;

	void IncreseBattleCnt();
	void ResetBattleCnt();
	void SetBattleCnt(const int value);

	virtual const int GetDamageValue() const = 0;
	virtual const int GetArmorValue() const = 0;
};

