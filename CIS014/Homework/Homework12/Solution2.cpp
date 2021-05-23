#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class CIS14
{
public:
    int getSignal(vector<int> &);
};
// ------------------------------------------------------------
// DO NOT MODIFY ABOVE THIS LINE. The above is your C++ class
// named CIS14 with its method and the Node class you will use.
// Note <climits> is included to accommodate INT_MAX and INT_MIN.
// ------------------------------------------------------------

/**
 * PURPOSE: To determine whether the product of a vector list of integers is positive, negative, or zero
 * PARAMETERS: vector<int> &ints
 * RETURN VALUE: int
 * FUNCTION SIGNATURE: int getSignal(vector<int> &ints)
*/
int CIS14::getSignal(vector<int> &ints)
{
    int negatives = 0;
    for (int i = 0; i < ints.size(); i++){
        if (ints[i] == 0)
            return 0;
        if (ints[i] < 0)
            negatives += 1;
    }

    return negatives % 2 ? -1 : 1; 
};

int main()
{
    // Instantiate an instance of the CIS14 class
    CIS14 cis14;

    // Your target method will be tested with random input such
    // as the following examples; the actual test cases will vary
    vector<int> v = {1, -1};
    cout << cis14.getSignal(v) << endl; // expects -1
    v = {1, 0, 1, 232, -23, 8, 109};
    cout << cis14.getSignal(v) << endl; // expects 0
    v = {-1,-2,-3,-4,3,2,1};
    cout << cis14.getSignal(v) << endl; // expects 1
    v = {0};
    cout << cis14.getSignal(v) << endl; // expects 0
    v = {-1,1,-1};
    cout << cis14.getSignal(v) << endl; // expects 1
    v = {INT_MAX,INT_MIN};
    cout << cis14.getSignal(v) << endl; // expects -1
    v = {INT_MAX,1,1,1,1,1,1,1,1,1,2};
    cout << cis14.getSignal(v) << endl; // expects 1
    // etc.

    return 0;
}