#include "SmartPlayer.h"
#include "SmartPlayer.h"

SmartPlayer::SmartPlayer()
{
	_itemPickedFlag = false;
	_enemyEncounter = false;
	_canEquip = false;
	_equipAction = false;
	_repairEntered = false;
	_defence = 0;
	_equipInd = 0;
	_startDamage = 0;
}

SmartPlayer::SmartPlayer(const int x, const int y, int health, int damage, int defence, std::string name) : Unit(x, y, health, damage)
{
	_playerName = name;
	_defence = defence;
	_itemPickedFlag = false;
	_enemyEncounter = false;
	_canEquip = false;
	_equipAction = false;
	_repairEntered = false;
	_equipInd = 0;
	_startDamage = damage;
}

SmartPlayer::~SmartPlayer()
{
}

void SmartPlayer::MoveObject2(int vertical, int horizontal, Board& board)
{
	int x = GetPosX();
	int x2 = x + horizontal;

	int y = GetPosY();
	int y2 = y + vertical;

	char nextElem1 = board.GetElem3(x2, y);
	char nextElem2 = board.GetElem3(x, y2);

	if (nextElem1 == ' ') {
		board.SetElem3(x, y, ' ');
		x += horizontal;
		SetPosX(x);
		board.SetElem3(x, y, '@');
	}

	if (nextElem2 == ' ') {
		board.SetElem3(x, y, ' ');
		y += vertical;
		SetPosY(y);
		board.SetElem3(x, y, '@');
	}

	if (nextElem1 == 'i') {
		board.SetElem3(x, y, ' ');
		x += horizontal;
		SetPosX(x);
		board.SetElem3(x, y, '@');
		_itemPickedFlag = true;

	}

	if (nextElem2 == 'i') {
		board.SetElem3(x, y, ' ');
		y += vertical;
		SetPosY(y);
		board.SetElem3(x, y, '@');
		_itemPickedFlag = true;
	}
	if (nextElem1 == 'e') {
		board.SetElem3(x, y, ' ');
		x += horizontal;
		SetPosX(x);
		board.SetElem3(x, y, '@');
		_enemyEncounter = true;

	}

	if (nextElem2 == 'e') {
		board.SetElem3(x, y, ' ');
		y += vertical;
		SetPosY(y);
		board.SetElem3(x, y, '@');
		_enemyEncounter = true;
	}

	if (nextElem1 == 'R') {
		_repairEntered = true;
	}

	if (nextElem2 == 'R') {
		_repairEntered = true;
	}
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

void SmartPlayer::SetStartDamage(const int value)
{
	_startDamage = value;
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

void SmartPlayer::SetRepairEntered(const bool & value)
{
	_repairEntered = value;
}

void SmartPlayer::ReceiveHit(const int enemyDamage)
{
	if (GetDefence() - enemyDamage < 0)
	{
		SetDefence(0);
		if (GetSmartArmor())
		{
			GetSmartArmor2().SetArmorValue(0);
		}
		SetHealth(GetHealth() + GetDefence() - enemyDamage);
	}
	else
	{
		SetDefence(GetDefence() - enemyDamage);
	}
}

bool SmartPlayer::CanBattle(const int enemyDamage) const
{
	return (GetHealth() + GetDefence() - enemyDamage > 0);
}

SmartInventory& SmartPlayer::GetSmartInventory()
{
	return _smartInventory;
}

SmartInventory SmartPlayer::GetSmartInventory2() const
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

bool SmartPlayer::GetRepairEntered() const
{
	return _repairEntered;
}

int SmartPlayer::GetEquipInd() const
{
	return _equipInd;
}

int SmartPlayer::GetStartDamage() const
{
	return _startDamage;
}

const std::string& SmartPlayer::GetName() const
{
	return _playerName;
}

std::shared_ptr<Weapon> SmartPlayer::GetSmartWeapon() const
{
	return _smartWeapon;
}

Weapon& SmartPlayer::GetSmartWeapon2()
{
	return *_smartWeapon;
}

std::shared_ptr<Armor> SmartPlayer::GetSmartArmor() const
{
	return _smartArmor;
}

Armor& SmartPlayer::GetSmartArmor2()
{
	return *_smartArmor;
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

void SmartPlayer::UpdatePlayerInventory2(SmartInventory & gameInventory)
{
	SetPickedFlag(false);
	int index = gameInventory.GetItemIndex(GetPosX(), GetPosY());
	if (index >= 0)
	{
		_smartInventory.AddSmartItem(gameInventory[index]);
		gameInventory.RemoveSmartItem(index);
		_canEquip = true;
	}
}

void SmartPlayer::UpdateSmartPlayerInventory(SmartInventory& smartGameInventory)
{
	SetPickedFlag(false);
	int index = smartGameInventory.GetItemIndex(GetPosX(), GetPosY());
	if (index >= 0)
	{
		_smartInventory.AddSmartItem(smartGameInventory[index]);
		smartGameInventory.RemoveSmartItem(index);
		_canEquip = true;
	}
}
void SmartPlayer::EquipSmartItem(const int index)
{
	int type = GetSmartInventory().AtSmart(index)->GetSubType();

	if (type == 0)
	{
		std::shared_ptr<Armor> tmp_a = std::static_pointer_cast<Armor>(GetSmartInventory().AtSmart(index));
		GetSmartInventory().RemoveSmartItem(index);
		if (GetSmartArmor())
		{
			GetSmartInventory().AddSmartItem(GetSmartArmor());
		}
		AddDefence(tmp_a->GetArmorValue());
		SetSmartArmor(tmp_a);
		

	}
	else if (type == 1)
	{
		std::shared_ptr<Weapon> tmp_w = std::static_pointer_cast<Weapon>(GetSmartInventory().AtSmart(index));
		GetSmartInventory().RemoveSmartItem(index);
		if (GetSmartWeapon())
		{
			GetSmartInventory().AddSmartItem(GetSmartWeapon());
		}
		AddDamage(tmp_w->GetDamageValue());
		SetSmartWeapon(tmp_w);
	}
	else if (type == 2)
	{
		std::shared_ptr<HealthPotion> tmp_p = std::static_pointer_cast<HealthPotion>(GetSmartInventory().AtSmart(index));
		AddHealth(tmp_p->GetHealthValue());
		GetSmartInventory().RemoveSmartItem(index);
	}
	if (GetSmartInventory().GetVector().size() > 0) {
		SetCanEquip(true);
	}
}
void SmartPlayer::UpdateSmartPlayerWeapon()
{
	if (_smartWeapon->CheckIfDamaged())
	{
		int tmpValue = 0;
		if (GetSmartWeapon2().GetDamageValue() > GetSmartWeapon2().GetMinDamageValue())
		{
			tmpValue = GetSmartWeapon2().GetDamageValue() - GetSmartWeapon2().GetDecreseValue();
		}
		GetSmartWeapon2().SetDamageValue(tmpValue);
		SetDamage(GetSmartWeapon2().GetDamageValue() + GetStartDamage());
	}
}
const std::string SmartPlayer::toString() const
{
	std::stringstream ss;
	ss << "Player: " << GetName() << " | Health: " << GetHealth() << " | Damage: " << GetDamage() << " | Armor: " << _defence;
	return ss.str();
}
