//
//  Board.cpp
//  CS32 project 3
//
//  Created by Caden McQuillen on 5/13/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//

#include "Board.h"


Board:: Board(int nHoles, int nInitialBeansPerHole)
{
    m_Holes = nHoles;
    m_InitialBeansPerHole = nInitialBeansPerHole;
    if(nHoles<0)
    {
        m_Holes = 1;
    }
    if(nInitialBeansPerHole<0)
    {
        m_InitialBeansPerHole = 0;
    }
    
    m_North = new int[m_Holes+1]; //create array representing north holes
    m_South = new int[m_Holes+1]; // array representing south holes
    m_North[0]=0; //intialize pots to 0
    m_South[0]=0;
    for (int i = 1; i<m_Holes+1; i++) // start after the 0th element (pot)
    {
        m_North[i]= m_InitialBeansPerHole;
        m_South[i]= m_InitialBeansPerHole;
    }
    
    
}
Board::~Board()
{
    delete m_North;
    delete m_South;
}

Board:: Board(const Board& other)
{
    m_Holes = other.m_Holes;
    m_South = new int[m_Holes+1];
    m_North = new int[m_Holes+1];
    
    for(int i = 0; i<m_Holes+1; i++)
    {
        m_North[i]= other.m_North[i];
        m_South[i]= other.m_South[i];
    }
    
}
Board& Board:: operator= (const Board& other)
{
    if(this != &other)
    {
        delete [] m_North;
        delete [] m_South;
        m_Holes = other.m_Holes;
        m_South = new int[m_Holes];
        m_North = new int[m_Holes];
        for(int i = 0; i<m_Holes+1; i++)
        {
            m_North[i]= other.m_North[i];
            m_South[i]= other.m_South[i];
        }
        
    }
    return *this;
}




int Board:: holes() const
{
    return m_Holes;
}

int Board:: beans(Side s, int hole) const
{
    if (hole>m_Holes || hole<0) //hole doesnt exist
        return -1;
    
    if(s==NORTH)
    {
        return m_North[hole];
    }
    else{
        return m_South[hole];
    }
    
}

int Board:: beansInPlay(Side s) const
{
    if(s==NORTH)
    {
        int total = 0;
        for(int i = 1; i<m_Holes+1; i++)
        {
            total+= m_North[i];
        }
        return total;
    }
    else{
        int total = 0;
        for(int i = 1; i<m_Holes+1; i++)
        {
            total+= m_South[i];
        }
        return total;
    }
}
int Board:: totalBeans() const
{
    return beansInPlay(SOUTH)+beansInPlay(NORTH) +beans(SOUTH, 0)+ beans(NORTH, 0);
}
bool Board::  sow(Side s, int hole, Side& endSide, int& endHole)
{
    if(s == NORTH)
    {
        if(hole<=0 || hole>m_Holes || m_North[hole]==0)
        {
            return false;
        }
        int numBeans =m_North[hole];
        endHole = hole; //first time start with endhole being hole
        endSide = s; // start with endSide being s
        while(numBeans>0) //loop till beans are all gone
        {
            if(endSide == NORTH)
            {
                for(int i = endHole-1; i>=0; i--) //loop from endhole to end of your side
                {
                    
                    if(i == 0) // add to your pot
                    {
                        m_North[0]++;
                        m_North[hole] --;
                        numBeans--;
                        endHole = 0;
                        endSide= opponent(s); //switch sides
                        if (numBeans==0)
                        {
                            endSide= opponent(endSide); //switch sides back
                        }
                        break;
                    }
                    else{ // add bean to hole and subtract from hole
                        m_North[i]++;
                        m_North[hole] --;
                        numBeans--;
                    }
                    if(numBeans==0) //if beans run out break
                    {
                        if(i == 0)
                        {
                            endHole = 0;
                        }
                        else{
                            endHole = i;
                        }
                        break;
                    }
                }
                
            }
            if(endSide==SOUTH && numBeans!=0) //if gets to other side
            {
                for(int i = endHole+1; i<=m_Holes+1; i++) //start at first opponent hole after north's pot
                {
                    if(i==m_Holes+1) // dont add to opponents pot
                    {
                        endHole = i;
                        endSide= opponent(endSide); //swtich sides
                        break;
                    }
                    else{ // add bean to opponents side hole and remove form your hole
                        m_South[i]++;
                        m_North[hole] --;
                        numBeans--;
                    }
                    if(numBeans==0)
                    {
                        endHole = i;
                        break;
                    }
                }
                
                
            }
        }
        return true;
    }
    else
    {
        if(hole<=0 || hole>m_Holes || m_South[hole]==0)
        {
            return false;
        }
        int numBeans =m_South[hole];
        endHole = hole; //first time start with endhole being hole
        endSide = s; // start with endSide being s
        while(numBeans>0) //loop till beans are all gone
        {
            if(endSide == SOUTH)
            {
                for(int i = endHole+1; i<=m_Holes+1; i++) //loop from endhole to end of your side
                {
                    
                    if(i == m_Holes+1) // add to your pot
                    {
                        m_South[0]++;
                        m_South[hole] --;
                        numBeans--;
                        endHole = m_Holes+1;
                        endSide= opponent(s); //switch sides
                        if(numBeans==0)
                        {
                            endSide= opponent(endSide); //switch sides back to south
                            endHole = 0;
                        }
                        break;
                    }
                    else{ // add bean to hole and subtract from hole
                        m_South[i]++;
                        m_South[hole] --;
                        numBeans--;
                    }
                    if(numBeans==0) //if beans run out break
                    {
                        if(i == m_Holes+1)
                        {
                            endHole = 0;
                        }
                        else{
                            endHole = i;
                        }
                        break;
                    }
                }
            }
            if(endSide==NORTH && numBeans!=0) //if gets to other side
            {
                for(int i = endHole-1; i>=0; i--) //start at first opponent hole after north's pot
                {
                    if(i==0) // dont add to opponents pot
                    {
                        endHole = i;
                        endSide= opponent(endSide); //switch sides
                        break;
                    }
                    else{ // add bean to opponents side hole and remove form your hole
                        m_North[i]++;
                        m_South[hole] --;
                        numBeans--;
                    }
                    if(numBeans==0)
                    {
                        endHole = i;
                        break;
                    }
                }
                
                
            }
        }
        return true;
    }
}

                    
                    
                    
                    
                
bool Board:: moveToPot(Side s, int hole, Side potOwner)
{
    if(s == NORTH)
    {
        if(hole<=0 || hole>m_Holes || m_North[hole]==0)
        {
            return false;
        }
        else{
            if (potOwner == NORTH)
            {
                m_North[0]+= m_North[hole];
                m_North[hole]=0;
                return true;
            }
            else{
                m_South[0]+= m_North[hole];
                m_North[hole]=0;
                return true;
            }
        }
    }
    else
    {
        if(hole<=0 || hole>m_Holes || m_South[hole]==0)
        {
            return false;
        }
        else{
            if (potOwner == NORTH)
            {
                m_North[0]+= m_South[hole];
                m_South[hole]=0;
                return true;
            }
            else{
                m_South[0]+= m_South[hole];
                m_South[hole]=0;
                return true;
            }
        }
        
    }
}
bool Board:: setBeans(Side s, int hole, int beans)
{
    if(s ==NORTH)
    {
        if(hole<=0 || hole>m_Holes || beans<0)
        {
            return false;
        }
        else{
            m_North[hole] = beans;
            return true;
        }
    }
    else
    {
        if(hole<=0 || hole>m_Holes || beans<0)
        {
            return false;
        }
        else{
            m_South[hole]= beans;
            return true;
        }
    }
    
}




