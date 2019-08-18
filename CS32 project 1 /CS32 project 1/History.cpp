//
//  History.cpp
//  CS32 project 1
//
//  Created by Caden McQuillen on 4/6/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//

#include "History.h"
#include "globals.h"
#include <iostream>
using namespace std;


History :: History( int nRows, int nCols): m_Rows(nRows), m_Cols(nCols) //initializes rows and cols so history's arena knows how big to make grid
{
    for (int i = 0; i<nRows; i++) // makes grid thats of size of give rows/cols
    {
        for (int j =0; j< nCols; j++)
        {
            m_Arena[i][j] = 0 ; // sets the number of deaths for every coordinant at 0
        }
        
    }
    
}


bool History :: record(int r , int c)
{
    if (r > m_Rows || c > m_Cols)
    {
        return false;
    }
    else // puts 1 at coordinats in m_Arena grid and increase the number for every occurance
    {
        m_Arena[r-1][c-1]++;
        return true;
    }
}

void History :: display() const
{
    char m_grid[MAXCOLS][MAXCOLS]; // grid of char since not data member can be changed despite const
    
    for (int i = 0; i<m_Rows; i++) //fills char grid with dots
    {
        for (int j =0; j< m_Cols; j++)
        {
            m_grid[i][j] = '.';
        }
        
    }
    
    
    
    for (int i = 0; i< m_Rows; i++)
        {
            for (int j = 0; j <m_Cols; j++)
            {
                if (m_Arena[i][j]>=26)
                {
                    m_grid[i][j]= 'Z';
                }
                else if (m_Arena[i][j]>0)
                {
                    m_grid[i][j] = 'A' + (m_Arena[i][j]-1);
                }
            }
        }
    
    clearScreen();
    for (int i = 0; i < m_Rows; i++)
    {
        for (int j = 0; j < m_Cols; j++)
        
            cout << m_grid[i][j];
            cout << endl;
        
    }
    cout << endl;
    
   
   
    
}
