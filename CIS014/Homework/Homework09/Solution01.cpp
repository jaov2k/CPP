#include <iostream>
#include <vector>

using namespace std;

class CIS14 {
public:
     int getMaxPoints(vector<vector<int>> &maze);
}; 

// ------------------------------------------------------------
// DO NOT MODIFY ABOVE THIS LINE. The above is your C++ class 
// named CIS14 with a method called getMaxPoints(...) you will
// implement
// ------------------------------------------------------------

/**
 * PURPOSE: To determine the largest score possible
 * PARAMETERS: vector<vector<int>> &maze
 * RETURN VALUES: int
 * FUNCTION SIGNATURE: int CIS14::getMaxPoints(vector<vector<int>> &maze)
 */
int CIS14::getMaxPoints(vector<vector<int>> &maze) {
    // maze is completely empty
    if (maze.empty()) 
        return 0;

    for (int i = maze.size() - 2; i >= 0; i--){
        for (int j = 0; j < maze.at(i).size(); j++){
            if (maze.at(i+1).at(j) > maze.at(i+1).at(j+1))
                maze.at(i).at(j) += maze.at(i+1).at(j);
            else
                maze.at(i).at(j) += maze.at(i+1).at(j+1);
        }        
    }  
    return maze.at(0).at(0);
}

int main()
{
    // Instantiate an instance of the CIS14 class
    CIS14 cis14;    
    
    // Your target method will be tested as such, with random input
    // as the following example illustrates
    vector<vector<int>> maze = {{0}, {4,1}, {5,3,8}, {1,6,7,3}}; // output = 16
    cout << cis14.getMaxPoints(maze) << endl;
    maze = {{2}, {4,1}, {5,3,8}, {1,6,7,3}}; // output = 18
    cout << cis14.getMaxPoints(maze) << endl;
    maze = {{1}, {1,1}, {1,1,1}, {1,1,1,1}}; // output = 4
    cout << cis14.getMaxPoints(maze) << endl;
    maze = {{3}, {7,4}, {2,4,6}, {8,5,9,3}}; // output = 23
    cout << cis14.getMaxPoints(maze) << endl;
    maze = {{1}, {1,22305}, {1,29394,1}, {1,1,1234,1}, {1,1,3,1,10}}; // output = 52937
    cout << cis14.getMaxPoints(maze) << endl; 
    
    return 0;
}