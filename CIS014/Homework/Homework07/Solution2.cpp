#include <iostream>
#include <vector>
using namespace std;

/**
 * PURPOSE: Suggests the maximum profit an investor can make by placing AS MANY 
 *          buy-sell orders in the given time slice the input vector represents.
 * PARAMETERS: vector<int>
 * RETURN VALUES: int
 * FUNCTION SIGNATURE: int getMaxProfit(vector<int> &prices)
 */
int getMaxProfit(vector<int> &prices) {
   int total = 0;

   //First check if there is enough prices to perform a transaction.
   if (prices.size() == 1)
      return 0;
   
   //Total all the profits; Sell price is on the left, Buy price on the right.
   for (int i = 0; i < prices.size() - 1; i++){
      if(prices[i] < prices[i + 1])
         total += prices[i + 1] - prices[i];
   }
   return total;
}
int main() {
   // your target function will be tested as such, with random input like so
   vector<int> arr{1, 2, 4};
   cout << getMaxProfit(arr) << endl; // 3
   arr = {4,2,1};
   cout << getMaxProfit(arr) << endl; // 0
   arr = {1};
   cout << getMaxProfit(arr) << endl; // 0
   arr = {1,2,5,1,6};
   cout << getMaxProfit(arr) << endl; // 9
   arr = {3,1,5,2,4};
   cout << getMaxProfit(arr) << endl; // 6
   return 0;
}