#include <iostream>

using namespace std;

int main()
{
    cout <<"The size of an int is: " << sizeof(int) << " bytes" << endl;
    cout <<"The size of a float is: " << sizeof(float) << " bytes" << endl;
    cout <<"The size of a double is: " << sizeof(double) << " bytes" << endl;
    cout <<"The size of a char is: " << sizeof(char) << " byte" << endl;
    cout <<"The size of a string is: " << sizeof(string) << " bytes" << endl;
    cout <<"The size of a void is: " << "sizeof(void) does not compile." << endl;
    cout <<"The size of a bool is: " << sizeof(bool) << " byte" <<  endl;
    return 0;
}