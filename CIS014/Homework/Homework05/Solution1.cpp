#include <iostream>
#include <vector>

using namespace std;

/**
 * PURPOSE: To test whether the number of avocados desired 
 *          can be planted in the given field configuration
 * PARAMETERS: vector, int
 * RETURN VALUES: bool
 * FUNCTION SINGATURE: bool canPlantAvocados(vector<int> field, int n)
 */
bool canPlantAvocados(vector<int> field, int n)
{
   bool isGoodField = false;
   int goodSpaces = 0;
   
   // Count total available good spaces: [0, 0, 0]
   for (int i = 1; i < n; i++)
   {
      if (field[i-1] == 0 && field[i] == 0 && field[i+1] == 0)
      {
         goodSpaces++;
         n--;
      }
   }
   if (goodSpaces <= n)
      isGoodField = true;
   
   return isGoodField;
}

int main() {
   // your target function will be tested as such, 
   // with random input
   vector<int> field = {1, 0, 0, 0, 0, 1, 0, 0, 1};
   cout << canPlantAvocados(field, 1); // returns 0
   return 0;
}