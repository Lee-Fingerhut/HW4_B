//
//  Paramedic.cpp
//  wargame-a
//
//  Created by Lee Fingerhut on 22/05/2020.
//  Copyright © 2020 Lee Fingerhut. All rights reserved.
//

#include "Paramedic.hpp"

// I assumed that the Paramedic doesn't heals himself
// but heals other paramdics next to him;

void Paramedic::activity(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> loc){
    Soldier* s = nullptr;
    int loc_x = loc.first;
    int loc_y = loc.second;
    unsigned long startX = loc_x - 1 < 0 ? 0 : loc_x-1;
    unsigned long stopX = loc_x + 1 >= board.size() ? board.size()-1 : loc_x + 1;
    unsigned long startY = loc_y - 1 < 0 ? 0 : loc_y-1;
    unsigned long stopY = loc_y + 1 >= board[0].size() ? board[0].size()-1 : loc_y + 1;
    for(unsigned long i=startX; i<=stopX; i++){
        for(unsigned long j=startY; j<=stopY; j++){
            if(loc_x == i && loc_y == j)
                continue;
            s = board[i][j];
            if(s != nullptr){
                s->setHealth_points(s->getInitial_Health_Points());
                if (s->getHealth_points() <= 0) {
                    delete s;
                }
            }
        }
    }
}

