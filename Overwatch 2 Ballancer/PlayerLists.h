#pragma once
#include <vector>
#include <memory>
#include "Player.h"

class PlayerLists
{
public:
	static std::vector<std::shared_ptr<Player>> allPlayers;
	static std::vector<std::weak_ptr<Player>> actPlayers;

	//add player to list. return true if player added
	//return false if player already exists
	static bool addPlayer(std::shared_ptr<Player> player);

	//adds a player to active players list. 
	//if player already exists in thie list, reutrns 2.
	//if player exists in global list, adds and returns 1
	//if player does not exist anywhere, adds to both lists and returns 0
	static int addActivePlayer(std::shared_ptr<Player> player);

	//returns true if there is a given player in given list
	static std::shared_ptr<Player> hasPlayer(std::shared_ptr<Player> player);
	static std::shared_ptr<Player> hasActivePlayer(std::shared_ptr<Player> player);

	//edits player with given name to given stats
	//returns true if success, returns true if player not found
	static std::shared_ptr<Player> editPlayer(std::string lastName, 
								std::shared_ptr<Player> newPlayer);

	//removes given player from global list. finds this player
	//in actives, and if finds, removes too
	//returns true if player found and removed, false overwise
	static bool removePlayer(std::shared_ptr<Player> player);

	//finds and removes active player. it remains in global list.
	//returns true if player found and removed, false overwise
	static bool removeActPlayer(std::shared_ptr<Player> player);

};

