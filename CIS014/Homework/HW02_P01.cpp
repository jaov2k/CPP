#include <iostream>
#include <string>

using namespace std;

/**
 * FUNCTION NAME: breakCash
 * PURPOSE: the function takes in the total of pennies from the user as input, 
 *     computes its equivalent in dollars, quarters, dimes, nickels, and 
 *     pennies, and outputs the result in string to the console
 * PARAMETER:
 *     int numPennies
 * RETURN VALUE:
 *     string: result in dollars, quarters, dimes, nickels, and pennies
 * FUNCTION SINGATURE:
 *     string breakCash(int numPennies)
 */ 
string breakCash(int numPennies) {
   int dollars = 0;
   int quarters = 0;
   int dimes = 0;
   int nickles = 0;
   int pennies = 0;
   double exchangeRate = 1.33;

   dollars = numPennies / 100;
   quarters = (numPennies % 100) / 25;
   dimes = ((numPennies % 100) % 25) / 10;
   nickles = (((numPennies % 100) % 25) % 10) / 5;
   pennies = (((numPennies % 100) % 25) % 10) % 5;

   return "In US currency you have: " + 
          to_string(dollars) + " dollars, " +
          to_string(quarters) + " quarters, " +
          to_string(dimes) + " dimes, " +
          to_string(nickles) + " nickles, and " +
          to_string(pennies) + " pennies.\n" +
          "In Canadian currency you have: " + to_string((numPennies * exchangeRate) / 100) + " dollars.";
}

int main() {
   int numOfPennies = 0;
   cout << "Please enter all of your pennies: " << endl;
   cin >> numOfPennies;
   cout << breakCash(numOfPennies);
   return 0;
}