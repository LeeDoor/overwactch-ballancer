#pragma once
#include "Identity.h"
#include "Stats.h"

struct Player
{
public:
	Identity identity;
	Stats stats;
	std::string createdAt;

	bool operator == (Player player);
	bool operator == (std::string name);
};

