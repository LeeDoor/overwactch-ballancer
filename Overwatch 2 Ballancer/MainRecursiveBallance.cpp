#include "BallanceCounter.h"
void BallanceCounter::MainRecursiveBallance::begin(
	TEAMS_TYPE teams, PLAYERS_TYPE players, std::map<PLAYER_TYPE, bool> playersDone) {
	ROLE_STATS roleStats = countRoleStats(teams, players);
	analizing(roleStats, teams, PlayersTeamsManager::findAllPlayers(players, [&](PLAYER_TYPE& p) {return p->isChosen; }));
}

void BallanceCounter::MainRecursiveBallance::analizing(
	ROLE_STATS roleStats, TEAMS_TYPE teams, PLAYERS_TYPE players) {
	float average = getAverageRank(teams); // average rank of all teams or all ballanced teams

	//first we need to ballance all players whos roles are more than needed
	for (int i = 0; i < 3; ++i) {
		auto curMainPl = PlayersTeamsManager::findAllPlayers(players, [&](PLAYER_TYPE& p) {
			return p->mainRole()->type == i;
		});
		auto curTeams = PlayersTeamsManager::findAllTeams(teams, [&](TEAM_TYPE& t) {
			return t->needed()[i] > 0;
		});
		for (int r = 0; 0 < roleStats[AR_SUM_MAIN][i]; ++r) {
			std::vector<TEAM_TYPE>::iterator curTeam = std::max_element(curTeams->begin(), curTeams->end(), [&](TEAM_TYPE& t1, TEAM_TYPE& t2) {
				return abs(average - t1->getAverageRank()) < abs(average - t2->getAverageRank());
			}); // find team with most difference in average rank
			std::vector<PLAYER_TYPE>::iterator curPlayer; // current player
			if (average - (**curTeam).getAverageRank() < 0)  // if current team is the weakest find stronger player
				curPlayer = std::max_element(curMainPl->begin(), curMainPl->end(), [&](PLAYER_TYPE& p1, PLAYER_TYPE& p2) {
					return p1->mainRole()->rank < p2->mainRole()->rank;
				});
			//else find weakest player
			else curPlayer = std::min_element(curMainPl->begin(), curMainPl->end(), [&](PLAYER_TYPE& p1, PLAYER_TYPE& p2) {
					return p1->mainRole()->rank < p2->mainRole()->rank;
				});
			
			(**curTeam).addWithType(*curPlayer);
			if ((**curTeam).needed()[i] == 0) curTeams->erase(curTeam);
			curMainPl->erase(curPlayer);
			--roleStats[AR_SUM_MAIN][i];
			--roleStats[AR_SUM_NEED][i];
		}
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

PLAYER_TYPE BallanceCounter::MainRecursiveBallance::bestPlayerForTeam (PLAYERS_TYPE players, TEAM_TYPE team, float average) {
	
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