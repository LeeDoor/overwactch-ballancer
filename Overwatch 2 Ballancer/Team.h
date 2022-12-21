#pragma once
#include <memory>
#include <array>
#include "Player.h"
#include "Roles.h"

#define TANK_ID 0
#define DPS1_ID 1
#define DPS2_ID 2
#define SUP1_ID 3
#define SUP2_ID 4

class Team
{
private:
	std::array<std::shared_ptr<Player>, 5> players;

public:
	Roles squire;
	Roles captain;

	void addTank(std::shared_ptr<Player>);
	void addDps(std::shared_ptr<Player>);
	void addSupport(std::shared_ptr<Player>);

	float getAverageRank();
	int getOffclassAmount();
	int getOffclassDouble();
	int getLowrankDouble();
};

