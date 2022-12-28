#include "Team.h"

float Team::getAverageRank() {
	return averageRank;
}

void Team::addTank(PLAYER_TYPE p) {
	players[TANK_ID] = p;
	p->isChosen = true;
	countAverageRank();
}
void Team::addDps(PLAYER_TYPE p) {
	if (players[DPS1_ID]) players[DPS2_ID] = p;
	else players[DPS1_ID] = p;
	p->isChosen = true;
	countAverageRank();
}
void Team::addSupport(PLAYER_TYPE p) {
	if (players[SUP1_ID]) players[SUP2_ID] = p;
	else players[SUP1_ID] = p;
	p->isChosen = true;
	countAverageRank();
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

void Team::countAverageRank() {
	int averageRank = 0;
	averageRank += players[TANK_ID]->stats.classes.tank.rank;
	averageRank += players[DPS1_ID]->stats.classes.dps.rank;
	averageRank += players[DPS2_ID]->stats.classes.dps.rank;
	averageRank += players[SUP1_ID]->stats.classes.support.rank;
	averageRank += players[SUP2_ID]->stats.classes.support.rank;
	averageRank *= 0.2f;
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

std::array<int, 3> Team::needed() {
	std::array<int, 3> res;
	if (!players[TANK_ID]) ++res[0];
	if (!players[DPS1_ID]) ++res[1];
	if (!players[DPS2_ID]) ++res[1];
	if (!players[SUP1_ID]) ++res[2];
	if (!players[SUP2_ID]) ++res[2];
	return res;
}

bool Team::isFilled() {
	for (int i = 0; i < 5; ++i) if (players[i]) return false;
	return true;
}