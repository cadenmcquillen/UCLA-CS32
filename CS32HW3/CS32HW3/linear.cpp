//
//  linear.cpp
//  CS32HW3
//
//  Created by Caden McQuillen on 5/6/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//



bool allTrue(const string a[], int n)
{
    if(n<1) // doesnt look at any elements if n is 0 or below
    {
        return true; //check this
    }
    else if (n == 1) //stop at the 0th element in the array which is when n = 1
    {
        bool result =somePredicate(a[0]);
        return result;
    }
    else
    {
        if (somePredicate(a[n-1])==true)//n is the number of items but arrays start at 0
        {
            return allTrue(a, n-1); //call itself but with n incremented down
            
        }
        else
        {
            return false;
        }
        
    }
    
}


int countFalse(const string a[], int n)
{
    int counter = 0;
    if (n<1) // dont look at any elements
    {
        return 0;
    }
    else if (n==1) //stop at the 0th element in the array which is when n = 1
    {
        if (somePredicate(a[0])==true)
        {
            return counter;
        }
        else{
            counter ++; //if false increment counter
            return counter;
        }
    }
    
    else{
        if(somePredicate(a[n-1])==true)
        {
            return counter+ countFalse(a, n-1); //return whatever current running total is plus countFalse (if its true then counter will be 0 plus running total)
        }
        else{
            counter ++; //increment counter
            return counter+ countFalse(a, n-1); //return counter plus running total
        }
    }
}


int firstFalse(const string a[], int n)
{
    int subscript = 0;
    if (n<=0) //looking at no elements
    {
        return -1;
    }
    else
    {
        if(somePredicate(a[0])==false)
        {
            return subscript;
        }
        else
        {
            subscript = firstFalse(a+1,n-1);
            if (subscript==-1) // if goes through entire array w/o false
            {
                return -1;
            }
            return subscript+1; 
            
        }
    }
}

int indexOfLeast(const string a[], int n)
{
  
    if (n<=0) // looking at no elements
    {
        return -1;
    }
    else if (n==1) //if you get to first element (n gets decrement all the way to 1)
    {
        return n-1;
    }
    else{
        if (a[n-1]<a[indexOfLeast(a,n-1)]) //if last element is less than all other elements
        {
            
            return n-1;
        }
        else{
            return indexOfLeast(a, n-1); //go to next element
        }
    }
}


bool includes(const string a1[], int n1, const string a2[], int n2)
{
    if(n1<=0 ) // a1 doesnt have any elements
    {
        return false;
    }
    else if (n2<=0) // a2 has no elements
    {
        return true;
    }
    else if(n2==1) //when only 1 element
    {
        if (n1==1) //base case
        {
            if (a2[0]==a1[n1-1])
            {
                return true;
            }
            else{
                return false;
            }
        }
        else
        {
            if(a1[n1-1]==a2[n2-1])
            {
                return true;
            }
            else
            {
                return includes(a1,n1-1,a2,n2); //check the next element in a1 (from the back)
            }
        }
    }
    else
    {
        if(a1[n1-1]==a2[n2-1])
        {
            return includes(a1,n1,a2,n2-1); //found the first element of a2 look for next one
        }
        else
        {
            return includes(a1,n1-1,a2,n2); //look at next element of a1
        }
    }
}


