/**
 * @file sim_specs.h
 * @author Juraj Mariani <xmaria03 AT stud.fit.vutbr.cz>, Lukas Macejka <xmacej03 AT stud.fit.vutbr.cz>
 * @brief Simulation variables are defined here
 * @version 0.1
 * @date 2022-12-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __IMS_SIMULATION_PROBABILITIES_AND_TIME_OPTIONS__
#define __IMS_SIMULATION_PROBABILITIES_AND_TIME_OPTIONS__

#include <string>

using namespace std;

typedef struct {
    unsigned int hamasMissileCount;
    unsigned int interceptorMissileCount;
    unsigned int detectorDelay;
    unsigned int trajectoryCalculationDelay;
} nonpercentageSpecs;


typedef struct {
    double hamasDecoyChance;
    double detectionReliability;
    double trajectoryCalculationReliability;
    double interceptorSuccessRate;
} percentageSpecs;


typedef struct {
    unsigned int missilesMissedOnRadar = 0;
    unsigned int silentHits = 0;
    unsigned int misinterpretedTarget = 0;
    unsigned int unnecessaryLaunches = 0;
    unsigned int missilesNeutralised = 0;
    unsigned int interceptorFailCount = 0;
    unsigned int missilesHitTarget = 0;
    unsigned int missilesTargetingImportant = 0;
    unsigned int interceptorMissilesLaunched = 0;
    unsigned int misinterpretedNoninterceptHit = 0;
    unsigned int unableToIntercept = 0;
} simOutput;


typedef struct {
    string name;
    nonpercentageSpecs* npSpecs;
    percentageSpecs* pSpecs;
    simOutput* oSpecs;
} sim_specs;

extern sim_specs sim;
extern sim_specs normal;

#endif
