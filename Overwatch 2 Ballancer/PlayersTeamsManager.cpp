#include "PlayersTeamsManager.h"


PLAYERS_TYPE PlayersTeamsManager::findAllPlayers(PLAYERS_TYPE players, std::function<bool(PLAYER_TYPE&)> pred) {
	PLAYERS_TYPE res = std::make_shared<std::vector<PLAYER_TYPE>>();
	std::for_each(players->begin(), players->end(),
		[&](PLAYER_TYPE& p) {
			if (pred(p)) res->push_back(p);
		});
	return res;
}
TEAMS_TYPE PlayersTeamsManager::findAllTeams(TEAMS_TYPE teams, std::function<bool(TEAM_TYPE&)> pred) {
	TEAMS_TYPE res = std::make_shared<std::vector<TEAM_TYPE>>();
	std::for_each(teams->begin(), teams->end(),
		[&](TEAM_TYPE& p) {
			if (pred(p)) res->push_back(p);
		});
	return res;
}