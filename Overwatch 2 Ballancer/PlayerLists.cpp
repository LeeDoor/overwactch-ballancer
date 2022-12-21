#include "PlayerLists.h"
#include "JSONParser.h"
#include <algorithm>

std::vector<std::shared_ptr<Player>> PlayerLists::allPlayers;
std::vector<std::weak_ptr<Player>> PlayerLists::actPlayers;

bool PlayerLists::addPlayer(std::shared_ptr<Player> player) {
	bool exists = (bool)hasPlayer(player);
	if (!exists) {
		allPlayers.push_back(player);
		return true;
	}
	return false;
}

std::shared_ptr<Player> PlayerLists::addActivePlayer(std::shared_ptr<Player> player) {
	if (hasActivePlayer(player)) {
		return nullptr;
	}
	else {
		addPlayer(player);
		std::shared_ptr<Player> pl = *allFindIter(player);
		actPlayers.push_back(pl);
		return pl;
	}
}

bool PlayerLists::hasPlayer(std::shared_ptr<Player> player) {
	auto iter = allFindIter(player);
	if (iter == allPlayers.end()) return false;
	return true;
}
bool PlayerLists::hasActivePlayer(std::shared_ptr<Player> player) {
	auto iter = actFindIter(player);
	if (iter == actPlayers.end()) return false;
	return true;
}

std::shared_ptr<Player> PlayerLists::editPlayer(std::string lastName, std::shared_ptr<Player> newPlayer) {
	auto iter = allFindIter(lastName);
	if (iter == allPlayers.end())return nullptr;
	*(* iter) = (*newPlayer);
	return *iter;
}


bool PlayerLists::removePlayer(std::shared_ptr<Player> player) {
	removeActPlayer(player);
	auto iter = allFindIter(player);
	if (iter == allPlayers.end())return false;
	allPlayers.erase(iter);
	return true;
}

bool PlayerLists::removeActPlayer(std::shared_ptr<Player> player) {
	auto iter = actFindIter(player);
	if (iter == actPlayers.end())return false;
	actPlayers.erase(iter);
	return true;
}

std::vector<std::shared_ptr<Player>>::iterator PlayerLists::allFindIter(std::shared_ptr<Player> p) {
	return allFindIter(p->identity.name);//ne menat ta pk
}
std::vector<std::shared_ptr<Player>>::iterator PlayerLists::allFindIter(std::string name) {
	return std::find_if(allPlayers.begin(), allPlayers.end(),
		[&](std::shared_ptr<Player>& p) {
			return (p->identity.name.compare(name) == 0);
		});
}

std::vector<std::weak_ptr<Player>>::iterator PlayerLists::actFindIter(std::shared_ptr<Player> p) {
	return actFindIter(p->identity.name);
}
std::vector<std::weak_ptr<Player>>::iterator PlayerLists::actFindIter(std::string name) {
	return std::find_if(actPlayers.begin(), actPlayers.end(),
		[&](std::weak_ptr<Player> p) { 
			return p.lock()->identity.name.compare(name) == 0;
		});
}