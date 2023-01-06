#include "BallanceSlotData.h"

BallanceSlotData::BallanceSlotData() {}
BallanceSlotData::BallanceSlotData(unsigned disp, unsigned offp, unsigned subPair, unsigned lowPair, unsigned teamsAm) {
	setTeamsAm(teamsAm);
	setDisp(disp);
	setOffp(offp);
	setSubPair(subPair);
	setLowPair(lowPair);
}

unsigned BallanceSlotData::disp() { return _disp; }
unsigned BallanceSlotData::offp() { return _offp; }
unsigned BallanceSlotData::subPair() { return _subPair; }
unsigned BallanceSlotData::lowPair() { return _lowPair; }
unsigned BallanceSlotData::teamsAm() { return _teamsAm; }

void BallanceSlotData::setDisp(unsigned v) {
	_disp = v;
}

void BallanceSlotData::setOffp(unsigned v) {
	if (v <= 100)_offp = v;
	else _offp = -1;
}

void BallanceSlotData::setSubPair(unsigned v){
	if (v <= teamsAm())_subPair = v;
	else _subPair = -1;
}
void BallanceSlotData::setLowPair(unsigned v){
	if (v <= teamsAm())_lowPair = v;
	else _lowPair = -1;
}
void BallanceSlotData::setTeamsAm(unsigned v) {
	_teamsAm = v;
}