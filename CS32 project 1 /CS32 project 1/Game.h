//
//  Game.h
//  CS32 project 1
//
//  Created by Caden McQuillen on 4/3/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//

#ifndef Game_h
#define Game_h
class Arena;
class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nZombies);
    ~Game();
    
    // Mutators
    void play();
    
private:
    Arena* m_arena;
};


#endif /* Game_h */
