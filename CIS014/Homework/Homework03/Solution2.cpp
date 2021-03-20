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
    if (input.length() <= 50 && !input.empty())
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
    else if (input.length() > 50)
        return "String length exceeded. Max length is 50 characters.";
    else if (input.empty())
        return "String Empty. Please enter a string of characters. Max length is 50.";
}

int main() {
    // your target function will be tested like so, with
    // a random string input
    cout << separateLetters("abbbbbbbbaaaaaaa");
    return 0;
}