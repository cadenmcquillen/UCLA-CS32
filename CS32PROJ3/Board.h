//
//  Board.hpp
//  CS32 project 3
//
//  Created by Caden McQuillen on 5/13/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//

#ifndef Board_h
#define Board_h
#include "Side.h"

class Board
{
public:
    Board(int nHoles, int nInitialBeansPerHole);
    ~Board(); //destructor
    Board(const Board &other); // copy constructor
    Board & operator= (const Board &other); // assignment operator
    int holes() const;
    int beans(Side s, int hole) const;
    int beansInPlay(Side s) const;
    int totalBeans() const;
    bool sow(Side s, int hole, Side& endSide, int& endHole);
    bool moveToPot(Side s, int hole, Side potOwner);
    bool setBeans(Side s, int hole, int beans);
private:
    int m_Holes;
    int m_InitialBeansPerHole;
    int* m_North;
    int* m_South;
    
};


#endif /* Board_hp */
