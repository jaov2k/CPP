#include <iostream>
#include <string>
using namespace std;

// YOUR API DOCUMENTATION HERE: FAILURE TO
// INCLUDE API WILL BE DOCKED A POINT
int compareVersions(string ver1, string ver2) {
   // YOUR CODE HERE
}
int main() {
   // your target function will be tested as such, with 
   // random input. To streamline your testing, you may
   // also test your own code this way:
   // cout << (compareVersions("0.1", "0.1") == 0); // 1, which is true
   cout << compareVersions("0.1", "0.1"); // 0
   cout << compareVersions("1.0", "1.1") << endl;
   cout << compareVersions("2.0", "2.0.1") << endl;
   return 0;
}