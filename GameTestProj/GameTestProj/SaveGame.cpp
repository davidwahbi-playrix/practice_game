#include "SaveGame.h"

SaveGame::SaveGame()
{
}

SaveGame::~SaveGame()
{
}

void SaveGame::SaveSmartGameState2(const int & level, SmartPlayer & player, const std::vector<std::shared_ptr<Enemy>>& smartEnemies, SmartInventory & gameItems)
{
	std::ofstream newFile;
	newFile.open("SaveGame.txt");
	if (newFile.is_open()) {
		newFile << "Level" << std::endl;
		newFile << level << std::endl;
		newFile << "GameItems" << std::endl;
		SaveSmartInventory(newFile, gameItems);
		newFile << "Player" << std::endl;
		newFile << player.GetPosX() << ';' << player.GetPosY() << ';' << player.GetHealth() << ';' << player.GetDamage() << ';' << player.GetDefence() << ';' << player.GetName() << ';' << player.GetStartDamage() << ';' << std::endl;;
		newFile << "PlayerInventory" << std::endl;
		SaveSmartInventory(newFile, player.GetSmartInventory2());
		newFile << "PlayerEquipment" << std::endl;
		SaveSmartPlayerEquipment(newFile, player);
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

void SaveGame::SaveSmartPlayerEquipment(std::ofstream& file, SmartPlayer player)
{
	file << "Weapon" << std::endl;
	if (player.GetSmartWeapon()) {
		file << "Yes" << std::endl;
		file << player.GetSmartWeapon()->GetName() << ';' << player.GetSmartWeapon()->GetSubTypeAsString() << ';' << player.GetSmartWeapon()->GetPosX() << ';' << player.GetSmartWeapon()->GetPosY() << ';' << player.GetSmartWeapon()->GetDamageValue() << ';' << player.GetSmartWeapon()->GetStartDamageValue() << ';' << player.GetSmartWeapon()->GetBattleCnt() << ';';
		file << std::endl;
	}
	else
	{
		file << "None" << std::endl;
	}
	file << "Armor" << std::endl;
	if (player.GetSmartArmor()) {
		file << "Yes" << std::endl;
		file << player.GetSmartArmor()->GetName() << ';' << player.GetSmartArmor()->GetSubTypeAsString() << ';' << player.GetSmartArmor()->GetPosX() << ';' << player.GetSmartArmor()->GetPosY() << ';' << player.GetSmartArmor()->GetDamageValue() << ';' << player.GetSmartArmor()->GetStartArmorValue() << ';' << player.GetSmartArmor()->GetBattleCnt() << ';';
		file << std::endl;
	}
	else
	{
		file << "None" << std::endl;
	}
}

void SaveGame::SaveSmartInventory(std::ofstream& file, SmartInventory& inventory)
{
	if (inventory.Size() > 0)
	{
		file << inventory.Size() << std::endl;
		for (size_t i = 0; i < inventory.Size(); i++)
		{
			int type = inventory.AtSmart(i)->GetSubType();

			if (type == 0)
			{
				std::shared_ptr<Armor> tmp_a = std::static_pointer_cast<Armor>(inventory.AtSmart(i));
				file << tmp_a->GetName() << ';' << tmp_a->GetSubTypeAsString() << ';' << tmp_a->GetPosX() << ';' << tmp_a->GetPosY() << ';' << tmp_a->GetArmorValue() << ';' << tmp_a->GetStartArmorValue() << ';' << tmp_a->GetBattleCnt() << ';';
			}
			if (type == 1)
			{
				std::shared_ptr<Weapon> tmp_w = std::static_pointer_cast<Weapon>(inventory.AtSmart(i));
				file << tmp_w->GetName() << ';' << tmp_w->GetSubTypeAsString() << ';' << tmp_w->GetPosX() << ';' << tmp_w->GetPosY() << ';' << tmp_w->GetDamageValue() << ';' << tmp_w->GetStartDamageValue() << ';' << tmp_w->GetBattleCnt() << ';';
			}
			if (type == 2)
			{
				std::shared_ptr<HealthPotion> tmp_p = std::static_pointer_cast<HealthPotion>(inventory.AtSmart(i));
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
