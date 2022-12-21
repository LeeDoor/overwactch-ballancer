#pragma once
#include "Player.h"
#include <vector>
#include <memory>
#include <functional>
#include <algorithm>
#include "Team.h"

class BallanceCounter
{
private:
	std::vector<std::shared_ptr<Player>> players;

	std::vector<std::shared_ptr<Player>> find_all(std::function<bool(std::shared_ptr<Player>&)>);
public:
	BallanceCounter();
	BallanceCounter(std::vector<std::shared_ptr<Player>> _players);

	void setPlayers(std::vector<std::shared_ptr<Player>> _players);
	void ballance(std::vector<std::shared_ptr<Player>> _players);
};

