#include <iostream>
using namespace std;

int main() {
    int a = 3;
    int b;

    // The value of 'a' is assigned to 'b' first, then 'a' is incremented
    b = a++;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    return 0;
}
