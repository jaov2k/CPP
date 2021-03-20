/*
Jose Ortiz
3/16/2021
CIS014 - Spring 2021
Homework Assignment 4: Problem 2
*/

// STARTER CODE
#include <iostream>
#include <string>
using namespace std;

/**
 * FUNCTION NAME: deduplicate
 * PURPOSE: This function will internally run as many iterations as needed to 
 *          remove all consecutive duplicates until there is either no consecutive 
 *          duplicates left, or the string becomes empty (in which the function
 *          returns an empty string back to the user)
 * PARAMETER:
 *          string str
 * RETURN VALUE:
 *          string
 * FUNCTION SINGATURE:
 *          string deduplicate(string str)
 */ 
string deduplicate(string str) 
{
   int i = 0;
   while (i < str.length())
   {
        if (str[i] == str[i + 1])
        {
            str.erase(i,2);     
            i = 0;
        }
        else
            i++;
   }
   return str;
}

int main() {
  cout << deduplicate("AABB"); // should return empty "" string
  cout << deduplicate("A"); // "A"
  cout << deduplicate("ABBA"); // should return an empty "" string
  cout << deduplicate("AAA"); // "A"
  cout << deduplicate("AKA"); // "AKA" because there is no consecutive pair.
  cout << deduplicate("KCCK"); // should return an empty "" string
  cout << deduplicate("ZZZ"); // "Z"
  cout << deduplicate("KKCCD"); // should return an empty "" string
  return 0;
}