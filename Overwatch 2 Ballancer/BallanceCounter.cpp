#include "BallanceCounter.h"
#include <array>

///standart funcs
BallanceCounter::BallanceCounter() {}	
BallanceCounter::BallanceCounter(PLAYERS_TYPE _players) {
	setPlayers(_players);
}
void BallanceCounter::setPlayers(PLAYERS_TYPE _players) {
	players = _players;
}


void BallanceCounter::teamsInit() {
	int size = players->size() / 5;
	for (int i = 0; i < size; ++i) {
		teams->push_back(std::make_shared<Team>());
	}
}

void BallanceCounter::fillDpsCaptain() {
	// find all teams with dps cap and non-dps squire
	TEAMS_TYPE subteams = PlayersTeamsManager::findAllTeams(teams, [](TEAM_TYPE& t)->bool {
		return t->captain == Roles::Dps && t->squire != Roles::Dps;
	});
	if (subteams->size() == 0)return;
	//find all unchosen dps players
	PLAYERS_TYPE players = PlayersTeamsManager::findAllPlayers(players, [](PLAYER_TYPE& p)->bool {
		return p->mainRole()->type == Roles::Dps && !p->isChosen;
	});
	//sort by rank
	std::sort(players->begin(), players->end(), [](PLAYER_TYPE& p1, PLAYER_TYPE& p2) {
		return p1->mainRole()->rank < p2->mainRole()->rank;
	});

	for (int i = 0; i < std::min(subteams->size(), players->size()); ++i) {
		(*subteams)[i]->addDps((*players)[i]);
	}
}


/// public
void BallanceCounter::ballance(PLAYERS_TYPE _players) {
	setPlayers(_players);
	teamsInit();
	CapSquireMapper csm;
	//adding squires and captains
	csm.begin(teams, players);
	fillDpsCaptain();


}