#include <iostream>
#include <string>
#include <sstream>

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

string breakCash(int numPennies) 
{
   int dollars = numPennies / 100;
   int quarters = (numPennies % 100) / 25;
   int dimes = ((numPennies % 100) % 25) / 10;
   int nickles = (((numPennies % 100) % 25) % 10) / 5;
   int pennies = (((numPennies % 100) % 25) % 10) % 5;
   double exchangeRate = 1.33;

   stringstream os;
   os.precision(2);
   os << "In US currency you have: " + 
      to_string(dollars) + " dollars, " +
      to_string(quarters) + " quarters, " +
      to_string(dimes) + " dimes, " +
      to_string(nickles) + " nickles, and " +
      to_string(pennies) + " pennies.\n" + "In Canadian currency you have: $"
      << fixed << (numPennies * exchangeRate / 100);
   os.str((os.str() + " dollars."));
   return os.str();
}

int main()
{
   int numOfPennies = 0;
   cout << "Please enter all of your pennies: " << endl;
   cin >> numOfPennies;
   cout << breakCash(numOfPennies) << endl;
   return 0;
} 