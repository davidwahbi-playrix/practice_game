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

void Renderer::Render(Profile & profile, bool & running)
{
	if (GetDraw())
	{
		SetDraw(false);
		SaveLoadMenu();
		profile.GetBoard().Display2();
		if (profile.GetPlayer().GetInventory().Size() > 0)
		{
			RenderPlayerInventory(profile.GetPlayer());
		}
		RenderPlayer(profile.GetPlayer());
		if (profile.GetSmartEnemies().size() == 0)
		{
			profile.IncreseLevel();
			NextLevel(profile.GetLevel());
			profile.NewGame(running);
		}
		if (!running)
		{
			SetDraw(false);
		}
	}
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

/*void Renderer::Pause()
{
	bool loop = true;
	std::cout << "Press Enter to continue..." << std::endl;
	while (loop)
	{
		if (GetAsyncKeyState(VK_RETURN)) {
			loop = false;
		}
	}
}*/
