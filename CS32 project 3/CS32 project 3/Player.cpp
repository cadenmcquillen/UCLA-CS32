//
//  Player.cpp
//  CS32 project 3
//
//  Created by Caden McQuillen on 5/13/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//

#include "Player.h"


Player:: Player(std::string name)
{
    m_Name = name;
}
std::string Player:: name() const
{
    return m_Name;
}
bool Player:: isInteractive() const
{
    return false;
}
Player::~Player()
{
    
}

//HUMAN PLAYER

HumanPlayer::HumanPlayer(std::string name):Player(name)
{
    
}
bool HumanPlayer:: isInteractive() const
{
    return true;
}
int HumanPlayer:: chooseMove(const Board& b, Side s) const
{
    int move= 0;
    cout<<"Please choose a valid hole, "<<name()<<endl;
    while(true) //keep prompting until valid move
    {
        cin>>move;
        if(move>=1 && move<=b.holes() && b.beans(s, move)!=0 ) //check for valid move
        {
            return move;
        }
        cout<<"Please choose a valid hole, " <<name()<<endl;
    }
    
}

// BAD PLAYER

BadPlayer:: BadPlayer(std::string name): Player(name)
{
    
}
int BadPlayer::chooseMove(const Board& b, Side s) const
{
    for(int i = 1; i<b.holes()+1; i++) //loop until first hole with at least one bean
    {
        if (b.beans(s, i)!=0)
        {
            return i;
        }
    }
    return -1;
}

//SMART PLAYER




SmartPlayer::SmartPlayer(std::string name): Player(name)
{
    
}
int SmartPlayer::chooseMove(const Board& b, Side s) const
{
    int bestHole;
    int value;
    AlarmClock timer(4900);
    minimax(b, s, bestHole , value, timer);
    return bestHole;
}


int SmartPlayer::minimax(const Board& b, Side mySide, int &bestHole, int &value,AlarmClock& timer) const
{
    
    Board copy(b);
    int endHole,bestHole2;
    int v2;
    Side endSide;
    
   
    if(copy.beansInPlay(NORTH)==0 || copy.beansInPlay(SOUTH)==0) //game over
    {
        bestHole = -1;
       
        for (int i = 1; i < copy.holes() + 1; i++) //sweep remaining beans
        {
            copy.moveToPot(opponent(mySide), i , opponent(mySide));
            copy.moveToPot(mySide, i, mySide);
        }

        
        if(copy.beans(mySide, 0)>copy.beans(opponent(mySide), 0))
        {
            if(mySide==SOUTH)
            {
                value = 10000; //big number for south win
            }
            else{
                value = -10000; // negative number for north win
            }
        }
        else if (copy.beans(mySide, 0)<copy.beans(opponent(mySide), 0))
        {
            if(mySide==SOUTH)
            {
                value = -10000;  // bad for south
            }
            else{
                value = 10000; // bad for north
            }
        }
        else{
            value = 0; //tie
        }
        return 0;
    }
    if(timer.timedOut()==true) //limiting criterion
    {
        bestHole = -1;
        value = copy.beans(SOUTH, POT)- copy.beans(NORTH, POT);
        return 0;
    }
    if(mySide==SOUTH)
    {
        value = -100000000; //intialize value to super negative number if south
    }
    else{
        value = 100000000; //intialize value to super big number if north
    }
    for(int i = 1; i<b.holes()+1; i++) //limits to between first hole and number of holes
    {
        
        if (copy.beans(mySide,i ) == 0) // dont pick empty hole
        {
            continue;
        }
        copy.sow(mySide, i, endSide, endHole); //"make" the move
        if(endSide==mySide && endHole == POT) // lands in your pot 
        {
            minimax(copy,mySide, bestHole2, v2, timer);
        }
        else if(endSide==mySide && copy.beans(endSide, endHole) == 1 ) //capture
        {
            if(copy.beans(opponent(mySide), endHole)>0) // if opponent side has no beans
            {
                copy.moveToPot(opponent(mySide), endHole, mySide);
                copy.moveToPot(mySide, endHole, mySide);
            }
        }
        minimax(copy,opponent(mySide), bestHole2, v2, timer);
        copy = b; //unmake move
        if((v2 > value && mySide == SOUTH) || (v2 < value && mySide == NORTH))
        {
            bestHole = i;
            value = v2;
        
        }
    }
    return bestHole;
}

