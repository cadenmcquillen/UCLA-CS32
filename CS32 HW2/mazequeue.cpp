//
//  mazequeue.cpp
//  Homework 2 Q1
//
//  Created by Caden McQuillen on 4/28/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//

#include <iostream>
#include <queue>
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
    queue<Coord> coordQueue;
    coordQueue.push(Coord(sr,sc));
    maze[sr][sc] = '0';
    while (coordQueue.empty()==false)
    {
        Coord currentCoord = coordQueue.front();
        Coord endCoord(er,ec);
        coordQueue.pop();
        if (currentCoord.c() == endCoord.c() && currentCoord.r()==endCoord.r())
        {
            return true;
        }
        else
        {
            if(maze[currentCoord.r()+1][currentCoord.c()]=='.') //if south is unxplored and not a wall
            {
                coordQueue.push(Coord(currentCoord.r()+1, currentCoord.c()));
                maze[currentCoord.r()+1][currentCoord.c()] = '0';
            }
            if(maze[currentCoord.r()][currentCoord.c()-1]=='.') //west
            {
                coordQueue.push(Coord(currentCoord.r(), currentCoord.c()-1));
                maze[currentCoord.r()][currentCoord.c()-1] = '0';
            }
            if(maze[currentCoord.r()-1][currentCoord.c()]=='.') //north
            {
                coordQueue.push(Coord(currentCoord.r()-1, currentCoord.c()));
                maze[currentCoord.r()-1][currentCoord.c()] = '0';
            }
            if(maze[currentCoord.r()][currentCoord.c()+1]=='.') //east
            {
                coordQueue.push(Coord(currentCoord.r(), currentCoord.c()+1));
                maze[currentCoord.r()][currentCoord.c()+1] = '0';
            }
            
        }
        
    }
    return false;
}

