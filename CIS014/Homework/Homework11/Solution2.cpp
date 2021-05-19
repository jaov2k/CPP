#include <iostream>
using namespace std;

/**
 * PURPOSE: Calculates the max cross sectional area of the biggest pond based 
 *          on an array of arbitrary elevation profiles and the array size
 * PARAMETERS: int* arr, int n
 * RETURN VALUES: int
 * FUNCTION SIGNATURE: int getMaxPond(int* arr, int n)
 */
int getMaxPond(int* arr, int n) {
   // YOUR CODE HERE
}
int main() {
   // Your function will be tested with random input such as the following. 
   // Actual test cases will be different.
   int arr[] = {22,31,1,23};
   cout << getMaxPond(arr, sizeof(arr)/sizeof(arr[0])); // 66
   int arr1[] = {1};
   cout << getMaxPond(arr1, sizeof(arr1)/sizeof(arr1[0])); // 0
   int arr2[] = {1,3,5};
   cout << getMaxPond(arr2, sizeof(arr2)/sizeof(arr2[0])); // 3
   int arr3[] = {3,2,1};
   cout << getMaxPond(arr3, sizeof(arr3)/sizeof(arr3[0])); // 2
   int arr4[] = {1,1,1,1,1,1,1,1,1};
   cout << getMaxPond(arr4, sizeof(arr4)/sizeof(arr4[0])); // 8
   int arr5[] = {1,99,1};
   cout << getMaxPond(arr5, sizeof(arr5)/sizeof(arr5[0])); // 2
   
   return 0;
}