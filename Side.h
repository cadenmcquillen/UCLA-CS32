//
//  Side.h
//  CS32 project 3
//
//  Created by Caden McQuillen on 5/14/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//

#ifndef Side_h
#define Side_h

enum Side { NORTH, SOUTH };

const int NSIDES = 2;
const int POT = 0;

inline
Side opponent(Side s)
{
    return Side(NSIDES - 1 - s);
}



#endif /* Side_h */
