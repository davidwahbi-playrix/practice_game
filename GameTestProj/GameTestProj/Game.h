#pragma once
#include <fstream>
#include <sstream>
#include "Player.h"
#include "Enemy.h"
#include "SaveGame.h"
#include "LoadGame.h"
class Game
{
public:
	Game();
	~Game();

	void Init();
	void HandleEvents();
	void Update();
	void Render();
	void Clean();
	void UpdatePlayerInventory();
	void Battle();

	void EquipItem(const int index);

	void SaveLoadMenu();

	//void LoadGame();
	void LoadGameItems(std::ifstream& file, const int size);
	void LoadPlayer(std::ifstream& file);
	void LoadPlayerIneventory(std::ifstream& file, const int size);
	void LoadPlayerEquipment(std::ifstream& file, const int state);
	void LoadEnemy(std::ifstream& file);
	void LoadBoard();

	unsigned int GetGameItemIndex(const int x, const int y);
	bool Running();
	bool Draw();
	bool HasFile();
	void SetHesFile(bool flag);
	int ReadIntFromFile(std::ifstream& file);
private:
	bool _isRunning;
	bool _draw;
	bool _equip;
	bool _canEquip;
	bool _hasFile;
	int _dir;
	int _equipInd;
	Player _player;
	Enemy* _enemy;
	Board _board;
	Inventory _gameItems;
};
