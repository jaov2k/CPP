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
   int output = 0, temp = 0;
   
   //First check if there is enough prices to perform a transaction.
   if (prices.size() == 1)
      return 0;
   
   //Search for the largest profit; Sell price is on the left, Buy price on the right.
   for (int i = prices.size() - 1; i >=0; i--){
      for (int j = i; j >=0; j--){
         temp = prices[i] - prices[j];
         if (temp > output)
            output = temp; // Keep track of largest difference thus far.
      }
   }
   return output; //Largest profit.
}
int main() {
   // your target function will be tested as such, with random input like so
   vector<int> arr{1, 2, 4};
   cout << getMaxProfit(arr); // 3
   return 0;
}