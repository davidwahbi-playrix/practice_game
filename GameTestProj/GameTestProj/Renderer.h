#pragma once
#include <iostream>
#include <fstream>
#include "Board.h";
#include "Player.h";
class Renderer
{
public:
	Renderer();
	~Renderer();

	void Render(Board board, Player player);
	void SaveLoadMenu();

	bool GetFlag() const;
private:
	bool _canEnter;
};

