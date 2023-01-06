#pragma once
#include <vector>
#include <memory>
#include <functional>
#include <algorithm>
#include <map>
#include "PList.h"
#include "Player.h"
#include "Team.h"

#define AR_SUM_NEED 0
#define AR_SUM_MAIN 1
#define AR_SUM_SUB 2
typedef std::array<std::array<int, 3>, 3> ROLE_STATS;
class BallanceCounter
{
private:
	PList<std::shared_ptr<Player>> players;
	PList<std::shared_ptr<Team>> teams;
	void teamsInit();

	//filling teams with dps captain. they should have weak second dps
	void fillDpsCaptain();

	//class mapps squire and captain with given rules
	class CapSquireMapper {
	private:
		PList<std::shared_ptr<Team>> teams;
		PList<std::shared_ptr<Player>> players;
		std::vector<std::pair<std::shared_ptr<Player>, std::shared_ptr<Player>>> pairs;// vector with pair captain - squire players
	public:
		//begins mapping
		void begin(PList<std::shared_ptr<Team>> teams, PList<std::shared_ptr<Player>> players);
		//making simple mapping without any rules and returns wrong keys of map
		//returns array with std::shared_ptr<Player> keys captains whose have wrong pair with squires
		PList<std::shared_ptr<Player>> primaryMapping();
		//replaces squires in map
		//returns vector of unreplaceable players if they are, nullptr otherwise
		PList<std::shared_ptr<Player>> wrongReplacing(PList<std::shared_ptr<Player>> keys);
		//finds valid pair for iterated std::shared_ptr<Player>. other keys required to not 
		//swap their valid pairs
		//returns true if succeed, false otherwise
		bool findValidPair(PList<std::shared_ptr<Player>> keys, int id, int delt = 1);
		bool isFound(PList<std::shared_ptr<Player>> keys, int curId, int compId);
	};
	//class to ballance all players in different variations
	class MainRecursiveBallance {
	private:
		//counts required classes and collects stats
		ROLE_STATS countRoleStats(PList<std::shared_ptr<Team>> teams, PList<std::shared_ptr<Player>> players);
		// decides which std::shared_ptr<Player> need to ballance now and ballances it
		// while there are some unballanced players
		void analizing(ROLE_STATS roleStats, PList<std::shared_ptr<Team>> teams, PList<std::shared_ptr<Player>> players);

		// counts average rank for every team and returns average rank for all teams
		// if threre are some filled teams, returns average value for filled teams
		float getAverageRank(PList<std::shared_ptr<Team>> teams);
	public:
		void begin(PList<std::shared_ptr<Team>> teams, PList<std::shared_ptr<Player>> players);
	};
public:
	BallanceCounter();
	BallanceCounter(PList<std::shared_ptr<Player>> _players);
	void setPlayers(PList<std::shared_ptr<Player>> _players);

	void ballance(PList<std::shared_ptr<Player>> _players);
};

