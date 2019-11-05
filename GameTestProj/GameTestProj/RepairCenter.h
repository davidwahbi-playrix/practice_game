#pragma once
#include <iostream>
#include "Player.h"
class RepairCenter
{
public:
	RepairCenter();
	~RepairCenter();

	int ReapirEquipment(Player player);

	void SetExit(const bool& value);
private:
	bool _exit;
};

