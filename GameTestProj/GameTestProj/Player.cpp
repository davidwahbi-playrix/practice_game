#include "Player.h"

Player::Player()
{
	this->_itemPickedFlag = false;
	this->_enemyEncounter = false;
	this->_canEquip = false;
	this->_defence = 0;
	this->_equipInd = 0;
	this->_weapon = nullptr;
	this->_armor = nullptr;
}

Player::Player( const int x, const int y, int health, int damage, int defence, std::string name, Board board) : Unit( x, y, health, damage)
{
	this->_playerName = name;
	this->_playerBoard = board;
	this->_defence = defence;
	this->_itemPickedFlag = false;
	this->_enemyEncounter = false;
	this->_canEquip = false;
	this->_equipInd = 0;
	this->_weapon = nullptr;
	this->_armor = nullptr;
}

void Player::MoveObject(int vertical, int horizontal)
{
	int x = GetPosX();
	int x2 = x + horizontal;

	int y = GetPosY();
	int y2 = y + vertical;

	char nextElem1 = _playerBoard.GetElem(x2, y);
	char nextElem2 = _playerBoard.GetElem(x, y2);

	if (nextElem1 == ' ') {
		_playerBoard.SetElem(x, y, ' ');
		x += horizontal;
		SetPosX(x);
		_playerBoard.SetElem(x, y, '@');
	}

	if (nextElem2 == ' ') {
		_playerBoard.SetElem(x, y, ' ');
		y += vertical;
		SetPosY(y);
		_playerBoard.SetElem(x, y, '@');
	}

	if (nextElem1 == 'i') {
		_playerBoard.SetElem(x, y, ' ');
		x += horizontal;
		SetPosX(x);
		_playerBoard.SetElem(x, y, '@');
		_itemPickedFlag = true;

	}

	if (nextElem2 == 'i') {
		_playerBoard.SetElem(x, y, ' ');
		y += vertical;
		SetPosY(y);
		_playerBoard.SetElem(x, y, '@');
		_itemPickedFlag = true;
	}
	if (nextElem1 == 'e') {
		_playerBoard.SetElem(x, y, ' ');
		x += horizontal;
		SetPosX(x);
		_playerBoard.SetElem(x, y, '@');
		_enemyEncounter = true;

	}

	if (nextElem2 == 'e') {
		_playerBoard.SetElem(x, y, ' ');
		y += vertical;
		SetPosY(y);
		_playerBoard.SetElem(x, y, '@');
		_enemyEncounter = true;
	}
}

Board Player::GetBoard()
{
	return this->_playerBoard;
}

Inventory& Player::GetInventory()
{
	return this->_inventory;
}

void Player::SetInventory(const Inventory& inventory)
{
	this->_inventory = inventory;
}

void Player::SetBoard(const Board& board)
{
	this->_playerBoard = board;
}

void Player::SetPickedFlag(const bool& flag)
{
	this->_itemPickedFlag = flag;
}

void Player::SetEnemyFlag(const bool& flag)
{
	this->_enemyEncounter = flag;
}

void Player::SetName(const std::string& name)
{
	this->_playerName = name;
}

void Player::SetDefence(const int defence)
{
	this->_defence = defence;
}

bool Player::GetPickedFlag()
{
	return this->_itemPickedFlag;
}

bool Player::GetEnemyFlag()
{
	return this->_enemyEncounter;
}

bool Player::GetCanEquip() const
{
	return this->_canEquip;
}

int Player::GetEquipInd() const
{
	return _equipInd;
}

void Player::SetCanEquip(const bool& value)
{
	this->_canEquip = value;
}

void Player::SetEquipInd(const int value)
{
	this->_equipInd = value;
}

const std::string& Player::GetName() const
{
	return this->_playerName;
}

Weapon* Player::GetWeapon()
{
	return this->_weapon;
}

Armor* Player::GetArmor()
{
	return this->_armor;
}

const int Player::GetDefence()
{
	return this->_defence;
}

void Player::AddDamage(int value)
{
	int damage = this->GetDamage() + value;
	this->SetDamage(damage);
}

void Player::AddDefence(int value)
{
	this->_defence += value;
}

void Player::AddHealth(int value)
{
	int health = this->GetHealth() + value;
	this->SetHealth(health);
}

void Player::SetWeapon(Weapon* weapon)
{
	this->_weapon = weapon;
}

void Player::SetArmor(Armor* armor)
{
	this->_armor = armor;
}

Inventory Player::UpdatePlayerInventory(Inventory gameInventory)
{
	this->SetPickedFlag(false);
	Inventory tmp = this->GetInventory();
	int index = gameInventory.GetItemIndex(this->GetPosX(), this->GetPosY());
	if (index >= 0)
	{
		tmp.AddItem(gameInventory[index]);
		SetInventory(tmp);
		gameInventory.RemoveItem(index);
		this->_canEquip = true;
		return gameInventory;
	}
}

void Player::EquipItem(const int index)
{
	Weapon* tmp_w = dynamic_cast<Weapon*>(&this->GetInventory().At(index));
	Armor* tmp_a = dynamic_cast<Armor*>(&this->GetInventory().At(index));
	HealthPotion* tmp_p = dynamic_cast<HealthPotion*>(&this->GetInventory().At(index));

	if (tmp_w)
	{
		tmp_w = static_cast<Weapon*>(this->GetInventory().Replace(index, this->GetWeapon()));
		this->SetWeapon(tmp_w);
		this->AddDamage(tmp_w->GetDamageValue());
	}
	else if (tmp_a)
	{
		tmp_a = static_cast<Armor*>(this->GetInventory().Replace(index, this->GetArmor()));
		this->SetArmor(tmp_a);
		this->AddDefence(tmp_a->GetArmorValue());
	}
	else if (tmp_p)
	{
		this->AddHealth(tmp_p->GetHealthValue());
		this->GetInventory().RemoveItem(index);
	}
	if (this->GetInventory().Size() > 0) {
		this->SetCanEquip(true);
	}
}
const std::string Player::toString()
{
	std::stringstream ss;
	ss << "Player: " << this->GetName() << " | Health: " << this->GetHealth() << " | Damage: " << this->GetDamage() <<  " | Armor: " << this->_defence;
	return ss.str();
}

Player::~Player()
{
}
