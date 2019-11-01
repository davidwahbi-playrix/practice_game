#include "Player.h"

Player::Player()
{
	this->_itemPickedFlag = false;
	this->_enemyEncounter = false;
	this->_canEquip = false;
	this->_equipAction = false;
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
	this->_equipAction = false;
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

void Player::SetInventory(const Inventory& inventory)
{
	this->_inventory = inventory;
}

/*void Player::SetSmartInventory(const Inventory& inventory)
{
	this->_smartInventory = inventory;
} */

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

void Player::SetCanEquip(const bool& value)
{
	this->_canEquip = value;
}

void Player::SetEquipAction(const bool& value)
{
	this->_equipAction = value;
}

void Player::SetEquipInd(const int value)
{
	this->_equipInd = value;
}

Board Player::GetBoard() const
{
	return this->_playerBoard;
}

Inventory& Player::GetInventory()
{
	return this->_inventory;
}

Inventory& Player::GetSmartInventory()
{
	return this->_smartInventory;
}

bool Player::GetPickedFlag() const
{
	return this->_itemPickedFlag;
}

bool Player::GetEnemyFlag() const
{
	return this->_enemyEncounter;
}

bool Player::GetCanEquip() const
{
	return this->_canEquip;
}

bool Player::GetEquipAction() const
{
	return this->_equipAction;
}

unsigned int Player::GetEquipInd() const
{
	return _equipInd;
}

const std::string& Player::GetName() const
{
	return this->_playerName;
}

Weapon* Player::GetWeapon() const
{
	return this->_weapon;
}

/*std::shared_ptr<Weapon> Player::GetSmartWeapon() const
{
	return this->_smartWeapon;
} */

Armor* Player::GetArmor() const
{
	return this->_armor;
}

/*std::shared_ptr<Armor> Player::GetSmartArmor() const
{
	return this->_smartArmor;
} */

const int Player::GetDefence() const
{
	return this->_defence;
}

void Player::AddDamage(int value)
{
	int damage = 0;
	if (this->GetWeapon() != nullptr)
	{
		damage = this->GetDamage() + value - this->GetWeapon()->GetDamageValue();
	}
	else
	{
		damage = this->GetDamage() + value;
	}
	
	this->SetDamage(damage);
}

void Player::AddDefence(int value)
{
	int defence = 0;
	if (this->GetArmor() != nullptr)
	{
		defence = this->GetDefence() + value - this->GetArmor()->GetArmorValue();
	}
	else
	{
		defence = this->GetDefence() + value;
	}
	this->SetDefence(defence);
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

/*void Player::SetSmartWeapon(std::shared_ptr<Weapon> smartWeapon)
{
	this->_smartWeapon = smartWeapon;
} */

void Player::SetArmor(Armor* armor)
{
	this->_armor = armor;
}

/*void Player::SetSmartArmor(std::shared_ptr<Armor> smartArmor)
{
	this->_smartArmor = smartArmor;
} */

Inventory Player::UpdatePlayerInventory(Inventory gameInventory)
{
	this->SetPickedFlag(false);
	Inventory tmp = this->GetInventory();
	int index = gameInventory.GetItemIndex(this->GetPosX(), this->GetPosY());
	if (index >= 0)
	{
		tmp.AddItem(gameInventory[index]);
		//tmp.AddSmartItem(gameInventory.GetVector()[index]);
		SetInventory(tmp);
		gameInventory.RemoveItem(index);
		//gameInventory.RemoveSmartItem(index);
		this->_canEquip = true;
		return gameInventory;
	}
}

Inventory Player::UpdateSmartPlayerInventory(Inventory smartGameInventory)
{
	this->SetPickedFlag(false);
	Inventory tmp = this->GetInventory();
	int index = smartGameInventory.GetItemIndex(this->GetPosX(), this->GetPosY());
	if (index >= 0)
	{
		tmp.AddItem(smartGameInventory[index]);
		//tmp.AddSmartItem(smartGameInventory.GetVector()[index]);
		SetInventory(tmp);
		//SetSmartInventory(tmp);
		smartGameInventory.RemoveItem(index);
		//smartGameInventory.RemoveSmartItem(index);
		this->_canEquip = true;
		return smartGameInventory;
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
		this->AddDamage(tmp_w->GetDamageValue());
		this->SetWeapon(tmp_w);

	}
	else if (tmp_a)
	{
		tmp_a = static_cast<Armor*>(this->GetInventory().Replace(index, this->GetArmor()));
		this->AddDefence(tmp_a->GetArmorValue());
		this->SetArmor(tmp_a);
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
/*void Player::EquipSmartItem(const int index)
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
} */
const std::string Player::toString() const
{
	std::stringstream ss;
	ss << "Player: " << this->GetName() << " | Health: " << this->GetHealth() << " | Damage: " << this->GetDamage() <<  " | Armor: " << this->_defence;
	return ss.str();
}

Player::~Player()
{
}
