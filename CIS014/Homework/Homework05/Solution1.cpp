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
   for (int i = 1; i < field.size(); i++)
   {
      if (field[i-1] == 0 && field[i] == 0 && field[i+1] == 0)
      {
         n--;
         i++;
      }        
      if (n == 0)
         return true;
   }
   return false;
}

int main() {
   // your target function will be tested as such, 
   // with random input
   vector<int> field = {1, 0, 1};
   cout << canPlantAvocados(field, 1); // returns 0
   return 0;
}