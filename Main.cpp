//
//  main.cpp
//  CS32 project 3
//
//  Created by Caden McQuillen on 5/13/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//
#include "Game.h"
#include "Player.h"
#include "Board.h"
int main()
{
    
    HumanPlayer bp1("Peggy");
    SmartPlayer bp2("Homer");
    Board b(3, 3);
    Game g(b, &bp1, &bp2);
    g.play();

   
    
    
   
}



