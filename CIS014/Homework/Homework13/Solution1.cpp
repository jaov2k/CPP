#include <iostream>
#include <vector>

using namespace std;

struct Block{
    int top = 0;
    int right = 0;
    int bottom = 0;
    int left = 0;
    int val = 0;
    bool isExterior = true;
};

int checkDepth(vector<vector<int>>& v){
    int smallestWall = 1000;

    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v[i].size(); j++){
            if ((i==1 && j==1) || v[i][j] == -1){ //skip if its the center or diagonals
                continue;
            }
            else if (v[i][j] <= v[1][1]){ //if a wall can't hold water and it spills
                return 0;
            }
            else{
                if (v[i][j] < smallestWall){ //is it the shortest wall
                    smallestWall = v[i][j];
                }
            }
        }
    }
    return smallestWall - v[1][1];
}

//Start Experimental
int checkDepthBlock(vector<vector<Block>>& b){
    int smallestWall = 1000;

    for (int i = 0; i < b.size(); i++){
        for (int j = 0; j < b[i].size(); j++){
            if (b[i][j].isExterior){ //skip if its an exterior wall
                continue;
            }
            else if (b[i][j].val <= b[i][j].top ||
                     b[i][j].val <= b[i][j].right ||
                     b[i][j].val <= b[i][j].bottom ||
                     b[i][j].val <= b[i][j].left) { //if a wall can't hold water and it spills
                return 0;
            }
            else{
                if (b[i][j].val < smallestWall){ //is it the shortest wall
                    smallestWall = b[i][j].val;
                }
            }
        }
    }
    return smallestWall - b[1][1].val;
}
//End Experimental

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

    //Start Experimental
    vector<vector<Block>> Blocks(3, vector<Block>(3));
    vector<Block> singleBlock;
    for (int i = 0; i < map.size(); i++){
        for (int j = 0; j < map[i].size(); j++){
            singleBlock.push_back({
                map.at(i-1).at(j),  // Top
                map.at(i).at(j+1),  // Right
                map.at(i+1).at(j),  // Bottom
                map.at(i).at(j-1),  // Left
                map.at(i).at(j)});    // Value 
            if (i == 0 || j == 0 || i == map.size()-1 || j == map[i].size()-1)
                singleBlock[j].isExterior = true;
            Blocks.push_back(singleBlock);
        }
    }
    return checkDepthBlock(Blocks);
    //End Experimental

    int temp = 0;
    vector<vector<int>> subNine(3, vector<int> (3, -1));
    for (int i = 1; i < map.size() - 1; i++){
        for (int j = 1; j < map[i].size()-1; j++){
            subNine.at(1).at(1) = map.at(i).at(j); // Center
            subNine.at(0).at(1) = map.at(i-1).at(j); // Top
            subNine.at(1).at(2) = map.at(i).at(j+1); // Right
            subNine.at(2).at(1) = map.at(i+1).at(j); // Bottom
            subNine.at(1).at(0) = map.at(i).at(j-1); // Left
            temp += checkDepth(subNine);
        }
    }
    return temp;
}

int main()
{
    vector<vector<int>> map = {{123}};
    cout << "outputs: " << getTotalWaterAmount(map) << endl; // outputs 0

    map = { {9,2},
            {2,1}};
    cout << "outputs: " << getTotalWaterAmount(map) << endl; // outputs 0

    map = { {1,1,1},
            {1,1,2},
            {1,2,2}};
    cout << "outputs: " << getTotalWaterAmount(map) << endl; // outputs 0

    map = { {6,2,4,123},
            {33,2,35,10},
            {12,3,0,23},
            {83,33,2,34}};
    cout << "outputs: " << getTotalWaterAmount(map) << endl; // outputs 2

    map = { {1,4,3,7,3,2},
            {3,2,1,1,3,4},
            {5,3,3,5,3,1}};
    cout << "outputs: " << getTotalWaterAmount(map) << endl; // outputs 5

    map = { {13,45,33,77,335,2,3},
            {32,25,123,1,3,41,3},
            {13,64,19,73,3,212,3},
            {52,3,35,35,389,13,3},
            {1,4,9,7,3,21,3}};
    cout << "outputs: " << getTotalWaterAmount(map) << endl; // outputs 140

    return 0;
}