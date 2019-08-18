//
//  Player.hpp
//  CS32 project 3
//
//  Created by Caden McQuillen on 5/13/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//

#ifndef Player_h
#define Player_h
#include <iostream>
#include "Board.h"
using namespace std;


#include <chrono>
#include <future>
#include <atomic>
class AlarmClock
{
public:
    AlarmClock(int ms)
    {
        m_timedOut = false;
        m_isRunning = true;
        m_alarmClockFuture = std::async([=]() {
            for (int k = 0; k < ms  &&  m_isRunning; k++)
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            if (m_isRunning)
                m_timedOut = true;
        });
    }
    
    ~AlarmClock()
    {
        m_isRunning = false;
        m_alarmClockFuture.get();
    }
    
    bool timedOut() const
    {
        return m_timedOut;
    }
    
    AlarmClock(const AlarmClock&) = delete;
    AlarmClock& operator=(const AlarmClock&) = delete;
private:
    std::atomic<bool> m_isRunning;
    std::atomic<bool> m_timedOut;
    std::future<void> m_alarmClockFuture;
};



class Player
{
public:
    Player(std::string name);
    std::string name() const;
    virtual bool isInteractive() const; //returns false
    virtual int chooseMove(const Board& b, Side s) const = 0;
    virtual ~Player();
private:
    std::string m_Name;
};

class HumanPlayer: public Player
{
public:
    HumanPlayer(std::string name);
    virtual bool isInteractive() const; //will override and return true
    virtual int chooseMove(const Board& b, Side s) const;
};

class BadPlayer: public Player
{
public:
    BadPlayer(std::string name);
    virtual int chooseMove(const Board& b, Side s) const;
};

class SmartPlayer: public Player
{
public:
    SmartPlayer(std::string name);
    virtual int chooseMove(const Board& b, Side s) const;
//private:
    int minimax(const Board& b, Side mySide, int &bestHole, int &value, AlarmClock& timer) const;
    
};




#endif /* Player_h */
