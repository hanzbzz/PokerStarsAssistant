#pragma once
#include "PlayerStats.h"
#include <string>

class Player {
public:
	Player(std::string name);
	void calculatePlayerStats();

private:
	PlayerStats playerStats;
	std::string name;

protected:
};