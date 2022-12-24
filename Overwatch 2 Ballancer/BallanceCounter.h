#pragma once
#include "Player.h"
#include <vector>
#include <memory>
#include <functional>
#include <algorithm>
#include "Team.h"
typedef std::shared_ptr<Team> TEAM_TYPE;
typedef std::shared_ptr<std::vector<TEAM_TYPE>> TEAMS_TYPE;

class BallanceCounter
{
private:
	PLAYERS_TYPE players;
	TEAMS_TYPE teams;

	PLAYERS_TYPE find_all(std::function<bool(PLAYER_TYPE&)>);
	void teamsInit();

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
public:
	BallanceCounter();
	BallanceCounter(PLAYERS_TYPE _players);

	void setPlayers(PLAYERS_TYPE _players);
	void ballance(PLAYERS_TYPE _players);
};

