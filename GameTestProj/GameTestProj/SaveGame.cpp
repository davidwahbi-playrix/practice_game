#include "SaveGame.h"

SaveGame::SaveGame()
{
}

SaveGame::~SaveGame()
{
}

void SaveGame::SaveSmartGameState(Player player, std::vector<std::shared_ptr<Enemy>> smartEnemies, Inventory gameItems)
{
	std::ofstream newFile;
	newFile.open("SaveGame.txt");
	if (newFile.is_open()) {
		newFile << "Game" << std::endl;
		this->SaveGameItems(newFile, gameItems);
		//this->SaveSmartGameItems(newFile, gameItems);
		newFile << "Player" << std::endl;
		newFile << player.GetPosX() << ';' << player.GetPosY() << ';' << player.GetHealth() << ';' << player.GetDamage() << ';' << player.GetDefence() << ';' << player.GetName() << ';' << std::endl;;
		newFile << "PlayerInventory" << std::endl;
		this->SavePlayerInventory(newFile, player);
		newFile << "PlayerEquipment" << std::endl;
		this->SavePlayerEquipment(newFile, player);
		newFile << "Enemy" << std::endl;
		if (smartEnemies.size() > 0)
		{
			newFile << smartEnemies.size() << std::endl;
			for (size_t i = 0; i < smartEnemies.size(); i++)
			{
				newFile << smartEnemies[i]->GetPosX() << ';' << smartEnemies[i]->GetPosY() << ';' << smartEnemies[i]->GetHealth() << ';' << smartEnemies[i]->GetDamage() << ';' << smartEnemies[i]->GetDropChance() << ';' << std::endl;
			}
		}
		else
		{
			newFile << -1 << std::endl;
		}

		newFile.close();
		std::cout << '\n' << "Game is saved!" << '\n';
	}
}

void SaveGame::SavePlayerInventory(std::ofstream& file, Player player)
{
	if (player.GetInventory().Size() > 0)
	{
		file << player.GetInventory().Size() << std::endl;
		for (size_t i = 0; i < player.GetInventory().Size(); i++)
		{
			Weapon* tmp_w = dynamic_cast<Weapon*>(&player.GetInventory().At(i));
			Armor* tmp_a = dynamic_cast<Armor*>(&player.GetInventory().At(i));
			HealthPotion* tmp_p = dynamic_cast<HealthPotion*>(&player.GetInventory().At(i));

			if (tmp_w)
			{
				file << tmp_w->GetName() << ';' << tmp_w->GetSubTypeAsString() << ';' << tmp_w->GetPosX() << ';' << tmp_w->GetPosY() << ';' << tmp_w->GetDamageValue() << ';';
			}
			if (tmp_a)
			{
				file << tmp_a->GetName() << ';' << tmp_a->GetSubTypeAsString() << ';' << tmp_a->GetPosX() << ';' << tmp_a->GetPosY() << ';' << tmp_a->GetArmorValue() << ';';
			}
			if (tmp_p)
			{
				file << tmp_p->GetName() << ';' << tmp_p->GetSubTypeAsString() << ';' << tmp_p->GetPosX() << ';' << tmp_p->GetPosY() << ';' << tmp_p->GetHealthValue() << ';';
			}
		}
		file << std::endl;
	}
	else
	{
		file << -1 << std::endl;
	}
}

/*void SaveGame::SaveSmartPlayerInventory(std::ofstream& file, Player player)
{
	if (player.GetInventory().Size() > 0)
	{
		file << player.GetInventory().Size() << std::endl;
		for (size_t i = 0; i < player.GetSmartInventory().Size(); i++)
		{
			std::shared_ptr<Item> tmp_i = std::make_shared<Item>(&player.GetSmartInventory().At(i));
			std::shared_ptr<Weapon> tmp_w = std::dynamic_pointer_cast<Weapon>(tmp_i);
			std::shared_ptr<Armor> tmp_a = std::dynamic_pointer_cast<Armor>(tmp_i);
			std::shared_ptr<HealthPotion> tmp_p = std::dynamic_pointer_cast<HealthPotion>(tmp_i);

			if (tmp_w)
			{
				file << tmp_w->GetName() << ';' << tmp_w->GetSubTypeAsString() << ';' << tmp_w->GetPosX() << ';' << tmp_w->GetPosY() << ';' << tmp_w->GetDamageValue() << ';';
			}
			if (tmp_a)
			{
				file << tmp_a->GetName() << ';' << tmp_a->GetSubTypeAsString() << ';' << tmp_a->GetPosX() << ';' << tmp_a->GetPosY() << ';' << tmp_a->GetArmorValue() << ';';
			}
			if (tmp_p)
			{
				file << tmp_p->GetName() << ';' << tmp_p->GetSubTypeAsString() << ';' << tmp_p->GetPosX() << ';' << tmp_p->GetPosY() << ';' << tmp_p->GetHealthValue() << ';';
			}
		}
		file << std::endl;
	}
	else
	{
		file << -1 << std::endl;
	}
} */

void SaveGame::SavePlayerEquipment(std::ofstream& file, Player player)
{
	file << "Weapon" << std::endl;
	if (player.GetWeapon()) {
		file << "Yes" << std::endl;
		file << player.GetWeapon()->GetName() << ';' << player.GetWeapon()->GetSubTypeAsString() << ';' << player.GetWeapon()->GetPosX() << ';' << player.GetWeapon()->GetPosY() << ';' << player.GetWeapon()->GetDamageValue() << ';';
		file << std::endl;
	}
	else
	{
		file << "None" << std::endl;
	}
	file << "Armor" << std::endl;
	if (player.GetArmor()) {
		file << "Yes" << std::endl;
		file << player.GetArmor()->GetName() << ';' << player.GetArmor()->GetSubTypeAsString() << ';' << player.GetArmor()->GetPosX() << ';' << player.GetArmor()->GetPosY() << ';' << player.GetArmor()->GetDamageValue() << ';';
		file << std::endl;
	}
	else
	{
		file << "None" << std::endl;
	}
}

/*void SaveGame::SaveSmartPlayerEquipment(std::ofstream& file, Player player)
{
	file << "Weapon" << std::endl;
	if (player.GetSmartWeapon()) {
		file << "Yes" << std::endl;
		file << player.GetSmartWeapon()->GetName() << ';' << player.GetSmartWeapon()->GetSubTypeAsString() << ';' << player.GetSmartWeapon()->GetPosX() << ';' << player.GetWeapon()->GetPosY() << ';' << player.GetSmartWeapon()->GetDamageValue() << ';';
		file << std::endl;
	}
	else
	{
		file << "None" << std::endl;
	}
	file << "Armor" << std::endl;
	if (player.GetSmartArmor()) {
		file << "Yes" << std::endl;
		file << player.GetSmartArmor()->GetName() << ';' << player.GetSmartArmor()->GetSubTypeAsString() << ';' << player.GetSmartArmor()->GetPosX() << ';' << player.GetSmartArmor()->GetPosY() << ';' << player.GetSmartArmor()->GetDamageValue() << ';';
		file << std::endl;
	}
	else
	{
		file << "None" << std::endl;
	}
} */

void SaveGame::SaveGameItems(std::ofstream& file, Inventory gameItems)
{
	if (gameItems.Size() > 0)
	{
		file << gameItems.Size() << std::endl;
		for (size_t i = 0; i < gameItems.Size(); i++)
		{
			Weapon* tmp_w = dynamic_cast<Weapon*>(&gameItems.At(i));
			Armor* tmp_a = dynamic_cast<Armor*>(&gameItems.At(i));
			HealthPotion* tmp_p = dynamic_cast<HealthPotion*>(&gameItems.At(i));

			if (tmp_w)
			{
				file << tmp_w->GetName() << ';' << tmp_w->GetSubTypeAsString() << ';' << tmp_w->GetPosX() << ';' << tmp_w->GetPosY() << ';' << tmp_w->GetDamageValue() << ';';
			}
			if (tmp_a)
			{
				file << tmp_a->GetName() << ';' << tmp_a->GetSubTypeAsString() << ';' << tmp_a->GetPosX() << ';' << tmp_a->GetPosY() << ';' << tmp_a->GetArmorValue() << ';';
			}
			if (tmp_p)
			{
				file << tmp_p->GetName() << ';' << tmp_p->GetSubTypeAsString() << ';' << tmp_p->GetPosX() << ';' << tmp_p->GetPosY() << ';' << tmp_p->GetHealthValue() << ';';
			}
		}
		file << std::endl;
	}
	else
	{
		file << -1 << std::endl;
	}
}

/*void SaveGame::SaveSmartGameItems(std::ofstream& file, Inventory gameItems)
{
	if (gameItems.Size() > 0)
	{
		file << gameItems.Size() << std::endl;
		for (size_t i = 0; i < gameItems.Size(); i++)
		{
			std::shared_ptr<Item> tmp_i = std::make_shared<Item>(&gameItems.At(i));
			std::shared_ptr<Weapon> tmp_w = std::dynamic_pointer_cast<Weapon>(tmp_i);
			std::shared_ptr<Armor> tmp_a = std::dynamic_pointer_cast<Armor>(tmp_i);
			std::shared_ptr<HealthPotion> tmp_p = std::dynamic_pointer_cast<HealthPotion>(tmp_i);

			if (tmp_w)
			{
				file << tmp_w->GetName() << ';' << tmp_w->GetSubTypeAsString() << ';' << tmp_w->GetPosX() << ';' << tmp_w->GetPosY() << ';' << tmp_w->GetDamageValue() << ';';
			}
			if (tmp_a)
			{
				file << tmp_a->GetName() << ';' << tmp_a->GetSubTypeAsString() << ';' << tmp_a->GetPosX() << ';' << tmp_a->GetPosY() << ';' << tmp_a->GetArmorValue() << ';';
			}
			if (tmp_p)
			{
				file << tmp_p->GetName() << ';' << tmp_p->GetSubTypeAsString() << ';' << tmp_p->GetPosX() << ';' << tmp_p->GetPosY() << ';' << tmp_p->GetHealthValue() << ';';
			}
		}
		file << std::endl;
	}
	else
	{
		file << -1 << std::endl;
	}
} */
