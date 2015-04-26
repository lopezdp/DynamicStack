/*
  DynStrStk.cpp
  Ex.04-LopezDP

  Created by David P. Lopez on 4/25/15.
  Copyright (c) 2015 David P. Lopez. All rights reserved.
*/

#include <iostream>
#include "DynStrStk.h"

//function to delete every node in the list
DynStrStk::~DynStrStk()
{
    StackNode *nodePtr = nullptr;
    StackNode *nextNode = nullptr;
    
    //Position nodePtr at the top of the stack
    nodePtr = top;
    
    //Traverse the list and delete each node
    while(nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

//function that pushes the argument onto the list
void DynStrStk::push(string newString)
{
    StackNode *newNode = nullptr; //Pointer to a node
    
    //Allocate a new node and store string
    newNode = new StackNode;
    newNode->newString = newString;
    
    //if there are no nodes in the list make newNode the first node
    if(isEmpty())
    {
        top = newNode;
        newNode->next = nullptr;
    }
    else //otherwise insert NewNode before top
    {
        newNode->next = top;
        top = newNode;
    }
}

/*
function that pops the string at the top of the stack off, and copies it into the variable
passed as an argument
*/

void DynStrStk::pop(string &newString)
{
    StackNode *temp = nullptr; //temporary pointer to node type StackNode
    
    //first make sure stack not empty
    if(isEmpty())
    {
        cout << "The Stack is Empty" << endl;
    }
    else //pop string off of the top of the stack
    {
        newString = top->newString;
        temp = top->next;
        delete top;
        top = temp;
    }
}

/*
function returns true if the stack is empty or false otherwise
*/

bool DynStrStk::isEmpty()
{
    bool status;
    
    if(!top)
        status = true;
    else
        status = false;
    
    return status;
}

//function to traverse every node in the dynamically allocated stack
//implemented with a linked list to assign the data from each node
//to an array. function returns a pointer to the array of strings
//array of strings will be checked for palindromes
string *DynStrStk::nodeStrings(int count)
{
    StackNode *nodePtr = nullptr;
    StackNode *nextNode = nullptr;
    int i = 0;
    
    //Position nodePtr at the top of the stack
    nodePtr = top;
    
    string *arr = new string[count];
    
    //Traverse the list and delete each node
    while(nodePtr != nullptr && i < count)
    {
        nextNode = nodePtr->next;
        arr[i] = nodePtr->newString;
        nodePtr = nextNode;
        i++;
    }
    return arr;
}

//function to count the size of the stack
int DynStrStk::countStack()
{
    int count = 0;
    StackNode *nodePtr = nullptr;
    StackNode *nextNode = nullptr;
    
    //Position nodePtr at the top of the stack
    nodePtr = top;
    
    //Traverse the list and delete each node
    while(nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        count++;
        nodePtr = nextNode;
    }
    
    return count;
}







