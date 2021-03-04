#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

/* FUNCTION NAME: HasZeros
 * PURPOSE:
 *      To check if an integer has a 0 as one of its digits
 * PARAMETER:
 *      int
 * RETURN VALUE:
 *      bool
 * FUNCTION SINGATURE:
 *      bool HasZeros (int)*/
bool HasZeros (int);

/* FUNCTION NAME: getChampions
 * PURPOSE: 
 *      To collect all the champion numbers in a range
 * PARAMETER:
 *      int left, int right
 * RETURN VALUE:
 *      vector<int>
 * FUNCTION SINGATURE:
 *      vector<int> getChampions(int left, int right)*/
//vector<int> getChampions(int, int);

bool HasZeros (int n)
{
    string num = to_string(n);
    for (int i = 0; i < num.length(); i++)
    {
        if (num[i] == '0')
            return false;
    }
    return true;
}

// vector<int> getChampions(int left, int right)
// {
//     vector<int> champs; // for the return
//     int quotient = 0;
//     int remainder = 0;
//     string temp;
//     if (1 <= left && left <= right && right <= 100)
//     {
//         for (int i = 0; i <= (right - left); i++)
//         {
//             //Check for 0 digit
//             HasZeros(left);

//             if (left % 10)
//             quotient = left / 10;
//             remainder = left % 10;
//             if (left % remainder)

//         }
//         return champs;
//     }
//     else
//         cout << "Numbers are out of range. Exiting.";    
// }

int main()
{
    int x;
    cout <<"Enter x: ";
    cin >> x;
    if (INT_MIN < x && x < INT_MAX)
        HasZeros(x) ? cout << "no zeros found" : cout << "zeros detected";
    else
        cout << "Out of range. Exiting.";
    // your target function will be tested as such, 
    // with a random start and end value  
    // vector<int> a = getChampions(1, 22);
    
    // this is one example to print out your vector content
    // in the ascending order
    // for(int i=0; i < a.size(); i++)
    //     cout << a.at(i) << ' ';
    return 0;
}