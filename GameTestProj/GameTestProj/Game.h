#pragma once
#include "Player.h"
#include "Enemy.h"
class Game
{
private:
	bool _isRunning;
	bool _draw;
	bool _equip;
	int _dir;
	int _equipInd;
	Player _player;
	Enemy* _enemy;
	Board _board;
	Inventory _gameItems;
public:
	Game();
	~Game();

	void Init();
	void HandleEvents();
	void Update();
	void Render();
	void Clean();
	void UpdatePlayerInventory();
	void Battle();

	void EquipItem(const int index);
	unsigned int GetGameItemIndex(const int x, const int y);
	bool Running();
	bool Draw();
};

