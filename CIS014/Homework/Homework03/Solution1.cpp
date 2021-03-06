#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* FUNCTION NAME: hasNoZeros
 * PURPOSE:
 *      To check if an integer has a 0 as one of its digits
 * PARAMETER:
 *      int
 * RETURN VALUE:
 *      bool
 * FUNCTION SINGATURE:
 *      bool hasZeros (int)*/
bool hasNoZeros (int);

/* FUNCTION NAME: getChampions
 * PURPOSE: 
 *      To collect all the champion numbers in a range
 * PARAMETER:
 *      int left, int right
 * RETURN VALUE:
 *      vector<int>
 * FUNCTION SINGATURE:
 *      vector<int> getChampions(int left, int right)*/
vector<int> getChampions(int, int);

bool hasNoZeros (int n) {
    string num = to_string(n);
    for (int i = 0; i < num.length(); i++) {
        if (num[i] == '0')
            return false;
    }
    return true;
}

vector<int> getChampions(int left, int right) {
    vector<int> champs; // for the return
    bool isChamp = false;
    int temp = 0;
    if (1 <= left && left <= right && right <= 100) {
        while (left <= right) {
            if (hasNoZeros(left)) {
                temp = left;
                do
                {
                    if ((left % (temp % 10)) == 0) {
                        isChamp = true;
                        temp = temp / 10;
                    }                        
                    else {                        
                        isChamp = false;
                        break;
                    }
                } while (temp >= 1);
                if (isChamp)
                    champs.push_back(left);
            }
            left++;
        }
        return champs;
    }
    else
        cout << "Numbers are out of range. Exiting.";    
}

int main()
{
    // your target function will be tested as such, 
    // with a random start and end value  
    vector<int> a = getChampions(1, 22);
    
    // this is one example to print out your vector content
    // in the ascending order
    for(int i=0; i < a.size(); i++)
        cout << a.at(i) << ' ';
    return 0;
}