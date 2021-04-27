#include <iostream>
using namespace std;

/**
 * PURPOSE: 
 *    The function takes in a series of addresses in a 
 *    string array and compares each of them with the available 
 *    letterInventory, returning the number of addresses 
 *    that are POSSIBLE to form from the given letterInventory
 * PARAMETERS:
 *    string* letterInventory
 *    string* addresses
 *    int length: length of the array, addresses[]
 * RETURN VALUE:
 *    int: the number of possible addresses that can be 
 *         formed from your inventory of letters
 * FUNCTION SIGNATURE: 
 *    int getNumPossibleSigns(string*, string*, int);
*/ 
class Solution {
public:
    int getNumPossibleSigns(string*, string*, int);
};

int Solution::getNumPossibleSigns(
    string* letterInventory, 
    string* addresses, 
    int length) {
        


        cout << length << endl;
        return 145;
};

int main() {
    // Your code will be tested as follows, with different input values
    Solution solution;
    string inventory = "AAAADFADFA223432112";
    string addresses[] = {"S1","CAD","G2"};
    cout << solution.getNumPossibleSigns(&inventory, addresses, 
        sizeof(addresses)/sizeof(addresses[0]));
}