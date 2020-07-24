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
class notInTheGame: public exception {
    virtual const char* what() const throw() {
        return "this player not in the game";
    }
} ex_not_in_the_geme;

class boundary: public exception {
    virtual const char* what() const throw() {
        return "Exceeds the boundary of the board";
    }
} ex_boundary;

class invalidWord: public exception {
    virtual const char* what() const throw() {
        return "Invalid word";
    }
} ex_InvalidWord;

class alreadyHasASoldier: public exception {
    virtual const char* what() const throw() {
        return "already has a soldier there";
    }
} ex_already_has_a_soldier;

//putting soldiers on the game-board
//pointer on the borad -> we can add/delete
Soldier*& Board::operator[](std::pair<int, int> location) {
    return board[location.first][location.second];
}

//reading is there a soldr -> null/*soldier
Soldier* Board::operator[](std::pair<int,int> location) const {
    return board[location.first][location.second];
}

void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction) {
    if(source.first < 0 || source.first >= board.size()|| source.second<0 || source.second >=board[source.first].size()) {
        throw ex_boundary;
    }

    Soldier* ps = board[source.first][source.second];
    if( ps == nullptr){
        throw ex_not_in_the_geme;
    }

    if(ps->getNum_Of_Player() != player_number){
        throw ex_not_in_the_geme;
    }

    int i = source.first;
    int j = source.second;
    pair<int,int> ps_loc;
    

    if(i < 0 || i >= board.size() || j > board[i].size() || j < 0){
      throw ex_boundary;
    }
    
    switch(direction){
        case Up :
            ps_loc = make_pair(i+1,j);//constractor of pair
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
            throw ex_InvalidWord;
    }
 //   cout << "pc_loc: " << ps_loc.first << ", " << ps_loc.second << std::endl;
    if(ps_loc.first < 0 || ps_loc.first >= board.size() || ps_loc.second >= board[ps_loc.first].size() || ps_loc.second < 0){
        throw ex_boundary;
    }
    Soldier* pc = board[ps_loc.first][ps_loc.second];
    if( pc != nullptr){
        throw ex_already_has_a_soldier;
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