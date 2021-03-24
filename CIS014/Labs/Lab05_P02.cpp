#include <iostream>

using namespace std;

int main()
{
    //3x3 matrix printing consecutive 1 to 9
    for (int i = 1; i < 10; i++) {
        cout << i << " ";
        if (!(i % 3))
            cout << endl;
    }

    cout << "\n";
    
    //3x3 matrix printing 2 to 18 consecutive even numbers only
    for (int i = 1; i <= 18; i++) {
        if (!(i % 2)) {
            cout << i << " ";
            if (!(i % 3))
                cout << endl;
        }        
    }
    return 0;
}