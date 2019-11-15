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
		saver.SaveSmartGameState2(profile.GetLevel(), profile.GetSmartPlayer2(), profile.GetSmartEnemies(), profile.GetSmartGameItems());
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
	if (profile.GetSmartPlayer2().GetCanEquip())
	{
		renderer.ClearView();
		profile.GetSmartPlayer2().SetCanEquip(false);
		profile.GetSmartPlayer2().SetEquipInd(number);
		profile.GetSmartPlayer2().SetEquipAction(true);
		renderer.SetDraw(true);
	}
}

void EventHandler::LoadPressed(LoadGame & loader, Profile & profile)
{
	loader.LoadSmartGameState3(profile.GetLevel2(), profile.GetSmartGameItems(), profile.GetSmartPlayer2(), profile.GetSmartEnemies2(), profile.GetBoard2());
}
