#include "Player.h"

Player::Player() {
	stats.classes.dps.type = Roles::Dps;
	stats.classes.tank.type = Roles::Tank;
	stats.classes.support.type = Roles::Support;
	isChosen = false;
}

bool Player::operator==(Player player) {
	return PK() == player.PK();
}


bool Player::operator==(std::string pk) {
	return PK() == pk;
}

std::string Player::PK() { return identity.name; }

Role* Player::mainRole() {
	if (stats.classes.dps.priority == 2) return &stats.classes.dps;
	else if (stats.classes.tank.priority == 2) return &stats.classes.tank;
	else if (stats.classes.support.priority == 2) return &stats.classes.support;
}

