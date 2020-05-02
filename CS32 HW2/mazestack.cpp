//
//  mazestack.cpp
//  Homework 2 Q1
//
//  Created by Caden McQuillen on 4/27/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//



#include <iostream>
#include <stack>
using namespace std;

class Coord
{
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};


bool pathExists(char maze[][10], int sr, int sc, int er, int ec);

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    stack<Coord> coordStack;
    coordStack.push(Coord(sr,sc));
    maze[sr][sc] = '0';
    while (coordStack.empty()==false)
    {
        Coord currentCoord = coordStack.top();
        Coord endCoord(er,ec);
        coordStack.pop();
        if (currentCoord.c() == endCoord.c() && currentCoord.r()==endCoord.r())
        {
            return true;
        }
        else
        {
            if(maze[currentCoord.r()+1][currentCoord.c()]=='.') //if south is unxplored and not a wall
            {
                coordStack.push(Coord(currentCoord.r()+1, currentCoord.c()));
                maze[currentCoord.r()+1][currentCoord.c()] = '0';
            }
            if(maze[currentCoord.r()][currentCoord.c()-1]=='.') //west
            {
                coordStack.push(Coord(currentCoord.r(), currentCoord.c()-1));
                maze[currentCoord.r()][currentCoord.c()-1] = '0';
            }
            if(maze[currentCoord.r()-1][currentCoord.c()]=='.') //north
            {
                coordStack.push(Coord(currentCoord.r()-1, currentCoord.c()));
                maze[currentCoord.r()-1][currentCoord.c()] = '0';
            }
            if(maze[currentCoord.r()][currentCoord.c()+1]=='.') //east
            {
                coordStack.push(Coord(currentCoord.r(), currentCoord.c()+1));
                maze[currentCoord.r()][currentCoord.c()+1] = '0';
            }
            
        }
        
    }
    return false;
}



