#pragma once
#include "Identity.h"
#include "Stats.h"

class Player
{
public:
	Identity identity;
	Stats stats;

	std::string createdAt;
};

