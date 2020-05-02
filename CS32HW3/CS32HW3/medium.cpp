//
//  medium.cpp
//  CS32HW3
//
//  Created by Caden McQuillen on 5/3/19.
//  Copyright © 2019 Caden McQuillen. All rights reserved.
//

class Medium
{
public:
    Medium(string id); //takes in id parameter
    virtual ~Medium();
    virtual string connect() const = 0;
    string id() const;
    virtual string transmit(string msg) const =0;
private:
    string m_id;
};

Medium:: Medium(string id)
{
    m_id = id;
}


Medium:: ~Medium()
{
    
}

 string Medium:: id() const
{
    return m_id;
}



class TwitterAccount: public Medium
{
public:
    TwitterAccount(string id);
    virtual ~TwitterAccount();
    virtual string connect() const;
    virtual string transmit(string msg) const;
    
    
};

TwitterAccount:: TwitterAccount(string id):Medium(id)
{
    
}

TwitterAccount:: ~TwitterAccount()
{
    cout<<"Destroying the Twitter account "<< id()<<"."<<endl;
}

string TwitterAccount:: connect() const
{
    return "Tweet";
}

string TwitterAccount:: transmit(string msg) const
{
    
    return "text: "+msg;
}



class EmailAccount: public Medium
{
public:
    EmailAccount(string id);
    virtual ~EmailAccount();
    virtual string connect() const;
    virtual string transmit(string msg) const;
};

EmailAccount::EmailAccount(string id):Medium(id)
{
    
}

EmailAccount::~EmailAccount()
{
    cout<<"Destroying the email account "<<id()<<"."<<endl;
}

string EmailAccount:: connect() const
{
    return "Email";
}

string EmailAccount:: transmit(string msg) const
{
    return "text: "+ msg;
}

class Phone: public Medium
{
public:
    Phone(string id, CallType TextOrCall);
    virtual ~Phone();
    virtual string connect() const;
    virtual string transmit(string msg) const;
private:
    CallType m_CallType;
    
};

Phone::Phone(string id, CallType TextOrCall):Medium(id)
{
    m_CallType = TextOrCall;
}

Phone:: ~Phone()
{
    cout<<"Destroying the phone "<<id()<<"."<<endl;
}

string Phone:: connect() const
{
    return "Call";
}

string Phone:: transmit(string msg) const
{
    if (m_CallType== TEXT)
    {
        return "text: "+msg;
    }
    else{
        return "voice: "+msg;
    }
}



