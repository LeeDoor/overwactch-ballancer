#include "BallanceCounter.h"

BallanceCounter::BallanceCounter() {}	
BallanceCounter::BallanceCounter(std::vector<std::shared_ptr<Player>> _players) {
	setPlayers(_players);
}

void BallanceCounter::setPlayers(std::vector<std::shared_ptr<Player>> _players) {
	players = _players;
}


std::vector<std::shared_ptr<Player>> BallanceCounter::find_all(std::function<bool(std::shared_ptr<Player>&)> pred) {
	std::vector<std::shared_ptr<Player>> res;
	std::for_each(players.begin(), players.end(),
		[&](std::shared_ptr<Player>& p) {
			if (pred(p)) res.push_back(p);
		});
	return res;
}