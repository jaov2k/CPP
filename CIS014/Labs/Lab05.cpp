#include <iostream>
#include <string.h>

using namespace std;

/**
 * PURPOSE: Determines whether a string is within another larger string.
 * PARAMETERS: const char*, const char*
 * RETURN VALUES: int
 * FUNCTION SINGATURE: int findx(const char* s, const char* x)
 */
int findx(const char* s, const char* x) {
    
}

int main() {
    // Your code will be tested with random input. For example:
    cout << (findx("mississippi","issip") == 4) << endl; // 1
    cout << (findx("pasadena","pas") == 0) << endl;      // 1
    // etc.
    return 0;
}