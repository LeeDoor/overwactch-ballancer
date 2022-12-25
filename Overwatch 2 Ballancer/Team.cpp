#include "Team.h"

void Team::addTank(PLAYER_TYPE p) {
	players[TANK_ID] = p;
	p->isChosen = true;
}
void Team::addDps(PLAYER_TYPE p) {
	if (players[DPS1_ID]) players[DPS2_ID] = p;
	else players[DPS1_ID] = p;
	p->isChosen = true;
}
void Team::addSupport(PLAYER_TYPE p) {
	if (players[SUP1_ID]) players[SUP2_ID] = p;
	else players[SUP1_ID] = p;
	p->isChosen = true;
}
void Team::addWithType(PLAYER_TYPE player) {
	switch (player->mainRole()->type)
	{
	case Tank:
		addTank(player);
		break;
	case Dps:
		addDps(player);
		break;
	case Support:
		addSupport(player);
		break;
	}
}

float Team::getAverageRank() {
	int total = 0;
	total += players[TANK_ID]->stats.classes.tank.rank;
	total += players[DPS1_ID]->stats.classes.dps.rank;
	total += players[DPS2_ID]->stats.classes.dps.rank;
	total += players[SUP1_ID]->stats.classes.support.rank;
	total += players[SUP2_ID]->stats.classes.support.rank;
	return total / 5.0f;
}
int Team::getOffclassAmount() {
	int off = 0;
	for (auto p : players) off += p->identity.isOffclass;
	return off;
}
int Team::getOffclassDouble() {
	return (players[DPS1_ID]->identity.isOffclass && players[DPS2_ID]->identity.isOffclass) +
		(players[SUP1_ID]->identity.isOffclass && players[SUP2_ID]->identity.isOffclass);
}
int Team::getLowrankDouble() {
	return (players[DPS1_ID]->stats.classes.dps.rank < 500 && players[DPS2_ID]->stats.classes.dps.rank < 500) +
		(players[SUP1_ID]->stats.classes.dps.rank < 500 && players[SUP2_ID]->stats.classes.dps.rank < 500);
}