#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string listOfChars = "FDSAFDSA12345GFD654125";
    vector<vector<int>> myChars;
    vector<int> temp;
    temp.push_back(listOfChars[0]);
    temp.push_back(1);
    myChars.push_back(temp);
    temp.clear();
    temp.push_back(listOfChars[1]);
    temp.push_back(1);
    myChars.push_back(temp);
    temp.clear();
    temp.push_back(listOfChars[2]);
    temp.push_back(1);
    myChars.push_back(temp);
    temp.clear();
    temp.push_back(listOfChars[3]);
    temp.push_back(1);
    myChars.push_back(temp);
    for (int i = 0; i <myChars.size(); i++){
        cout << myChars[i][0] << ", " << myChars[i][1] << endl;
    }
    return 0;
}