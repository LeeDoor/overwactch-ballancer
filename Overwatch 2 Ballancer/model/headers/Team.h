#pragma once
#include <memory>
#include <array>
#include <vector>
#include "Player.h"
#include "Roles.h"
#include "PList.h"

#define TANK_ID 0
#define DPS1_ID 1
#define DPS2_ID 2
#define SUP1_ID 3
#define SUP2_ID 4

class Team
{
private:
	std::array<std::shared_ptr<Player>, 5> players;
	float averageRank;

	void countAverageRank();
public:
	Roles squire;
	Roles captain;

	float getAverageRank();

	void addTank(std::shared_ptr<Player> player);
	void addDps(std::shared_ptr<Player> player);
	void addSupport(std::shared_ptr<Player> player);
	void addWithType(std::shared_ptr<Player> player);

	int getOffclassAmount();
	int getOffclassDouble();
	int getLowrankDouble();
	std::array<int, 3> needed();
	bool isFilled();
};
