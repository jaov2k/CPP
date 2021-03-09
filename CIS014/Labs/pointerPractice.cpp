#include <iostream>

using namespace std;
const int MAX = 3;

int main()
{
    int x = 1234;
    int *ptrX = &x;
    cout << "The value of x is: " << x << endl;
    cout << "The address in ptrX is: " << ptrX << endl;
    cout << "The value *ptrX is pointing to is: " << *ptrX << endl;



    // C++ program to understand difference between  
    // pointer to an integer and pointer to an 
    // array of integers.

    // Pointer to an integer 
    int *p1;  
      
    // Pointer to an array of 5 integers 
    int (*ptrArr1)[5];  
    int arr1[5]; 
      
    // Points to 0th element of the arr. 
    p1 = arr1; 
      
    // Points to the whole array arr. 
    ptrArr1 = &arr1;  
      
    cout << "p =" << p1 <<", ptr = "<< ptrArr1 << endl; 
    p1++;  
    ptrArr1++; 
    cout << "p =" << p1 <<", ptr = "<< ptrArr1 << endl;



    // C++ program to illustrate sizes of 
    // pointer of array 

    int arr2[] = { 3, 5, 6, 7, 9 }; 
    int *p2 = arr2; 
    int (*ptr2)[5] = &arr2; 
      
    cout << "p = "<< p2 <<", ptr = " << ptr2 << endl; 
    cout << "*p = "<< *p2 <<", *ptr = " << *ptr2 << endl; 
      
    cout << "sizeof(p2) = "<< sizeof(p2) << 
            ", sizeof(*p2) = " << sizeof(*p2) << endl; 
    cout << "sizeof(ptr2) = "<< sizeof(ptr2) << 
        ", sizeof(*ptr2) = " << sizeof(*ptr2) << endl;
        

    return 0;
}