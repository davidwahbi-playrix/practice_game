#include "Renderer.h"
#include <Windows.h>

Renderer::Renderer()
{
	_canEnter = true;
	_draw = false;
}

Renderer::~Renderer()
{
}

void Renderer::RenderPlayerInventory(Player player) const
{

	std::cout << "Player inventory:" << std::endl;
	std::cout << player.GetInventory().toString() << '\n';
	std::cout << "Equip/Consume item using keys 0,1,2..." << '\n';
}

void Renderer::RenderPlayer(Player player) const
{
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

void Renderer::SetDraw(const bool& value)
{
	_draw = value;
}

void Renderer::ClearView()
{
	system("cls");
}

void Renderer::NextLevel(int level)
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "***CONGRATULATIONS***" << std::endl;
	std::cout << std::endl;
	std::cout << "Level completed!" << std::endl;
	std::cout << std::endl;
	std::cout << "Next level: " << "LEVEL " << std::to_string(level) << "!" << std::endl;
	system("pause");
}

bool Renderer::GetDraw() const
{
	return _draw;
}

bool Renderer::GetFlag() const
{
	return _canEnter;
}
