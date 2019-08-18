//
//  Game.cpp
//  CS32 project 3
//
//  Created by Caden McQuillen on 5/13/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//

#include "Game.h"


Game::Game(const Board& b, Player* south, Player* north):m_Board(b) //create copy of board b
{
    m_SouthPlayer = south;
    m_NorthPlayer = north;
    m_CurrentSide = SOUTH;
}
void Game:: display() const
{
    for (int i =0; i<m_Board.holes()/2;
         i++) // print north player halfway
    {
        std::cout<<"   ";
    }
    std::cout << m_NorthPlayer->name() << endl;
    
    std::cout << "     ";
    for (int i = 1; i <= m_Board.holes(); i++) {
        std::cout << m_Board.beans(NORTH, i) << "   ";
    }
    std::cout << endl;
    
    std::cout << "  " << m_Board.beans(NORTH, 0);
    
    for (int i = 0; i < m_Board.holes(); i++) {
        std::cout << "    ";
    }
    
    std::cout << m_Board.beans(SOUTH, 0) << endl;
    
    std::cout << "     ";
    for (int i = 1; i <= m_Board.holes(); i++) {
        std::cout << m_Board.beans(SOUTH, i) << "   ";
    }
    std::cout << endl;
    
    for (int i =0; i<m_Board.holes()/2;
         i++) // print south player halfway
    {
        std::cout<<"   ";
    }
    std::cout << m_SouthPlayer->name() << endl;
}
void Game::status(bool& over, bool& hasWinner, Side& winner) const
{
    if(m_Board.beansInPlay(NORTH)==0 && m_Board.beansInPlay(SOUTH)==0)
    {
        over = true;
        if(m_Board.beans(NORTH, POT)> m_Board.beans(SOUTH,POT))
        {
            hasWinner = true;
            winner = NORTH;
        }
        else if(m_Board.beans(NORTH, POT)< m_Board.beans(SOUTH,POT))
        {
            hasWinner = true;
            winner = SOUTH;
        }
        else{
            hasWinner = false;
        }
    }
    else{
        over = false;
    }
}

bool Game::move()
{
    if(m_Board.beansInPlay(NORTH)==0 && m_Board.beansInPlay(SOUTH)==0)
    {
        return false;
    }
    else{
        Side endSide;
        int endHole;
        if(m_CurrentSide==SOUTH)
        {
            m_Board.sow(m_CurrentSide,m_SouthPlayer->chooseMove(m_Board,m_CurrentSide) , endSide, endHole );
            if(m_Board.beansInPlay(SOUTH)==0)//sweep north side beans into pot
            {
                for(int i =1; i<m_Board.holes()+1; i++)
                {
                    m_Board.moveToPot(NORTH, i, NORTH);
                }
            }
            while(endSide==SOUTH && endHole == POT) // lands in your own pot
            {
                display();
                m_Board.sow(endSide,m_SouthPlayer->chooseMove(m_Board,endSide) , endSide, endHole );
                    if(m_Board.beansInPlay(SOUTH)==0)//sweep north side beans into pot
                    {
                        for(int i =1; i<m_Board.holes()+1; i++)
                        {
                            m_Board.moveToPot(NORTH, i, NORTH);
                        }
                        break;
                    }
            }
            if(endSide==SOUTH && m_Board.beans(endSide, endHole)==1 && m_Board.beans(NORTH, endHole)> 0) //capture
            {
                m_Board.moveToPot(NORTH,endHole , SOUTH); //beans from oppostie side
                m_Board.moveToPot(SOUTH, endHole, SOUTH); //plus bean landed in empty hole
                if(m_Board.beansInPlay(SOUTH)==0)//sweep north side beans into pot
                {
                    for(int i =1; i<m_Board.holes()+1; i++)
                    {
                        m_Board.moveToPot(NORTH, i, NORTH);
                    }
                }
            }
            
            m_CurrentSide = opponent(m_CurrentSide);
            return true;
        }
        else{
            m_Board.sow(m_CurrentSide,m_NorthPlayer->chooseMove(m_Board,m_CurrentSide) , endSide, endHole );
            if (m_Board.beansInPlay(NORTH)==0) //sweep south side beans into pot
            {
                for(int i =1; i<m_Board.holes()+1; i++)
                {
                    m_Board.moveToPot(SOUTH, i, SOUTH);
                }
            }
            while(endSide==NORTH && endHole == POT) // lands in your own pot
            {
                display();
                m_Board.sow(endSide,m_NorthPlayer->chooseMove(m_Board,endSide) , endSide, endHole );
                if (m_Board.beansInPlay(NORTH)==0) //sweep south side beans into pot
                {
                    for(int i =1; i<m_Board.holes()+1; i++)
                    {
                        m_Board.moveToPot(SOUTH, i, SOUTH);
                    }
                    break;
                }
            }
            if(endSide==NORTH && m_Board.beans(endSide, endHole)==1 && m_Board.beans(SOUTH, endHole) > 0) //capture
            {
                m_Board.moveToPot(SOUTH,endHole ,NORTH);
                m_Board.moveToPot(NORTH, endHole, NORTH);
                if (m_Board.beansInPlay(NORTH)==0) //sweep south side beans into pot
                {
                    for(int i =1; i<m_Board.holes()+1; i++)
                    {
                        m_Board.moveToPot(SOUTH, i, SOUTH);
                    }
                }
            }
            m_CurrentSide = opponent(m_CurrentSide);
            return true;
        }
    }
}
void Game::play()
{
    display();
    while (move()==true)
    {
        //if neither player is human
        if (m_NorthPlayer->isInteractive()==false && m_SouthPlayer->isInteractive()==false)
        {
            display();
            cout << "Press ENTER to continue";
            cin.ignore(10000, '\n');
        }
        else
        {
            display();
        }
    }
    display();
    
    bool over, hasWinner;
    Side winner;
    status(over, hasWinner, winner);
    if (hasWinner == false)
        cout << "The game resulted in a tie." << endl;
    if (winner == NORTH)
        cout << "The winner is " << m_NorthPlayer -> name() << "." << endl;
    else if (winner == SOUTH)
        cout << "The winner is " << m_SouthPlayer -> name() << "." << endl;

}

int Game:: beans(Side s, int hole) const
{
        return m_Board.beans(s, hole);
}
