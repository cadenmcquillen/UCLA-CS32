//
//  LinkedList.hpp
//  Linked List
//
//  Created by Caden McQuillen on 4/21/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
using ItemType = unsigned long;

struct Node
{
    ItemType value;
    Node *next;
    Node *prev;
    
};

struct Sequence
{
    
    Sequence();
    ~Sequence();
    void addToFront(ItemType value);
    void addToBack(ItemType value);
    void addToMiddle(ItemType value, int pos);
    int findItem(ItemType value) const;
    void deleteItem(ItemType value);
    void deleteItemPos(int pos);
    void dump() const;
    
    Node *head;
    int length;
    
};





#endif /* LinkedList_h */
