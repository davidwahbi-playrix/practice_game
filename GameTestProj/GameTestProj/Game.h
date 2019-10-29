#pragma once
#include <fstream>
#include <sstream>
#include "Player.h"
#include "Enemy.h"
#include "SaveGame.h"
#include "LoadGame.h"
#include "Combat.h"
#include "Renderer.h"
#include "MoveUnit.h"
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

	bool Running();
	bool Draw();
private:
	bool _isRunning;
	bool _draw;
	bool _equip;
	Player _player;
	Enemy* _enemy;
	Board _board;
	Inventory _gameItems;
	Renderer _renderer;
	MoveUnit _unitMover;
};
