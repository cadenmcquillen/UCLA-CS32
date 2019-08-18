#include <iostream>
#include <fstream>
#include <string>
#include "hashtable.h"
#include <stack>
#include <cmath>

using namespace std;


//void createDiff(istream& fold, istream& fnew, ostream& fdiff);
//bool applyDiff(istream& fold, istream& fdiff, ostream& fnew);

int numberHelper(string oldString)
{
    int tester = oldString.length();
    if(tester<200)
    {
        return 4;
    }
    else if(tester<1000)
    {
        return 8;
    }
    else if(tester<100000)
    {
        return 12;
    }
    else if(tester < 500000)
    {
        return 16;
    }
    else{
        return 20;
    }
}

bool getInt(istream& inf, int& n)
{
    char ch;
    if (!inf.get(ch)  ||  !isascii(ch)  ||  !isdigit(ch))
        return false;
    inf.unget();
    inf >> n;
    return true;
}

bool getCommand(istream& inf, char& cmd, int& length, int& offset)
{
    if (!inf.get(cmd))
    {
        cmd = 'x';  // signals end of file
        return true;
    }
    char ch;
    switch (cmd)
    {
        case 'A':
            return getInt(inf, length) && inf.get(ch) && ch == ':';
        case 'C':
            return getInt(inf, length) && inf.get(ch) && ch == ',' && getInt(inf, offset);
        case '\r':
        case '\n':
            return true;
    }
    return false;
}

void createDiff(istream& fold, istream& fnew, ostream& fdiff)
{
    string oldString, newString;
    string temp;
    while(getline(fold,temp))
    {
        oldString+=temp;
        oldString+="\n";
    }
    while(getline(fnew,temp))
    {
        newString+=temp;
        newString+="\n";
    }
    HashTable diffMap; // create hashtable
    int N = numberHelper(oldString); // N byte size sequence constant
    unsigned int addCounter =0; // counter for consective add instructions
    string addString = "";
    unsigned int offset = 0;
    string current;
    for(unsigned int i = 0; i<oldString.length(); i++)
    {
        if( (i!=0 && i%N==0) ||  i==oldString.length()-1) //insert into table or if last sequence is >N insert when reach end of oldString
        {
            
            diffMap.insert(offset,current);
            offset ++;
            current = ""; //reset current back to empty
        }
        current+= oldString[i];
        
    }
    unsigned int j =0;
    while (j!=newString.length())
    {
        string newCurrent = newString.substr(j,N); //test sequence (16 bytes) from newf
        unsigned int k=0;
        while(k!=diffMap.size()) //check all the keys for mathcing sequence
        {
            string current = diffMap.getValue(k);
            if (newCurrent==current) //if theres a match, check if following bytes match
            {
                unsigned int Copycounter =0;
                unsigned int hashKeyIncrementor = k+1;
                int cycleIncrementor = 0;
                
                for(unsigned int i = (j+N); i<2*newString.length(); i++)
                {
                    if(newString[i]!=diffMap.getValue(hashKeyIncrementor)[cycleIncrementor])
                    {
                        Copycounter +=N; // add the 16 bytes for the
                        if(addString!="") // dont insert an add instruction if not nessasary
                        {
                            fdiff<<"A"<<addCounter<<":"<<addString; // put build up of add instructions into diff file
                        }
                        fdiff<<"C"<<Copycounter<<","<<k; //insert copy instruction
                        addCounter = 0; //reset add counter
                        addString = ""; //reset add string
                        break;
                    }
                    Copycounter++;
                    cycleIncrementor++;
                    if(Copycounter%N==0)
                    {
                        hashKeyIncrementor++;
                        cycleIncrementor =0;
                    }
                    
                }
                j+= Copycounter; //increment j so that next substring starts at j=j+counter
                break; //if you found a match and determined how long it is break from loop checking all the keys
            }
            k++;
            if(k==diffMap.size()) // if sequence isn't in table
            {
                addString+= newString[j];
                addCounter++;
                j++;
                if(j==newString.length()) // if its the last instruction before new string ends
                {
                    fdiff<<"A"<<addCounter<<":"<<addString;
                }
                break;
            }
        }
    }
}

// If it fails because the diff file is malformed (e.g., there's a character other than an A or C where an instruction is expected, or an offset or length is invalid), the function returns false. If the function returns false, the caller can make no assumption about what may or may not have been written to the output destination (so you're free to, for example, just return false as soon as you detect an error, without regard to what you may have already written).


bool applyDiff(istream& fold, istream& fdiff, ostream& fnew)
{
    int length,offset;
    char cmd = ' ';
    string oldString;
    string temp;
    while(getline(fold,temp))
    {
        oldString+=temp;
        oldString+="\n";
    }
    int N = numberHelper(oldString);
    
    while(cmd!='x')
    {
        if(getCommand(fdiff, cmd, length, offset)==false)
        {
            return false;
        }
        if(cmd=='A')
        {
            for(int i = 0; i<length; i++)
            {
                char c;
                fdiff.get(c);
                fnew<<c;
            }
        }
        else if( cmd =='C')
        {
            for(int i = offset*N; i<(offset*N)+length; i++)
            {
                fnew<<oldString[i];
            }
        }
        
        
    }
    return true;
    
}







