#include "BallanceCounter.h"

///standart funcs
BallanceCounter::BallanceCounter() {}	
BallanceCounter::BallanceCounter(PLAYERS_TYPE _players) {
	setPlayers(_players);
}
void BallanceCounter::setPlayers(PLAYERS_TYPE _players) {
	players = _players;
}

/// private
PLAYERS_TYPE BallanceCounter::find_all(std::function<bool(PLAYER_TYPE&)> pred) {
	PLAYERS_TYPE res;
	std::for_each(players.begin(), players.end(),
		[&](PLAYER_TYPE& p) {
			if (pred(p)) res.push_back(p);
		});
	return res;
}

/// public
void BallanceCounter::ballance(PLAYERS_TYPE _players) {
	setPlayers(_players);
	teamsInit();

	CapSquireMapper a;
	a.begin(teams, players);
}