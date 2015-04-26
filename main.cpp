//
//  main.cpp
//  Ex.04-LopezDP
//
//  Created by David P. Lopez on 4/18/15.
//  Copyright (c) 2015 David P. Lopez. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <iomanip>
#include "DynStrStk.h"

using namespace std;

void processFile();
void parseFile(ifstream&, fstream&);
void createStack(fstream&, ostream&);
void palinTest(string*, int);

int main()
{
    //call function to open file and process
    cout << "processing file..." << endl;
    processFile();

    return 0;
}

void processFile()
{
    ifstream inFile;
    fstream normFile;
    ofstream outFile;
    
    cout << "opening files..." << endl;
    // open files
    inFile.open("inFile.txt");
    normFile.open("normFile.txt");
    outFile.open("outFile.txt");
    
    cout << "parsing file..." << endl;
    //parse file for capitalization & punctuation
    parseFile(inFile, normFile);
    
    cout << "..." << endl;
    normFile.seekg(0, ios::beg); //need to "rewind" normFile so it can be read correctly before calling createStack()
    
    //create stack with parsed and normalized normFile and
    //test for palindromes and display to terminal
    createStack(normFile, outFile);
    
    //close files
    outFile.close();
    normFile.close();
    inFile.close();
}

void parseFile(ifstream &inFile, fstream &normFile)
{
    //create and initialize variables
    string newString;;
    int i;
    
    if(!inFile)
    {
        cout << "ERROR!!! Cannot read file.";
    }
    else
    {
        do
        {
            //read each line in the input file until EOF
            getline(inFile, newString);
            
            i = 0;
            
            //parse each string for punctuation
            while(newString[i])
            {
                if(isalpha(newString[i])) //check each char in each string for punctuation
                {
                    if(isupper(newString[i])) //check each string for capitalization
                    {
                        newString[i] = tolower(newString[i]); //convert string to lower case
                    }
                    normFile << newString[i]; //output each line to a file
                }
                i++;
            }
            normFile << '\n';
        } while(!inFile.eof());
    }
}

void createStack(fstream &normFile, ostream &outFile)
{
    string catchNewString;
    string *arr; //ptr to array of strings that will be checked for palindromes
    int count = 0; //counts the number of items in the stack
    
    DynStrStk stringStk; //instantiate a new dynamic stack using a linked list data structure
    
    while(getline(normFile,catchNewString)) // read and push to stack
    {
        stringStk.push(catchNewString); // push to stack
        //TRACER ROUNDS
        outFile << catchNewString << endl;
        count++;
        
    }
    
    //a pointer to an array of strings that contains
    //every string in the stack that will be checked
    //for palindromes by another function
    arr = stringStk.nodeStrings(count);
    
    /* TRACER ROUNDS
    for(int i = 0; i < count; i++)
    {
        cout << "test2: " << (arr[i]) << endl;
    }
    cout << "known count: " << count << endl;
    cout << "test count: " << stringStk.countStack() << endl;
     */
    
    //function that tests for palindromes and displays to terminal
    palinTest(arr, stringStk.countStack());
    
    //stringStk.~DynStrStk();
}

//function takes a pointer to an array of strings to test for
//palindromes and then displays to terminal
void palinTest(string *arr, int arrSize)
{
    string str;
    string revStr;
    int strLen = 0;
    
    cout << "String" << setw(43) << "isPalindrome" << endl;
    
    for(int i = 0; i < arrSize; i++)
    {
        strLen = arr[i].length();
        str = arr[i];
        revStr = string(str.rbegin(),str.rend());//reverse string library function to reverse string
        
        if(revStr == str)//test for palindrome
        {
            cout << str << setw(40-strLen) << "Y" << endl;
        }
        else
        {
            cout << str << setw(40-strLen) << "N" << endl;
        }
    }
}





