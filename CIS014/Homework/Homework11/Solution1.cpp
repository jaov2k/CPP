#include <iostream>
using namespace std;

/**
 * PURPOSE: Calculates the amount of totalWater collected in a given topographic terrain after rain.
 * PARAMETERS: int*, int
 * RETURN VALUES: int
 * FUNCTION SIGNATURE: int getTotalWaterAmount(int* arr, int size)
 */
int getTotalWaterAmount(int* arr, int size) {
   int length = size - 1;
   int elev = arr[0];
   int elevIndex = 0;
   int totalWater = 0;
   int temp = 0;

   // For totaling all the water from left to right
   // remembering the tallest peak
   for(int i = 0; i <= length; i++)
   {
      if (arr[i] >= elev)
      {
         elev = arr[i];
         elevIndex = i;
         temp = 0;
      }
      else
      {
         totalWater += elev - arr[i];
         temp += elev - arr[i];
      }
   }

   // For removing all the excess water double counted previously
   // and totaling from right to left
   if(elevIndex < length)
   {
      totalWater -= temp;
      elev = arr[length];
      for(int i = length; i >= elevIndex; i--)
      {
         if(arr[i] >= elev)
               elev = arr[i];
         else
            totalWater += elev - arr[i];
      }
   }
   return totalWater;
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