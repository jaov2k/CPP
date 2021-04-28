#include <iostream>
#include <vector>
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
    vector<vector<int>> inStock;
    vector<int> temp;
    temp.push_back((int)(*letterInventory)[0]);
    temp.push_back(0);
    inStock.push_back(temp);

    for (int i = 0; i < (*letterInventory).length(); i++){
        for(int j = 0; j < inStock.size(); j++){
            if (inStock.at(j).at(0) == (int)(*letterInventory)[i]){
                inStock.at(j).at(1)++;
                break;
            }
            else{
                temp.clear();
                temp.push_back((int)(*letterInventory)[i]);
                temp.push_back(1);
                inStock.push_back(temp);
                break;
            }                
        }
    }
    for(int i = 0; i < inStock.size(); i++)
        cout << inStock.at(i).at(0) << ", " << inStock.at(i).at(1) << endl;
        
    return 99999;
};

int main() {
    // Your code will be tested as follows, with different input values
    Solution solution;
    string inventory = "ABBCCCABBCCCABBCCC";
    string addresses[] = {"S1","CAD","G2"};
    cout << solution.getNumPossibleSigns(&inventory, addresses, 
        sizeof(addresses)/sizeof(addresses[0]));
}