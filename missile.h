/**
 * @file missile.h
 * @author Juraj Mariani <xmaria03 AT stud.fit.vutbr.cz>, Lukas Macejka <xmacej03 AT stud.fit.vutbr.cz>
 * @brief Main simulation process
 * @version 0.1
 * @date 2022-12-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __IMS_TYPE_PROCESS_MISSILE__
#define __IMS_TYPE_PROCESS_MISSILE__

#include <simlib.h>
#include "sim_specs.h"

extern Queue missileQueue;
extern Queue missilesDiscovered;

extern Facility radarDetector;
extern Facility trajectoryComputation;

enum Target_t {
    important, not_important
};


class Missile : public Process {
public:
    Target_t target;

    Missile();

    void Behavior();

    /**
     * @brief Seize Wait and Release a Facility
     * 
     * @param f Seized Facility
     * @param deltaT Wait-time
     */
    void facilityUsage(Facility &f, double deltaT);

    void calculateMissileTrajectory();

    void undetected();

    void detectedWithCorrectTrajectory();

    void detectedWithWrongTrajectory();

    void intercept();
};

#endif
