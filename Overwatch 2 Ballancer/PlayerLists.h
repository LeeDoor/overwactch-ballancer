#pragma once
#include "Players.h"

class PlayerLists
{
private:
	static Players allPlayers;
	static Players activePlayers;

public:
	static void addPlayer(std::shared_ptr<Player> player);
	static void addActivePlayer(std::shared_ptr<Player> player);
	static void hasPlayer(std::shared_ptr<Player> player);
	static void hasActivePlayer(std::shared_ptr<Player> player);
	static void editPlayer(std::string lastName, std::shared_ptr<Player> newPlayer);
};

