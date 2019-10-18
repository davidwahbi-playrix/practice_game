#pragma once
#include "Player.h"
#include "Weapon.h"
#include "Armor.h"
#include "HealthPotion.h"
class Game
{
private:
	bool _isRunning;
	bool _draw;
	int _dir;
	Player _player;
	Board _board;
	Inventory _gameItems;
	//Weapon* _weapon;
	//Armor* _armor;
public:
	Game();
	~Game();

	void Init();
	void HandleEvents();
	void Update();
	void Render();
	void Clean();
	void UpdatePlayerInventory();
	unsigned int GetGameItemIndex(const int x, const int y);
	bool Running();
	bool Draw();
};

