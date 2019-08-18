//
//  Sequence.hpp
//  CS32 Project 2
//
//  Created by Caden McQuillen on 4/18/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//

#ifndef Sequence_h
#define Sequence_h

#include <stdio.h>
#include <string>

using ItemType = std::string; //unsigned long;

class Sequence
{
public:
    Sequence();
    ~Sequence();
    Sequence(const Sequence& other);
    Sequence& operator=(const Sequence& other);
    
    bool empty() const;
    int size() const;
    int insert(int pos, const ItemType& value);
    int insert(const ItemType& value);// Let p be the smallest integer such that value <= the item at
    // position p in the sequence; if no such item exists (i.e.,
    // value > all items in the sequence), let p be size().  Insert
    // value into the sequence so that it becomes the item at position
    // p.  The original item at position p and those that follow it end
    // up at positions one higher than before.  Return p if the value
    // was actually inserted.  Return -1 if the value was not inserted
    // (perhaps because the sequence has a fixed capacity and is full).
    
    bool erase(int pos);
    int remove(const ItemType& value);
    bool get(int pos, ItemType& value) const;
    bool set(int pos, const ItemType& value);
    int find(const ItemType& value) const;
    void swap(Sequence& other);
    
    void dump() const ;
    
private:
    
    struct Node
    {
        ItemType value;
        Node *next;
        Node *prev;
        
    };
        void addToFront(ItemType value);
        void addToBack(ItemType value);
        void addToMiddle(ItemType value, int pos);
        int findItem(ItemType value) const;
        void deleteItem(ItemType value);
        void deleteItemPos(int pos);
        
        Node *head;
        int length;
        
 
    
   
    
    
};


int subsequence(const Sequence& seq1, const Sequence& seq2);
void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result);

#endif /* Sequence_h */
