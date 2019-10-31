#include "Renderer.h"

Renderer::Renderer()
{
	this->_canEnter = true;
	this->_draw = false;
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
	this->_draw = value;
}

bool Renderer::GetDraw() const
{
	return this->_draw;
}

bool Renderer::GetFlag() const
{
	return this->_canEnter;
}
