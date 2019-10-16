#pragma once
#include "Player.h"
class Game
{
private:
	bool _isRunning;
	bool _draw;
	int _dir;
	Player _player;
	Board _board;
	Item* _item;
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
};

