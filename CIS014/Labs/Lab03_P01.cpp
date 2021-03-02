#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

/**
 * PURPOSE: checks to see whether an integer is a palindrome or not
 * PARAMETER:
 *     input, the integral input between the INT_MIN and INT_MAX range
 * RETURN VALUE:
 *     boolean indicating whether this input is an integer palindrome or not
*/

bool isPalindrome(int input)
{
    if (INT_MIN < input && input < INT_MAX)
    {
        string inputString = to_string(input);
        string inputStringRvrs = inputString;
        reverse(inputStringRvrs.begin(),inputStringRvrs.end());
        if (inputString == inputStringRvrs && 0 <= input)
            return true;
        else
            return false;
    }    
}

int main()
{
    // Hardcode input
    cout << (isPalindrome(-8465) ? "Output: true" : "Output: false");
}