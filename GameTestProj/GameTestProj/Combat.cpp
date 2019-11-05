#include "Combat.h"

Combat::Combat()
{
	this->_continue = true;
}

Combat::~Combat()
{
}

void Combat::SmartBattle(Player player, std::shared_ptr<Enemy> smartEnemy)
{
	if (player.GetEnemyFlag())
	{
		player.SetEnemyFlag(false);
	}
	else
	{
		smartEnemy->SetPlayerEncounter(false);
	}
	bool exit = false;
	std::cout << "Battle started!" << '\n';
	while (!exit)
	{
		int tmpPlayerHP = player.GetHealth();
		int tmpEnemyHP = smartEnemy->GetHealth();
		int tmpPlayerDamage = player.GetDamage();
		int tmpEnemyDamage = smartEnemy->GetDamage();
		int tmpPlayerDefence = player.GetDefence();
		if (tmpPlayerHP + tmpPlayerDefence - tmpEnemyDamage > 0)
		{
			int tmpDamage = tmpPlayerDefence - tmpEnemyDamage;
			if (tmpDamage < 0)
			{
				player.SetDefence(0);
				player.SetHealth(tmpPlayerHP + tmpDamage);
			}
			else
			{
				player.SetDefence(tmpDamage);
			}
			std::cout << "Enemy Attacks!" << '\n';
			std::cout << player.toString() << '\n';
			if (tmpEnemyHP - tmpPlayerDamage > 0)
			{
				smartEnemy->SetHealth(tmpEnemyHP - tmpPlayerDamage);
				std::cout << "Player Attacks!" << '\n';
				std::cout << smartEnemy->toString() << '\n';
				system("pause");
			}
			else
			{
				std::cout << "Enemy KILLED!" << '\n';
				exit = true;
				int drop = rand() % 100 + 1;
				if (drop <= smartEnemy->GetDropChance())
				{
					int type = rand() % 3;
					switch (type)
					{
					case 0:
						std::cout << "Enemy dropped a wepon!" << '\n';
						player.GetInventory().AddItem(Weapon("Spear", WEAPON, 8));
						player.SetCanEquip(true);
						break;
					case 1:
						std::cout << "Enemy dropped an aromor!" << '\n';
						player.GetInventory().AddItem(Armor("Vest", ARMOR, 5));
						player.SetCanEquip(true);
						break;
					case 2:
						std::cout << "Enemy dropped a potion!" << '\n';
						player.GetInventory().AddItem(HealthPotion("Spirit", HEAL, 15));
						player.SetCanEquip(true);
						break;
					default:
						break;
					}
				}
				if (player.GetWeapon())
				{
					player.IncreseBattleCnt();
					player.UpdatePlayerWeapon();
				}
				system("pause");
				system("cls");
				smartEnemy = nullptr;
			}
		}
		else {
			system("cls");
			std::cout << "GAME OVER!" << '\n';
			std::cout << "You are Dead!" << '\n';
			this->_continue = false;
			exit = true;
			system("pause");
		}
	}
	if (player.GetArmor() && player.GetDefence() == 0)
	{
		Armor* tmpArmor = player.GetArmor();
		tmpArmor->SetArmorValue(0);
		player.SetArmor(tmpArmor);
	}
	this->_player = player;
	this->_smartEnemy = smartEnemy;
}

void Combat::SetContinue(const bool & value)
{
	this->_continue = value;
}

bool Combat::GetContinue() const
{
	return this->_continue;
}

Player Combat::GetPlayer() const
{
	return this->_player;
}

std::shared_ptr<Enemy> Combat::GetSmartEnemy()
{
	return this->_smartEnemy;
}
