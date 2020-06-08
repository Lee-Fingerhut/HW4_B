//
//  FootSoldier.hpp
//  wargame-a
//
//  Created by Lee Fingerhut on 22/05/2020.
//  Copyright © 2020 Lee Fingerhut. All rights reserved.
//
#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Soldier.hpp"

using namespace std;

class FootSoldier : public Soldier {
public:
    FootSoldier(int player) : Soldier(100, 10, player){
        initial_health_points = 100;
        type = SoldierID::FootSoldier;
    }
    void activity(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> loc);
};

