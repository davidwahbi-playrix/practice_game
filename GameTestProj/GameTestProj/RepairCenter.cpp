#include "RepairCenter.h"



RepairCenter::RepairCenter()
{
}


RepairCenter::~RepairCenter()
{
}

void RepairCenter::ReapirEquipment3(SmartPlayer & player)
{
	int state = 0;
	bool exit = false;
	std::cout << "Welcome to repair center!" << std::endl;
	std::cout << "Here you can repair any damaged equipment." << std::endl;

	while (!exit)
	{
		if (player.GetSmartArmor()) {
			if (player.GetSmartArmor()->GetArmorValue() < player.GetSmartArmor()->GetStartArmorValue())
			{
				std::cout << player.GetSmartArmor()->toString() << std::endl;
				std::cout << "Your Armor is damaged! We can repair it right away." << std::endl;
				system("pause");
				std::cout << std::endl;
				player.GetSmartArmor2().SetArmorValue(player.GetSmartArmor()->GetStartArmorValue());
				player.GetSmartArmor2().ResetBattleCnt();
				std::cout << "Armor repaired!" << std::endl;
				std::cout << player.GetSmartArmor()->toString() << std::endl;
				player.SetDefence(player.GetSmartArmor()->GetArmorValue());
				system("pause");
				system("cls");
			}
			else
			{
				std::cout << "Your Armor is in perfect shape!" << std::endl;
				system("pause");
				system("cls");
			}
		}
		else
		{
			std::cout << "You have no Armor equipped!" << std::endl;
			system("pause");
			system("cls");
		}
		if (player.GetSmartWeapon()) {
			if (player.GetSmartWeapon()->GetDamageValue() < player.GetSmartWeapon()->GetStartDamageValue())
			{
				std::cout << player.GetSmartWeapon()->toString() << std::endl;
				std::cout << "Your Weapon is damaged! We can repair it right away." << std::endl;
				system("pause");
				std::cout << std::endl;
				player.GetSmartWeapon2().SetDamageValue(player.GetSmartWeapon()->GetStartDamageValue());
				player.GetSmartWeapon2().ResetBattleCnt();
				std::cout << "Weapon repaired!" << std::endl;
				std::cout << player.GetSmartWeapon()->toString() << std::endl;
				player.SetDamage(player.GetSmartWeapon()->GetDamageValue() + player.GetStartDamage());
				state = 1;
				system("pause");
				system("cls");
			}
			else
			{
				std::cout << "Your Weapon is in perfect shape!" << std::endl;
				system("pause");
				system("cls");
			}
		}
		else
		{
			std::cout << "You have no Weapon equipped!" << std::endl;
			system("pause");
			system("cls");
		}
		exit = true;
	}
}
