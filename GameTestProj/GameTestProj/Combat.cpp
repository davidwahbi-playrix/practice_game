#include "Combat.h"

Combat::Combat()
{
	_continue = true;
}

Combat::~Combat()
{
}

void Combat::SmartBattle2(Player & player, std::shared_ptr<Enemy>& smartEnemy)
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
		if (player.CanBattle(smartEnemy->GetDamage()))
		{
			std::cout << "Enemy Attacks!" << '\n';
			player.ReceiveHit(smartEnemy->GetDamage());
			std::cout << player.toString() << '\n';
			if (smartEnemy->CanBattle(player.GetDamage()))
			{
				std::cout << "Player Attacks!" << '\n';
				smartEnemy->ReceiveHit(player.GetDamage(), player.GetHealth(), player.GetDefence());
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
					player.GetWeapon2().IncreseBattleCnt();
					player.UpdatePlayerWeapon();
				}
				if (player.GetArmor())
				{
					player.GetArmor2().IncreseBattleCnt();
				}
				system("pause");
				system("cls");
				smartEnemy = nullptr;
			}

		}
		else
		{
			system("cls");
			std::cout << "GAME OVER!" << '\n';
			std::cout << "You are Dead!" << '\n';
			_continue = false;
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
}

void Combat::SetContinue(const bool & value)
{
	_continue = value;
}

bool Combat::GetContinue() const
{
	return _continue;
}
