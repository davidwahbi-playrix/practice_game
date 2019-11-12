#include "Player.h"

Player::Player()
{
	_itemPickedFlag = false;
	_enemyEncounter = false;
	_canEquip = false;
	_equipAction = false;
	_repairEntered = false;
	_defence = 0;
	_equipInd = 0;
	_weapon = nullptr;
	_armor = nullptr;
	_startDamage = 0;
}
Player::~Player()
{
}

Player::Player(const int x, const int y, int health, int damage, int defence, std::string name) : Unit(x, y, health, damage)
{
	_playerName = name;
	_defence = defence;
	_itemPickedFlag = false;
	_enemyEncounter = false;
	_canEquip = false;
	_equipAction = false;
	_repairEntered = false;
	_equipInd = 0;
	_weapon = nullptr;
	_armor = nullptr;
	_startDamage = damage;
}

void Player::MoveObject2(int vertical, int horizontal, Board & board)
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

void Player::SetInventory(const Inventory& inventory)
{
	_inventory = inventory;
}

/*void Player::SetSmartInventory(const Inventory& inventory)
{
	_smartInventory = inventory;
} */

void Player::SetPickedFlag(const bool& flag)
{
	_itemPickedFlag = flag;
}

void Player::SetEnemyFlag(const bool& flag)
{
	_enemyEncounter = flag;
}

void Player::SetName(const std::string& name)
{
	_playerName = name;
}

void Player::SetDefence(const int defence)
{
	_defence = defence;
}

void Player::SetStartDamage(const int value)
{
	_startDamage = value;
}

void Player::SetCanEquip(const bool& value)
{
	_canEquip = value;
}

void Player::SetEquipAction(const bool& value)
{
	_equipAction = value;
}

void Player::SetEquipInd(const int value)
{
	_equipInd = value;
}

void Player::SetRepairEntered(const bool & value)
{
	_repairEntered = value;
}

void Player::ReceiveHit(const int enemyDamage)
{
	if (GetDefence() - enemyDamage < 0)
	{
		SetDefence(0);
		if (GetArmor())
		{
			GetArmor2().SetArmorValue(0);
		}
		SetHealth(GetHealth() + GetDefence() - enemyDamage);
	}
	else
	{
		SetDefence(GetDefence() - enemyDamage);
	}
}

bool Player::CanBattle(const int enemyDamage) const
{
	return (GetHealth() + GetDefence() - enemyDamage > 0);
}

Inventory& Player::GetInventory()
{
	return _inventory;
}

Inventory& Player::GetSmartInventory()
{
	return _smartInventory;
}

bool Player::GetPickedFlag() const
{
	return _itemPickedFlag;
}

bool Player::GetEnemyFlag() const
{
	return _enemyEncounter;
}

bool Player::GetCanEquip() const
{
	return _canEquip;
}

bool Player::GetEquipAction() const
{
	return _equipAction;
}

bool Player::GetRepairEntered() const
{
	return _repairEntered;
}

unsigned int Player::GetEquipInd() const
{
	return _equipInd;
}

int Player::GetStartDamage() const
{
	return _startDamage;
}

const std::string& Player::GetName() const
{
	return _playerName;
}

Weapon* Player::GetWeapon() const
{
	return _weapon;
}

Weapon & Player::GetWeapon2()
{
	// TODO: insert return statement here
	return *(_weapon);
}

/*std::shared_ptr<Weapon> Player::GetSmartWeapon() const
{
	return _smartWeapon;
} */

Armor* Player::GetArmor() const
{
	return _armor;
}

Armor & Player::GetArmor2()
{
	// TODO: insert return statement here
	return *(_armor);
}

/*std::shared_ptr<Armor> Player::GetSmartArmor() const
{
	return _smartArmor;
} */

const int Player::GetDefence() const
{
	return _defence;
}

void Player::AddDamage(int value)
{
	int damage = 0;
	if (GetWeapon() != nullptr)
	{
		damage = GetDamage() + value - GetWeapon()->GetDamageValue();
	}
	else
	{
		damage = GetDamage() + value;
	}
	
	SetDamage(damage);
}

void Player::AddDefence(int value)
{
	int defence = 0;
	if (GetArmor() != nullptr)
	{
		defence = value;
	}
	else
	{
		defence = GetDefence() + value;
	}
	SetDefence(defence);
}

void Player::AddHealth(int value)
{
	int health = GetHealth() + value;
	SetHealth(health);
}

void Player::SetWeapon(Weapon* weapon)
{
	_weapon = weapon;
}

/*void Player::SetSmartWeapon(std::shared_ptr<Weapon> smartWeapon)
{
	_smartWeapon = smartWeapon;
} */

void Player::SetArmor(Armor* armor)
{
	_armor = armor;
}

/*void Player::SetSmartArmor(std::shared_ptr<Armor> smartArmor)
{
	_smartArmor = smartArmor;
} */

Inventory Player::UpdatePlayerInventory(Inventory gameInventory)
{
	SetPickedFlag(false);
	Inventory tmp = GetInventory();
	int index = gameInventory.GetItemIndex(GetPosX(), GetPosY());
	if (index >= 0)
	{
		tmp.AddItem(gameInventory[index]);
		//tmp.AddSmartItem(gameInventory.GetVector()[index]);
		SetInventory(tmp);
		gameInventory.RemoveItem(index);
		//gameInventory.RemoveSmartItem(index);
		_canEquip = true;
		return gameInventory;
	}
}

void Player::UpdatePlayerInventory2(Inventory & gameInventory)
{
	SetPickedFlag(false);
	int index = gameInventory.GetItemIndex(GetPosX(), GetPosY());
	if (index >= 0)
	{
		_inventory.AddItem(gameInventory[index]);
		gameInventory.RemoveItem(index);
		_canEquip = true;
	}
}

Inventory Player::UpdateSmartPlayerInventory(Inventory smartGameInventory)
{
	SetPickedFlag(false);
	Inventory tmp = GetInventory();
	int index = smartGameInventory.GetItemIndex(GetPosX(), GetPosY());
	if (index >= 0)
	{
		tmp.AddItem(smartGameInventory[index]);
		//tmp.AddSmartItem(smartGameInventory.GetVector()[index]);
		SetInventory(tmp);
		//SetSmartInventory(tmp);
		smartGameInventory.RemoveItem(index);
		//smartGameInventory.RemoveSmartItem(index);
		_canEquip = true;
		return smartGameInventory;
	}
}

void Player::UpdatePlayerWeapon()
{
	if (_weapon->CheckIfDamaged())
	{
		int tmpValue = 0;
		if (GetWeapon2().GetDamageValue() > GetWeapon2().GetMinDamageValue())
		{
			tmpValue = GetWeapon2().GetDamageValue() - GetWeapon2().GetDecreseValue();
		}
		GetWeapon2().SetDamageValue(tmpValue);
		SetDamage(GetWeapon2().GetDamageValue() + GetStartDamage());
	}
}

void Player::EquipItem(const int index)
{
	Weapon* tmp_w = dynamic_cast<Weapon*>(&GetInventory().At(index));
	Armor* tmp_a = dynamic_cast<Armor*>(&GetInventory().At(index));
	HealthPotion* tmp_p = dynamic_cast<HealthPotion*>(&GetInventory().At(index));

	if (tmp_w)
	{
		tmp_w = static_cast<Weapon*>(GetInventory().Replace(index, GetWeapon()));
		AddDamage(tmp_w->GetDamageValue());
		SetWeapon(tmp_w);

	}
	else if (tmp_a)
	{
		tmp_a = static_cast<Armor*>(GetInventory().Replace(index, GetArmor()));
		AddDefence(tmp_a->GetArmorValue());
		SetArmor(tmp_a);
	}
	else if (tmp_p)
	{
		AddHealth(tmp_p->GetHealthValue());
		GetInventory().RemoveItem(index);
	}
	if (GetInventory().Size() > 0) {
		SetCanEquip(true);
	}
}
/*void Player::EquipSmartItem(const int index)
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
} */
const std::string Player::toString() const
{
	std::stringstream ss;
	ss << "Player: " << GetName() << " | Health: " << GetHealth() << " | Damage: " << GetDamage() <<  " | Armor: " << _defence;
	return ss.str();
}
