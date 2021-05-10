#include <iostream>
#include <vector>

using namespace std;

class CIS14 {
public:
     vector<int> getMaxHits(vector<int> &requests, int window_size);
};

// ------------------------------------------------------------
// DO NOT MODIFY ABOVE THIS LINE. The above is your C++ class 
// named CIS14 with its method you will implement.
// ------------------------------------------------------------

/**
 * PURPOSE: Mechanism to throttle or limit the amount of requests a site handles
 * PARAMETERS: vector<int>, int
 * RETURN VALUES: vector<int>
 * FUNCTION SIGNATURE: vector<int> getMaxHits(vector<int> &requests, int window_size)
 */
vector<int> CIS14::getMaxHits(vector<int> &requests, int window_size) {
    vector<int> output = {};

    //When window length is greater than the vector size, return output as empty vector.
    if (window_size > requests.size())
        return output;

    //The rolling window length is 0. There is nothing to calculate.
    if (window_size == 0)
        return output;
    
    for (int i = 0; i <= requests.size() - window_size; i++){
        output.push_back(requests.at(i));
        for (int j = 0; j < window_size; j++){
            if (output.at(i) <= requests.at(i+j))
                output.at(i) = requests.at(i+j);
        }            
    }
    return output;
}

int main()
{
    // Instantiate an instance of the CIS14 class
    CIS14 cis14;    
    
    // Your target method will be tested with random input such
    // as the following example; the actual test cases will vary
    vector<int> v = {1,2,4};
    vector<int> ans = cis14.getMaxHits(v,1);
    for (int i=0; i<ans.size(); i++) cout << ans[i] << ((i==ans.size()-1) ? "" : ",");
    v.clear();
    cout << endl;

    v = {4, 4, 4, 3, 5, 2, 1};
    ans = cis14.getMaxHits(v,3);
    for (int i=0; i<ans.size(); i++) cout << ans[i] << ((i==ans.size()-1) ? "" : ",");
    v.clear();
    cout << endl;

    v = {1, 2, 9};
    ans = cis14.getMaxHits(v,0);
    for (int i=0; i<ans.size(); i++) cout << ans[i] << ((i==ans.size()-1) ? "" : ",");
    v.clear();
    cout << endl;

    v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ans = cis14.getMaxHits(v,3);
    for (int i=0; i<ans.size(); i++) cout << ans[i] << ((i==ans.size()-1) ? "" : ",");
    v.clear();
    cout << endl;

    v = {0,0,0};
    ans = cis14.getMaxHits(v,3);
    for (int i=0; i<ans.size(); i++) cout << ans[i] << ((i==ans.size()-1) ? "" : ",");
    v.clear();
    cout << endl;

    v = {0,0,0};
    ans = cis14.getMaxHits(v,10);
    for (int i=0; i<ans.size(); i++) cout << ans[i] << ((i==ans.size()-1) ? "" : ",");
    v.clear();
    cout << endl;
    
    return 0;
}