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
				this->_exit = true;
				state = 1;
				system("pause");
				system("cls");
			}
		}
		else
		{
			std::cout << "You have no Armor equipped!" << std::endl;
			this->_exit = true;
			state = 2;
			system("pause");
			system("cls");
		}
	}

	if (state == 1) 
	{
		return player.GetArmor()->GetArmorValue();
	}
	else
	{
		return state;
	}
}

void RepairCenter::SetExit(const bool & value)
{
	this->_exit = value;
}
