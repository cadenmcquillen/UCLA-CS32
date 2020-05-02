//
//  main.cpp
//  Linked List
//
//  Created by Caden McQuillen on 4/21/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    Sequence s;
    s.addToMiddle(0, 0);
    s.addToMiddle(1, 1);
    s.addToMiddle(2, 2);
    s.addToMiddle(3, 3);
    s.addToMiddle(4, 4);
    s.addToMiddle(69, 2);
    s.dump();
    cout<<endl;
    
    cout<<s.findItem(100);
}
