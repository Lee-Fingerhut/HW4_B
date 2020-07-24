
//
//  Sniper.hpp
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

//Shoots the strongest soldier of the enemy - the one who has the most health points. can move one step
class Sniper : public Soldier {
public:
    Sniper(int player) : Soldier(100, 50, player){
        initial_health_points = 100;
        type = SoldierID::Sniper;
    }
    void activity(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> loc);
};