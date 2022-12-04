/**
 * @file sim_specs.cpp
 * @author Juraj Mariani <xmaria03 AT stud.fit.vutbr.cz>, Lukas Macejka <xmacej03 AT stud.fit.vutbr.cz>
 * @brief Simulation variables are set here
 * @version 0.1
 * @date 2022-12-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "sim_specs.h"


/**
 * Specs set in accordance with a wikipedia article
 * www.en.wikipedia.org/wiki/Iron_Dome
 * Section Deployment
 * "During the 50 days of the conflict 4,594 rockets and mortars were fired at Israeli targets;
 * Iron Dome systems intercepted 735 projectiles that it determined were threatening, 
 * achieving success rate of 90 percent. Only 70 rockets ... failed to be intercepted ...
 * ... only 25 percent of rockets fired were determined to be threatening"
 * 
 */
nonpercentageSpecs normalNP = {
    4594, //4594
    1000,
    5,
    8
};

percentageSpecs normalP = {
    84,
    90,
    95,
    100
};

simOutput out;

sim_specs normal = {
    "Experiment based on the 2014 attack",
    &normalNP,
    &normalP,
    &out
};

nonpercentageSpecs exp1NP = {
	100,
	100,
	5,
	10
};

percentageSpecs exp1P = {
	0,
	90,
	95,
	99
};

sim_specs exp_1 = {
	"Experiment 1",
	&exp1NP,
	&exp1P,
	&out
};

nonpercentageSpecs exp2NP = {
	100,
	100,
	5,
	10
};

percentageSpecs exp2P = {
	86,
	98,
	100,
	100
};

sim_specs exp_2 = {
	"Experiment 2",
	&exp2NP,
	&exp2P,
	&out
};

nonpercentageSpecs exp3NP = {
	1400,
	80,
	5,
	10
};

percentageSpecs exp3P = {
	86,
	90,
	95,
	100
};

sim_specs exp_3 = {
	"Experiment 3",
	&exp3NP,
	&exp3P,
	&out
};


//sim_specs sim;

#ifdef EXP1
sim_specs sim = exp_1;
#elif defined EXP2
sim_specs sim = exp_2;
#elif defined EXP3
sim_specs sim = exp_3;
#else
sim_specs sim = normal;
#endif
