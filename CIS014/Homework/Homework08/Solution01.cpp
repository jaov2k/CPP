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
    vector<vector<int>> countChars(string);
};

int Solution::getNumPossibleSigns(string* letterInventory, string* addresses, int length) {
    int possibleSigns = 0;
    int charMatches = 0;
    int signTotalChars = 0;
    vector<vector<int>> letterTotals;
    vector<vector<int>> signTotals;
    letterTotals = countChars(*letterInventory);
    for (int i = 0; i < length; i++){
        signTotals = countChars(addresses[i]);
        charMatches = 0;
        signTotalChars = 0;
        for (int j = 0; j < letterTotals.size(); j++){
            for (int k = 0; k < signTotals.size(); k++){
                if (signTotals.at(k).at(0) == letterTotals.at(j).at(0) && signTotals.at(k).at(1) <= letterTotals.at(j).at(1)){
                    charMatches += signTotals.at(k).at(1);                  
                }                    
            }                   
        }
        for (int x = 0; x < signTotals.size(); x++){
            if ((char)signTotals.at(x).at(0) != ' ')
                signTotalChars += signTotals.at(x).at(1);
        }
        if (charMatches == signTotalChars)
            possibleSigns++;
    }
    return possibleSigns;
};

vector<vector<int>> Solution::countChars (string str){
    vector<vector<int>> tally;
    vector<int> temp;
    for (int i = 0; i < str.length(); i++){
        bool foundIt = false;
        for(int j = 0; j <= tally.size(); j++){
            if (j == tally.size() && !foundIt){
                temp.clear();
                temp.push_back((int)str[i]);
                temp.push_back(1);
                tally.push_back(temp);
                break;
            }
            else if (j != tally.size() && tally.at(j).at(0) == (int)str[i]) {
                tally.at(j).at(1)++;
                foundIt = true;
            }
        }
    }
    return tally;
};

int main() {
    // Your code will be tested as follows, with different input values
    Solution solution;
    string inventory = "AAAADFADFA223432112";
    string addresses[] = {"S1","CAD","G2"};
    cout << solution.getNumPossibleSigns(&inventory, addresses, 
        sizeof(addresses)/sizeof(addresses[0]))<<endl; // 0
    string inventory0 = "AAAABCCC123456789";
    string addresses0[] = {"123C" , "123A" , "123 ADA"};
    cout << solution.getNumPossibleSigns(&inventory0, addresses0, 
        sizeof(addresses0)/sizeof(addresses0[0]))<<endl; // 2
    string inventory1 = "ABCDEFGHIJKLMNORSTUVWXYZ1234567890";
    string addresses1[] = {"2 FIRST ST" , " 13 PUN ST" , "101 AKER"};
    cout << solution.getNumPossibleSigns(&inventory1, addresses1, 
        sizeof(addresses1)/sizeof(addresses1[0]))<<endl; // 0
    string inventory2 = "ABCDAAST";
    string addresses2[] = {"A BAD ST"};
    cout << solution.getNumPossibleSigns(&inventory2, addresses2, 
        sizeof(addresses2)/sizeof(addresses2[0]))<<endl; // 1
}