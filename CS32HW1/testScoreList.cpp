//
//  testScoreList.cpp
//  Homework 1
//
//  Created by Caden McQuillen on 4/15/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//




#include "ScoreList.h"
#include "Sequence.h"
using namespace std;
void testScoreList();

void testScoreList()
{
    ScoreList s;
    assert(s.size()==0);
    assert(s.maximum()==NO_SCORE);
    assert(s.maximum()==NO_SCORE);
    s.add(98);
    s.add(75);
    s.add(100);
    s.add(-5);
    assert(s.size()==3);
    assert(s.maximum()==100);
    assert(s.minimum()==75);
    assert(s.remove(98)==true);
    assert(s.remove(7)==false);
    assert(s.size()==2);
    cerr<<"All tests passed"<<endl;
}


