//
//  FootSoldier.cpp
//  wargame-a
//
//  Created by Lee Fingerhut on 22/05/2020.
//  Copyright © 2020 Lee Fingerhut. All rights reserved.
//
#include "FootSoldier.hpp"
#include "math.h"

void FootSoldier::activity(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> loc) {
    long mindistance = board.size()*board.size() +  board[0].size()* board[0].size() + 1;
    Soldier* s = nullptr;
    Soldier* s_min = nullptr;
    pair<int,int> ps_loc;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            s = board[i][j];
            if (s != nullptr && s->getNum_Of_Player() != this->getNum_Of_Player()){
                long dist = (loc.first - i)*(loc.first - i) + (loc.second - j)*(loc.second - j);
                //cout << " loc_first: " << loc.first << " loc_second: " << loc.second << std::endl;
                //cout << "dist: " << dist << " i: " << i << " j: " << j << std::endl;
                if(dist < mindistance){
                    mindistance = dist;
                    s_min = s;
                    ps_loc = make_pair(i, j);
                }
            }
        }
    }
    if(s_min != nullptr) {
        s_min->setHealth_points(s_min->getHealth_points() - this->getDamge());
        if (s_min->getHealth_points() <= 0){
            //s_min = dynamic_cast<FootSoldier*>(s_min);
            delete s_min;
            s_min = nullptr;
            board[ps_loc.first][ps_loc.second] = nullptr;
        }
    }
}

