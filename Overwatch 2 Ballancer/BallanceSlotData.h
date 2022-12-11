#pragma once
class BallanceSlotData
{
private:
	unsigned _disp; // dispersion
	unsigned _offp; // offclass player persent
	unsigned _subPair; // subclass pair players
	unsigned _lowPair; // lowrank pair players
	unsigned _teamsAm; // amount of teams

public:
	BallanceSlotData();
	BallanceSlotData(
					unsigned disp, 
					unsigned offp, 
					unsigned subPair, 
					unsigned lowPair, 
					unsigned teamsAm);

	unsigned disp();
	unsigned offp();
	unsigned subPair();
	unsigned lowPair();
	unsigned teamsAm();

	void setDisp(unsigned v);
	void setOffp(unsigned v);
	void setSubPair(unsigned v);
	void setLowPair(unsigned v);
	void setTeamsAm(unsigned v);


};

