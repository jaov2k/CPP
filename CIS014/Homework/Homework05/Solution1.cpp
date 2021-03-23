/*
Jose Ortiz
3/22/2021
CIS014 - Spring 2021
Homework Assignment 5: Problem 1 
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * PURPOSE: Helper function to canPlantAvocados which tests
 *          if current index is the first.
 * PARAMETERS: vector, int
 * RETURN VALUES: bool
 * FUNCTION SINGATURE: bool isStart(vector<int> field, int i)
 */
bool isStart(vector<int> field, int i) {
   if (i == 0 && field[i] == 0 && field[i+1] == 0)
      return true;
   return false;
}

/**
 * PURPOSE: Helper function to canPlantAvocados which tests
 *          if current index is the last.
 * PARAMETERS: vector, int
 * RETURN VALUES: bool
 * FUNCTION SINGATURE: bool isEnd(vector<int> field, int i)
 */
bool isEnd(vector<int> field, int i) {
   if (i == field.size()-1 && field[i-1] == 0 && field[i] == 0)
      return true;
   return false;
}

/**
 * PURPOSE: Helper function to canPlantAvocados which tests indexes
 *          between, but not including, the first and last.
 * PARAMETERS: vector, int
 * RETURN VALUES: bool
 * FUNCTION SINGATURE: bool isMiddle(vector<int> field, int n)
 */
bool isMiddle(vector<int> field, int i) {
   if (field[i-1] == 0 && field[i] == 0 && field[i+1] == 0)
      return true;
   return false;
}

/**
 * PURPOSE: To test whether the number of avocados desired 
 *          can be planted in the given field configuration
 * PARAMETERS: vector, int
 * RETURN VALUES: bool
 * FUNCTION SINGATURE: bool canPlantAvocados(vector<int> field, int n)
 */
bool canPlantAvocados(vector<int> field, int n)
{
   //Initial check; there's always room for zero seeds.
   if (n == 0)
      return true;

   for (int i = 0; i < field.size(); i++)
   {  //If the space is available and doesn't touch others 
      if (isStart(field, i) || isEnd(field, i) || isMiddle(field, i))
      {
         n--; //plant the seed
         i++; //skip a planter for spacing
      }      
      if (n == 0)
         return true; //If all the seeds can be planted
   }
   return false; //If some seeds remain
}

int main() {
   // your target function will be tested as such, 
   // with random input
   vector<int> field = {0,0,1,0,0};
   cout << canPlantAvocados(field, 2); // returns 1
   return 0;
}