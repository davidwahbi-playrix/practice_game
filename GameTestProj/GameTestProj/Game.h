#pragma once
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
	Renderer GetRenderer() const;
private:
	bool _isRunning;
	Renderer _renderer;
	MoveUnit _unitMover;
	EventHandler _eventHandler;
	LoadGame _loader;
	SaveGame _saver;
	Profile _profile;
};
