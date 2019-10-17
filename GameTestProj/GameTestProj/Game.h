#pragma once
#include "Player.h"
#include "Weapon.h"
class Game
{
private:
	bool _isRunning;
	bool _draw;
	int _dir;
	Player _player;
	Board _board;
	Weapon* _weapon;
public:
	Game();
	~Game();

	void Init();
	void HandleEvents();
	void Update();
	void Render();
	void Clean();
	void UpdatePlayerInventory();
	bool Running();
	bool Draw();
};

