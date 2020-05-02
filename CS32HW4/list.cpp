//
//  list.cpp
//  CS32 HW 4
//
//  Created by Caden McQuillen on 5/26/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//


void listAll(const Domain* d, string path) // two-parameter overload
{
    if(d->subdomains().size()==0) //baseCase when vector of subdomains is empty (leaf)
    {
        cout<< path<<endl;
        return;
    }
    vector<Domain*>::const_iterator it = d->subdomains().begin();
    for (; it!=d->subdomains().end(); it++)
    {
        if(path != "")
        {
            listAll(*it, (*it)->label()+ "." + path);
        }
        else{
            listAll(*it, (*it)->label() + path); //dont put dot in front of first one
        }
    }
}
 

