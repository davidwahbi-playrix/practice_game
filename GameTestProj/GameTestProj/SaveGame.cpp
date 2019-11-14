#include "SaveGame.h"

SaveGame::SaveGame()
{
}

SaveGame::~SaveGame()
{
}

void SaveGame::SaveSmartGameState(const int& level, Player& player, const std::vector<std::shared_ptr<Enemy>>& smartEnemies, Inventory& gameItems)
{
	std::ofstream newFile;
	newFile.open("SaveGame.txt");
	if (newFile.is_open()) {
		newFile << "Level" << std::endl;
		newFile << level << std::endl;
		newFile << "GameItems" << std::endl;
		SaveInventory(newFile, gameItems);
		//SaveSmartInventory(newFile, gameItems);
		newFile << "Player" << std::endl;
		newFile << player.GetPosX() << ';' << player.GetPosY() << ';' << player.GetHealth() << ';' << player.GetDamage() << ';' << player.GetDefence() << ';' << player.GetName() << ';' << player.GetStartDamage() << ';' << std::endl;;
		newFile << "PlayerInventory" << std::endl;
		SaveInventory(newFile, player.GetInventory());
		//SaveSmartInventory(newFile, player.GetInventory());
		newFile << "PlayerEquipment" << std::endl;
		SavePlayerEquipment(newFile, player);
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

void SaveGame::SavePlayerEquipment(std::ofstream& file, Player player)
{
	file << "Weapon" << std::endl;
	if (player.GetWeapon()) {
		file << "Yes" << std::endl;
		file << player.GetWeapon()->GetName() << ';' << player.GetWeapon()->GetSubTypeAsString() << ';' << player.GetWeapon()->GetPosX() << ';' << player.GetWeapon()->GetPosY() << ';' << player.GetWeapon()->GetDamageValue() << ';' << player.GetWeapon()->GetStartDamageValue() << ';' << player.GetWeapon()->GetBattleCnt() << ';';
		file << std::endl;
	}
	else
	{
		file << "None" << std::endl;
	}
	file << "Armor" << std::endl;
	if (player.GetArmor()) {
		file << "Yes" << std::endl;
		file << player.GetArmor()->GetName() << ';' << player.GetArmor()->GetSubTypeAsString() << ';' << player.GetArmor()->GetPosX() << ';' << player.GetArmor()->GetPosY() << ';' << player.GetArmor()->GetDamageValue() << ';' << player.GetArmor()->GetStartArmorValue() << ';' << player.GetArmor()->GetBattleCnt() << ';';
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

void SaveGame::SaveInventory(std::ofstream & file, Inventory & inaventory)
{
	if (inaventory.Size() > 0)
	{
		file << inaventory.Size() << std::endl;
		for (size_t i = 0; i < inaventory.Size(); i++)
		{
			Weapon* tmp_w = dynamic_cast<Weapon*>(&inaventory.At(i));
			Armor* tmp_a = dynamic_cast<Armor*>(&inaventory.At(i));
			HealthPotion* tmp_p = dynamic_cast<HealthPotion*>(&inaventory.At(i));

			if (tmp_w)
			{
				file << tmp_w->GetName() << ';' << tmp_w->GetSubTypeAsString() << ';' << tmp_w->GetPosX() << ';' << tmp_w->GetPosY() << ';' << tmp_w->GetDamageValue() << ';' << tmp_w->GetStartDamageValue() << ';' << tmp_w->GetBattleCnt() << ';';
			}
			if (tmp_a)
			{
				file << tmp_a->GetName() << ';' << tmp_a->GetSubTypeAsString() << ';' << tmp_a->GetPosX() << ';' << tmp_a->GetPosY() << ';' << tmp_a->GetArmorValue() << ';' << tmp_a->GetStartArmorValue() << ';' << tmp_a->GetBattleCnt() << ';';
			}
			if (tmp_p)
			{
				file << tmp_p->GetName() << ';' << tmp_p->GetSubTypeAsString() << ';' << tmp_p->GetPosX() << ';' << tmp_p->GetPosY() << ';' << tmp_p->GetHealthValue() << ';' << healConst << ';' << healConst << ';';
			}
		}
		file << std::endl;
	}
	else
	{
		file << -1 << std::endl;
	}
}

/*void SaveGame::SaveSmartInventory(std::ofstream& file, Inventory inventory)
{
	if (inaventory.Size() > 0)
	{
		file << inventory.Size() << std::endl;
		for (size_t i = 0; i < inventory.Size(); i++)
		{
			std::shared_ptr<Item> tmp_i = std::make_shared<Item>(&inventory.At(i));
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
