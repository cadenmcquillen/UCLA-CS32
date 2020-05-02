//
//  eval.cpp
//  Homework2Q5
//
//  Created by Caden McQuillen on 4/30/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//

#include <stack>
#include <queue>
#include <iostream>
using namespace std;

int evaluate(string infix, string& postfix, bool& result);

int evaluate(string infix, string& postfix, bool& result)
{
   
    queue<char>checkQueue;
    if(infix.length()==0) //cant be empty
    {
        return 1;
    }
    int operandCounter=0;
    int binaryCounter=0;
    for(int i = 0; i<infix.length(); i++)
    {
        if(infix[i]=='T' || infix[i]=='F' )
        {
            operandCounter++;
        }
        if(infix[i]=='^' || infix[i]=='&')
        {
            binaryCounter++;
        }
    }
    if(operandCounter ==0 || operandCounter<=binaryCounter){ //cant be more or same number of binary operators as operands or no operands
        return 1;
    }
    
    
    checkQueue.push(infix[0]);
    for(int i = 1; i<infix.length(); i++) //checking valid infix string, doesnt check for matching parathesis will be checked later
    {
        switch (infix[i])
        {
            
            case 'T':
            case 'F':
                    if (checkQueue.back()=='T' ||checkQueue.back()=='F' || checkQueue.back()==')')//checks that theres an operator between prev expression
                    {
                        return 1;
                    }
                
                checkQueue.push(infix[i]);
                break;
            case ' ':
                break;
            case '(':
                if (checkQueue.back() =='T' || checkQueue.back()== 'F' || checkQueue.back()== ')') //checks that theres an operator between prev expression and new set of parathesis
                {
                    return 1;
                }
                checkQueue.push(infix[i]);
                break;
            case ')':
                if (checkQueue.empty()==true) //cant be the first element
                {
                    return 1;
                }
                if (checkQueue.back()=='(') //empty set of parathesis
                {
                    return 1;
                }
                checkQueue.push(infix[i]);
                break;
            case '&':
            case '^':
                if (checkQueue.empty()==true) //cant be the first element
                {
                    return 1;
                }
                if (checkQueue.back()=='^' || checkQueue.back()=='&' || checkQueue.back()=='!') //cant be two operators next to each other
                {
                    return 1;
                }
                checkQueue.push(infix[i]);
                break;
            case '!':
                checkQueue.push(infix[i]);
                break;
                
            default:
                return 1;
                
        }
        
        
    }
    
    //Converting infix to postfix
    postfix = "";
    stack<char>operatorStack;
    for(int ch = 0; ch<infix.length(); ch++)
    {
        switch (infix[ch])
        {
            case 'T':
            case 'F':
                postfix += infix[ch]; //if operand just add to postfix string
                break;
            case ' ':
                break;
            case '(':
                operatorStack.push(infix[ch]); //push open parathesis onto stack
                break;
            case ')' :
                while(operatorStack.top()!='(') //loop till you find matching parethesis
                {
                    postfix+=operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.pop(); //pop ( off the stack
                break;
            case '!':
                while(operatorStack.empty()!=true  && operatorStack.top()!='(' && operatorStack.top()== '!') // has highest precedence so can only be = and not <
                {
                    postfix+=operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push(infix[ch]);
                break;
           
            case '&':
                while(operatorStack.empty()!=true  && operatorStack.top()!='(' && operatorStack.top()!= '^') // only precedence less is ^
                {
                    postfix+=operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push(infix[ch]);
                break;
                
            case '^':
               
                while(operatorStack.empty()!=true && operatorStack.top()!= '(' ) //lowest precedence so alwasys <= top
                {
                    postfix+=operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push(infix[ch]);
                break;
        }
        
    }
    while(operatorStack.empty()!=true)
    {
        if (operatorStack.top()=='(') //check for unclosed paranthesis
        {
            return 1;
        }
        postfix+=operatorStack.top();
        operatorStack.pop();
    }

    
    //Evaluating postfix
    stack<char>operandStack;
    for (int j = 0; j<postfix.length();j++)
    {
        if(postfix[j]=='T' || postfix[j]=='F') //if its operand push onto stack
        {
            operandStack.push(postfix[j]);
        }
        else if(postfix[j]=='!') //unary operator
        {
            if (operandStack.top()=='T') //switch true to false
            {
                operandStack.pop();
                operandStack.push('F');
            }
            else{
                operandStack.pop();
                operandStack.push('T');
            }
        
        }
        else
        {
            char operand2 = operandStack.top();
            operandStack.pop();
            char operand1 = operandStack.top();
            operandStack.pop();
            bool temp;
            if(postfix[j]=='^')
            {
                if(operand1=='T')
                {
                    if(operand2 == 'T')
                    {
                        temp = true^true;
                    }
                    else{
                        temp = true^false;
                    }
                    
                }
                else
                {
                    if(operand2 == 'T')
                    {
                        temp = false^true;
                    }
                    else{
                        temp = false^false;
                    }
                }
            }
            else // for & operator
            {
                if(operand1=='T')
                {
                    if(operand2 == 'T')
                    {
                        temp = true&true;
                    }
                    else{
                        temp = true&false;
                    }
                    
                }
                else
                {
                    if(operand2 == 'T')
                    {
                        temp = false&true;
                    }
                    else{
                        temp = false&false;
                    }
                }
                
            }
            
            
            if(temp==true) //convert temp back into T or F and push onto stack
            {
                operandStack.push('T');
            }
            else
            {
                operandStack.push('F');
            }
        }
    }
    if (operandStack.top()=='T') //when stack is one, convert to true or false
        {
            result = true;
        }
    else{
        result = false;
    }
    
    return 0;
   
}



