#include "Combat.h"

Combat::Combat()
{
}

Combat::Combat(Player player, Enemy* enemy)
{
	this->_player = player;
	this->_enemy = enemy;
}

Combat::~Combat()
{
}

void Combat::Battle()
{
	this->_player.SetEnemyFlag(false);
	bool exit = false;
	std::cout << "Battle started!" << '\n';
	while (!exit)
	{
		int tmpPlayerHP = this->_player.GetHealth();
		int tmpEnemyHP = this->_enemy->GetHealth();
		int tmpPlayerDamage = this->_player.GetDamage();
		int tmpEnemyDamage = this->_enemy->GetDamage();
		if (tmpPlayerHP - tmpEnemyDamage > 0)
		{
			this->_player.SetHealth(tmpPlayerHP - tmpEnemyDamage);
			std::cout << "Enemy Attacks!" << '\n';
			std::cout << this->_player.toString() << '\n';
			if (tmpEnemyHP - tmpPlayerDamage > 0)
			{
				this->_enemy->SetHealth(tmpEnemyHP - tmpPlayerDamage);
				std::cout << "Player Attacks!" << '\n';
				std::cout << this->_enemy->toString() << '\n';
				system("pause");
			}
			else {
				std::cout << "Enemy KILLED!" << '\n';
				exit = true;
				int drop = rand() % 100 + 1;
				if (drop <= _enemy->GetDropChance())
				{
					int type = rand() % 3;
					switch (type)
					{
					case 0:
						std::cout << "Enemy dropped a wepon!" << '\n';
						this->_player.GetInventory().AddItem(Weapon("Spear", WEAPON, 8));
						break;
					case 1:
						std::cout << "Enemy dropped an aromor!" << '\n';
						this->_player.GetInventory().AddItem(Armor("Vest", ARMOR, 5));
						break;
					case 2:
						std::cout << "Enemy dropped a potion!" << '\n';
						this->_player.GetInventory().AddItem(HealthPotion("Spirit", HEAL, 15));
						break;
					default:
						break;
					}
				}
				delete this->_enemy;
				this->_enemy = nullptr;
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
}

Player Combat::GetPlayer()
{
	return this->_player;
}

Enemy* Combat::GetEnemy()
{
	return this->_enemy;
}
