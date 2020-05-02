//
//  Sequence.cpp
//  Homework 1
//
//  Created by Caden McQuillen on 4/13/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//

#include "Sequence.h"
using namespace std;

Sequence:: Sequence():counter(0)
{
    
}

bool Sequence:: empty() const
{
    if (counter == 0)
    {
        return true;
    }
    else{
        return false;
    }
}

int Sequence:: size() const
{
    return counter;
}

int Sequence :: insert(int pos, const ItemType& value)
{
    if (0 <= pos && pos <= size())
    {
        if (pos == size())
        {
            counter +=1;
            m_array[pos]= value;
            return pos;
        }
        for (int i = size(); i>pos; i--)
        {
            m_array[i]=m_array[i-1];
            
        }
        m_array[pos]= value;
        counter +=1;
        return pos;
    }
    else
    {
        return -1;
    }

}

int Sequence:: insert(const ItemType& value)
{
    if (size()==DEFAULT_MAX_ITEMS)
    {
        return -1;
    }
    else{
        
    
            int p = size();
            for (int i= size(); i>=0 ;i--)
            {
                if (m_array[i]>=value)
                {
                    p = i;
                }
                
            }
           if (p==size())
           {
               m_array[p]= value;
               counter+=1;
               return p;
           }
           else{
               for (int i = size(); i>p; i--)
               {
                   m_array[i]=m_array[i-1];
                   
               }
               m_array[p]= value;
               counter +=1;
               return p;
           }
    
    }
}

bool Sequence:: erase(int pos)
{
    if (0 <= pos && pos < size())
    {
        for (int i =pos; i<size(); i++)
        {
            m_array[i]=m_array[i+1];
        }
        counter-=1;
        return true;
    }
    else{
        return false;
    }
}

int Sequence:: remove(const ItemType& value)
{
    int j = 0;
    int numTimes = 0;
    for(int i = 0; i<size(); i++)
    {
        if(m_array[i]!=value)
        {
            m_array[j]=m_array[i];
            j+=1;
        }
        else{
            numTimes+=1;
        }
    }
    counter-=numTimes;
    return numTimes;
}

bool Sequence:: get(int pos, ItemType& value) const
{
    if (0 <= pos && pos < size())
    {
        value = m_array[pos];
        return true;
    }
    else
    {
        return false;
    }
}

bool Sequence:: set(int pos, const ItemType& value)
{
    if (0 <= pos && pos < size())
    {
        m_array[pos]= value;
        return true;
    }
    else{
        return false;
    }
}

int Sequence:: find(const ItemType& value) const
{
    int p=size();
    int numSize =0;
    for(int i = size();i>=0; i--)
    {
        if (m_array[i]==value)
        {
            p=i;
            numSize+=1;
        }
    }
    if (numSize==0)
    {
        return -1;
    }
    else{
        return p;
    }
    
    
}

void Sequence:: swap(Sequence& other)
{
    int diff = abs(size()-other.size());
    int i = 0;
    while (i<size()&&i<other.size())
    {
        ItemType x = other.m_array[i];
        other.m_array[i]= m_array[i];
        m_array[i]= x;
        i++;
    }
   if (diff!=0)
   {
       for(int j = i; j<((size()+other.size())/2 + diff);j++)
       {
           ItemType x = other.m_array[j];
           other.m_array[j]= m_array[j];
           m_array[j]= x;
           if (size()>other.size())
           {
               counter -= 1;
               other.counter+=1;
           }
           else{
               counter+=1;
               other.counter-=1;
           }
       }
    
   }
    
    
    

}

void Sequence:: dump() const
{
    for (int i = 0; i<size(); i++)
    {
        cerr<<m_array[i]<<endl;
    }
}
