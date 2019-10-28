#include "Renderer.h"

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::Render(Board board, Player player)
{
	this->SaveLoadMenu();
	board = player.GetBoard();
	board.Display();
	if (player.GetInventory().Size() > 0)
	{
		std::cout << "Player inventory:" << std::endl;
		std::cout << player.GetInventory().toString() << '\n';
		std::cout << "Equip/Consume item using keys 0,1,2..." << '\n';
	}
	std::cout << player.toString();
}

void Renderer::SaveLoadMenu()
{
	std::cout << "s -> Save game." << '\n';
	std::ifstream hasFile("SaveGame.txt");
	if (!hasFile.fail())
	{
		std::cout << "l -> Load game." << '\n';
	}
	std::cout << '\n';
}
