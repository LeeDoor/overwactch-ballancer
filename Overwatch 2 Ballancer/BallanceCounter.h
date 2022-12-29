#pragma once
#include "Player.h"
#include <vector>
#include <memory>
#include <functional>
#include <algorithm>
#include <map>
#include "Team.h"
#include "PlayersTeamsManager.h"

#define AR_SUM_NEED 0
#define AR_SUM_MAIN 1
#define AR_SUM_SUB 2
typedef std::shared_ptr<Team> TEAM_TYPE;
typedef std::shared_ptr<std::vector<TEAM_TYPE>> TEAMS_TYPE;
typedef std::array<std::array<int, 3>, 3> ROLE_STATS;
class BallanceCounter
{
private:
	PLAYERS_TYPE players;
	TEAMS_TYPE teams;
	void teamsInit();

	//filling teams with dps captain. they should have weak second dps
	void fillDpsCaptain();

	//class mapps squire and captain with given rules
	class CapSquireMapper {
	private:
		TEAMS_TYPE teams;
		PLAYERS_TYPE players;
		std::vector<std::pair<PLAYER_TYPE, PLAYER_TYPE>> pairs;// vector with pair captain - squire players
	public:
		//begins mapping
		void begin(TEAMS_TYPE teams, PLAYERS_TYPE players);
		//making simple mapping without any rules and returns wrong keys of map
		//returns array with player keys captains whose have wrong pair with squires
		PLAYERS_TYPE primaryMapping();
		//replaces squires in map
		//returns vector of unreplaceable players if they are, nullptr otherwise
		PLAYERS_TYPE wrongReplacing(PLAYERS_TYPE keys);
		//finds valid pair for iterated player. other keys required to not 
		//swap their valid pairs
		//returns true if succeed, false otherwise
		bool findValidPair(PLAYERS_TYPE keys, int id, int delt = 1);
		bool isFound(PLAYERS_TYPE keys, int curId, int compId);
	};
	//class to ballance all players in different variations
	class MainRecursiveBallance {
	private:
		//counts required classes and collects stats
		ROLE_STATS countRoleStats(TEAMS_TYPE teams, PLAYERS_TYPE players);
		// decides which player need to ballance now and ballances it
		// while there are some unballanced players
		void analizing(ROLE_STATS roleStats, TEAMS_TYPE teams, PLAYERS_TYPE players);

		PLAYER_TYPE bestPlayerForTeam(PLAYERS_TYPE players, TEAM_TYPE team, float average);

		// counts average rank for every team and returns average rank for all teams
		// if threre are some filled teams, returns average value for filled teams
		float getAverageRank(TEAMS_TYPE teams);
	public:
		void begin(TEAMS_TYPE teams, PLAYERS_TYPE players, std::map<PLAYER_TYPE, bool> playersDone);
	};
public:
	BallanceCounter();
	BallanceCounter(PLAYERS_TYPE _players);
	void setPlayers(PLAYERS_TYPE _players);

	void ballance(PLAYERS_TYPE _players);
};

