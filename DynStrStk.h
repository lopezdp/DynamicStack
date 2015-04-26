//
//  DynStrStk.h
//  Ex.04-LopezDP
//
//  Created by David P. Lopez on 4/25/15.
//  Copyright (c) 2015 David P. Lopez. All rights reserved.
//

#ifndef DynStrStk_h
#define DynStrStk_h

#include <iostream>
#include <string>

using namespace std;

class DynStrStk
{
private:
    //struct stack nodes
    struct StackNode
    {
        string newString; //string held in the node
        StackNode *next; //pointer to the next node
    };
    
    StackNode *top; //pointer to the top of the stack
    
public:
    //Constructor
    DynStrStk()
    {top = nullptr;}
    
    //Destructor
    ~DynStrStk();
    
    //Stack Operations
    void push(string);
    void pop(string &);
    bool isEmpty();
    
    //utility
    string *nodeStrings(int);
    int countStack();

};

#endif
