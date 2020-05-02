//
//  LinkedList.cpp
//  Linked List
//
//  Created by Caden McQuillen on 4/21/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//

#include "LinkedList.h"
#include <iostream>


void Sequence:: addToFront(ItemType value)
{
    Node *AddNode = new Node(); //Creates a new node object
    AddNode->value= value;  // give value to node
    AddNode->next= head;  // node's next will point at previous first object (null if previously empty)
    AddNode->prev = nullptr; // node's prev will point to null since its first node
    if (head!=nullptr)
    {
        head->prev = AddNode;  //if list isnt empty then prev pointer of the second node must be changed from null to the new node
    }
    head = AddNode; //head points at new node
    length++;
    
}
void Sequence:: addToBack(ItemType value)
{
    
    
    if (head==nullptr)
    {
        addToFront(value);
    }
    else
    {
        Node *iterator = head; //create temp pointer to walk the list
        while(iterator->next!=nullptr) //iterate to the end of the list, goes until its pointing at object with its next pointer = null
        {
            iterator= iterator->next;
        }
        Node *AddNode = new Node(); //creates new node object
        AddNode->value = value;       //assigns value to new node object
        AddNode->next = nullptr;      //since end of list new node next ptr = null
        AddNode->prev = iterator;      // new nodes prev ptr = iterator which points to the previous end of the list
        iterator->next = AddNode;    //makes the previous last node next pointer to the new node
        length++;
    }
    
}

void Sequence:: addToMiddle(ItemType value, int pos)
{
    
    if (head==nullptr)
    {
        addToFront(value);
    }
    else if (pos==0)
    {
        addToFront(value);
    }
    else if(pos==length)
    {
        addToBack(value);
    }
    else
    {
        Node *iterator = head;   //create temp ptr
        for(int i = 0; i <pos-1; i++ )
        {
            if (iterator->next!=nullptr)
            {
                iterator = iterator->next;// walks through the list till it gets to pos
            }
        }
        Node *AddNode = new Node();     //allocate new node
        AddNode->value= value;          // gives new node its value
        AddNode-> prev = iterator;      //makes new nodes prev ptr = to node at pos
        AddNode->next = iterator->next; //makes new nodes next ptr = to next ptr of node at pos
        iterator->next = AddNode;        // makes node at pos's next ptr = new node
        iterator->next->prev = AddNode;  //makes node after pos prev ptr = new node
        length++;
    }
    
}

int Sequence:: findItem(ItemType value) const
{
    int position = 0;
    Node *iterator = head;
    Node *prev = head;
    if (iterator!=nullptr)     //checks if list is empty
    {
        while( iterator != nullptr &&iterator->value!=value) //loop until value is found
        {
            prev = iterator; //increment prev to next node
            iterator= iterator->next; //increment iterator to next node
            position++; //update postion
            
        }
        if (iterator != nullptr && iterator->value==value) // if value isnt found return -1
        {
            return position; //if value is found return postion
            
        }
        
        return -1;
    }
    return -1;
}

void Sequence:: deleteItem(ItemType value)
{
    
    if (head==nullptr) //if list is empty return
    {
        return;
    }
    if (head->value==value) // if value is found at first node
    {
        Node *Delete = head;
        head = Delete->next;
        head->prev= nullptr;
        delete Delete;
        length--;
        return;
    }
    Node *temp= head; // if value isnt found at first node
    while(temp!=nullptr)
    {
        if (temp->next!=nullptr&&temp->next->value ==value) //loop through list breaking if value is found
        {
            break;
            
        }
        temp=temp->next;
    }
    if(temp!=nullptr) // if value is found
    {
        Node *Delete = temp->next; //pointer to node we want to delete
        temp->next = Delete->next; //node before one being deleted next pointer changed to node after one being deleted
        if(Delete->next== nullptr) //if deleting last node (dont need to change prev pointer)
        {
            delete Delete;
            length--;
            
        }
        else{
            Delete->next->prev = temp; //changes previous pointer to node before one being deleted
            delete Delete;
            length--;
        }
        
    }
}


void Sequence:: deleteItemPos(int pos)
{
    if (head==nullptr)
    {
        return;
    }
    else if (pos == 0 )      //if pos is the first node
    {
        Node *Delete = head;
        head = Delete->next;
        head->prev= nullptr;
        delete Delete;
        length--;
        return;
    }
    
    Node *temp = head;
    for(int i =0; /*temp->next!=nullptr && */ i<pos; i++)
    {
        temp= temp->next;
    }
    if (temp->next==nullptr) //if pos is the last node
    {
        Node *previous = temp->prev;
        previous->next = nullptr;
        delete temp;
        length--;
    }
    else{
        
        Node *Previous = temp->prev;
        Previous->next = temp->next;     //makes node before pos next ptr point to node after pos
        temp->next->prev = Previous;     //makes node after pos prev ptr point to node before pos
        delete temp;
        length--;
    }
}

Sequence:: Sequence():length(0),head(nullptr)
{
    
}

Sequence:: ~Sequence()
{
    Node *temp = head;
    while(temp !=nullptr) //loop through list deleting all nodes (new allocated memory)
    {
        Node *next = temp->next;
        delete temp;
        temp = next;
    }
}

void Sequence:: dump() const
{
    Node *p = head;
    while(p!=nullptr)
    {
        std::cerr<<p->value<<std::endl;
        p= p->next;
    }
}
