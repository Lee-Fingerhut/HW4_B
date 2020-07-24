#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include "FootSoldier.hpp"
using namespace std;

//like footsoldier, but when he movs all the footsoldiers sout
class FootCommander : public FootSoldier {
public:
    FootCommander(int player) : FootSoldier(player){
        health_points = 150;
        initial_health_points = 150;
        damage        = 20;
        type = SoldierID::FootCommander;
    }
    void activity(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> loc);
};