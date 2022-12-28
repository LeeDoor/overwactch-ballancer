#pragma once
#include "BallanceCounter.h"
class PlayersTeamsManager
{
public:
	static PLAYERS_TYPE findAllPlayers(PLAYERS_TYPE players, std::function<bool(PLAYER_TYPE&)> pred);
	static TEAMS_TYPE findAllTeams(TEAMS_TYPE teams, std::function<bool(TEAM_TYPE&)> pred);
};

