#include "FootCommander.hpp"

//like footsoldier, but when he movs all the footsoldiers sout
void FootCommander::activity(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> loc){
    FootSoldier* s = nullptr;
    std::pair<int,int> ps_loc;
    //only shout like footcomandar
    s = dynamic_cast<FootSoldier*>(board[loc.first][loc.second]);
    //myself->FootCommander
    s->FootSoldier::activity(board, loc);
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[i].size(); j++) {
            //the loc of the FootCommander
            if(i == loc.first && j == loc.second){
                continue;
            }
            s = dynamic_cast<FootSoldier*>(board[i][j]);
            if (s != nullptr && s->getNum_Of_Player() == this->getNum_Of_Player()) {
                if (s->getType() == SoldierID::FootSoldier || s->getType() == SoldierID::FootCommander) {
                    ps_loc = std::make_pair(i,j);
                    s->FootSoldier::activity(board, ps_loc);
                    s = nullptr;
                }
            }
        }
    }
}