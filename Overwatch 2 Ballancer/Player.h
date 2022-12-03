#pragma once
#include "Identity.h"
#include "Stats.h"

// отдельный игрок
class Player
{
public:
	Identity identity;
	Stats stats;

	std::string createdAt;
};

