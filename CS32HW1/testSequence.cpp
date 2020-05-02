//
//  testSequence.cpp
//  Homework 1
//
//  Created by Caden McQuillen on 4/14/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//



#include "Sequence.h"
using namespace std;

void test();
void test ()
{
    Sequence s;
    s.insert(0, 3);
    s.insert(1, 4);
    s.insert(2, 2);
    s.insert(3, 3);
    s.insert(4, 67);
    assert(s.remove(3) == 2);
    assert(s.size() == 3);
    unsigned long x;
    assert(s.get(0, x)  &&  x == 4);
    assert(s.get(1, x)  &&  x == 2);
    assert(s.get(2, x)  &&  x == 67);
    s.insert(54);
    s.insert(99);
    assert(s.size()==5);
    assert(s.set(2,5)==true);
    assert(s.erase(2)==true);
    assert(s.find(99)==3);
    assert(s.find(67)==2);
    
    Sequence s2;
    
    s2.insert(0, 0);
    s2.insert(1, 0);
    s2.insert(2, 0);
    
    s.swap(s2);
    assert(s.size()==3);
    assert(s2.size()==4);
    unsigned long y;
    assert(s.get(0, y)  &&  y == 0);
    assert(s.get(1, y)  &&  y == 0);
    assert(s.get(2, y)  &&  y == 0);
    
    assert(s2.get(0, y)  &&  y == 4);
    assert(s2.get(1, y)  &&  y == 2);
    assert(s2.get(2, y)  &&  y == 67);
    assert(s2.get(3, y)  &&  y == 99);
    
    cerr<<"All tests passed"<<endl;
    
}



