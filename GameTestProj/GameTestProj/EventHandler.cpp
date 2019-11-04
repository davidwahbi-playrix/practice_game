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
		tmp = 1;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		tmp = 3;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		tmp = 4;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		tmp = 2;
	}
	if (GetAsyncKeyState(0x30))
	{
		tmp = 5;
	}
	if (GetAsyncKeyState(0x31))
	{
		tmp = 6;
	}
	if (GetAsyncKeyState(0x32))
	{
		tmp = 7;
	}
	if (GetAsyncKeyState(0x33))
	{
		tmp = 8;
	}
	if (GetAsyncKeyState(0x34))
	{
		tmp = 9;
	}
	if (GetAsyncKeyState(0x53))
	{
		tmp = 10;
	}
	if (GetAsyncKeyState(0x4C))
	{
		tmp = 11;
	}
	return tmp;
}
		
