#include "Combat.h"

Combat::Combat()
{
}

Combat::~Combat()
{
}

void Combat::SmartBattle(Player player, std::shared_ptr<Enemy> smartEnemy)
{
	player.SetEnemyFlag(false);
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
			else {
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
						break;
					case 1:
						std::cout << "Enemy dropped an aromor!" << '\n';
						player.GetInventory().AddItem(Armor("Vest", ARMOR, 5));
						break;
					case 2:
						std::cout << "Enemy dropped a potion!" << '\n';
						player.GetInventory().AddItem(HealthPotion("Spirit", HEAL, 15));
						break;
					default:
						break;
					}
				}
				system("pause");
				system("cls");
				smartEnemy = nullptr;
			}
		}
		else {
			std::cout << "You are DEAD!" << '\n';
			exit = true;
			system("pause");
			system("cls");
		}
	}
	this->_player = player;
	this->_smartEnemy = smartEnemy;
}

Player Combat::GetPlayer() const
{
	return this->_player;
}

std::shared_ptr<Enemy> Combat::GetSmartEnemy()
{
	return this->_smartEnemy;
}
