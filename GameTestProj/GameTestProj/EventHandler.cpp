#include "EventHandler.h"

EventHandler::EventHandler()
{
	_key = NOTHING;
}

EventHandler::~EventHandler()
{
}

void EventHandler::HandleEvent()
{
	//_key = NOTHING;
	if (GetAsyncKeyState(VK_UP))
	{
		_key = UP;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		_key = DOWN;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		_key = LEFT;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		_key = RIGHT;
	}
	if (GetAsyncKeyState(NUM_KEY_0))
	{
		_key = NUMKEY0;
	}
	if (GetAsyncKeyState(NUM_KEY_1))
	{
		_key = NUMKEY1;
	}
	if (GetAsyncKeyState(NUM_KEY_2))
	{
		_key = NUMKEY2;
	}
	if (GetAsyncKeyState(NUM_KEY_3))
	{
		_key = NUMKEY3;
	}
	if (GetAsyncKeyState(NUM_KEY_4))
	{
		_key = NUMKEY4;
	}
	if (GetAsyncKeyState(KEY_S))
	{
		_key = SAVE;
	}
	if (GetAsyncKeyState(KEY_L))
	{
		_key = LOAD;
	}
	//return _key;
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
			return NOTHING;
			break;
		}
	}
}

int EventHandler::GetKey() const
{
	return _key;
}

int EventHandler::GetNumKey() const
{
	return _key - NUMKEY0;
}

void EventHandler::ResetKey()
{
	_key = NOTHING;
}

bool EventHandler::ArrowKeyClicked()
{
	return (_key > NOTHING && _key < NUMKEY0);
}

bool EventHandler::EquipKeyClicked()
{
	return (_key > LEFT && _key < SAVE);
}

bool EventHandler::SaveKeyClicked()
{
	return (_key == SAVE);
}

bool EventHandler::LoadKeyClicked()
{
	return (_key == LOAD);
}
