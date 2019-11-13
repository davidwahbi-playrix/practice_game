#include "EventHandler.h"

EventHandler::EventHandler()
{
}

EventHandler::~EventHandler()
{
}

void EventHandler::HandleEvent2(MoveUnit& unitMover, Renderer& renderer, Profile& profile, SaveGame& saver, LoadGame& loader)
{
	if (GetAsyncKeyState(VK_UP))
	{
		ArrowPressed(unitMover, renderer, UP);
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		ArrowPressed(unitMover, renderer, DOWN);
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		ArrowPressed(unitMover, renderer, LEFT);
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		ArrowPressed(unitMover, renderer, RIGHT);
	}
	if (GetAsyncKeyState(NUM_KEY_0))
	{
		NumberPressed(renderer, profile, NUMKEY0);
	}
	if (GetAsyncKeyState(NUM_KEY_1))
	{
		NumberPressed(renderer, profile, NUMKEY1);
	}
	if (GetAsyncKeyState(NUM_KEY_2))
	{
		NumberPressed(renderer, profile, NUMKEY2);
	}
	if (GetAsyncKeyState(NUM_KEY_3))
	{
		NumberPressed(renderer, profile, NUMKEY3);
	}
	if (GetAsyncKeyState(NUM_KEY_4))
	{
		NumberPressed(renderer, profile, NUMKEY4);
	}
	if (GetAsyncKeyState(KEY_S))
	{
		saver.SaveSmartGameState(profile.GetLevel(), profile.GetPlayer(), profile.GetSmartEnemies(), profile.GetGameItems());
	}
	if (GetAsyncKeyState(KEY_L))
	{
		LoadPressed(loader, profile);
	}
}

void EventHandler::ArrowPressed(MoveUnit & unitMover, Renderer & renderer, const int arrow)
{
	renderer.ClearView();
	unitMover.SetDir(arrow);
	renderer.SetDraw(true);
}

void EventHandler::NumberPressed(Renderer & renderer, Profile & profile, const int number)
{
	if (profile.GetPlayer().GetCanEquip())
	{
		renderer.ClearView();
		profile.GetPlayer2().SetCanEquip(false);
		profile.GetPlayer2().SetEquipInd(number);
		profile.GetPlayer2().SetEquipAction(true);
		renderer.SetDraw(true);
	}
}

void EventHandler::LoadPressed(LoadGame & loader, Profile & profile)
{
	loader.LoadSmartGameState();
	profile.SetLevel(loader.GetCurrentLevel());
	profile.SetPlayer(loader.GetPlayer());
	profile.SetSmartEnemies(loader.GetSmartEnemies());
	profile.SetGameItems(loader.GetGameInventory());
	profile.SetBoard(loader.GetBoard());
}
