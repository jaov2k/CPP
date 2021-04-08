#include<iostream>
#include <string.h>

using namespace std;

/**
 * PURPOSE: Determines whether a string is within another larger string.
 * PARAMETERS: const char*, const char*
 * RETURN VALUES: int
 * FUNCTION SINGATURE: int findx(const char* s, const char* x)
 */
int findx(const char* s, const char* x) {
    for (int i = 0; i < strlen(s) - strlen(x); i++){
        for (int j = 0; j < strlen(x); j++){
            if (s[i+j] == x[j])                
                continue;
            else
                break;
        return i;        
        }
    }            
}

int main() {
    // Your code will be tested with random input. For example:
    cout << (findx("mississippi","issip") == 4) << endl; // 1
    cout << (findx("pasadena","pas") == 0) << endl;      // 1
    // etc.
    return 0;
}