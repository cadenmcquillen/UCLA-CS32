//
//  hashtable.h
//  CS32 Project 4
//
//  Created by Caden McQuillen on 6/3/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef hashtable_h
#define hashtable_h

struct bucket
{
    bucket(unsigned int key, string sequence)
    {
        m_key = key;
        m_sequence = sequence;
    }
    string m_sequence;
    unsigned int m_key;
};





class HashTable
{
public:
    HashTable();
    void insert(unsigned int key, string seqeunce);
    string getValue(unsigned int key);
    unsigned int size();
    
    
private:
    unsigned int m_size;
    vector<bucket> m_table;
    
    
};




#endif /* hashtable_h */
