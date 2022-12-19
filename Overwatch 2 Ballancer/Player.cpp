#include "Player.h"

bool Player::operator==(Player player) {
	return identity.name == player.identity.name;
}


bool Player::operator==(std::string name) {
	return identity.name == identity.name;
}