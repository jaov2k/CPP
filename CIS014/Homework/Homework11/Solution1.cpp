#include <iostream>
using namespace std;

/**
 * PURPOSE: Calculates the amount of water retention there is in a given topographic terrain after it rains
 * PARAMETERS: int*, int
 * RETURN VALUES: int
 * FUNCTION SIGNATURE: int getTotalWaterAmount(int* arr, int size)
 */
int getTotalWaterAmount(int* arr, int size) {
   int maxElevation = arr[0];
   for (int i = 0; i < size; i++) {
      if (maxElevation < arr[i]) {
         maxElevation = arr[i];
      }
   }

   cout << maxElevation << endl;
   return 999999999;
}

int main() {
   // Your function will be tested with random input such as the following. 
   // Actual test cases will be different.
   int arr[] = {10, 20, 30 , 40, 42, 40, 30, 20, 40, 50, 55, 50, 40, 30, 20, 10, 3};
   cout << getTotalWaterAmount(arr, sizeof(arr)/sizeof(arr[0]))<<endl; // 38
   int arr1[] = {5,2,1,2,1,5};
   cout << getTotalWaterAmount(arr1, sizeof(arr1)/sizeof(arr1[0]))<<endl; // 14
   int arr2[] = {0,1,0};
   cout << getTotalWaterAmount(arr2, sizeof(arr2)/sizeof(arr2[0]))<<endl; // 0
   int arr3[] = {1,2,3,4,5,6,5,4,3,6,22,3,2};
   cout << getTotalWaterAmount(arr3, sizeof(arr3)/sizeof(arr3[0]))<<endl; // 6
   int arr4[] = {0,1,2,5,4,2,6,4,3,2,1,1,1,1,1,1,8};
   cout << getTotalWaterAmount(arr4, sizeof(arr4)/sizeof(arr4[0]))<<endl; // 43
   int arr5[] = {5,4,1,2};
   cout << getTotalWaterAmount(arr5, sizeof(arr5)/sizeof(arr5[0]))<<endl; // 1
   int arr6[] = {5,2,1,3,1,5};
   cout << getTotalWaterAmount(arr6, sizeof(arr6)/sizeof(arr6[0]))<<endl; // 13
   
   return 0;
}