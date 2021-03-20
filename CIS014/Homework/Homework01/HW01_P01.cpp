#include <iostream>
using namespace std;
/**
* PURPOSE: this console program breaks the total number of pennies into 
*          respective USD and CAN denominations, and print the string buffer 
*          containing the entire formatted output string to the console display
* PARAMETERS:
*     	None
* RETURN VALUES:
*     	None
*/
int main() {
   int numPennies = 0;
   
   cout << "Please enter all of your pennies: " << endl;
   cin >> numPennies;
   
   int dollars = numPennies / 100;
   int quarters = (numPennies % 100) / 25;
   int dimes = ((numPennies % 100) % 25) / 10;
   int nickles = (((numPennies % 100) % 25) % 10) / 5;
   int pennies = (((numPennies % 100) % 25) % 10) % 5;
   double exchangeRate = 1.33;

   cout.precision(2);
   cout << "In US currency you have: " << dollars << " dollars, " << quarters << " quarters, " 
        << dimes << " dimes, " << nickles << " nickles, and " << pennies <<" pennies." << endl;
   cout << "In Canadian currency you have: $"<< fixed << (numPennies * exchangeRate) / 100 << " dollars.";

   return 0;
}