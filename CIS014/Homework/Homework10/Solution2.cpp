#include <iostream>
#include <vector>

using namespace std;

class CIS14 {
public:
   int getLegoCombinations(vector<int> &lego_heights, int target_height);
};

// ------------------------------------------------------------
// DO NOT MODIFY ABOVE THIS LINE. The above is your C++ class 
// named CIS14 with its method you will implement.
// ------------------------------------------------------------

/**
 * PURPOSE: Output the number of possible ways to build a wall of legos, 
 * PARAMETERS: vector<int>, int
 * RETURN VALUES: int
 * FUNCTION SIGNATURE: int getLegoCombinations(vector<int> &lego_heights, int target_height)
 */
int CIS14::getLegoCombinations(vector<int> &lego_heights, int target_height) {
    //Cannot built with a 0 target height
    if (target_height == 0)
        return 0;
    
    //Declare and initialize vectors for counting
    vector<int> temp(target_height + 1);
    vector<vector<int>> output(lego_heights.size() + 1, temp);
    for(int i = 0; i <= lego_heights.size(); i++)
        output.at(i).at(0) = 1;
    for(int i = 1; i <= target_height; i++)
        output.at(0).at(i) = 0;

    //Total possibilities
	for (int i = 1; i <= lego_heights.size(); i++){
		for (int j = 0; j <= target_height; j++){
			if (lego_heights.at(i-1) <= j)
				output.at(i).at(j) = output.at(i-1).at(j) + output.at(i).at(j-lego_heights[i-1]);
            else
                output.at(i).at(j) = output.at(i-1).at(j);
        }
    }

	return output.at(lego_heights.size()).at(target_height);
}

int main()
{
    // Instantiate an instance of the CIS14 class
    CIS14 cis14;    
    
    // Your target method will be tested with random input such
    // as the following example; the actual test cases will vary
    vector<int> v = {1,2,5};
    cout << cis14.getLegoCombinations(v,3) << endl; // 2 (see example)

    v = {1,2,5};
    cout << cis14.getLegoCombinations(v,0) << endl; // 0

    v = {1,2,5};
    cout << cis14.getLegoCombinations(v,7) << endl; // 6

    v = {5};
    cout << cis14.getLegoCombinations(v,9) << endl; // 0
        
    return 0;
}