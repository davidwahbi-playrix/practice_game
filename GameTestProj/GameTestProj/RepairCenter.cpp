#include "RepairCenter.h"



RepairCenter::RepairCenter()
{
	this->_exit = false;
}


RepairCenter::~RepairCenter()
{
}

int RepairCenter::ReapirEquipment(Player player)
{
	int state = 0;
	std::cout << "Welcome to repair center!" << std::endl;
	std::cout << "Here you can repair any damaged equipment." << std::endl;

	while (!this->_exit)
	{
		if (player.GetArmor()) {
			if (player.GetArmor()->GetArmorValue() < player.GetArmor()->GetStartArmorValue())
			{
				std::cout << player.GetArmor()->toString() << std::endl;
				std::cout << "Your Armor is damaged! We can repair it right away." << std::endl;
				system("pause");
				std::cout << std::endl;
				Armor* tmpArmor = player.GetArmor();
				tmpArmor->SetArmorValue(tmpArmor->GetStartArmorValue());
				player.SetArmor(tmpArmor);
				std::cout << "Armor repaired!" << std::endl;
				std::cout << player.GetArmor()->toString() << std::endl;
				this->_exit = true;
				state = 1;
				system("pause");
				system("cls");
			}
			else
			{
				std::cout << "Your Armor is in perfect shape!" << std::endl;
				state = 1;
				system("pause");
				system("cls");
			}
		}
		else
		{
			std::cout << "You have no Armor equipped!" << std::endl;
			state = 2;
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
				Weapon* tmpWeapon = player.GetWeapon();
				tmpWeapon->SetDamageValue(tmpWeapon->GetStartDamageValue());
				player.SetWeapon(tmpWeapon);
				std::cout << "Weapon repaired!" << std::endl;
				std::cout << player.GetWeapon()->toString() << std::endl;
				state = 1;
				system("pause");
				system("cls");
			}
			else
			{
				std::cout << "Your Weapon is in perfect shape!" << std::endl;
				state = 1;
				system("pause");
				system("cls");
			}
		}
		else
		{
			std::cout << "You have no Weapon equipped!" << std::endl;
			state = 2;
			system("pause");
			system("cls");
		}
		this->_exit = true;
	}

	if (state == 1)
	{
		this->_player = player;
	}
	return state;
}

void RepairCenter::SetExit(const bool & value)
{
	this->_exit = value;
}

Player RepairCenter::GetPlayer() const
{
	return this->_player;
}
