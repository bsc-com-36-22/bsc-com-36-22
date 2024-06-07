#include <iostream>
using namespace std;

int main() {
    int a = 25;
    int b = 100;

    cout << "a before swap: " << a << endl;
    cout << "b before swap: " << b << endl;

    // Swap the values of a and b
    int temp = a;
    a = b;
    b = temp;

    cout << "a after swap: " << a << endl;
    cout << "b after swap: " << b << endl;

    return 0;
}
