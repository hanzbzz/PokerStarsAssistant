#pragma once
class PlayerStats {
public:
	explicit PlayerStats();
private:
	int handsPlayed;
	/*
	PRE-FLOP STATS
	*/
	// Voluntarily Put Into Pot
	// percentage of hands player put any money into pot without being forced to
	double VPIP;
	// Pre Flop Raise
	// percentage of hands player raises pre-flop (either initial raise or re-raise)
	double PFR;
	// Pre Flop 3-bet
	// percetage of hands player 3-beta fre flop raise
	double PF3B;
	// Pre Flop 3-bet Fold
	// percentage of hands player faced a PF3B and folded
	double PF3BF;
	// Attempts To Steal
	// percentage of hands player initial raised from a late position (BTN, CO, HJ) 
	double ATS;
	// Attempts To Steal Fold
	// percentage of hands player faced an ATS and folded
	double ATSF;

	/*
	POST-FLOP STATS
	*/
	// Continuation Bet Flop
	// percentage of hands where player last raised pre flop and then bet on flop
	double CBF;
	// Continuation Bet Flop Fold
	// percentage of hands where player who faced a CBF folded
	double CBFF;
	// Continuation Bet Turn
	// percentage of hands where player did CBF and continuted betting on turn
	double CBT;
	// Continuation Bet Turn Fold
	// percentage of hands where player faced CBT and folded
	double CBTF;
	// Won Show Down
	// percentage of hands player won at show down
	double WSD;
	// Went To Show Down
	// percentage of hands player went to show down
	double WTSD;

protected:
};