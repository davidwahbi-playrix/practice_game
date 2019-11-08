/*#include "SmartPlayer.h"

SmartPlayer::SmartPlayer()
{
	_itemPickedFlag = false;
	_enemyEncounter = false;
	_canEquip = false;
	_equipAction = false;
	_defence = 0;
	_equipInd = 0;
}

SmartPlayer::SmartPlayer(const int x, const int y, int health, int damage, int defence, std::string name) : Unit(x, y, health, damage)
{
	_playerName = name;
	_defence = defence;
	_itemPickedFlag = false;
	_enemyEncounter = false;
	_canEquip = false;
	_equipAction = false;
	_equipInd = 0;
}

SmartPlayer::~SmartPlayer()
{
}

Board SmartPlayer::MoveObject(int vertical, int horizontal, Board board)
{
	int x = GetPosX();
	int x2 = x + horizontal;

	int y = GetPosY();
	int y2 = y + vertical;

	char nextElem1 = board.GetElem(x2, y);
	char nextElem2 = board.GetElem(x, y2);

	if (nextElem1 == ' ') {
		board.SetElem(x, y, ' ');
		x += horizontal;
		SetPosX(x);
		board.SetElem(x, y, '@');
	}

	if (nextElem2 == ' ') {
		board.SetElem(x, y, ' ');
		y += vertical;
		SetPosY(y);
		board.SetElem(x, y, '@');
	}

	if (nextElem1 == 'i') {
		board.SetElem(x, y, ' ');
		x += horizontal;
		SetPosX(x);
		board.SetElem(x, y, '@');
		_itemPickedFlag = true;

	}

	if (nextElem2 == 'i') {
		board.SetElem(x, y, ' ');
		y += vertical;
		SetPosY(y);
		board.SetElem(x, y, '@');
		_itemPickedFlag = true;
	}
	if (nextElem1 == 'e') {
		board.SetElem(x, y, ' ');
		x += horizontal;
		SetPosX(x);
		board.SetElem(x, y, '@');
		_enemyEncounter = true;

	}

	if (nextElem2 == 'e') {
		board.SetElem(x, y, ' ');
		y += vertical;
		SetPosY(y);
		board.SetElem(x, y, '@');
		_enemyEncounter = true;
	}

	return board;
}

void SmartPlayer::SetSmartInventory(const SmartInventory& inventory)
{
	_smartInventory = inventory;
}

void SmartPlayer::SetPickedFlag(const bool& flag)
{
	_itemPickedFlag = flag;
}

void SmartPlayer::SetEnemyFlag(const bool& flag)
{
	_enemyEncounter = flag;
}

void SmartPlayer::SetName(const std::string& name)
{
	_playerName = name;
}

void SmartPlayer::SetDefence(const int defence)
{
	_defence = defence;
}

void SmartPlayer::SetCanEquip(const bool& value)
{
	_canEquip = value;
}

void SmartPlayer::SetEquipAction(const bool& value)
{
	_equipAction = value;
}

void SmartPlayer::SetEquipInd(const int value)
{
	_equipInd = value;
}

SmartInventory& SmartPlayer::GetSmartInventory()
{
	return _smartInventory;
}

bool SmartPlayer::GetPickedFlag() const
{
	return _itemPickedFlag;
}

bool SmartPlayer::GetEnemyFlag() const
{
	return _enemyEncounter;
}

bool SmartPlayer::GetCanEquip() const
{
	return _canEquip;
}

bool SmartPlayer::GetEquipAction() const
{
	return _equipAction;
}

int SmartPlayer::GetEquipInd() const
{
	return _equipInd;
}

const std::string& SmartPlayer::GetName() const
{
	return _playerName;
}

std::shared_ptr<Weapon> SmartPlayer::GetSmartWeapon() const
{
	return _smartWeapon;
}

std::shared_ptr<Armor> SmartPlayer::GetSmartArmor() const
{
	return _smartArmor;
}

const int SmartPlayer::GetDefence() const
{
	return _defence;
}

void SmartPlayer::AddDamage(int value)
{
	int damage = 0;
	if (GetSmartWeapon() != nullptr)
	{
		damage = GetDamage() + value - GetSmartWeapon()->GetDamageValue();
	}
	else
	{
		damage = GetDamage() + value;
	}

	SetDamage(damage);
}

void SmartPlayer::AddDefence(int value)
{
	int defence = 0;
	if (GetSmartArmor() != nullptr)
	{
		defence = GetDefence() + value - GetSmartArmor()->GetArmorValue();
	}
	else
	{
		defence = GetDefence() + value;
	}
	SetDefence(defence);
}

void SmartPlayer::AddHealth(int value)
{
	int health = GetHealth() + value;
	SetHealth(health);
}

void SmartPlayer::SetSmartWeapon(std::shared_ptr<Weapon> smartWeapon)
{
	_smartWeapon = smartWeapon;
}

void SmartPlayer::SetSmartArmor(std::shared_ptr<Armor> smartArmor)
{
	_smartArmor = smartArmor;
}

SmartInventory SmartPlayer::UpdatePlayerInventory(SmartInventory gameInventory)
{
	SetPickedFlag(false);
	SmartInventory tmp = GetSmartInventory();
	int index = gameInventory.GetItemIndex(GetPosX(), GetPosY());
	if (index >= 0)
	{
		tmp.AddSmartItem(gameInventory[index]);
		SetSmartInventory(tmp);
		gameInventory.RemoveSmartItem(index);
		_canEquip = true;
		return gameInventory;
	}
}

SmartInventory SmartPlayer::UpdateSmartPlayerInventory(SmartInventory smartGameInventory)
{
	SetPickedFlag(false);
	SmartInventory tmp = GetSmartInventory();
	int index = smartGameInventory.GetItemIndex(GetPosX(), GetPosY());
	if (index >= 0)
	{
		tmp.AddSmartItem(smartGameInventory[index]);
		SetSmartInventory(tmp);
		smartGameInventory.RemoveSmartItem(index);
		_canEquip = true;
		return smartGameInventory;
	}
}
void SmartPlayer::EquipSmartItem(const int index)
{
	std::shared_ptr<Item> tmp_i = std::make_shared<Item>(&GetSmartInventory().AtSmart(index));
	std::shared_ptr<Weapon> tmp_w = std::dynamic_pointer_cast<Weapon>(tmp_i);
	std::shared_ptr<Armor> tmp_a = std::dynamic_pointer_cast<Armor>(tmp_i);
	std::shared_ptr<HealthPotion> tmp_p = std::dynamic_pointer_cast<HealthPotion>(tmp_i);

	if (tmp_w)
	{
		tmp_w = std::static_pointer_cast<Weapon>(GetSmartInventory().SmartReplace(index, GetSmartWeapon()));
		AddDamage(tmp_w->GetDamageValue());
		SetSmartWeapon(tmp_w);

	}
	else if (tmp_a)
	{
		tmp_a = std::static_pointer_cast<Armor>(GetSmartInventory().SmartReplace(index, GetSmartArmor()));
		AddDefence(tmp_a->GetArmorValue());
		SetSmartArmor(tmp_a);
	}
	else if (tmp_p)
	{
		AddHealth(tmp_p->GetHealthValue());
		GetSmartInventory().RemoveSmartItem(index);
	}
	if (GetSmartInventory().GetVector().size() > 0) {
		SetCanEquip(true);
	}
}
const std::string SmartPlayer::toString() const
{
	std::stringstream ss;
	ss << "Player: " << GetName() << " | Health: " << GetHealth() << " | Damage: " << GetDamage() << " | Armor: " << _defence;
	return ss.str();
}*/
