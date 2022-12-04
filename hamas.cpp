/**
 * @file hamas.cpp
 * @author Juraj Mariani <xmaria03 AT stud.fit.vutbr.cz>, Lukas Macejka <xmacej03 AT stud.fit.vutbr.cz>
 * @brief Missile generator
 * @version 0.1
 * @date 2022-12-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <simlib.h>
#include "hamas.h"

Hamas::Hamas(sim_specs *data) {
    Activate();
    specs = data;
}

void Hamas::Behavior() {
    if (rockets.size() < specs->npSpecs->hamasMissileCount)
    {
        auto missile = new Missile();
        rockets.push_back(missile);
        missile->Activate();
        // Maybe add rocket genesis timer
        //this->Activate(Time + Normal(specs->nonpercentageSpecs->???));

        this->Activate(Time);
    }
}
