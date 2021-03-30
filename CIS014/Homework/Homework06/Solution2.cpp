#include <iostream>
#include <vector>
using namespace std;

/**
 * PURPOSE: To simulate --N by taking in a vector representation as the function parameter.
            The function returns the result of --N in its vector form
 * PARAMETERS: vector<int>
 * RETURN VALUES: vector<int>
 * FUNCTION SINGATURE: vector<int> minusMinusN(vector<int> digits)
 */
vector<int> minusMinusN(vector<int> digits) {
   for (int i = digits.size() - 1; i >= 0; i--) {
      if (digits[i] == 0)
         digits[i] = 9;
      else {
         --digits[i];
         if (digits[0] == 0 && digits.size() > 1) {
            digits[0] = 9;
            digits.pop_back();
         }
         break;
      }
   }
   return digits;
}

int main() {
   // your target function will be tested like so, with random input
   vector<int> v {1,0};
   vector <int> retVal = minusMinusN(v); // retVal = [9]
   // etc.
   return 0;
}