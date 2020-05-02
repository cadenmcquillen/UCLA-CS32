//
//  odds.cpp
//  CS32 HW 4
//
//  Created by Caden McQuillen on 5/24/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//

void removeOdds(vector<int>& v)
{
    vector<int>::iterator i= v.begin();
    while(i!=v.end())
    {
        if(*i %2 !=0) // if its odd
        {
            i = v.erase(i); //returns iterator item past deleted item
        }
        else{
            i++; //increment iterator if doesnt delete item
        }
    }
}


