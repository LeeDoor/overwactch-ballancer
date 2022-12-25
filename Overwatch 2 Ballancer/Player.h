#pragma once
#include "Identity.h"
#include "Stats.h"

struct Player
{
public:
	Identity identity;
	Stats stats;
	std::string createdAt;
	int isChosen; // is this player's role identified

	bool operator == (Player player);
	bool operator == (std::string pk);

	Player();

	std::string PK();
	Role* mainRole();
};

