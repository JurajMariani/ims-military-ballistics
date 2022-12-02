/**
 * @file sim_specs.cpp
 * @author your name (you@domain.com)
 * @brief 
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
    10
};

percentageSpecs normalP = {
    25,
    98,
    98,
    90
};

simOutput out;

sim_specs normal = {
    "Experiment based on the 2014 attack",
    &normalNP,
    &normalP,
    &out
};

//sim_specs sim;

#ifdef SCENARIO1
sim_specs sim = normal;
#elif defined SCENARIO2
sim_specs sim = scenario2;
#else
sim_specs sim = normal;
#endif