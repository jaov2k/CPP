/*
Jose Ortiz
3/16/2021
CIS014 - Spring 2021
Homework Assignment 4: Problem 1 
*/

// STARTER CODE
#include <iostream>
#include <string>
using namespace std;

/**
 * FUNCTION NAME: getLongestLength
 * PURPOSE: To determine the largest possible palindrome given
 *          a string of characters, a-z or A-Z.
 * PARAMETER:
 *     string str
 * RETURN VALUE:
 *     int
 * FUNCTION SINGATURE:
 *     int getLongestLength(string str)
 */ 
int getLongestLength(string str)
{
    const int LEN = 256;
    int tally[LEN] = {}, total = 0;
    bool isOdd = false;
    
    //Frequency histogram of the letters
    for (char i : str)
        tally[i]++;
    
    //Totaling max size of the palindrome
    for (int i = 0; i < LEN; i++)
    {
        //if its even
        if ((tally[i] % 2) == 0)
            total += tally[i];
        //if its odd
        else if ((tally[i] % 2 ) == 1)
        {
            tally[i--]--;
            isOdd = true;
        }        
    }    
    return isOdd ? ++total : total;
}

int main()
{
    // your target function will be tested as such,
    // with a random input
    cout << getLongestLength("a");
    return 0;
}