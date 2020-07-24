//
//  Sniper.cpp
//  wargame-a
//
//  Created by Lee Fingerhut on 22/05/2020.
//  Copyright © 2020 Lee Fingerhut. All rights reserved.
//

#include "Sniper.hpp"

//Shoots the strongest soldier of the enemy - the one who has the most health points. can move one step
void Sniper::activity(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> loc){
    Soldier* s = nullptr;
    Soldier* s_max = nullptr;
    int max_health_points = -1;
    pair<int,int> ps_loc;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            s = board[i][j];
            if (s!= nullptr && s->getNum_Of_Player() != this->getNum_Of_Player()){
                int s_health_points = s->getHealth_points();
                if(s_health_points > max_health_points){
                    max_health_points = s_health_points;
                    s_max = s;
                    ps_loc = make_pair(i,j);
                }
            }
        }
    }
    if(s_max != nullptr) {
       // cout << "sniper at: " << loc.first << ", " << loc.second << " damge: " << this->getDamge() << std::endl;
        s_max->setHealth_points(s_max->getHealth_points() - this->getDamge());
        if (s_max->getHealth_points() <= 0) {
            s_max = dynamic_cast<Sniper*>(s_max);
            delete s_max;
            s_max = nullptr;
            board[ps_loc.first][ps_loc.second] = nullptr;
        }
    }
    
}