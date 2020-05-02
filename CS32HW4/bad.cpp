//
//  bad.cpp
//  CS32 HW 4
//
//  Created by Caden McQuillen on 5/24/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//


void removeBad(list<Movie*>& li)
{
    list<Movie*>::iterator it = li.begin();
    while(it!=li.end())
    {
        if((*it)->rating()<=55)
        {
            (*it)->~Movie();
            it= li.erase(it);
        }
        else{
            it++;
        }
    }
}

