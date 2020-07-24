//
//  SniperCommander.cpp
//  wargame-a
//
//  Created by Lee Fingerhut on 22/05/2020.
//  Copyright © 2020 Lee Fingerhut. All rights reserved.
//
#include "SniperCommander.hpp"

//Like a sniper, but when he moves, not only does he shoot but all the sniper of that player shoots.
void SniperCommander::activity(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> loc){
    Sniper* ps = nullptr;
    std::pair<int,int> ps_loc;
    ps = dynamic_cast<Sniper*>(board[loc.first][loc.second]);
    ps->Sniper::activity(board, loc);
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(i == loc.first && j == loc.second){
                continue;
            }
            ps = dynamic_cast<Sniper*>(board[i][j]);
            if (ps != nullptr && ps->getNum_Of_Player() == this->getNum_Of_Player()) {
                if (ps->getType() == SoldierID::Sniper || ps->getType() == SoldierID::SniperCommander){
                    ps_loc = std::make_pair(i,j);
                    ps->Sniper::activity(board, ps_loc);
                    ps = nullptr;
                }
            }
        }
    }
}