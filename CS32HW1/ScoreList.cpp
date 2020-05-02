//
//  ScoreList.cpp
//  Homework 1
//
//  Created by Caden McQuillen on 4/14/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//



#include "ScoreList.h"


ScoreList:: ScoreList()
{
    
    
}

bool ScoreList:: add(unsigned long score)
{
    if(score>=0&&score<=100&&m_sequence.size()<DEFAULT_MAX_ITEMS)
    {
        m_sequence.insert(score);
        return true;
    }
    else{
        return false;
    }
}


bool ScoreList::remove(unsigned long score)
{
    int position = m_sequence.find(score);
    bool result = m_sequence.erase(position);
    return result;
}

int ScoreList::size() const
{
    return m_sequence.size();
}

unsigned long ScoreList:: minimum() const
{
    unsigned long value;
    if(m_sequence.size()>0)
    {
        m_sequence.get(0,value);
        return value;
    }
    else{
        return NO_SCORE;
    }
}

unsigned long ScoreList::maximum() const
{
    unsigned long value;
    if(m_sequence.size()>0)
    {
        m_sequence.get(size()-1, value);
        return value;
    }
    else{
        return NO_SCORE;
    }
    
}


