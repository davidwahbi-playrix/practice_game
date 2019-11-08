#include "EventHandler.h"

EventHandler::EventHandler()
{
}

EventHandler::~EventHandler()
{
}

int EventHandler::HandleEvent()
{
	int tmp = 100;
	if (GetAsyncKeyState(VK_UP))
	{
		tmp = UP;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		tmp = DOWN;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		tmp = LEFT;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		tmp = RIGHT;
	}
	if (GetAsyncKeyState(NUM_KEY_0))
	{
		tmp = NUMKEY0;
	}
	if (GetAsyncKeyState(NUM_KEY_1))
	{
		tmp = NUMKEY1;
	}
	if (GetAsyncKeyState(NUM_KEY_2))
	{
		tmp = NUMKEY2;
	}
	if (GetAsyncKeyState(NUM_KEY_3))
	{
		tmp = NUMKEY3;
	}
	if (GetAsyncKeyState(NUM_KEY_4))
	{
		tmp = NUMKEY4;
	}
	if (GetAsyncKeyState(KEY_S))
	{
		tmp = SAVE;
	}
	if (GetAsyncKeyState(KEY_L))
	{
		tmp = LOAD;
	}
	return tmp;
}

int EventHandler::HandleEvent2()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case KEY_UP:
			return UP;
			break;
		case KEY_RIGHT:
			return RIGHT;
			break;
		case KEY_DOWN:
			return DOWN;
			break;
		case KEY_LEFT:
			return LEFT;
			break;
		case NUM_KEY_0:
			return NUMKEY0;
			break;
		case NUM_KEY_1:
			return NUMKEY1;
			break;
		case NUM_KEY_2:
			return NUMKEY2;
			break;
		case NUM_KEY_3:
			return NUMKEY3;
			break;
		case NUM_KEY_4:
			return NUMKEY4;
			break;
		case 's':
			return SAVE;
			break;
		case 'l':
			return LOAD;
			break;
		default:
			break;
		}
	}
}
		
