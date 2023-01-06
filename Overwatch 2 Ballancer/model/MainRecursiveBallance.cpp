#include "BallanceCounter.h"
void BallanceCounter::MainRecursiveBallance::begin(PList<std::shared_ptr<Team>> teams, PList<std::shared_ptr<Player>> players) {
	ROLE_STATS roleStats = countRoleStats(teams, players);
	analizing(roleStats, teams, players.findAll([&](std::shared_ptr<Player>& p)->bool { return p->isChosen; }));
}

void BallanceCounter::MainRecursiveBallance::analizing(
	ROLE_STATS roleStats, PList<std::shared_ptr<Team>> teams, PList<std::shared_ptr<Player>> players) {
	float average = getAverageRank(teams); // average rank of all teams or all ballanced teams

	//first we need to ballance all players whos roles are more than needed
	for (int i = 0; i < 3; ++i) {
		auto curMainPl = players.findAll([&](std::shared_ptr<Player>& p) {
			return p->mainRole()->type == i;
		});
		auto curTeams = teams.findAll([&](std::shared_ptr<Team>& t) {
			return t->needed()[i] > 0;
		});
		for (int r = 0; 0 < roleStats[AR_SUM_MAIN][i]; ++r) {
			std::vector<std::shared_ptr<Team>>::iterator curTeam = std::max_element(curTeams->begin(), curTeams->end(), [&](std::shared_ptr<Team>& t1, std::shared_ptr<Team>& t2) {
				return abs(average - t1->getAverageRank()) < abs(average - t2->getAverageRank());
			}); // find team with most difference in average rank
			std::vector<std::shared_ptr<Player>>::iterator curPlayer; // current player
			if (average - (**curTeam).getAverageRank() < 0)  // if current team is the weakest find stronger player
				curPlayer = std::max_element(curMainPl->begin(), curMainPl->end(), [&](std::shared_ptr<Player>& p1, std::shared_ptr<Player>& p2) {
					return p1->mainRole()->rank < p2->mainRole()->rank;
				});
			//else find weakest player
			else curPlayer = std::min_element(curMainPl->begin(), curMainPl->end(), [&](std::shared_ptr<Player>& p1, std::shared_ptr<Player>& p2) {
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

ROLE_STATS BallanceCounter::MainRecursiveBallance::countRoleStats(PList<std::shared_ptr<Team>> teams, PList<std::shared_ptr<Player>> players) {
	//          Sum needed | Sum in main | Sum in sub
	// Tank
	// Dps
	// Support
	//
	// roleStats[sum][role]
	ROLE_STATS roleStats{};
	//count needed
	std::for_each(teams->begin(), teams->end(), [&](std::shared_ptr<Team>& t) {
		auto req = t->needed();
		for (int i = 0; i < 3; ++i) {
			roleStats[AR_SUM_NEED][i] += req[i];
		}
	});
	//count main
	std::for_each(players->begin(), players->end(), [&](std::shared_ptr<Player>& p) {
		Roles cur = p->mainRole()->type;
		roleStats[AR_SUM_MAIN][cur]++;
	});
	for (int i = 0; i < 3; ++i) {
		roleStats[AR_SUM_SUB][i] = roleStats[AR_SUM_NEED][i] - roleStats[AR_SUM_MAIN][i];
	}
	return roleStats;
}

float BallanceCounter::MainRecursiveBallance::getAverageRank(PList<std::shared_ptr<Team>> teams) {
	bool isFilled = false;
	float sum = 0;
	std::for_each(teams->begin(), teams->end(), [&](std::shared_ptr<Team>& team) {
		if (team->isFilled()) isFilled = true;
		sum += team->getAverageRank();
	}); 
	if (isFilled) {
		float fillSum = 0;
		int amount = 0;
		for (int i = 0; i < teams->size(); ++i) {
			if (teams[i]->isFilled()) {
				fillSum += teams[i]->getAverageRank();
				++amount;
			}
			return fillSum / amount;
		}
	}
	else {
		return sum / teams->size();
	}
}