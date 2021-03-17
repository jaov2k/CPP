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
   string temp;
   int j = 0, len = str.length();
   for (int i = 0; i < len-1; i++)
   {
      if (str[i] != str[i+1])
      {
         temp[j++] = str[i];
         cout << str[i] << " " << str[i+1] << " not suppsed to be equal" << endl;
      }
         
   }
   temp[j++] = str[len-1];
   for (int i = 0; i < j; i++)
      str[i] = temp[j];

   return str;
}

int main() {
   // your target function will be tested as such, 
   // with a random input
   string input;
   cin >> input;
   cout << deduplicate(input); // "A"
   return 0;
}