#include "Combat.h"

Combat::Combat()
{
}

Combat::~Combat()
{
}

void Combat::SmartBattle3(SmartPlayer & player, std::shared_ptr<Enemy>& smartEnemy, bool & canContinue)
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
						player.GetSmartInventory().AddSmartItem(std::make_shared<Weapon>("Spear", WEAPON, 8));
						player.SetCanEquip(true);
						break;
					case 1:
						std::cout << "Enemy dropped an aromor!" << '\n';
						player.GetSmartInventory().AddSmartItem(std::make_shared<Armor>("Vest", ARMOR, 5));
						player.SetCanEquip(true);
						break;
					case 2:
						std::cout << "Enemy dropped a potion!" << '\n';
						player.GetSmartInventory().AddSmartItem(std::make_shared<HealthPotion>("Spirit", HEAL, 15));
						player.SetCanEquip(true);
						break;
					default:
						break;
					}
				}
				if (player.GetSmartWeapon())
				{
					player.GetSmartWeapon2().IncreseBattleCnt();
					player.UpdateSmartPlayerWeapon();
				}
				if (player.GetSmartArmor())
				{
					player.GetSmartArmor2().IncreseBattleCnt();
				}
				system("pause");
				system("cls");
				smartEnemy = nullptr;
			}

		}
		else
		{
			system("cls");
			std::cout << "You are Dead!" << '\n';
			canContinue = false;
			exit = true;
			system("pause");
		}
	}
}
