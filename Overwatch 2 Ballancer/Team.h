#pragma once
#include <memory>
#include <array>
#include <vector>
#include "Player.h"
#include "Roles.h"

typedef std::shared_ptr<Player> PLAYER_TYPE;
typedef std::shared_ptr<std::vector<PLAYER_TYPE>> PLAYERS_TYPE;
#define TANK_ID 0
#define DPS1_ID 1
#define DPS2_ID 2
#define SUP1_ID 3
#define SUP2_ID 4

class Team
{
private:
	std::array<PLAYER_TYPE, 5> players;

public:
	Roles squire;
	Roles captain;

	void addTank(PLAYER_TYPE player);
	void addDps(PLAYER_TYPE player);
	void addSupport(PLAYER_TYPE player);
	void addWithType(PLAYER_TYPE player);

	float getAverageRank();
	int getOffclassAmount();
	int getOffclassDouble();
	int getLowrankDouble();
};

