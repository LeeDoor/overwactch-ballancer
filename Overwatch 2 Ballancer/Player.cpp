#include "Player.h"

bool Player::operator==(Player player) {
	return identity.uuid == player.identity.uuid;
}


bool Player::operator==(std::string name) {
	return identity.uuid == identity.uuid;
}

void Player::update(Player p) {
	std::string prefId = identity.uuid;
	identity = p.identity;
	stats = p.stats;

	identity.uuid = prefId;
}