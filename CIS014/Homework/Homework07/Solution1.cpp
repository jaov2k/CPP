#include <iostream>
#include <vector>
using namespace std;

/**
 * PURPOSE: Recommends the maximum profit an investor can make by placing 
 *          at most one buy and one sell order in the time slice represented
 *          by the input vector.
 * PARAMETERS: vector<int>
 * RETURN VALUES: int
 * FUNCTION SIGNATURE: int getMaxProfit(vector<int> &prices)
 */
void getMaxProfit(vector<int> &prices) {
   int output = 0, temp = 0;
   if (prices.size() == 1)
      cout << "Not enough prices for a transaction...";
   for (int i = 0; i < prices.size(); i++)
      cout << prices[i] << ", ";
   cout << "\nthere are " << prices.size() << " prices." << endl;
   for (int i = prices.size() - 1; i >=0; i--){
      for (int j = i; j >=0; j--){
         temp = prices[i] - prices[j];
         if (temp > output)
            output = temp;
         cout << "temp is: " << prices[i] << " - " << prices[j] << " = " <<temp << "\tOutput is: " << output << endl;
      }
   }

   cout << "output: " << output << endl;
}
int main() {
   // your target function will be tested as such, with random input like so
   vector<int> arr{1,2,4};
   getMaxProfit(arr);
   //cout << getMaxProfit(arr); // 3
   return 0;
}