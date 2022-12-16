#include "PlayerLists.h"
#include <algorithm>

std::vector<std::shared_ptr<Player>> PlayerLists::allPlayers;
std::vector<std::weak_ptr<Player>> PlayerLists::actPlayers;

bool PlayerLists::addPlayer(std::shared_ptr<Player> player) {
	bool exists = (bool)hasPlayer(player);
	if (!exists) {
		allPlayers.push_back(player);
	}
	return !exists;
}

int PlayerLists::addActivePlayer(std::shared_ptr<Player> player) {
	if (hasActivePlayer(player)) {
		return 2;
	}
	else if (hasPlayer(player)) {
		actPlayers.push_back(player);
		return 1;
	}
	else {
		addPlayer(player);
		actPlayers.push_back(player);
		return 0;
	}
}

std::shared_ptr<Player> PlayerLists::hasPlayer(std::shared_ptr<Player> player) {
	auto iter = std::find(allPlayers.begin(), allPlayers.end(), player);
	if (iter == allPlayers.end()) return nullptr;
	return *iter;
}
std::shared_ptr<Player> PlayerLists::hasActivePlayer(std::shared_ptr<Player> player) {
	std::vector<std::weak_ptr<Player>>::iterator iter = std::find_if(actPlayers.begin(), actPlayers.end(), 
		[&](std::weak_ptr<Player> p) { return *p.lock() == *player; });
	if (iter == actPlayers.end()) return nullptr;
	return iter->lock();
}

std::shared_ptr<Player> PlayerLists::editPlayer(std::string lastName, std::shared_ptr<Player> newPlayer) {
	auto iter = std::find_if(allPlayers.begin(), allPlayers.end(), 
	[&](std::shared_ptr<Player>& p) {
		return (p->identity.name.compare(lastName) == 0);
	});
	if (iter == allPlayers.end())return nullptr;
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
	auto iter = std::find_if(actPlayers.begin(), actPlayers.end(),
		[&](std::weak_ptr<Player> p) { return *p.lock() == *player; });
	if (iter == actPlayers.end())return false;
	actPlayers.erase(iter);
	return true;
}