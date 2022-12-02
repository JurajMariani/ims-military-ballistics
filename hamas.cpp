/**
 * @file hamas.cpp
 * @author your name (you@domain.com)
 * @brief 
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