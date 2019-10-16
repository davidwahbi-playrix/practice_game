#include <iostream>
#include <string>
#include "Board.h"
#include "Player.h"
#include "Game.h"
#include <Windows.h>
#include <memory>

std::unique_ptr<Game> game(nullptr);

int main()
{	
	game = std::make_unique<Game>();

	game->Init();

	while (game->Running()) {

		game->HandleEvents();
		if (game->Draw())
		{
			game->Update();
			game->Render();
		}
		Sleep(50);
	}


	system("pause");
	return 0;
}
