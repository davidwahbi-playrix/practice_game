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
#include "EventHandler.h"
#include "LoadGame.h"
#include "SaveGame.h"
#include "Profile.h"
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

	bool Running() const;
	bool Draw() const;
private:
	bool _isRunning;
	bool _draw;
	bool _equip;
	Renderer _renderer;
	MoveUnit _unitMover;
	EventHandler _eventHandler;
	LoadGame _loader;
	SaveGame _saver;
	Profile _profile;
};
