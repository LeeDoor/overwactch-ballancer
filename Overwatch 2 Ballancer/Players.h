#pragma once
#include <vector>
#include "Player.h"
#include <memory>

class Players
{
	std::vector<std::shared_ptr<Player>> players;
};

