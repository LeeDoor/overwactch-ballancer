#include "BallanceCounter.h"

void BallanceCounter::CapSquireMapper::begin(TEAMS_TYPE _teams, PLAYERS_TYPE _players) {
	players = _players;
	teams = _teams;
	pairs.clear();// на всякий

	//sort with main role rank
	std::sort(players->begin(), players->end(), [](PLAYER_TYPE p1, PLAYER_TYPE p2)->bool {
		return p1->mainRole()->rank > p2->mainRole()->rank;
		});

	//mapping captain-squire
	PLAYERS_TYPE wrongKeys = primaryMapping();
	PLAYERS_TYPE remained = wrongReplacing(wrongKeys);

	//nenaviju pometku TODO, ostavil ee chtobi ne zab_bIt
	//TODO: make smth with REMAINED
	for (int i = 0; i < teams->size(); ++i) {
		(*teams)[i]->addWithType(pairs[i].first);
		(*teams)[i]->captain = pairs[i].first->mainRole()->type;

		(*teams)[i]->addWithType(pairs[i].second);
		(*teams)[i]->squire = pairs[i].second->mainRole()->type;
	}

	return;
}
PLAYERS_TYPE BallanceCounter::CapSquireMapper::primaryMapping() {
	PLAYERS_TYPE wrongPairKeys = std::make_shared<std::vector<PLAYER_TYPE>>(); // vector with captain players, whose pair is wrong (DPS-SUPPORT)
	for (int i = 0; i < teams->size(); ++i) {
		std::pair<PLAYER_TYPE, PLAYER_TYPE> pair;
		pairs.push_back(pair);
		pairs[i].first = (*players)[i];
		pairs[i].second = (*players)[players->size() - 1 - i];
		if ((*players)[i]->mainRole()->type == Roles::Dps &&
			pairs[i].second->mainRole()->type == Roles::Support) {
			wrongPairKeys->push_back((*players)[i]);
		}
	}
	return wrongPairKeys;
}

PLAYERS_TYPE BallanceCounter::CapSquireMapper::wrongReplacing(PLAYERS_TYPE keys) {
	PLAYERS_TYPE unpairedPlayers = std::make_shared<std::vector<PLAYER_TYPE>>();
	for (int i = 0; i < keys->size(); ++i) {
		if (!findValidPair(keys, i)) {
			unpairedPlayers->push_back((*keys)[i]);
		}
	}
	return unpairedPlayers;
}
bool BallanceCounter::CapSquireMapper::findValidPair(PLAYERS_TYPE keys, int id, int delt) {
	auto cur1 = id - delt;
	auto cur2 = id + delt;
	if (cur1 <= -1 && cur2 >= pairs.size())return false;
	bool res = false;
	if (cur1 > -1) res = isFound(keys, id, cur1);
	if (res)return res;
	if (cur2 < pairs.size()) res = isFound(keys, id, cur2);
	if (res) return res;

	return findValidPair(keys, id, delt + 1); // call recursion for previous and next key
}

bool BallanceCounter::CapSquireMapper::isFound(PLAYERS_TYPE keys, int curId, int compId) {
	if (pairs[compId].first->mainRole()->type != Roles::Dps &&
		pairs[compId].second->mainRole()->type != Roles::Support) {
		if (std::count_if(keys->begin(), keys->end(),
			[&](PLAYER_TYPE p) {return p == pairs[compId].first; }) == 0) {
			std::swap(pairs[curId].second, pairs[compId].second);
			return true;
		}
	}
	return false;
}