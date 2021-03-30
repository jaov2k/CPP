#include <iostream>
using namespace std;

/**
 * PURPOSE: To simulate the effect of a circular array in that all of its elements 
 *          would shift to the RIGHT by M elements, where M is an integer >= 0
 * PARAMETERS: int[], int, int
 * RETURN VALUES: void
 * FUNCTION SINGATURE:void rightShiftElements(int arr[], int N, int M)
 */
void rightShiftElements(int arr[], int N, int M) { 
   if (M == 0 || M == N) //Final configuration is the same as the starting. No work needed.
      return;
   if (M > N) //This avoids the loops doing laps, and just assigns the actual right shift.
      M = M % N;

   for (int i = 0; i < M; i++) { //This counts the shifts
      int swap = arr[N-1];
      for (int j = N-1; j >= 0; j--) { // This moves the entire array to the right by one
         arr[j] = arr[j-1];
         if (j == 0)
            arr[0] = swap;
      }
   }
}

int main() {
   // your target function will be tested as such, with random input like so
   int arr[] = {1, 2, 3};
   int size = sizeof(arr)/sizeof(arr[0]);
   rightShiftElements(arr, size, 1); 
   return 0;
}