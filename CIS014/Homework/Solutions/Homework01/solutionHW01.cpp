/**
* PURPOSE: this console program breaks the total number of pennies into respective USD and 
*   CAN denominations, and print the string buffer containing the entire formatted output 
*   string to the console display.
* PARAMETERS:
*   None
* RETURN VALUES:
*   None
* FUNCTION: int main()
*/

#include <iostream>

using namespace std;

int main() {

	int numPennies = 0;
	cout << "Please enter all of your pennies: " << endl;
	cin >> numPennies;

	if (numPennies < 0) {
		cout << "Invalid input";
	} else {

		//Variables to store unit of each currency, up to dollars
		//The cents is a temp holder for the actual number of pennies
		//being passed into this breakCash function
		int dollars, quarters, dimes, nickels, cents;

		// American dollar to Canadian dollar exchange rate is 1:1.30 as of 9/12/16
		const double exchangeRate = 1.33;
		double canDollars = (numPennies / 100.00) * exchangeRate;

		// This is one way of doing your calculations. There are several other
		// ways you can also achieve the same answer
		dollars = numPennies / 100;
		numPennies = numPennies - dollars * 100;
		quarters = numPennies / 25;
		numPennies = numPennies - quarters * 25;
		dimes = numPennies / 10;
		numPennies = numPennies - dimes * 10;
		nickels = numPennies / 5;
		numPennies = numPennies - nickels * 5;
		cents = numPennies; //Pennies are what's left over.

		// Preallocate enough buffer to do sprintf(). Sprintf is a standard C++ library.
		// You may also use other C or C++ libraries to get this result string, such as
		// using itoa (converting integer to string), STLSoft's integer_to_string(), etc.
		// For sprintf() please see http://www.cplusplus.com/reference/cstdio/sprintf/
		char result[200];
		sprintf(result, "In US currency you have: %d dollars, %d quarters, %d dimes, %d nickels, and %d pennies.\nIn Canadian currency you have: %.2f dollars.", dollars, quarters, dimes, nickels, cents, canDollars);
		cout << result;
	}

	return 0;
}