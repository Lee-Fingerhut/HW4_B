//
//  SniperCommander.hpp
//  wargame-a
//
//  Created by Lee Fingerhut on 22/05/2020.
//  Copyright © 2020 Lee Fingerhut. All rights reserved.
//
#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include "Sniper.hpp"

using namespace std;

class SniperCommander :  public Sniper {
public:
    SniperCommander(int player) : Sniper(player){
        health_points = 120;
        initial_health_points = 120;
        damage        = 100;
        type = SoldierID::SniperCommander;

    }
      void activity(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> loc);
};

