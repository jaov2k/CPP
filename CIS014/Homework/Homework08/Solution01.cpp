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

int Solution::getNumPossibleSigns(string* letterInventory, string* addresses, int length) {
    int stock[36][1] = {0};
    stock[0][0] = (*letterInventory)[0];
    for (int i = 0; i < (*letterInventory).length(); i++){
        if ((*letterInventory)[i] == stock[i][0])
            stock[i][1]++;

    }
    for (int i = 0; i < length; i++) 
        cout << addresses[i] << (i < length - 1 ? ", " : "");
    cout << endl;
    return 999;
};

int main() {
    // Your code will be tested as follows, with different input values
    Solution solution;
    string inventory = "AAAADFADFA223432112";
    string addresses[] = {"S1","CAD","G2"};
    cout << solution.getNumPossibleSigns(&inventory, addresses, 
        sizeof(addresses)/sizeof(addresses[0]));
}