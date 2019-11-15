#pragma once
#include <iostream>
#include <fstream>
#include "SmartPlayer.h"
#include "Profile.h"
class Renderer
{
public:
	Renderer();
	~Renderer();

	void Render(Profile& profile, bool& running);

	void RenderPlayerSmartInventory(const SmartPlayer& player) const;

	void RenderSmartPlayer(const SmartPlayer& player) const;

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

