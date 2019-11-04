/*#include "SmartPlayer.h"

SmartPlayer::SmartPlayer()
{
	this->_itemPickedFlag = false;
	this->_enemyEncounter = false;
	this->_canEquip = false;
	this->_equipAction = false;
	this->_defence = 0;
	this->_equipInd = 0;
}

SmartPlayer::SmartPlayer(const int x, const int y, int health, int damage, int defence, std::string name) : Unit(x, y, health, damage)
{
	this->_playerName = name;
	this->_defence = defence;
	this->_itemPickedFlag = false;
	this->_enemyEncounter = false;
	this->_canEquip = false;
	this->_equipAction = false;
	this->_equipInd = 0;
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
		this->SetPosX(x);
		board.SetElem(x, y, '@');
	}

	if (nextElem2 == ' ') {
		board.SetElem(x, y, ' ');
		y += vertical;
		this->SetPosY(y);
		board.SetElem(x, y, '@');
	}

	if (nextElem1 == 'i') {
		board.SetElem(x, y, ' ');
		x += horizontal;
		this->SetPosX(x);
		board.SetElem(x, y, '@');
		this->_itemPickedFlag = true;

	}

	if (nextElem2 == 'i') {
		board.SetElem(x, y, ' ');
		y += vertical;
		this->SetPosY(y);
		board.SetElem(x, y, '@');
		this->_itemPickedFlag = true;
	}
	if (nextElem1 == 'e') {
		board.SetElem(x, y, ' ');
		x += horizontal;
		this->SetPosX(x);
		board.SetElem(x, y, '@');
		this->_enemyEncounter = true;

	}

	if (nextElem2 == 'e') {
		board.SetElem(x, y, ' ');
		y += vertical;
		this->SetPosY(y);
		board.SetElem(x, y, '@');
		this->_enemyEncounter = true;
	}

	return this->board;
}

void SmartPlayer::SetSmartInventory(const SmartInventory& inventory)
{
	this->_smartInventory = inventory;
}

void SmartPlayer::SetPickedFlag(const bool& flag)
{
	this->_itemPickedFlag = flag;
}

void SmartPlayer::SetEnemyFlag(const bool& flag)
{
	this->_enemyEncounter = flag;
}

void SmartPlayer::SetName(const std::string& name)
{
	this->_playerName = name;
}

void SmartPlayer::SetDefence(const int defence)
{
	this->_defence = defence;
}

void SmartPlayer::SetCanEquip(const bool& value)
{
	this->_canEquip = value;
}

void SmartPlayer::SetEquipAction(const bool& value)
{
	this->_equipAction = value;
}

void SmartPlayer::SetEquipInd(const int value)
{
	this->_equipInd = value;
}

SmartInventory& SmartPlayer::GetSmartInventory()
{
	return this->_smartInventory;
}

bool SmartPlayer::GetPickedFlag() const
{
	return this->_itemPickedFlag;
}

bool SmartPlayer::GetEnemyFlag() const
{
	return this->_enemyEncounter;
}

bool SmartPlayer::GetCanEquip() const
{
	return this->_canEquip;
}

bool SmartPlayer::GetEquipAction() const
{
	return this->_equipAction;
}

int SmartPlayer::GetEquipInd() const
{
	return _equipInd;
}

const std::string& SmartPlayer::GetName() const
{
	return this->_playerName;
}

std::shared_ptr<Weapon> SmartPlayer::GetSmartWeapon() const
{
	return this->_smartWeapon;
}

std::shared_ptr<Armor> SmartPlayer::GetSmartArmor() const
{
	return this->_smartArmor;
}

const int SmartPlayer::GetDefence() const
{
	return this->_defence;
}

void SmartPlayer::AddDamage(int value)
{
	int damage = 0;
	if (this->GetSmartWeapon() != nullptr)
	{
		damage = this->GetDamage() + value - this->GetSmartWeapon()->GetDamageValue();
	}
	else
	{
		damage = this->GetDamage() + value;
	}

	this->SetDamage(damage);
}

void SmartPlayer::AddDefence(int value)
{
	int defence = 0;
	if (this->GetSmartArmor() != nullptr)
	{
		defence = this->GetDefence() + value - this->GetSmartArmor()->GetArmorValue();
	}
	else
	{
		defence = this->GetDefence() + value;
	}
	this->SetDefence(defence);
}

void SmartPlayer::AddHealth(int value)
{
	int health = this->GetHealth() + value;
	this->SetHealth(health);
}

void SmartPlayer::SetSmartWeapon(std::shared_ptr<Weapon> smartWeapon)
{
	this->_smartWeapon = smartWeapon;
}

void SmartPlayer::SetSmartArmor(std::shared_ptr<Armor> smartArmor)
{
	this->_smartArmor = smartArmor;
}

SmartInventory SmartPlayer::UpdatePlayerInventory(SmartInventory gameInventory)
{
	this->SetPickedFlag(false);
	SmartInventory tmp = this->GetSmartInventory();
	int index = gameInventory.GetItemIndex(this->GetPosX(), this->GetPosY());
	if (index >= 0)
	{
		tmp.AddSmartItem(gameInventory[index]);
		SetSmartInventory(tmp);
		gameInventory.RemoveSmartItem(index);
		this->_canEquip = true;
		return gameInventory;
	}
}

SmartInventory SmartPlayer::UpdateSmartPlayerInventory(SmartInventory smartGameInventory)
{
	this->SetPickedFlag(false);
	SmartInventory tmp = this->GetSmartInventory();
	int index = smartGameInventory.GetItemIndex(this->GetPosX(), this->GetPosY());
	if (index >= 0)
	{
		tmp.AddSmartItem(smartGameInventory[index]);
		SetSmartInventory(tmp);
		smartGameInventory.RemoveSmartItem(index);
		this->_canEquip = true;
		return smartGameInventory;
	}
}
void SmartPlayer::EquipSmartItem(const int index)
{
	std::shared_ptr<Item> tmp_i = std::make_shared<Item>(&this->GetSmartInventory().AtSmart(index));
	std::shared_ptr<Weapon> tmp_w = std::dynamic_pointer_cast<Weapon>(tmp_i);
	std::shared_ptr<Armor> tmp_a = std::dynamic_pointer_cast<Armor>(tmp_i);
	std::shared_ptr<HealthPotion> tmp_p = std::dynamic_pointer_cast<HealthPotion>(tmp_i);

	if (tmp_w)
	{
		tmp_w = std::static_pointer_cast<Weapon>(this->GetSmartInventory().SmartReplace(index, this->GetSmartWeapon()));
		this->AddDamage(tmp_w->GetDamageValue());
		this->SetSmartWeapon(tmp_w);

	}
	else if (tmp_a)
	{
		tmp_a = std::static_pointer_cast<Armor>(this->GetSmartInventory().SmartReplace(index, this->GetSmartArmor()));
		this->AddDefence(tmp_a->GetArmorValue());
		this->SetSmartArmor(tmp_a);
	}
	else if (tmp_p)
	{
		this->AddHealth(tmp_p->GetHealthValue());
		this->GetSmartInventory().RemoveSmartItem(index);
	}
	if (this->GetSmartInventory().GetVector().size() > 0) {
		this->SetCanEquip(true);
	}
}
const std::string SmartPlayer::toString() const
{
	std::stringstream ss;
	ss << "Player: " << this->GetName() << " | Health: " << this->GetHealth() << " | Damage: " << this->GetDamage() << " | Armor: " << this->_defence;
	return ss.str();
}*/
