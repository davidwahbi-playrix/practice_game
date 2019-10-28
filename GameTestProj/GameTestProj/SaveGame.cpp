#include "SaveGame.h"

SaveGame::SaveGame()
{
}

SaveGame::SaveGame(Player player, Enemy* enemy, Inventory gameItems)
{
	this->_player = player;
	this->_enemy = enemy;
	this->_gameItems = gameItems;
}

SaveGame::~SaveGame()
{
}

void SaveGame::SaveGameState()
{
	std::ofstream newFile;
	newFile.open("SaveGame.txt");
	if (newFile.is_open()) {
		newFile << "Game" << std::endl;
		this->SaveGameItems(newFile);
		newFile << "Player" << std::endl;
		newFile << this->_player.GetPosX() << ';' << this->_player.GetPosY() << ';' << this->_player.GetHealth() << ';' << this->_player.GetDamage() << ';' << this->_player.GetDefence() << ';' << this->_player.GetName() << ';' << std::endl;;
		newFile << "PlayerInventory" << std::endl;
		this->SavePlayerInventory(newFile);
		newFile << "PlayerEquipment" << std::endl;
		this->SavePlayerEquipment(newFile);
		newFile << "Enemy" << std::endl;
		if (this->_enemy)
		{
			newFile << "Yes" << std::endl;
			newFile << this->_enemy->GetPosX() << ';' << this->_enemy->GetPosY() << ';' << this->_enemy->GetHealth() << ';' << this->_enemy->GetDamage() << ';' << this->_enemy->GetDropChance() << ';' << std::endl;;
		}
		else
		{
			newFile << "None" << std::endl;
		}
		newFile.close();
		std::cout << '\n' << "Game is saved!" << '\n';
	}
}

void SaveGame::SavePlayerInventory(std::ofstream& file)
{
	if (this->_player.GetInventory().Size() > 0)
	{
		file << this->_player.GetInventory().Size() << std::endl;
		for (size_t i = 0; i < _player.GetInventory().Size(); i++)
		{
			Weapon* tmp_w = dynamic_cast<Weapon*>(&this->_player.GetInventory().At(i));
			Armor* tmp_a = dynamic_cast<Armor*>(&this->_player.GetInventory().At(i));
			HealthPotion* tmp_p = dynamic_cast<HealthPotion*>(&this->_player.GetInventory().At(i));

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

void SaveGame::SavePlayerEquipment(std::ofstream& file)
{
	file << "Weapon" << std::endl;
	if (this->_player.GetWeapon()) {
		file << "Yes" << std::endl;
		file << _player.GetWeapon()->GetName() << ';' << _player.GetWeapon()->GetSubTypeAsString() << ';' << _player.GetWeapon()->GetPosX() << ';' << _player.GetWeapon()->GetPosY() << ';' << _player.GetWeapon()->GetDamageValue() << ';';
		file << std::endl;
	}
	else
	{
		file << "None" << std::endl;
	}
	file << "Armor" << std::endl;
	if (this->_player.GetArmor()) {
		file << "Yes" << std::endl;
		file << _player.GetArmor()->GetName() << ';' << _player.GetArmor()->GetSubTypeAsString() << ';' << _player.GetArmor()->GetPosX() << ';' << _player.GetArmor()->GetPosY() << ';' << _player.GetArmor()->GetDamageValue() << ';';
		file << std::endl;
	}
	else
	{
		file << "None" << std::endl;
	}
}

void SaveGame::SaveGameItems(std::ofstream& file)
{
	if (this->_gameItems.Size() > 0)
	{
		file << this->_gameItems.Size() << std::endl;
		for (size_t i = 0; i < this->_gameItems.Size(); i++)
		{
			Weapon* tmp_w = dynamic_cast<Weapon*>(&this->_gameItems.At(i));
			Armor* tmp_a = dynamic_cast<Armor*>(&this->_gameItems.At(i));
			HealthPotion* tmp_p = dynamic_cast<HealthPotion*>(&this->_gameItems.At(i));

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
