#include <iostream>
#include <vector>
using namespace std;

/**
 * PURPOSE: To calculate how much water retention there is 
 *          in a given topographic 3D terrain whenever it rains
 * PARAMETERS: vector<vector<int>>& map
 * RETURN VALUE: int
 * FUNCTION SIGNATURE: int getTotalWaterAmount(vector<vector<int>>& map)
*/
int getTotalWaterAmount(vector<vector<int>>& map)
{
    // Terrain needs to be at least 3x3 to hold water
    if (map.size() < 3 && map[0].size() < 3)
        return 0;
    

}

int main()
{
    vector<vector<int>> map = {{123}};
    cout << getTotalWaterAmount(map) << endl; // outputs 0

    map = { {9,2},
            {2,1}};
    cout << getTotalWaterAmount(map) << endl; // outputs 0

    map = { {1,1,1},
            {1,1,2},
            {1,2,2}};
    cout << getTotalWaterAmount(map) << endl; // outputs 0

    map = { {6,2,4,123},
            {33,2,35,10},
            {12,3,0,23},
            {83,33,2,34}};
    cout << getTotalWaterAmount(map) << endl; // outputs 2

    map = { {1,4,3,7,3,2},
            {3,2,1,1,3,4},
            {5,3,3,5,3,1}};
    cout << getTotalWaterAmount(map) << endl; // outputs 5

    map = { {13,45,33,77,335,2,3},
            {32,25,123,1,3,41,3},
            {13,64,19,73,3,212,3},
            {52,3,35,35,389,13,3},
            {1,4,9,7,3,21,3}};
    cout << getTotalWaterAmount(map) << endl; // outputs 140

    return 0;
}