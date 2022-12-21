#include "Player.h"

bool Player::operator==(Player player) {
	return PK() == player.PK();
}


bool Player::operator==(std::string pk) {
	return PK() == pk;
}

std::string Player::PK() { return identity.name; }