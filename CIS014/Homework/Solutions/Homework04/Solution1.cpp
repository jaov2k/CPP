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
    const int size = 256;    
    int tally[size] = {0};
    int total = 0;
    bool singles = false;
    
    //Frequency histogram of the letters
    for (char i : str)
        tally[i]++;
    
    //Totaling max size of the palindrome
    for (int i = 0; i < size; i++)
    {
        if (tally[i] > 1)
        {
            //if its even
            if ((tally[i] % 2) == 0)
                total += tally[i];
            //if its odd
            else if ((tally[i] % 2 ) != 0)
                total = --tally[i];
        }
        //if there's single instances
        else if (tally[i] == 1)
            singles = true;
    }
    return singles ? ++total : total;
}

int main()
{
    // your target function will be tested as such,
    // with a random input
    cout << getLongestLength("a");
    return 0;
}