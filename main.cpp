/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <simlib.h>
#include <iostream>
#include "hamas.h"
#include "missile.h"
#include "sim_specs.h"

using namespace std;

int main ()
{
    Init(0, 60 * 60 * 5);
    Hamas* attack = new Hamas(&sim);

    RandomSeed(time(NULL));

    Run();
    printf("???\n");

    #ifdef DEBUG_INFO
    
    missileQueue.Output();
    missilesDiscovered.Output();
    radarDetector.Output();
    trajectoryComputation.Output();

    #endif

    delete attack;

    printf("----------------------SUMMARY----------------------\n\n");
    cout << "SCENARIO:\t" << sim.name << "\n\n";
    printf("\tMissiles launched:\t\t\t\t\t%d\n",sim.npSpecs->hamasMissileCount);
    printf("\tInterceptor missiles launched:\t\t\t\t%d\n", sim.oSpecs->interceptorMissilesLaunched);
    printf("\tMissiles unintercepted due to interceptor shortage:\t%d\n", sim.oSpecs->unableToIntercept);
    printf("\tMissiles uncaught by radar:\t\t\t\t%d (%d of the hit)\n", sim.oSpecs->missilesMissedOnRadar, sim.oSpecs->silentHits);
    printf("\t\tThus %d missiles have been detected, equivalent to %f %% detection rate\n", (sim.npSpecs->hamasMissileCount - sim.oSpecs->missilesMissedOnRadar), ((double)(sim.npSpecs->hamasMissileCount - sim.oSpecs->missilesMissedOnRadar) / (double)sim.npSpecs->hamasMissileCount) * 100);
    printf("\tMissiles neutralized:\t\t\t\t\t%d\n", sim.oSpecs->missilesNeutralised);
    printf("\tInterceptor fails:\t\t\t\t\t%d\n", sim.oSpecs->interceptorFailCount);
    printf("\tInterceptor missiles remaining:\t\t\t\t%d\n", sim.npSpecs->interceptorMissileCount - sim.oSpecs->interceptorMissilesLaunched);
    printf("\tRisk Eval. target misinterpretation:\t\t\t%d times\n", sim.oSpecs->misinterpretedTarget);
    printf("\t\tResulting in %d unnecessary launches and in %d unintercepted hits\n", sim.oSpecs->unnecessaryLaunches, sim.oSpecs->misinterpretedNoninterceptHit);
    printf("\tHamas missiles hit target:\t\t\t\t%d times out of %d\n", sim.oSpecs->missilesHitTarget, sim.oSpecs->missilesTargetingImportant);
    return 0;
}
