#pragma once
#include <iostream>
#include <fstream>
#include "Player.h"
#include "Profile.h"
class Renderer
{
public:
	Renderer();
	~Renderer();

	void Render(Profile& profile, bool& running);
	void RenderPlayerInventory(Player player) const;
	void RenderPlayer(Player player) const;
	void SaveLoadMenu();
	void SetDraw(const bool& value);
	void ClearView();
	void NextLevel(int level);

	bool GetDraw() const;
	bool GetFlag() const;

private:
	bool _draw;
	bool _canEnter;
};

