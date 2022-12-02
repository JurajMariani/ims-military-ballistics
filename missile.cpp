/**
 * @file missile.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <simlib.h>
#include "missile.h"

Queue missileQueue("Missile queue");
Queue missilesDiscovered("Detected missiles");

Facility radarDetector("Radar");
Facility trajectoryComputation("Risk evaluation");

Missile::Missile()
{
    double missileTarget = Random() * 100;
    
    if (missileTarget < sim.pSpecs->hamasDecoyChance)
        this->target = not_important;
    else
    {
        sim.oSpecs->missilesTargetingImportant++;
        this->target = important;
    }

    Activate();
}

void Missile::Behavior()
{
    if (radarDetector.Busy())
    {
        missileQueue.Insert(this);
        this->Passivate();
    }

    double detected = Random() * 100;

    if (detected < (100 - sim.pSpecs->detectionReliability))
        undetected();

    facilityUsage(radarDetector, sim.npSpecs->detectorDelay);

    if (!missileQueue.empty())
    {
        Missile* m = (Missile*)missileQueue.GetFirst();
        m->Activate();
    }
    
    calculateMissileTrajectory();
}

void Missile::facilityUsage(Facility &f, double deltaT)
{
    f.Seize(this);
    Wait(Normal(deltaT, 0));
    f.Release(this);
}

void Missile::calculateMissileTrajectory()
{
    if (trajectoryComputation.Busy())
    {
        missilesDiscovered.Insert(this);
        this->Passivate();
    }

    facilityUsage(trajectoryComputation, sim.npSpecs->trajectoryCalculationDelay);

    if (!missilesDiscovered.empty())
    {
        Missile* m = (Missile*)missilesDiscovered.GetFirst();
        m->Activate();
    }
    
    double correctTarget = Random() * 100;
    
    if (correctTarget <= (100 - sim.pSpecs->trajectoryCalculationReliability))
        detectedWithWrongTrajectory();
    else
        detectedWithCorrectTrajectory();
}

void Missile::detectedWithCorrectTrajectory()
{
    if (this->target == important)
    {
        intercept();
    }
    else
        return;
}

void Missile::detectedWithWrongTrajectory()
{
    sim.oSpecs->misinterpretedTarget++;
    if (this->target == important)
    {
        sim.oSpecs->misinterpretedNoninterceptHit++;
        return;
    }
    else
    {
        sim.oSpecs->unnecessaryLaunches++;
        intercept();
    }
}

void Missile::intercept()
{
    if (sim.oSpecs->interceptorMissilesLaunched >= sim.npSpecs->interceptorMissileCount)
    {
        sim.oSpecs->unableToIntercept++;
        if (this->target == important)
            sim.oSpecs->missilesHitTarget++;
        return;
    }

    sim.oSpecs->interceptorMissilesLaunched++;

    double neutralise = Random() * 100;

    if (neutralise <= sim.pSpecs->interceptorSuccessRate)
        sim.oSpecs->missilesNeutralised++;
    else
    {
        sim.oSpecs->interceptorFailCount++;
        if ( this->target == important )
            sim.oSpecs->missilesHitTarget++;
    }
}

void Missile::undetected()
{
    sim.oSpecs->missilesMissedOnRadar++;

    if (this->target == important)
    {
        sim.oSpecs->missilesHitTarget++;
        sim.oSpecs->silentHits++;
    }
}