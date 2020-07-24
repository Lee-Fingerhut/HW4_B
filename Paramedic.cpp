//
//  Paramedic.cpp
//  wargame-a
//
//  Created by Lee Fingerhut on 22/05/2020.
//  Copyright © 2020 Lee Fingerhut. All rights reserved.
//

#include "Paramedic.hpp"

//Can go one slot in each direction. 
//Does not shoot at all, but only heals all the soldiers of the same player who are in the box next to him 
//(returns the number of their health points to the starting number)

// I assumed that the Paramedic doesn't heals himself
// but heals other paramdics next to him;
void Paramedic::activity(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> loc){
    Soldier* s = nullptr;
    int loc_x = loc.first;
    int loc_y = loc.second;
    int startX = loc_x - 1 < 0 ? 0 : loc_x-1;
    int stopX = loc_x + 1 >= board.size() ? board.size()-1 : loc_x + 1;
    int startY = loc_y - 1 < 0 ? 0 : loc_y-1;
    int stopY = loc_y + 1 >= board[0].size() ? board[0].size()-1 : loc_y + 1;
    //cout << "startX: " << startX << ", stopX: " << stopX << std::endl;
   // cout << "starty: " << startY << ", stopy: " << stopY << std::endl;
    
    for(int i=startX; i<=stopX; i++){
        for(int j=startY; j<=stopY; j++){
            if(loc_x == i && loc_y == j){
                continue;
            }
            s = board[i][j];
            if(s != nullptr && s->getNum_Of_Player() == this->getNum_Of_Player()){
                s->setHealth_points(s->getInitial_Health_Points());
            }
        }
    }
}