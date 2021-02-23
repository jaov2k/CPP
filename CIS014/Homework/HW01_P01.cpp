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
   int dollars = 0;
   int quarters = 0;
   int dimes = 0;
   int nickles = 0;
   int pennies = 0;
   double exchangeRate = 1.33;

   cout << "Please enter all of your pennies: " << endl;
   cin >> numPennies;
   dollars = numPennies / 100;
   quarters = (numPennies % 100) / 25;
   dimes = ((numPennies % 100) % 25) / 10;
   nickles = (((numPennies % 100) % 25) % 10) / 5;
   pennies = (((numPennies % 100) % 25) % 10) % 5;

   cout << "In US currency you have: " << dollars << " dollars, " << quarters << " quarters, " 
        << dimes << " dimes, " << nickles << " nickles, and " << pennies <<" pennies." << endl;
   cout << "In Canadian currency you have: "<< (numPennies * exchangeRate) / 100 << " dollars.";
   return 0;
}