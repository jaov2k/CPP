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
int getLongestLength(string str)
{
    const int size = 256;    
    int tally[size] = {0};
    int total = 0;

    for (char i : str)
        tally[i]++;
    
    char c;
    for (int i = 0; i < size; i++)
    {
        if (tally[i] >= 1)
        { 
            c = i;
            cout << "[" << i << "]:\t" << c << ":\t" << tally[i] << endl;
        }
    }
    cout <<"String length is: " << str.length() << "\n\n" << endl;
    return 0;
}

int main()
{
    // your target function will be tested as such, 
    // with a random input
    cout << getLongestLength("aaaaAAAAbbbbbBBBccccccCCCdddddddDDDDeeeeeeeeEEEZx");
    return 0;
}