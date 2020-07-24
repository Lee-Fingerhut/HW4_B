//
//  ParamedicCommander.hpp
//  wargame-a
//
//  Created by Lee Fingerhut on 22/05/2020.
//  Copyright © 2020 Lee Fingerhut. All rights reserved.
//
#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include "Paramedic.hpp"

using namespace std;

class ParamedicCommander : public  Paramedic {
public:
    ParamedicCommander(int player) : Paramedic(player){
        health_points = 200;
        initial_health_points = 200;
        damage        = 100;
        type = SoldierID::ParamedicCommander;

    }
        void activity(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> loc);
};