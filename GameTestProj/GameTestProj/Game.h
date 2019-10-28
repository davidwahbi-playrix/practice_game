#pragma once
#include <fstream>
#include <sstream>
#include "Player.h"
#include "Enemy.h"
#include "SaveGame.h"
#include "LoadGame.h"
#include "Combat.h"
#include "Renderer.h"
class Game
{
public:
	Game();
	~Game();

	void Init();
	void HandleEvents();
	void Update();
	void Render();
	void Clean();
	void UpdatePlayerInventory();

	void EquipItem(const int index);

	unsigned int GetGameItemIndex(const int x, const int y);
	bool Running();
	bool Draw();
private:
	bool _isRunning;
	bool _draw;
	bool _equip;
	bool _canEquip;
	int _dir;
	int _equipInd;
	Player _player;
	Enemy* _enemy;
	Board _board;
	Inventory _gameItems;
	Renderer _renderer;
};
