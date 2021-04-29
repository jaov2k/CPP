#include <iostream>
#include <unordered_set>
using namespace std;

/**
 * PURPOSE: Attempts to generate the input by combining any number of words in the dictionary
 * PARAMETERS:
*           string* s, unordered_set<string> &dict
 * RETURN VALUE:
 *          bool
 * FUNCTION SIGNATURE:
 *          bool isInputInDictionary(string* s, unordered_set<string> &dict);
*/ 
class Solution {
   public:
      bool isInputInDictionary(string* s, unordered_set<string> &dict);
};
bool Solution::isInputInDictionary(string* s, unordered_set<string> &dict) {
    // YOUR CODE HERE
    return false;
}
int main() {
  // Your solution will be tested as such, with different input values
  Solution solution;
  string input = "joe";
  unordered_set<string> dict = {"joe1","joe"};
  cout << solution.isInputInDictionary(&input, dict);
}