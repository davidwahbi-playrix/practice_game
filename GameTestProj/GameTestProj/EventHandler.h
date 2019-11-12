#pragma once
#include <Windows.h>
#include <conio.h>
#include "LoadGame.h"
#include "SaveGame.h"

constexpr auto KEY_UP = 72;
constexpr auto KEY_DOWN = 80;
constexpr auto KEY_LEFT = 75;
constexpr auto KEY_RIGHT = 77;
constexpr auto NUM_KEY_0 = 48;
constexpr auto NUM_KEY_1 = 49;
constexpr auto NUM_KEY_2 = 50;
constexpr auto NUM_KEY_3 = 51;
constexpr auto NUM_KEY_4 = 52;
constexpr auto KEY_S = 83;
constexpr auto KEY_L = 76;

enum eDirection { NOTHING = 0, UP, RIGHT, DOWN, LEFT, NUMKEY0, NUMKEY1, NUMKEY2, NUMKEY3, NUMKEY4, SAVE, LOAD};

class EventHandler
{
public:
	EventHandler();
	~EventHandler();
	void HandleEvent();
	int HandleArrowEvent();
	int HandleEvent2();

	int GetKey() const;
	int GetNumKey() const;
	void ResetKey();
	bool ArrowKeyClicked();
	bool EquipKeyClicked();
	bool SaveKeyClicked();
	bool LoadKeyClicked();
private:
	int _key;
};

