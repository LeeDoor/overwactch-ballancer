#pragma once
#include "Player.h"
#include <map>

struct JSON {
	std::string format;
	std::map<std::string, Player> players;
};