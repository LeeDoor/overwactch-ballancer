#include "BallanceCounter.h"

void BallanceCounter::CapSquireMapper::begin(TEAMS_TYPE _teams, PLAYERS_TYPE _players) {
	players = _players;
	teams = _teams;
	map.clear();// на всякий

	//sort with main role rank
	std::sort(players->begin(), players->end(), [](PLAYER_TYPE p1, PLAYER_TYPE p2)->bool {
		return p1->mainRole()->rank > p2->mainRole()->rank;
		});

	//mapping captain-squire
	PLAYERS_TYPE wrongKeys = primaryMapping();
	PLAYERS_TYPE remained = wrongReplacing(wrongKeys);


}
PLAYERS_TYPE BallanceCounter::CapSquireMapper::primaryMapping() {
	PLAYERS_TYPE wrongPairKeys; // vector with captain players, whose pair is wrong (DPS-SUPPORT)
	for (int i = 0; i < teams->size(); ++i) {
		map[(*players)[i]] = (*players)[players->size() - 1 - i];
		if ((*players)[i]->mainRole()->type == Roles::Dps &&
			map[(*players)[i]]->mainRole()->type == Roles::Support) {
			wrongPairKeys->push_back((*players)[i]);
		}
	}
	return wrongPairKeys;
}

PLAYERS_TYPE BallanceCounter::CapSquireMapper::wrongReplacing(PLAYERS_TYPE keys) {
	PLAYERS_TYPE unpairedPlayers = std::make_shared<std::vector<PLAYER_TYPE>>();
	for (auto it = keys->begin(); it != keys->end(); ++it) {
		if (!findValidPair(keys, it, 0)) {
			unpairedPlayers->push_back(*it);
		}
	}
	return unpairedPlayers;
}
bool BallanceCounter::CapSquireMapper::findValidPair(PLAYERS_TYPE keys, std::vector<PLAYER_TYPE>::iterator it, int delt = 0) {
	auto cur1 = it - delt;
	auto cur2 = it + delt;
	if (it == cur1 && it == cur2) { // if its init call
		return	findValidPair(keys, it, delt + 1); // call recursion for previous and next key
	}
	if (cur1 == keys->begin() - 1) return false;
	if (cur2 == keys->end()) return false;

	if ((*cur1)->mainRole()->type != Roles::Dps &&
		map[*cur1]->mainRole()->type != Roles::Support) {
		if (std::count_if(keys->begin(), keys->end(),
			[&](PLAYER_TYPE p) {return p == *cur1; }) == 0) {
			std::swap(map[*it], map[*cur1]);
			return true;
		}
	}
	if ((*cur2)->mainRole()->type != Roles::Dps &&
		map[*cur2]->mainRole()->type != Roles::Support) {
		if (std::count_if(keys->begin(), keys->end(),
			[&](PLAYER_TYPE p) {return p == *cur2; }) == 0) {
			std::swap(map[*it], map[*cur2]);
			return true;
		}
	}

	return	findValidPair(keys, it, delt + 1); // call recursion for previous and next key
}