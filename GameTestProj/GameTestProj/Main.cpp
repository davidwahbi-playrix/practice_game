#include <memory>
#include "Game.h"

std::unique_ptr<Game> game(nullptr);

int main()
{	
	game = std::make_unique<Game>();

	game->Init();

	while (game->Running()) {

		game->HandleEvents();
		if (game->GetRenderer().GetDraw())
		{
			game->Update();
			game->Render();
		}
		Sleep(100);
	}


	system("pause");
	return 0;
}
