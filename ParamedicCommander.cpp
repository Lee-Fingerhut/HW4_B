//
//  ParamedicCommander.cpp
//  wargame-a
//
//  Created by Lee Fingerhut on 22/05/2020.
//  Copyright © 2020 Lee Fingerhut. All rights reserved.
//

#include "ParamedicCommander.hpp"
#include "Soldier.hpp"

void ParamedicCommander::activity(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> loc){
    Paramedic* ps = nullptr;
    std::pair<int,int> ps_loc;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if (board[i][j] != nullptr && board[i][j]->getNum_Of_Player() == this->getNum_Of_Player()){
                ps = dynamic_cast<Paramedic*>(board[i][j]);
                if(ps->getType() == SoldierID::Paramedic || ps->getType() ==SoldierID::ParamedicCommander){
                    ps_loc = std::make_pair(i,j);
                    ps->Paramedic::activity(board, ps_loc);
                    ps = nullptr;
                }
            }
        }
    }
}
