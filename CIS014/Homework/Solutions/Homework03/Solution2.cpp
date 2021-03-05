#include <iostream>
using namespace std;

/* FUNCTION NAME: separateLetters
 * PURPOSE:
 *      To separate all of the 'a' and 'b' in the string so that all 'a' appear before 'b'
 * PARAMETER:
 *      string
 * RETURN VALUE:
 *      string
 * FUNCTION SINGATURE:
 *      string separateLetters(string input)
 */
 
string separateLetters(string input)
{
    string aStr = "";
    string bStr = "";
    for (char c : input)
        if (c == 'a')
            aStr = aStr + c;
        else
            bStr = bStr + c;
    return aStr + bStr;
}

int main() {
    // your target function will be tested like so, with
    // a random string input
    cout << separateLetters("abababa");
    return 0;
}