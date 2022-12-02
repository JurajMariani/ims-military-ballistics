/**
 * @file hamas.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __IMS_ROCKET_GENERATOR_HAMAS__
#define __IMS_ROCKET_GENERATOR_HAMAS__

#include <vector>
#include <simlib.h>
#include "missile.h"
#include "sim_specs.h"

class Hamas : public Event {
    std::vector<Missile *> rockets;
    sim_specs *specs;
public:
    Hamas(sim_specs *custom_data);

    void Behavior();
};

#endif