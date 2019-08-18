//
//  hashtable.cpp
//  CS32 Project 4
//
//  Created by Caden McQuillen on 6/3/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//

#include "hashtable.h"


HashTable::HashTable()
{
    m_size = 0;
}




void HashTable:: insert(unsigned int key, string seqeunce)
{
    bucket newBucket(key,seqeunce);
    m_table.push_back(newBucket);
    m_size++;
}


string HashTable::getValue(unsigned int key)
{
    for(unsigned int i = 0; i<m_size; i++)
    {
        if(m_table[i].m_key==key)
        {
            return m_table[i].m_sequence;
        }
    }
    return "";
}


unsigned int HashTable:: size()
{
    return m_size;
}
