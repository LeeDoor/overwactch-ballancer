#include "BallanceCounter.h"
void BallanceCounter::MainRecursiveBallance::begin(
	TEAMS_TYPE teams, PLAYERS_TYPE players, std::map<PLAYER_TYPE, bool> playersDone) {
	ROLE_STATS roleStats = countRoleStats(teams, players);
	analizing(roleStats, teams, players);
}

void BallanceCounter::MainRecursiveBallance::analizing(
	ROLE_STATS roleStats, TEAMS_TYPE teams, PLAYERS_TYPE players) {
	float average = getAverageRank(teams); // average rank of all teams or all ballanced teams
	float maxDev = average; // maximum deviation from average
	int idDev = 0; // id of max deviated team
	for (int i = 0; i < teams->size(); ++i) {
		float curDev = (*teams)[i]->getAverageRank() - average;
		if (abs(curDev) > abs(maxDev)) {
			maxDev = curDev;
			idDev = 0;
		}
	}
	PLAYER_TYPE adding;
	if (maxDev < 0) {
		adding = bestPlayerForTeam(players, (*teams)[idDev], average, [](float a, float b) {
			return a < b; // mb mistake here
		});
	}
	else {
		adding = bestPlayerForTeam(players, (*teams)[idDev], average, [](float a, float b) {
			return a > b; // mb mistake here
			});
	}
}

ROLE_STATS BallanceCounter::MainRecursiveBallance::countRoleStats(TEAMS_TYPE teams, PLAYERS_TYPE players) {
	//          Sum needed | Sum in main | Sum in sub
	// Tank
	// Dps
	// Support
	//
	// roleStats[sum][role]
	ROLE_STATS roleStats{};
	//count needed
	std::for_each(teams->begin(), teams->end(), [&](TEAM_TYPE& t) {
		auto req = t->needed();
		for (int i = 0; i < 3; ++i) {
			roleStats[AR_SUM_NEED][i] += req[i];
		}
	});
	//count main
	for_each(players->begin(), players->end(), [&](PLAYER_TYPE& p) {
		Roles cur = p->mainRole()->type;
		roleStats[AR_SUM_MAIN][cur]++;
	});
	for (int i = 0; i < 3; ++i) {
		roleStats[AR_SUM_SUB][i] = roleStats[AR_SUM_NEED][i] - roleStats[AR_SUM_MAIN][i];
	}
	return roleStats;
}

PLAYER_TYPE BallanceCounter::MainRecursiveBallance::bestPlayerForTeam
(PLAYERS_TYPE players, TEAM_TYPE team, float average, std::function<bool(float, float)> pred) {
	auto player = std::find(players->begin(), players->end(), [&](PLAYER_TYPE& player) {
		return pred(player->mainRole()->rank, average) &&
		team->needed()[player->mainRole()->type] != 0;
	});
	if (player == players->end()) {
		auto allRequired = PlayersTeamsManager::findAllPlayers(players,
			[&](PLAYER_TYPE& player) {
				return team->needed()[player->mainRole()->type] != 0;
			});
		player = std::max_element(allRequired->begin(), allRequired->end(),
			[&](PLAYER_TYPE& p1, PLAYER_TYPE& p2) {
				return pred(p1->mainRole()->rank, p2->mainRole()->rank);
			});
	}
}

float BallanceCounter::MainRecursiveBallance::getAverageRank(TEAMS_TYPE teams) {
	bool isFilled = false;
	float sum = 0;
	std::for_each(teams->begin(), teams->end(), [&](TEAM_TYPE& team) {
		if (team->isFilled()) isFilled = true;
		sum += team->getAverageRank();
	}); 
	if (isFilled) {
		float fillSum = 0;
		int amount = 0;
		for (int i = 0; i < teams->size(); ++i) {
			if ((*teams)[i]->isFilled()) {
				fillSum += (*teams)[i]->getAverageRank();
				++amount;
			}
			return fillSum / amount;
		}
	}
	else {
		return sum / teams->size();
	}
}