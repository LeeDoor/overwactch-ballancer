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
	//if successfully added, returns true, false overwise
	static bool addPlayer(std::shared_ptr<Player> player);
	static bool addActivePlayer(std::shared_ptr<Player> player);

	//returns true if there is a given player in given list
	static bool hasPlayer(std::shared_ptr<Player> player);
	static bool hasActivePlayer(std::shared_ptr<Player> player);

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

	static void updateAllWithJson(std::string path);
	static void updateActWithJson(std::string path);
private:
	static std::vector<std::shared_ptr<Player>>::iterator allFindIter(std::shared_ptr<Player> p);
	static std::vector<std::shared_ptr<Player>>::iterator allFindIter(std::string name);
	static std::vector<std::weak_ptr<Player>>::iterator actFindIter(std::shared_ptr<Player> p);
	static std::vector<std::weak_ptr<Player>>::iterator actFindIter(std::string name);
};

