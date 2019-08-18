//
//  History.hpp
//  CS32 project 1
//
//  Created by Caden McQuillen on 4/6/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//

#ifndef History_h
#define History_h
#include "globals.h"

class Arena;


class History
{
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;
    
    
private:
    int m_Arena[MAXROWS][MAXCOLS];
    int m_Rows;
    int m_Cols;
};


#endif /* History_hpp */
