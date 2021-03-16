// STARTER CODE
#include <iostream>
#include <string>
using namespace std;

/**
 * FUNCTION NAME: getLongestLength
 * PURPOSE: 
 * PARAMETER:
 *     string str
 * RETURN VALUE:
 * FUNCTION SINGATURE:
 *     int getLongestLength(string str)
 */ 
void getLongestLength(string str)
{
    for (char i : str)
    {
        cout << i << endl;     
    }
    cout << str << endl;
    //return 0;
}

int main()
{
    // your target function will be tested as such, 
    // with a random input 
    getLongestLength("abfdsafdsadfsaf");
    return 0;
}