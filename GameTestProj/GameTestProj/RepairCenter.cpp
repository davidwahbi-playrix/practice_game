#include "RepairCenter.h"



RepairCenter::RepairCenter()
{
	_exit = false;
}


RepairCenter::~RepairCenter()
{
}

void RepairCenter::ReapirEquipment2(Player & player)
{
	int state = 0;
	std::cout << "Welcome to repair center!" << std::endl;
	std::cout << "Here you can repair any damaged equipment." << std::endl;

	while (!_exit)
	{
		if (player.GetArmor()) {
			if (player.GetArmor()->GetArmorValue() < player.GetArmor()->GetStartArmorValue())
			{
				std::cout << player.GetArmor()->toString() << std::endl;
				std::cout << "Your Armor is damaged! We can repair it right away." << std::endl;
				system("pause");
				std::cout << std::endl;
				player.GetArmor2().SetArmorValue(player.GetArmor()->GetStartArmorValue());
				player.GetArmor2().ResetBattleCnt();
				std::cout << "Armor repaired!" << std::endl;
				std::cout << player.GetArmor()->toString() << std::endl;
				player.SetDefence(player.GetArmor()->GetArmorValue());
				_exit = true;
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
		if (player.GetWeapon()) {
			if (player.GetWeapon()->GetDamageValue() < player.GetWeapon()->GetStartDamageValue())
			{
				std::cout << player.GetWeapon()->toString() << std::endl;
				std::cout << "Your Weapon is damaged! We can repair it right away." << std::endl;
				system("pause");
				std::cout << std::endl;
				player.GetWeapon2().SetDamageValue(player.GetWeapon()->GetStartDamageValue());
				player.GetWeapon2().ResetBattleCnt();
				std::cout << "Weapon repaired!" << std::endl;
				std::cout << player.GetWeapon()->toString() << std::endl;
				player.SetDamage(player.GetWeapon()->GetDamageValue() + player.GetStartDamage());
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
		_exit = true;
	}
}

void RepairCenter::SetExit(const bool & value)
{
	_exit = value;
}
