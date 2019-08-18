//
//  Sequence.cpp
//  CS32 Project 2
//
//  Created by Caden McQuillen on 4/18/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//

#include "Sequence.h"
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
    else if(pos==length-1)
    {
        addToBack(value);
    }
    else
    {
        Node *iterator = head;   //create temp ptr
        for(int i = 0; i <pos; i++ )
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
        if(AddNode->next!=nullptr){
        iterator->next->prev = AddNode;  //makes node after pos prev ptr = new node
        }
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
        if (iterator!= nullptr&&iterator->value==value) // if value isnt found return -1
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
        if (size()!=1)
        {
            head->prev= nullptr;
        }
        
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
    else if(size()==1) //only one node
    {
        Node *Delete = head;
        head = Delete->next;
        delete Delete;
        length--;
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

Sequence:: Sequence(const Sequence& other)
{
    if (other.head== nullptr)
    {
        head = nullptr; // if other is an empty linked list
        length = 0;
    }
    else{
        length = other.length;
        head = new Node; //create first node
        head->value = other.head->value; //give it other's value
        head->next = other.head->next; // give it other's next ptr
        head->prev = nullptr; //prev will always be null
        Node *thisCurrent = head;
        Node *otherCurrent = other.head;
        while(otherCurrent->next!=nullptr) //loop through other
        {
            thisCurrent->next= new Node; //create new node
            thisCurrent->next->value = otherCurrent->next->value; //give it others value
            thisCurrent->next->next = otherCurrent->next->next; //give it others next ptr
            thisCurrent->next->prev = thisCurrent; // prev will always be thiscurrent node
            
            thisCurrent = thisCurrent->next; //incrment to next node
            otherCurrent = otherCurrent->next; // increment to next node
        }
    }
}


Sequence& Sequence:: operator=(const Sequence& other)
{
    if (head != other.head)
    {
        Node *temp = head;      //clean up allocated memory
        while(temp !=nullptr)
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }

        if (other.head== nullptr)
        {
            head = nullptr; // if other is an empty linked list
            length = 0;
        }
        else{
            length = other.length; // give length of the other sequence
            head = new Node;
            head->value = other.head->value;
            head->next = other.head->next;
            head->prev = nullptr;
            Node *thisCurrent = head;
            Node *otherCurrent = other.head;
            while(otherCurrent->next!=nullptr)
            {
                thisCurrent->next= new Node;
                thisCurrent->next->value = otherCurrent->next->value;
                thisCurrent->next->next = otherCurrent->next->next;
                thisCurrent->next->prev = thisCurrent;
                
                thisCurrent = thisCurrent->next;
                otherCurrent = otherCurrent->next;
            }
        }
    }
    return *this;
}


bool Sequence:: empty() const
{
    if(length==0)
    {
        return true;
    
    }
    else{
        return false;
    }
}

int Sequence:: size() const
{
    return length;
}


int Sequence:: insert(int pos, const ItemType& value)
{
    if (pos>=0&&pos<=size()) // if postion parameter is less than length of the list and non negative
    {
        addToMiddle(value,pos ); //insert into list
        return pos;
    }
    else{
        return -1;
    }
}

int Sequence:: insert(const ItemType& value)
{
    Node *temp = head;
    int p = size();
    int i = 0;
    while(i<size()) //compare and insert in order
    {
        if (value<=temp->value)
        {
            p = i;
        }
        i++;
        temp=temp->next;
    }
    addToMiddle(value, p);
    return p;
    
}

bool Sequence:: erase(int pos)
{
    if (pos>=0 && pos<=length-1)
    {
        deleteItemPos(pos);
        return true;
    }
    else{
        return false;
    }
}

 int Sequence:: remove(const ItemType& value)
{
    
    int counter =0;
    int p = size();
    while(p>0)
    {
        if (findItem(value)==-1)
        {
            break;
        }
        deleteItem(value);
        counter++;
        p--;
    }
    return counter;
    
}

bool Sequence:: get(int pos, ItemType& value) const
{
    if (pos>=0&&pos<size()) //if postion is within bounds of the size of the sequence, since starting with 0th element the last element is size()-1
    {
        Node *temp = head;
        for(int i = 0; i<pos; i++) //loop though to given postion
        {
            temp = temp->next;
        }
        
        value = temp->value; //store that nodes value into value
        return true;
    }
    return false;
}

bool Sequence:: set(int pos, const ItemType& value)
{
    if (pos>=0&&pos<size()) //if postion is within bounds of the size of the sequence, since starting with 0th element the last element is size()-1
    {
        Node *temp = head;
        for(int i = 0; i<pos; i++)
        {
            temp = temp->next;
        }
        temp->value= value; //change nodes value to value parameter
        return true;
    }
    return false;
}


int Sequence:: find(const ItemType& value) const
{
    return findItem(value);
}

void Sequence:: swap(Sequence& other)
{
    Node *temp1 = head; //create pointer to head
    Node *temp2 = other.head; // create a pointer to others head
    head = temp2; //make head point at other's head
    other.head = temp1; //make other's head point at head
    
    int tempLength = length; //swap the lengths
    length = other.length;
    other.length = tempLength;
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


// int subsequence(const Sequence& seq1, const Sequence& seq2);




int subsequence(const Sequence& seq1, const Sequence& seq2)
{
    ItemType value1;
    ItemType value2;
    Sequence s3;
    int position=0;
    if (seq1.empty()==true || seq2.empty()==true) //check if either are empty
    {
        return -1;
    }
    
    for(int j= 0; j<seq1.size(); j++) //loop through longer seqeunce
    {
        seq1.get(j, value1); //compare value to the first value of short sequence
        seq2.get(0, value2);
        if (value1==value2)
        {
            position = j; //if the same store in j
            
            for(int k = 0, i = j; k<seq2.size(); k++, i++) //loop through both with longer starting at j, only loops through the length of seq 2 so all values have to be in consective order
            {
                seq1.get(i, value1);
                seq2.get(k, value2);
                if (value1==value2) //if theyre the same store in empty sequence
                {
                    s3.insert(k, value1);
                }
                
            }
        }
    }
    if (s3.size()==seq2.size()) //if same size it means that all of short seqeuence was contained in long sequence
    {
        return position;
    }
    else{
        return -1;
    }
}



void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result)
{
   
    ItemType value1;
    ItemType value2;
    
    
    while(result.size()!=0) //erase anything in result
    {
        result.erase(0);
    }
    
    if (seq1.empty()==true && seq2.empty()==true) //check if both are empty
    {
        return;
    }
    else if(seq1.empty()==true) //check if one emptry, return the other one
    {
        result = seq2;
    }
    else if (seq2.empty()==true)//check if one emptry, return the other one
    {
        result = seq1;
    }
    else
    {
        if (seq1.size()>=seq2.size()) // if first is bigger
        {
            seq1.get(0, value1); //insert the first values
            seq2.get(0,value2);
            result.insert(0, value1);
            result.insert(1, value2);
            for (int i = 1; i<seq2.size();i++) //loop through shorter
            {
                seq1.get(i, value1);
                seq2.get(i,value2);
                result.insert(i*2, value1); //insert at alternating posistions
                result.insert((i*2)+1 , value2);
            }
            for (int j = seq2.size()*2 ; j<seq1.size()+seq2.size(); j++) //finish inserting longer sequence
            {
                if (j % 2 == 0) //an even number
                {
                    seq1.get(j/2, value1);
                    result.insert(j, value1);
                }
                else{
                    seq1.get((j+1)/2, value1);
                    result.insert(j, value1);
                }
               
            }
            
        }
        else // if the second is longer do the same but switched
        {
                seq2.get(0, value1);
                seq1.get(0,value2);
                result.insert(0, value1);
                result.insert(1, value2);
                for (int i = 1; i<seq1.size();i++)
                {
                    seq2.get(i, value1);
                    seq1.get(i,value2);
                    result.insert(i*2, value1);
                    result.insert((i*2)+1 , value2);
                }
                for (int j = seq1.size()*2 ; j<seq1.size()+seq2.size(); j++)
                {
                    if (j % 2 == 0) //an even number
                    {
                        seq2.get(j/2, value1);
                        result.insert(j, value1);
                    }
                    else{
                        seq2.get((j+1)/2, value1);
                        result.insert(j, value1);
                    }
                    
                }
                
            
        }
    }
}



