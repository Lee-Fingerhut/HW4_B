//
//  Board.cpp
//  wargame-a
//
//  Created by Lee Fingerhut on 22/05/2020.
//  Copyright © 2020 Lee Fingerhut. All rights reserved.
//

#include "Soldier.hpp"
#include "Board.hpp"
#include <cmath>
#include <iostream>
#include <exception>
#include <typeinfo>

using namespace std;

namespace WarGame {
//************************* exceptions *******************************
class ex_1: public exception {
    virtual const char* what() const throw() {
        return "this player not in the game";
    }
} myex_1;

class ex_2: public exception {
    virtual const char* what() const throw() {
        return "Exceeds the boundary of the board";
    }
} myex_2;

class ex_3: public exception {
    virtual const char* what() const throw() {
        return "Invalid word";
    }
} myex_3;

class ex_4: public exception {
    virtual const char* what() const throw() {
        return "already has a soldier there";
    }
} myex_4;

Soldier*& Board::operator[](std::pair<int, int> location) {
    /*if(board[location.first][location.second] !=  nullptr){
        throw myex_4;
    }*/
    return board[location.first][location.second];
}
Soldier* Board::operator[](std::pair<int,int> location) const {
   /* if(board[location.first][location.second] !=  nullptr){
        throw myex_4;
    }*/
    return board[location.first][location.second];
}

void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction) {
    if(source.first < 0 || source.first >= board.size()|| source.second<0 || source.second >=board[source.first].size()) {
          throw myex_2;
      }
    Soldier *ps = board[source.first][source.second];
    int i = source.first;
    int j = source.second;
    pair<int,int> ps_loc;
    if( ps == nullptr){
        throw myex_1;
    }
    if(ps->getNum_Of_Player() != player_number){
        throw myex_1;
    }
         //  cout << "source: " << i << ", " << j << std::endl;
    if(i < 0 || i >= board.size() || j > board[i].size() || j < 0){
        throw myex_2;
    }
    
    switch(direction){
        case Up :
            ps_loc = make_pair(i+1,j);
            break;
        case Down :
            ps_loc = make_pair(i-1,j);
            break;
        case Right :
            ps_loc = make_pair(i,j+1);
            break;
        case Left :
            ps_loc = make_pair(i,j-1);
            break;
        default:
            throw myex_3;
    }
 //   cout << "pc_loc: " << ps_loc.first << ", " << ps_loc.second << std::endl;
    
    if(ps_loc.first < 0 || ps_loc.first >= board.size() || ps_loc.second >= board[ps_loc.first].size() || ps_loc.second < 0){
        throw myex_2;
    }
    Soldier *pc = board[ps_loc.first][ps_loc.second];
    if( pc != nullptr){
        throw myex_4;
    }
    board[ps_loc.first][ps_loc.second] = ps;
    board[source.first][source.second] = nullptr;
    ps->activity(board, ps_loc);
}


bool Board::has_soldiers(uint player_number) const {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] != nullptr && board[i][j]->getNum_Of_Player() == player_number ){
                return true;
            }
        }
    }
    return false;
}
}
