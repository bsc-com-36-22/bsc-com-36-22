#include <iostream>
using namespace std;

int main() {
    int a = 3;
    int b;

    // The value of 'a' is incremented first, then the incremented value is assigned to 'b'
    b = ++a;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    return 0;
}
