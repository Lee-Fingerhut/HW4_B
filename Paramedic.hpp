//
//  Paramedic.hpp
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
//Can go one slot in each direction. 
//Does not shoot at all, but only heals all the soldiers of the same player who are in the box next to him 
//(returns the number of their health points to the starting number)

// I assumed that the Paramedic doesn't heals himself
// but heals other paramdics next to him;
class Paramedic : public  Soldier {
public:
    Paramedic(int player) : Soldier(100,100,player){
        initial_health_points = 100;
        type = SoldierID::Paramedic;
        
    }
    void activity(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> loc);
};