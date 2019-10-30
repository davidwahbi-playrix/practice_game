#include "SaveGame.h"

SaveGame::SaveGame()
{
}

SaveGame::~SaveGame()
{
}

void SaveGame::SaveGameState(Player player, std::vector<Enemy*> enemies, Inventory gameItems)
{
	std::ofstream newFile;
	newFile.open("SaveGame.txt");
	if (newFile.is_open()) {
		newFile << "Game" << std::endl;
		this->SaveGameItems(newFile, gameItems);
		newFile << "Player" << std::endl;
		newFile << player.GetPosX() << ';' << player.GetPosY() << ';' << player.GetHealth() << ';' << player.GetDamage() << ';' << player.GetDefence() << ';' << player.GetName() << ';' << std::endl;;
		newFile << "PlayerInventory" << std::endl;
		this->SavePlayerInventory(newFile, player);
		newFile << "PlayerEquipment" << std::endl;
		this->SavePlayerEquipment(newFile, player);
		newFile << "Enemy" << std::endl;
		if (enemies.size() > 0)
		{
			newFile << enemies.size() << std::endl;
			for (size_t i = 0; i < enemies.size(); i++)
			{
				newFile << enemies[i]->GetPosX() << ';' << enemies[i]->GetPosY() << ';' << enemies[i]->GetHealth() << ';' << enemies[i]->GetDamage() << ';' << enemies[i]->GetDropChance() << ';' << std::endl;
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
