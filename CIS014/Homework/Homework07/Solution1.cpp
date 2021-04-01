#include <iostream>
#include <vector>
using namespace std;

/**
 * PURPOSE:
 * PARAMETERS: vector<int>
 * RETURN VALUES: int
 * FUNCTION SIGNATURE: int getMaxProfit(vector<int> &prices)
 */
void getMaxProfit(vector<int> &prices) {
   int min = prices[0], max = prices[0];
   if (prices.size() == 1)
      cout << "Only one price available. Can not complete transation..." << endl;
   for (int i = 0; i < prices.size(); i++){
      if (min > prices[i])
         min = prices[i];
      if (max < prices[i])
         max = prices[i];

      cout << prices[i] << ", ";
   }   
   cout << "\nMin: " << min <<", Max: " <<max<< endl;
}
int main() {
   // your target function will be tested as such, with random input like so
   vector<int> arr{64, 8, 80, 42, 95, 11, 36, 98, 72, 84, 74, 3, 35, 90, 57, 
                   54, 86, 69, 76, 13, 79, 89, 21, 47, 41, 93, 77, 22, 45, 16};
   getMaxProfit(arr);
   //cout << getMaxProfit(arr); // 3
   return 0;
}