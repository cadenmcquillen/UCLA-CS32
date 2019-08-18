//
//  Game.hpp
//  CS32 project 3
//
//  Created by Caden McQuillen on 5/13/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include "Board.h"
#include "Player.h"

class Game
{
public:
    Game(const Board& b, Player* south, Player* north);
    void display() const;
    void status(bool& over, bool& hasWinner, Side& winner) const;
    bool move();
    void play();
    int beans(Side s, int hole) const;
private:
    Board m_Board;
    Player* m_SouthPlayer;
    Player* m_NorthPlayer;
    Side m_CurrentSide;
    
    
    
};

#endif /* Game_h */
