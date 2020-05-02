//
//  maze.cpp
//  CS32HW3
//
//  Created by Caden McQuillen on 5/8/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//

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

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    Coord startCoord(sr,sc);
    if (startCoord.c()==ec &&startCoord.r()==er)
    {
        return true;
    }
    maze[startCoord.r()][startCoord.c()]= '0';
    for(int i = 0; i<4; i++)
    {
        if(i==0)//south
        {
    
            if (maze[startCoord.r()][startCoord.c()-1]=='.')
            {
                bool result = pathExists(maze,startCoord.r(), startCoord.c()-1 ,er, ec);
                if (result==true)
                {
                    return true;
                }
            }
        }
        if(i==1)//west
        {
            
            if (maze[startCoord.r()-1][startCoord.c()]=='.')
            {
                bool result = pathExists(maze,startCoord.r()-1, startCoord.c() ,er, ec);
                if (result==true)
                {
                    return true;
                }
            }
        }
        if(i==2)//North
        {
            
            if (maze[startCoord.r()][startCoord.c()+1]=='.')
            {
                bool result = pathExists(maze,startCoord.r(), startCoord.c()+1 ,er, ec);
                if (result==true)
                {
                    return true;
                }
            }
        }
        if(i==3)//east
        {
            
            if (maze[startCoord.r()+1][startCoord.c()]=='.')
            {
                bool result = pathExists(maze,startCoord.r()+1, startCoord.c() ,er, ec);
                if (result==true)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
