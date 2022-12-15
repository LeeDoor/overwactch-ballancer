#include "PlayerLists.h"
#include <algorithm>

bool PlayerLists::addPlayer(std::shared_ptr<Player> player) {
	bool exists = (bool)hasPlayer(player);
	if (!exists) {
		allPlayers.push_back(player);
	}
	return exists;
}

bool PlayerLists::addActivePlayer(std::shared_ptr<Player> player) {
	if (hasActivePlayer(player)) {
		return false;
	}
	else if (hasPlayer(player)) {
		actPlayers.push_back(player);
	}
}

std::shared_ptr<Player> PlayerLists::hasPlayer(std::shared_ptr<Player> player) {
	auto iter = std::find(allPlayers.begin(), allPlayers.end(), player);
	if (iter == allPlayers.end()) return nullptr;
	return *iter;
}
std::shared_ptr<Player> PlayerLists::hasActivePlayer(std::shared_ptr<Player> player) {
	auto iter = std::find(actPlayers.begin(), actPlayers.end(), player);
	if (iter == actPlayers.end()) return nullptr;
	return iter->lock();
}

std::shared_ptr<Player> PlayerLists::editPlayer(std::string lastName, std::shared_ptr<Player> newPlayer) {
	auto iter = std::find_if(allPlayers.begin(), allPlayers.end(), [&](std::shared_ptr<Player> p) {
		p->identity.name == lastName; 
	});
	if (iter == allPlayers.end())return false;
	*iter = newPlayer;
	return *iter;
}


bool PlayerLists::removePlayer(std::shared_ptr<Player> player) {
	auto iter = std::find(allPlayers.begin(), allPlayers.end(), player);
	if (iter == allPlayers.end())return false;

	std::remove(allPlayers.begin(), allPlayers.end(), player);
	allPlayers.erase(iter);
	iter->reset();
	return true;
}

bool PlayerLists::removeActPlayer(std::shared_ptr<Player> player) {
	auto iter = std::find(actPlayers.begin(), actPlayers.end(), player);
	if (iter == actPlayers.end())return false;
	actPlayers.erase(iter);
	return true;
}