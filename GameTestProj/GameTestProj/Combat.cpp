#include "Combat.h"

Combat::Combat()
{
}

Combat::~Combat()
{
}

void Combat::Battle(Player player, Enemy* enemy)
{
	player.SetEnemyFlag(false);
	bool exit = false;
	std::cout << "Battle started!" << '\n';
	while (!exit)
	{
		int tmpPlayerHP = player.GetHealth();
		int tmpEnemyHP = enemy->GetHealth();
		int tmpPlayerDamage = player.GetDamage();
		int tmpEnemyDamage = enemy->GetDamage();
		if (tmpPlayerHP - tmpEnemyDamage > 0)
		{
			player.SetHealth(tmpPlayerHP - tmpEnemyDamage);
			std::cout << "Enemy Attacks!" << '\n';
			std::cout << player.toString() << '\n';
			if (tmpEnemyHP - tmpPlayerDamage > 0)
			{
				enemy->SetHealth(tmpEnemyHP - tmpPlayerDamage);
				std::cout << "Player Attacks!" << '\n';
				std::cout << enemy->toString() << '\n';
				system("pause");
			}
			else {
				std::cout << "Enemy KILLED!" << '\n';
				exit = true;
				int drop = rand() % 100 + 1;
				if (drop <= enemy->GetDropChance())
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
				delete enemy;
				enemy = nullptr;
				system("pause");
				system("cls");
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
	this->_enemy = enemy;
}

Player Combat::GetPlayer() const
{
	return this->_player;
}

Enemy* Combat::GetEnemy() const
{
	return this->_enemy;
}
