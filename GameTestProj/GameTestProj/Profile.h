#pragma once
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <memory>
class Profile
{
public:
	Profile();
	~Profile();

	void NewGame();

	Player GetPlayer() const;
	Inventory GetGameItems() const;
	Board GetBoard() const;
	std::vector<std::shared_ptr<Enemy>> GetSmartEnemies() const;

	void SetPlayer(const Player& player);
	void SetGameItems(const Inventory& inv);
	void SetBoard(const Board& board);
	void SetSmartEnemies(const std::vector<std::shared_ptr<Enemy>> smartEnemies);
private:
	Player _player;
	std::vector<std::shared_ptr<Enemy>> _smartEnemies;
	Inventory _gameItems;
	Board _board;
};

